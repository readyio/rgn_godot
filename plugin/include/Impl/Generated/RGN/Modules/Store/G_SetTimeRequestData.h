#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Store/SetTimeRequestData.h"
#include "../../../../../Generated/RGN/Model/TimeInfo.h"
#include "../../Model/G_TimeInfo.h"
#include "../../../../../Generated/RGN/Model/Request/BaseRequestData.h"
#include "../../Model/Request/G_BaseRequestData.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_SetTimeRequestData {
	static void ConvertToGodotModel(const RGN::Modules::Store::SetTimeRequestData& source, godot::Dictionary& target) {
        target["offerId"] = godot::String(source.offerId.c_str());
        godot::Dictionary g_target_time;
        G_TimeInfo::ConvertToGodotModel(source.time, g_target_time);
        target["time"] = g_target_time;
		G_BaseRequestData::ConvertToGodotModel(source, target);
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Store::SetTimeRequestData& target) {
        godot::String g_source_offerId = source["offerId"];
        target.offerId = std::string(g_source_offerId.utf8().get_data());
        G_TimeInfo::ConvertToCoreModel(source["time"], target.time);
		G_BaseRequestData::ConvertToCoreModel(source, target);
	}
};
