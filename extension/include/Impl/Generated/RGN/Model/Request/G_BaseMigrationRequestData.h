#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Model/Request/BaseMigrationRequestData.h"
#include "../../../../../Generated/RGN/Model/Request/BaseRequestData.h"
#include "G_BaseRequestData.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <string>
#include <vector>
#include <unordered_map>

/**
 * This class supports multiple versions of an API by appending a "version" parameter to the request data.
 */
struct G_BaseMigrationRequestData {
	static void ConvertToGodotModel(const RGN::Model::Request::BaseMigrationRequestData& source, godot::Dictionary& target) {
        target["version"] = source.version;
		G_BaseRequestData::ConvertToGodotModel(source, target);
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Model::Request::BaseMigrationRequestData& target) {
        int32_t g_source_version = source["version"];
        target.version = g_source_version;
		G_BaseRequestData::ConvertToCoreModel(source, target);
	}
};
