#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Achievement/GetAchievementsResponse.h"
#include "../../../../../Generated/RGN/Modules/Achievement/AchievementData.h"
#include "G_AchievementData.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_GetAchievementsResponse {
	static void ConvertToGodotModel(const RGN::Modules::Achievement::GetAchievementsResponse& source, godot::Dictionary& target) {
        godot::Array g_target_achievements;
        for (const auto& source_achievements_item : source.achievements) {
            godot::Dictionary g_source_achievements_item;
            godot::Dictionary g_g_source_achievements_item = g_source_achievements_item;
            G_AchievementData::ConvertToGodotModel(source_achievements_item, g_g_source_achievements_item);
            g_target_achievements.push_back(g_source_achievements_item);
        }
        target["achievements"] = g_target_achievements;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Achievement::GetAchievementsResponse& target) {
        godot::Array g_target_achievements = source["achievements"];
        for (int i = 0; i < g_target_achievements.size(); ++i) {
            godot::Dictionary g_target_achievements_item = g_target_achievements[i];
            RGN::Modules::Achievement::AchievementData cpp_source_achievements_item;
            G_AchievementData::ConvertToCoreModel(g_target_achievements_item, cpp_source_achievements_item);
            target.achievements.push_back(cpp_source_achievements_item);
        }
	}
};
