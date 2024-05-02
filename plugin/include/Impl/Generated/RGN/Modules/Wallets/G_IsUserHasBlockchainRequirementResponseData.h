#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Wallets/IsUserHasBlockchainRequirementResponseData.h"
#include "../../../../../Generated/RGN/Model/Response/BaseResponseData.h"
#include "../../Model/Response/G_BaseResponseData.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_IsUserHasBlockchainRequirementResponseData {
	static void ConvertToGodotModel(const RGN::Modules::Wallets::IsUserHasBlockchainRequirementResponseData& source, godot::Dictionary& target) {
        target["hasBlockchainRequirement"] = source.hasBlockchainRequirement;
		G_BaseResponseData::ConvertToGodotModel(source, target);
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Wallets::IsUserHasBlockchainRequirementResponseData& target) {
        bool g_source_hasBlockchainRequirement = source["hasBlockchainRequirement"];
        target.hasBlockchainRequirement = g_source_hasBlockchainRequirement;
		G_BaseResponseData::ConvertToCoreModel(source, target);
	}
};
