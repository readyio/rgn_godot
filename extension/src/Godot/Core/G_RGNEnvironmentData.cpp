#include "Godot/Core/G_RGNEnvironmentTarget.h"
#include "Core/RGNEnvironmentTarget.h"
#include <string>
#include <godot_cpp/core/class_db.hpp>

G_RGNEnvironmentTarget *G_RGNEnvironmentTarget::singleton = nullptr;

void G_RGNEnvironmentTarget::_bind_methods() {
	godot::ClassDB::bind_method(godot::D_METHOD("NONE"), &G_RGNEnvironmentTarget::NONE);
	godot::ClassDB::bind_method(godot::D_METHOD("DEVELOPMENT"), &G_RGNEnvironmentTarget::DEVELOPMENT);
	godot::ClassDB::bind_method(godot::D_METHOD("STAGING"), &G_RGNEnvironmentTarget::STAGING);
	godot::ClassDB::bind_method(godot::D_METHOD("PRODUCTION"), &G_RGNEnvironmentTarget::PRODUCTION);
}

G_RGNEnvironmentTarget *G_RGNEnvironmentTarget::get_singleton() {
	return singleton;
}

G_RGNEnvironmentTarget::G_RGNEnvironmentTarget() {
	ERR_FAIL_COND(singleton != nullptr);
	singleton = this;
}

G_RGNEnvironmentTarget::~G_RGNEnvironmentTarget() {
	ERR_FAIL_COND(singleton != this);
	singleton = nullptr;
}

uint32_t G_RGNEnvironmentTarget::NONE() {
    return static_cast<uint32_t>(RGN::RGNEnvironmentTarget::NONE);
}

uint32_t G_RGNEnvironmentTarget::DEVELOPMENT() {
    return static_cast<uint32_t>(RGN::RGNEnvironmentTarget::DEVELOPMENT);
}

uint32_t G_RGNEnvironmentTarget::STAGING() {
    return static_cast<uint32_t>(RGN::RGNEnvironmentTarget::STAGING);
}

uint32_t G_RGNEnvironmentTarget::PRODUCTION() {
    return static_cast<uint32_t>(RGN::RGNEnvironmentTarget::PRODUCTION);
}