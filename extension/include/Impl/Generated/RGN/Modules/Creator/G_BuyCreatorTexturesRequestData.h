#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Creator/BuyCreatorTexturesRequestData.h"
#include "../../../../../Generated/RGN/Model/Request/BaseRequestData.h"
#include "../../Model/Request/G_BaseRequestData.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_BuyCreatorTexturesRequestData {
	static void ConvertToGodotModel(const RGN::Modules::Creator::BuyCreatorTexturesRequestData& source, godot::Dictionary& target) {
        godot::Array g_target_textureIds;
        for (const auto& source_textureIds_item : source.textureIds) {
            godot::String g_source_textureIds_item;
            g_source_textureIds_item = godot::String(source_textureIds_item.c_str());
            g_target_textureIds.push_back(g_source_textureIds_item);
        }
        target["textureIds"] = g_target_textureIds;
		G_BaseRequestData::ConvertToGodotModel(source, target);
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Creator::BuyCreatorTexturesRequestData& target) {
        godot::Array g_target_textureIds = source["textureIds"];
        for (int i = 0; i < g_target_textureIds.size(); ++i) {
            godot::String g_target_textureIds_item = g_target_textureIds[i];
            string cpp_source_textureIds_item;
            godot::String g_g_target_textureIds_item = g_target_textureIds_item;
            cpp_source_textureIds_item = std::string(g_g_target_textureIds_item.utf8().get_data());
            target.textureIds.push_back(cpp_source_textureIds_item);
        }
		G_BaseRequestData::ConvertToCoreModel(source, target);
	}
};
