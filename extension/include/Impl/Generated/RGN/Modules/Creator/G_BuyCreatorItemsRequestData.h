#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Creator/BuyCreatorItemsRequestData.h"
#include "../../../../../Generated/RGN/Model/Request/BaseRequestData.h"
#include "../../Model/Request/G_BaseRequestData.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_BuyCreatorItemsRequestData {
	static void ConvertToGodotModel(const RGN::Modules::Creator::BuyCreatorItemsRequestData& source, godot::Dictionary& target) {
        godot::Array g_target_itemIds;
        for (const auto& source_itemIds_item : source.itemIds) {
            godot::String g_source_itemIds_item;
            g_source_itemIds_item = godot::String(source_itemIds_item.c_str());
            g_target_itemIds.push_back(g_source_itemIds_item);
        }
        target["itemIds"] = g_target_itemIds;
		G_BaseRequestData::ConvertToGodotModel(source, target);
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Creator::BuyCreatorItemsRequestData& target) {
        godot::Array g_target_itemIds = source["itemIds"];
        for (int i = 0; i < g_target_itemIds.size(); ++i) {
            godot::String g_target_itemIds_item = g_target_itemIds[i];
            string cpp_source_itemIds_item;
            godot::String g_g_target_itemIds_item = g_target_itemIds_item;
            cpp_source_itemIds_item = std::string(g_g_target_itemIds_item.utf8().get_data());
            target.itemIds.push_back(cpp_source_itemIds_item);
        }
		G_BaseRequestData::ConvertToCoreModel(source, target);
	}
};
