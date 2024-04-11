#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/UserProfile/UpdateUserProfileRequestData.h"
#include "../../../../../Generated/RGN/Model/Request/BaseMigrationRequestData.h"
#include "../../Model/Request/G_BaseMigrationRequestData.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <string>
#include <vector>
#include <unordered_map>

struct G_UpdateUserProfileRequestData {
	static void ConvertToGodotModel(const RGN::Modules::UserProfile::UpdateUserProfileRequestData& source, godot::Dictionary& target) {
        target["displayName"] = godot::String(source.displayName.c_str());
        target["bio"] = godot::String(source.bio.c_str());
		G_BaseMigrationRequestData::ConvertToGodotModel(source, target);
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::UserProfile::UpdateUserProfileRequestData& target) {
        godot::String g_source_displayName = source["displayName"];
        target.displayName = std::string(g_source_displayName.utf8().get_data());
        godot::String g_source_bio = source["bio"];
        target.bio = std::string(g_source_bio.utf8().get_data());
		G_BaseMigrationRequestData::ConvertToCoreModel(source, target);
	}
};
