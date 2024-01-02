#include "SharedPrefs.h"
#include <godot_cpp/classes/file_access.hpp>
#include <godot_cpp/variant/string.hpp>

bool SharedPrefs::Load(std::string name, std::string& target) {
    std::string path = "user://" + name;
    godot::String gpath = godot::String(path.c_str());
    if (godot::FileAccess::file_exists(gpath)) {
        godot::Ref<godot::FileAccess> file = godot::FileAccess::open(gpath, godot::FileAccess::ModeFlags::READ);
        target = std::string((*file)->get_as_text().utf8().get_data());
        (*file)->close();
        return true;
    }
    return false;
}

void SharedPrefs::Save(std::string name, std::string content) {
    std::string path = "user://" + name;
    godot::String gpath = godot::String(path.c_str());
    godot::Ref<godot::FileAccess> file = godot::FileAccess::open(gpath, godot::FileAccess::ModeFlags::WRITE);
    (*file)->store_string(godot::String(content.c_str()));
    (*file)->close();
}