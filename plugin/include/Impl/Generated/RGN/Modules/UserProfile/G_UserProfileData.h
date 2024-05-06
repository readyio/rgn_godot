#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/UserProfile/UserProfileData.h"
#include "../../../../../Generated/RGN/Modules/Currency/Currency.h"
#include "../Currency/G_Currency.h"
#include "../../../../../Generated/RGN/Modules/UserProfile/UserData.h"
#include "G_UserData.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_UserProfileData {
	static void ConvertToGodotModel(const RGN::Modules::UserProfile::UserProfileData& source, godot::Dictionary& target) {
        target["lastAppPackageName"] = godot::String(source.lastAppPackageName.c_str());
        target["invisibleStatus"] = source.invisibleStatus;
        godot::Array g_target_currencies;
        for (const auto& source_currencies_item : source.currencies) {
            godot::Dictionary g_source_currencies_item;
            godot::Dictionary g_g_source_currencies_item;
            G_Currency::ConvertToGodotModel(source_currencies_item, g_g_source_currencies_item);
            g_source_currencies_item = g_g_source_currencies_item;
            g_target_currencies.push_back(g_source_currencies_item);
        }
        target["currencies"] = g_target_currencies;
		G_UserData::ConvertToGodotModel(source, target);
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::UserProfile::UserProfileData& target) {
        godot::String g_source_lastAppPackageName = source["lastAppPackageName"];
        target.lastAppPackageName = std::string(g_source_lastAppPackageName.utf8().get_data());
        bool g_source_invisibleStatus = source["invisibleStatus"];
        target.invisibleStatus = g_source_invisibleStatus;
        godot::Array g_target_currencies = source["currencies"];
        for (int i = 0; i < g_target_currencies.size(); ++i) {
            godot::Dictionary g_target_currencies_item = g_target_currencies[i];
            RGN::Modules::Currency::Currency cpp_source_currencies_item;
            G_Currency::ConvertToCoreModel(g_target_currencies_item, cpp_source_currencies_item);
            target.currencies.push_back(cpp_source_currencies_item);
        }
		G_UserData::ConvertToCoreModel(source, target);
	}
};
