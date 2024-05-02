#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Store/LootBox.h"
#include "../../../../../Generated/RGN/Modules/VirtualItems/PriceInfo.h"
#include "../VirtualItems/G_PriceInfo.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_LootBox {
	static void ConvertToGodotModel(const RGN::Modules::Store::LootBox& source, godot::Dictionary& target) {
        target["id"] = godot::String(source.id.c_str());
        target["name"] = godot::String(source.name.c_str());
        target["appId"] = godot::String(source.appId.c_str());
        target["totalQuantity"] = source.totalQuantity;
        target["purchasedQuantity"] = source.purchasedQuantity;
        target["availableQuantity"] = source.availableQuantity;
        target["createdAt"] = source.createdAt;
        target["updatedAt"] = source.updatedAt;
        target["createdBy"] = godot::String(source.createdBy.c_str());
        target["updatedBy"] = godot::String(source.updatedBy.c_str());
        godot::Array g_target_prices;
        for (const auto& source_prices_item : source.prices) {
            godot::Dictionary g_source_prices_item;
            godot::Dictionary g_g_source_prices_item = g_source_prices_item;
            G_PriceInfo::ConvertToGodotModel(source_prices_item, g_g_source_prices_item);
            g_target_prices.push_back(g_source_prices_item);
        }
        target["prices"] = g_target_prices;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Store::LootBox& target) {
        godot::String g_source_id = source["id"];
        target.id = std::string(g_source_id.utf8().get_data());
        godot::String g_source_name = source["name"];
        target.name = std::string(g_source_name.utf8().get_data());
        godot::String g_source_appId = source["appId"];
        target.appId = std::string(g_source_appId.utf8().get_data());
        int64_t g_source_totalQuantity = source["totalQuantity"];
        target.totalQuantity = g_source_totalQuantity;
        int64_t g_source_purchasedQuantity = source["purchasedQuantity"];
        target.purchasedQuantity = g_source_purchasedQuantity;
        int64_t g_source_availableQuantity = source["availableQuantity"];
        target.availableQuantity = g_source_availableQuantity;
        int64_t g_source_createdAt = source["createdAt"];
        target.createdAt = g_source_createdAt;
        int64_t g_source_updatedAt = source["updatedAt"];
        target.updatedAt = g_source_updatedAt;
        godot::String g_source_createdBy = source["createdBy"];
        target.createdBy = std::string(g_source_createdBy.utf8().get_data());
        godot::String g_source_updatedBy = source["updatedBy"];
        target.updatedBy = std::string(g_source_updatedBy.utf8().get_data());
        godot::Array g_target_prices = source["prices"];
        for (int i = 0; i < g_target_prices.size(); ++i) {
            godot::Dictionary g_target_prices_item = g_target_prices[i];
            RGN::Modules::VirtualItems::PriceInfo cpp_source_prices_item;
            G_PriceInfo::ConvertToCoreModel(g_target_prices_item, cpp_source_prices_item);
            target.prices.push_back(cpp_source_prices_item);
        }
	}
};
