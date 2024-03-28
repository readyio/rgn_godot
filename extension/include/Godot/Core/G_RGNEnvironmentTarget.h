#pragma once

#include <godot_cpp/classes/object.hpp>

class G_RGNEnvironmentTarget : public godot::Object
{
	GDCLASS(G_RGNEnvironmentTarget, godot::Object);

	static G_RGNEnvironmentTarget *singleton;

protected:
	static void _bind_methods();

public:
	static G_RGNEnvironmentTarget *get_singleton();

	G_RGNEnvironmentTarget();
	~G_RGNEnvironmentTarget();

	uint32_t NONE();
	uint32_t DEVELOPMENT();
	uint32_t STAGING();
	uint32_t PRODUCTION();
};