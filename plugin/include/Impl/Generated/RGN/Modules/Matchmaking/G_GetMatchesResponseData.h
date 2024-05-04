#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Matchmaking/GetMatchesResponseData.h"
#include "../../../../../Generated/RGN/Modules/Matchmaking/MatchmakingData.h"
#include "G_MatchmakingData.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_GetMatchesResponseData {
	static void ConvertToGodotModel(const RGN::Modules::Matchmaking::GetMatchesResponseData& source, godot::Dictionary& target) {
        godot::Array g_target_matches;
        for (const auto& source_matches_item : source.matches) {
            godot::Dictionary g_source_matches_item;
            godot::Dictionary g_g_source_matches_item;
            G_MatchmakingData::ConvertToGodotModel(source_matches_item, g_g_source_matches_item);
            g_source_matches_item = g_g_source_matches_item;
            g_target_matches.push_back(g_source_matches_item);
        }
        target["matches"] = g_target_matches;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Matchmaking::GetMatchesResponseData& target) {
        godot::Array g_target_matches = source["matches"];
        for (int i = 0; i < g_target_matches.size(); ++i) {
            godot::Dictionary g_target_matches_item = g_target_matches[i];
            RGN::Modules::Matchmaking::MatchmakingData cpp_source_matches_item;
            G_MatchmakingData::ConvertToCoreModel(g_target_matches_item, cpp_source_matches_item);
            target.matches.push_back(cpp_source_matches_item);
        }
	}
};
