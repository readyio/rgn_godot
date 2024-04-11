#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../Utility/G_CancellationToken.h"
#include "../../../../../Utility/CancellationToken.h"
#include "../../../../../Generated/RGN/Modules/VirtualItems/VirtualItemsModule.h"
#include "../../../../../Generated/RGN/Modules/VirtualItems/VirtualItem.h"
#include "G_VirtualItem.h"
#include "../../../../../Generated/RGN/Modules/VirtualItems/AddVirtualItemResponseData.h"
#include "G_AddVirtualItemResponseData.h"
#include "../../../../../Generated/RGN/Modules/VirtualItems/AddToVirtualItemsRequestData.h"
#include "G_AddToVirtualItemsRequestData.h"
#include "../../../../../Generated/RGN/Modules/VirtualItems/UpdateVirtualItemsRequestData.h"
#include "G_UpdateVirtualItemsRequestData.h"
#include "../../../../../Generated/RGN/Modules/VirtualItems/VirtualItemsResponseData.h"
#include "G_VirtualItemsResponseData.h"
#include "../../../../../Generated/RGN/Model/Request/BaseMigrationRequestData.h"
#include "../../Model/Request/G_BaseMigrationRequestData.h"
#include "../../../../../Generated/RGN/Modules/VirtualItems/GetAllVirtualItemsByAppIdsRequestData.h"
#include "G_GetAllVirtualItemsByAppIdsRequestData.h"
#include "../../../../../Generated/RGN/Modules/VirtualItems/GetVirtualItemsByIdsRequestData.h"
#include "G_GetVirtualItemsByIdsRequestData.h"
#include "../../../../../Generated/RGN/Modules/VirtualItems/GetVirtualItemTagsResponse.h"
#include "G_GetVirtualItemTagsResponse.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>

using namespace std;

class G_VirtualItemsModule : public godot::Object {
    GDCLASS(G_VirtualItemsModule, godot::Object);
    static inline G_VirtualItemsModule* singleton = nullptr;
protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("addVirtualItemAsync", "virtualItem", "onSuccess", "onFail"), &G_VirtualItemsModule::addVirtualItemAsync, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("addFromCSVAsync", "virtualItemName", "csvContent", "csvDelimiter", "cancellationToken", "onSuccess", "onFail"), &G_VirtualItemsModule::addFromCSVAsync, DEFVAL(","), DEFVAL(nullptr), godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("updateVirtualItemAsync", "itemId", "virtualItem", "onSuccess", "onFail"), &G_VirtualItemsModule::updateVirtualItemAsync, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("deleteVirtualItemAsync", "itemId", "onSuccess", "onFail"), &G_VirtualItemsModule::deleteVirtualItemAsync, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("getVirtualItemsAsync", "onSuccess", "onFail"), &G_VirtualItemsModule::getVirtualItemsAsync, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("getVirtualItemsAsync_Limit_StartAfter", "limit", "startAfter", "onSuccess", "onFail"), &G_VirtualItemsModule::getVirtualItemsAsync_Limit_StartAfter, DEFVAL(""), godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("getVirtualItemsByIdsAsync", "virtualItemsIds", "onSuccess", "onFail"), &G_VirtualItemsModule::getVirtualItemsByIdsAsync, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("getByTagsAsync", "tags", "appId", "onSuccess", "onFail"), &G_VirtualItemsModule::getByTagsAsync, DEFVAL(""), godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("getTagsAsync", "virtualItemId", "onSuccess", "onFail"), &G_VirtualItemsModule::getTagsAsync, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("setTagsAsync", "virtualItemId", "tags", "appId", "onSuccess", "onFail"), &G_VirtualItemsModule::setTagsAsync, DEFVAL(""), godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("setNameAsync", "virtualItemId", "name", "onSuccess", "onFail"), &G_VirtualItemsModule::setNameAsync, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("setDescriptionAsync", "virtualItemId", "description", "onSuccess", "onFail"), &G_VirtualItemsModule::setDescriptionAsync, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("getPropertiesAsync", "virtualItemId", "onSuccess", "onFail"), &G_VirtualItemsModule::getPropertiesAsync, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("setPropertiesAsync", "virtualItemId", "json", "onSuccess", "onFail"), &G_VirtualItemsModule::setPropertiesAsync, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("uploadImageAsync", "virtualItemId", "thumbnailTextureBytes", "cancellationToken", "onSuccess", "onFail"), &G_VirtualItemsModule::uploadImageAsync, DEFVAL(nullptr), godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("downloadImageAsync", "virtualItemId", "size", "cancellationToken", "onSuccess", "onFail"), &G_VirtualItemsModule::downloadImageAsync, DEFVAL(nullptr), godot::Callable(), godot::Callable());
    }
