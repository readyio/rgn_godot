#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Leaderboard/LeaderboardModule_Admin.h"
#include "../../../../../Generated/RGN/Modules/Leaderboard/LeaderboardData.h"
#include "G_LeaderboardData.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>

using namespace std;

class G_LeaderboardModule_Admin : public godot::Object {
    GDCLASS(G_LeaderboardModule_Admin, godot::Object);
    static inline G_LeaderboardModule_Admin* singleton = nullptr;
protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("addLeaderboardAsync", "leaderboardData", "onSuccess", "onFail"), &G_LeaderboardModule_Admin::addLeaderboardAsync, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("updateLeaderboardAsync", "leaderboardData", "onSuccess", "onFail"), &G_LeaderboardModule_Admin::updateLeaderboardAsync, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("deleteLeaderboardAsync", "leaderboardId", "onSuccess", "onFail"), &G_LeaderboardModule_Admin::deleteLeaderboardAsync, godot::Callable(), godot::Callable());
    }
public:
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
    void addLeaderboardAsync(
        godot::Dictionary leaderboardData,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            RGN::Modules::Leaderboard::LeaderboardData cpp_leaderboardData;
            G_LeaderboardData::ConvertToCoreModel(leaderboardData, cpp_leaderboardData);
            RGN::Modules::Leaderboard::LeaderboardModule_Admin::AddLeaderboardAsync(
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
                cpp_leaderboardData
            );
    }
    void updateLeaderboardAsync(
        godot::Dictionary leaderboardData,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            RGN::Modules::Leaderboard::LeaderboardData cpp_leaderboardData;
            G_LeaderboardData::ConvertToCoreModel(leaderboardData, cpp_leaderboardData);
            RGN::Modules::Leaderboard::LeaderboardModule_Admin::UpdateLeaderboardAsync(
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
                cpp_leaderboardData
            );
    }
    void deleteLeaderboardAsync(
        godot::String leaderboardId,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            string cpp_leaderboardId;
            godot::String g_leaderboardId = leaderboardId;
            cpp_leaderboardId = std::string(g_leaderboardId.utf8().get_data());
            RGN::Modules::Leaderboard::LeaderboardModule_Admin::DeleteLeaderboardAsync(
                [onSuccess]() {
                    onSuccess.callv(godot::Array());
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                },
                cpp_leaderboardId
            );
    }
};
