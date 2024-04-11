#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../Utility/G_CancellationToken.h"
#include "../../../../../Utility/CancellationToken.h"
#include "../../../../../Generated/RGN/Modules/VirtualItems/VirtualItemsModule_Admin.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>

using namespace std;

class G_VirtualItemsModule_Admin : public godot::Object {
    GDCLASS(G_VirtualItemsModule_Admin, godot::Object);
    static inline G_VirtualItemsModule_Admin* singleton = nullptr;
protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("deleteVirtualItemsByIdsAsync", "virtualItemIds", "onSuccess", "onFail"), &G_VirtualItemsModule_Admin::deleteVirtualItemsByIdsAsync, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("deleteVirtualItemsByNameAsync", "itemName", "onSuccess", "onFail"), &G_VirtualItemsModule_Admin::deleteVirtualItemsByNameAsync, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("deleteVirtualItemByAppIdAsync", "appId", "onSuccess", "onFail"), &G_VirtualItemsModule_Admin::deleteVirtualItemByAppIdAsync, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("addFromCSVWithBlockchainStubAsync", "virtualItemName", "csvContent", "csvDelimiter", "cancellationToken", "onSuccess", "onFail"), &G_VirtualItemsModule_Admin::addFromCSVWithBlockchainStubAsync, DEFVAL(","), DEFVAL(nullptr), godot::Callable(), godot::Callable());
    }
public:
    static G_VirtualItemsModule_Admin *get_singleton() {
        return singleton;
    }
    G_VirtualItemsModule_Admin() {
        ERR_FAIL_COND(singleton != nullptr);
        singleton = this;
    }
    ~G_VirtualItemsModule_Admin() {
        ERR_FAIL_COND(singleton != this);
        singleton = nullptr;
    }
    void deleteVirtualItemsByIdsAsync(
        godot::Array virtualItemIds,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            vector<string> cpp_virtualItemIds;
            godot::Array g_cpp_virtualItemIds = virtualItemIds;
            for (int i = 0; i < g_cpp_virtualItemIds.size(); ++i) {
                godot::String g_cpp_virtualItemIds_item = g_cpp_virtualItemIds[i];
                string cpp_virtualItemIds_item;
                godot::String g_g_cpp_virtualItemIds_item = g_cpp_virtualItemIds_item;
                cpp_virtualItemIds_item = std::string(g_g_cpp_virtualItemIds_item.utf8().get_data());
                cpp_virtualItemIds.push_back(cpp_virtualItemIds_item);
            }
            RGN::Modules::VirtualItems::VirtualItemsModule_Admin::DeleteVirtualItemsByIdsAsync(
                [onSuccess]() {
                    onSuccess.callv(godot::Array());
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                },
                cpp_virtualItemIds
            );
    }
    void deleteVirtualItemsByNameAsync(
        godot::String itemName,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            string cpp_itemName;
            godot::String g_itemName = itemName;
            cpp_itemName = std::string(g_itemName.utf8().get_data());
            RGN::Modules::VirtualItems::VirtualItemsModule_Admin::DeleteVirtualItemsByNameAsync(
                [onSuccess]() {
                    onSuccess.callv(godot::Array());
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                },
                cpp_itemName
            );
    }
    void deleteVirtualItemByAppIdAsync(
        godot::String appId,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            string cpp_appId;
            godot::String g_appId = appId;
            cpp_appId = std::string(g_appId.utf8().get_data());
            RGN::Modules::VirtualItems::VirtualItemsModule_Admin::DeleteVirtualItemByAppIdAsync(
                [onSuccess]() {
                    onSuccess.callv(godot::Array());
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                },
                cpp_appId
            );
    }
    void addFromCSVWithBlockchainStubAsync(
        godot::String virtualItemName,
        godot::String csvContent,
        godot::String csvDelimiter,
        godot::Object* cancellationToken,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            string cpp_virtualItemName;
            string cpp_csvContent;
            string cpp_csvDelimiter;
            RGN::CancellationToken cpp_cancellationToken;
            godot::String g_virtualItemName = virtualItemName;
            cpp_virtualItemName = std::string(g_virtualItemName.utf8().get_data());
            godot::String g_csvContent = csvContent;
            cpp_csvContent = std::string(g_csvContent.utf8().get_data());
            godot::String g_csvDelimiter = csvDelimiter;
            cpp_csvDelimiter = std::string(g_csvDelimiter.utf8().get_data());
            G_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::VirtualItems::VirtualItemsModule_Admin::AddFromCSVWithBlockchainStubAsync(
                [onSuccess](vector<string> response) {
                    godot::Array gArgs;
                    godot::Array gResponse;
                    godot::Array g_gResponse;
                    for (const auto& response_item : response) {
                        godot::String g_response_item;
                        g_response_item = godot::String(response_item.c_str());
                        g_gResponse.push_back(g_response_item);
                    }
                    gResponse = g_gResponse;
                    gArgs.push_back(gResponse);
                    onSuccess.callv(gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                },
                cpp_virtualItemName,
                cpp_csvContent,
                cpp_csvDelimiter,
                cpp_cancellationToken
            );
    }
};
