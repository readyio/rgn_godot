#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/VirtualItems/VirtualItem.h"
#include "../../../../../Generated/RGN/Modules/VirtualItems/VirtualItemImage.h"
#include "G_VirtualItemImage.h"
#include "../../../../../Generated/RGN/Modules/VirtualItems/Properties.h"
#include "G_Properties.h"
#include "../../../../../Generated/RGN/Modules/VirtualItems/PriceInfo.h"
#include "G_PriceInfo.h"
#include "../../../../../Generated/RGN/Modules/VirtualItems/BlockchainInfo.h"
#include "G_BlockchainInfo.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_VirtualItem {
	static void ConvertToGodotModel(const RGN::Modules::VirtualItems::VirtualItem& source, godot::Dictionary& target) {
        target["id"] = godot::String(source.id.c_str());
        target["name"] = godot::String(source.name.c_str());
        target["description"] = godot::String(source.description.c_str());
        godot::Dictionary g_target_image = target["image"];
        G_VirtualItemImage::ConvertToGodotModel(source.image, g_target_image);
        target["createdAt"] = source.createdAt;
        target["updatedAt"] = source.updatedAt;
        target["createdBy"] = godot::String(source.createdBy.c_str());
        target["updatedBy"] = godot::String(source.updatedBy.c_str());
        target["isStackable"] = source.isStackable;
        godot::Array g_target_appIds;
        for (const auto& source_appIds_item : source.appIds) {
            godot::String g_source_appIds_item;
            g_source_appIds_item = godot::String(source_appIds_item.c_str());
            g_target_appIds.push_back(g_source_appIds_item);
        }
        target["appIds"] = g_target_appIds;
        godot::Array g_target_tags;
        for (const auto& source_tags_item : source.tags) {
            godot::String g_source_tags_item;
            g_source_tags_item = godot::String(source_tags_item.c_str());
            g_target_tags.push_back(g_source_tags_item);
        }
        target["tags"] = g_target_tags;
        godot::Array g_target_properties;
        for (const auto& source_properties_item : source.properties) {
            godot::Dictionary g_source_properties_item;
            godot::Dictionary g_g_source_properties_item = g_source_properties_item;
            G_Properties::ConvertToGodotModel(source_properties_item, g_g_source_properties_item);
            g_target_properties.push_back(g_source_properties_item);
        }
        target["properties"] = g_target_properties;
        godot::Array g_target_prices;
        for (const auto& source_prices_item : source.prices) {
            godot::Dictionary g_source_prices_item;
            godot::Dictionary g_g_source_prices_item = g_source_prices_item;
            G_PriceInfo::ConvertToGodotModel(source_prices_item, g_g_source_prices_item);
            g_target_prices.push_back(g_source_prices_item);
        }
        target["prices"] = g_target_prices;
        target["totalQuantity"] = source.totalQuantity;
        godot::Dictionary g_target_blockchain = target["blockchain"];
        G_BlockchainInfo::ConvertToGodotModel(source.blockchain, g_target_blockchain);
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::VirtualItems::VirtualItem& target) {
        godot::String g_source_id = source["id"];
        target.id = std::string(g_source_id.utf8().get_data());
        godot::String g_source_name = source["name"];
        target.name = std::string(g_source_name.utf8().get_data());
        godot::String g_source_description = source["description"];
        target.description = std::string(g_source_description.utf8().get_data());
        G_VirtualItemImage::ConvertToCoreModel(source["image"], target.image);
        int64_t g_source_createdAt = source["createdAt"];
        target.createdAt = g_source_createdAt;
        int64_t g_source_updatedAt = source["updatedAt"];
        target.updatedAt = g_source_updatedAt;
        godot::String g_source_createdBy = source["createdBy"];
        target.createdBy = std::string(g_source_createdBy.utf8().get_data());
        godot::String g_source_updatedBy = source["updatedBy"];
        target.updatedBy = std::string(g_source_updatedBy.utf8().get_data());
        bool g_source_isStackable = source["isStackable"];
        target.isStackable = g_source_isStackable;
        godot::Array g_target_appIds = source["appIds"];
        for (int i = 0; i < g_target_appIds.size(); ++i) {
            godot::String g_target_appIds_item = g_target_appIds[i];
            string cpp_source_appIds_item;
            godot::String g_g_target_appIds_item = g_target_appIds_item;
            cpp_source_appIds_item = std::string(g_g_target_appIds_item.utf8().get_data());
            target.appIds.push_back(cpp_source_appIds_item);
        }
        godot::Array g_target_tags = source["tags"];
        for (int i = 0; i < g_target_tags.size(); ++i) {
            godot::String g_target_tags_item = g_target_tags[i];
            string cpp_source_tags_item;
            godot::String g_g_target_tags_item = g_target_tags_item;
            cpp_source_tags_item = std::string(g_g_target_tags_item.utf8().get_data());
            target.tags.push_back(cpp_source_tags_item);
        }
        godot::Array g_target_properties = source["properties"];
        for (int i = 0; i < g_target_properties.size(); ++i) {
            godot::Dictionary g_target_properties_item = g_target_properties[i];
            RGN::Modules::VirtualItems::Properties cpp_source_properties_item;
            G_Properties::ConvertToCoreModel(g_target_properties_item, cpp_source_properties_item);
            target.properties.push_back(cpp_source_properties_item);
        }
        godot::Array g_target_prices = source["prices"];
        for (int i = 0; i < g_target_prices.size(); ++i) {
            godot::Dictionary g_target_prices_item = g_target_prices[i];
            RGN::Modules::VirtualItems::PriceInfo cpp_source_prices_item;
            G_PriceInfo::ConvertToCoreModel(g_target_prices_item, cpp_source_prices_item);
            target.prices.push_back(cpp_source_prices_item);
        }
        int64_t g_source_totalQuantity = source["totalQuantity"];
        target.totalQuantity = g_source_totalQuantity;
        G_BlockchainInfo::ConvertToCoreModel(source["blockchain"], target.blockchain);
	}
};
