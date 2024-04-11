#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Achievement/PurchaseAchievements.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <string>
#include <vector>
#include <unordered_map>

/**
 * Purchase achievements. Triggered when the user purchases a virtual item with the specified tag.
 * Is triggered when 'storeV2-buyStoreOffer' or 'storeV2-buyVirtualItems' is called.
 */
struct G_PurchaseAchievements {
	static void ConvertToGodotModel(const RGN::Modules::Achievement::PurchaseAchievements& source, godot::Dictionary& target) {
        target["virtualItemTag"] = godot::String(source.virtualItemTag.c_str());
        target["achievementId"] = godot::String(source.achievementId.c_str());
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Achievement::PurchaseAchievements& target) {
        godot::String g_source_virtualItemTag = source["virtualItemTag"];
        target.virtualItemTag = std::string(g_source_virtualItemTag.utf8().get_data());
        godot::String g_source_achievementId = source["achievementId"];
        target.achievementId = std::string(g_source_achievementId.utf8().get_data());
	}
};
