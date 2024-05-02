#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Creator/CreatorSaleItem.h"
#include "../../../../../Generated/RGN/Modules/Currency/Currency.h"
#include "../Currency/G_Currency.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_CreatorSaleItem {
	static void ConvertToGodotModel(const RGN::Modules::Creator::CreatorSaleItem& source, godot::Dictionary& target) {
        target["id"] = godot::String(source.id.c_str());
        target["name"] = godot::String(source.name.c_str());
        target["totalUnit"] = source.totalUnit;
        godot::Array g_target_totalCurrencies;
        for (const auto& source_totalCurrencies_item : source.totalCurrencies) {
            godot::Dictionary g_source_totalCurrencies_item;
            godot::Dictionary g_g_source_totalCurrencies_item = g_source_totalCurrencies_item;
            G_Currency::ConvertToGodotModel(source_totalCurrencies_item, g_g_source_totalCurrencies_item);
            g_target_totalCurrencies.push_back(g_source_totalCurrencies_item);
        }
        target["totalCurrencies"] = g_target_totalCurrencies;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Creator::CreatorSaleItem& target) {
        godot::String g_source_id = source["id"];
        target.id = std::string(g_source_id.utf8().get_data());
        godot::String g_source_name = source["name"];
        target.name = std::string(g_source_name.utf8().get_data());
        int32_t g_source_totalUnit = source["totalUnit"];
        target.totalUnit = g_source_totalUnit;
        godot::Array g_target_totalCurrencies = source["totalCurrencies"];
        for (int i = 0; i < g_target_totalCurrencies.size(); ++i) {
            godot::Dictionary g_target_totalCurrencies_item = g_target_totalCurrencies[i];
            RGN::Modules::Currency::Currency cpp_source_totalCurrencies_item;
            G_Currency::ConvertToCoreModel(g_target_totalCurrencies_item, cpp_source_totalCurrencies_item);
            target.totalCurrencies.push_back(cpp_source_totalCurrencies_item);
        }
	}
};
