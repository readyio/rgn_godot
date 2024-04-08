#pragma once

#include "Generated/RGN/Modules/Currency/RGNCoinEconomy.h"
#include "Impl/Generated/RGN/Modules/Currency/G_RGNCoinEconomyProduct.h"
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <vector>

struct G_RGNCoinEconomy {
    static void ConvertToGodotModel(const RGN::Modules::Currency::RGNCoinEconomy& source, godot::Dictionary& target) {
        godot::Array products;
        for (const auto& source_products_item : source.products) {
            godot::Dictionary g_source_products_item;
            G_RGNCoinEconomyProduct::ConvertToGodotModel(source_products_item, g_source_products_item);
            products.push_back(g_source_products_item);
        }
        target["products"] = products;
    }

    static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Currency::RGNCoinEconomy& target) {
        godot::Array products = source["products"];
        for (int i = 0; i < products.size(); i++) {
            godot::Dictionary g_product = products[i];
            RGN::Modules::Currency::RGNCoinEconomyProduct cpp_source_products_item;
            G_RGNCoinEconomyProduct::ConvertToCoreModel(g_product, cpp_source_products_item);
            target.products.push_back(cpp_source_products_item);
        }
    }
};
