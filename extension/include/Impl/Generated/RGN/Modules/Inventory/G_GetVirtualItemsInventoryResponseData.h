#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Inventory/GetVirtualItemsInventoryResponseData.h"
#include "../../../../../Generated/RGN/Modules/Inventory/InventoryItemData.h"
#include "G_InventoryItemData.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <string>
#include <vector>
#include <unordered_map>

struct G_GetVirtualItemsInventoryResponseData {
	static void ConvertToGodotModel(const RGN::Modules::Inventory::GetVirtualItemsInventoryResponseData& source, godot::Dictionary& target) {
        godot::Array g_target_virtualItemInventoryDatas;
        for (const auto& source_virtualItemInventoryDatas_item : source.virtualItemInventoryDatas) {
            godot::Dictionary g_source_virtualItemInventoryDatas_item;
            godot::Dictionary g_g_source_virtualItemInventoryDatas_item = g_source_virtualItemInventoryDatas_item;
            G_InventoryItemData::ConvertToGodotModel(source_virtualItemInventoryDatas_item, g_g_source_virtualItemInventoryDatas_item);
            g_target_virtualItemInventoryDatas.push_back(g_source_virtualItemInventoryDatas_item);
        }
        target["virtualItemInventoryDatas"] = g_target_virtualItemInventoryDatas;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Inventory::GetVirtualItemsInventoryResponseData& target) {
        godot::Array g_target_virtualItemInventoryDatas = source["virtualItemInventoryDatas"];
        for (int i = 0; i < g_target_virtualItemInventoryDatas.size(); ++i) {
            godot::Dictionary g_target_virtualItemInventoryDatas_item = g_target_virtualItemInventoryDatas[i];
            RGN::Modules::Inventory::InventoryItemData cpp_source_virtualItemInventoryDatas_item;
            G_InventoryItemData::ConvertToCoreModel(g_target_virtualItemInventoryDatas_item, cpp_source_virtualItemInventoryDatas_item);
            target.virtualItemInventoryDatas.push_back(cpp_source_virtualItemInventoryDatas_item);
        }
	}
};
