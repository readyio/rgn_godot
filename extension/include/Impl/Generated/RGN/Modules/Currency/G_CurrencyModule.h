#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Currency/CurrencyModule.h"
#include "../../../../../Generated/RGN/Modules/Currency/RGNCoinEconomy.h"
#include "G_RGNCoinEconomy.h"
#include "../../../../../Generated/RGN/Model/Request/BaseRequestData.h"
#include "../../Model/Request/G_BaseRequestData.h"
#include "../../../../../Generated/RGN/Modules/Currency/Currency.h"
#include "G_Currency.h"
#include "../../../../../Generated/RGN/Modules/Currency/PurchaseRGNCoinRequestData.h"
#include "G_PurchaseRGNCoinRequestData.h"
#include "../../../../../Generated/RGN/Modules/Currency/CurrencyProductsData.h"
#include "G_CurrencyProductsData.h"
#include "../../../../../Generated/RGN/Model/Request/BaseMigrationRequestData.h"
#include "../../Model/Request/G_BaseMigrationRequestData.h"
#include "../../../../../Generated/RGN/Modules/Currency/PurchaseCurrencyProductRequestData.h"
#include "G_PurchaseCurrencyProductRequestData.h"
#include "../../../../../Generated/RGN/Modules/Currency/AddUserCurrenciesResponseData.h"
#include "G_AddUserCurrenciesResponseData.h"
#include "../../../../../Generated/RGN/Modules/Currency/GetUserCurrenciesResponseData.h"
#include "G_GetUserCurrenciesResponseData.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>

using namespace std;

class G_CurrencyModule : public godot::Object {
    GDCLASS(G_CurrencyModule, godot::Object);
    static inline G_CurrencyModule* singleton = nullptr;
protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("getRGNCoinEconomyAsync", "onSuccess", "onFail"), &G_CurrencyModule::getRGNCoinEconomyAsync, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("purchaseRGNCoinAsync", "iapUUID", "iapTransactionId", "iapReceipt", "onSuccess", "onFail"), &G_CurrencyModule::purchaseRGNCoinAsync, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("getInAppPurchaseCurrencyDataAsync", "onSuccess", "onFail"), &G_CurrencyModule::getInAppPurchaseCurrencyDataAsync, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("purchaseCurrencyProductAsync", "productId", "onSuccess", "onFail"), &G_CurrencyModule::purchaseCurrencyProductAsync, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("addUserCurrenciesAsync", "currencies", "onSuccess", "onFail"), &G_CurrencyModule::addUserCurrenciesAsync, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("getUserCurrenciesAsync", "onSuccess", "onFail"), &G_CurrencyModule::getUserCurrenciesAsync, godot::Callable(), godot::Callable());
    }
