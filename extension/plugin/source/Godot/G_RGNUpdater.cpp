#include "Godot/G_RGNUpdater.h"
#include "Http/HttpGodot.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

G_RGNUpdater *G_RGNUpdater::singleton = nullptr;

void G_RGNUpdater::_bind_methods()
{
	godot::ClassDB::bind_method(godot::D_METHOD("update"), &G_RGNUpdater::update);
}

G_RGNUpdater *G_RGNUpdater::get_singleton()
{
	return singleton;
}

G_RGNUpdater::G_RGNUpdater()
{
	ERR_FAIL_COND(singleton != nullptr);
	singleton = this;
}

G_RGNUpdater::~G_RGNUpdater()
{
	ERR_FAIL_COND(singleton != this);
	singleton = nullptr;
}

void G_RGNUpdater::update()
{
	HttpGodot::Poll();
}