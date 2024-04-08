#pragma once

#include "Generated/RGN/Modules/Currency/RGNCoinEconomyProduct.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <string>

struct G_RGNCoinEconomyProduct {
    static void ConvertToGodotModel(const RGN::Modules::Currency::RGNCoinEconomyProduct& source, godot::Dictionary& target) {
        godot::String g_uid = godot::String(source.uid.c_str());
        float g_priceInUSD = source.priceInUSD;
        int g_quantity = source.quantity;
        target["uid"] = g_uid;
        target["priceInUSD"] = g_priceInUSD;
        target["quantity"] = g_quantity;
    }

    static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Currency::RGNCoinEconomyProduct& target) {
        godot::String g_uid = source["uid"];
        float g_priceInUSD = source["priceInUSD"];
        int g_quantity = source["quantity"];
        target.uid = std::string(g_uid.utf8().get_data());;
        target.priceInUSD = g_priceInUSD;
        target.quantity = g_quantity;
    }
};