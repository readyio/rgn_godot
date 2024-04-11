#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/UserProfile/SetInvisibleStatusRequestData.h"
#include "../../../../../Generated/RGN/Model/Request/BaseRequestData.h"
#include "../../Model/Request/G_BaseRequestData.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <string>
#include <vector>
#include <unordered_map>

struct G_SetInvisibleStatusRequestData {
	static void ConvertToGodotModel(const RGN::Modules::UserProfile::SetInvisibleStatusRequestData& source, godot::Dictionary& target) {
        target["invisibleStatus"] = source.invisibleStatus;
		G_BaseRequestData::ConvertToGodotModel(source, target);
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::UserProfile::SetInvisibleStatusRequestData& target) {
        bool g_source_invisibleStatus = source["invisibleStatus"];
        target.invisibleStatus = g_source_invisibleStatus;
		G_BaseRequestData::ConvertToCoreModel(source, target);
	}
};
