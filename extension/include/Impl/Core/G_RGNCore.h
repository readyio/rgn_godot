#pragma once

#include "Impl/Core/G_RGNConfigurationData.h"
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
	std::vector<godot::Callable> _authCallbacks;
	godot::Node* _node;
protected:
	static void _bind_methods();
	void _onFocus();
	void _onUnfocus();
	void _onSignIn(godot::Callable callback, bool success);
	void _onWebFormRedirect(godot::String url);
public:
	static G_RGNCore *get_singleton();
	G_RGNCore();
	~G_RGNCore();
	RGN::Utility::FunctionEvent<void()> onFocusEvent;
	RGN::Utility::FunctionEvent<void()> onUnfocusEvent;
	void startTimer(double delay, std::function<void()> callback);
	void initialize(godot::Node* node, G_RGNConfigurationData* configure_data);
	void update();
	void bindAuthChangeCallback(godot::Callable callback);
	void unbindAuthChangeCallback(godot::Callable callback);
	void signIn(godot::Callable callback);
	void signInAnonymously(godot::Callable callback);
	void signOut();
	void createWallet(godot::Callable callback);
	bool isLoggedIn();
	godot::String getUserId();
	godot::String getIdToken();
};