#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Store/SetPricesRequestData.h"
#include "../../../../../Generated/RGN/Modules/VirtualItems/PriceInfo.h"
#include "../VirtualItems/G_PriceInfo.h"
#include "../../../../../Generated/RGN/Model/Request/BaseRequestData.h"
#include "../../Model/Request/G_BaseRequestData.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <string>
#include <vector>
#include <unordered_map>

struct G_SetPricesRequestData {
	static void ConvertToGodotModel(const RGN::Modules::Store::SetPricesRequestData& source, godot::Dictionary& target) {
        target["offerId"] = godot::String(source.offerId.c_str());
        godot::Array g_target_prices;
        for (const auto& source_prices_item : source.prices) {
            godot::Dictionary g_source_prices_item;
            godot::Dictionary g_g_source_prices_item = g_source_prices_item;
            G_PriceInfo::ConvertToGodotModel(source_prices_item, g_g_source_prices_item);
            g_target_prices.push_back(g_source_prices_item);
        }
        target["prices"] = g_target_prices;
		G_BaseRequestData::ConvertToGodotModel(source, target);
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Store::SetPricesRequestData& target) {
        godot::String g_source_offerId = source["offerId"];
        target.offerId = std::string(g_source_offerId.utf8().get_data());
        godot::Array g_target_prices = source["prices"];
        for (int i = 0; i < g_target_prices.size(); ++i) {
            godot::Dictionary g_target_prices_item = g_target_prices[i];
            RGN::Modules::VirtualItems::PriceInfo cpp_source_prices_item;
            G_PriceInfo::ConvertToCoreModel(g_target_prices_item, cpp_source_prices_item);
            target.prices.push_back(cpp_source_prices_item);
        }
		G_BaseRequestData::ConvertToCoreModel(source, target);
	}
};
