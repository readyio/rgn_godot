#pragma once

#include "Impl/Core/G_RGNEnvironmentTarget.h"
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/variant/string.hpp>
#include <functional>
#include <vector>

class G_RGNConfigurationData : public godot::Object
{
private:
    GDCLASS(G_RGNConfigurationData, godot::Object);
    godot::String appId = "";
    godot::String apiKey = "";
    G_RGNEnvironmentTarget::Enumeration environmentTarget = G_RGNEnvironmentTarget::Enumeration::STAGING;
    bool autoGuestLogin = true;
    bool useFunctionsEmulator = false;
    godot::String emulatorHost = "127.0.0.1";
    godot::String emulatorPort = "5001";
protected:
	static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("getAppId"), &G_RGNConfigurationData::getAppId);
        godot::ClassDB::bind_method(godot::D_METHOD("setAppId", "appId"), &G_RGNConfigurationData::setAppId);
        godot::ClassDB::bind_method(godot::D_METHOD("getApiKey"), &G_RGNConfigurationData::getApiKey);
        godot::ClassDB::bind_method(godot::D_METHOD("setApiKey", "apiKey"), &G_RGNConfigurationData::setApiKey);
        godot::ClassDB::bind_method(godot::D_METHOD("getEnvironmentTarget"), &G_RGNConfigurationData::getEnvironmentTarget);
        godot::ClassDB::bind_method(godot::D_METHOD("setEnvironmentTarget", "environmentTarget"), &G_RGNConfigurationData::setEnvironmentTarget);
        godot::ClassDB::bind_method(godot::D_METHOD("getAutoGuestLogin"), &G_RGNConfigurationData::getAutoGuestLogin);
        godot::ClassDB::bind_method(godot::D_METHOD("setAutoGuestLogin", "autoGuestLogin"), &G_RGNConfigurationData::setAutoGuestLogin);
        godot::ClassDB::bind_method(godot::D_METHOD("getUseFunctionsEmulator"), &G_RGNConfigurationData::getUseFunctionsEmulator);
        godot::ClassDB::bind_method(godot::D_METHOD("setUseFunctionsEmulator", "useFunctionsEmulator"), &G_RGNConfigurationData::setUseFunctionsEmulator);
        godot::ClassDB::bind_method(godot::D_METHOD("getEmulatorHost"), &G_RGNConfigurationData::getEmulatorHost);
        godot::ClassDB::bind_method(godot::D_METHOD("setEmulatorHost", "host"), &G_RGNConfigurationData::setEmulatorHost);
        godot::ClassDB::bind_method(godot::D_METHOD("getEmulatorPort"), &G_RGNConfigurationData::getEmulatorPort);
        godot::ClassDB::bind_method(godot::D_METHOD("setEmulatorPort", "port"), &G_RGNConfigurationData::setEmulatorPort);
	}
public:
    godot::String getAppId() {
        return appId;
    }
    G_RGNConfigurationData* setAppId(godot::String appId) {
        this->appId = appId;
        return this;
    }
    godot::String getApiKey() {
        return apiKey;
    }
    G_RGNConfigurationData* setApiKey(godot::String apiKey) {
        this->apiKey = apiKey;
        return this;
    }
    G_RGNEnvironmentTarget::Enumeration getEnvironmentTarget() {
        return environmentTarget;
    }
    G_RGNConfigurationData* setEnvironmentTarget(G_RGNEnvironmentTarget::Enumeration environmentTarget) {
        this->environmentTarget = environmentTarget;
        return this;
    }
    bool getAutoGuestLogin() {
        return autoGuestLogin;
    }
    G_RGNConfigurationData* setAutoGuestLogin(bool autoGuestLogin) {
        this->autoGuestLogin = autoGuestLogin;
        return this;
    }
    bool getUseFunctionsEmulator() {
        return useFunctionsEmulator;
    }
    G_RGNConfigurationData* setUseFunctionsEmulator(bool useFunctionsEmulator) {
        this->useFunctionsEmulator = useFunctionsEmulator;
        return this;
    }
    godot::String getEmulatorHost() {
        return emulatorHost;
    }
    G_RGNConfigurationData* setEmulatorHost(godot::String host) {
        this->emulatorHost = host;
        return this;
    }
    godot::String getEmulatorPort() {
        return emulatorPort;
    }
    G_RGNConfigurationData* setEmulatorPort(godot::String port) {
        this->emulatorPort = port;
        return this;
    }
};