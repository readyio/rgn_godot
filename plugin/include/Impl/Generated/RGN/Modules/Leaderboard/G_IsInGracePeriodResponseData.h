#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Leaderboard/IsInGracePeriodResponseData.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

/**
 * Information about the leaderboard's grace period.
 */
struct G_IsInGracePeriodResponseData {
	static void ConvertToGodotModel(const RGN::Modules::Leaderboard::IsInGracePeriodResponseData& source, godot::Dictionary& target) {
        target["isInGracePeriod"] = source.isInGracePeriod;
        target["leaderboardEndTime"] = source.leaderboardEndTime;
        target["gracePeriodEndTime"] = source.gracePeriodEndTime;
        target["currentTime"] = source.currentTime;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Leaderboard::IsInGracePeriodResponseData& target) {
        bool g_source_isInGracePeriod = source["isInGracePeriod"];
        target.isInGracePeriod = g_source_isInGracePeriod;
        int64_t g_source_leaderboardEndTime = source["leaderboardEndTime"];
        target.leaderboardEndTime = g_source_leaderboardEndTime;
        int64_t g_source_gracePeriodEndTime = source["gracePeriodEndTime"];
        target.gracePeriodEndTime = g_source_gracePeriodEndTime;
        int64_t g_source_currentTime = source["currentTime"];
        target.currentTime = g_source_currentTime;
	}
};
