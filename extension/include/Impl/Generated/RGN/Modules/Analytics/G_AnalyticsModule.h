#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../Utility/G_CancellationToken.h"
#include "../../../../../Utility/CancellationToken.h"
#include "../../../../../Generated/RGN/Modules/Analytics/AnalyticsModule.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>

using namespace std;

class G_AnalyticsModule : public godot::Object {
    GDCLASS(G_AnalyticsModule, godot::Object);
    static inline G_AnalyticsModule* singleton = nullptr;
protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("logEventAsync", "eventName", "eventParameters", "cancellationToken", "onSuccess", "onFail"), &G_AnalyticsModule::logEventAsync, DEFVAL(""), DEFVAL(nullptr), godot::Callable(), godot::Callable());
    }
public:
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
    void logEventAsync(
        godot::String eventName,
        godot::String eventParameters,
        godot::Object* cancellationToken,
        godot::Callable onSuccess,
        godot::Callable onFail) {
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
                    onSuccess.callv(godot::Array());
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                },
                cpp_eventName,
                cpp_eventParameters,
                cpp_cancellationToken
            );
    }
};
