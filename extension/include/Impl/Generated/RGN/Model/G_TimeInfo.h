#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../Generated/RGN/Model/TimeInfo.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

/**
 * Represents the time information.
 * This information can be used for time-limited entities.
 */
struct G_TimeInfo {
	static void ConvertToGodotModel(const RGN::Model::TimeInfo& source, godot::Dictionary& target) {
        target["hasStart"] = source.hasStart;
        target["start"] = source.start;
        target["hasEnd"] = source.hasEnd;
        target["end"] = source.end;
        target["hasInterval"] = source.hasInterval;
        target["intervalDuration"] = source.intervalDuration;
        target["intervalDelay"] = source.intervalDelay;
        target["hasPromo"] = source.hasPromo;
        target["promo"] = source.promo;
        target["hasGrace"] = source.hasGrace;
        target["grace"] = source.grace;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Model::TimeInfo& target) {
        bool g_source_hasStart = source["hasStart"];
        target.hasStart = g_source_hasStart;
        int64_t g_source_start = source["start"];
        target.start = g_source_start;
        bool g_source_hasEnd = source["hasEnd"];
        target.hasEnd = g_source_hasEnd;
        int64_t g_source_end = source["end"];
        target.end = g_source_end;
        bool g_source_hasInterval = source["hasInterval"];
        target.hasInterval = g_source_hasInterval;
        int64_t g_source_intervalDuration = source["intervalDuration"];
        target.intervalDuration = g_source_intervalDuration;
        int64_t g_source_intervalDelay = source["intervalDelay"];
        target.intervalDelay = g_source_intervalDelay;
        bool g_source_hasPromo = source["hasPromo"];
        target.hasPromo = g_source_hasPromo;
        int64_t g_source_promo = source["promo"];
        target.promo = g_source_promo;
        bool g_source_hasGrace = source["hasGrace"];
        target.hasGrace = g_source_hasGrace;
        int64_t g_source_grace = source["grace"];
        target.grace = g_source_grace;
	}
};
