#include "Impl/G_Defs.h"
#include "Impl/Core/G_RGNCore.h"
#include "Impl/Core/G_Timer.h"
#include "Core/RGNCore.h"
#include "Core/RGNAuth.h"
#include "Core/RGNEnvironmentTarget.h"
#include "WebForm/WebForm.h"
#include "Utility/Logger.h"
#ifdef GODOT3
#include "OS.hpp"
#else
#include <godot_cpp/classes/window.hpp>
#endif

void G_RGNCore::startTimer(double delay, std::function<void()> callback) {
#ifdef GODOT3
	G_Timer* timer = G_Timer::_new();
	add_child(timer);
#else
	if (_node == nullptr) {
		return;
	}
	G_Timer* timer = memnew(G_Timer());
	_node->add_child(timer);
#endif
	timer->start(delay, callback);
}

G_RGNCore *G_RGNCore::singleton = nullptr;

G_RGNCore *G_RGNCore::get_singleton() {
	return singleton;
}

G_RGNCore::G_RGNCore() {
	ERR_FAIL_COND(singleton != nullptr);
	singleton = this;
}

G_RGNCore::~G_RGNCore() {
	ERR_FAIL_COND(singleton != this);
	singleton = nullptr;
}

REG_GCLASS_METHODS_SOURCE(G_RGNCore) {
	BIND_GCLASS_METHOD(G_RGNCore::_onFocus, GCLASS_METHOD_SIGNATURE("on_focus"));
	BIND_GCLASS_METHOD(G_RGNCore::_onUnfocus, GCLASS_METHOD_SIGNATURE("on_unfocus"));
	BIND_GCLASS_METHOD(G_RGNCore::_onSignIn, GCLASS_METHOD_SIGNATURE("on_signin"));
	BIND_GCLASS_METHOD(G_RGNCore::_onWebFormRedirect, GCLASS_METHOD_SIGNATURE("on_webform_redirect", "url"));
#ifdef GODOT3
	BIND_GCLASS_METHOD_DEFVAL(G_RGNCore::initialize, GCLASS_METHOD_SIGNATURE("initialize", "configure_data", "on_initialize"), nullptr, GCALLBACK_DEFVAL);
#else
	BIND_GCLASS_METHOD_DEFVAL(G_RGNCore::initialize, GCLASS_METHOD_SIGNATURE("initialize", "node", "configure_data", "on_initialize"), nullptr, GCALLBACK_DEFVAL);
#endif
	BIND_GCLASS_METHOD(G_RGNCore::update, GCLASS_METHOD_SIGNATURE("update"));
	BIND_GCLASS_METHOD_DEFVAL(G_RGNCore::bindAuthChangeCallback, GCLASS_METHOD_SIGNATURE("bindAuthChangeCallback", "callback"), GCALLBACK_DEFVAL);
	BIND_GCLASS_METHOD_DEFVAL(G_RGNCore::unbindAuthChangeCallback, GCLASS_METHOD_SIGNATURE("unbindAuthChangeCallback", "callback"), GCALLBACK_DEFVAL);
	BIND_GCLASS_METHOD(G_RGNCore::signIn, GCLASS_METHOD_SIGNATURE("signIn", "callback"));
	BIND_GCLASS_METHOD_DEFVAL(G_RGNCore::signInAnonymously, GCLASS_METHOD_SIGNATURE("signInAnonymously", "callback"), GCALLBACK_DEFVAL);
	BIND_GCLASS_METHOD(G_RGNCore::signOut, GCLASS_METHOD_SIGNATURE("signOut"));
	BIND_GCLASS_METHOD_DEFVAL(G_RGNCore::createWallet, GCLASS_METHOD_SIGNATURE("createWallet", "callback"), GCALLBACK_DEFVAL);
	BIND_GCLASS_METHOD(G_RGNCore::isLoggedIn, GCLASS_METHOD_SIGNATURE("isLoggedIn"));
	BIND_GCLASS_METHOD(G_RGNCore::getUserId, GCLASS_METHOD_SIGNATURE("getUserId"));
	BIND_GCLASS_METHOD(G_RGNCore::getIdToken, GCLASS_METHOD_SIGNATURE("getIdToken"));
}

void G_RGNCore::_onFocus() {
	onFocusEvent.raise();
}

void G_RGNCore::_onUnfocus() {
	onUnfocusEvent.raise();
}

void G_RGNCore::_onSignIn(GCALLBACK callback, bool success) {
	if (callback.is_valid()) {
		godot::Array args;
		args.push_back(success);
		EXECUTE_GCALLBACK_DEFVAL(callback, args);
	}
}

