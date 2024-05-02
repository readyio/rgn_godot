#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/VirtualItems/VirtualItemImage.h"
#include "../../../../../Generated/RGN/Model/ImageUrl.h"
#include "../../Model/G_ImageUrl.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

struct G_VirtualItemImage {
	static void ConvertToGodotModel(const RGN::Modules::VirtualItems::VirtualItemImage& source, godot::Dictionary& target) {
		G_ImageUrl::ConvertToGodotModel(source, target);
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Modules::VirtualItems::VirtualItemImage& target) {
		G_ImageUrl::ConvertToCoreModel(source, target);
	}
};
