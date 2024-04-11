#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Leaderboard/GetLeaderboardResetsResponseData.h"
#include "../../../../../Generated/RGN/Modules/Leaderboard/LeaderboardReset.h"
#include "G_LeaderboardReset.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <string>
#include <vector>
#include <unordered_map>

struct G_GetLeaderboardResetsResponseData {
	static void ConvertToGodotModel(const RGN::Modules::Leaderboard::GetLeaderboardResetsResponseData& source, godot::Dictionary& target) {
        godot::Array g_target_resets;
        for (const auto& source_resets_item : source.resets) {
            godot::Dictionary g_source_resets_item;
            godot::Dictionary g_g_source_resets_item = g_source_resets_item;
            G_LeaderboardReset::ConvertToGodotModel(source_resets_item, g_g_source_resets_item);
            g_target_resets.push_back(g_source_resets_item);
        }
        target["resets"] = g_target_resets;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Leaderboard::GetLeaderboardResetsResponseData& target) {
        godot::Array g_target_resets = source["resets"];
        for (int i = 0; i < g_target_resets.size(); ++i) {
            godot::Dictionary g_target_resets_item = g_target_resets[i];
            RGN::Modules::Leaderboard::LeaderboardReset cpp_source_resets_item;
            G_LeaderboardReset::ConvertToCoreModel(g_target_resets_item, cpp_source_resets_item);
            target.resets.push_back(cpp_source_resets_item);
        }
	}
};
