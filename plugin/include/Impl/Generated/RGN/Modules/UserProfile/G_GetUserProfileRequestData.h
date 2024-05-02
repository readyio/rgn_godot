#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/UserProfile/GetUserProfileRequestData.h"
#include "../../../../../Generated/RGN/Model/Request/BaseMigrationRequestData.h"
#include "../../Model/Request/G_BaseMigrationRequestData.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_GetUserProfileRequestData {
	static void ConvertToGodotModel(const RGN::Modules::UserProfile::GetUserProfileRequestData& source, godot::Dictionary& target) {
        target["userId"] = godot::String(source.userId.c_str());
		G_BaseMigrationRequestData::ConvertToGodotModel(source, target);
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::UserProfile::GetUserProfileRequestData& target) {
        godot::String g_source_userId = source["userId"];
        target.userId = std::string(g_source_userId.utf8().get_data());
		G_BaseMigrationRequestData::ConvertToCoreModel(source, target);
	}
};
