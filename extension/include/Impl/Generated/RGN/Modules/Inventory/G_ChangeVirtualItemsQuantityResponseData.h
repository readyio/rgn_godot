#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Inventory/ChangeVirtualItemsQuantityResponseData.h"
#include "../../../../../Generated/RGN/Modules/VirtualItems/VirtualItem.h"
#include "../VirtualItems/G_VirtualItem.h"
#include "../../../../../Generated/RGN/Model/Request/BaseRequestData.h"
#include "../../Model/Request/G_BaseRequestData.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <string>
#include <vector>
#include <unordered_map>

struct G_ChangeVirtualItemsQuantityResponseData {
	static void ConvertToGodotModel(const RGN::Modules::Inventory::ChangeVirtualItemsQuantityResponseData& source, godot::Dictionary& target) {
        godot::Array g_target_updatedItems;
        for (const auto& source_updatedItems_item : source.updatedItems) {
            godot::Dictionary g_source_updatedItems_item;
            godot::Dictionary g_g_source_updatedItems_item = g_source_updatedItems_item;
            G_VirtualItem::ConvertToGodotModel(source_updatedItems_item, g_g_source_updatedItems_item);
            g_target_updatedItems.push_back(g_source_updatedItems_item);
        }
        target["updatedItems"] = g_target_updatedItems;
		G_BaseRequestData::ConvertToGodotModel(source, target);
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Inventory::ChangeVirtualItemsQuantityResponseData& target) {
        godot::Array g_target_updatedItems = source["updatedItems"];
        for (int i = 0; i < g_target_updatedItems.size(); ++i) {
            godot::Dictionary g_target_updatedItems_item = g_target_updatedItems[i];
            RGN::Modules::VirtualItems::VirtualItem cpp_source_updatedItems_item;
            G_VirtualItem::ConvertToCoreModel(g_target_updatedItems_item, cpp_source_updatedItems_item);
            target.updatedItems.push_back(cpp_source_updatedItems_item);
        }
		G_BaseRequestData::ConvertToCoreModel(source, target);
	}
};
