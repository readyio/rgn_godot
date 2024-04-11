#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Leaderboard/GetLeaderboardIdsResponseData.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <string>
#include <vector>
#include <unordered_map>

struct G_GetLeaderboardIdsResponseData {
	static void ConvertToGodotModel(const RGN::Modules::Leaderboard::GetLeaderboardIdsResponseData& source, godot::Dictionary& target) {
        godot::Array g_target_ids;
        for (const auto& source_ids_item : source.ids) {
            godot::String g_source_ids_item;
            g_source_ids_item = godot::String(source_ids_item.c_str());
            g_target_ids.push_back(g_source_ids_item);
        }
        target["ids"] = g_target_ids;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Leaderboard::GetLeaderboardIdsResponseData& target) {
        godot::Array g_target_ids = source["ids"];
        for (int i = 0; i < g_target_ids.size(); ++i) {
            godot::String g_target_ids_item = g_target_ids[i];
            string cpp_source_ids_item;
            godot::String g_g_target_ids_item = g_target_ids_item;
            cpp_source_ids_item = std::string(g_g_target_ids_item.utf8().get_data());
            target.ids.push_back(cpp_source_ids_item);
        }
	}
};