public:
    static G_CurrencyModule *get_singleton() {
        return singleton;
    }
    G_CurrencyModule() {
        ERR_FAIL_COND(singleton != nullptr);
        singleton = this;
    }
    ~G_CurrencyModule() {
        ERR_FAIL_COND(singleton != this);
        singleton = nullptr;
    }
    void getRGNCoinEconomyAsync(
        godot::Callable onSuccess,
        godot::Callable onFail) {
            RGN::Modules::Currency::CurrencyModule::GetRGNCoinEconomyAsync(
                [onSuccess](RGN::Modules::Currency::RGNCoinEconomy response) {
                    godot::Array gArgs;
                    godot::Dictionary gResponse;
                    godot::Dictionary g_gResponse = gResponse;
                    G_RGNCoinEconomy::ConvertToGodotModel(response, g_gResponse);
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
    void purchaseRGNCoinAsync(
        godot::String iapUUID,
        godot::String iapTransactionId,
        godot::String iapReceipt,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            string cpp_iapUUID;
            string cpp_iapTransactionId;
            string cpp_iapReceipt;
            godot::String g_iapUUID = iapUUID;
            cpp_iapUUID = std::string(g_iapUUID.utf8().get_data());
            godot::String g_iapTransactionId = iapTransactionId;
            cpp_iapTransactionId = std::string(g_iapTransactionId.utf8().get_data());
            godot::String g_iapReceipt = iapReceipt;
            cpp_iapReceipt = std::string(g_iapReceipt.utf8().get_data());
            RGN::Modules::Currency::CurrencyModule::PurchaseRGNCoinAsync(
                [onSuccess](vector<RGN::Modules::Currency::Currency> response) {
                    godot::Array gArgs;
                    godot::Array gResponse;
                    godot::Array g_gResponse;
                    for (const auto& response_item : response) {
                        godot::Dictionary g_response_item;
                        godot::Dictionary g_g_response_item = g_response_item;
                        G_Currency::ConvertToGodotModel(response_item, g_g_response_item);
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
                cpp_iapUUID,
                cpp_iapTransactionId,
                cpp_iapReceipt
            );
    }
    void getInAppPurchaseCurrencyDataAsync(
        godot::Callable onSuccess,
        godot::Callable onFail) {
            RGN::Modules::Currency::CurrencyModule::GetInAppPurchaseCurrencyDataAsync(
                [onSuccess](RGN::Modules::Currency::CurrencyProductsData response) {
                    godot::Array gArgs;
                    godot::Dictionary gResponse;
                    godot::Dictionary g_gResponse = gResponse;
                    G_CurrencyProductsData::ConvertToGodotModel(response, g_gResponse);
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
    void purchaseCurrencyProductAsync(
        godot::String productId,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            string cpp_productId;
            godot::String g_productId = productId;
            cpp_productId = std::string(g_productId.utf8().get_data());
            RGN::Modules::Currency::CurrencyModule::PurchaseCurrencyProductAsync(
                [onSuccess](vector<RGN::Modules::Currency::Currency> response) {
                    godot::Array gArgs;
                    godot::Array gResponse;
                    godot::Array g_gResponse;
                    for (const auto& response_item : response) {
                        godot::Dictionary g_response_item;
                        godot::Dictionary g_g_response_item = g_response_item;
                        G_Currency::ConvertToGodotModel(response_item, g_g_response_item);
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
                cpp_productId
            );
    }
    void addUserCurrenciesAsync(
        godot::Array currencies,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            vector<RGN::Modules::Currency::Currency> cpp_currencies;
            godot::Array g_cpp_currencies = currencies;
            for (int i = 0; i < g_cpp_currencies.size(); ++i) {
                godot::Dictionary g_cpp_currencies_item = g_cpp_currencies[i];
                RGN::Modules::Currency::Currency cpp_currencies_item;
                G_Currency::ConvertToCoreModel(g_cpp_currencies_item, cpp_currencies_item);
                cpp_currencies.push_back(cpp_currencies_item);
            }
            RGN::Modules::Currency::CurrencyModule::AddUserCurrenciesAsync(
                [onSuccess](vector<RGN::Modules::Currency::Currency> response) {
                    godot::Array gArgs;
                    godot::Array gResponse;
                    godot::Array g_gResponse;
                    for (const auto& response_item : response) {
                        godot::Dictionary g_response_item;
                        godot::Dictionary g_g_response_item = g_response_item;
                        G_Currency::ConvertToGodotModel(response_item, g_g_response_item);
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
                cpp_currencies
            );
    }
    void getUserCurrenciesAsync(
        godot::Callable onSuccess,
        godot::Callable onFail) {
            RGN::Modules::Currency::CurrencyModule::GetUserCurrenciesAsync(
                [onSuccess](vector<RGN::Modules::Currency::Currency> response) {
                    godot::Array gArgs;
                    godot::Array gResponse;
                    godot::Array g_gResponse;
                    for (const auto& response_item : response) {
                        godot::Dictionary g_response_item;
                        godot::Dictionary g_g_response_item = g_response_item;
                        G_Currency::ConvertToGodotModel(response_item, g_g_response_item);
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
                }            );
    }
};
