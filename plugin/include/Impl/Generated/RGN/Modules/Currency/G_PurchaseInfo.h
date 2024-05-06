#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Currency/PurchaseInfo.h"
#include "../../../../../Generated/RGN/Modules/Currency/Currency.h"
#include "G_Currency.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_PurchaseInfo {
	static void ConvertToGodotModel(const RGN::Modules::Currency::PurchaseInfo& source, godot::Dictionary& target) {
        godot::Array g_target_cost;
        for (const auto& source_cost_item : source.cost) {
            godot::Dictionary g_source_cost_item;
            godot::Dictionary g_g_source_cost_item;
            G_Currency::ConvertToGodotModel(source_cost_item, g_g_source_cost_item);
            g_source_cost_item = g_g_source_cost_item;
            g_target_cost.push_back(g_source_cost_item);
        }
        target["cost"] = g_target_cost;
        target["quantity"] = source.quantity;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Currency::PurchaseInfo& target) {
        godot::Array g_target_cost = source["cost"];
        for (int i = 0; i < g_target_cost.size(); ++i) {
            godot::Dictionary g_target_cost_item = g_target_cost[i];
            RGN::Modules::Currency::Currency cpp_source_cost_item;
            G_Currency::ConvertToCoreModel(g_target_cost_item, cpp_source_cost_item);
            target.cost.push_back(cpp_source_cost_item);
        }
        int32_t g_source_quantity = source["quantity"];
        target.quantity = g_source_quantity;
	}
};
