#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Leaderboard/LeaderboardReset.h"
#include "../../../../../Generated/RGN/Modules/Leaderboard/LeaderboardEntryWithRewards.h"
#include "G_LeaderboardEntryWithRewards.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

/**
 * A class that represents an reset history entry in the leaderboard.
 * This class serves as a Data Transfer Object (DTO) that contains details about a leaderboard reset data
 */
struct G_LeaderboardReset {
	static void ConvertToGodotModel(const RGN::Modules::Leaderboard::LeaderboardReset& source, godot::Dictionary& target) {
        target["id"] = godot::String(source.id.c_str());
        target["resetAt"] = source.resetAt;
        target["rewardsGivenAt"] = source.rewardsGivenAt;
        target["totalGivenRewardsCount"] = source.totalGivenRewardsCount;
        godot::Array g_target_entries;
        for (const auto& source_entries_item : source.entries) {
            godot::Dictionary g_source_entries_item;
            godot::Dictionary g_g_source_entries_item;
            G_LeaderboardEntryWithRewards::ConvertToGodotModel(source_entries_item, g_g_source_entries_item);
            g_source_entries_item = g_g_source_entries_item;
            g_target_entries.push_back(g_source_entries_item);
        }
        target["entries"] = g_target_entries;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Leaderboard::LeaderboardReset& target) {
        godot::String g_source_id = source["id"];
        target.id = std::string(g_source_id.utf8().get_data());
        int64_t g_source_resetAt = source["resetAt"];
        target.resetAt = g_source_resetAt;
        int64_t g_source_rewardsGivenAt = source["rewardsGivenAt"];
        target.rewardsGivenAt = g_source_rewardsGivenAt;
        int32_t g_source_totalGivenRewardsCount = source["totalGivenRewardsCount"];
        target.totalGivenRewardsCount = g_source_totalGivenRewardsCount;
        godot::Array g_target_entries = source["entries"];
        for (int i = 0; i < g_target_entries.size(); ++i) {
            godot::Dictionary g_target_entries_item = g_target_entries[i];
            RGN::Modules::Leaderboard::LeaderboardEntryWithRewards cpp_source_entries_item;
            G_LeaderboardEntryWithRewards::ConvertToCoreModel(g_target_entries_item, cpp_source_entries_item);
            target.entries.push_back(cpp_source_entries_item);
        }
	}
};
