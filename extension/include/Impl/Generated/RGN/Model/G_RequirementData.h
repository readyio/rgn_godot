#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../Generated/RGN/Model/RequirementData.h"
#include "../../../../Generated/RGN/Model/Requirement.h"
#include "G_Requirement.h"
#include "Impl/G_Defs.h"
#include <string>
#include <vector>
#include <unordered_map>

/**
 * A class that represents a leaderboard join or store offer purchase requirements on Ready Games Network.
 */
struct G_RequirementData {
	static void ConvertToGodotModel(const RGN::Model::RequirementData& source, godot::Dictionary& target) {
        target["operation"] = godot::String(source.operation.c_str());
        godot::Array g_target_requirements;
        for (const auto& source_requirements_item : source.requirements) {
            godot::Dictionary g_source_requirements_item;
            godot::Dictionary g_g_source_requirements_item = g_source_requirements_item;
            G_Requirement::ConvertToGodotModel(source_requirements_item, g_g_source_requirements_item);
            g_target_requirements.push_back(g_source_requirements_item);
        }
        target["requirements"] = g_target_requirements;
	}

	static void ConvertToCoreModel(const godot::Dictionary& source, RGN::Model::RequirementData& target) {
        godot::String g_source_operation = source["operation"];
        target.operation = std::string(g_source_operation.utf8().get_data());
        godot::Array g_target_requirements = source["requirements"];
        for (int i = 0; i < g_target_requirements.size(); ++i) {
            godot::Dictionary g_target_requirements_item = g_target_requirements[i];
            RGN::Model::Requirement cpp_source_requirements_item;
            G_Requirement::ConvertToCoreModel(g_target_requirements_item, cpp_source_requirements_item);
            target.requirements.push_back(cpp_source_requirements_item);
        }
	}
};
