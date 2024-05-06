#pragma once

#include "Impl/G_Defs.h"
#include "Impl/Core/G_RGNCore.h"
#include <functional>
#ifdef GODOT3
#include <Timer.hpp>
#else
#include <godot_cpp/classes/timer.hpp>
#endif

class G_Timer : public godot::Node
{
	REG_GCLASS(G_Timer, godot::Node);

    godot::Timer* _timer;
    std::function<void()> _callback;

protected:
	void _on_callback();

public:
	REG_GCLASS_METHODS_HEADER();
#ifdef GODOT3
	void _init() {}
#endif
	void start(double delay, std::function<void()> callback);
};