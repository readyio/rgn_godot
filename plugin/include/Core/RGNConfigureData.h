#pragma once

#include "RGNEnvironmentTarget.h"
#include <string>

namespace RGN {
    struct RGNConfigureData {
        std::string appId;
        std::string apiKey;
        RGNEnvironmentTarget environmentTarget;
        bool useFunctionsEmulator;
        std::string emulatorHost;
        std::string emulatorPort;
    };
}