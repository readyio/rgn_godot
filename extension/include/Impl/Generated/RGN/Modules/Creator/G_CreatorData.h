#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Creator/CreatorData.h"
#include "../../../../../Generated/RGN/Modules/Currency/Currency.h"
#include "../Currency/G_Currency.h"
#include "../../../../../Generated/RGN/Modules/Creator/CreatorSaleItem.h"
#include "G_CreatorSaleItem.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <string>
#include <vector>
#include <unordered_map>

struct G_CreatorData {
	static void ConvertToGodotModel(const RGN::Modules::Creator::CreatorData& source, godot::Dictionary& target) {
        godot::Array g_target_unclaimedCurrencies;
        for (const auto& source_unclaimedCurrencies_item : source.unclaimedCurrencies) {
            godot::Dictionary g_source_unclaimedCurrencies_item;
            godot::Dictionary g_g_source_unclaimedCurrencies_item = g_source_unclaimedCurrencies_item;
            G_Currency::ConvertToGodotModel(source_unclaimedCurrencies_item, g_g_source_unclaimedCurrencies_item);
            g_target_unclaimedCurrencies.push_back(g_source_unclaimedCurrencies_item);
        }
        target["unclaimedCurrencies"] = g_target_unclaimedCurrencies;
        godot::Array g_target_creatorSaleItems;
        for (const auto& source_creatorSaleItems_item : source.creatorSaleItems) {
            godot::Dictionary g_source_creatorSaleItems_item;
            godot::Dictionary g_g_source_creatorSaleItems_item = g_source_creatorSaleItems_item;
            G_CreatorSaleItem::ConvertToGodotModel(source_creatorSaleItems_item, g_g_source_creatorSaleItems_item);
            g_target_creatorSaleItems.push_back(g_source_creatorSaleItems_item);
        }
        target["creatorSaleItems"] = g_target_creatorSaleItems;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Creator::CreatorData& target) {
        godot::Array g_target_unclaimedCurrencies = source["unclaimedCurrencies"];
        for (int i = 0; i < g_target_unclaimedCurrencies.size(); ++i) {
            godot::Dictionary g_target_unclaimedCurrencies_item = g_target_unclaimedCurrencies[i];
            RGN::Modules::Currency::Currency cpp_source_unclaimedCurrencies_item;
            G_Currency::ConvertToCoreModel(g_target_unclaimedCurrencies_item, cpp_source_unclaimedCurrencies_item);
            target.unclaimedCurrencies.push_back(cpp_source_unclaimedCurrencies_item);
        }
        godot::Array g_target_creatorSaleItems = source["creatorSaleItems"];
        for (int i = 0; i < g_target_creatorSaleItems.size(); ++i) {
            godot::Dictionary g_target_creatorSaleItems_item = g_target_creatorSaleItems[i];
            RGN::Modules::Creator::CreatorSaleItem cpp_source_creatorSaleItems_item;
            G_CreatorSaleItem::ConvertToCoreModel(g_target_creatorSaleItems_item, cpp_source_creatorSaleItems_item);
            target.creatorSaleItems.push_back(cpp_source_creatorSaleItems_item);
        }
	}
};
