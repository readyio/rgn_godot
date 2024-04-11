#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Messaging/MessagingModule.h"
#include "../../../../../Generated/RGN/Modules/Messaging/IMessageReceiver.h"
#include "G_IMessageReceiver.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>

using namespace std;

class G_MessagingModule : public godot::Object {
    GDCLASS(G_MessagingModule, godot::Object);
    static inline G_MessagingModule* singleton = nullptr;
protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("subscribe", "topic", "messageReceiver", "onSuccess", "onFail"), &G_MessagingModule::subscribe, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("unsubscribe", "topic", "messageReceiver", "onSuccess", "onFail"), &G_MessagingModule::unsubscribe, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("sendMessageByUserId", "appId", "userId", "payload", "title", "text", "onSuccess", "onFail"), &G_MessagingModule::sendMessageByUserId, godot::Callable(), godot::Callable());
    }
public:
    static G_MessagingModule *get_singleton() {
        return singleton;
    }
    G_MessagingModule() {
        ERR_FAIL_COND(singleton != nullptr);
        singleton = this;
    }
    ~G_MessagingModule() {
        ERR_FAIL_COND(singleton != this);
        singleton = nullptr;
    }
    void subscribe(
        godot::String topic,
        godot::Dictionary messageReceiver,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            string cpp_topic;
            RGN::Modules::Messaging::IMessageReceiver cpp_messageReceiver;
            godot::String g_topic = topic;
            cpp_topic = std::string(g_topic.utf8().get_data());
            G_IMessageReceiver::ConvertToCoreModel(messageReceiver, cpp_messageReceiver);
            RGN::Modules::Messaging::MessagingModule::Subscribe(
                cpp_topic,
                cpp_messageReceiver
            );
    }
    void unsubscribe(
        godot::String topic,
        godot::Dictionary messageReceiver,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            string cpp_topic;
            RGN::Modules::Messaging::IMessageReceiver cpp_messageReceiver;
            godot::String g_topic = topic;
            cpp_topic = std::string(g_topic.utf8().get_data());
            G_IMessageReceiver::ConvertToCoreModel(messageReceiver, cpp_messageReceiver);
            RGN::Modules::Messaging::MessagingModule::Unsubscribe(
                cpp_topic,
                cpp_messageReceiver
            );
    }
    void sendMessageByUserId(
        godot::String appId,
        godot::String userId,
        godot::String payload,
        godot::String title,
        godot::String text,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            string cpp_appId;
            string cpp_userId;
            string cpp_payload;
            string cpp_title;
            string cpp_text;
            godot::String g_appId = appId;
            cpp_appId = std::string(g_appId.utf8().get_data());
            godot::String g_userId = userId;
            cpp_userId = std::string(g_userId.utf8().get_data());
            godot::String g_payload = payload;
            cpp_payload = std::string(g_payload.utf8().get_data());
            godot::String g_title = title;
            cpp_title = std::string(g_title.utf8().get_data());
            godot::String g_text = text;
            cpp_text = std::string(g_text.utf8().get_data());
            RGN::Modules::Messaging::MessagingModule::SendMessageByUserId(
                [onSuccess]() {
                    onSuccess.callv(godot::Array());
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                },
                cpp_appId,
                cpp_userId,
                cpp_payload,
                cpp_title,
                cpp_text
            );
    }
};
