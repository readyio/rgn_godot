#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/UserProfile/SearchUsersResultData.h"
#include "../../../../../Generated/RGN/Modules/UserProfile/UserData.h"
#include "G_UserData.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_SearchUsersResultData {
	static void ConvertToGodotModel(const RGN::Modules::UserProfile::SearchUsersResultData& source, godot::Dictionary& target) {
        godot::Array g_target_queryResult;
        for (const auto& source_queryResult_item : source.queryResult) {
            godot::Dictionary g_source_queryResult_item;
            godot::Dictionary g_g_source_queryResult_item = g_source_queryResult_item;
            G_UserData::ConvertToGodotModel(source_queryResult_item, g_g_source_queryResult_item);
            g_target_queryResult.push_back(g_source_queryResult_item);
        }
        target["queryResult"] = g_target_queryResult;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::UserProfile::SearchUsersResultData& target) {
        godot::Array g_target_queryResult = source["queryResult"];
        for (int i = 0; i < g_target_queryResult.size(); ++i) {
            godot::Dictionary g_target_queryResult_item = g_target_queryResult[i];
            RGN::Modules::UserProfile::UserData cpp_source_queryResult_item;
            G_UserData::ConvertToCoreModel(g_target_queryResult_item, cpp_source_queryResult_item);
            target.queryResult.push_back(cpp_source_queryResult_item);
        }
	}
};
