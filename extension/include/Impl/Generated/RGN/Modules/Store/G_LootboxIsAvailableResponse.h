#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Store/LootboxIsAvailableResponse.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_LootboxIsAvailableResponse {
	static void ConvertToGodotModel(const RGN::Modules::Store::LootboxIsAvailableResponse& source, godot::Dictionary& target) {
        target["isAvailable"] = source.isAvailable;
        target["count"] = source.count;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Store::LootboxIsAvailableResponse& target) {
        bool g_source_isAvailable = source["isAvailable"];
        target.isAvailable = g_source_isAvailable;
        int64_t g_source_count = source["count"];
        target.count = g_source_count;
	}
};
