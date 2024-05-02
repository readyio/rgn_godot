#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/GameProgress/AddUserLevelRequestData.h"
#include "../../../../../Generated/RGN/Model/Request/BaseMigrationRequestData.h"
#include "../../Model/Request/G_BaseMigrationRequestData.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_AddUserLevelRequestData {
	static void ConvertToGodotModel(const RGN::Modules::GameProgress::AddUserLevelRequestData& source, godot::Dictionary& target) {
        target["playerProgress"] = godot::String(source.playerProgress.c_str());
		G_BaseMigrationRequestData::ConvertToGodotModel(source, target);
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::GameProgress::AddUserLevelRequestData& target) {
        godot::String g_source_playerProgress = source["playerProgress"];
        target.playerProgress = std::string(g_source_playerProgress.utf8().get_data());
		G_BaseMigrationRequestData::ConvertToCoreModel(source, target);
	}
};
