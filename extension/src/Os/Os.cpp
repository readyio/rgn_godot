#include "Os/Os.h"
#include <godot_cpp/classes/os.hpp>

namespace RGN {
    void Os::OpenURL(std::string url) {
        godot::OS* os = memnew(godot::OS);
        os->shell_open(godot::String(url.c_str()));
        memdelete(os);
    }
}