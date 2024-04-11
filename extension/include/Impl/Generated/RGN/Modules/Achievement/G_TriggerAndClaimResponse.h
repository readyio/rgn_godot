#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Achievement/TriggerAndClaimResponse.h"
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
 * This object is returned for the Trigger and Claim methods
 * In case the achievement gave the rewards the 
 * will be true. Otherwise it it false
 */
struct G_TriggerAndClaimResponse {
	static void ConvertToGodotModel(const RGN::Modules::Achievement::TriggerAndClaimResponse& source, godot::Dictionary& target) {
        target["rewardsHaveBeenGivenOut"] = source.rewardsHaveBeenGivenOut;
        godot::Array g_target_rewards;
        for (const auto& source_rewards_item : source.rewards) {
            godot::Dictionary g_source_rewards_item;
            godot::Dictionary g_g_source_rewards_item = g_source_rewards_item;
            G_AchievementReward::ConvertToGodotModel(source_rewards_item, g_g_source_rewards_item);
            g_target_rewards.push_back(g_source_rewards_item);
        }
        target["rewards"] = g_target_rewards;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Achievement::TriggerAndClaimResponse& target) {
        bool g_source_rewardsHaveBeenGivenOut = source["rewardsHaveBeenGivenOut"];
        target.rewardsHaveBeenGivenOut = g_source_rewardsHaveBeenGivenOut;
        godot::Array g_target_rewards = source["rewards"];
        for (int i = 0; i < g_target_rewards.size(); ++i) {
            godot::Dictionary g_target_rewards_item = g_target_rewards[i];
            RGN::Modules::Achievement::AchievementReward cpp_source_rewards_item;
            G_AchievementReward::ConvertToCoreModel(g_target_rewards_item, cpp_source_rewards_item);
            target.rewards.push_back(cpp_source_rewards_item);
        }
	}
};
