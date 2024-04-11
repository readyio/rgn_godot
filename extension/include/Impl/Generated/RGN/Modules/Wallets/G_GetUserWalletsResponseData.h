#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Wallets/GetUserWalletsResponseData.h"
#include "../../../../../Generated/RGN/Modules/Wallets/RGNWallet.h"
#include "G_RGNWallet.h"
#include "../../../../../Generated/RGN/Model/Response/BaseResponseData.h"
#include "../../Model/Response/G_BaseResponseData.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <string>
#include <vector>
#include <unordered_map>

struct G_GetUserWalletsResponseData {
	static void ConvertToGodotModel(const RGN::Modules::Wallets::GetUserWalletsResponseData& source, godot::Dictionary& target) {
        godot::Array g_target_wallets;
        for (const auto& source_wallets_item : source.wallets) {
            godot::Dictionary g_source_wallets_item;
            godot::Dictionary g_g_source_wallets_item = g_source_wallets_item;
            G_RGNWallet::ConvertToGodotModel(source_wallets_item, g_g_source_wallets_item);
            g_target_wallets.push_back(g_source_wallets_item);
        }
        target["wallets"] = g_target_wallets;
		G_BaseResponseData::ConvertToGodotModel(source, target);
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Wallets::GetUserWalletsResponseData& target) {
        godot::Array g_target_wallets = source["wallets"];
        for (int i = 0; i < g_target_wallets.size(); ++i) {
            godot::Dictionary g_target_wallets_item = g_target_wallets[i];
            RGN::Modules::Wallets::RGNWallet cpp_source_wallets_item;
            G_RGNWallet::ConvertToCoreModel(g_target_wallets_item, cpp_source_wallets_item);
            target.wallets.push_back(cpp_source_wallets_item);
        }
		G_BaseResponseData::ConvertToCoreModel(source, target);
	}
};
