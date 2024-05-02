#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Matchmaking/StartMatchResponseData.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_StartMatchResponseData {
	static void ConvertToGodotModel(const RGN::Modules::Matchmaking::StartMatchResponseData& source, godot::Dictionary& target) {
        target["matchId"] = godot::String(source.matchId.c_str());
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Matchmaking::StartMatchResponseData& target) {
        godot::String g_source_matchId = source["matchId"];
        target.matchId = std::string(g_source_matchId.utf8().get_data());
	}
};
