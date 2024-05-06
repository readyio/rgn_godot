#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Inventory/InventoryData.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_InventoryData {
	static void ConvertToGodotModel(const RGN::Modules::Inventory::InventoryData& source, godot::Dictionary& target) {
        target["id"] = godot::String(source.id.c_str());
        target["quantity"] = source.quantity;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Inventory::InventoryData& target) {
        godot::String g_source_id = source["id"];
        target.id = std::string(g_source_id.utf8().get_data());
        int32_t g_source_quantity = source["quantity"];
        target.quantity = g_source_quantity;
	}
};
