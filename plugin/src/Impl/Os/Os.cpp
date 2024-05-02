#include "Os/Os.h"
#ifdef GODOT3
#include <OS.hpp>
#else
#include <godot_cpp/classes/os.hpp>
#endif

namespace RGN {
    void Os::OpenURL(std::string url) {
#ifdef GODOT3
        godot::OS::get_singleton()->shell_open(godot::String(url.c_str()));
#else
        godot::OS* os = memnew(godot::OS);
        os->shell_open(godot::String(url.c_str()));
        memdelete(os);
#endif
    }
}