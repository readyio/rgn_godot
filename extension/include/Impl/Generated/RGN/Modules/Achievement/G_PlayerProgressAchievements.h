#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Achievement/PlayerProgressAchievements.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <string>
#include <vector>
#include <unordered_map>

/**
 * Player progress achievements. Triggered when the player progress field reaches the specified value.
 * Is triggered when 'game-updatePlayerProgress' or 'game-addPlayerProgress' is called.
 */
struct G_PlayerProgressAchievements {
	static void ConvertToGodotModel(const RGN::Modules::Achievement::PlayerProgressAchievements& source, godot::Dictionary& target) {
        target["playerProgressFieldName"] = godot::String(source.playerProgressFieldName.c_str());
        target["playerProgressFieldValueToReach"] = source.playerProgressFieldValueToReach;
        target["achievementId"] = godot::String(source.achievementId.c_str());
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Achievement::PlayerProgressAchievements& target) {
        godot::String g_source_playerProgressFieldName = source["playerProgressFieldName"];
        target.playerProgressFieldName = std::string(g_source_playerProgressFieldName.utf8().get_data());
        int32_t g_source_playerProgressFieldValueToReach = source["playerProgressFieldValueToReach"];
        target.playerProgressFieldValueToReach = g_source_playerProgressFieldValueToReach;
        godot::String g_source_achievementId = source["achievementId"];
        target.achievementId = std::string(g_source_achievementId.utf8().get_data());
	}
};
