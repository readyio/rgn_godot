#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Matchmaking/Vote.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

/**
 * Represents a vote in the matchmaking process.
 */
struct G_Vote {
	static void ConvertToGodotModel(const RGN::Modules::Matchmaking::Vote& source, godot::Dictionary& target) {
        target["voterId"] = godot::String(source.voterId.c_str());
        target["participantId"] = godot::String(source.participantId.c_str());
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Matchmaking::Vote& target) {
        godot::String g_source_voterId = source["voterId"];
        target.voterId = std::string(g_source_voterId.utf8().get_data());
        godot::String g_source_participantId = source["participantId"];
        target.participantId = std::string(g_source_participantId.utf8().get_data());
	}
};
