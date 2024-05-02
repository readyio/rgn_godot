#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Achievement/TriggerByIdRequestData.h"
#include "../../../../../Generated/RGN/Model/Request/BaseMigrationRequestData.h"
#include "../../Model/Request/G_BaseMigrationRequestData.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_TriggerByIdRequestData {
	static void ConvertToGodotModel(const RGN::Modules::Achievement::TriggerByIdRequestData& source, godot::Dictionary& target) {
        target["id"] = godot::String(source.id.c_str());
        target["progress"] = source.progress;
		G_BaseMigrationRequestData::ConvertToGodotModel(source, target);
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Achievement::TriggerByIdRequestData& target) {
        godot::String g_source_id = source["id"];
        target.id = std::string(g_source_id.utf8().get_data());
        int32_t g_source_progress = source["progress"];
        target.progress = g_source_progress;
		G_BaseMigrationRequestData::ConvertToCoreModel(source, target);
	}
};
