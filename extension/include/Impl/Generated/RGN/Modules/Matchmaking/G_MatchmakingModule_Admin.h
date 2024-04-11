#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Matchmaking/MatchmakingModule_Admin.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>

using namespace std;

class G_MatchmakingModule_Admin : public godot::Object {
    GDCLASS(G_MatchmakingModule_Admin, godot::Object);
    static inline G_MatchmakingModule_Admin* singleton = nullptr;
protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("deleteMatchesByAppIdAsync", "appIdToRemoveTheMatchesFor", "onSuccess", "onFail"), &G_MatchmakingModule_Admin::deleteMatchesByAppIdAsync, godot::Callable(), godot::Callable());
    }
public:
    static G_MatchmakingModule_Admin *get_singleton() {
        return singleton;
    }
    G_MatchmakingModule_Admin() {
        ERR_FAIL_COND(singleton != nullptr);
        singleton = this;
    }
    ~G_MatchmakingModule_Admin() {
        ERR_FAIL_COND(singleton != this);
        singleton = nullptr;
    }
    void deleteMatchesByAppIdAsync(
        godot::String appIdToRemoveTheMatchesFor,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            string cpp_appIdToRemoveTheMatchesFor;
            godot::String g_appIdToRemoveTheMatchesFor = appIdToRemoveTheMatchesFor;
            cpp_appIdToRemoveTheMatchesFor = std::string(g_appIdToRemoveTheMatchesFor.utf8().get_data());
            RGN::Modules::Matchmaking::MatchmakingModule_Admin::DeleteMatchesByAppIdAsync(
                [onSuccess]() {
                    onSuccess.callv(godot::Array());
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                },
                cpp_appIdToRemoveTheMatchesFor
            );
    }
};
