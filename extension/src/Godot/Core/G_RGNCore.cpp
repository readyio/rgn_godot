#include "Godot/Core/G_RGNCore.h"
#include "Core/RGNCore.h"
#include "Core/RGNEnvironmentTarget.h"
#include <string>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

G_RGNCore *G_RGNCore::singleton = nullptr;

void G_RGNCore::_bind_methods() {
	godot::ClassDB::bind_method(godot::D_METHOD("initialize", "p_configure_data"), &G_RGNCore::initialize);
	godot::ClassDB::bind_method(godot::D_METHOD("update"), &G_RGNCore::update);
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

void G_RGNCore::initialize(godot::Dictionary p_configure_data) {
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
}

void G_RGNCore::update() {
	RGN::RGNCore::Update();
}