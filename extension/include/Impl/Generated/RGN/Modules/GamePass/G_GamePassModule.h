#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/GamePass/GamePassModule.h"
#include "../../../../../Generated/RGN/Modules/GamePass/GamePassData.h"
#include "G_GamePassData.h"
#include "../../../../../Generated/RGN/Modules/GamePass/GetForCurrentAppResponseData.h"
#include "G_GetForCurrentAppResponseData.h"
#include "../../../../../Generated/RGN/Model/Request/BaseRequestData.h"
#include "../../Model/Request/G_BaseRequestData.h"
#include "../../../../../Generated/RGN/Modules/GamePass/GetGamePassUserDataResponseData.h"
#include "G_GetGamePassUserDataResponseData.h"
#include "../../../../../Generated/RGN/Modules/GamePass/GamePassUserData.h"
#include "G_GamePassUserData.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>

using namespace std;

class G_GamePassModule : public godot::Object {
    GDCLASS(G_GamePassModule, godot::Object);
    static inline G_GamePassModule* singleton = nullptr;
protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("getAsync", "id", "requestName", "onSuccess", "onFail"), &G_GamePassModule::getAsync, DEFVAL(""), DEFVAL(""), godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("getForCurrentAppAsync", "onSuccess", "onFail"), &G_GamePassModule::getForCurrentAppAsync, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("getForUserAsync", "id", "requestName", "userId", "onSuccess", "onFail"), &G_GamePassModule::getForUserAsync, DEFVAL(""), DEFVAL(""), DEFVAL(""), godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("getAllForUserAsync", "userId", "onSuccess", "onFail"), &G_GamePassModule::getAllForUserAsync, DEFVAL(""), godot::Callable(), godot::Callable());
    }
public:
    static G_GamePassModule *get_singleton() {
        return singleton;
    }
    G_GamePassModule() {
        ERR_FAIL_COND(singleton != nullptr);
        singleton = this;
    }
    ~G_GamePassModule() {
        ERR_FAIL_COND(singleton != this);
        singleton = nullptr;
    }
    void getAsync(
        godot::String id,
        godot::String requestName,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            string cpp_id;
            string cpp_requestName;
            godot::String g_id = id;
            cpp_id = std::string(g_id.utf8().get_data());
            godot::String g_requestName = requestName;
            cpp_requestName = std::string(g_requestName.utf8().get_data());
            RGN::Modules::GamePass::GamePassModule::GetAsync(
                [onSuccess](RGN::Modules::GamePass::GamePassData response) {
                    godot::Array gArgs;
                    godot::Dictionary gResponse;
                    godot::Dictionary g_gResponse = gResponse;
                    G_GamePassData::ConvertToGodotModel(response, g_gResponse);
                    gArgs.push_back(gResponse);
                    onSuccess.callv(gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                },
                cpp_id,
                cpp_requestName
            );
    }
    void getForCurrentAppAsync(
        godot::Callable onSuccess,
        godot::Callable onFail) {
            RGN::Modules::GamePass::GamePassModule::GetForCurrentAppAsync(
                [onSuccess](vector<RGN::Modules::GamePass::GamePassData> response) {
                    godot::Array gArgs;
                    godot::Array gResponse;
                    godot::Array g_gResponse;
                    for (const auto& response_item : response) {
                        godot::Dictionary g_response_item;
                        godot::Dictionary g_g_response_item = g_response_item;
                        G_GamePassData::ConvertToGodotModel(response_item, g_g_response_item);
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
    void getForUserAsync(
        godot::String id,
        godot::String requestName,
        godot::String userId,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            string cpp_id;
            string cpp_requestName;
            string cpp_userId;
            godot::String g_id = id;
            cpp_id = std::string(g_id.utf8().get_data());
            godot::String g_requestName = requestName;
            cpp_requestName = std::string(g_requestName.utf8().get_data());
            godot::String g_userId = userId;
            cpp_userId = std::string(g_userId.utf8().get_data());
            RGN::Modules::GamePass::GamePassModule::GetForUserAsync(
                [onSuccess](vector<RGN::Modules::GamePass::GamePassUserData> response) {
                    godot::Array gArgs;
                    godot::Array gResponse;
                    godot::Array g_gResponse;
                    for (const auto& response_item : response) {
                        godot::Dictionary g_response_item;
                        godot::Dictionary g_g_response_item = g_response_item;
                        G_GamePassUserData::ConvertToGodotModel(response_item, g_g_response_item);
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
                cpp_id,
                cpp_requestName,
                cpp_userId
            );
    }
    void getAllForUserAsync(
        godot::String userId,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            string cpp_userId;
            godot::String g_userId = userId;
            cpp_userId = std::string(g_userId.utf8().get_data());
            RGN::Modules::GamePass::GamePassModule::GetAllForUserAsync(
                [onSuccess](vector<RGN::Modules::GamePass::GamePassUserData> response) {
                    godot::Array gArgs;
                    godot::Array gResponse;
                    godot::Array g_gResponse;
                    for (const auto& response_item : response) {
                        godot::Dictionary g_response_item;
                        godot::Dictionary g_g_response_item = g_response_item;
                        G_GamePassUserData::ConvertToGodotModel(response_item, g_g_response_item);
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
                cpp_userId
            );
    }
};
