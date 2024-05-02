#include "SharedPrefs/SharedPrefs.h"
#include "Utility/Logger.h"
#ifdef GODOT3
#include <Godot.hpp>
#include <GodotGlobal.hpp>
#include <File.hpp>
#include <String.hpp>
#include <Ref.hpp>
#else
#include <godot_cpp/classes/file_access.hpp>
#include <godot_cpp/variant/string.hpp>
#endif

namespace RGN {
    bool SharedPrefs::Load(std::string name, std::string& target) {
        bool loadSuccess = false;
        std::string path = "user://" + name;
        godot::String gpath = godot::String(path.c_str());
#ifdef GODOT3
        godot::Ref<godot::File> file = godot::File::_new();
        if (file->open(gpath, godot::File::READ) == godot::Error::OK) {
            godot::String contents = file->get_as_text(); 
            char* c_string = contents.alloc_c_string();
            target = std::string(c_string);
            godot::api->godot_free(c_string);
            file->close();
            loadSuccess = true;
        }
#else
        if (godot::FileAccess::file_exists(gpath)) {
            godot::Ref<godot::FileAccess> file = godot::FileAccess::open(gpath, godot::FileAccess::ModeFlags::READ);
            target = std::string((*file)->get_as_text().utf8().get_data());
            (*file)->close();
            loadSuccess = true;
        }
#endif
        return loadSuccess;
    }

    void SharedPrefs::Save(std::string name, std::string content) {
        std::string path = "user://" + name;
        godot::String gpath = godot::String(path.c_str());
#ifdef GODOT3
        godot::Ref<godot::File> file = godot::File::_new();
        if (file->open(gpath, godot::File::WRITE) == godot::Error::OK) {
            file->store_string(godot::String(content.c_str()));
            file->close();
        }
#else
        godot::Ref<godot::FileAccess> file = godot::FileAccess::open(gpath, godot::FileAccess::ModeFlags::WRITE);
        (*file)->store_string(godot::String(content.c_str()));
        (*file)->close();
#endif
    }
}