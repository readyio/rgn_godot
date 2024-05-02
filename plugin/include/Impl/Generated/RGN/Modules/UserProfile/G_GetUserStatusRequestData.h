#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/UserProfile/GetUserStatusRequestData.h"
#include "../../../../../Generated/RGN/Model/Request/BaseRequestData.h"
#include "../../Model/Request/G_BaseRequestData.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_GetUserStatusRequestData {
	static void ConvertToGodotModel(const RGN::Modules::UserProfile::GetUserStatusRequestData& source, godot::Dictionary& target) {
        target["userId"] = godot::String(source.userId.c_str());
		G_BaseRequestData::ConvertToGodotModel(source, target);
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::UserProfile::GetUserStatusRequestData& target) {
        godot::String g_source_userId = source["userId"];
        target.userId = std::string(g_source_userId.utf8().get_data());
		G_BaseRequestData::ConvertToCoreModel(source, target);
	}
};
