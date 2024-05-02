#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/GamePass/GetForCurrentAppResponseData.h"
#include "../../../../../Generated/RGN/Modules/GamePass/GamePassData.h"
#include "G_GamePassData.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

/**
 * Represents the response data received when requesting Game Pass data for the current application.
 */
struct G_GetForCurrentAppResponseData {
	static void ConvertToGodotModel(const RGN::Modules::GamePass::GetForCurrentAppResponseData& source, godot::Dictionary& target) {
        godot::Array g_target_gamePasses;
        for (const auto& source_gamePasses_item : source.gamePasses) {
            godot::Dictionary g_source_gamePasses_item;
            godot::Dictionary g_g_source_gamePasses_item = g_source_gamePasses_item;
            G_GamePassData::ConvertToGodotModel(source_gamePasses_item, g_g_source_gamePasses_item);
            g_target_gamePasses.push_back(g_source_gamePasses_item);
        }
        target["gamePasses"] = g_target_gamePasses;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::GamePass::GetForCurrentAppResponseData& target) {
        godot::Array g_target_gamePasses = source["gamePasses"];
        for (int i = 0; i < g_target_gamePasses.size(); ++i) {
            godot::Dictionary g_target_gamePasses_item = g_target_gamePasses[i];
            RGN::Modules::GamePass::GamePassData cpp_source_gamePasses_item;
            G_GamePassData::ConvertToCoreModel(g_target_gamePasses_item, cpp_source_gamePasses_item);
            target.gamePasses.push_back(cpp_source_gamePasses_item);
        }
	}
};
