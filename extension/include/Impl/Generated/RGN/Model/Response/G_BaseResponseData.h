#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Model/Response/BaseResponseData.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <string>
#include <vector>
#include <unordered_map>

/**
 * Represents the base class for response data received from a server.
 * It contains common properties that are expected in all responses.
 */
struct G_BaseResponseData {
	static void ConvertToGodotModel(const RGN::Model::Response::BaseResponseData& source, godot::Dictionary& target) {
        target["status"] = source.status;
        target["message"] = godot::String(source.message.c_str());
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Model::Response::BaseResponseData& target) {
        int32_t g_source_status = source["status"];
        target.status = g_source_status;
        godot::String g_source_message = source["message"];
        target.message = std::string(g_source_message.utf8().get_data());
	}
};
