#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/GameProgress/UpdateUserLevelRequestData.h"
#include "../../../../../Generated/RGN/Modules/Currency/Currency.h"
#include "../Currency/G_Currency.h"
#include "../../../../../Generated/RGN/Model/Request/BaseMigrationRequestData.h"
#include "../../Model/Request/G_BaseMigrationRequestData.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_UpdateUserLevelRequestData {
	static void ConvertToGodotModel(const RGN::Modules::GameProgress::UpdateUserLevelRequestData& source, godot::Dictionary& target) {
        target["playerProgress"] = godot::String(source.playerProgress.c_str());
        godot::Array g_target_reward;
        for (const auto& source_reward_item : source.reward) {
            godot::Dictionary g_source_reward_item;
            godot::Dictionary g_g_source_reward_item = g_source_reward_item;
            G_Currency::ConvertToGodotModel(source_reward_item, g_g_source_reward_item);
            g_target_reward.push_back(g_source_reward_item);
        }
        target["reward"] = g_target_reward;
		G_BaseMigrationRequestData::ConvertToGodotModel(source, target);
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::GameProgress::UpdateUserLevelRequestData& target) {
        godot::String g_source_playerProgress = source["playerProgress"];
        target.playerProgress = std::string(g_source_playerProgress.utf8().get_data());
        godot::Array g_target_reward = source["reward"];
        for (int i = 0; i < g_target_reward.size(); ++i) {
            godot::Dictionary g_target_reward_item = g_target_reward[i];
            RGN::Modules::Currency::Currency cpp_source_reward_item;
            G_Currency::ConvertToCoreModel(g_target_reward_item, cpp_source_reward_item);
            target.reward.push_back(cpp_source_reward_item);
        }
		G_BaseMigrationRequestData::ConvertToCoreModel(source, target);
	}
};
