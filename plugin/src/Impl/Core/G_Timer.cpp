#include "Impl/G_Defs.h"
#include "Impl/Core/G_Timer.h"
#include "Core/RGNCore.h"
#include "Core/RGNEnvironmentTarget.h"
#include <string>

REG_GCLASS_METHODS_SOURCE(G_Timer) {
    BIND_GCLASS_METHOD(G_Timer::_on_callback, GCLASS_METHOD_SIGNATURE("on_callback"));
}

void G_Timer::_on_callback() {
    if (_callback) {
        _callback();
    }
    queue_free();
}

void G_Timer::start(double delay, std::function<void()> callback) {
    _callback = callback;
#ifdef GODOT3
    _timer = godot::Timer()._new();
#else
    _timer = memnew(godot::Timer());
#endif
    _timer->set_wait_time(delay);
    _timer->set_one_shot(true);
    _timer->set_autostart(true);
#ifdef GODOT3
    _timer->connect("timeout", this, "on_callback");
#else
    _timer->connect("timeout", godot::Callable(this, "on_callback"));
#endif
    add_child(_timer);
}