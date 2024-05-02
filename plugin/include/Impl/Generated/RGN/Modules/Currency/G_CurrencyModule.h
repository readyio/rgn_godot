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
#include "Impl/G_Defs.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>

using namespace std;

class G_CurrencyModule : public godot::Object {
    REG_GCLASS(G_CurrencyModule, godot::Object);
#ifdef GODOT4
    static inline G_CurrencyModule* singleton = nullptr;
#endif
public:
#ifdef GODOT3
    void _init() {}
#else
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
#endif
    REG_GCLASS_METHODS_HEADER() {
        BIND_GCLASS_METHOD_DEFVAL(G_CurrencyModule::getRGNCoinEconomyAsync, GCLASS_METHOD_SIGNATURE("getRGNCoinEconomyAsync", "onSuccess", "onFail"), GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_CurrencyModule::purchaseRGNCoinAsync, GCLASS_METHOD_SIGNATURE("purchaseRGNCoinAsync", "iapUUID", "iapTransactionId", "iapReceipt", "onSuccess", "onFail"), GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_CurrencyModule::getInAppPurchaseCurrencyDataAsync, GCLASS_METHOD_SIGNATURE("getInAppPurchaseCurrencyDataAsync", "onSuccess", "onFail"), GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_CurrencyModule::purchaseCurrencyProductAsync, GCLASS_METHOD_SIGNATURE("purchaseCurrencyProductAsync", "productId", "onSuccess", "onFail"), GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_CurrencyModule::addUserCurrenciesAsync, GCLASS_METHOD_SIGNATURE("addUserCurrenciesAsync", "currencies", "onSuccess", "onFail"), GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_CurrencyModule::getUserCurrenciesAsync, GCLASS_METHOD_SIGNATURE("getUserCurrenciesAsync", "onSuccess", "onFail"), GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
    }
    void getRGNCoinEconomyAsync(
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            RGN::Modules::Currency::CurrencyModule::GetRGNCoinEconomyAsync(
                [onSuccess](RGN::Modules::Currency::RGNCoinEconomy response) {
                    godot::Array gArgs;
                    godot::Dictionary gResponse;
                    godot::Dictionary g_gResponse = gResponse;
                    G_RGNCoinEconomy::ConvertToGodotModel(response, g_gResponse);
                    gArgs.push_back(gResponse);
                    EXECUTE_GCALLBACK_DEFVAL(onSuccess, gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     EXECUTE_GCALLBACK_DEFVAL(onFail, gArgs);
                }            );
    }
    void purchaseRGNCoinAsync(
        godot::String iapUUID,
        godot::String iapTransactionId,
        godot::String iapReceipt,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
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
                    EXECUTE_GCALLBACK_DEFVAL(onSuccess, gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     EXECUTE_GCALLBACK_DEFVAL(onFail, gArgs);
                },
                cpp_iapUUID,
                cpp_iapTransactionId,
                cpp_iapReceipt
            );
    }
    void getInAppPurchaseCurrencyDataAsync(
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            RGN::Modules::Currency::CurrencyModule::GetInAppPurchaseCurrencyDataAsync(
                [onSuccess](RGN::Modules::Currency::CurrencyProductsData response) {
                    godot::Array gArgs;
                    godot::Dictionary gResponse;
                    godot::Dictionary g_gResponse = gResponse;
                    G_CurrencyProductsData::ConvertToGodotModel(response, g_gResponse);
                    gArgs.push_back(gResponse);
                    EXECUTE_GCALLBACK_DEFVAL(onSuccess, gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     EXECUTE_GCALLBACK_DEFVAL(onFail, gArgs);
                }            );
    }
    void purchaseCurrencyProductAsync(
        godot::String productId,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
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
                    EXECUTE_GCALLBACK_DEFVAL(onSuccess, gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     EXECUTE_GCALLBACK_DEFVAL(onFail, gArgs);
                },
                cpp_productId
            );
    }
    void addUserCurrenciesAsync(
        godot::Array currencies,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
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
                    EXECUTE_GCALLBACK_DEFVAL(onSuccess, gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     EXECUTE_GCALLBACK_DEFVAL(onFail, gArgs);
                },
                cpp_currencies
            );
    }
    void getUserCurrenciesAsync(
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
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
                    EXECUTE_GCALLBACK_DEFVAL(onSuccess, gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     EXECUTE_GCALLBACK_DEFVAL(onFail, gArgs);
                }            );
    }
};
