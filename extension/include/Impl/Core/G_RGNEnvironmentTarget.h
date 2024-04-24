#pragma once

#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/core/class_db.hpp>

class G_RGNEnvironmentTarget : public godot::Object
{
	GDCLASS(G_RGNEnvironmentTarget, godot::Object);
public:
    enum Enumeration {
        NONE = 0,
        DEVELOPMENT = 1,
        STAGING = 2,
        PRODUCTION = 3
    };
protected:
	static void _bind_methods() {
		BIND_ENUM_CONSTANT(NONE);
        BIND_ENUM_CONSTANT(DEVELOPMENT);
        BIND_ENUM_CONSTANT(STAGING);
        BIND_ENUM_CONSTANT(PRODUCTION);
	}
};

VARIANT_ENUM_CAST(G_RGNEnvironmentTarget::Enumeration)