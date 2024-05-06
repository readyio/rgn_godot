#pragma once

#include <string>

namespace RGN {
    enum class RGNEnvironmentTarget : uint8_t {
        NONE = 0,
        DEVELOPMENT = 1,
        STAGING = 2,
        PRODUCTION = 3
    };

    std::string GetEnvironmentTargetName(RGNEnvironmentTarget target);
}