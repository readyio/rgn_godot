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
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>

using namespace std;

class G_GameProgressModule : public godot::Object {
    GDCLASS(G_GameProgressModule, godot::Object);
    static inline G_GameProgressModule* singleton = nullptr;
protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("onGameCompleteAsync", "reward", "onSuccess", "onFail"), &G_GameProgressModule::onGameCompleteAsync, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("getGameProgressAsync", "onSuccess", "onFail"), &G_GameProgressModule::getGameProgressAsync, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("addUserProgressAsync", "userProgressJson", "onSuccess", "onFail"), &G_GameProgressModule::addUserProgressAsync, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("updateUserProgressAsync", "userProgressJson", "reward", "onSuccess", "onFail"), &G_GameProgressModule::updateUserProgressAsync, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("getUserProgressAsync", "onSuccess", "onFail"), &G_GameProgressModule::getUserProgressAsync, godot::Callable(), godot::Callable());
    }
public:
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
    void onGameCompleteAsync(
        godot::Array reward,
        godot::Callable onSuccess,
        godot::Callable onFail) {
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
                    onSuccess.callv(gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                },
                cpp_reward
            );
    }
    void getGameProgressAsync(
        godot::Callable onSuccess,
        godot::Callable onFail) {
            RGN::Modules::GameProgress::GameProgressModule::GetGameProgressAsync(
                [onSuccess](RGN::Modules::GameProgress::GameProgress response) {
                    godot::Array gArgs;
                    godot::Dictionary gResponse;
                    godot::Dictionary g_gResponse = gResponse;
                    G_GameProgress::ConvertToGodotModel(response, g_gResponse);
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
    void addUserProgressAsync(
        godot::String userProgressJson,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            string cpp_userProgressJson;
            godot::String g_userProgressJson = userProgressJson;
            cpp_userProgressJson = std::string(g_userProgressJson.utf8().get_data());
            RGN::Modules::GameProgress::GameProgressModule::AddUserProgressAsync(
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
                cpp_userProgressJson
            );
    }
    void updateUserProgressAsync(
        godot::String userProgressJson,
        godot::Array reward,
        godot::Callable onSuccess,
        godot::Callable onFail) {
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
                    onSuccess.callv(gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                },
                cpp_userProgressJson,
                cpp_reward
            );
    }
    void getUserProgressAsync(
        godot::Callable onSuccess,
        godot::Callable onFail) {
            RGN::Modules::GameProgress::GameProgressModule::GetUserProgressAsync(
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
                }            );
    }
};
