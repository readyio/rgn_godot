#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Store/GetLootBoxesResponse.h"
#include "../../../../../Generated/RGN/Modules/Store/LootBox.h"
#include "G_LootBox.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_GetLootBoxesResponse {
	static void ConvertToGodotModel(const RGN::Modules::Store::GetLootBoxesResponse& source, godot::Dictionary& target) {
        godot::Array g_target_lootBoxes;
        for (const auto& source_lootBoxes_item : source.lootBoxes) {
            godot::Dictionary g_source_lootBoxes_item;
            godot::Dictionary g_g_source_lootBoxes_item = g_source_lootBoxes_item;
            G_LootBox::ConvertToGodotModel(source_lootBoxes_item, g_g_source_lootBoxes_item);
            g_target_lootBoxes.push_back(g_source_lootBoxes_item);
        }
        target["lootBoxes"] = g_target_lootBoxes;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Store::GetLootBoxesResponse& target) {
        godot::Array g_target_lootBoxes = source["lootBoxes"];
        for (int i = 0; i < g_target_lootBoxes.size(); ++i) {
            godot::Dictionary g_target_lootBoxes_item = g_target_lootBoxes[i];
            RGN::Modules::Store::LootBox cpp_source_lootBoxes_item;
            G_LootBox::ConvertToCoreModel(g_target_lootBoxes_item, cpp_source_lootBoxes_item);
            target.lootBoxes.push_back(cpp_source_lootBoxes_item);
        }
	}
};
