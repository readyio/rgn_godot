#include "Impl/Core/G_RGNCore.h"
#include "Impl/Core/G_Timer.h"
#include "Core/RGNCore.h"
#include "Core/RGNAuth.h"
#include "Core/RGNEnvironmentTarget.h"
#include "Utility/Logger.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/window.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/classes/object.hpp>

G_RGNCore *G_RGNCore::singleton = nullptr;

void G_RGNCore::_bind_methods() {
	godot::ClassDB::bind_method(godot::D_METHOD("on_focus"), &G_RGNCore::_onFocus);
	godot::ClassDB::bind_method(godot::D_METHOD("on_unfocus"), &G_RGNCore::_onUnfocus);
	godot::ClassDB::bind_method(godot::D_METHOD("initialize", "node", "configure_data"), &G_RGNCore::initialize);
	godot::ClassDB::bind_method(godot::D_METHOD("update"), &G_RGNCore::update);
	godot::ClassDB::bind_method(godot::D_METHOD("bindAuthChangeCallback", "callback"), &G_RGNCore::bindAuthChangeCallback, godot::Callable());
	godot::ClassDB::bind_method(godot::D_METHOD("unbindAuthChangeCallback", "callback"), &G_RGNCore::unbindAuthChangeCallback, godot::Callable());
	godot::ClassDB::bind_method(godot::D_METHOD("signIn", "callback"), &G_RGNCore::signIn);
	godot::ClassDB::bind_method(godot::D_METHOD("signInAnonymously", "callback"), &G_RGNCore::signInAnonymously, godot::Callable());
	godot::ClassDB::bind_method(godot::D_METHOD("signOut"), &G_RGNCore::signOut);
	godot::ClassDB::bind_method(godot::D_METHOD("createWallet", "callback"), &G_RGNCore::createWallet, godot::Callable());
	godot::ClassDB::bind_method(godot::D_METHOD("isLoggedIn"), &G_RGNCore::isLoggedIn);
	godot::ClassDB::bind_method(godot::D_METHOD("getUserId"), &G_RGNCore::getUserId);
	godot::ClassDB::bind_method(godot::D_METHOD("getIdToken"), &G_RGNCore::getIdToken);
}

G_RGNCore *G_RGNCore::get_singleton() {
	return singleton;
}

G_RGNCore::G_RGNCore() {
	ERR_FAIL_COND(singleton != nullptr);
	singleton = this;
}

G_RGNCore::~G_RGNCore() {
	ERR_FAIL_COND(singleton != this);
	singleton = nullptr;
}

void G_RGNCore::startTimer(double delay, std::function<void()> callback) {
	G_Timer* timer = memnew(G_Timer());
	_node->add_child(timer);
	timer->start(delay, callback);
}

void G_RGNCore::_onFocus() {
	onFocusEvent.raise();
}

void G_RGNCore::_onUnfocus() {
	onUnfocusEvent.raise();
}

void G_RGNCore::initialize(godot::Node* node, godot::Dictionary configure_data) {
	RGN::RGNConfigureData configureData;
    configureData.appId = configure_data.has("appId") ?
		((godot::String)configure_data["appId"]).utf8().get_data() : "";
    configureData.apiKey = configure_data.has("apiKey") ?
		((godot::String)configure_data["apiKey"]).utf8().get_data() : "";
    configureData.environmentTarget = configure_data.has("environmentTarget") ?
		static_cast<RGN::RGNEnvironmentTarget>((uint32_t)configure_data["environmentTarget"]) : RGN::RGNEnvironmentTarget::STAGING;
    configureData.useFunctionsEmulator = configure_data.has("useFunctionsEmulator") ?
		(bool)configure_data["useFunctionsEmulator"] : false;
    configureData.emulatorHost = configure_data.has("emulatorHost") ?
		((godot::String)configure_data["emulatorHost"]).utf8().get_data() : "127.0.0.1";
    configureData.emulatorPort = configure_data.has("emulatorPort") ?
		((godot::String)configure_data["emulatorPort"]).utf8().get_data() : "5001";
	RGN::RGNAuth::BindAuthChangeCallback([&](bool isLoggedIn) {
        for (auto callback : _authCallbacks) {
			if (callback.is_valid()) {
				godot::Array args;
				args.push_back(isLoggedIn);
				callback.callv(args);
			}
        }
    });
	RGN::RGNCore::Initialize(configureData);
	// Observer events when the app is focused/unfocused to properly handle cancel of webform process
	_node = node;
	godot::Window* gwin = _node->get_window();
	gwin->connect("focus_entered", godot::Callable(this, "on_focus"));
	gwin->connect("focus_exited", godot::Callable(this, "on_unfocus"));
}

void G_RGNCore::update() {
	RGN::RGNCore::Update();
}

void G_RGNCore::bindAuthChangeCallback(godot::Callable callback) {
	_authCallbacks.push_back(callback);
}

void G_RGNCore::unbindAuthChangeCallback(godot::Callable callback) {
    auto it = std::find(_authCallbacks.begin(), _authCallbacks.end(), callback);
    if (it != _authCallbacks.end()) {
        _authCallbacks.erase(it);
    }
}

void G_RGNCore::signIn(godot::Callable callback) {
    RGN::RGNAuth::SignIn([callback](bool isLoggedIn) {
		if (callback.is_valid()) {
			godot::Array args;
			args.push_back(isLoggedIn);
			callback.callv(args);
		}
    });
}

void G_RGNCore::signInAnonymously(godot::Callable callback) {
    RGN::RGNAuth::SignInAnonymously([callback](bool isLoggedIn) {
		if (callback.is_valid()) {
			godot::Array args;
			args.push_back(isLoggedIn);
			callback.callv(args);
		}
    });
}

void G_RGNCore::signOut() {
    RGN::RGNAuth::SignOut();
}

void G_RGNCore::createWallet(godot::Callable callback) {
	RGN::RGNAuth::CreateWallet([callback](bool canceled) {
		if (callback.is_valid()) {
			godot::Array args;
			args.push_back(canceled);
			callback.callv(args);
		}
    });
}

bool G_RGNCore::isLoggedIn() {
    return RGN::RGNAuth::IsLoggedIn();
}

godot::String G_RGNCore::getUserId() {
    return godot::String(RGN::RGNAuth::GetUserId().c_str());
}

godot::String G_RGNCore::getIdToken() {
    return godot::String(RGN::RGNAuth::GetIdToken().c_str());
}