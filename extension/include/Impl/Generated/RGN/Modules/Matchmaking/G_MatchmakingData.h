#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Matchmaking/MatchmakingData.h"
#include "../../../../../Generated/RGN/Modules/Matchmaking/Vote.h"
#include "G_Vote.h"
#include "../../../../../Generated/RGN/Model/ParticipationFee.h"
#include "../../Model/G_ParticipationFee.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <string>
#include <vector>
#include <unordered_map>

/**
 * Encapsulates all data necessary to create, manage and finalize a matchmaking process in the Ready Games Network (RGN).
 * This data includes match configuration, participant data, voting data, and match lifecycle timestamps.
 */
struct G_MatchmakingData {
	static void ConvertToGodotModel(const RGN::Modules::Matchmaking::MatchmakingData& source, godot::Dictionary& target) {
        target["id"] = godot::String(source.id.c_str());
        target["appId"] = godot::String(source.appId.c_str());
        target["type"] = godot::String(source.type.c_str());
        target["finishType"] = godot::String(source.finishType.c_str());
        target["startType"] = godot::String(source.startType.c_str());
        target["maxUsers"] = source.maxUsers;
        target["isStarted"] = source.isStarted;
        target["votingEnabled"] = source.votingEnabled;
        target["oncePerUserVoting"] = source.oncePerUserVoting;
        target["createdBy"] = godot::String(source.createdBy.c_str());
        target["updatedBy"] = godot::String(source.updatedBy.c_str());
        target["createdAt"] = source.createdAt;
        target["updatedAt"] = source.updatedAt;
        godot::Array g_target_participants;
        for (const auto& source_participants_item : source.participants) {
            godot::String g_source_participants_item;
            g_source_participants_item = godot::String(source_participants_item.c_str());
            g_target_participants.push_back(g_source_participants_item);
        }
        target["participants"] = g_target_participants;
        godot::Array g_target_votes;
        for (const auto& source_votes_item : source.votes) {
            godot::Dictionary g_source_votes_item;
            godot::Dictionary g_g_source_votes_item = g_source_votes_item;
            G_Vote::ConvertToGodotModel(source_votes_item, g_g_source_votes_item);
            g_target_votes.push_back(g_source_votes_item);
        }
        target["votes"] = g_target_votes;
        godot::Dictionary g_target_participantsScore;
        for (const auto& [source_participantsScore_key, source_participantsScore_value] : source.participantsScore) {
            godot::String g_source_participantsScore_key;
            g_source_participantsScore_key = godot::String(source_participantsScore_key.c_str());
            int64_t g_source_participantsScore_value;
            g_source_participantsScore_value = source_participantsScore_value;
            g_target_participantsScore[g_source_participantsScore_key] = g_source_participantsScore_value;
        }
        target["participantsScore"] = g_target_participantsScore;
        godot::Dictionary g_target_participantsPayload;
        for (const auto& [source_participantsPayload_key, source_participantsPayload_value] : source.participantsPayload) {
            godot::String g_source_participantsPayload_key;
            g_source_participantsPayload_key = godot::String(source_participantsPayload_key.c_str());
            godot::String g_source_participantsPayload_value;
            g_source_participantsPayload_value = godot::String(source_participantsPayload_value.c_str());
            g_target_participantsPayload[g_source_participantsPayload_key] = g_source_participantsPayload_value;
        }
        target["participantsPayload"] = g_target_participantsPayload;
        godot::Array g_target_participationFees;
        for (const auto& source_participationFees_item : source.participationFees) {
            godot::Dictionary g_source_participationFees_item;
            godot::Dictionary g_g_source_participationFees_item = g_source_participationFees_item;
            G_ParticipationFee::ConvertToGodotModel(source_participationFees_item, g_g_source_participationFees_item);
            g_target_participationFees.push_back(g_source_participationFees_item);
        }
        target["participationFees"] = g_target_participationFees;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Matchmaking::MatchmakingData& target) {
        godot::String g_source_id = source["id"];
        target.id = std::string(g_source_id.utf8().get_data());
        godot::String g_source_appId = source["appId"];
        target.appId = std::string(g_source_appId.utf8().get_data());
        godot::String g_source_type = source["type"];
        target.type = std::string(g_source_type.utf8().get_data());
        godot::String g_source_finishType = source["finishType"];
        target.finishType = std::string(g_source_finishType.utf8().get_data());
        godot::String g_source_startType = source["startType"];
        target.startType = std::string(g_source_startType.utf8().get_data());
        int32_t g_source_maxUsers = source["maxUsers"];
        target.maxUsers = g_source_maxUsers;
        bool g_source_isStarted = source["isStarted"];
        target.isStarted = g_source_isStarted;
        bool g_source_votingEnabled = source["votingEnabled"];
        target.votingEnabled = g_source_votingEnabled;
        bool g_source_oncePerUserVoting = source["oncePerUserVoting"];
        target.oncePerUserVoting = g_source_oncePerUserVoting;
        godot::String g_source_createdBy = source["createdBy"];
        target.createdBy = std::string(g_source_createdBy.utf8().get_data());
        godot::String g_source_updatedBy = source["updatedBy"];
        target.updatedBy = std::string(g_source_updatedBy.utf8().get_data());
        int64_t g_source_createdAt = source["createdAt"];
        target.createdAt = g_source_createdAt;
        int64_t g_source_updatedAt = source["updatedAt"];
        target.updatedAt = g_source_updatedAt;
        godot::Array g_target_participants = source["participants"];
        for (int i = 0; i < g_target_participants.size(); ++i) {
            godot::String g_target_participants_item = g_target_participants[i];
            string cpp_source_participants_item;
            godot::String g_g_target_participants_item = g_target_participants_item;
            cpp_source_participants_item = std::string(g_g_target_participants_item.utf8().get_data());
            target.participants.push_back(cpp_source_participants_item);
        }
        godot::Array g_target_votes = source["votes"];
        for (int i = 0; i < g_target_votes.size(); ++i) {
            godot::Dictionary g_target_votes_item = g_target_votes[i];
            RGN::Modules::Matchmaking::Vote cpp_source_votes_item;
            G_Vote::ConvertToCoreModel(g_target_votes_item, cpp_source_votes_item);
            target.votes.push_back(cpp_source_votes_item);
        }
        godot::Dictionary g_source_participantsScore = source["participantsScore"];
        godot::Array g_source_participantsScore_keys = g_source_participantsScore.keys();
        for (int i = 0; i < g_source_participantsScore_keys.size(); ++i) {
            godot::String g_source_participantsScore_key = g_source_participantsScore_keys[i];
            int64_t g_source_participantsScore_value = g_source_participantsScore[g_source_participantsScore_key];
            string cpp_source_participantsScore_key;
            godot::String g_g_source_participantsScore_key = g_source_participantsScore_key;
            cpp_source_participantsScore_key = std::string(g_g_source_participantsScore_key.utf8().get_data());
            int64_t cpp_source_participantsScore_value;
            int64_t g_g_source_participantsScore_value = g_source_participantsScore_value;
            cpp_source_participantsScore_value = g_g_source_participantsScore_value;
            target.participantsScore.insert({cpp_source_participantsScore_key, cpp_source_participantsScore_value});
        }
        godot::Dictionary g_source_participantsPayload = source["participantsPayload"];
        godot::Array g_source_participantsPayload_keys = g_source_participantsPayload.keys();
        for (int i = 0; i < g_source_participantsPayload_keys.size(); ++i) {
            godot::String g_source_participantsPayload_key = g_source_participantsPayload_keys[i];
            godot::String g_source_participantsPayload_value = g_source_participantsPayload[g_source_participantsPayload_key];
            string cpp_source_participantsPayload_key;
            godot::String g_g_source_participantsPayload_key = g_source_participantsPayload_key;
            cpp_source_participantsPayload_key = std::string(g_g_source_participantsPayload_key.utf8().get_data());
            string cpp_source_participantsPayload_value;
            godot::String g_g_source_participantsPayload_value = g_source_participantsPayload_value;
            cpp_source_participantsPayload_value = std::string(g_g_source_participantsPayload_value.utf8().get_data());
            target.participantsPayload.insert({cpp_source_participantsPayload_key, cpp_source_participantsPayload_value});
        }
        godot::Array g_target_participationFees = source["participationFees"];
        for (int i = 0; i < g_target_participationFees.size(); ++i) {
            godot::Dictionary g_target_participationFees_item = g_target_participationFees[i];
            RGN::Model::ParticipationFee cpp_source_participationFees_item;
            G_ParticipationFee::ConvertToCoreModel(g_target_participationFees_item, cpp_source_participationFees_item);
            target.participationFees.push_back(cpp_source_participationFees_item);
        }
	}
};
