#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Wallets/IsUserHavePrimaryWalletResponseData.h"
#include "../../../../../Generated/RGN/Model/Response/BaseResponseData.h"
#include "../../Model/Response/G_BaseResponseData.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <string>
#include <vector>
#include <unordered_map>

struct G_IsUserHavePrimaryWalletResponseData {
	static void ConvertToGodotModel(const RGN::Modules::Wallets::IsUserHavePrimaryWalletResponseData& source, godot::Dictionary& target) {
        target["isUserHavePrimaryWallet"] = source.isUserHavePrimaryWallet;
        target["address"] = godot::String(source.address.c_str());
		G_BaseResponseData::ConvertToGodotModel(source, target);
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Wallets::IsUserHavePrimaryWalletResponseData& target) {
        bool g_source_isUserHavePrimaryWallet = source["isUserHavePrimaryWallet"];
        target.isUserHavePrimaryWallet = g_source_isUserHavePrimaryWallet;
        godot::String g_source_address = source["address"];
        target.address = std::string(g_source_address.utf8().get_data());
		G_BaseResponseData::ConvertToCoreModel(source, target);
	}
};
