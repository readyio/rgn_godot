#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Store/BuyStoreOfferResponse.h"
#include "../../../../../Generated/RGN/Modules/Store/PurchaseItem.h"
#include "G_PurchaseItem.h"
#include "../../../../../Generated/RGN/Modules/Currency/Currency.h"
#include "../Currency/G_Currency.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_BuyStoreOfferResponse {
	static void ConvertToGodotModel(const RGN::Modules::Store::BuyStoreOfferResponse& source, godot::Dictionary& target) {
        target["offerId"] = godot::String(source.offerId.c_str());
        godot::Array g_target_purchasedItems;
        for (const auto& source_purchasedItems_item : source.purchasedItems) {
            godot::Dictionary g_source_purchasedItems_item;
            godot::Dictionary g_g_source_purchasedItems_item;
            G_PurchaseItem::ConvertToGodotModel(source_purchasedItems_item, g_g_source_purchasedItems_item);
            g_source_purchasedItems_item = g_g_source_purchasedItems_item;
            g_target_purchasedItems.push_back(g_source_purchasedItems_item);
        }
        target["purchasedItems"] = g_target_purchasedItems;
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

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Store::BuyStoreOfferResponse& target) {
        godot::String g_source_offerId = source["offerId"];
        target.offerId = std::string(g_source_offerId.utf8().get_data());
        godot::Array g_target_purchasedItems = source["purchasedItems"];
        for (int i = 0; i < g_target_purchasedItems.size(); ++i) {
            godot::Dictionary g_target_purchasedItems_item = g_target_purchasedItems[i];
            RGN::Modules::Store::PurchaseItem cpp_source_purchasedItems_item;
            G_PurchaseItem::ConvertToCoreModel(g_target_purchasedItems_item, cpp_source_purchasedItems_item);
            target.purchasedItems.push_back(cpp_source_purchasedItems_item);
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
