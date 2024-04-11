#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Messaging/Message.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <string>
#include <vector>
#include <unordered_map>

/**
 * This struct used to get messages from the backend
 */
struct G_Message {
	static void ConvertToGodotModel(const RGN::Modules::Messaging::Message& source, godot::Dictionary& target) {
        target["Id"] = godot::String(source.Id.c_str());
        target["Payload"] = godot::String(source.Payload.c_str());
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Messaging::Message& target) {
        godot::String g_source_Id = source["Id"];
        target.Id = std::string(g_source_Id.utf8().get_data());
        godot::String g_source_Payload = source["Payload"];
        target.Payload = std::string(g_source_Payload.utf8().get_data());
	}
};
