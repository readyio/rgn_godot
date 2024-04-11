#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Achievement/CompletedAchievementHistoryEntry.h"
#include "../../../../../Generated/RGN/Modules/Achievement/AchievementReward.h"
#include "G_AchievementReward.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <string>
#include <vector>
#include <unordered_map>

/**
 * Represents completed achievement history entry for a given achievement
 * This data is comming from the users data
 */
struct G_CompletedAchievementHistoryEntry {
	static void ConvertToGodotModel(const RGN::Modules::Achievement::CompletedAchievementHistoryEntry& source, godot::Dictionary& target) {
        target["id"] = godot::String(source.id.c_str());
        target["valueToReach"] = source.valueToReach;
        godot::Array g_target_rewards;
        for (const auto& source_rewards_item : source.rewards) {
            godot::Dictionary g_source_rewards_item;
            godot::Dictionary g_g_source_rewards_item = g_source_rewards_item;
            G_AchievementReward::ConvertToGodotModel(source_rewards_item, g_g_source_rewards_item);
            g_target_rewards.push_back(g_source_rewards_item);
        }
        target["rewards"] = g_target_rewards;
        target["completeTime"] = source.completeTime;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Achievement::CompletedAchievementHistoryEntry& target) {
        godot::String g_source_id = source["id"];
        target.id = std::string(g_source_id.utf8().get_data());
        int32_t g_source_valueToReach = source["valueToReach"];
        target.valueToReach = g_source_valueToReach;
        godot::Array g_target_rewards = source["rewards"];
        for (int i = 0; i < g_target_rewards.size(); ++i) {
            godot::Dictionary g_target_rewards_item = g_target_rewards[i];
            RGN::Modules::Achievement::AchievementReward cpp_source_rewards_item;
            G_AchievementReward::ConvertToCoreModel(g_target_rewards_item, cpp_source_rewards_item);
            target.rewards.push_back(cpp_source_rewards_item);
        }
        int64_t g_source_completeTime = source["completeTime"];
        target.completeTime = g_source_completeTime;
	}
};
