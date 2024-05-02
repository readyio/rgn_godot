#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Currency/ClaimCurrencyResponseData.h"
#include "../../../../../Generated/RGN/Modules/Currency/Currency.h"
#include "G_Currency.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_ClaimCurrencyResponseData {
	static void ConvertToGodotModel(const RGN::Modules::Currency::ClaimCurrencyResponseData& source, godot::Dictionary& target) {
        target["isSuccess"] = source.isSuccess;
        godot::Array g_target_unclaimedCurrencies;
        for (const auto& source_unclaimedCurrencies_item : source.unclaimedCurrencies) {
            godot::Dictionary g_source_unclaimedCurrencies_item;
            godot::Dictionary g_g_source_unclaimedCurrencies_item = g_source_unclaimedCurrencies_item;
            G_Currency::ConvertToGodotModel(source_unclaimedCurrencies_item, g_g_source_unclaimedCurrencies_item);
            g_target_unclaimedCurrencies.push_back(g_source_unclaimedCurrencies_item);
        }
        target["unclaimedCurrencies"] = g_target_unclaimedCurrencies;
        godot::Array g_target_currencies;
        for (const auto& source_currencies_item : source.currencies) {
            godot::Dictionary g_source_currencies_item;
            godot::Dictionary g_g_source_currencies_item = g_source_currencies_item;
            G_Currency::ConvertToGodotModel(source_currencies_item, g_g_source_currencies_item);
            g_target_currencies.push_back(g_source_currencies_item);
        }
        target["currencies"] = g_target_currencies;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Currency::ClaimCurrencyResponseData& target) {
        bool g_source_isSuccess = source["isSuccess"];
        target.isSuccess = g_source_isSuccess;
        godot::Array g_target_unclaimedCurrencies = source["unclaimedCurrencies"];
        for (int i = 0; i < g_target_unclaimedCurrencies.size(); ++i) {
            godot::Dictionary g_target_unclaimedCurrencies_item = g_target_unclaimedCurrencies[i];
            RGN::Modules::Currency::Currency cpp_source_unclaimedCurrencies_item;
            G_Currency::ConvertToCoreModel(g_target_unclaimedCurrencies_item, cpp_source_unclaimedCurrencies_item);
            target.unclaimedCurrencies.push_back(cpp_source_unclaimedCurrencies_item);
        }
        godot::Array g_target_currencies = source["currencies"];
        for (int i = 0; i < g_target_currencies.size(); ++i) {
            godot::Dictionary g_target_currencies_item = g_target_currencies[i];
            RGN::Modules::Currency::Currency cpp_source_currencies_item;
            G_Currency::ConvertToCoreModel(g_target_currencies_item, cpp_source_currencies_item);
            target.currencies.push_back(cpp_source_currencies_item);
        }
	}
};
