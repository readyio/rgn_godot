#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Model/Request/BaseRequestData.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

/**
 * Base class for request data that is sent to a server.
 * It includes common data that is required for all requests.
 */
struct G_BaseRequestData {
	static void ConvertToGodotModel(const RGN::Model::Request::BaseRequestData& source, godot::Dictionary& target) {
        target["appPackageName"] = godot::String(source.appPackageName.c_str());
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Model::Request::BaseRequestData& target) {
        godot::String g_source_appPackageName = source["appPackageName"];
        target.appPackageName = std::string(g_source_appPackageName.utf8().get_data());
	}
};
