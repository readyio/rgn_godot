#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/GameProgress/GameUserFullProfileData.h"
#include "../../../../../Generated/RGN/Modules/UserProfile/UserProfileData.h"
#include "../UserProfile/G_UserProfileData.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_GameUserFullProfileData {
	static void ConvertToGodotModel(const RGN::Modules::GameProgress::GameUserFullProfileData& source, godot::Dictionary& target) {
        target["readyWins"] = source.readyWins;
        target["readyLosses"] = source.readyLosses;
        target["readyDraws"] = source.readyDraws;
        target["readyTrophies"] = source.readyTrophies;
        target["readyAchievements"] = source.readyAchievements;
        target["previousThreshold"] = source.previousThreshold;
        target["nextThreshold"] = source.nextThreshold;
		G_UserProfileData::ConvertToGodotModel(source, target);
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::GameProgress::GameUserFullProfileData& target) {
        int32_t g_source_readyWins = source["readyWins"];
        target.readyWins = g_source_readyWins;
        int32_t g_source_readyLosses = source["readyLosses"];
        target.readyLosses = g_source_readyLosses;
        int32_t g_source_readyDraws = source["readyDraws"];
        target.readyDraws = g_source_readyDraws;
        int32_t g_source_readyTrophies = source["readyTrophies"];
        target.readyTrophies = g_source_readyTrophies;
        int32_t g_source_readyAchievements = source["readyAchievements"];
        target.readyAchievements = g_source_readyAchievements;
        int32_t g_source_previousThreshold = source["previousThreshold"];
        target.previousThreshold = g_source_previousThreshold;
        int32_t g_source_nextThreshold = source["nextThreshold"];
        target.nextThreshold = g_source_nextThreshold;
		G_UserProfileData::ConvertToCoreModel(source, target);
	}
};
