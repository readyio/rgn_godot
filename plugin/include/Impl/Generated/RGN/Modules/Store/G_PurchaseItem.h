#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Store/PurchaseItem.h"
#include "../../../../../Generated/RGN/Modules/VirtualItems/VirtualItem.h"
#include "../VirtualItems/G_VirtualItem.h"
#include "../../../../../Generated/RGN/Modules/Inventory/InventoryItemData.h"
#include "../Inventory/G_InventoryItemData.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_PurchaseItem {
	static void ConvertToGodotModel(const RGN::Modules::Store::PurchaseItem& source, godot::Dictionary& target) {
        godot::Dictionary g_target_virtualItem;
        G_VirtualItem::ConvertToGodotModel(source.virtualItem, g_target_virtualItem);
        target["virtualItem"] = g_target_virtualItem;
        godot::Dictionary g_target_inventoryItem;
        G_InventoryItemData::ConvertToGodotModel(source.inventoryItem, g_target_inventoryItem);
        target["inventoryItem"] = g_target_inventoryItem;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Store::PurchaseItem& target) {
        G_VirtualItem::ConvertToCoreModel(source["virtualItem"], target.virtualItem);
        G_InventoryItemData::ConvertToCoreModel(source["inventoryItem"], target.inventoryItem);
	}
};
