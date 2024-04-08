#pragma once

#include "Generated/RGN/Modules/Currency/CurrencyModule.h"
#include "Impl/Generated/RGN/Modules/Currency/G_RGNCoinEconomy.h"
#include "Impl/Generated/RGN/Modules/Currency/G_Currency.h"
#include "Impl/Generated/RGN/Modules/Currency/G_CurrencyProductsData.h"
#include "Utility/Logger.h"
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/variant/callable.hpp>
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <string>
#include <vector>

class G_CurrencyModule : public godot::Object {
	GDCLASS(G_CurrencyModule, godot::Object);
	static inline G_CurrencyModule* singleton = nullptr;
protected:
	static void _bind_methods() {
		godot::ClassDB::bind_method(godot::D_METHOD("getRGNCoinEconomyAsync", "success", "fail"), &G_CurrencyModule::getRGNCoinEconomyAsync);
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

	void getRGNCoinEconomyAsync(godot::Callable onSuccess, godot::Callable onFail) {
		RGN::Modules::Currency::CurrencyModule::GetRGNCoinEconomyAsync(
			[onSuccess](RGN::Modules::Currency::RGNCoinEconomy result) {
				if (onSuccess.is_valid()) {
					godot::Array args;
					godot::Dictionary g_result;
					G_RGNCoinEconomy::ConvertToGodotModel(result, g_result);
					args.push_back(g_result);
					onSuccess.callv(args);
				}
			}, [onFail](int code, std::string message) {
				if (onFail.is_valid()) {
					godot::Array args;
					args.push_back(code);
					args.push_back(godot::String(message.c_str()));
					onFail.callv(args);
				}
			}
		);
	}

	void purchaseRGNCoinAsync(godot::String iapUUID, godot::String iapTransactionId, godot::String iapReceipt, godot::Callable onSuccess, godot::Callable onFail) {
		std::string cpp_iapUUID = std::string(iapUUID.utf8().get_data());
		std::string cpp_iapTransactionId = std::string(iapTransactionId.utf8().get_data());
		std::string cpp_iapReceipt = std::string(iapReceipt.utf8().get_data());
		RGN::Modules::Currency::CurrencyModule::PurchaseRGNCoinAsync(
			[onSuccess](std::vector<RGN::Modules::Currency::Currency> result) {
				if (onSuccess.is_valid()) {
					godot::Array args;
					godot::Array g_result;
					for (const auto currency : result) {
						godot::Dictionary g_currency;
						G_Currency::ConvertToGodotModel(currency, g_currency);
						g_result.push_back(g_currency);
					}
					args.push_back(g_result);
					onSuccess.callv(args);
				}
			}, [onFail](int code, std::string message) {
				if (onFail.is_valid()) {
					godot::Array args;
					args.push_back(code);
					args.push_back(godot::String(message.c_str()));
					onFail.callv(args);
				}
			},
			cpp_iapUUID,
			cpp_iapTransactionId,
			cpp_iapReceipt
		);
	}

	void getInAppPurchaseCurrencyDataAsync(godot::Callable onSuccess, godot::Callable onFail) {
		RGN::Modules::Currency::CurrencyModule::GetInAppPurchaseCurrencyDataAsync(
			[onSuccess](RGN::Modules::Currency::CurrencyProductsData response) {
				if (onSuccess.is_valid()) {
					godot::Array args;
					godot::Dictionary g_response;
					G_CurrencyProductsData::ConvertToGodotModel(response, g_response);
					args.push_back(g_response);
					onSuccess.callv(args);
				}
			},
			[onFail](int code, std::string message) {
				if (onFail.is_valid()) {
					godot::Array args;
					args.push_back(code);
					args.push_back(godot::String(message.c_str()));
					onFail.callv(args);
				}
			}
		);
	}

	void purchaseCurrencyProductAsync(godot::String productId, godot::Callable onSuccess, godot::Callable onFail) {
		std::string cpp_productId = std::string(productId.utf8().get_data());
		RGN::Modules::Currency::CurrencyModule::PurchaseCurrencyProductAsync(
			[onSuccess](std::vector<RGN::Modules::Currency::Currency> response) {
				if (onSuccess.is_valid()) {
					godot::Array args;
					godot::Array g_response;
					for (const auto currency : response) {
						godot::Dictionary g_currency;
						G_Currency::ConvertToGodotModel(currency, g_currency);
						g_response.push_back(g_currency);
					}
					args.push_back(g_response);
					onSuccess.callv(args);
				}
			},
			[onFail](int code, std::string message) {
				if (onFail.is_valid()) {
					godot::Array args;
					args.push_back(code);
					args.push_back(godot::String(message.c_str()));
					onFail.callv(args);
				}
			},
			cpp_productId
		);
	}

	void addUserCurrenciesAsync(godot::Array currencies, godot::Callable onSuccess, godot::Callable onFail) {
		std::vector<RGN::Modules::Currency::Currency> cpp_currencies;
		for (int i = 0; i < currencies.size(); ++i) {
			godot::Dictionary g_currency = currencies[i];
            RGN::Modules::Currency::Currency currency;
            G_Currency::ConvertToCoreModel(g_currency, currency);
            cpp_currencies.push_back(currency);
		}
		RGN::Modules::Currency::CurrencyModule::AddUserCurrenciesAsync(
			[onSuccess](std::vector<RGN::Modules::Currency::Currency> response) {
				if (onSuccess.is_valid()) {
					godot::Array args;
					godot::Array g_response;
					for (const auto currency : response) {
						godot::Dictionary g_currency;
						G_Currency::ConvertToGodotModel(currency, g_currency);
						g_response.push_back(g_currency);
					}
					args.push_back(g_response);
					onSuccess.callv(args);
				}
			},
			[onFail](int code, std::string message) {
				if (onFail.is_valid()) {
					godot::Array args;
					args.push_back(code);
					args.push_back(godot::String(message.c_str()));
					onFail.callv(args);
				}
			},
			cpp_currencies
		);
	}

	void getUserCurrenciesAsync(godot::Callable onSuccess, godot::Callable onFail) {
		RGN::Modules::Currency::CurrencyModule::GetUserCurrenciesAsync(
			[onSuccess](vector<RGN::Modules::Currency::Currency> response) {
				if (onSuccess.is_valid()) {
					godot::Array args;
					godot::Array g_response;
					for (const auto currency : response) {
						godot::Dictionary g_currency;
						G_Currency::ConvertToGodotModel(currency, g_currency);
						g_response.push_back(g_currency);
					}
					args.push_back(g_response);
					onSuccess.callv(args);
				}
			},
			[onFail](int code, std::string message) {
				if (onFail.is_valid()) {
					godot::Array args;
					args.push_back(code);
					args.push_back(godot::String(message.c_str()));
					onFail.callv(args);
				}
			}
		);
	}
};