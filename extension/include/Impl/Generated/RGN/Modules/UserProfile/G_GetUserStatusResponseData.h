#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/UserProfile/GetUserStatusResponseData.h"
#include "../../../../../Generated/RGN/Model/Response/BaseResponseData.h"
#include "../../Model/Response/G_BaseResponseData.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_GetUserStatusResponseData {
	static void ConvertToGodotModel(const RGN::Modules::UserProfile::GetUserStatusResponseData& source, godot::Dictionary& target) {
        target["userStatus"] = static_cast<int32_t>(source.userStatus);
        target["lastAppPackageName"] = godot::String(source.lastAppPackageName.c_str());
        target["lastActivityTS"] = source.lastActivityTS;
		G_BaseResponseData::ConvertToGodotModel(source, target);
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::UserProfile::GetUserStatusResponseData& target) {
        int32_t g_source_userStatus = source["userStatus"];
        target.userStatus = static_cast<RGN::Modules::UserProfile::UserStatus>(g_source_userStatus);
        godot::String g_source_lastAppPackageName = source["lastAppPackageName"];
        target.lastAppPackageName = std::string(g_source_lastAppPackageName.utf8().get_data());
        int64_t g_source_lastActivityTS = source["lastActivityTS"];
        target.lastActivityTS = g_source_lastActivityTS;
		G_BaseResponseData::ConvertToCoreModel(source, target);
	}
};
