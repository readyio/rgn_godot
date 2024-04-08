#pragma once

#include "Generated/RGN/Modules/Currency/Currency.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <string>

struct G_Currency {
    static void ConvertToGodotModel(const RGN::Modules::Currency::Currency& source, godot::Dictionary& target) {
        godot::Array g_appIds = godot::Array();
        for (const auto& appId : source.appIds) {
            g_appIds.push_back(godot::String(appId.c_str()));
        }
        godot::String g_name = godot::String(source.name.c_str());
        int g_quantity = source.quantity;
        target["name"] = g_name;
        target["quantity"] = g_quantity;
    }

    static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::Currency::Currency& target) {
        godot::Array g_appIds = source["appIds"];
        godot::String g_name = source["name"];
        int g_quantity = source["quantity"];
        for (int i = 0; i < g_appIds.size(); ++i) {
            godot::String g_appId = g_appIds[i];
            target.appIds.push_back(std::string(g_appId.utf8().get_data()));
        }
        target.name = std::string(g_name.utf8().get_data());;
        target.quantity = g_quantity;
    }
};