#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Achievement/TriggerByRequestNameRequestData.h"
#include "../../../../../Generated/RGN/Model/Request/BaseMigrationRequestData.h"
#include "../../Model/Request/G_BaseMigrationRequestData.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <string>
#include <vector>
#include <unordered_map>

struct G_TriggerByRequestNameRequestData {
	static void ConvertToGodotModel(const RGN::Modules::Achievement::TriggerByRequestNameRequestData& source, godot::Dictionary& target) {
        target["requestName"] = godot::String(source.requestName.c_str());
        target["progress"] = source.progress;
		G_BaseMigrationRequestData::ConvertToGodotModel(source, target);
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Achievement::TriggerByRequestNameRequestData& target) {
        godot::String g_source_requestName = source["requestName"];
        target.requestName = std::string(g_source_requestName.utf8().get_data());
        int32_t g_source_progress = source["progress"];
        target.progress = g_source_progress;
		G_BaseMigrationRequestData::ConvertToCoreModel(source, target);
	}
};
