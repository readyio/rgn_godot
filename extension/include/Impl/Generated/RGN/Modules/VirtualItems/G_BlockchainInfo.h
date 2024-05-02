#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/VirtualItems/BlockchainInfo.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

/**
 * Blockchain Information for minted Virtual Items
 */
struct G_BlockchainInfo {
	static void ConvertToGodotModel(const RGN::Modules::VirtualItems::BlockchainInfo& source, godot::Dictionary& target) {
        target["purchasedQuantity"] = source.purchasedQuantity;
        target["totalQuantity"] = source.totalQuantity;
        target["walletAddress"] = godot::String(source.walletAddress.c_str());
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::VirtualItems::BlockchainInfo& target) {
        int64_t g_source_purchasedQuantity = source["purchasedQuantity"];
        target.purchasedQuantity = g_source_purchasedQuantity;
        int64_t g_source_totalQuantity = source["totalQuantity"];
        target.totalQuantity = g_source_totalQuantity;
        godot::String g_source_walletAddress = source["walletAddress"];
        target.walletAddress = std::string(g_source_walletAddress.utf8().get_data());
	}
};
