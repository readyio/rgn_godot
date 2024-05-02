#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/UserProfile/UserData.h"
#include "../../../../../Generated/RGN/Modules/UserProfile/UserProfilePicture.h"
#include "G_UserProfilePicture.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_UserData {
	static void ConvertToGodotModel(const RGN::Modules::UserProfile::UserData& source, godot::Dictionary& target) {
        target["userId"] = godot::String(source.userId.c_str());
        target["email"] = godot::String(source.email.c_str());
        target["displayName"] = godot::String(source.displayName.c_str());
        godot::Dictionary g_target_profilePicture = target["profilePicture"];
        G_UserProfilePicture::ConvertToGodotModel(source.profilePicture, g_target_profilePicture);
        target["bio"] = godot::String(source.bio.c_str());
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::UserProfile::UserData& target) {
        godot::String g_source_userId = source["userId"];
        target.userId = std::string(g_source_userId.utf8().get_data());
        godot::String g_source_email = source["email"];
        target.email = std::string(g_source_email.utf8().get_data());
        godot::String g_source_displayName = source["displayName"];
        target.displayName = std::string(g_source_displayName.utf8().get_data());
        G_UserProfilePicture::ConvertToCoreModel(source["profilePicture"], target.profilePicture);
        godot::String g_source_bio = source["bio"];
        target.bio = std::string(g_source_bio.utf8().get_data());
	}
};
