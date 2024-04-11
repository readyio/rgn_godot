#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/GamePass/GamePassData.h"
#include "../../../../../Generated/RGN/Model/Request/BaseRequestData.h"
#include "../../Model/Request/G_BaseRequestData.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <string>
#include <vector>
#include <unordered_map>

/**
 * Represents a Game Pass in the Ready Games Network (RGN) with its associated properties.
 */
struct G_GamePassData {
	static void ConvertToGodotModel(const RGN::Modules::GamePass::GamePassData& source, godot::Dictionary& target) {
        target["id"] = godot::String(source.id.c_str());
        godot::Array g_target_appIds;
        for (const auto& source_appIds_item : source.appIds) {
            godot::String g_source_appIds_item;
            g_source_appIds_item = godot::String(source_appIds_item.c_str());
            g_target_appIds.push_back(g_source_appIds_item);
        }
        target["appIds"] = g_target_appIds;
        target["requestName"] = godot::String(source.requestName.c_str());
        target["name"] = godot::String(source.name.c_str());
        target["description"] = godot::String(source.description.c_str());
        target["setBy"] = godot::String(source.setBy.c_str());
        godot::Array g_target_linkedVirtualItems;
        for (const auto& source_linkedVirtualItems_item : source.linkedVirtualItems) {
            godot::String g_source_linkedVirtualItems_item;
            g_source_linkedVirtualItems_item = godot::String(source_linkedVirtualItems_item.c_str());
            g_target_linkedVirtualItems.push_back(g_source_linkedVirtualItems_item);
        }
        target["linkedVirtualItems"] = g_target_linkedVirtualItems;
        target["createdAt"] = source.createdAt;
        target["updatedAt"] = source.updatedAt;
        target["createdBy"] = godot::String(source.createdBy.c_str());
        target["updatedBy"] = godot::String(source.updatedBy.c_str());
		G_BaseRequestData::ConvertToGodotModel(source, target);
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::GamePass::GamePassData& target) {
        godot::String g_source_id = source["id"];
        target.id = std::string(g_source_id.utf8().get_data());
        godot::Array g_target_appIds = source["appIds"];
        for (int i = 0; i < g_target_appIds.size(); ++i) {
            godot::String g_target_appIds_item = g_target_appIds[i];
            string cpp_source_appIds_item;
            godot::String g_g_target_appIds_item = g_target_appIds_item;
            cpp_source_appIds_item = std::string(g_g_target_appIds_item.utf8().get_data());
            target.appIds.push_back(cpp_source_appIds_item);
        }
        godot::String g_source_requestName = source["requestName"];
        target.requestName = std::string(g_source_requestName.utf8().get_data());
        godot::String g_source_name = source["name"];
        target.name = std::string(g_source_name.utf8().get_data());
        godot::String g_source_description = source["description"];
        target.description = std::string(g_source_description.utf8().get_data());
        godot::String g_source_setBy = source["setBy"];
        target.setBy = std::string(g_source_setBy.utf8().get_data());
        godot::Array g_target_linkedVirtualItems = source["linkedVirtualItems"];
        for (int i = 0; i < g_target_linkedVirtualItems.size(); ++i) {
            godot::String g_target_linkedVirtualItems_item = g_target_linkedVirtualItems[i];
            string cpp_source_linkedVirtualItems_item;
            godot::String g_g_target_linkedVirtualItems_item = g_target_linkedVirtualItems_item;
            cpp_source_linkedVirtualItems_item = std::string(g_g_target_linkedVirtualItems_item.utf8().get_data());
            target.linkedVirtualItems.push_back(cpp_source_linkedVirtualItems_item);
        }
        int64_t g_source_createdAt = source["createdAt"];
        target.createdAt = g_source_createdAt;
        int64_t g_source_updatedAt = source["updatedAt"];
        target.updatedAt = g_source_updatedAt;
        godot::String g_source_createdBy = source["createdBy"];
        target.createdBy = std::string(g_source_createdBy.utf8().get_data());
        godot::String g_source_updatedBy = source["updatedBy"];
        target.updatedBy = std::string(g_source_updatedBy.utf8().get_data());
		G_BaseRequestData::ConvertToCoreModel(source, target);
	}
};
