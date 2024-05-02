#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Inventory/UpgradesResponseData.h"
#include "../../../../../Generated/RGN/Modules/Inventory/VirtualItemUpgrade.h"
#include "G_VirtualItemUpgrade.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_UpgradesResponseData {
	static void ConvertToGodotModel(const RGN::Modules::Inventory::UpgradesResponseData& source, godot::Dictionary& target) {
        target["ownedItemId"] = godot::String(source.ownedItemId.c_str());
        target["virtualItemId"] = godot::String(source.virtualItemId.c_str());
        godot::Array g_target_itemUpgrades;
        for (const auto& source_itemUpgrades_item : source.itemUpgrades) {
            godot::Dictionary g_source_itemUpgrades_item;
            godot::Dictionary g_g_source_itemUpgrades_item = g_source_itemUpgrades_item;
            G_VirtualItemUpgrade::ConvertToGodotModel(source_itemUpgrades_item, g_g_source_itemUpgrades_item);
            g_target_itemUpgrades.push_back(g_source_itemUpgrades_item);
        }
        target["itemUpgrades"] = g_target_itemUpgrades;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Inventory::UpgradesResponseData& target) {
        godot::String g_source_ownedItemId = source["ownedItemId"];
        target.ownedItemId = std::string(g_source_ownedItemId.utf8().get_data());
        godot::String g_source_virtualItemId = source["virtualItemId"];
        target.virtualItemId = std::string(g_source_virtualItemId.utf8().get_data());
        godot::Array g_target_itemUpgrades = source["itemUpgrades"];
        for (int i = 0; i < g_target_itemUpgrades.size(); ++i) {
            godot::Dictionary g_target_itemUpgrades_item = g_target_itemUpgrades[i];
            RGN::Modules::Inventory::VirtualItemUpgrade cpp_source_itemUpgrades_item;
            G_VirtualItemUpgrade::ConvertToCoreModel(g_target_itemUpgrades_item, cpp_source_itemUpgrades_item);
            target.itemUpgrades.push_back(cpp_source_itemUpgrades_item);
        }
	}
};
