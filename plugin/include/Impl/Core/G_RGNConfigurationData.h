#pragma once

#include "Impl/G_Defs.h"
#include "Core/RGNEnvironmentTarget.h"
#include <functional>
#include <vector>

class G_RGNConfigurationData : public godot::Object
{
private:
	REG_GCLASS(G_RGNConfigurationData, godot::Object);
    godot::String appId = "";
    godot::String apiKey = "";
    RGN::RGNEnvironmentTarget environmentTarget = RGN::RGNEnvironmentTarget::STAGING;
    bool autoGuestLogin = true;
    bool useFunctionsEmulator = false;
    godot::String emulatorHost = "127.0.0.1";
    godot::String emulatorPort = "5001";
public:
	REG_GCLASS_METHODS_HEADER() {
        BIND_GCLASS_METHOD(G_RGNConfigurationData::getAppId, GCLASS_METHOD_SIGNATURE("getAppId"));
        BIND_GCLASS_METHOD(G_RGNConfigurationData::setAppId, GCLASS_METHOD_SIGNATURE("setAppId", "appId"));
        BIND_GCLASS_METHOD(G_RGNConfigurationData::getApiKey, GCLASS_METHOD_SIGNATURE("getApiKey"));
        BIND_GCLASS_METHOD(G_RGNConfigurationData::setApiKey, GCLASS_METHOD_SIGNATURE("setApiKey", "apiKey"));
        BIND_GCLASS_METHOD(G_RGNConfigurationData::getEnvironmentTarget, GCLASS_METHOD_SIGNATURE("getEnvironmentTarget"));
        BIND_GCLASS_METHOD(G_RGNConfigurationData::setDevelopmentEnvironment, GCLASS_METHOD_SIGNATURE("setDevelopmentEnvironment"));
        BIND_GCLASS_METHOD(G_RGNConfigurationData::setStagingEnvironment, GCLASS_METHOD_SIGNATURE("setStagingEnvironment"));
        BIND_GCLASS_METHOD(G_RGNConfigurationData::setProductionEnvironment, GCLASS_METHOD_SIGNATURE("setProductionEnvironment"));
        BIND_GCLASS_METHOD(G_RGNConfigurationData::getAutoGuestLogin, GCLASS_METHOD_SIGNATURE("getAutoGuestLogin"));
        BIND_GCLASS_METHOD(G_RGNConfigurationData::setAutoGuestLogin, GCLASS_METHOD_SIGNATURE("setAutoGuestLogin", "autoGuestLogin"));
        BIND_GCLASS_METHOD(G_RGNConfigurationData::getUseFunctionsEmulator, GCLASS_METHOD_SIGNATURE("getUseFunctionsEmulator"));
        BIND_GCLASS_METHOD(G_RGNConfigurationData::setUseFunctionsEmulator, GCLASS_METHOD_SIGNATURE("setUseFunctionsEmulator", "useFunctionsEmulator"));
        BIND_GCLASS_METHOD(G_RGNConfigurationData::getEmulatorHost, GCLASS_METHOD_SIGNATURE("getEmulatorHost"));
        BIND_GCLASS_METHOD(G_RGNConfigurationData::setEmulatorHost, GCLASS_METHOD_SIGNATURE("setEmulatorHost", "host"));
        BIND_GCLASS_METHOD(G_RGNConfigurationData::getEmulatorPort, GCLASS_METHOD_SIGNATURE("getEmulatorPort"));
        BIND_GCLASS_METHOD(G_RGNConfigurationData::setEmulatorPort, GCLASS_METHOD_SIGNATURE("setEmulatorPort", "port"));
	}

#ifdef GODOT3
	void _init() {}
#endif

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
    int32_t getEnvironmentTarget() {
        return static_cast<int32_t>(environmentTarget);
    }
    G_RGNConfigurationData* setDevelopmentEnvironment() {
        this->environmentTarget = RGN::RGNEnvironmentTarget::DEVELOPMENT;
        return this;
    }
    G_RGNConfigurationData* setStagingEnvironment() {
        this->environmentTarget = RGN::RGNEnvironmentTarget::STAGING;
        return this;
    }
    G_RGNConfigurationData* setProductionEnvironment() {
        this->environmentTarget = RGN::RGNEnvironmentTarget::PRODUCTION;
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