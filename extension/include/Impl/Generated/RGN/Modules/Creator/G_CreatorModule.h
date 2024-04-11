#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Creator/CreatorModule.h"
#include "../../../../../Generated/RGN/Modules/Creator/CreatorSignupResponseData.h"
#include "G_CreatorSignupResponseData.h"
#include "../../../../../Generated/RGN/Modules/Creator/CreatorSignupRequestData.h"
#include "G_CreatorSignupRequestData.h"
#include "../../../../../Generated/RGN/Modules/VirtualItems/VirtualItem.h"
#include "../VirtualItems/G_VirtualItem.h"
#include "../../../../../Generated/RGN/Modules/Creator/CreatorSubmitItemResponseData.h"
#include "G_CreatorSubmitItemResponseData.h"
#include "../../../../../Generated/RGN/Modules/Creator/CreatorSubmitItemRequestData.h"
#include "G_CreatorSubmitItemRequestData.h"
#include "../../../../../Generated/RGN/Modules/Creator/CreatorData.h"
#include "G_CreatorData.h"
#include "../../../../../Generated/RGN/Model/Request/BaseMigrationRequestData.h"
#include "../../Model/Request/G_BaseMigrationRequestData.h"
#include "../../../../../Generated/RGN/Modules/Currency/ClaimCurrencyResponseData.h"
#include "../Currency/G_ClaimCurrencyResponseData.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>

using namespace std;

class G_CreatorModule : public godot::Object {
    GDCLASS(G_CreatorModule, godot::Object);
    static inline G_CreatorModule* singleton = nullptr;
protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("becomeACreatorAsync", "brandName", "onSuccess", "onFail"), &G_CreatorModule::becomeACreatorAsync, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("submitItemAsync", "customizedItem", "onSuccess", "onFail"), &G_CreatorModule::submitItemAsync, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("getCreatorDataAsync", "onSuccess", "onFail"), &G_CreatorModule::getCreatorDataAsync, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("claimCurrenciesAsync", "onSuccess", "onFail"), &G_CreatorModule::claimCurrenciesAsync, godot::Callable(), godot::Callable());
    }
public:
    static G_CreatorModule *get_singleton() {
        return singleton;
    }
    G_CreatorModule() {
        ERR_FAIL_COND(singleton != nullptr);
        singleton = this;
    }
    ~G_CreatorModule() {
        ERR_FAIL_COND(singleton != this);
        singleton = nullptr;
    }
    void becomeACreatorAsync(
        godot::String brandName,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            string cpp_brandName;
            godot::String g_brandName = brandName;
            cpp_brandName = std::string(g_brandName.utf8().get_data());
            RGN::Modules::Creator::CreatorModule::BecomeACreatorAsync(
                [onSuccess](RGN::Modules::Creator::CreatorSignupResponseData response) {
                    godot::Array gArgs;
                    godot::Dictionary gResponse;
                    godot::Dictionary g_gResponse = gResponse;
                    G_CreatorSignupResponseData::ConvertToGodotModel(response, g_gResponse);
                    gArgs.push_back(gResponse);
                    onSuccess.callv(gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                },
                cpp_brandName
            );
    }
    void submitItemAsync(
        godot::Dictionary customizedItem,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            RGN::Modules::VirtualItems::VirtualItem cpp_customizedItem;
            G_VirtualItem::ConvertToCoreModel(customizedItem, cpp_customizedItem);
            RGN::Modules::Creator::CreatorModule::SubmitItemAsync(
                [onSuccess](RGN::Modules::Creator::CreatorSubmitItemResponseData response) {
                    godot::Array gArgs;
                    godot::Dictionary gResponse;
                    godot::Dictionary g_gResponse = gResponse;
                    G_CreatorSubmitItemResponseData::ConvertToGodotModel(response, g_gResponse);
                    gArgs.push_back(gResponse);
                    onSuccess.callv(gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                },
                cpp_customizedItem
            );
    }
    void getCreatorDataAsync(
        godot::Callable onSuccess,
        godot::Callable onFail) {
            RGN::Modules::Creator::CreatorModule::GetCreatorDataAsync(
                [onSuccess](RGN::Modules::Creator::CreatorData response) {
                    godot::Array gArgs;
                    godot::Dictionary gResponse;
                    godot::Dictionary g_gResponse = gResponse;
                    G_CreatorData::ConvertToGodotModel(response, g_gResponse);
                    gArgs.push_back(gResponse);
                    onSuccess.callv(gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                }            );
    }
    void claimCurrenciesAsync(
        godot::Callable onSuccess,
        godot::Callable onFail) {
            RGN::Modules::Creator::CreatorModule::ClaimCurrenciesAsync(
                [onSuccess](RGN::Modules::Currency::ClaimCurrencyResponseData response) {
                    godot::Array gArgs;
                    godot::Dictionary gResponse;
                    godot::Dictionary g_gResponse = gResponse;
                    G_ClaimCurrencyResponseData::ConvertToGodotModel(response, g_gResponse);
                    gArgs.push_back(gResponse);
                    onSuccess.callv(gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                }            );
    }
};
