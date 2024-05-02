#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Inventory/InventoryModule.h"
#include "../../../../../Generated/RGN/Modules/VirtualItems/Properties.h"
#include "../VirtualItems/G_Properties.h"
#include "../../../../../Generated/RGN/Modules/Inventory/AddToInventoryResponseData.h"
#include "G_AddToInventoryResponseData.h"
#include "../../../../../Generated/RGN/Modules/Inventory/InventoryItemData.h"
#include "G_InventoryItemData.h"
#include "../../../../../Generated/RGN/Modules/Inventory/AddVirtualItemToUserInventoryRequestData.h"
#include "G_AddVirtualItemToUserInventoryRequestData.h"
#include "../../../../../Generated/RGN/Modules/Inventory/RemoveByVirtualItemIdResponseData.h"
#include "G_RemoveByVirtualItemIdResponseData.h"
#include "../../../../../Generated/RGN/Modules/Inventory/RemoveByOwnedIdResponseData.h"
#include "G_RemoveByOwnedIdResponseData.h"
#include "../../../../../Generated/RGN/Modules/Inventory/UpgradesResponseData.h"
#include "G_UpgradesResponseData.h"
#include "../../../../../Generated/RGN/Modules/Currency/Currency.h"
#include "../Currency/G_Currency.h"
#include "../../../../../Generated/RGN/Modules/Inventory/VirtualItemUpgrade.h"
#include "G_VirtualItemUpgrade.h"
#include "../../../../../Generated/RGN/Modules/Inventory/InventoryItemsWithVirtualItemsData.h"
#include "G_InventoryItemsWithVirtualItemsData.h"
#include "Impl/G_Defs.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>

using namespace std;

