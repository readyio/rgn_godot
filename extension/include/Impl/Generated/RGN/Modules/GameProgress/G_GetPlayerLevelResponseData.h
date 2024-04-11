#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/GameProgress/GetPlayerLevelResponseData.h"
#include "../../../../../Generated/RGN/Model/Response/BaseResponseData.h"
#include "../../Model/Response/G_BaseResponseData.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <string>
#include <vector>
#include <unordered_map>

struct G_GetPlayerLevelResponseData {
	static void ConvertToGodotModel(const RGN::Modules::GameProgress::GetPlayerLevelResponseData& source, godot::Dictionary& target) {
        target["playerProgress"] = godot::String(source.playerProgress.c_str());
		G_BaseResponseData::ConvertToGodotModel(source, target);
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::GameProgress::GetPlayerLevelResponseData& target) {
        godot::String g_source_playerProgress = source["playerProgress"];
        target.playerProgress = std::string(g_source_playerProgress.utf8().get_data());
		G_BaseResponseData::ConvertToCoreModel(source, target);
	}
};
