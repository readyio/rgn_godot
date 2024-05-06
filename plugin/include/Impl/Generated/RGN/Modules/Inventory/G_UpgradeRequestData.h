#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Inventory/UpgradeRequestData.h"
#include "../../../../../Generated/RGN/Model/Request/BaseRequestData.h"
#include "../../Model/Request/G_BaseRequestData.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_UpgradeRequestData {
	static void ConvertToGodotModel(const RGN::Modules::Inventory::UpgradeRequestData& source, godot::Dictionary& target) {
        target["ownedItemId"] = godot::String(source.ownedItemId.c_str());
        target["upgradeId"] = godot::String(source.upgradeId.c_str());
        target["newUpgradeLevel"] = source.newUpgradeLevel;
		G_BaseRequestData::ConvertToGodotModel(source, target);
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Inventory::UpgradeRequestData& target) {
        godot::String g_source_ownedItemId = source["ownedItemId"];
        target.ownedItemId = std::string(g_source_ownedItemId.utf8().get_data());
        godot::String g_source_upgradeId = source["upgradeId"];
        target.upgradeId = std::string(g_source_upgradeId.utf8().get_data());
        int32_t g_source_newUpgradeLevel = source["newUpgradeLevel"];
        target.newUpgradeLevel = g_source_newUpgradeLevel;
		G_BaseRequestData::ConvertToCoreModel(source, target);
	}
};
