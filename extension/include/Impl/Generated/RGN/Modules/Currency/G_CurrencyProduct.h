#pragma once

#include "Generated/RGN/Modules/Currency/CurrencyProduct.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <string>

struct G_CurrencyProduct {
    static void ConvertToGodotModel(const RGN::Modules::Currency::CurrencyProduct& source, godot::Dictionary& target) {
        godot::String g_id = godot::String(source.id.c_str());
        godot::String g_currencyName = godot::String(source.currencyName.c_str());
        float g_price = source.price;
        int g_quantity = source.quantity;
        godot::String g_type = godot::String(source.type.c_str());
        godot::String g_promotionalSticker = godot::String(source.promotionalSticker.c_str());
        target["id"] = g_id;
        target["currencyName"] = g_currencyName;
        target["price"] = g_price;
        target["quantity"] = g_quantity;
        target["type"] = g_type;
        target["promotionalSticker"] = g_promotionalSticker;
    }

    static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Currency::CurrencyProduct& target) {
        godot::String g_id = source["id"];
        godot::String g_currencyName = source["currencyName"];
        int g_price = source["price"];
        int g_quantity = source["quantity"];
        godot::String g_type = source["type"];
        godot::String g_promotionalSticker = source["promotionalSticker"];
        target.id = std::string(g_id.utf8().get_data());
        target.currencyName = std::string(g_currencyName.utf8().get_data());
        target.price = g_price;
        target.quantity = g_quantity;
        target.type = std::string(g_type.utf8().get_data());
        target.promotionalSticker = std::string(g_promotionalSticker.utf8().get_data());
    }
};