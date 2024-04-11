#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Wallets/RGNWallet.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <string>
#include <vector>
#include <unordered_map>

struct G_RGNWallet {
	static void ConvertToGodotModel(const RGN::Modules::Wallets::RGNWallet& source, godot::Dictionary& target) {
        target["address"] = godot::String(source.address.c_str());
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Wallets::RGNWallet& target) {
        godot::String g_source_address = source["address"];
        target.address = std::string(g_source_address.utf8().get_data());
	}
};
