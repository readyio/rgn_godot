#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../Utility/G_CancellationToken.h"
#include "../../../../../Utility/CancellationToken.h"
#include "../../../../../Generated/RGN/Modules/Analytics/AnalyticsModule.h"
#include "Impl/G_Defs.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>

using namespace std;

class G_AnalyticsModule : public godot::Object {
    REG_GCLASS(G_AnalyticsModule, godot::Object);
#ifdef GODOT4
    static G_AnalyticsModule* singleton;
#endif
public:
#ifdef GODOT3
    void _init() {}
#else
    static G_AnalyticsModule *get_singleton() {
        return singleton;
    }
    G_AnalyticsModule() {
        ERR_FAIL_COND(singleton != nullptr);
        singleton = this;
    }
    ~G_AnalyticsModule() {
        ERR_FAIL_COND(singleton != this);
        singleton = nullptr;
    }
#endif
    REG_GCLASS_METHODS_HEADER() {
        BIND_GCLASS_METHOD_DEFVAL(G_AnalyticsModule::logEventAsync, GCLASS_METHOD_SIGNATURE("logEventAsync", "eventName", "eventParameters", "cancellationToken", "onSuccess", "onFail"), &G_AnalyticsModule::logEventAsync, DEFVAL(""), DEFVAL(nullptr), GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
    }
    void logEventAsync(
        godot::String eventName,
        godot::String eventParameters,
        godot::Object* cancellationToken,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            string cpp_eventName;
            string cpp_eventParameters;
            RGN::CancellationToken cpp_cancellationToken;
            godot::String g_eventName = eventName;
            cpp_eventName = std::string(g_eventName.utf8().get_data());
            godot::String g_eventParameters = eventParameters;
            cpp_eventParameters = std::string(g_eventParameters.utf8().get_data());
            G_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Analytics::AnalyticsModule::LogEventAsync(
                [onSuccess]() {
                    EXECUTE_GCALLBACK_DEFVAL(onSuccess, godot::Array());
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     EXECUTE_GCALLBACK_DEFVAL(onFail, gArgs);
                },
                cpp_eventName,
                cpp_eventParameters,
                cpp_cancellationToken
            );
    }
};
