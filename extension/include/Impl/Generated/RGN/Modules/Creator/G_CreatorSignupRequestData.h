#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Creator/CreatorSignupRequestData.h"
#include "../../../../../Generated/RGN/Model/Request/BaseMigrationRequestData.h"
#include "../../Model/Request/G_BaseMigrationRequestData.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_CreatorSignupRequestData {
	static void ConvertToGodotModel(const RGN::Modules::Creator::CreatorSignupRequestData& source, godot::Dictionary& target) {
        target["brandName"] = godot::String(source.brandName.c_str());
		G_BaseMigrationRequestData::ConvertToGodotModel(source, target);
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Creator::CreatorSignupRequestData& target) {
        godot::String g_source_brandName = source["brandName"];
        target.brandName = std::string(g_source_brandName.utf8().get_data());
		G_BaseMigrationRequestData::ConvertToCoreModel(source, target);
	}
};