class G_InventoryModule : public godot::Object {
    REG_GCLASS(G_InventoryModule, godot::Object);
#ifdef GODOT4
    static G_InventoryModule* singleton;
#endif
public:
#ifdef GODOT3
    void _init() {}
#else
    static G_InventoryModule *get_singleton() {
        return singleton;
    }
    G_InventoryModule() {
        ERR_FAIL_COND(singleton != nullptr);
        singleton = this;
    }
    ~G_InventoryModule() {
        ERR_FAIL_COND(singleton != this);
        singleton = nullptr;
    }
#endif
    REG_GCLASS_METHODS_HEADER() {
        BIND_GCLASS_METHOD_DEFVAL(G_InventoryModule::addToInventoryAsync_VirtualItemId_Quantity_Properties, GCLASS_METHOD_SIGNATURE("addToInventoryAsync_VirtualItemId_Quantity_Properties", "virtualItemId", "quantity", "properties", "onSuccess", "onFail"), &G_InventoryModule::addToInventoryAsync_VirtualItemId_Quantity_Properties, DEFVAL(1), DEFVAL(godot::Dictionary()), GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_InventoryModule::addToInventoryAsync_UserId_VirtualItemId_Quantity_Properties, GCLASS_METHOD_SIGNATURE("addToInventoryAsync_UserId_VirtualItemId_Quantity_Properties", "userId", "virtualItemId", "quantity", "properties", "onSuccess", "onFail"), &G_InventoryModule::addToInventoryAsync_UserId_VirtualItemId_Quantity_Properties, DEFVAL(1), DEFVAL(godot::Dictionary()), GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_InventoryModule::addToInventoryAsync_UserId_InventoryData, GCLASS_METHOD_SIGNATURE("addToInventoryAsync_UserId_InventoryData", "userId", "inventoryData", "onSuccess", "onFail"), &G_InventoryModule::addToInventoryAsync_UserId_InventoryData, GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_InventoryModule::removeByVirtualItemIdAsync, GCLASS_METHOD_SIGNATURE("removeByVirtualItemIdAsync", "userId", "virtualItemId", "quantity", "onSuccess", "onFail"), &G_InventoryModule::removeByVirtualItemIdAsync, GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_InventoryModule::removeByInventoryItemIdAsync, GCLASS_METHOD_SIGNATURE("removeByInventoryItemIdAsync", "userId", "ownedItemId", "quantity", "onSuccess", "onFail"), &G_InventoryModule::removeByInventoryItemIdAsync, DEFVAL(1), GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_InventoryModule::getPropertiesAsync, GCLASS_METHOD_SIGNATURE("getPropertiesAsync", "ownedItemId", "onSuccess", "onFail"), &G_InventoryModule::getPropertiesAsync, GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_InventoryModule::setPropertiesAsync, GCLASS_METHOD_SIGNATURE("setPropertiesAsync", "ownedItemId", "json", "onSuccess", "onFail"), &G_InventoryModule::setPropertiesAsync, GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_InventoryModule::getUpgradesAsync, GCLASS_METHOD_SIGNATURE("getUpgradesAsync", "ownedItemId", "onSuccess", "onFail"), &G_InventoryModule::getUpgradesAsync, GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_InventoryModule::upgradeAsync, GCLASS_METHOD_SIGNATURE("upgradeAsync", "ownedItemId", "newUpgradeLevel", "upgradePrice", "upgradeId", "onSuccess", "onFail"), &G_InventoryModule::upgradeAsync, DEFVAL(godot::Array()), DEFVAL(""), GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_InventoryModule::getByIdAsync, GCLASS_METHOD_SIGNATURE("getByIdAsync", "ownedItemId", "onSuccess", "onFail"), &G_InventoryModule::getByIdAsync, GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_InventoryModule::getByIdsAsync, GCLASS_METHOD_SIGNATURE("getByIdsAsync", "ownedItemIds", "onSuccess", "onFail"), &G_InventoryModule::getByIdsAsync, GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_InventoryModule::getByVirtualItemIdsAsync, GCLASS_METHOD_SIGNATURE("getByVirtualItemIdsAsync", "virtualItemIds", "onSuccess", "onFail"), &G_InventoryModule::getByVirtualItemIdsAsync, GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_InventoryModule::getAllForCurrentAppAsync, GCLASS_METHOD_SIGNATURE("getAllForCurrentAppAsync", "onSuccess", "onFail"), &G_InventoryModule::getAllForCurrentAppAsync, GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_InventoryModule::getByAppIdsAsync, GCLASS_METHOD_SIGNATURE("getByAppIdsAsync", "appIds", "onSuccess", "onFail"), &G_InventoryModule::getByAppIdsAsync, GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_InventoryModule::getWithVirtualItemsDataForCurrentAppAsync, GCLASS_METHOD_SIGNATURE("getWithVirtualItemsDataForCurrentAppAsync", "startAfter", "limit", "onSuccess", "onFail"), &G_InventoryModule::getWithVirtualItemsDataForCurrentAppAsync, DEFVAL(""), DEFVAL(100), GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_InventoryModule::getWithVirtualItemsDataByAppIdsAsync, GCLASS_METHOD_SIGNATURE("getWithVirtualItemsDataByAppIdsAsync", "appIds", "startAfter", "limit", "onSuccess", "onFail"), &G_InventoryModule::getWithVirtualItemsDataByAppIdsAsync, DEFVAL(""), DEFVAL(100), GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_InventoryModule::parseInventoryItemData, GCLASS_METHOD_SIGNATURE("parseInventoryItemData", "json", "onSuccess", "onFail"), &G_InventoryModule::parseInventoryItemData, GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_InventoryModule::parseInventoryItemsData, GCLASS_METHOD_SIGNATURE("parseInventoryItemsData", "json", "onSuccess", "onFail"), &G_InventoryModule::parseInventoryItemsData, GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_InventoryModule::getByTagsAsync, GCLASS_METHOD_SIGNATURE("getByTagsAsync", "tags", "appId", "onSuccess", "onFail"), &G_InventoryModule::getByTagsAsync, DEFVAL(""), GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_InventoryModule::getTagsAsync, GCLASS_METHOD_SIGNATURE("getTagsAsync", "ownedItemId", "onSuccess", "onFail"), &G_InventoryModule::getTagsAsync, GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_InventoryModule::setTagsAsync, GCLASS_METHOD_SIGNATURE("setTagsAsync", "ownedItemId", "tags", "appId", "onSuccess", "onFail"), &G_InventoryModule::setTagsAsync, DEFVAL(""), GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
    }
    void addToInventoryAsync_VirtualItemId_Quantity_Properties(
        godot::String virtualItemId,
        int32_t quantity,
        godot::Dictionary properties,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            string cpp_virtualItemId;
            int32_t cpp_quantity;
            RGN::Modules::VirtualItems::Properties cpp_properties;
            godot::String g_virtualItemId = virtualItemId;
            cpp_virtualItemId = std::string(g_virtualItemId.utf8().get_data());
            int32_t g_quantity = quantity;
            cpp_quantity = g_quantity;
            G_Properties::ConvertToCoreModel(properties, cpp_properties);
            RGN::Modules::Inventory::InventoryModule::AddToInventoryAsync(
                [onSuccess](RGN::Modules::Inventory::AddToInventoryResponseData response) {
                    godot::Array gArgs;
                    godot::Dictionary gResponse;
                    godot::Dictionary g_gResponse = gResponse;
                    G_AddToInventoryResponseData::ConvertToGodotModel(response, g_gResponse);
                    gArgs.push_back(gResponse);
                    EXECUTE_GCALLBACK_DEFVAL(onSuccess, gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     EXECUTE_GCALLBACK_DEFVAL(onFail, gArgs);
                },
                cpp_virtualItemId,
                cpp_quantity,
                cpp_properties
            );
    }
    void addToInventoryAsync_UserId_VirtualItemId_Quantity_Properties(
        godot::String userId,
        godot::String virtualItemId,
        int32_t quantity,
        godot::Dictionary properties,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            string cpp_userId;
            string cpp_virtualItemId;
            int32_t cpp_quantity;
            RGN::Modules::VirtualItems::Properties cpp_properties;
            godot::String g_userId = userId;
            cpp_userId = std::string(g_userId.utf8().get_data());
            godot::String g_virtualItemId = virtualItemId;
            cpp_virtualItemId = std::string(g_virtualItemId.utf8().get_data());
            int32_t g_quantity = quantity;
            cpp_quantity = g_quantity;
            G_Properties::ConvertToCoreModel(properties, cpp_properties);
            RGN::Modules::Inventory::InventoryModule::AddToInventoryAsync(
                [onSuccess](RGN::Modules::Inventory::AddToInventoryResponseData response) {
                    godot::Array gArgs;
                    godot::Dictionary gResponse;
                    godot::Dictionary g_gResponse = gResponse;
                    G_AddToInventoryResponseData::ConvertToGodotModel(response, g_gResponse);
                    gArgs.push_back(gResponse);
                    EXECUTE_GCALLBACK_DEFVAL(onSuccess, gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     EXECUTE_GCALLBACK_DEFVAL(onFail, gArgs);
                },
                cpp_userId,
                cpp_virtualItemId,
                cpp_quantity,
                cpp_properties
            );
    }
    void addToInventoryAsync_UserId_InventoryData(
        godot::String userId,
        godot::Dictionary inventoryData,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            string cpp_userId;
            RGN::Modules::Inventory::InventoryItemData cpp_inventoryData;
            godot::String g_userId = userId;
            cpp_userId = std::string(g_userId.utf8().get_data());
            G_InventoryItemData::ConvertToCoreModel(inventoryData, cpp_inventoryData);
            RGN::Modules::Inventory::InventoryModule::AddToInventoryAsync(
                [onSuccess](RGN::Modules::Inventory::AddToInventoryResponseData response) {
                    godot::Array gArgs;
                    godot::Dictionary gResponse;
                    godot::Dictionary g_gResponse = gResponse;
                    G_AddToInventoryResponseData::ConvertToGodotModel(response, g_gResponse);
                    gArgs.push_back(gResponse);
                    EXECUTE_GCALLBACK_DEFVAL(onSuccess, gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     EXECUTE_GCALLBACK_DEFVAL(onFail, gArgs);
                },
                cpp_userId,
                cpp_inventoryData
            );
    }
    void removeByVirtualItemIdAsync(
        godot::String userId,
        godot::String virtualItemId,
        int32_t quantity,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            string cpp_userId;
            string cpp_virtualItemId;
            int32_t cpp_quantity;
            godot::String g_userId = userId;
            cpp_userId = std::string(g_userId.utf8().get_data());
            godot::String g_virtualItemId = virtualItemId;
            cpp_virtualItemId = std::string(g_virtualItemId.utf8().get_data());
            int32_t g_quantity = quantity;
            cpp_quantity = g_quantity;
            RGN::Modules::Inventory::InventoryModule::RemoveByVirtualItemIdAsync(
                [onSuccess](RGN::Modules::Inventory::RemoveByVirtualItemIdResponseData response) {
                    godot::Array gArgs;
                    godot::Dictionary gResponse;
                    godot::Dictionary g_gResponse = gResponse;
                    G_RemoveByVirtualItemIdResponseData::ConvertToGodotModel(response, g_gResponse);
                    gArgs.push_back(gResponse);
                    EXECUTE_GCALLBACK_DEFVAL(onSuccess, gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     EXECUTE_GCALLBACK_DEFVAL(onFail, gArgs);
                },
                cpp_userId,
                cpp_virtualItemId,
                cpp_quantity
            );
    }
    void removeByInventoryItemIdAsync(
        godot::String userId,
        godot::String ownedItemId,
        int32_t quantity,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            string cpp_userId;
            string cpp_ownedItemId;
            int32_t cpp_quantity;
            godot::String g_userId = userId;
            cpp_userId = std::string(g_userId.utf8().get_data());
            godot::String g_ownedItemId = ownedItemId;
            cpp_ownedItemId = std::string(g_ownedItemId.utf8().get_data());
            int32_t g_quantity = quantity;
            cpp_quantity = g_quantity;
            RGN::Modules::Inventory::InventoryModule::RemoveByInventoryItemIdAsync(
                [onSuccess](RGN::Modules::Inventory::RemoveByOwnedIdResponseData response) {
                    godot::Array gArgs;
                    godot::Dictionary gResponse;
                    godot::Dictionary g_gResponse = gResponse;
                    G_RemoveByOwnedIdResponseData::ConvertToGodotModel(response, g_gResponse);
                    gArgs.push_back(gResponse);
                    EXECUTE_GCALLBACK_DEFVAL(onSuccess, gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     EXECUTE_GCALLBACK_DEFVAL(onFail, gArgs);
                },
                cpp_userId,
                cpp_ownedItemId,
                cpp_quantity
            );
    }
    void getPropertiesAsync(
        godot::String ownedItemId,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            string cpp_ownedItemId;
            godot::String g_ownedItemId = ownedItemId;
            cpp_ownedItemId = std::string(g_ownedItemId.utf8().get_data());
            RGN::Modules::Inventory::InventoryModule::GetPropertiesAsync(
                [onSuccess](string response) {
                    godot::Array gArgs;
                    godot::String gResponse;
                    gResponse = godot::String(response.c_str());
                    gArgs.push_back(gResponse);
                    EXECUTE_GCALLBACK_DEFVAL(onSuccess, gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     EXECUTE_GCALLBACK_DEFVAL(onFail, gArgs);
                },
                cpp_ownedItemId
            );
    }
    void setPropertiesAsync(
        godot::String ownedItemId,
        godot::String json,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            string cpp_ownedItemId;
            string cpp_json;
            godot::String g_ownedItemId = ownedItemId;
            cpp_ownedItemId = std::string(g_ownedItemId.utf8().get_data());
            godot::String g_json = json;
            cpp_json = std::string(g_json.utf8().get_data());
            RGN::Modules::Inventory::InventoryModule::SetPropertiesAsync(
                [onSuccess](string response) {
                    godot::Array gArgs;
                    godot::String gResponse;
                    gResponse = godot::String(response.c_str());
                    gArgs.push_back(gResponse);
                    EXECUTE_GCALLBACK_DEFVAL(onSuccess, gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     EXECUTE_GCALLBACK_DEFVAL(onFail, gArgs);
                },
                cpp_ownedItemId,
                cpp_json
            );
    }
    void getUpgradesAsync(
        godot::String ownedItemId,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            string cpp_ownedItemId;
            godot::String g_ownedItemId = ownedItemId;
            cpp_ownedItemId = std::string(g_ownedItemId.utf8().get_data());
            RGN::Modules::Inventory::InventoryModule::GetUpgradesAsync(
                [onSuccess](vector<RGN::Modules::Inventory::UpgradesResponseData> response) {
                    godot::Array gArgs;
                    godot::Array gResponse;
                    godot::Array g_gResponse;
                    for (const auto& response_item : response) {
                        godot::Dictionary g_response_item;
                        godot::Dictionary g_g_response_item = g_response_item;
                        G_UpgradesResponseData::ConvertToGodotModel(response_item, g_g_response_item);
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
                cpp_ownedItemId
            );
    }
    void upgradeAsync(
        godot::String ownedItemId,
        int32_t newUpgradeLevel,
        godot::Array upgradePrice,
        godot::String upgradeId,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            string cpp_ownedItemId;
            int32_t cpp_newUpgradeLevel;
            vector<RGN::Modules::Currency::Currency> cpp_upgradePrice;
            string cpp_upgradeId;
            godot::String g_ownedItemId = ownedItemId;
            cpp_ownedItemId = std::string(g_ownedItemId.utf8().get_data());
            int32_t g_newUpgradeLevel = newUpgradeLevel;
            cpp_newUpgradeLevel = g_newUpgradeLevel;
            godot::Array g_cpp_upgradePrice = upgradePrice;
            for (int i = 0; i < g_cpp_upgradePrice.size(); ++i) {
                godot::Dictionary g_cpp_upgradePrice_item = g_cpp_upgradePrice[i];
                RGN::Modules::Currency::Currency cpp_upgradePrice_item;
                G_Currency::ConvertToCoreModel(g_cpp_upgradePrice_item, cpp_upgradePrice_item);
                cpp_upgradePrice.push_back(cpp_upgradePrice_item);
            }
            godot::String g_upgradeId = upgradeId;
            cpp_upgradeId = std::string(g_upgradeId.utf8().get_data());
            RGN::Modules::Inventory::InventoryModule::UpgradeAsync(
                [onSuccess](vector<RGN::Modules::Inventory::VirtualItemUpgrade> response) {
                    godot::Array gArgs;
                    godot::Array gResponse;
                    godot::Array g_gResponse;
                    for (const auto& response_item : response) {
                        godot::Dictionary g_response_item;
                        godot::Dictionary g_g_response_item = g_response_item;
                        G_VirtualItemUpgrade::ConvertToGodotModel(response_item, g_g_response_item);
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
                cpp_ownedItemId,
                cpp_newUpgradeLevel,
                cpp_upgradePrice,
                cpp_upgradeId
            );
    }
    void getByIdAsync(
        godot::String ownedItemId,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            string cpp_ownedItemId;
            godot::String g_ownedItemId = ownedItemId;
            cpp_ownedItemId = std::string(g_ownedItemId.utf8().get_data());
            RGN::Modules::Inventory::InventoryModule::GetByIdAsync(
                [onSuccess](RGN::Modules::Inventory::InventoryItemData response) {
                    godot::Array gArgs;
                    godot::Dictionary gResponse;
                    godot::Dictionary g_gResponse = gResponse;
                    G_InventoryItemData::ConvertToGodotModel(response, g_gResponse);
                    gArgs.push_back(gResponse);
                    EXECUTE_GCALLBACK_DEFVAL(onSuccess, gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     EXECUTE_GCALLBACK_DEFVAL(onFail, gArgs);
                },
                cpp_ownedItemId
            );
    }
    void getByIdsAsync(
        godot::Array ownedItemIds,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            vector<string> cpp_ownedItemIds;
            godot::Array g_cpp_ownedItemIds = ownedItemIds;
            for (int i = 0; i < g_cpp_ownedItemIds.size(); ++i) {
                godot::String g_cpp_ownedItemIds_item = g_cpp_ownedItemIds[i];
                string cpp_ownedItemIds_item;
                godot::String g_g_cpp_ownedItemIds_item = g_cpp_ownedItemIds_item;
                cpp_ownedItemIds_item = std::string(g_g_cpp_ownedItemIds_item.utf8().get_data());
                cpp_ownedItemIds.push_back(cpp_ownedItemIds_item);
            }
            RGN::Modules::Inventory::InventoryModule::GetByIdsAsync(
                [onSuccess](vector<RGN::Modules::Inventory::InventoryItemData> response) {
                    godot::Array gArgs;
                    godot::Array gResponse;
                    godot::Array g_gResponse;
                    for (const auto& response_item : response) {
                        godot::Dictionary g_response_item;
                        godot::Dictionary g_g_response_item = g_response_item;
                        G_InventoryItemData::ConvertToGodotModel(response_item, g_g_response_item);
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
                cpp_ownedItemIds
            );
    }
    void getByVirtualItemIdsAsync(
        godot::Array virtualItemIds,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            vector<string> cpp_virtualItemIds;
            godot::Array g_cpp_virtualItemIds = virtualItemIds;
            for (int i = 0; i < g_cpp_virtualItemIds.size(); ++i) {
                godot::String g_cpp_virtualItemIds_item = g_cpp_virtualItemIds[i];
                string cpp_virtualItemIds_item;
                godot::String g_g_cpp_virtualItemIds_item = g_cpp_virtualItemIds_item;
                cpp_virtualItemIds_item = std::string(g_g_cpp_virtualItemIds_item.utf8().get_data());
                cpp_virtualItemIds.push_back(cpp_virtualItemIds_item);
            }
            RGN::Modules::Inventory::InventoryModule::GetByVirtualItemIdsAsync(
                [onSuccess](vector<RGN::Modules::Inventory::InventoryItemData> response) {
                    godot::Array gArgs;
                    godot::Array gResponse;
                    godot::Array g_gResponse;
                    for (const auto& response_item : response) {
                        godot::Dictionary g_response_item;
                        godot::Dictionary g_g_response_item = g_response_item;
                        G_InventoryItemData::ConvertToGodotModel(response_item, g_g_response_item);
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
                cpp_virtualItemIds
            );
    }
    void getAllForCurrentAppAsync(
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            RGN::Modules::Inventory::InventoryModule::GetAllForCurrentAppAsync(
                [onSuccess](vector<RGN::Modules::Inventory::InventoryItemData> response) {
                    godot::Array gArgs;
                    godot::Array gResponse;
                    godot::Array g_gResponse;
                    for (const auto& response_item : response) {
                        godot::Dictionary g_response_item;
                        godot::Dictionary g_g_response_item = g_response_item;
                        G_InventoryItemData::ConvertToGodotModel(response_item, g_g_response_item);
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
    void getByAppIdsAsync(
        godot::Array appIds,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            vector<string> cpp_appIds;
            godot::Array g_cpp_appIds = appIds;
            for (int i = 0; i < g_cpp_appIds.size(); ++i) {
                godot::String g_cpp_appIds_item = g_cpp_appIds[i];
                string cpp_appIds_item;
                godot::String g_g_cpp_appIds_item = g_cpp_appIds_item;
                cpp_appIds_item = std::string(g_g_cpp_appIds_item.utf8().get_data());
                cpp_appIds.push_back(cpp_appIds_item);
            }
            RGN::Modules::Inventory::InventoryModule::GetByAppIdsAsync(
                [onSuccess](vector<RGN::Modules::Inventory::InventoryItemData> response) {
                    godot::Array gArgs;
                    godot::Array gResponse;
                    godot::Array g_gResponse;
                    for (const auto& response_item : response) {
                        godot::Dictionary g_response_item;
                        godot::Dictionary g_g_response_item = g_response_item;
                        G_InventoryItemData::ConvertToGodotModel(response_item, g_g_response_item);
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
                cpp_appIds
            );
    }
    void getWithVirtualItemsDataForCurrentAppAsync(
        godot::String startAfter,
        int32_t limit,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            string cpp_startAfter;
            int32_t cpp_limit;
            godot::String g_startAfter = startAfter;
            cpp_startAfter = std::string(g_startAfter.utf8().get_data());
            int32_t g_limit = limit;
            cpp_limit = g_limit;
            RGN::Modules::Inventory::InventoryModule::GetWithVirtualItemsDataForCurrentAppAsync(
                [onSuccess](vector<RGN::Modules::Inventory::InventoryItemData> response) {
                    godot::Array gArgs;
                    godot::Array gResponse;
                    godot::Array g_gResponse;
                    for (const auto& response_item : response) {
                        godot::Dictionary g_response_item;
                        godot::Dictionary g_g_response_item = g_response_item;
                        G_InventoryItemData::ConvertToGodotModel(response_item, g_g_response_item);
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
                cpp_startAfter,
                cpp_limit
            );
    }
    void getWithVirtualItemsDataByAppIdsAsync(
        godot::Array appIds,
        godot::String startAfter,
        int32_t limit,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            vector<string> cpp_appIds;
            string cpp_startAfter;
            int32_t cpp_limit;
            godot::Array g_cpp_appIds = appIds;
            for (int i = 0; i < g_cpp_appIds.size(); ++i) {
                godot::String g_cpp_appIds_item = g_cpp_appIds[i];
                string cpp_appIds_item;
                godot::String g_g_cpp_appIds_item = g_cpp_appIds_item;
                cpp_appIds_item = std::string(g_g_cpp_appIds_item.utf8().get_data());
                cpp_appIds.push_back(cpp_appIds_item);
            }
            godot::String g_startAfter = startAfter;
            cpp_startAfter = std::string(g_startAfter.utf8().get_data());
            int32_t g_limit = limit;
            cpp_limit = g_limit;
            RGN::Modules::Inventory::InventoryModule::GetWithVirtualItemsDataByAppIdsAsync(
                [onSuccess](vector<RGN::Modules::Inventory::InventoryItemData> response) {
                    godot::Array gArgs;
                    godot::Array gResponse;
                    godot::Array g_gResponse;
                    for (const auto& response_item : response) {
                        godot::Dictionary g_response_item;
                        godot::Dictionary g_g_response_item = g_response_item;
                        G_InventoryItemData::ConvertToGodotModel(response_item, g_g_response_item);
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
                cpp_appIds,
                cpp_startAfter,
                cpp_limit
            );
    }
    void parseInventoryItemData(
        godot::String json,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            string cpp_json;
            godot::String g_json = json;
            cpp_json = std::string(g_json.utf8().get_data());
            RGN::Modules::Inventory::InventoryModule::ParseInventoryItemData(
                cpp_json
            );
    }
    void parseInventoryItemsData(
        godot::String json,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            string cpp_json;
            godot::String g_json = json;
            cpp_json = std::string(g_json.utf8().get_data());
            RGN::Modules::Inventory::InventoryModule::ParseInventoryItemsData(
                cpp_json
            );
    }
    void getByTagsAsync(
        godot::Array tags,
        godot::String appId,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            vector<string> cpp_tags;
            string cpp_appId;
            godot::Array g_cpp_tags = tags;
            for (int i = 0; i < g_cpp_tags.size(); ++i) {
                godot::String g_cpp_tags_item = g_cpp_tags[i];
                string cpp_tags_item;
                godot::String g_g_cpp_tags_item = g_cpp_tags_item;
                cpp_tags_item = std::string(g_g_cpp_tags_item.utf8().get_data());
                cpp_tags.push_back(cpp_tags_item);
            }
            godot::String g_appId = appId;
            cpp_appId = std::string(g_appId.utf8().get_data());
            RGN::Modules::Inventory::InventoryModule::GetByTagsAsync(
                [onSuccess](vector<RGN::Modules::Inventory::InventoryItemData> response) {
                    godot::Array gArgs;
                    godot::Array gResponse;
                    godot::Array g_gResponse;
                    for (const auto& response_item : response) {
                        godot::Dictionary g_response_item;
                        godot::Dictionary g_g_response_item = g_response_item;
                        G_InventoryItemData::ConvertToGodotModel(response_item, g_g_response_item);
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
                cpp_tags,
                cpp_appId
            );
    }
    void getTagsAsync(
        godot::String ownedItemId,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            string cpp_ownedItemId;
            godot::String g_ownedItemId = ownedItemId;
            cpp_ownedItemId = std::string(g_ownedItemId.utf8().get_data());
            RGN::Modules::Inventory::InventoryModule::GetTagsAsync(
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
                    EXECUTE_GCALLBACK_DEFVAL(onSuccess, gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     EXECUTE_GCALLBACK_DEFVAL(onFail, gArgs);
                },
                cpp_ownedItemId
            );
    }
    void setTagsAsync(
        godot::String ownedItemId,
        godot::Array tags,
        godot::String appId,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            string cpp_ownedItemId;
            vector<string> cpp_tags;
            string cpp_appId;
            godot::String g_ownedItemId = ownedItemId;
            cpp_ownedItemId = std::string(g_ownedItemId.utf8().get_data());
            godot::Array g_cpp_tags = tags;
            for (int i = 0; i < g_cpp_tags.size(); ++i) {
                godot::String g_cpp_tags_item = g_cpp_tags[i];
                string cpp_tags_item;
                godot::String g_g_cpp_tags_item = g_cpp_tags_item;
                cpp_tags_item = std::string(g_g_cpp_tags_item.utf8().get_data());
                cpp_tags.push_back(cpp_tags_item);
            }
            godot::String g_appId = appId;
            cpp_appId = std::string(g_appId.utf8().get_data());
            RGN::Modules::Inventory::InventoryModule::SetTagsAsync(
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
                    EXECUTE_GCALLBACK_DEFVAL(onSuccess, gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     EXECUTE_GCALLBACK_DEFVAL(onFail, gArgs);
                },
                cpp_ownedItemId,
                cpp_tags,
                cpp_appId
            );
    }
};
