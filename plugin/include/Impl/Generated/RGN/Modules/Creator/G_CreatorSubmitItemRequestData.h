#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Creator/CreatorSubmitItemRequestData.h"
#include "../../../../../Generated/RGN/Modules/VirtualItems/VirtualItem.h"
#include "../VirtualItems/G_VirtualItem.h"
#include "../../../../../Generated/RGN/Model/Request/BaseMigrationRequestData.h"
#include "../../Model/Request/G_BaseMigrationRequestData.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_CreatorSubmitItemRequestData {
	static void ConvertToGodotModel(const RGN::Modules::Creator::CreatorSubmitItemRequestData& source, godot::Dictionary& target) {
        godot::Dictionary g_target_customizedItem = target["customizedItem"];
        G_VirtualItem::ConvertToGodotModel(source.customizedItem, g_target_customizedItem);
		G_BaseMigrationRequestData::ConvertToGodotModel(source, target);
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Creator::CreatorSubmitItemRequestData& target) {
        G_VirtualItem::ConvertToCoreModel(source["customizedItem"], target.customizedItem);
		G_BaseMigrationRequestData::ConvertToCoreModel(source, target);
	}
};
