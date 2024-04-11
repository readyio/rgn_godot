#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Leaderboard/SetScoreResponseData.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <string>
#include <vector>
#include <unordered_map>

struct G_SetScoreResponseData {
	static void ConvertToGodotModel(const RGN::Modules::Leaderboard::SetScoreResponseData& source, godot::Dictionary& target) {
        target["place"] = source.place;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Leaderboard::SetScoreResponseData& target) {
        int32_t g_source_place = source["place"];
        target.place = g_source_place;
	}
};
