#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Inventory/InventoryItemsWithVirtualItemsData.h"
#include "../../../../../Generated/RGN/Modules/Inventory/InventoryItemData.h"
#include "G_InventoryItemData.h"
#include "../../../../../Generated/RGN/Modules/VirtualItems/VirtualItem.h"
#include "../VirtualItems/G_VirtualItem.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_InventoryItemsWithVirtualItemsData {
	static void ConvertToGodotModel(const RGN::Modules::Inventory::InventoryItemsWithVirtualItemsData& source, godot::Dictionary& target) {
        godot::Array g_target_items;
        for (const auto& source_items_item : source.items) {
            godot::Dictionary g_source_items_item;
            godot::Dictionary g_g_source_items_item;
            G_InventoryItemData::ConvertToGodotModel(source_items_item, g_g_source_items_item);
            g_source_items_item = g_g_source_items_item;
            g_target_items.push_back(g_source_items_item);
        }
        target["items"] = g_target_items;
        godot::Array g_target_virtualItems;
        for (const auto& source_virtualItems_item : source.virtualItems) {
            godot::Dictionary g_source_virtualItems_item;
            godot::Dictionary g_g_source_virtualItems_item;
            G_VirtualItem::ConvertToGodotModel(source_virtualItems_item, g_g_source_virtualItems_item);
            g_source_virtualItems_item = g_g_source_virtualItems_item;
            g_target_virtualItems.push_back(g_source_virtualItems_item);
        }
        target["virtualItems"] = g_target_virtualItems;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Inventory::InventoryItemsWithVirtualItemsData& target) {
        godot::Array g_target_items = source["items"];
        for (int i = 0; i < g_target_items.size(); ++i) {
            godot::Dictionary g_target_items_item = g_target_items[i];
            RGN::Modules::Inventory::InventoryItemData cpp_source_items_item;
            G_InventoryItemData::ConvertToCoreModel(g_target_items_item, cpp_source_items_item);
            target.items.push_back(cpp_source_items_item);
        }
        godot::Array g_target_virtualItems = source["virtualItems"];
        for (int i = 0; i < g_target_virtualItems.size(); ++i) {
            godot::Dictionary g_target_virtualItems_item = g_target_virtualItems[i];
            RGN::Modules::VirtualItems::VirtualItem cpp_source_virtualItems_item;
            G_VirtualItem::ConvertToCoreModel(g_target_virtualItems_item, cpp_source_virtualItems_item);
            target.virtualItems.push_back(cpp_source_virtualItems_item);
        }
	}
};
