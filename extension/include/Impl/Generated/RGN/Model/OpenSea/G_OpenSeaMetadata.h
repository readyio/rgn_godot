#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Model/OpenSea/OpenSeaMetadata.h"
#include "../../../../../Generated/RGN/Model/OpenSea/OpenSeaAttribute.h"
#include "G_OpenSeaAttribute.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <string>
#include <vector>
#include <unordered_map>

/**
 * Please review the official OpenSea documentation:
 * https://docs.opensea.io/docs/metadata-standards
 */
struct G_OpenSeaMetadata {
	static void ConvertToGodotModel(const RGN::Model::OpenSea::OpenSeaMetadata& source, godot::Dictionary& target) {
        target["name"] = godot::String(source.name.c_str());
        target["description"] = godot::String(source.description.c_str());
        target["external_url"] = godot::String(source.external_url.c_str());
        target["background_color"] = godot::String(source.background_color.c_str());
        target["animation_url"] = godot::String(source.animation_url.c_str());
        target["youtube_url"] = godot::String(source.youtube_url.c_str());
        target["image"] = godot::String(source.image.c_str());
        target["image_data"] = godot::String(source.image_data.c_str());
        godot::Array g_target_attributes;
        for (const auto& source_attributes_item : source.attributes) {
            godot::Dictionary g_source_attributes_item;
            godot::Dictionary g_g_source_attributes_item = g_source_attributes_item;
            G_OpenSeaAttribute::ConvertToGodotModel(source_attributes_item, g_g_source_attributes_item);
            g_target_attributes.push_back(g_source_attributes_item);
        }
        target["attributes"] = g_target_attributes;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Model::OpenSea::OpenSeaMetadata& target) {
        godot::String g_source_name = source["name"];
        target.name = std::string(g_source_name.utf8().get_data());
        godot::String g_source_description = source["description"];
        target.description = std::string(g_source_description.utf8().get_data());
        godot::String g_source_external_url = source["external_url"];
        target.external_url = std::string(g_source_external_url.utf8().get_data());
        godot::String g_source_background_color = source["background_color"];
        target.background_color = std::string(g_source_background_color.utf8().get_data());
        godot::String g_source_animation_url = source["animation_url"];
        target.animation_url = std::string(g_source_animation_url.utf8().get_data());
        godot::String g_source_youtube_url = source["youtube_url"];
        target.youtube_url = std::string(g_source_youtube_url.utf8().get_data());
        godot::String g_source_image = source["image"];
        target.image = std::string(g_source_image.utf8().get_data());
        godot::String g_source_image_data = source["image_data"];
        target.image_data = std::string(g_source_image_data.utf8().get_data());
        godot::Array g_target_attributes = source["attributes"];
        for (int i = 0; i < g_target_attributes.size(); ++i) {
            godot::Dictionary g_target_attributes_item = g_target_attributes[i];
            RGN::Model::OpenSea::OpenSeaAttribute cpp_source_attributes_item;
            G_OpenSeaAttribute::ConvertToCoreModel(g_target_attributes_item, cpp_source_attributes_item);
            target.attributes.push_back(cpp_source_attributes_item);
        }
	}
};
