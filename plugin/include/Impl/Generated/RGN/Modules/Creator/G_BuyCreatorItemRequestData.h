#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Creator/BuyCreatorItemRequestData.h"
#include "../../../../../Generated/RGN/Model/Request/BaseRequestData.h"
#include "../../Model/Request/G_BaseRequestData.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_BuyCreatorItemRequestData {
	static void ConvertToGodotModel(const RGN::Modules::Creator::BuyCreatorItemRequestData& source, godot::Dictionary& target) {
        target["itemId"] = godot::String(source.itemId.c_str());
		G_BaseRequestData::ConvertToGodotModel(source, target);
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Creator::BuyCreatorItemRequestData& target) {
        godot::String g_source_itemId = source["itemId"];
        target.itemId = std::string(g_source_itemId.utf8().get_data());
		G_BaseRequestData::ConvertToCoreModel(source, target);
	}
};
