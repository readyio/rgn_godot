#pragma once

#include "Utility/FunctionEvent.h"
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/node.hpp>
#include <functional>

class G_RGNCore : public godot::Object
{
	GDCLASS(G_RGNCore, godot::Object);

	static G_RGNCore *singleton;
	godot::Node* _node;

protected:
	static void _bind_methods();
	void _on_focus();
	void _on_unfocus();

public:
	static G_RGNCore *get_singleton();

	G_RGNCore();
	~G_RGNCore();

	RGN::Utility::FunctionEvent<void()> onFocusEvent;
	RGN::Utility::FunctionEvent<void()> onUnfocusEvent;
	void initialize(godot::Node* node, godot::Dictionary p_configure_data);
	void update();
	void signIn();
	void startTimer(double delay, std::function<void()> callback);
};