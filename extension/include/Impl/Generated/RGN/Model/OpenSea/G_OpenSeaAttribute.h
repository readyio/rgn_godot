#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Model/OpenSea/OpenSeaAttribute.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <string>
#include <vector>
#include <unordered_map>

/**
 * Represents an attribute for an item on OpenSea, typically a trait associated with a collectible or NFT.
 */
struct G_OpenSeaAttribute {
	static void ConvertToGodotModel(const RGN::Model::OpenSea::OpenSeaAttribute& source, godot::Dictionary& target) {
        target["trait_type"] = godot::String(source.trait_type.c_str());
        target["value"] = godot::String(source.value.c_str());
        target["display_type"] = godot::String(source.display_type.c_str());
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Model::OpenSea::OpenSeaAttribute& target) {
        godot::String g_source_trait_type = source["trait_type"];
        target.trait_type = std::string(g_source_trait_type.utf8().get_data());
        godot::String g_source_value = source["value"];
        target.value = std::string(g_source_value.utf8().get_data());
        godot::String g_source_display_type = source["display_type"];
        target.display_type = std::string(g_source_display_type.utf8().get_data());
	}
};
