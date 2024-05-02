#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/GameProgress/UpdateUserLevelResponseData.h"
#include "../../../../../Generated/RGN/Model/Response/BaseResponseData.h"
#include "../../Model/Response/G_BaseResponseData.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_UpdateUserLevelResponseData {
	static void ConvertToGodotModel(const RGN::Modules::GameProgress::UpdateUserLevelResponseData& source, godot::Dictionary& target) {
        target["playerProgress"] = godot::String(source.playerProgress.c_str());
		G_BaseResponseData::ConvertToGodotModel(source, target);
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::GameProgress::UpdateUserLevelResponseData& target) {
        godot::String g_source_playerProgress = source["playerProgress"];
        target.playerProgress = std::string(g_source_playerProgress.utf8().get_data());
		G_BaseResponseData::ConvertToCoreModel(source, target);
	}
};
