#include "register_types.h"

#include "Impl/Core/G_RGNCore.h"
#include "Impl/Core/G_RGNEnvironmentTarget.h"
#include "Impl/Core/G_Timer.h"
#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/classes/engine.hpp>

static G_RGNCore* _g_rgnCore;
static G_RGNEnvironmentTarget* _g_rgnEnvironmentTarget;

void initialize_module(godot::ModuleInitializationLevel p_level) {
	if (p_level != godot::MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	godot::ClassDB::register_class<G_RGNCore>();
	godot::ClassDB::register_class<G_RGNEnvironmentTarget>();
	godot::ClassDB::register_class<G_Timer>();
	_g_rgnCore = memnew(G_RGNCore);
	_g_rgnEnvironmentTarget = memnew(G_RGNEnvironmentTarget);
	godot::Engine::get_singleton()->register_singleton("RGNCore", G_RGNCore::get_singleton());
	godot::Engine::get_singleton()->register_singleton("RGNEnvironmentTarget", G_RGNEnvironmentTarget::get_singleton());
}

void uninitialize_module(godot::ModuleInitializationLevel p_level) {
	if (p_level != godot::MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	godot::Engine::get_singleton()->unregister_singleton("RGNCore");
	godot::Engine::get_singleton()->unregister_singleton("RGNEnvironmentTarget");
	memdelete(_g_rgnCore);
	memdelete(_g_rgnEnvironmentTarget);
}

extern "C" {
	GDExtensionBool GDE_EXPORT rgn_library_init(
		GDExtensionInterfaceGetProcAddress p_get_proc_address,
		const GDExtensionClassLibraryPtr p_library,
		GDExtensionInitialization *r_initialization
	) {
		godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

		init_obj.register_initializer(initialize_module);
		init_obj.register_terminator(uninitialize_module);
		init_obj.set_minimum_library_initialization_level(godot::MODULE_INITIALIZATION_LEVEL_SCENE);

		return init_obj.init();
	}
}