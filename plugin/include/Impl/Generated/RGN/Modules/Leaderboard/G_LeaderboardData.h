#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Leaderboard/LeaderboardData.h"
#include "../../../../../Generated/RGN/Modules/Leaderboard/LeaderboardReward.h"
#include "G_LeaderboardReward.h"
#include "../../../../../Generated/RGN/Model/TimeInfo.h"
#include "../../Model/G_TimeInfo.h"
#include "../../../../../Generated/RGN/Model/RequirementData.h"
#include "../../Model/G_RequirementData.h"
#include "../../../../../Generated/RGN/Model/ParticipationFee.h"
#include "../../Model/G_ParticipationFee.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

/**
 * A class that represents a leaderboard on Ready Games Network.
 */
struct G_LeaderboardData {
	static void ConvertToGodotModel(const RGN::Modules::Leaderboard::LeaderboardData& source, godot::Dictionary& target) {
        target["id"] = godot::String(source.id.c_str());
        godot::Array g_target_appIds;
        for (const auto& source_appIds_item : source.appIds) {
            godot::String g_source_appIds_item;
            g_source_appIds_item = godot::String(source_appIds_item.c_str());
            g_target_appIds.push_back(g_source_appIds_item);
        }
        target["appIds"] = g_target_appIds;
        target["requestName"] = godot::String(source.requestName.c_str());
        godot::Array g_target_tags;
        for (const auto& source_tags_item : source.tags) {
            godot::String g_source_tags_item;
            g_source_tags_item = godot::String(source_tags_item.c_str());
            g_target_tags.push_back(g_source_tags_item);
        }
        target["tags"] = g_target_tags;
        target["name"] = godot::String(source.name.c_str());
        target["description"] = godot::String(source.description.c_str());
        target["setBy"] = godot::String(source.setBy.c_str());
        target["invertSortOrder"] = source.invertSortOrder;
        target["decimalOffset"] = source.decimalOffset;
        target["type"] = godot::String(source.type.c_str());
        godot::Array g_target_rewardsAtReset;
        for (const auto& source_rewardsAtReset_item : source.rewardsAtReset) {
            godot::Dictionary g_source_rewardsAtReset_item;
            godot::Dictionary g_g_source_rewardsAtReset_item;
            G_LeaderboardReward::ConvertToGodotModel(source_rewardsAtReset_item, g_g_source_rewardsAtReset_item);
            g_source_rewardsAtReset_item = g_g_source_rewardsAtReset_item;
            g_target_rewardsAtReset.push_back(g_source_rewardsAtReset_item);
        }
        target["rewardsAtReset"] = g_target_rewardsAtReset;
        target["rewardsDrawType"] = godot::String(source.rewardsDrawType.c_str());
        target["createdAt"] = source.createdAt;
        target["updatedAt"] = source.updatedAt;
        target["createdBy"] = godot::String(source.createdBy.c_str());
        target["updatedBy"] = godot::String(source.updatedBy.c_str());
        godot::Dictionary g_target_time;
        G_TimeInfo::ConvertToGodotModel(source.time, g_target_time);
        target["time"] = g_target_time;
        godot::Dictionary g_target_requiredToJoin;
        G_RequirementData::ConvertToGodotModel(source.requiredToJoin, g_target_requiredToJoin);
        target["requiredToJoin"] = g_target_requiredToJoin;
        target["autoClaim"] = source.autoClaim;
        godot::Array g_target_participationFees;
        for (const auto& source_participationFees_item : source.participationFees) {
            godot::Dictionary g_source_participationFees_item;
            godot::Dictionary g_g_source_participationFees_item;
            G_ParticipationFee::ConvertToGodotModel(source_participationFees_item, g_g_source_participationFees_item);
            g_source_participationFees_item = g_g_source_participationFees_item;
            g_target_participationFees.push_back(g_source_participationFees_item);
        }
        target["participationFees"] = g_target_participationFees;
        target["totalEntriesNumber"] = source.totalEntriesNumber;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Leaderboard::LeaderboardData& target) {
        godot::String g_source_id = source["id"];
        target.id = std::string(g_source_id.utf8().get_data());
        godot::Array g_target_appIds = source["appIds"];
        for (int i = 0; i < g_target_appIds.size(); ++i) {
            godot::String g_target_appIds_item = g_target_appIds[i];
            string cpp_source_appIds_item;
            godot::String g_g_target_appIds_item = g_target_appIds_item;
            cpp_source_appIds_item = std::string(g_g_target_appIds_item.utf8().get_data());
            target.appIds.push_back(cpp_source_appIds_item);
        }
        godot::String g_source_requestName = source["requestName"];
        target.requestName = std::string(g_source_requestName.utf8().get_data());
        godot::Array g_target_tags = source["tags"];
        for (int i = 0; i < g_target_tags.size(); ++i) {
            godot::String g_target_tags_item = g_target_tags[i];
            string cpp_source_tags_item;
            godot::String g_g_target_tags_item = g_target_tags_item;
            cpp_source_tags_item = std::string(g_g_target_tags_item.utf8().get_data());
            target.tags.push_back(cpp_source_tags_item);
        }
        godot::String g_source_name = source["name"];
        target.name = std::string(g_source_name.utf8().get_data());
        godot::String g_source_description = source["description"];
        target.description = std::string(g_source_description.utf8().get_data());
        godot::String g_source_setBy = source["setBy"];
        target.setBy = std::string(g_source_setBy.utf8().get_data());
        bool g_source_invertSortOrder = source["invertSortOrder"];
        target.invertSortOrder = g_source_invertSortOrder;
        int32_t g_source_decimalOffset = source["decimalOffset"];
        target.decimalOffset = g_source_decimalOffset;
        godot::String g_source_type = source["type"];
        target.type = std::string(g_source_type.utf8().get_data());
        godot::Array g_target_rewardsAtReset = source["rewardsAtReset"];
        for (int i = 0; i < g_target_rewardsAtReset.size(); ++i) {
            godot::Dictionary g_target_rewardsAtReset_item = g_target_rewardsAtReset[i];
            RGN::Modules::Leaderboard::LeaderboardReward cpp_source_rewardsAtReset_item;
            G_LeaderboardReward::ConvertToCoreModel(g_target_rewardsAtReset_item, cpp_source_rewardsAtReset_item);
            target.rewardsAtReset.push_back(cpp_source_rewardsAtReset_item);
        }
        godot::String g_source_rewardsDrawType = source["rewardsDrawType"];
        target.rewardsDrawType = std::string(g_source_rewardsDrawType.utf8().get_data());
        int64_t g_source_createdAt = source["createdAt"];
        target.createdAt = g_source_createdAt;
        int64_t g_source_updatedAt = source["updatedAt"];
        target.updatedAt = g_source_updatedAt;
        godot::String g_source_createdBy = source["createdBy"];
        target.createdBy = std::string(g_source_createdBy.utf8().get_data());
        godot::String g_source_updatedBy = source["updatedBy"];
        target.updatedBy = std::string(g_source_updatedBy.utf8().get_data());
        G_TimeInfo::ConvertToCoreModel(source["time"], target.time);
        G_RequirementData::ConvertToCoreModel(source["requiredToJoin"], target.requiredToJoin);
        bool g_source_autoClaim = source["autoClaim"];
        target.autoClaim = g_source_autoClaim;
        godot::Array g_target_participationFees = source["participationFees"];
        for (int i = 0; i < g_target_participationFees.size(); ++i) {
            godot::Dictionary g_target_participationFees_item = g_target_participationFees[i];
            RGN::Model::ParticipationFee cpp_source_participationFees_item;
            G_ParticipationFee::ConvertToCoreModel(g_target_participationFees_item, cpp_source_participationFees_item);
            target.participationFees.push_back(cpp_source_participationFees_item);
        }
        int32_t g_source_totalEntriesNumber = source["totalEntriesNumber"];
        target.totalEntriesNumber = g_source_totalEntriesNumber;
	}
};
