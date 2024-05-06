#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Leaderboard/GetLeaderboardsResponse.h"
#include "../../../../../Generated/RGN/Modules/Leaderboard/LeaderboardData.h"
#include "G_LeaderboardData.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_GetLeaderboardsResponse {
	static void ConvertToGodotModel(const RGN::Modules::Leaderboard::GetLeaderboardsResponse& source, godot::Dictionary& target) {
        godot::Array g_target_leaderboards;
        for (const auto& source_leaderboards_item : source.leaderboards) {
            godot::Dictionary g_source_leaderboards_item;
            godot::Dictionary g_g_source_leaderboards_item;
            G_LeaderboardData::ConvertToGodotModel(source_leaderboards_item, g_g_source_leaderboards_item);
            g_source_leaderboards_item = g_g_source_leaderboards_item;
            g_target_leaderboards.push_back(g_source_leaderboards_item);
        }
        target["leaderboards"] = g_target_leaderboards;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Leaderboard::GetLeaderboardsResponse& target) {
        godot::Array g_target_leaderboards = source["leaderboards"];
        for (int i = 0; i < g_target_leaderboards.size(); ++i) {
            godot::Dictionary g_target_leaderboards_item = g_target_leaderboards[i];
            RGN::Modules::Leaderboard::LeaderboardData cpp_source_leaderboards_item;
            G_LeaderboardData::ConvertToCoreModel(g_target_leaderboards_item, cpp_source_leaderboards_item);
            target.leaderboards.push_back(cpp_source_leaderboards_item);
        }
	}
};
