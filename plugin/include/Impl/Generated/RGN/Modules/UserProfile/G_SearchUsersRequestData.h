#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/UserProfile/SearchUsersRequestData.h"
#include "../../../../../Generated/RGN/Model/Request/BaseMigrationRequestData.h"
#include "../../Model/Request/G_BaseMigrationRequestData.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_SearchUsersRequestData {
	static void ConvertToGodotModel(const RGN::Modules::UserProfile::SearchUsersRequestData& source, godot::Dictionary& target) {
        target["nicknameQuery"] = godot::String(source.nicknameQuery.c_str());
		G_BaseMigrationRequestData::ConvertToGodotModel(source, target);
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::UserProfile::SearchUsersRequestData& target) {
        godot::String g_source_nicknameQuery = source["nicknameQuery"];
        target.nicknameQuery = std::string(g_source_nicknameQuery.utf8().get_data());
		G_BaseMigrationRequestData::ConvertToCoreModel(source, target);
	}
};
