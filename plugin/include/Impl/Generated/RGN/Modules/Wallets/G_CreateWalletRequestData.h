#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Wallets/CreateWalletRequestData.h"
#include "../../../../../Generated/RGN/Model/Request/BaseMigrationRequestData.h"
#include "../../Model/Request/G_BaseMigrationRequestData.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_CreateWalletRequestData {
	static void ConvertToGodotModel(const RGN::Modules::Wallets::CreateWalletRequestData& source, godot::Dictionary& target) {
        target["token"] = godot::String(source.token.c_str());
        target["password"] = godot::String(source.password.c_str());
		G_BaseMigrationRequestData::ConvertToGodotModel(source, target);
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Wallets::CreateWalletRequestData& target) {
        godot::String g_source_token = source["token"];
        target.token = std::string(g_source_token.utf8().get_data());
        godot::String g_source_password = source["password"];
        target.password = std::string(g_source_password.utf8().get_data());
		G_BaseMigrationRequestData::ConvertToCoreModel(source, target);
	}
};
