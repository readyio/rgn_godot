#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Achievement/UserAchievement.h"
#include "../../../../../Generated/RGN/Modules/Achievement/CompletedAchievementHistoryEntry.h"
#include "G_CompletedAchievementHistoryEntry.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

/**
 * Represents completed achievement data from the users data
 * If the achievement is  then
 * this document can contain more that one
 */
struct G_UserAchievement {
	static void ConvertToGodotModel(const RGN::Modules::Achievement::UserAchievement& source, godot::Dictionary& target) {
        target["id"] = godot::String(source.id.c_str());
        target["value"] = source.value;
        target["valueToReach"] = source.valueToReach;
        target["isCompleted"] = source.isCompleted;
        target["isClaimed"] = source.isClaimed;
        target["lastCompleteTime"] = source.lastCompleteTime;
        godot::Array g_target_history;
        for (const auto& source_history_item : source.history) {
            godot::Dictionary g_source_history_item;
            godot::Dictionary g_g_source_history_item;
            G_CompletedAchievementHistoryEntry::ConvertToGodotModel(source_history_item, g_g_source_history_item);
            g_source_history_item = g_g_source_history_item;
            g_target_history.push_back(g_source_history_item);
        }
        target["history"] = g_target_history;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Achievement::UserAchievement& target) {
        godot::String g_source_id = source["id"];
        target.id = std::string(g_source_id.utf8().get_data());
        int32_t g_source_value = source["value"];
        target.value = g_source_value;
        int32_t g_source_valueToReach = source["valueToReach"];
        target.valueToReach = g_source_valueToReach;
        bool g_source_isCompleted = source["isCompleted"];
        target.isCompleted = g_source_isCompleted;
        bool g_source_isClaimed = source["isClaimed"];
        target.isClaimed = g_source_isClaimed;
        int64_t g_source_lastCompleteTime = source["lastCompleteTime"];
        target.lastCompleteTime = g_source_lastCompleteTime;
        godot::Array g_target_history = source["history"];
        for (int i = 0; i < g_target_history.size(); ++i) {
            godot::Dictionary g_target_history_item = g_target_history[i];
            RGN::Modules::Achievement::CompletedAchievementHistoryEntry cpp_source_history_item;
            G_CompletedAchievementHistoryEntry::ConvertToCoreModel(g_target_history_item, cpp_source_history_item);
            target.history.push_back(cpp_source_history_item);
        }
	}
};
