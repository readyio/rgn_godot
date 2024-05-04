#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Currency/RGNCoinEconomy.h"
#include "../../../../../Generated/RGN/Modules/Currency/RGNCoinEconomyProduct.h"
#include "G_RGNCoinEconomyProduct.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_RGNCoinEconomy {
	static void ConvertToGodotModel(const RGN::Modules::Currency::RGNCoinEconomy& source, godot::Dictionary& target) {
        godot::Array g_target_products;
        for (const auto& source_products_item : source.products) {
            godot::Dictionary g_source_products_item;
            godot::Dictionary g_g_source_products_item;
            G_RGNCoinEconomyProduct::ConvertToGodotModel(source_products_item, g_g_source_products_item);
            g_source_products_item = g_g_source_products_item;
            g_target_products.push_back(g_source_products_item);
        }
        target["products"] = g_target_products;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Currency::RGNCoinEconomy& target) {
        godot::Array g_target_products = source["products"];
        for (int i = 0; i < g_target_products.size(); ++i) {
            godot::Dictionary g_target_products_item = g_target_products[i];
            RGN::Modules::Currency::RGNCoinEconomyProduct cpp_source_products_item;
            G_RGNCoinEconomyProduct::ConvertToCoreModel(g_target_products_item, cpp_source_products_item);
            target.products.push_back(cpp_source_products_item);
        }
	}
};
