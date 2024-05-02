#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Achievement/DailyAchievements.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

/**
 * Daily achievements. Triggered when the user logs in.
 * Use the 'repeatNoMoreOftenThanCron' field to specify how often the achievement can give rewards.
 */
struct G_DailyAchievements {
	static void ConvertToGodotModel(const RGN::Modules::Achievement::DailyAchievements& source, godot::Dictionary& target) {
        target["daysInRow"] = source.daysInRow;
        target["achievementId"] = godot::String(source.achievementId.c_str());
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Achievement::DailyAchievements& target) {
        int32_t g_source_daysInRow = source["daysInRow"];
        target.daysInRow = g_source_daysInRow;
        godot::String g_source_achievementId = source["achievementId"];
        target.achievementId = std::string(g_source_achievementId.utf8().get_data());
	}
};
