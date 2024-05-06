#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Matchmaking/GetMatchResponseData.h"
#include "../../../../../Generated/RGN/Modules/Matchmaking/MatchmakingData.h"
#include "G_MatchmakingData.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_GetMatchResponseData {
	static void ConvertToGodotModel(const RGN::Modules::Matchmaking::GetMatchResponseData& source, godot::Dictionary& target) {
        godot::Dictionary g_target_match;
        G_MatchmakingData::ConvertToGodotModel(source.match, g_target_match);
        target["match"] = g_target_match;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Matchmaking::GetMatchResponseData& target) {
        G_MatchmakingData::ConvertToCoreModel(source["match"], target.match);
	}
};
