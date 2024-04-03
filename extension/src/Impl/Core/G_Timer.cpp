#include "Impl/Core/G_Timer.h"
#include "Core/RGNCore.h"
#include "Core/RGNEnvironmentTarget.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/window.hpp>
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/callable.hpp>
#include <string>

void G_Timer::_bind_methods() {
	godot::ClassDB::bind_method(godot::D_METHOD("on_callback"), &G_Timer::_on_callback);
}

void G_Timer::_on_callback() {
    if (_callback) {
        _callback();
    }
    queue_free();
}

void G_Timer::start(double delay, std::function<void()> callback) {
    _callback = callback;
    _timer = memnew(godot::Timer());
    _timer->set_wait_time(delay);
    _timer->set_one_shot(true);
    _timer->connect("timeout", godot::Callable(this, "on_callback"));
    add_child(_timer);
    _timer->start();
}