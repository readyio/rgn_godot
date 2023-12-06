#include "Os.h"
#include <godot_cpp/classes/os.hpp>

void Os::OpenURL(std::string url) {
    godot::OS* os = memnew(godot::OS);
    os->shell_open(godot::String(url.c_str()));
    memdelete(os);
}