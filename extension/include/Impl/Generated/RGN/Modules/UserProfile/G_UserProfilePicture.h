#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/UserProfile/UserProfilePicture.h"
#include "../../../../../Generated/RGN/Model/ImageUrl.h"
#include "../../Model/G_ImageUrl.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <string>
#include <vector>
#include <unordered_map>

struct G_UserProfilePicture {
	static void ConvertToGodotModel(const RGN::Modules::UserProfile::UserProfilePicture& source, godot::Dictionary& target) {
		G_ImageUrl::ConvertToGodotModel(source, target);
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::UserProfile::UserProfilePicture& target) {
		G_ImageUrl::ConvertToCoreModel(source, target);
	}
};
