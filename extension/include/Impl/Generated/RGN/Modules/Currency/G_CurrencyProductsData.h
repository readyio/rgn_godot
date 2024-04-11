#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Currency/CurrencyProductsData.h"
#include "../../../../../Generated/RGN/Modules/Currency/CurrencyProduct.h"
#include "G_CurrencyProduct.h"
#include "../../../../../Generated/RGN/Modules/Currency/CurrencyOffer.h"
#include "G_CurrencyOffer.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <string>
#include <vector>
#include <unordered_map>

struct G_CurrencyProductsData {
	static void ConvertToGodotModel(const RGN::Modules::Currency::CurrencyProductsData& source, godot::Dictionary& target) {
        godot::Array g_target_products;
        for (const auto& source_products_item : source.products) {
            godot::Dictionary g_source_products_item;
            godot::Dictionary g_g_source_products_item = g_source_products_item;
            G_CurrencyProduct::ConvertToGodotModel(source_products_item, g_g_source_products_item);
            g_target_products.push_back(g_source_products_item);
        }
        target["products"] = g_target_products;
        godot::Array g_target_offers;
        for (const auto& source_offers_item : source.offers) {
            godot::Dictionary g_source_offers_item;
            godot::Dictionary g_g_source_offers_item = g_source_offers_item;
            G_CurrencyOffer::ConvertToGodotModel(source_offers_item, g_g_source_offers_item);
            g_target_offers.push_back(g_source_offers_item);
        }
        target["offers"] = g_target_offers;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Currency::CurrencyProductsData& target) {
        godot::Array g_target_products = source["products"];
        for (int i = 0; i < g_target_products.size(); ++i) {
            godot::Dictionary g_target_products_item = g_target_products[i];
            RGN::Modules::Currency::CurrencyProduct cpp_source_products_item;
            G_CurrencyProduct::ConvertToCoreModel(g_target_products_item, cpp_source_products_item);
            target.products.push_back(cpp_source_products_item);
        }
        godot::Array g_target_offers = source["offers"];
        for (int i = 0; i < g_target_offers.size(); ++i) {
            godot::Dictionary g_target_offers_item = g_target_offers[i];
            RGN::Modules::Currency::CurrencyOffer cpp_source_offers_item;
            G_CurrencyOffer::ConvertToCoreModel(g_target_offers_item, cpp_source_offers_item);
            target.offers.push_back(cpp_source_offers_item);
        }
	}
};
