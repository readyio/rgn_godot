#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Creator/CreatorSignupResponseData.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_CreatorSignupResponseData {
	static void ConvertToGodotModel(const RGN::Modules::Creator::CreatorSignupResponseData& source, godot::Dictionary& target) {
        target["message"] = godot::String(source.message.c_str());
        target["success"] = source.success;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Creator::CreatorSignupResponseData& target) {
        godot::String g_source_message = source["message"];
        target.message = std::string(g_source_message.utf8().get_data());
        bool g_source_success = source["success"];
        target.success = g_source_success;
	}
};
