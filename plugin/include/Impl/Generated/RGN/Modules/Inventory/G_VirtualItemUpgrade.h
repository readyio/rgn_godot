#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Inventory/VirtualItemUpgrade.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_VirtualItemUpgrade {
	static void ConvertToGodotModel(const RGN::Modules::Inventory::VirtualItemUpgrade& source, godot::Dictionary& target) {
        target["upgradeId"] = godot::String(source.upgradeId.c_str());
        target["upgradeLevel"] = source.upgradeLevel;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Inventory::VirtualItemUpgrade& target) {
        godot::String g_source_upgradeId = source["upgradeId"];
        target.upgradeId = std::string(g_source_upgradeId.utf8().get_data());
        int32_t g_source_upgradeLevel = source["upgradeLevel"];
        target.upgradeLevel = g_source_upgradeLevel;
	}
};
