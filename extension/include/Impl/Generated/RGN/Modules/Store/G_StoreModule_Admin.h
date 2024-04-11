#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Store/StoreModule_Admin.h"
#include "../../../../../Generated/RGN/Modules/VirtualItems/PriceInfo.h"
#include "../VirtualItems/G_PriceInfo.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>

using namespace std;

class G_StoreModule_Admin : public godot::Object {
    GDCLASS(G_StoreModule_Admin, godot::Object);
    static inline G_StoreModule_Admin* singleton = nullptr;
protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("createLootBoxAsync", "lootBoxName", "virtualItemTags", "prices", "onSuccess", "onFail"), &G_StoreModule_Admin::createLootBoxAsync, DEFVAL(godot::Array()), godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("deleteLootBoxAsync", "lootBoxId", "onSuccess", "onFail"), &G_StoreModule_Admin::deleteLootBoxAsync, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("deleteStoreOfferAsync", "offerId", "onSuccess", "onFail"), &G_StoreModule_Admin::deleteStoreOfferAsync, godot::Callable(), godot::Callable());
    }
public:
    static G_StoreModule_Admin *get_singleton() {
        return singleton;
    }
    G_StoreModule_Admin() {
        ERR_FAIL_COND(singleton != nullptr);
        singleton = this;
    }
    ~G_StoreModule_Admin() {
        ERR_FAIL_COND(singleton != this);
        singleton = nullptr;
    }
    void createLootBoxAsync(
        godot::String lootBoxName,
        godot::Array virtualItemTags,
        godot::Array prices,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            string cpp_lootBoxName;
            vector<string> cpp_virtualItemTags;
            vector<RGN::Modules::VirtualItems::PriceInfo> cpp_prices;
            godot::String g_lootBoxName = lootBoxName;
            cpp_lootBoxName = std::string(g_lootBoxName.utf8().get_data());
            godot::Array g_cpp_virtualItemTags = virtualItemTags;
            for (int i = 0; i < g_cpp_virtualItemTags.size(); ++i) {
                godot::String g_cpp_virtualItemTags_item = g_cpp_virtualItemTags[i];
                string cpp_virtualItemTags_item;
                godot::String g_g_cpp_virtualItemTags_item = g_cpp_virtualItemTags_item;
                cpp_virtualItemTags_item = std::string(g_g_cpp_virtualItemTags_item.utf8().get_data());
                cpp_virtualItemTags.push_back(cpp_virtualItemTags_item);
            }
            godot::Array g_cpp_prices = prices;
            for (int i = 0; i < g_cpp_prices.size(); ++i) {
                godot::Dictionary g_cpp_prices_item = g_cpp_prices[i];
                RGN::Modules::VirtualItems::PriceInfo cpp_prices_item;
                G_PriceInfo::ConvertToCoreModel(g_cpp_prices_item, cpp_prices_item);
                cpp_prices.push_back(cpp_prices_item);
            }
            RGN::Modules::Store::StoreModule_Admin::CreateLootBoxAsync(
                [onSuccess](string response) {
                    godot::Array gArgs;
                    godot::String gResponse;
                    gResponse = godot::String(response.c_str());
                    gArgs.push_back(gResponse);
                    onSuccess.callv(gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                },
                cpp_lootBoxName,
                cpp_virtualItemTags,
                cpp_prices
            );
    }
    void deleteLootBoxAsync(
        godot::String lootBoxId,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            string cpp_lootBoxId;
            godot::String g_lootBoxId = lootBoxId;
            cpp_lootBoxId = std::string(g_lootBoxId.utf8().get_data());
            RGN::Modules::Store::StoreModule_Admin::DeleteLootBoxAsync(
                [onSuccess](string response) {
                    godot::Array gArgs;
                    godot::String gResponse;
                    gResponse = godot::String(response.c_str());
                    gArgs.push_back(gResponse);
                    onSuccess.callv(gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                },
                cpp_lootBoxId
            );
    }
    void deleteStoreOfferAsync(
        godot::String offerId,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            string cpp_offerId;
            godot::String g_offerId = offerId;
            cpp_offerId = std::string(g_offerId.utf8().get_data());
            RGN::Modules::Store::StoreModule_Admin::DeleteStoreOfferAsync(
                [onSuccess]() {
                    onSuccess.callv(godot::Array());
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                },
                cpp_offerId
            );
    }
};
