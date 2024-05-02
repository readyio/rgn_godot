#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Achievement/GetUserAchievementsResponse.h"
#include "../../../../../Generated/RGN/Modules/Achievement/UserAchievement.h"
#include "G_UserAchievement.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_GetUserAchievementsResponse {
	static void ConvertToGodotModel(const RGN::Modules::Achievement::GetUserAchievementsResponse& source, godot::Dictionary& target) {
        godot::Array g_target_userAchievements;
        for (const auto& source_userAchievements_item : source.userAchievements) {
            godot::Dictionary g_source_userAchievements_item;
            godot::Dictionary g_g_source_userAchievements_item = g_source_userAchievements_item;
            G_UserAchievement::ConvertToGodotModel(source_userAchievements_item, g_g_source_userAchievements_item);
            g_target_userAchievements.push_back(g_source_userAchievements_item);
        }
        target["userAchievements"] = g_target_userAchievements;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Achievement::GetUserAchievementsResponse& target) {
        godot::Array g_target_userAchievements = source["userAchievements"];
        for (int i = 0; i < g_target_userAchievements.size(); ++i) {
            godot::Dictionary g_target_userAchievements_item = g_target_userAchievements[i];
            RGN::Modules::Achievement::UserAchievement cpp_source_userAchievements_item;
            G_UserAchievement::ConvertToCoreModel(g_target_userAchievements_item, cpp_source_userAchievements_item);
            target.userAchievements.push_back(cpp_source_userAchievements_item);
        }
	}
};
