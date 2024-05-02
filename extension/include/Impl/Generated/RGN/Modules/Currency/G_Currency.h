#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Currency/Currency.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_Currency {
	static void ConvertToGodotModel(const RGN::Modules::Currency::Currency& source, godot::Dictionary& target) {
        godot::Array g_target_appIds;
        for (const auto& source_appIds_item : source.appIds) {
            godot::String g_source_appIds_item;
            g_source_appIds_item = godot::String(source_appIds_item.c_str());
            g_target_appIds.push_back(g_source_appIds_item);
        }
        target["appIds"] = g_target_appIds;
        target["name"] = godot::String(source.name.c_str());
        target["quantity"] = source.quantity;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Currency::Currency& target) {
        godot::Array g_target_appIds = source["appIds"];
        for (int i = 0; i < g_target_appIds.size(); ++i) {
            godot::String g_target_appIds_item = g_target_appIds[i];
            string cpp_source_appIds_item;
            godot::String g_g_target_appIds_item = g_target_appIds_item;
            cpp_source_appIds_item = std::string(g_g_target_appIds_item.utf8().get_data());
            target.appIds.push_back(cpp_source_appIds_item);
        }
        godot::String g_source_name = source["name"];
        target.name = std::string(g_source_name.utf8().get_data());
        int32_t g_source_quantity = source["quantity"];
        target.quantity = g_source_quantity;
	}
};
