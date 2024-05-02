#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Currency/CurrencyProduct.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_CurrencyProduct {
	static void ConvertToGodotModel(const RGN::Modules::Currency::CurrencyProduct& source, godot::Dictionary& target) {
        target["id"] = godot::String(source.id.c_str());
        target["currencyName"] = godot::String(source.currencyName.c_str());
        target["price"] = source.price;
        target["quantity"] = source.quantity;
        target["type"] = godot::String(source.type.c_str());
        target["promotionalSticker"] = godot::String(source.promotionalSticker.c_str());
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Currency::CurrencyProduct& target) {
        godot::String g_source_id = source["id"];
        target.id = std::string(g_source_id.utf8().get_data());
        godot::String g_source_currencyName = source["currencyName"];
        target.currencyName = std::string(g_source_currencyName.utf8().get_data());
        float g_source_price = source["price"];
        target.price = g_source_price;
        int32_t g_source_quantity = source["quantity"];
        target.quantity = g_source_quantity;
        godot::String g_source_type = source["type"];
        target.type = std::string(g_source_type.utf8().get_data());
        godot::String g_source_promotionalSticker = source["promotionalSticker"];
        target.promotionalSticker = std::string(g_source_promotionalSticker.utf8().get_data());
	}
};
