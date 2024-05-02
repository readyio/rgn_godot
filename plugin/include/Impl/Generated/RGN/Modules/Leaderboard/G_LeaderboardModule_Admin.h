#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Leaderboard/LeaderboardModule_Admin.h"
#include "../../../../../Generated/RGN/Modules/Leaderboard/LeaderboardData.h"
#include "G_LeaderboardData.h"
#include "Impl/G_Defs.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>

using namespace std;

class G_LeaderboardModule_Admin : public godot::Object {
    REG_GCLASS(G_LeaderboardModule_Admin, godot::Object);
#ifdef GODOT4
    static G_LeaderboardModule_Admin* singleton;
#endif
public:
#ifdef GODOT3
    void _init() {}
#else
    static G_LeaderboardModule_Admin *get_singleton() {
        return singleton;
    }
    G_LeaderboardModule_Admin() {
        ERR_FAIL_COND(singleton != nullptr);
        singleton = this;
    }
    ~G_LeaderboardModule_Admin() {
        ERR_FAIL_COND(singleton != this);
        singleton = nullptr;
    }
#endif
    REG_GCLASS_METHODS_HEADER() {
        BIND_GCLASS_METHOD_DEFVAL(G_LeaderboardModule_Admin::addLeaderboardAsync, GCLASS_METHOD_SIGNATURE("addLeaderboardAsync", "leaderboardData", "onSuccess", "onFail"), &G_LeaderboardModule_Admin::addLeaderboardAsync, GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_LeaderboardModule_Admin::updateLeaderboardAsync, GCLASS_METHOD_SIGNATURE("updateLeaderboardAsync", "leaderboardData", "onSuccess", "onFail"), &G_LeaderboardModule_Admin::updateLeaderboardAsync, GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_LeaderboardModule_Admin::deleteLeaderboardAsync, GCLASS_METHOD_SIGNATURE("deleteLeaderboardAsync", "leaderboardId", "onSuccess", "onFail"), &G_LeaderboardModule_Admin::deleteLeaderboardAsync, GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
    }
    void addLeaderboardAsync(
        godot::Dictionary leaderboardData,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            RGN::Modules::Leaderboard::LeaderboardData cpp_leaderboardData;
            G_LeaderboardData::ConvertToCoreModel(leaderboardData, cpp_leaderboardData);
            RGN::Modules::Leaderboard::LeaderboardModule_Admin::AddLeaderboardAsync(
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
                cpp_leaderboardData
            );
    }
    void updateLeaderboardAsync(
        godot::Dictionary leaderboardData,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            RGN::Modules::Leaderboard::LeaderboardData cpp_leaderboardData;
            G_LeaderboardData::ConvertToCoreModel(leaderboardData, cpp_leaderboardData);
            RGN::Modules::Leaderboard::LeaderboardModule_Admin::UpdateLeaderboardAsync(
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
                cpp_leaderboardData
            );
    }
    void deleteLeaderboardAsync(
        godot::String leaderboardId,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            string cpp_leaderboardId;
            godot::String g_leaderboardId = leaderboardId;
            cpp_leaderboardId = std::string(g_leaderboardId.utf8().get_data());
            RGN::Modules::Leaderboard::LeaderboardModule_Admin::DeleteLeaderboardAsync(
                [onSuccess]() {
                    EXECUTE_GCALLBACK_DEFVAL(onSuccess, godot::Array());
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     EXECUTE_GCALLBACK_DEFVAL(onFail, gArgs);
                },
                cpp_leaderboardId
            );
    }
};
