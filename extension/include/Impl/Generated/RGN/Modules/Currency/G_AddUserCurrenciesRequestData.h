#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Currency/AddUserCurrenciesRequestData.h"
#include "../../../../../Generated/RGN/Modules/Currency/Currency.h"
#include "G_Currency.h"
#include "../../../../../Generated/RGN/Model/Request/BaseRequestData.h"
#include "../../Model/Request/G_BaseRequestData.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <string>
#include <vector>
#include <unordered_map>

struct G_AddUserCurrenciesRequestData {
	static void ConvertToGodotModel(const RGN::Modules::Currency::AddUserCurrenciesRequestData& source, godot::Dictionary& target) {
        godot::Array g_target_currencies;
        for (const auto& source_currencies_item : source.currencies) {
            godot::Dictionary g_source_currencies_item;
            godot::Dictionary g_g_source_currencies_item = g_source_currencies_item;
            G_Currency::ConvertToGodotModel(source_currencies_item, g_g_source_currencies_item);
            g_target_currencies.push_back(g_source_currencies_item);
        }
        target["currencies"] = g_target_currencies;
		G_BaseRequestData::ConvertToGodotModel(source, target);
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Currency::AddUserCurrenciesRequestData& target) {
        godot::Array g_target_currencies = source["currencies"];
        for (int i = 0; i < g_target_currencies.size(); ++i) {
            godot::Dictionary g_target_currencies_item = g_target_currencies[i];
            RGN::Modules::Currency::Currency cpp_source_currencies_item;
            G_Currency::ConvertToCoreModel(g_target_currencies_item, cpp_source_currencies_item);
            target.currencies.push_back(cpp_source_currencies_item);
        }
		G_BaseRequestData::ConvertToCoreModel(source, target);
	}
};
