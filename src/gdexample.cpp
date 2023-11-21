#include "gdexample.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

GDExample *GDExample::singleton = nullptr;

void GDExample::_bind_methods() {
	ClassDB::bind_method(D_METHOD("hello"), &GDExample::hello);
}

GDExample *GDExample::get_singleton()
{
	return singleton;
}

GDExample::GDExample() {
	ERR_FAIL_COND(singleton != nullptr);
	singleton = this;
}

GDExample::~GDExample() {
	ERR_FAIL_COND(singleton != this);
	singleton = nullptr;
}

void GDExample::hello()
{
	UtilityFunctions::print("Hello GDExtension Singleton!");
}