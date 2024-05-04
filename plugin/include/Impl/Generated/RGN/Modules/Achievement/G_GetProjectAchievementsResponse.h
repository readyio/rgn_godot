#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Achievement/GetProjectAchievementsResponse.h"
#include "../../../../../Generated/RGN/Modules/Achievement/DailyAchievements.h"
#include "G_DailyAchievements.h"
#include "../../../../../Generated/RGN/Modules/Achievement/PlayerProgressAchievements.h"
#include "G_PlayerProgressAchievements.h"
#include "../../../../../Generated/RGN/Modules/Achievement/PurchaseAchievements.h"
#include "G_PurchaseAchievements.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

/**
 * Currently active achievements for a project
 */
struct G_GetProjectAchievementsResponse {
	static void ConvertToGodotModel(const RGN::Modules::Achievement::GetProjectAchievementsResponse& source, godot::Dictionary& target) {
        godot::Array g_target_dailyAchievements;
        for (const auto& source_dailyAchievements_item : source.dailyAchievements) {
            godot::Dictionary g_source_dailyAchievements_item;
            godot::Dictionary g_g_source_dailyAchievements_item;
            G_DailyAchievements::ConvertToGodotModel(source_dailyAchievements_item, g_g_source_dailyAchievements_item);
            g_source_dailyAchievements_item = g_g_source_dailyAchievements_item;
            g_target_dailyAchievements.push_back(g_source_dailyAchievements_item);
        }
        target["dailyAchievements"] = g_target_dailyAchievements;
        godot::Array g_target_playerProgressAchievements;
        for (const auto& source_playerProgressAchievements_item : source.playerProgressAchievements) {
            godot::Dictionary g_source_playerProgressAchievements_item;
            godot::Dictionary g_g_source_playerProgressAchievements_item;
            G_PlayerProgressAchievements::ConvertToGodotModel(source_playerProgressAchievements_item, g_g_source_playerProgressAchievements_item);
            g_source_playerProgressAchievements_item = g_g_source_playerProgressAchievements_item;
            g_target_playerProgressAchievements.push_back(g_source_playerProgressAchievements_item);
        }
        target["playerProgressAchievements"] = g_target_playerProgressAchievements;
        godot::Array g_target_purchaseAchievements;
        for (const auto& source_purchaseAchievements_item : source.purchaseAchievements) {
            godot::Dictionary g_source_purchaseAchievements_item;
            godot::Dictionary g_g_source_purchaseAchievements_item;
            G_PurchaseAchievements::ConvertToGodotModel(source_purchaseAchievements_item, g_g_source_purchaseAchievements_item);
            g_source_purchaseAchievements_item = g_g_source_purchaseAchievements_item;
            g_target_purchaseAchievements.push_back(g_source_purchaseAchievements_item);
        }
        target["purchaseAchievements"] = g_target_purchaseAchievements;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Achievement::GetProjectAchievementsResponse& target) {
        godot::Array g_target_dailyAchievements = source["dailyAchievements"];
        for (int i = 0; i < g_target_dailyAchievements.size(); ++i) {
            godot::Dictionary g_target_dailyAchievements_item = g_target_dailyAchievements[i];
            RGN::Modules::Achievement::DailyAchievements cpp_source_dailyAchievements_item;
            G_DailyAchievements::ConvertToCoreModel(g_target_dailyAchievements_item, cpp_source_dailyAchievements_item);
            target.dailyAchievements.push_back(cpp_source_dailyAchievements_item);
        }
        godot::Array g_target_playerProgressAchievements = source["playerProgressAchievements"];
        for (int i = 0; i < g_target_playerProgressAchievements.size(); ++i) {
            godot::Dictionary g_target_playerProgressAchievements_item = g_target_playerProgressAchievements[i];
            RGN::Modules::Achievement::PlayerProgressAchievements cpp_source_playerProgressAchievements_item;
            G_PlayerProgressAchievements::ConvertToCoreModel(g_target_playerProgressAchievements_item, cpp_source_playerProgressAchievements_item);
            target.playerProgressAchievements.push_back(cpp_source_playerProgressAchievements_item);
        }
        godot::Array g_target_purchaseAchievements = source["purchaseAchievements"];
        for (int i = 0; i < g_target_purchaseAchievements.size(); ++i) {
            godot::Dictionary g_target_purchaseAchievements_item = g_target_purchaseAchievements[i];
            RGN::Modules::Achievement::PurchaseAchievements cpp_source_purchaseAchievements_item;
            G_PurchaseAchievements::ConvertToCoreModel(g_target_purchaseAchievements_item, cpp_source_purchaseAchievements_item);
            target.purchaseAchievements.push_back(cpp_source_purchaseAchievements_item);
        }
	}
};
