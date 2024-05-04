#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Inventory/InventoryItemData.h"
#include "../../../../../Generated/RGN/Modules/Inventory/VirtualItemUpgrade.h"
#include "G_VirtualItemUpgrade.h"
#include "../../../../../Generated/RGN/Modules/VirtualItems/Properties.h"
#include "../VirtualItems/G_Properties.h"
#include "../../../../../Generated/RGN/Modules/VirtualItems/VirtualItem.h"
#include "../VirtualItems/G_VirtualItem.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

/**
 * Represents the data structure of an inventory item within the Ready Games Network (RGN).
 */
struct G_InventoryItemData {
	static void ConvertToGodotModel(const RGN::Modules::Inventory::InventoryItemData& source, godot::Dictionary& target) {
        target["id"] = godot::String(source.id.c_str());
        target["virtualItemId"] = godot::String(source.virtualItemId.c_str());
        godot::Array g_target_appIds;
        for (const auto& source_appIds_item : source.appIds) {
            godot::String g_source_appIds_item;
            g_source_appIds_item = godot::String(source_appIds_item.c_str());
            g_target_appIds.push_back(g_source_appIds_item);
        }
        target["appIds"] = g_target_appIds;
        godot::Array g_target_tags;
        for (const auto& source_tags_item : source.tags) {
            godot::String g_source_tags_item;
            g_source_tags_item = godot::String(source_tags_item.c_str());
            g_target_tags.push_back(g_source_tags_item);
        }
        target["tags"] = g_target_tags;
        target["quantity"] = source.quantity;
        target["status"] = godot::String(source.status.c_str());
        target["createdAt"] = source.createdAt;
        target["updatedAt"] = source.updatedAt;
        godot::Array g_target_itemUpgrades;
        for (const auto& source_itemUpgrades_item : source.itemUpgrades) {
            godot::Dictionary g_source_itemUpgrades_item;
            godot::Dictionary g_g_source_itemUpgrades_item;
            G_VirtualItemUpgrade::ConvertToGodotModel(source_itemUpgrades_item, g_g_source_itemUpgrades_item);
            g_source_itemUpgrades_item = g_g_source_itemUpgrades_item;
            g_target_itemUpgrades.push_back(g_source_itemUpgrades_item);
        }
        target["itemUpgrades"] = g_target_itemUpgrades;
        godot::Array g_target_properties;
        for (const auto& source_properties_item : source.properties) {
            godot::Dictionary g_source_properties_item;
            godot::Dictionary g_g_source_properties_item;
            G_Properties::ConvertToGodotModel(source_properties_item, g_g_source_properties_item);
            g_source_properties_item = g_g_source_properties_item;
            g_target_properties.push_back(g_source_properties_item);
        }
        target["properties"] = g_target_properties;
        godot::Dictionary g_target_virtualItem;
        G_VirtualItem::ConvertToGodotModel(source.virtualItem, g_target_virtualItem);
        target["virtualItem"] = g_target_virtualItem;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Inventory::InventoryItemData& target) {
        godot::String g_source_id = source["id"];
        target.id = std::string(g_source_id.utf8().get_data());
        godot::String g_source_virtualItemId = source["virtualItemId"];
        target.virtualItemId = std::string(g_source_virtualItemId.utf8().get_data());
        godot::Array g_target_appIds = source["appIds"];
        for (int i = 0; i < g_target_appIds.size(); ++i) {
            godot::String g_target_appIds_item = g_target_appIds[i];
            string cpp_source_appIds_item;
            godot::String g_g_target_appIds_item = g_target_appIds_item;
            cpp_source_appIds_item = std::string(g_g_target_appIds_item.utf8().get_data());
            target.appIds.push_back(cpp_source_appIds_item);
        }
        godot::Array g_target_tags = source["tags"];
        for (int i = 0; i < g_target_tags.size(); ++i) {
            godot::String g_target_tags_item = g_target_tags[i];
            string cpp_source_tags_item;
            godot::String g_g_target_tags_item = g_target_tags_item;
            cpp_source_tags_item = std::string(g_g_target_tags_item.utf8().get_data());
            target.tags.push_back(cpp_source_tags_item);
        }
        int32_t g_source_quantity = source["quantity"];
        target.quantity = g_source_quantity;
        godot::String g_source_status = source["status"];
        target.status = std::string(g_source_status.utf8().get_data());
        int64_t g_source_createdAt = source["createdAt"];
        target.createdAt = g_source_createdAt;
        int64_t g_source_updatedAt = source["updatedAt"];
        target.updatedAt = g_source_updatedAt;
        godot::Array g_target_itemUpgrades = source["itemUpgrades"];
        for (int i = 0; i < g_target_itemUpgrades.size(); ++i) {
            godot::Dictionary g_target_itemUpgrades_item = g_target_itemUpgrades[i];
            RGN::Modules::Inventory::VirtualItemUpgrade cpp_source_itemUpgrades_item;
            G_VirtualItemUpgrade::ConvertToCoreModel(g_target_itemUpgrades_item, cpp_source_itemUpgrades_item);
            target.itemUpgrades.push_back(cpp_source_itemUpgrades_item);
        }
        godot::Array g_target_properties = source["properties"];
        for (int i = 0; i < g_target_properties.size(); ++i) {
            godot::Dictionary g_target_properties_item = g_target_properties[i];
            RGN::Modules::VirtualItems::Properties cpp_source_properties_item;
            G_Properties::ConvertToCoreModel(g_target_properties_item, cpp_source_properties_item);
            target.properties.push_back(cpp_source_properties_item);
        }
        G_VirtualItem::ConvertToCoreModel(source["virtualItem"], target.virtualItem);
	}
};
