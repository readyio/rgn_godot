#include "Impl/Core/G_RGNCore.h"
#include "Impl/Core/G_Timer.h"
#include "Core/RGNCore.h"
#include "Core/RGNAuth.h"
#include "Core/RGNEnvironmentTarget.h"
#include "Utility/Logger.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/window.hpp>
#include <godot_cpp/variant/array.hpp>

G_RGNCore *G_RGNCore::singleton = nullptr;

void G_RGNCore::_bind_methods() {
	godot::ClassDB::bind_method(godot::D_METHOD("on_focus"), &G_RGNCore::_on_focus);
	godot::ClassDB::bind_method(godot::D_METHOD("on_unfocus"), &G_RGNCore::_on_unfocus);
	godot::ClassDB::bind_method(godot::D_METHOD("initialize", "p_configure_data"), &G_RGNCore::initialize);
	godot::ClassDB::bind_method(godot::D_METHOD("update"), &G_RGNCore::update);
	godot::ClassDB::bind_method(godot::D_METHOD("bindAuthChangeCallback", "p_callback"), &G_RGNCore::bindAuthChangeCallback);
	godot::ClassDB::bind_method(godot::D_METHOD("unbindAuthChangeCallback", "p_callback"), &G_RGNCore::unbindAuthChangeCallback);
	godot::ClassDB::bind_method(godot::D_METHOD("signIn", "p_callback"), &G_RGNCore::signIn);
	godot::ClassDB::bind_method(godot::D_METHOD("signInAnonymously", "p_callback"), &G_RGNCore::signInAnonymously);
	godot::ClassDB::bind_method(godot::D_METHOD("signOut"), &G_RGNCore::signOut);
	godot::ClassDB::bind_method(godot::D_METHOD("createWallet", "p_callback"), &G_RGNCore::createWallet);
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

void G_RGNCore::_on_focus() {
	onFocusEvent.raise();
}

void G_RGNCore::_on_unfocus() {
	onUnfocusEvent.raise();
}

void G_RGNCore::initialize(godot::Node* node, godot::Dictionary p_configure_data) {
	RGN::RGNConfigureData configureData;
    configureData.appId = p_configure_data.has("appId") ?
		((godot::String)p_configure_data["appId"]).utf8().get_data() : "";
    configureData.apiKey = p_configure_data.has("apiKey") ?
		((godot::String)p_configure_data["apiKey"]).utf8().get_data() : "";
    configureData.environmentTarget = p_configure_data.has("environmentTarget") ?
		static_cast<RGN::RGNEnvironmentTarget>((uint32_t)p_configure_data["environmentTarget"]) : RGN::RGNEnvironmentTarget::STAGING;
    configureData.useFunctionsEmulator = p_configure_data.has("useFunctionsEmulator") ?
		(bool)p_configure_data["useFunctionsEmulator"] : false;
    configureData.emulatorHost = p_configure_data.has("emulatorHost") ?
		((godot::String)p_configure_data["emulatorHost"]).utf8().get_data() : "127.0.0.1";
    configureData.emulatorPort = p_configure_data.has("emulatorPort") ?
		((godot::String)p_configure_data["emulatorPort"]).utf8().get_data() : "5001";
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

void G_RGNCore::bindAuthChangeCallback(godot::Callable p_callback) {
	_authCallbacks.push_back(p_callback);
}

void G_RGNCore::unbindAuthChangeCallback(godot::Callable p_callback) {
    auto it = std::find(_authCallbacks.begin(), _authCallbacks.end(), p_callback);
    if (it != _authCallbacks.end()) {
        _authCallbacks.erase(it);
    }
}

void G_RGNCore::signIn(godot::Callable p_callback) {
    RGN::RGNAuth::SignIn([p_callback](bool isLoggedIn) {
		if (p_callback.is_valid()) {
			godot::Array args;
			args.push_back(isLoggedIn);
			p_callback.callv(args);
		}
    });
}

void G_RGNCore::signInAnonymously(godot::Callable p_callback) {
    RGN::RGNAuth::SignInAnonymously([p_callback](bool isLoggedIn) {
		if (p_callback.is_valid()) {
			godot::Array args;
			args.push_back(isLoggedIn);
			p_callback.callv(args);
		}
    });
}

void G_RGNCore::signOut() {
    RGN::RGNAuth::SignOut();
}

void G_RGNCore::createWallet(godot::Callable p_callback) {
	RGN::RGNAuth::CreateWallet([p_callback](bool canceled) {
		if (p_callback.is_valid()) {
			godot::Array args;
			args.push_back(canceled);
			p_callback.callv(args);
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