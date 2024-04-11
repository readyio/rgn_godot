#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Leaderboard/LeaderboardEntry.h"
#include "../../../../../Generated/RGN/Modules/UserProfile/UserProfilePicture.h"
#include "../UserProfile/G_UserProfilePicture.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <string>
#include <vector>
#include <unordered_map>

/**
 * A class that represents an entry in the leaderboard.
 * This class serves as a Data Transfer Object (DTO) that contains details about a user's entry in the leaderboard.
 */
struct G_LeaderboardEntry {
	static void ConvertToGodotModel(const RGN::Modules::Leaderboard::LeaderboardEntry& source, godot::Dictionary& target) {
        target["userId"] = godot::String(source.userId.c_str());
        target["displayName"] = godot::String(source.displayName.c_str());
        godot::Dictionary g_target_profilePicture = target["profilePicture"];
        G_UserProfilePicture::ConvertToGodotModel(source.profilePicture, g_target_profilePicture);
        target["score"] = source.score;
        target["formattedScore"] = godot::String(source.formattedScore.c_str());
        target["place"] = source.place;
        target["extraData"] = godot::String(source.extraData.c_str());
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Leaderboard::LeaderboardEntry& target) {
        godot::String g_source_userId = source["userId"];
        target.userId = std::string(g_source_userId.utf8().get_data());
        godot::String g_source_displayName = source["displayName"];
        target.displayName = std::string(g_source_displayName.utf8().get_data());
        G_UserProfilePicture::ConvertToCoreModel(source["profilePicture"], target.profilePicture);
        int32_t g_source_score = source["score"];
        target.score = g_source_score;
        godot::String g_source_formattedScore = source["formattedScore"];
        target.formattedScore = std::string(g_source_formattedScore.utf8().get_data());
        int32_t g_source_place = source["place"];
        target.place = g_source_place;
        godot::String g_source_extraData = source["extraData"];
        target.extraData = std::string(g_source_extraData.utf8().get_data());
	}
};
