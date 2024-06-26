#include "Environment/Environment.h"
#ifdef GODOT3
#include <OS.hpp>
#include <Engine.hpp>
#else
#include <godot_cpp/classes/os.hpp>
#include <godot_cpp/classes/engine.hpp>
#endif

namespace RGN {
    void Environment::OpenURL(std::string url) {
		godot::OS::get_singleton()->shell_open(godot::String(url.c_str()));
    }

    std::string Environment::GetProcessorType() {
		return std::string(godot::OS::get_singleton()->get_processor_name().utf8().get_data());
	}

	int32_t Environment::GetProcessorCount() {
		return godot::OS::get_singleton()->get_processor_count();
	}

	int32_t Environment::GetSystemMemorySize() {
		return 0;
	}

	std::string Environment::GetGraphicsDeviceName() {
		return "";
	}

	int32_t Environment::GetGraphicsMemorySize() {
		return 0;
	}

	std::string Environment::GetOperatingSystem() {
#ifdef GODOT3
		return "";
#else
		return std::string(godot::OS::get_singleton()->get_version().utf8().get_data());
#endif
	}

	std::string Environment::GetOperatingSystemFamily() {
		return std::string(godot::OS::get_singleton()->get_name().utf8().get_data());
	}

	std::string Environment::GetEngineName() {
		return "GodotEngine";
	}

	std::string Environment::GetEngineVersion() {
		return std::string(godot::Engine::get_singleton()->get_version_info()["string"].stringify().utf8().get_data());
	}

	std::string Environment::GetAppIdentifier() {
#if defined(PLATFORM_ANDROID) || defined(PLATFORM_IOS)
        godot::Object* webview = godot::Engine::get_singleton()->get_singleton("RGNPluginMobile");
        if (webview != nullptr) {
			godot::String appIdentifier = webview->call("getAppIdentifier");
			return std::string(appIdentifier.utf8().get_data());
        }
#endif
		return "";
	}

	std::string Environment::GetAppInstallerName() {
#if defined(PLATFORM_ANDROID) || defined(PLATFORM_IOS)
        godot::Object* webview = godot::Engine::get_singleton()->get_singleton("RGNPluginMobile");
        if (webview != nullptr) {
			godot::String appInstallerName = webview->call("getAppInstallerName");
			return std::string(appInstallerName.utf8().get_data());
        }
#endif
		return "";
	}
}