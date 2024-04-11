#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Currency/PurchaseRGNCoinRequestData.h"
#include "../../../../../Generated/RGN/Model/Request/BaseRequestData.h"
#include "../../Model/Request/G_BaseRequestData.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <string>
#include <vector>
#include <unordered_map>

struct G_PurchaseRGNCoinRequestData {
	static void ConvertToGodotModel(const RGN::Modules::Currency::PurchaseRGNCoinRequestData& source, godot::Dictionary& target) {
        target["iapUUID"] = godot::String(source.iapUUID.c_str());
        target["requestId"] = godot::String(source.requestId.c_str());
        target["iapTransactionId"] = godot::String(source.iapTransactionId.c_str());
        target["iapReceipt"] = godot::String(source.iapReceipt.c_str());
		G_BaseRequestData::ConvertToGodotModel(source, target);
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Currency::PurchaseRGNCoinRequestData& target) {
        godot::String g_source_iapUUID = source["iapUUID"];
        target.iapUUID = std::string(g_source_iapUUID.utf8().get_data());
        godot::String g_source_requestId = source["requestId"];
        target.requestId = std::string(g_source_requestId.utf8().get_data());
        godot::String g_source_iapTransactionId = source["iapTransactionId"];
        target.iapTransactionId = std::string(g_source_iapTransactionId.utf8().get_data());
        godot::String g_source_iapReceipt = source["iapReceipt"];
        target.iapReceipt = std::string(g_source_iapReceipt.utf8().get_data());
		G_BaseRequestData::ConvertToCoreModel(source, target);
	}
};
