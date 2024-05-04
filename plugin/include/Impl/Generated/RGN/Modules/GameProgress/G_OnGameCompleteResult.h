#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/GameProgress/OnGameCompleteResult.h"
#include "../../../../../Generated/RGN/Modules/GameProgress/GameProgress.h"
#include "G_GameProgress.h"
#include "../../../../../Generated/RGN/Modules/Currency/UserCurrencyData.h"
#include "../Currency/G_UserCurrencyData.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_OnGameCompleteResult {
	static void ConvertToGodotModel(const RGN::Modules::GameProgress::OnGameCompleteResult& source, godot::Dictionary& target) {
        godot::Dictionary g_target_gameProgress;
        G_GameProgress::ConvertToGodotModel(source.gameProgress, g_target_gameProgress);
        target["gameProgress"] = g_target_gameProgress;
        godot::Dictionary g_target_userCurrencies;
        G_UserCurrencyData::ConvertToGodotModel(source.userCurrencies, g_target_userCurrencies);
        target["userCurrencies"] = g_target_userCurrencies;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::GameProgress::OnGameCompleteResult& target) {
        G_GameProgress::ConvertToCoreModel(source["gameProgress"], target.gameProgress);
        G_UserCurrencyData::ConvertToCoreModel(source["userCurrencies"], target.userCurrencies);
	}
};
