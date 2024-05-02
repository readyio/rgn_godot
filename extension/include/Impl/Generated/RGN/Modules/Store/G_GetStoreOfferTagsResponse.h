#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Store/GetStoreOfferTagsResponse.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_GetStoreOfferTagsResponse {
	static void ConvertToGodotModel(const RGN::Modules::Store::GetStoreOfferTagsResponse& source, godot::Dictionary& target) {
        godot::Array g_target_tags;
        for (const auto& source_tags_item : source.tags) {
            godot::String g_source_tags_item;
            g_source_tags_item = godot::String(source_tags_item.c_str());
            g_target_tags.push_back(g_source_tags_item);
        }
        target["tags"] = g_target_tags;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Store::GetStoreOfferTagsResponse& target) {
        godot::Array g_target_tags = source["tags"];
        for (int i = 0; i < g_target_tags.size(); ++i) {
            godot::String g_target_tags_item = g_target_tags[i];
            string cpp_source_tags_item;
            godot::String g_g_target_tags_item = g_target_tags_item;
            cpp_source_tags_item = std::string(g_g_target_tags_item.utf8().get_data());
            target.tags.push_back(cpp_source_tags_item);
        }
	}
};
