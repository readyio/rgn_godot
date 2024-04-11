#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/GameProgress/GameProgress.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <string>
#include <vector>
#include <unordered_map>

struct G_GameProgress {
	static void ConvertToGodotModel(const RGN::Modules::GameProgress::GameProgress& source, godot::Dictionary& target) {
        target["level"] = source.level;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::GameProgress::GameProgress& target) {
        int32_t g_source_level = source["level"];
        target.level = g_source_level;
	}
};
