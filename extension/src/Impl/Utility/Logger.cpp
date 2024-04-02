#include "Utility/Logger.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

namespace RGN { namespace Utility {
    void Logger::Debug(std::string message) {
        godot::UtilityFunctions::print(godot::String(message.c_str()));
    }
}}