#pragma once

#include "Impl/Core/G_RGNCore.h"
#include <godot_cpp/classes/timer.hpp>
#include <godot_cpp/classes/node.hpp>
#include <functional>

class G_Timer : public godot::Node
{
	GDCLASS(G_Timer, godot::Node);

    godot::Timer* _timer;
    std::function<void()> _callback;

protected:
	static void _bind_methods();
	void _on_callback();

public:
	void start(double delay, std::function<void()> callback);
};