#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/UserProfile/UserCustomClaims.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <string>
#include <vector>
#include <unordered_map>

struct G_UserCustomClaims {
	static void ConvertToGodotModel(const RGN::Modules::UserProfile::UserCustomClaims& source, godot::Dictionary& target) {
        godot::Dictionary g_target_claims;
        for (const auto& [source_claims_key, source_claims_value] : source.claims) {
            godot::String g_source_claims_key;
            g_source_claims_key = godot::String(source_claims_key.c_str());
            godot::String g_source_claims_value;
            g_source_claims_value = godot::String(source_claims_value.c_str());
            g_target_claims[g_source_claims_key] = g_source_claims_value;
        }
        target["claims"] = g_target_claims;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::UserProfile::UserCustomClaims& target) {
        godot::Dictionary g_source_claims = source["claims"];
        godot::Array g_source_claims_keys = g_source_claims.keys();
        for (int i = 0; i < g_source_claims_keys.size(); ++i) {
            godot::String g_source_claims_key = g_source_claims_keys[i];
            godot::String g_source_claims_value = g_source_claims[g_source_claims_key];
            string cpp_source_claims_key;
            godot::String g_g_source_claims_key = g_source_claims_key;
            cpp_source_claims_key = std::string(g_g_source_claims_key.utf8().get_data());
            string cpp_source_claims_value;
            godot::String g_g_source_claims_value = g_source_claims_value;
            cpp_source_claims_value = std::string(g_g_source_claims_value.utf8().get_data());
            target.claims.insert({cpp_source_claims_key, cpp_source_claims_value});
        }
	}
};
