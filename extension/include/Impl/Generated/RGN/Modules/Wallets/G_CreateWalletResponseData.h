#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Wallets/CreateWalletResponseData.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <string>
#include <vector>
#include <unordered_map>

struct G_CreateWalletResponseData {
	static void ConvertToGodotModel(const RGN::Modules::Wallets::CreateWalletResponseData& source, godot::Dictionary& target) {
        target["address"] = godot::String(source.address.c_str());
        target["wallet_created"] = source.wallet_created;
        target["success"] = source.success;
        target["error"] = godot::String(source.error.c_str());
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Wallets::CreateWalletResponseData& target) {
        godot::String g_source_address = source["address"];
        target.address = std::string(g_source_address.utf8().get_data());
        bool g_source_wallet_created = source["wallet_created"];
        target.wallet_created = g_source_wallet_created;
        bool g_source_success = source["success"];
        target.success = g_source_success;
        godot::String g_source_error = source["error"];
        target.error = std::string(g_source_error.utf8().get_data());
	}
};
