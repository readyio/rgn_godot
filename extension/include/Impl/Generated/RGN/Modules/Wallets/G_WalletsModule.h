#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Wallets/WalletsModule.h"
#include "../../../../../Generated/RGN/Modules/Wallets/IsUserHasBlockchainRequirementResponseData.h"
#include "G_IsUserHasBlockchainRequirementResponseData.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>

using namespace std;

class G_WalletsModule : public godot::Object {
    GDCLASS(G_WalletsModule, godot::Object);
    static inline G_WalletsModule* singleton = nullptr;
protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("isUserHasBlockchainRequirementAsync", "onSuccess", "onFail"), &G_WalletsModule::isUserHasBlockchainRequirementAsync, godot::Callable(), godot::Callable());
    }
public:
    static G_WalletsModule *get_singleton() {
        return singleton;
    }
    G_WalletsModule() {
        ERR_FAIL_COND(singleton != nullptr);
        singleton = this;
    }
    ~G_WalletsModule() {
        ERR_FAIL_COND(singleton != this);
        singleton = nullptr;
    }
    void isUserHasBlockchainRequirementAsync(
        godot::Callable onSuccess,
        godot::Callable onFail) {
            RGN::Modules::Wallets::WalletsModule::IsUserHasBlockchainRequirementAsync(
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
                }            );
    }
};
