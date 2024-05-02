#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Leaderboard/IsInPromoPeriodResponseData.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

/**
 * Information about the leaderboard's promo period.
 */
struct G_IsInPromoPeriodResponseData {
	static void ConvertToGodotModel(const RGN::Modules::Leaderboard::IsInPromoPeriodResponseData& source, godot::Dictionary& target) {
        target["isInPromoPeriod"] = source.isInPromoPeriod;
        target["leaderboardStartTime"] = source.leaderboardStartTime;
        target["promoPeriodStartTime"] = source.promoPeriodStartTime;
        target["currentTime"] = source.currentTime;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Leaderboard::IsInPromoPeriodResponseData& target) {
        bool g_source_isInPromoPeriod = source["isInPromoPeriod"];
        target.isInPromoPeriod = g_source_isInPromoPeriod;
        int64_t g_source_leaderboardStartTime = source["leaderboardStartTime"];
        target.leaderboardStartTime = g_source_leaderboardStartTime;
        int64_t g_source_promoPeriodStartTime = source["promoPeriodStartTime"];
        target.promoPeriodStartTime = g_source_promoPeriodStartTime;
        int64_t g_source_currentTime = source["currentTime"];
        target.currentTime = g_source_currentTime;
	}
};
