#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../Generated/RGN/Model/ImageUrl.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

/**
 * Represents a mapping of image URLs to their respective size identifiers.
 * Inherits from a dictionary with string keys and string values.
 */
struct G_ImageUrl {
	static void ConvertToGodotModel(const RGN::Model::ImageUrl& source, godot::Dictionary& target) {
        target["source"] = godot::String(source.source.c_str());
        target["large"] = godot::String(source.large.c_str());
        target["medium"] = godot::String(source.medium.c_str());
        target["small"] = godot::String(source.small.c_str());
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Model::ImageUrl& target) {
        godot::String g_source_source = source["source"];
        target.source = std::string(g_source_source.utf8().get_data());
        godot::String g_source_large = source["large"];
        target.large = std::string(g_source_large.utf8().get_data());
        godot::String g_source_medium = source["medium"];
        target.medium = std::string(g_source_medium.utf8().get_data());
        godot::String g_source_small = source["small"];
        target.small = std::string(g_source_small.utf8().get_data());
	}
};
