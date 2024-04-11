#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/VirtualItems/AddVirtualItemResponseData.h"
#include "../../../../../Generated/RGN/Modules/VirtualItems/VirtualItem.h"
#include "G_VirtualItem.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <string>
#include <vector>
#include <unordered_map>

struct G_AddVirtualItemResponseData {
	static void ConvertToGodotModel(const RGN::Modules::VirtualItems::AddVirtualItemResponseData& source, godot::Dictionary& target) {
        godot::Dictionary g_target_virtualItem = target["virtualItem"];
        G_VirtualItem::ConvertToGodotModel(source.virtualItem, g_target_virtualItem);
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::VirtualItems::AddVirtualItemResponseData& target) {
        G_VirtualItem::ConvertToCoreModel(source["virtualItem"], target.virtualItem);
	}
};
