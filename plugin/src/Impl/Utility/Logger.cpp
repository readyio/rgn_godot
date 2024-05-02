#include "Utility/Logger.h"
#ifdef GODOT3
#include <GodotGlobal.hpp>
#else
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#endif

namespace RGN { namespace Utility {
    void Logger::Debug(std::string message) {
#ifdef GODOT3
        godot::Godot::print(godot::String(message.c_str()));
#else
        godot::UtilityFunctions::print(godot::String(message.c_str()));
#endif
    }
}}