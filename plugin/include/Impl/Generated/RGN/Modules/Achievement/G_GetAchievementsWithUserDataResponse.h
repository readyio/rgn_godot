#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Achievement/GetAchievementsWithUserDataResponse.h"
#include "../../../../../Generated/RGN/Modules/Achievement/AchievementWithUserData.h"
#include "G_AchievementWithUserData.h"
#include "../../../../../Generated/RGN/Modules/Achievement/UserAchievement.h"
#include "G_UserAchievement.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_GetAchievementsWithUserDataResponse {
	static void ConvertToGodotModel(const RGN::Modules::Achievement::GetAchievementsWithUserDataResponse& source, godot::Dictionary& target) {
        godot::Array g_target_achievements;
        for (const auto& source_achievements_item : source.achievements) {
            godot::Dictionary g_source_achievements_item;
            godot::Dictionary g_g_source_achievements_item = g_source_achievements_item;
            G_AchievementWithUserData::ConvertToGodotModel(source_achievements_item, g_g_source_achievements_item);
            g_target_achievements.push_back(g_source_achievements_item);
        }
        target["achievements"] = g_target_achievements;
        godot::Array g_target_userAchievements;
        for (const auto& source_userAchievements_item : source.userAchievements) {
            godot::Dictionary g_source_userAchievements_item;
            godot::Dictionary g_g_source_userAchievements_item = g_source_userAchievements_item;
            G_UserAchievement::ConvertToGodotModel(source_userAchievements_item, g_g_source_userAchievements_item);
            g_target_userAchievements.push_back(g_source_userAchievements_item);
        }
        target["userAchievements"] = g_target_userAchievements;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Achievement::GetAchievementsWithUserDataResponse& target) {
        godot::Array g_target_achievements = source["achievements"];
        for (int i = 0; i < g_target_achievements.size(); ++i) {
            godot::Dictionary g_target_achievements_item = g_target_achievements[i];
            RGN::Modules::Achievement::AchievementWithUserData cpp_source_achievements_item;
            G_AchievementWithUserData::ConvertToCoreModel(g_target_achievements_item, cpp_source_achievements_item);
            target.achievements.push_back(cpp_source_achievements_item);
        }
        godot::Array g_target_userAchievements = source["userAchievements"];
        for (int i = 0; i < g_target_userAchievements.size(); ++i) {
            godot::Dictionary g_target_userAchievements_item = g_target_userAchievements[i];
            RGN::Modules::Achievement::UserAchievement cpp_source_userAchievements_item;
            G_UserAchievement::ConvertToCoreModel(g_target_userAchievements_item, cpp_source_userAchievements_item);
            target.userAchievements.push_back(cpp_source_userAchievements_item);
        }
	}
};
