#include "register_types.h"
// Core deps
#include "Impl/Core/G_RGNCore.h"
#include "Impl/Core/G_RGNEnvironmentTarget.h"
#include "Impl/Core/G_Timer.h"
// Module deps
#include "Impl/Generated/RGN/Modules/Currency/G_CurrencyModule.h"
// Godot deps
#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/classes/engine.hpp>

// Core singletons
static G_RGNCore* _g_rgnCore;
static G_RGNEnvironmentTarget* _g_rgnEnvironmentTarget;
// Module singletons
static G_CurrencyModule * _g_currencyModule;

void register_core() {
	// Register core classes
	godot::ClassDB::register_class<G_RGNCore>();
	godot::ClassDB::register_class<G_RGNEnvironmentTarget>();
	godot::ClassDB::register_class<G_Timer>();
	// Instantiate core singletones
	_g_rgnCore = memnew(G_RGNCore);
	_g_rgnEnvironmentTarget = memnew(G_RGNEnvironmentTarget);
	// Register core singletons
	godot::Engine::get_singleton()->register_singleton("RGNCore", G_RGNCore::get_singleton());
	godot::Engine::get_singleton()->register_singleton("RGNEnvironmentTarget", G_RGNEnvironmentTarget::get_singleton());
}

void unregister_core() {
	// Unregister singletons
	godot::Engine::get_singleton()->unregister_singleton("RGNCore");
	godot::Engine::get_singleton()->unregister_singleton("RGNEnvironmentTarget");
	// Free singletone instances
	memdelete(_g_rgnCore);
	memdelete(_g_rgnEnvironmentTarget);
}

void register_modules() {
	// Register module classes
	godot::ClassDB::register_class<G_CurrencyModule>();
	// Instantiate module singletons
	_g_currencyModule = memnew(G_CurrencyModule);
    // Register module singletons
    godot::Engine::get_singleton()->register_singleton("CurrencyModule", G_CurrencyModule::get_singleton());
}

void unregister_modules() {
	// Unregister module singletons
	godot::Engine::get_singleton()->unregister_singleton("CurrencyModule");
    // Free module singleton instances
    memdelete(_g_currencyModule);
}

void initialize_module(godot::ModuleInitializationLevel p_level) {
	if (p_level != godot::MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
	register_core();
	register_modules();
}

void uninitialize_module(godot::ModuleInitializationLevel p_level) {
	if (p_level != godot::MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
	unregister_modules();
	unregister_core();
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