#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Store/GetStoreOffersWithVirtualItemsDataResponse.h"
#include "../../../../../Generated/RGN/Modules/Store/StoreOffer.h"
#include "G_StoreOffer.h"
#include "../../../../../Generated/RGN/Modules/VirtualItems/VirtualItem.h"
#include "../VirtualItems/G_VirtualItem.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <string>
#include <vector>
#include <unordered_map>

struct G_GetStoreOffersWithVirtualItemsDataResponse {
	static void ConvertToGodotModel(const RGN::Modules::Store::GetStoreOffersWithVirtualItemsDataResponse& source, godot::Dictionary& target) {
        godot::Array g_target_offers;
        for (const auto& source_offers_item : source.offers) {
            godot::Dictionary g_source_offers_item;
            godot::Dictionary g_g_source_offers_item = g_source_offers_item;
            G_StoreOffer::ConvertToGodotModel(source_offers_item, g_g_source_offers_item);
            g_target_offers.push_back(g_source_offers_item);
        }
        target["offers"] = g_target_offers;
        godot::Array g_target_virtualItems;
        for (const auto& source_virtualItems_item : source.virtualItems) {
            godot::Dictionary g_source_virtualItems_item;
            godot::Dictionary g_g_source_virtualItems_item = g_source_virtualItems_item;
            G_VirtualItem::ConvertToGodotModel(source_virtualItems_item, g_g_source_virtualItems_item);
            g_target_virtualItems.push_back(g_source_virtualItems_item);
        }
        target["virtualItems"] = g_target_virtualItems;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Store::GetStoreOffersWithVirtualItemsDataResponse& target) {
        godot::Array g_target_offers = source["offers"];
        for (int i = 0; i < g_target_offers.size(); ++i) {
            godot::Dictionary g_target_offers_item = g_target_offers[i];
            RGN::Modules::Store::StoreOffer cpp_source_offers_item;
            G_StoreOffer::ConvertToCoreModel(g_target_offers_item, cpp_source_offers_item);
            target.offers.push_back(cpp_source_offers_item);
        }
        godot::Array g_target_virtualItems = source["virtualItems"];
        for (int i = 0; i < g_target_virtualItems.size(); ++i) {
            godot::Dictionary g_target_virtualItems_item = g_target_virtualItems[i];
            RGN::Modules::VirtualItems::VirtualItem cpp_source_virtualItems_item;
            G_VirtualItem::ConvertToCoreModel(g_target_virtualItems_item, cpp_source_virtualItems_item);
            target.virtualItems.push_back(cpp_source_virtualItems_item);
        }
	}
};
