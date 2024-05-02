#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Store/GetStoreOffersResponse.h"
#include "../../../../../Generated/RGN/Modules/Store/StoreOffer.h"
#include "G_StoreOffer.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_GetStoreOffersResponse {
	static void ConvertToGodotModel(const RGN::Modules::Store::GetStoreOffersResponse& source, godot::Dictionary& target) {
        godot::Array g_target_offers;
        for (const auto& source_offers_item : source.offers) {
            godot::Dictionary g_source_offers_item;
            godot::Dictionary g_g_source_offers_item = g_source_offers_item;
            G_StoreOffer::ConvertToGodotModel(source_offers_item, g_g_source_offers_item);
            g_target_offers.push_back(g_source_offers_item);
        }
        target["offers"] = g_target_offers;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Store::GetStoreOffersResponse& target) {
        godot::Array g_target_offers = source["offers"];
        for (int i = 0; i < g_target_offers.size(); ++i) {
            godot::Dictionary g_target_offers_item = g_target_offers[i];
            RGN::Modules::Store::StoreOffer cpp_source_offers_item;
            G_StoreOffer::ConvertToCoreModel(g_target_offers_item, cpp_source_offers_item);
            target.offers.push_back(cpp_source_offers_item);
        }
	}
};
