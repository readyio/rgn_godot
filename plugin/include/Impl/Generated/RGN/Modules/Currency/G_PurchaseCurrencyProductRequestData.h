#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Currency/PurchaseCurrencyProductRequestData.h"
#include "../../../../../Generated/RGN/Model/Request/BaseMigrationRequestData.h"
#include "../../Model/Request/G_BaseMigrationRequestData.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_PurchaseCurrencyProductRequestData {
	static void ConvertToGodotModel(const RGN::Modules::Currency::PurchaseCurrencyProductRequestData& source, godot::Dictionary& target) {
        target["productId"] = godot::String(source.productId.c_str());
		G_BaseMigrationRequestData::ConvertToGodotModel(source, target);
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Currency::PurchaseCurrencyProductRequestData& target) {
        godot::String g_source_productId = source["productId"];
        target.productId = std::string(g_source_productId.utf8().get_data());
		G_BaseMigrationRequestData::ConvertToCoreModel(source, target);
	}
};