void G_RGNCore::_onWebFormRedirect(godot::String url) {
	bool cancelled = url.begins_with("cancelled");
	std::string urlString = cancelled ? "" : std::string(url.utf8().get_data());
	RGN::WebForm::OnWebFormRedirect(cancelled, urlString);
}

#ifdef GODOT3
void G_RGNCore::initialize(G_RGNConfigurationData* configure_data, GCALLBACK on_initialize) {
#else
void G_RGNCore::initialize(godot::Node* node, G_RGNConfigurationData* configure_data, GCALLBACK on_initialize) {
	_node = node;
#endif
	RGN::RGNConfigureData configureData;
	if (configure_data) {
		configureData.appId = std::string(configure_data->getAppId().utf8().get_data());
		configureData.apiKey = std::string(configure_data->getApiKey().utf8().get_data());
		configureData.environmentTarget = static_cast<RGN::RGNEnvironmentTarget>(configure_data->getEnvironmentTarget());
		configureData.useFunctionsEmulator = configure_data->getUseFunctionsEmulator();
		configureData.emulatorHost = std::string(configure_data->getEmulatorHost().utf8().get_data());
		configureData.emulatorPort = std::string(configure_data->getEmulatorPort().utf8().get_data());
	}
	RGN::RGNAuth::BindAuthChangeCallback([&](bool isLoggedIn) {
        for (auto callback : G_RGNCore::_authCallbacks) {
			if (callback.is_valid()) {
				godot::Array args;
				args.push_back(isLoggedIn);
				EXECUTE_GCALLBACK_DEFVAL(callback, args);
			}
        }
    });
	RGN::RGNCore::Initialize(configureData);
	if (configure_data->getAutoGuestLogin() && !isLoggedIn()) {
        RGN::RGNAuth::SignInAnonymously([on_initialize](bool isLoggedIn) {
			if (on_initialize.is_valid()) {
				EXECUTE_GCALLBACK_DEFVAL(on_initialize, godot::Array());
			}
        });
    } else {
		if (on_initialize.is_valid()) {
			EXECUTE_GCALLBACK_DEFVAL(on_initialize, godot::Array());
		}
    }
#ifdef GODOT4
	// Observer events when the app is focused/unfocused to properly handle cancel of webform process
	if (_node != nullptr) {
		godot::Window* gwin = _node->get_window();
		gwin->connect("focus_entered", godot::Callable(this, "on_focus"));
		gwin->connect("focus_exited", godot::Callable(this, "on_unfocus"));
	}
#endif
}

void G_RGNCore::update() {
	RGN::RGNCore::Update();
#ifdef GODOT3
	if (_hasAppFocus && !godot::OS::get_singleton()->is_window_focused()) {
		onUnfocusEvent.raise();
	} else if (!_hasAppFocus && godot::OS::get_singleton()->is_window_focused()) {
		onFocusEvent.raise();
	}
	_hasAppFocus = godot::OS::get_singleton()->is_window_focused();
#endif
}

void G_RGNCore::bindAuthChangeCallback(GCALLBACK callback) {
	_authCallbacks.push_back(callback);
}

void G_RGNCore::unbindAuthChangeCallback(GCALLBACK callback) {
    auto it = std::find(_authCallbacks.begin(), _authCallbacks.end(), callback);
    if (it != _authCallbacks.end()) {
        _authCallbacks.erase(it);
    }
}

void G_RGNCore::signIn(GCALLBACK callback) {
    RGN::RGNAuth::SignIn([&, callback](bool isLoggedIn) {
		call_deferred("on_signin", callback, isLoggedIn);
    });
}

void G_RGNCore::signInAnonymously(GCALLBACK callback) {
    RGN::RGNAuth::SignInAnonymously([callback](bool isLoggedIn) {
		if (callback.is_valid()) {
			godot::Array args;
			args.push_back(isLoggedIn);
			EXECUTE_GCALLBACK_DEFVAL(callback, args);
		}
    });
}

void G_RGNCore::signOut() {
    RGN::RGNAuth::SignOut();
}

void G_RGNCore::createWallet(GCALLBACK callback) {
	RGN::RGNAuth::CreateWallet([&, callback](bool canceled) {
		call_deferred("on_signin", callback, canceled);
    });
}

bool G_RGNCore::isLoggedIn() {
    return RGN::RGNAuth::IsLoggedIn();
}

godot::String G_RGNCore::getUserId() {
    return godot::String(RGN::RGNAuth::GetUserId().c_str());
}

godot::String G_RGNCore::getIdToken() {
    return godot::String(RGN::RGNAuth::GetIdToken().c_str());
}