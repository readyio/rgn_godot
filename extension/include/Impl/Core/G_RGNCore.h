#pragma once

#include "Utility/FunctionEvent.h"
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/callable.hpp>
#include <functional>
#include <vector>

class G_RGNCore : public godot::Object
{
	GDCLASS(G_RGNCore, godot::Object);
	static G_RGNCore *singleton;
	std::vector<godot::Callable> G_RGNCore::_authCallbacks;
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
	void startTimer(double delay, std::function<void()> callback);
	void initialize(godot::Node* node, godot::Dictionary p_configure_data);
	void update();
	void G_RGNCore::bindAuthChangeCallback(godot::Callable p_callback);
	void G_RGNCore::unbindAuthChangeCallback(godot::Callable p_callback);
	void G_RGNCore::signIn(godot::Callable p_callback);
	void G_RGNCore::signInAnonymously(godot::Callable p_callback);
	void G_RGNCore::signOut();
	void G_RGNCore::createWallet(godot::Callable p_callback);
	bool G_RGNCore::isLoggedIn();
	godot::String G_RGNCore::getUserId();
	godot::String G_RGNCore::getIdToken();
};