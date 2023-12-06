#include "register_types.h"

#include "G_RGNCore.h"
#include "G_RGNUpdater.h"

#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/classes/engine.hpp>

using namespace godot;

static G_RGNCore* _g_rgnCore;
static G_RGNUpdater* _g_rgnUpdater;

void initialize_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	ClassDB::register_class<G_RGNCore>();
	ClassDB::register_class<G_RGNUpdater>();

	_g_rgnCore = memnew(G_RGNCore);
	_g_rgnUpdater = memnew(G_RGNUpdater);

	Engine::get_singleton()->register_singleton("G_RGNCore", G_RGNCore::get_singleton());
	Engine::get_singleton()->register_singleton("G_RGNUpdater", G_RGNUpdater::get_singleton());
}

void uninitialize_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	Engine::get_singleton()->unregister_singleton("G_RGNCore");
	Engine::get_singleton()->unregister_singleton("G_RGNUpdater");

	memdelete(_g_rgnCore);
	memdelete(_g_rgnUpdater);
}

extern "C" {
	// Initialization.
	GDExtensionBool GDE_EXPORT rgn_library_init(
		GDExtensionInterfaceGetProcAddress p_get_proc_address,
		const GDExtensionClassLibraryPtr p_library,
		GDExtensionInitialization *r_initialization
	) {
		GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

		init_obj.register_initializer(initialize_module);
		init_obj.register_terminator(uninitialize_module);
		init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

		return init_obj.init();
	}
}