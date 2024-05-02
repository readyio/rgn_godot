#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/GamePass/GamePassUserData.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

/**
 * Represents a Game Pass in the Ready Games Network (RGN) with its associated properties.
 */
struct G_GamePassUserData {
	static void ConvertToGodotModel(const RGN::Modules::GamePass::GamePassUserData& source, godot::Dictionary& target) {
        target["id"] = godot::String(source.id.c_str());
        target["gamePassId"] = godot::String(source.gamePassId.c_str());
        target["quantity"] = source.quantity;
        target["createdAt"] = source.createdAt;
        target["updatedAt"] = source.updatedAt;
        target["createdBy"] = godot::String(source.createdBy.c_str());
        target["updatedBy"] = godot::String(source.updatedBy.c_str());
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::GamePass::GamePassUserData& target) {
        godot::String g_source_id = source["id"];
        target.id = std::string(g_source_id.utf8().get_data());
        godot::String g_source_gamePassId = source["gamePassId"];
        target.gamePassId = std::string(g_source_gamePassId.utf8().get_data());
        int32_t g_source_quantity = source["quantity"];
        target.quantity = g_source_quantity;
        int64_t g_source_createdAt = source["createdAt"];
        target.createdAt = g_source_createdAt;
        int64_t g_source_updatedAt = source["updatedAt"];
        target.updatedAt = g_source_updatedAt;
        godot::String g_source_createdBy = source["createdBy"];
        target.createdBy = std::string(g_source_createdBy.utf8().get_data());
        godot::String g_source_updatedBy = source["updatedBy"];
        target.updatedBy = std::string(g_source_updatedBy.utf8().get_data());
	}
};
