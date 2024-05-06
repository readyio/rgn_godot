#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/VirtualItems/GetVirtualItemsByIdsRequestData.h"
#include "../../../../../Generated/RGN/Model/Request/BaseRequestData.h"
#include "../../Model/Request/G_BaseRequestData.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_GetVirtualItemsByIdsRequestData {
	static void ConvertToGodotModel(const RGN::Modules::VirtualItems::GetVirtualItemsByIdsRequestData& source, godot::Dictionary& target) {
        godot::Array g_target_ids;
        for (const auto& source_ids_item : source.ids) {
            godot::String g_source_ids_item;
            g_source_ids_item = godot::String(source_ids_item.c_str());
            g_target_ids.push_back(g_source_ids_item);
        }
        target["ids"] = g_target_ids;
		G_BaseRequestData::ConvertToGodotModel(source, target);
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::VirtualItems::GetVirtualItemsByIdsRequestData& target) {
        godot::Array g_target_ids = source["ids"];
        for (int i = 0; i < g_target_ids.size(); ++i) {
            godot::String g_target_ids_item = g_target_ids[i];
            string cpp_source_ids_item;
            godot::String g_g_target_ids_item = g_target_ids_item;
            cpp_source_ids_item = std::string(g_g_target_ids_item.utf8().get_data());
            target.ids.push_back(cpp_source_ids_item);
        }
		G_BaseRequestData::ConvertToCoreModel(source, target);
	}
};
