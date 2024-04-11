#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Leaderboard/GetLeaderboardEntriesResponseData.h"
#include "../../../../../Generated/RGN/Modules/Leaderboard/LeaderboardEntry.h"
#include "G_LeaderboardEntry.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <string>
#include <vector>
#include <unordered_map>

struct G_GetLeaderboardEntriesResponseData {
	static void ConvertToGodotModel(const RGN::Modules::Leaderboard::GetLeaderboardEntriesResponseData& source, godot::Dictionary& target) {
        godot::Array g_target_entries;
        for (const auto& source_entries_item : source.entries) {
            godot::Dictionary g_source_entries_item;
            godot::Dictionary g_g_source_entries_item = g_source_entries_item;
            G_LeaderboardEntry::ConvertToGodotModel(source_entries_item, g_g_source_entries_item);
            g_target_entries.push_back(g_source_entries_item);
        }
        target["entries"] = g_target_entries;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Leaderboard::GetLeaderboardEntriesResponseData& target) {
        godot::Array g_target_entries = source["entries"];
        for (int i = 0; i < g_target_entries.size(); ++i) {
            godot::Dictionary g_target_entries_item = g_target_entries[i];
            RGN::Modules::Leaderboard::LeaderboardEntry cpp_source_entries_item;
            G_LeaderboardEntry::ConvertToCoreModel(g_target_entries_item, cpp_source_entries_item);
            target.entries.push_back(cpp_source_entries_item);
        }
	}
};
