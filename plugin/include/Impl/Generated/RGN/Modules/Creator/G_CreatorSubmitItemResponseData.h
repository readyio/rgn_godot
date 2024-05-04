#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Creator/CreatorSubmitItemResponseData.h"
#include "../../../../../Generated/RGN/Modules/VirtualItems/VirtualItem.h"
#include "../VirtualItems/G_VirtualItem.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_CreatorSubmitItemResponseData {
	static void ConvertToGodotModel(const RGN::Modules::Creator::CreatorSubmitItemResponseData& source, godot::Dictionary& target) {
        godot::Dictionary g_target_addedItem;
        G_VirtualItem::ConvertToGodotModel(source.addedItem, g_target_addedItem);
        target["addedItem"] = g_target_addedItem;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Creator::CreatorSubmitItemResponseData& target) {
        G_VirtualItem::ConvertToCoreModel(source["addedItem"], target.addedItem);
	}
};
