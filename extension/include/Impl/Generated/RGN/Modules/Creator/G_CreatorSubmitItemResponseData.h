#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Creator/CreatorSubmitItemResponseData.h"
#include "../../../../../Generated/RGN/Modules/VirtualItems/VirtualItem.h"
#include "../VirtualItems/G_VirtualItem.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <string>
#include <vector>
#include <unordered_map>

struct G_CreatorSubmitItemResponseData {
	static void ConvertToGodotModel(const RGN::Modules::Creator::CreatorSubmitItemResponseData& source, godot::Dictionary& target) {
        godot::Dictionary g_target_addedItem = target["addedItem"];
        G_VirtualItem::ConvertToGodotModel(source.addedItem, g_target_addedItem);
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Creator::CreatorSubmitItemResponseData& target) {
        G_VirtualItem::ConvertToCoreModel(source["addedItem"], target.addedItem);
	}
};
