#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Wallets/WalletsModule.h"
#include "../../../../../Generated/RGN/Modules/Wallets/IsUserHasBlockchainRequirementResponseData.h"
#include "G_IsUserHasBlockchainRequirementResponseData.h"
#include "Impl/G_Defs.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>

using namespace std;

class G_WalletsModule : public godot::Object {
    REG_GCLASS(G_WalletsModule, godot::Object);
#ifdef GODOT4
    static G_WalletsModule* singleton;
#endif
public:
#ifdef GODOT3
    void _init() {}
#else
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
#endif
    REG_GCLASS_METHODS_HEADER() {
        BIND_GCLASS_METHOD_DEFVAL(G_WalletsModule::isUserHasBlockchainRequirementAsync, GCLASS_METHOD_SIGNATURE("isUserHasBlockchainRequirementAsync", "onSuccess", "onFail"), &G_WalletsModule::isUserHasBlockchainRequirementAsync, GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
    }
    void isUserHasBlockchainRequirementAsync(
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            RGN::Modules::Wallets::WalletsModule::IsUserHasBlockchainRequirementAsync(
                [onSuccess](bool response) {
                    godot::Array gArgs;
                    bool gResponse;
                    gResponse = response;
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
