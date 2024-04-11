#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Leaderboard/LeaderboardReward.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <string>
#include <vector>
#include <unordered_map>

/**
 * A class that represents a leaderboard reward on Ready Games Network.
 */
struct G_LeaderboardReward {
	static void ConvertToGodotModel(const RGN::Modules::Leaderboard::LeaderboardReward& source, godot::Dictionary& target) {
        target["placeFrom"] = source.placeFrom;
        target["placeTo"] = source.placeTo;
        target["achievementId"] = godot::String(source.achievementId.c_str());
        target["quantity"] = source.quantity;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Leaderboard::LeaderboardReward& target) {
        int32_t g_source_placeFrom = source["placeFrom"];
        target.placeFrom = g_source_placeFrom;
        int32_t g_source_placeTo = source["placeTo"];
        target.placeTo = g_source_placeTo;
        godot::String g_source_achievementId = source["achievementId"];
        target.achievementId = std::string(g_source_achievementId.utf8().get_data());
        int32_t g_source_quantity = source["quantity"];
        target.quantity = g_source_quantity;
	}
};
