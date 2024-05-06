#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Achievement/AchievementWithUserData.h"
#include "../../../../../Generated/RGN/Modules/Achievement/UserAchievement.h"
#include "G_UserAchievement.h"
#include "../../../../../Generated/RGN/Modules/Achievement/AchievementData.h"
#include "G_AchievementData.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

/**
 * Represents achievement data from the backend
 */
struct G_AchievementWithUserData {
	static void ConvertToGodotModel(const RGN::Modules::Achievement::AchievementWithUserData& source, godot::Dictionary& target) {
        godot::Dictionary g_target__userAchievement;
        G_UserAchievement::ConvertToGodotModel(source._userAchievement, g_target__userAchievement);
        target["_userAchievement"] = g_target__userAchievement;
		G_AchievementData::ConvertToGodotModel(source, target);
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Achievement::AchievementWithUserData& target) {
        G_UserAchievement::ConvertToCoreModel(source["_userAchievement"], target._userAchievement);
		G_AchievementData::ConvertToCoreModel(source, target);
	}
};
