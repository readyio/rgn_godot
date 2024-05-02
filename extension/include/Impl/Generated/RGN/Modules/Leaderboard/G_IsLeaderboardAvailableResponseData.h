#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Leaderboard/IsLeaderboardAvailableResponseData.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

/**
 * Availability information
 */
struct G_IsLeaderboardAvailableResponseData {
	static void ConvertToGodotModel(const RGN::Modules::Leaderboard::IsLeaderboardAvailableResponseData& source, godot::Dictionary& target) {
        target["isAvailable"] = source.isAvailable;
        target["reason"] = godot::String(source.reason.c_str());
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Leaderboard::IsLeaderboardAvailableResponseData& target) {
        bool g_source_isAvailable = source["isAvailable"];
        target.isAvailable = g_source_isAvailable;
        godot::String g_source_reason = source["reason"];
        target.reason = std::string(g_source_reason.utf8().get_data());
	}
};
