#pragma once

#include "Generated/RGN/Modules/Currency/CurrencyOffer.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <string>

struct G_CurrencyOffer {
    static void ConvertToGodotModel(const RGN::Modules::Currency::CurrencyOffer& source, godot::Dictionary& target) {
        godot::String g_productId = godot::String(source.productId.c_str());
        godot::String g_offeredProductId = godot::String(source.offeredProductId.c_str());
        double g_remainingTime = source.remainingTime;
        float g_offeringPrice = source.offeringPrice;
        godot::String g_promotionalMessage = godot::String(source.promotionalMessage.c_str());
        target["productId"] = g_productId;
        target["offeredProductId"] = g_offeredProductId;
        target["remainingTime"] = g_remainingTime;
        target["offeringPrice"] = g_offeringPrice;
        target["promotionalMessage"] = g_promotionalMessage;
    }

    static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Currency::CurrencyOffer& target) {
        godot::String g_productId = source["productId"];
        godot::String g_offeredProductId = source["offeredProductId"];
        int g_remainingTime = source["remainingTime"];
        int g_offeringPrice = source["offeringPrice"];
        godot::String g_promotionalMessage = source["promotionalMessage"];
        target.productId = std::string(g_productId.utf8().get_data());
        target.offeredProductId = std::string(g_offeredProductId.utf8().get_data());
        target.remainingTime = g_remainingTime;
        target.offeringPrice = g_offeringPrice;
        target.promotionalMessage = std::string(g_promotionalMessage.utf8().get_data());
    }
};