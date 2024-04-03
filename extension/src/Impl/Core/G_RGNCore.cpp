#include "Impl/Core/G_RGNCore.h"
#include "Impl/Core/G_Timer.h"
#include "Core/RGNCore.h"
#include "Core/RGNAuth.h"
#include "Core/RGNEnvironmentTarget.h"
#include "Utility/Logger.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/window.hpp>
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/callable.hpp>
#include <string>

G_RGNCore *G_RGNCore::singleton = nullptr;

void G_RGNCore::_bind_methods() {
	godot::ClassDB::bind_method(godot::D_METHOD("initialize", "p_configure_data"), &G_RGNCore::initialize);
	godot::ClassDB::bind_method(godot::D_METHOD("update"), &G_RGNCore::update);
	godot::ClassDB::bind_method(godot::D_METHOD("signIn"), &G_RGNCore::signIn);
	godot::ClassDB::bind_method(godot::D_METHOD("on_focus"), &G_RGNCore::_on_focus);
	godot::ClassDB::bind_method(godot::D_METHOD("on_unfocus"), &G_RGNCore::_on_unfocus);
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
	RGN::RGNCore::Initialize(configureData);
	_node = node;
	godot::Window* gwin = _node->get_window();
	gwin->connect("focus_entered", godot::Callable(this, "on_focus"));
	gwin->connect("focus_exited", godot::Callable(this, "on_unfocus"));
}

void G_RGNCore::update() {
	RGN::RGNCore::Update();
}

void G_RGNCore::signIn() {
    RGN::RGNAuth::SignIn([](bool isLoggedIn) {
        RGN::Utility::Logger::Debug("RGNAuth::SignIn, isLoggedIn: " + std::to_string(isLoggedIn));
    });
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