#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Store/PurchaseResult.h"
#include "../../../../../Generated/RGN/Modules/Inventory/InventoryItemData.h"
#include "../Inventory/G_InventoryItemData.h"
#include "../../../../../Generated/RGN/Modules/Currency/Currency.h"
#include "../Currency/G_Currency.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_PurchaseResult {
	static void ConvertToGodotModel(const RGN::Modules::Store::PurchaseResult& source, godot::Dictionary& target) {
        target["offerId"] = godot::String(source.offerId.c_str());
        godot::Array g_target_items;
        for (const auto& source_items_item : source.items) {
            godot::Dictionary g_source_items_item;
            godot::Dictionary g_g_source_items_item;
            G_InventoryItemData::ConvertToGodotModel(source_items_item, g_g_source_items_item);
            g_source_items_item = g_g_source_items_item;
            g_target_items.push_back(g_source_items_item);
        }
        target["items"] = g_target_items;
        godot::Array g_target_updatedCurrencies;
        for (const auto& source_updatedCurrencies_item : source.updatedCurrencies) {
            godot::Dictionary g_source_updatedCurrencies_item;
            godot::Dictionary g_g_source_updatedCurrencies_item;
            G_Currency::ConvertToGodotModel(source_updatedCurrencies_item, g_g_source_updatedCurrencies_item);
            g_source_updatedCurrencies_item = g_g_source_updatedCurrencies_item;
            g_target_updatedCurrencies.push_back(g_source_updatedCurrencies_item);
        }
        target["updatedCurrencies"] = g_target_updatedCurrencies;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Store::PurchaseResult& target) {
        godot::String g_source_offerId = source["offerId"];
        target.offerId = std::string(g_source_offerId.utf8().get_data());
        godot::Array g_target_items = source["items"];
        for (int i = 0; i < g_target_items.size(); ++i) {
            godot::Dictionary g_target_items_item = g_target_items[i];
            RGN::Modules::Inventory::InventoryItemData cpp_source_items_item;
            G_InventoryItemData::ConvertToCoreModel(g_target_items_item, cpp_source_items_item);
            target.items.push_back(cpp_source_items_item);
        }
        godot::Array g_target_updatedCurrencies = source["updatedCurrencies"];
        for (int i = 0; i < g_target_updatedCurrencies.size(); ++i) {
            godot::Dictionary g_target_updatedCurrencies_item = g_target_updatedCurrencies[i];
            RGN::Modules::Currency::Currency cpp_source_updatedCurrencies_item;
            G_Currency::ConvertToCoreModel(g_target_updatedCurrencies_item, cpp_source_updatedCurrencies_item);
            target.updatedCurrencies.push_back(cpp_source_updatedCurrencies_item);
        }
	}
};
