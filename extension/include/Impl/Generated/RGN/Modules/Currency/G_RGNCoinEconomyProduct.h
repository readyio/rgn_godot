#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Currency/RGNCoinEconomyProduct.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_RGNCoinEconomyProduct {
	static void ConvertToGodotModel(const RGN::Modules::Currency::RGNCoinEconomyProduct& source, godot::Dictionary& target) {
        target["uid"] = godot::String(source.uid.c_str());
        target["priceInUSD"] = source.priceInUSD;
        target["quantity"] = source.quantity;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Currency::RGNCoinEconomyProduct& target) {
        godot::String g_source_uid = source["uid"];
        target.uid = std::string(g_source_uid.utf8().get_data());
        float g_source_priceInUSD = source["priceInUSD"];
        target.priceInUSD = g_source_priceInUSD;
        int32_t g_source_quantity = source["quantity"];
        target.quantity = g_source_quantity;
	}
};
