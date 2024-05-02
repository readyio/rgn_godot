#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/GameProgress/GameProgressModule.h"
#include "../../../../../Generated/RGN/Modules/Currency/Currency.h"
#include "../Currency/G_Currency.h"
#include "../../../../../Generated/RGN/Modules/GameProgress/OnGameCompleteResult.h"
#include "G_OnGameCompleteResult.h"
#include "../../../../../Generated/RGN/Modules/GameProgress/OnGameCompleteRequestData.h"
#include "G_OnGameCompleteRequestData.h"
#include "../../../../../Generated/RGN/Modules/GameProgress/GameProgress.h"
#include "G_GameProgress.h"
#include "../../../../../Generated/RGN/Model/Request/BaseMigrationRequestData.h"
#include "../../Model/Request/G_BaseMigrationRequestData.h"
#include "../../../../../Generated/RGN/Modules/GameProgress/AddUserLevelRequestData.h"
#include "G_AddUserLevelRequestData.h"
#include "../../../../../Generated/RGN/Modules/GameProgress/UpdateUserLevelResponseData.h"
#include "G_UpdateUserLevelResponseData.h"
#include "../../../../../Generated/RGN/Modules/GameProgress/UpdateUserLevelRequestData.h"
#include "G_UpdateUserLevelRequestData.h"
#include "../../../../../Generated/RGN/Modules/GameProgress/GetPlayerLevelResponseData.h"
#include "G_GetPlayerLevelResponseData.h"
#include "Impl/G_Defs.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>

using namespace std;

class G_GameProgressModule : public godot::Object {
    REG_GCLASS(G_GameProgressModule, godot::Object);
#ifdef GODOT4
    static G_GameProgressModule* singleton;
#endif
public:
#ifdef GODOT3
    void _init() {}
#else
    static G_GameProgressModule *get_singleton() {
        return singleton;
    }
    G_GameProgressModule() {
        ERR_FAIL_COND(singleton != nullptr);
        singleton = this;
    }
    ~G_GameProgressModule() {
        ERR_FAIL_COND(singleton != this);
        singleton = nullptr;
    }
#endif
    REG_GCLASS_METHODS_HEADER() {
        BIND_GCLASS_METHOD_DEFVAL(G_GameProgressModule::onGameCompleteAsync, GCLASS_METHOD_SIGNATURE("onGameCompleteAsync", "reward", "onSuccess", "onFail"), &G_GameProgressModule::onGameCompleteAsync, GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_GameProgressModule::getGameProgressAsync, GCLASS_METHOD_SIGNATURE("getGameProgressAsync", "onSuccess", "onFail"), &G_GameProgressModule::getGameProgressAsync, GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_GameProgressModule::addUserProgressAsync, GCLASS_METHOD_SIGNATURE("addUserProgressAsync", "userProgressJson", "onSuccess", "onFail"), &G_GameProgressModule::addUserProgressAsync, GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_GameProgressModule::updateUserProgressAsync, GCLASS_METHOD_SIGNATURE("updateUserProgressAsync", "userProgressJson", "reward", "onSuccess", "onFail"), &G_GameProgressModule::updateUserProgressAsync, GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_GameProgressModule::getUserProgressAsync, GCLASS_METHOD_SIGNATURE("getUserProgressAsync", "onSuccess", "onFail"), &G_GameProgressModule::getUserProgressAsync, GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
    }
    void onGameCompleteAsync(
        godot::Array reward,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            vector<RGN::Modules::Currency::Currency> cpp_reward;
            godot::Array g_cpp_reward = reward;
            for (int i = 0; i < g_cpp_reward.size(); ++i) {
                godot::Dictionary g_cpp_reward_item = g_cpp_reward[i];
                RGN::Modules::Currency::Currency cpp_reward_item;
                G_Currency::ConvertToCoreModel(g_cpp_reward_item, cpp_reward_item);
                cpp_reward.push_back(cpp_reward_item);
            }
            RGN::Modules::GameProgress::GameProgressModule::OnGameCompleteAsync(
                [onSuccess](RGN::Modules::GameProgress::OnGameCompleteResult response) {
                    godot::Array gArgs;
                    godot::Dictionary gResponse;
                    godot::Dictionary g_gResponse = gResponse;
                    G_OnGameCompleteResult::ConvertToGodotModel(response, g_gResponse);
                    gArgs.push_back(gResponse);
                    EXECUTE_GCALLBACK_DEFVAL(onSuccess, gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     EXECUTE_GCALLBACK_DEFVAL(onFail, gArgs);
                },
                cpp_reward
            );
    }
    void getGameProgressAsync(
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            RGN::Modules::GameProgress::GameProgressModule::GetGameProgressAsync(
                [onSuccess](RGN::Modules::GameProgress::GameProgress response) {
                    godot::Array gArgs;
                    godot::Dictionary gResponse;
                    godot::Dictionary g_gResponse = gResponse;
                    G_GameProgress::ConvertToGodotModel(response, g_gResponse);
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
    void addUserProgressAsync(
        godot::String userProgressJson,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            string cpp_userProgressJson;
            godot::String g_userProgressJson = userProgressJson;
            cpp_userProgressJson = std::string(g_userProgressJson.utf8().get_data());
            RGN::Modules::GameProgress::GameProgressModule::AddUserProgressAsync(
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
                cpp_userProgressJson
            );
    }
    void updateUserProgressAsync(
        godot::String userProgressJson,
        godot::Array reward,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            string cpp_userProgressJson;
            vector<RGN::Modules::Currency::Currency> cpp_reward;
            godot::String g_userProgressJson = userProgressJson;
            cpp_userProgressJson = std::string(g_userProgressJson.utf8().get_data());
            godot::Array g_cpp_reward = reward;
            for (int i = 0; i < g_cpp_reward.size(); ++i) {
                godot::Dictionary g_cpp_reward_item = g_cpp_reward[i];
                RGN::Modules::Currency::Currency cpp_reward_item;
                G_Currency::ConvertToCoreModel(g_cpp_reward_item, cpp_reward_item);
                cpp_reward.push_back(cpp_reward_item);
            }
            RGN::Modules::GameProgress::GameProgressModule::UpdateUserProgressAsync(
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
                cpp_userProgressJson,
                cpp_reward
            );
    }
    void getUserProgressAsync(
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            RGN::Modules::GameProgress::GameProgressModule::GetUserProgressAsync(
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
                }            );
    }
};
