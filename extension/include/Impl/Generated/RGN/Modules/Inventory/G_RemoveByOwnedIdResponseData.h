#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Inventory/RemoveByOwnedIdResponseData.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_RemoveByOwnedIdResponseData {
	static void ConvertToGodotModel(const RGN::Modules::Inventory::RemoveByOwnedIdResponseData& source, godot::Dictionary& target) {
        target["ownedItemId"] = godot::String(source.ownedItemId.c_str());
        target["newQuantity"] = source.newQuantity;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Inventory::RemoveByOwnedIdResponseData& target) {
        godot::String g_source_ownedItemId = source["ownedItemId"];
        target.ownedItemId = std::string(g_source_ownedItemId.utf8().get_data());
        int32_t g_source_newQuantity = source["newQuantity"];
        target.newQuantity = g_source_newQuantity;
	}
};
