#pragma once

#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

class GDExample : public Object {
	GDCLASS(GDExample, Object)

	static GDExample *singleton;

protected:
	static void _bind_methods();

public:
	static GDExample *get_singleton();

	GDExample();
	~GDExample();

	void hello();
};