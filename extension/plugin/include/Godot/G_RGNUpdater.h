#pragma once

#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/core/class_db.hpp>

class G_RGNUpdater : public godot::Object
{
	GDCLASS(G_RGNUpdater, godot::Object);

	static G_RGNUpdater *singleton;

protected:
	static void _bind_methods();

public:
	static G_RGNUpdater *get_singleton();

	G_RGNUpdater();
	~G_RGNUpdater();

	void update();
};