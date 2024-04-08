#pragma once

#include "Generated/RGN/Modules/Currency/CurrencyProductsData.h"
#include "Impl/Generated/RGN/Modules/Currency/G_CurrencyProduct.h"
#include "Impl/Generated/RGN/Modules/Currency/G_CurrencyOffer.h"
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <vector>

struct G_CurrencyProductsData {
    static void ConvertToGodotModel(const RGN::Modules::Currency::CurrencyProductsData& source, godot::Dictionary& target) {
        godot::Array products;
        godot::Array offers;
        for (const auto& source_products_item : source.products) {
            godot::Dictionary g_source_products_item;
            G_CurrencyProduct::ConvertToGodotModel(source_products_item, g_source_products_item);
            products.push_back(g_source_products_item);
        }
        for (const auto& source_offers_item : source.offers) {
            godot::Dictionary g_source_offers_item;
            G_CurrencyOffer::ConvertToGodotModel(source_offers_item, g_source_offers_item);
            products.push_back(g_source_offers_item);
        }
        target["products"] = products;
        target["offers"] = offers;
    }

    static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Currency::CurrencyProductsData& target) {
        godot::Array products = source["products"];
        godot::Array offers = source["offers"];
        for (int i = 0; i < products.size(); i++) {
            godot::Dictionary g_product = products[i];
            RGN::Modules::Currency::CurrencyProduct cpp_source_products_item;
            G_CurrencyProduct::ConvertToCoreModel(g_product, cpp_source_products_item);
            target.products.push_back(cpp_source_products_item);
        }
        for (int i = 0; i < offers.size(); i++) {
            godot::Dictionary g_offer = products[i];
            RGN::Modules::Currency::CurrencyOffer cpp_source_offers_item;
            G_CurrencyOffer::ConvertToCoreModel(g_offer, cpp_source_offers_item);
            target.offers.push_back(cpp_source_offers_item);
        }
    }
};
