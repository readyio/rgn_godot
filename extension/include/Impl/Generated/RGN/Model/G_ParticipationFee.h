#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../Generated/RGN/Model/ParticipationFee.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <string>
#include <vector>
#include <unordered_map>

/**
 * A class that represents a participation fee on Ready Games Network.
 */
struct G_ParticipationFee {
	static void ConvertToGodotModel(const RGN::Model::ParticipationFee& source, godot::Dictionary& target) {
        target["type"] = godot::String(source.type.c_str());
        target["id"] = godot::String(source.id.c_str());
        target["quantity"] = source.quantity;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Model::ParticipationFee& target) {
        godot::String g_source_type = source["type"];
        target.type = std::string(g_source_type.utf8().get_data());
        godot::String g_source_id = source["id"];
        target.id = std::string(g_source_id.utf8().get_data());
        int32_t g_source_quantity = source["quantity"];
        target.quantity = g_source_quantity;
	}
};
