#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Leaderboard/LeaderboardEntryWithRewards.h"
#include "../../../../../Generated/RGN/Modules/Leaderboard/LeaderboardReward.h"
#include "G_LeaderboardReward.h"
#include "../../../../../Generated/RGN/Modules/Leaderboard/LeaderboardEntry.h"
#include "G_LeaderboardEntry.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <string>
#include <vector>
#include <unordered_map>

/**
 * A class that represents an entry in the leaderboard.
 * This class serves as a Data Transfer Object (DTO) that contains details about a user's entry in the leaderboard.
 */
struct G_LeaderboardEntryWithRewards {
	static void ConvertToGodotModel(const RGN::Modules::Leaderboard::LeaderboardEntryWithRewards& source, godot::Dictionary& target) {
        godot::Array g_target_givenRewards;
        for (const auto& source_givenRewards_item : source.givenRewards) {
            godot::Dictionary g_source_givenRewards_item;
            godot::Dictionary g_g_source_givenRewards_item = g_source_givenRewards_item;
            G_LeaderboardReward::ConvertToGodotModel(source_givenRewards_item, g_g_source_givenRewards_item);
            g_target_givenRewards.push_back(g_source_givenRewards_item);
        }
        target["givenRewards"] = g_target_givenRewards;
        godot::Array g_target_failedRewards;
        for (const auto& source_failedRewards_item : source.failedRewards) {
            godot::Dictionary g_source_failedRewards_item;
            godot::Dictionary g_g_source_failedRewards_item = g_source_failedRewards_item;
            G_LeaderboardReward::ConvertToGodotModel(source_failedRewards_item, g_g_source_failedRewards_item);
            g_target_failedRewards.push_back(g_source_failedRewards_item);
        }
        target["failedRewards"] = g_target_failedRewards;
		G_LeaderboardEntry::ConvertToGodotModel(source, target);
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Leaderboard::LeaderboardEntryWithRewards& target) {
        godot::Array g_target_givenRewards = source["givenRewards"];
        for (int i = 0; i < g_target_givenRewards.size(); ++i) {
            godot::Dictionary g_target_givenRewards_item = g_target_givenRewards[i];
            RGN::Modules::Leaderboard::LeaderboardReward cpp_source_givenRewards_item;
            G_LeaderboardReward::ConvertToCoreModel(g_target_givenRewards_item, cpp_source_givenRewards_item);
            target.givenRewards.push_back(cpp_source_givenRewards_item);
        }
        godot::Array g_target_failedRewards = source["failedRewards"];
        for (int i = 0; i < g_target_failedRewards.size(); ++i) {
            godot::Dictionary g_target_failedRewards_item = g_target_failedRewards[i];
            RGN::Modules::Leaderboard::LeaderboardReward cpp_source_failedRewards_item;
            G_LeaderboardReward::ConvertToCoreModel(g_target_failedRewards_item, cpp_source_failedRewards_item);
            target.failedRewards.push_back(cpp_source_failedRewards_item);
        }
		G_LeaderboardEntry::ConvertToCoreModel(source, target);
	}
};
