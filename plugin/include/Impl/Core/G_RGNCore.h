#pragma once

#include "Impl/G_Defs.h"
#include "Impl/Core/G_RGNConfigurationData.h"
#include "Utility/FunctionEvent.h"
#include <functional>
#include <vector>

class G_RGNCore : public godot::Node {
	REG_GCLASS(G_RGNCore, godot::Node);
	static G_RGNCore *singleton;
	std::vector<GCALLBACK> _authCallbacks;
#ifdef GODOT3
	bool _hasAppFocus = true;
#endif
protected:
	void _onFocus();
	void _onUnfocus();
	void _onSignIn(GCALLBACK callback, bool success);
	void _onWebFormRedirect(godot::String url);
public:
	static G_RGNCore *get_singleton();
	G_RGNCore();
	~G_RGNCore();
	REG_GCLASS_METHODS_HEADER();
#ifdef GODOT3
	void _init() {}
#endif
	RGN::Utility::FunctionEvent<void()> onFocusEvent;
	RGN::Utility::FunctionEvent<void()> onUnfocusEvent;
	void startTimer(double delay, std::function<void()> callback);
	void initialize(G_RGNConfigurationData* configure_data, GCALLBACK on_initialize);
	void update();
	void bindAuthChangeCallback(GCALLBACK callback);
	void unbindAuthChangeCallback(GCALLBACK callback);
	void signIn(GCALLBACK callback);
	void signInAnonymously(GCALLBACK callback);
	void signOut();
	void createWallet(GCALLBACK callback);
	bool isLoggedIn();
	godot::String getUserId();
	godot::String getIdToken();
};