public:
    static G_VirtualItemsModule *get_singleton() {
        return singleton;
    }
    G_VirtualItemsModule() {
        ERR_FAIL_COND(singleton != nullptr);
        singleton = this;
    }
    ~G_VirtualItemsModule() {
        ERR_FAIL_COND(singleton != this);
        singleton = nullptr;
    }
    void addVirtualItemAsync(
        godot::Dictionary virtualItem,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            RGN::Modules::VirtualItems::VirtualItem cpp_virtualItem;
            G_VirtualItem::ConvertToCoreModel(virtualItem, cpp_virtualItem);
            RGN::Modules::VirtualItems::VirtualItemsModule::AddVirtualItemAsync(
                [onSuccess](RGN::Modules::VirtualItems::VirtualItem response) {
                    godot::Array gArgs;
                    godot::Dictionary gResponse;
                    godot::Dictionary g_gResponse = gResponse;
                    G_VirtualItem::ConvertToGodotModel(response, g_gResponse);
                    gArgs.push_back(gResponse);
                    onSuccess.callv(gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                },
                cpp_virtualItem
            );
    }
    void addFromCSVAsync(
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
            RGN::Modules::VirtualItems::VirtualItemsModule::AddFromCSVAsync(
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
    void updateVirtualItemAsync(
        godot::String itemId,
        godot::Dictionary virtualItem,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            string cpp_itemId;
            RGN::Modules::VirtualItems::VirtualItem cpp_virtualItem;
            godot::String g_itemId = itemId;
            cpp_itemId = std::string(g_itemId.utf8().get_data());
            G_VirtualItem::ConvertToCoreModel(virtualItem, cpp_virtualItem);
            RGN::Modules::VirtualItems::VirtualItemsModule::UpdateVirtualItemAsync(
                [onSuccess](RGN::Modules::VirtualItems::VirtualItem response) {
                    godot::Array gArgs;
                    godot::Dictionary gResponse;
                    godot::Dictionary g_gResponse = gResponse;
                    G_VirtualItem::ConvertToGodotModel(response, g_gResponse);
                    gArgs.push_back(gResponse);
                    onSuccess.callv(gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                },
                cpp_itemId,
                cpp_virtualItem
            );
    }
    void deleteVirtualItemAsync(
        godot::String itemId,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            string cpp_itemId;
            godot::String g_itemId = itemId;
            cpp_itemId = std::string(g_itemId.utf8().get_data());
            RGN::Modules::VirtualItems::VirtualItemsModule::DeleteVirtualItemAsync(
                [onSuccess]() {
                    onSuccess.callv(godot::Array());
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                },
                cpp_itemId
            );
    }
    void getVirtualItemsAsync(
        godot::Callable onSuccess,
        godot::Callable onFail) {
            RGN::Modules::VirtualItems::VirtualItemsModule::GetVirtualItemsAsync(
                [onSuccess](vector<RGN::Modules::VirtualItems::VirtualItem> response) {
                    godot::Array gArgs;
                    godot::Array gResponse;
                    godot::Array g_gResponse;
                    for (const auto& response_item : response) {
                        godot::Dictionary g_response_item;
                        godot::Dictionary g_g_response_item = g_response_item;
                        G_VirtualItem::ConvertToGodotModel(response_item, g_g_response_item);
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
    void getVirtualItemsAsync_Limit_StartAfter(
        int32_t limit,
        godot::String startAfter,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            int32_t cpp_limit;
            string cpp_startAfter;
            int32_t g_limit = limit;
            cpp_limit = g_limit;
            godot::String g_startAfter = startAfter;
            cpp_startAfter = std::string(g_startAfter.utf8().get_data());
            RGN::Modules::VirtualItems::VirtualItemsModule::GetVirtualItemsAsync(
                [onSuccess](vector<RGN::Modules::VirtualItems::VirtualItem> response) {
                    godot::Array gArgs;
                    godot::Array gResponse;
                    godot::Array g_gResponse;
                    for (const auto& response_item : response) {
                        godot::Dictionary g_response_item;
                        godot::Dictionary g_g_response_item = g_response_item;
                        G_VirtualItem::ConvertToGodotModel(response_item, g_g_response_item);
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
                cpp_limit,
                cpp_startAfter
            );
    }
    void getVirtualItemsByIdsAsync(
        godot::Array virtualItemsIds,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            vector<string> cpp_virtualItemsIds;
            godot::Array g_cpp_virtualItemsIds = virtualItemsIds;
            for (int i = 0; i < g_cpp_virtualItemsIds.size(); ++i) {
                godot::String g_cpp_virtualItemsIds_item = g_cpp_virtualItemsIds[i];
                string cpp_virtualItemsIds_item;
                godot::String g_g_cpp_virtualItemsIds_item = g_cpp_virtualItemsIds_item;
                cpp_virtualItemsIds_item = std::string(g_g_cpp_virtualItemsIds_item.utf8().get_data());
                cpp_virtualItemsIds.push_back(cpp_virtualItemsIds_item);
            }
            RGN::Modules::VirtualItems::VirtualItemsModule::GetVirtualItemsByIdsAsync(
                [onSuccess](vector<RGN::Modules::VirtualItems::VirtualItem> response) {
                    godot::Array gArgs;
                    godot::Array gResponse;
                    godot::Array g_gResponse;
                    for (const auto& response_item : response) {
                        godot::Dictionary g_response_item;
                        godot::Dictionary g_g_response_item = g_response_item;
                        G_VirtualItem::ConvertToGodotModel(response_item, g_g_response_item);
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
                cpp_virtualItemsIds
            );
    }
    void getByTagsAsync(
        godot::Array tags,
        godot::String appId,
        godot::Callable onSuccess,
        godot::Callable onFail) {
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
            RGN::Modules::VirtualItems::VirtualItemsModule::GetByTagsAsync(
                [onSuccess](vector<RGN::Modules::VirtualItems::VirtualItem> response) {
                    godot::Array gArgs;
                    godot::Array gResponse;
                    godot::Array g_gResponse;
                    for (const auto& response_item : response) {
                        godot::Dictionary g_response_item;
                        godot::Dictionary g_g_response_item = g_response_item;
                        G_VirtualItem::ConvertToGodotModel(response_item, g_g_response_item);
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
                cpp_tags,
                cpp_appId
            );
    }
    void getTagsAsync(
        godot::String virtualItemId,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            string cpp_virtualItemId;
            godot::String g_virtualItemId = virtualItemId;
            cpp_virtualItemId = std::string(g_virtualItemId.utf8().get_data());
            RGN::Modules::VirtualItems::VirtualItemsModule::GetTagsAsync(
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
                cpp_virtualItemId
            );
    }
    void setTagsAsync(
        godot::String virtualItemId,
        godot::Array tags,
        godot::String appId,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            string cpp_virtualItemId;
            vector<string> cpp_tags;
            string cpp_appId;
            godot::String g_virtualItemId = virtualItemId;
            cpp_virtualItemId = std::string(g_virtualItemId.utf8().get_data());
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
            RGN::Modules::VirtualItems::VirtualItemsModule::SetTagsAsync(
                [onSuccess]() {
                    onSuccess.callv(godot::Array());
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                },
                cpp_virtualItemId,
                cpp_tags,
                cpp_appId
            );
    }
    void setNameAsync(
        godot::String virtualItemId,
        godot::String name,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            string cpp_virtualItemId;
            string cpp_name;
            godot::String g_virtualItemId = virtualItemId;
            cpp_virtualItemId = std::string(g_virtualItemId.utf8().get_data());
            godot::String g_name = name;
            cpp_name = std::string(g_name.utf8().get_data());
            RGN::Modules::VirtualItems::VirtualItemsModule::SetNameAsync(
                [onSuccess]() {
                    onSuccess.callv(godot::Array());
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                },
                cpp_virtualItemId,
                cpp_name
            );
    }
    void setDescriptionAsync(
        godot::String virtualItemId,
        godot::String description,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            string cpp_virtualItemId;
            string cpp_description;
            godot::String g_virtualItemId = virtualItemId;
            cpp_virtualItemId = std::string(g_virtualItemId.utf8().get_data());
            godot::String g_description = description;
            cpp_description = std::string(g_description.utf8().get_data());
            RGN::Modules::VirtualItems::VirtualItemsModule::SetDescriptionAsync(
                [onSuccess]() {
                    onSuccess.callv(godot::Array());
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                },
                cpp_virtualItemId,
                cpp_description
            );
    }
    void getPropertiesAsync(
        godot::String virtualItemId,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            string cpp_virtualItemId;
            godot::String g_virtualItemId = virtualItemId;
            cpp_virtualItemId = std::string(g_virtualItemId.utf8().get_data());
            RGN::Modules::VirtualItems::VirtualItemsModule::GetPropertiesAsync(
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
                cpp_virtualItemId
            );
    }
    void setPropertiesAsync(
        godot::String virtualItemId,
        godot::String json,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            string cpp_virtualItemId;
            string cpp_json;
            godot::String g_virtualItemId = virtualItemId;
            cpp_virtualItemId = std::string(g_virtualItemId.utf8().get_data());
            godot::String g_json = json;
            cpp_json = std::string(g_json.utf8().get_data());
            RGN::Modules::VirtualItems::VirtualItemsModule::SetPropertiesAsync(
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
                cpp_virtualItemId,
                cpp_json
            );
    }
    void uploadImageAsync(
        godot::String virtualItemId,
        godot::Array thumbnailTextureBytes,
        godot::Object* cancellationToken,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            string cpp_virtualItemId;
            vector<uint8_t> cpp_thumbnailTextureBytes;
            RGN::CancellationToken cpp_cancellationToken;
            godot::String g_virtualItemId = virtualItemId;
            cpp_virtualItemId = std::string(g_virtualItemId.utf8().get_data());
            godot::Array g_cpp_thumbnailTextureBytes = thumbnailTextureBytes;
            for (int i = 0; i < g_cpp_thumbnailTextureBytes.size(); ++i) {
                uint8_t g_cpp_thumbnailTextureBytes_item = static_cast<uint8_t>((uint32_t)g_cpp_thumbnailTextureBytes[i]);
                uint8_t cpp_thumbnailTextureBytes_item;
                uint8_t g_g_cpp_thumbnailTextureBytes_item = g_cpp_thumbnailTextureBytes_item;
                cpp_thumbnailTextureBytes_item = static_cast<uint8_t>(g_g_cpp_thumbnailTextureBytes_item);
                cpp_thumbnailTextureBytes.push_back(cpp_thumbnailTextureBytes_item);
            }
            G_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::VirtualItems::VirtualItemsModule::UploadImageAsync(
                [onSuccess](bool response) {
                    godot::Array gArgs;
                    bool gResponse;
                    gResponse = response;
                    gArgs.push_back(gResponse);
                    onSuccess.callv(gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                },
                cpp_virtualItemId,
                cpp_thumbnailTextureBytes,
                cpp_cancellationToken
            );
    }
    void downloadImageAsync(
        godot::String virtualItemId,
        int32_t size,
        godot::Object* cancellationToken,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            string cpp_virtualItemId;
            RGN::Model::ImageSize cpp_size;
            RGN::CancellationToken cpp_cancellationToken;
            godot::String g_virtualItemId = virtualItemId;
            cpp_virtualItemId = std::string(g_virtualItemId.utf8().get_data());
            int32_t g_size = size;
            cpp_size = static_cast<RGN::Model::ImageSize>(g_size);
            G_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::VirtualItems::VirtualItemsModule::DownloadImageAsync(
                [onSuccess](vector<uint8_t> response) {
                    godot::Array gArgs;
                    godot::Array gResponse;
                    godot::Array g_gResponse;
                    for (const auto& response_item : response) {
                        uint8_t g_response_item;
                        g_response_item = static_cast<uint32_t>(response_item);
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
                cpp_virtualItemId,
                cpp_size,
                cpp_cancellationToken
            );
    }
};
