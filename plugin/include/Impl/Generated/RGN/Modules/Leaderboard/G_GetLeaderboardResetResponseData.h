#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Leaderboard/GetLeaderboardResetResponseData.h"
#include "../../../../../Generated/RGN/Modules/Leaderboard/LeaderboardReset.h"
#include "G_LeaderboardReset.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_GetLeaderboardResetResponseData {
	static void ConvertToGodotModel(const RGN::Modules::Leaderboard::GetLeaderboardResetResponseData& source, godot::Dictionary& target) {
        godot::Dictionary g_target_reset;
        G_LeaderboardReset::ConvertToGodotModel(source.reset, g_target_reset);
        target["reset"] = g_target_reset;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Leaderboard::GetLeaderboardResetResponseData& target) {
        G_LeaderboardReset::ConvertToCoreModel(source["reset"], target.reset);
	}
};
