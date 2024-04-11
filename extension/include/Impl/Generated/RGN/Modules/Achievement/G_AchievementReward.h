#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Achievement/AchievementReward.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <string>
#include <vector>
#include <unordered_map>

/**
 * This class represents the AchievementReward in the Ready Games Network (RGN) Unity SDK's AchievementsModule.
 * An AchievementReward is a generic type of reward that can be earned by the user upon completing an achievement.
 * This could be a Virtual Item, Currency Coins, Progression, or Leaderboard Score rewards depending on the `type`.
 */
struct G_AchievementReward {
	static void ConvertToGodotModel(const RGN::Modules::Achievement::AchievementReward& source, godot::Dictionary& target) {
        target["type"] = godot::String(source.type.c_str());
        godot::Array g_target_appIds;
        for (const auto& source_appIds_item : source.appIds) {
            godot::String g_source_appIds_item;
            g_source_appIds_item = godot::String(source_appIds_item.c_str());
            g_target_appIds.push_back(g_source_appIds_item);
        }
        target["appIds"] = g_target_appIds;
        target["name"] = godot::String(source.name.c_str());
        target["quantity"] = source.quantity;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Achievement::AchievementReward& target) {
        godot::String g_source_type = source["type"];
        target.type = std::string(g_source_type.utf8().get_data());
        godot::Array g_target_appIds = source["appIds"];
        for (int i = 0; i < g_target_appIds.size(); ++i) {
            godot::String g_target_appIds_item = g_target_appIds[i];
            string cpp_source_appIds_item;
            godot::String g_g_target_appIds_item = g_target_appIds_item;
            cpp_source_appIds_item = std::string(g_g_target_appIds_item.utf8().get_data());
            target.appIds.push_back(cpp_source_appIds_item);
        }
        godot::String g_source_name = source["name"];
        target.name = std::string(g_source_name.utf8().get_data());
        int32_t g_source_quantity = source["quantity"];
        target.quantity = g_source_quantity;
	}
};
