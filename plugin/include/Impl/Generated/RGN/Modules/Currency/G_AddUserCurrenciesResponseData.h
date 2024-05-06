#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Currency/AddUserCurrenciesResponseData.h"
#include "../../../../../Generated/RGN/Modules/Currency/Currency.h"
#include "G_Currency.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_AddUserCurrenciesResponseData {
	static void ConvertToGodotModel(const RGN::Modules::Currency::AddUserCurrenciesResponseData& source, godot::Dictionary& target) {
        godot::Array g_target_userCurrencies;
        for (const auto& source_userCurrencies_item : source.userCurrencies) {
            godot::Dictionary g_source_userCurrencies_item;
            godot::Dictionary g_g_source_userCurrencies_item;
            G_Currency::ConvertToGodotModel(source_userCurrencies_item, g_g_source_userCurrencies_item);
            g_source_userCurrencies_item = g_g_source_userCurrencies_item;
            g_target_userCurrencies.push_back(g_source_userCurrencies_item);
        }
        target["userCurrencies"] = g_target_userCurrencies;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Currency::AddUserCurrenciesResponseData& target) {
        godot::Array g_target_userCurrencies = source["userCurrencies"];
        for (int i = 0; i < g_target_userCurrencies.size(); ++i) {
            godot::Dictionary g_target_userCurrencies_item = g_target_userCurrencies[i];
            RGN::Modules::Currency::Currency cpp_source_userCurrencies_item;
            G_Currency::ConvertToCoreModel(g_target_userCurrencies_item, cpp_source_userCurrencies_item);
            target.userCurrencies.push_back(cpp_source_userCurrencies_item);
        }
	}
};
