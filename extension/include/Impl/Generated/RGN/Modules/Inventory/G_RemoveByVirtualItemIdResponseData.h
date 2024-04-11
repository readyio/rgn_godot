#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Inventory/RemoveByVirtualItemIdResponseData.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <string>
#include <vector>
#include <unordered_map>

struct G_RemoveByVirtualItemIdResponseData {
	static void ConvertToGodotModel(const RGN::Modules::Inventory::RemoveByVirtualItemIdResponseData& source, godot::Dictionary& target) {
        target["virtualItemId"] = godot::String(source.virtualItemId.c_str());
        target["newQuantity"] = source.newQuantity;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Inventory::RemoveByVirtualItemIdResponseData& target) {
        godot::String g_source_virtualItemId = source["virtualItemId"];
        target.virtualItemId = std::string(g_source_virtualItemId.utf8().get_data());
        int32_t g_source_newQuantity = source["newQuantity"];
        target.newQuantity = g_source_newQuantity;
	}
};
