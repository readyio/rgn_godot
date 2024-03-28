#pragma once

#include <godot_cpp/classes/object.hpp>

class G_RGNCore : public godot::Object
{
	GDCLASS(G_RGNCore, godot::Object);

	static G_RGNCore *singleton;

protected:
	static void _bind_methods();

public:
	static G_RGNCore *get_singleton();

	G_RGNCore();
	~G_RGNCore();

	void initialize(godot::Dictionary p_configure_data);
	void update();
};