#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Inventory/AddVirtualItemToUserInventoryRequestData.h"
#include "../../../../../Generated/RGN/Modules/Inventory/InventoryItemData.h"
#include "G_InventoryItemData.h"
#include "../../../../../Generated/RGN/Model/Request/BaseRequestData.h"
#include "../../Model/Request/G_BaseRequestData.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

/**
 * Request to add new item in user inventory
 */
struct G_AddVirtualItemToUserInventoryRequestData {
	static void ConvertToGodotModel(const RGN::Modules::Inventory::AddVirtualItemToUserInventoryRequestData& source, godot::Dictionary& target) {
        target["userId"] = godot::String(source.userId.c_str());
        godot::Dictionary g_target_virtualItemInventoryData;
        G_InventoryItemData::ConvertToGodotModel(source.virtualItemInventoryData, g_target_virtualItemInventoryData);
        target["virtualItemInventoryData"] = g_target_virtualItemInventoryData;
		G_BaseRequestData::ConvertToGodotModel(source, target);
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Inventory::AddVirtualItemToUserInventoryRequestData& target) {
        godot::String g_source_userId = source["userId"];
        target.userId = std::string(g_source_userId.utf8().get_data());
        G_InventoryItemData::ConvertToCoreModel(source["virtualItemInventoryData"], target.virtualItemInventoryData);
		G_BaseRequestData::ConvertToCoreModel(source, target);
	}
};
