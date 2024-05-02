#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Currency/CurrencyOffer.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_CurrencyOffer {
	static void ConvertToGodotModel(const RGN::Modules::Currency::CurrencyOffer& source, godot::Dictionary& target) {
        target["productId"] = godot::String(source.productId.c_str());
        target["offeredProductId"] = godot::String(source.offeredProductId.c_str());
        target["remainingTime"] = source.remainingTime;
        target["offeringPrice"] = source.offeringPrice;
        target["promotionalMessage"] = godot::String(source.promotionalMessage.c_str());
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Currency::CurrencyOffer& target) {
        godot::String g_source_productId = source["productId"];
        target.productId = std::string(g_source_productId.utf8().get_data());
        godot::String g_source_offeredProductId = source["offeredProductId"];
        target.offeredProductId = std::string(g_source_offeredProductId.utf8().get_data());
        int64_t g_source_remainingTime = source["remainingTime"];
        target.remainingTime = g_source_remainingTime;
        float g_source_offeringPrice = source["offeringPrice"];
        target.offeringPrice = g_source_offeringPrice;
        godot::String g_source_promotionalMessage = source["promotionalMessage"];
        target.promotionalMessage = std::string(g_source_promotionalMessage.utf8().get_data());
	}
};
