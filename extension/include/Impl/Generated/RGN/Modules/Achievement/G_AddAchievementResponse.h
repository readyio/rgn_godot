#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Achievement/AddAchievementResponse.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_AddAchievementResponse {
	static void ConvertToGodotModel(const RGN::Modules::Achievement::AddAchievementResponse& source, godot::Dictionary& target) {
        target["id"] = godot::String(source.id.c_str());
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Achievement::AddAchievementResponse& target) {
        godot::String g_source_id = source["id"];
        target.id = std::string(g_source_id.utf8().get_data());
	}
};
