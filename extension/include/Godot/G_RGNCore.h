#pragma once

#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/core/class_db.hpp>

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

	void test();
};