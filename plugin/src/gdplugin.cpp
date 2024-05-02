// Core deps
#include "Impl/Core/G_RGNCore.h"
#include "Impl/Core/G_RGNConfigurationData.h"
#include "Impl/Core/G_Timer.h"
#include "Impl/Utility/G_CancellationToken.h"
#include "Impl/Utility/G_CancellationTokenSource.h"
// Module deps
#include "Impl/Generated/RGN/Modules/Achievement/G_AchievementsModule.h"
#include "Impl/Generated/RGN/Modules/Achievement/G_AchievementsModule_Admin.h"
#include "Impl/Generated/RGN/Modules/Analytics/G_AnalyticsModule.h"
#include "Impl/Generated/RGN/Modules/Creator/G_CreatorModule.h"
#include "Impl/Generated/RGN/Modules/Currency/G_CurrencyModule.h"
#include "Impl/Generated/RGN/Modules/GamePass/G_GamePassModule.h"
#include "Impl/Generated/RGN/Modules/GamePass/G_GamePassModule_Admin.h"
#include "Impl/Generated/RGN/Modules/GameProgress/G_GameProgressModule.h"
#include "Impl/Generated/RGN/Modules/Inventory/G_InventoryModule.h"
#include "Impl/Generated/RGN/Modules/Leaderboard/G_LeaderboardModule.h"
#include "Impl/Generated/RGN/Modules/Leaderboard/G_LeaderboardModule_Admin.h"
#include "Impl/Generated/RGN/Modules/Matchmaking/G_MatchmakingModule.h"
#include "Impl/Generated/RGN/Modules/Matchmaking/G_MatchmakingModule_Admin.h"
#include "Impl/Generated/RGN/Modules/Messaging/G_MessagingModule.h"
#include "Impl/Generated/RGN/Modules/Store/G_StoreModule.h"
#include "Impl/Generated/RGN/Modules/Store/G_StoreModule_Admin.h"
#include "Impl/Generated/RGN/Modules/UserProfile/G_UserProfileModule.h"
#include "Impl/Generated/RGN/Modules/VirtualItems/G_VirtualItemsModule.h"
#include "Impl/Generated/RGN/Modules/VirtualItems/G_VirtualItemsModule_Admin.h"
#include "Impl/Generated/RGN/Modules/Wallets/G_WalletsModule.h"

#ifdef GODOT3
#include <Godot.hpp>

void register_core() {
	godot::register_class<G_RGNCore>();
	godot::register_class<G_RGNConfigurationData>();
	godot::register_class<G_Timer>();
	godot::register_class<G_CancellationToken>();
	godot::register_class<G_CancellationTokenSource>();
}

void register_modules() {
	godot::register_class<G_AchievementsModule>();
	godot::register_class<G_AchievementsModule_Admin>();
	godot::register_class<G_AnalyticsModule>();
	godot::register_class<G_CreatorModule>();
	godot::register_class<G_CurrencyModule>();
	godot::register_class<G_GamePassModule>();
	godot::register_class<G_GamePassModule_Admin>();
	godot::register_class<G_GameProgressModule>();
	godot::register_class<G_InventoryModule>();
	godot::register_class<G_LeaderboardModule>();
	godot::register_class<G_LeaderboardModule_Admin>();
	godot::register_class<G_MatchmakingModule>();
	godot::register_class<G_MatchmakingModule_Admin>();
	godot::register_class<G_MessagingModule>();
	godot::register_class<G_StoreModule>();
	godot::register_class<G_StoreModule_Admin>();
	godot::register_class<G_UserProfileModule>();
	godot::register_class<G_VirtualItemsModule>();
	godot::register_class<G_VirtualItemsModule_Admin>();
	godot::register_class<G_WalletsModule>();
}

extern "C" void GDN_EXPORT rgn_gdnative_init(godot_gdnative_init_options *o) {
	godot::Godot::gdnative_init(o);
}

extern "C" void GDN_EXPORT rgn_gdnative_terminate(godot_gdnative_terminate_options *o) {
	godot::Godot::gdnative_terminate(o);
}

extern "C" void GDN_EXPORT rgn_nativescript_init(void *handle) {
	godot::Godot::nativescript_init(handle);
	register_core();
	register_modules();
}
#else
#include "Impl/Core/G_RGNCore.h"
#include "Impl/Core/G_RGNConfigurationData.h"
#include "Impl/Core/G_Timer.h"
#include "Impl/Utility/G_CancellationToken.h"
#include "Impl/Utility/G_CancellationTokenSource.h"
// Module deps
#include "Impl/Generated/RGN/Modules/Achievement/G_AchievementsModule.h"
#include "Impl/Generated/RGN/Modules/Achievement/G_AchievementsModule_Admin.h"
#include "Impl/Generated/RGN/Modules/Analytics/G_AnalyticsModule.h"
#include "Impl/Generated/RGN/Modules/Creator/G_CreatorModule.h"
#include "Impl/Generated/RGN/Modules/Currency/G_CurrencyModule.h"
#include "Impl/Generated/RGN/Modules/GamePass/G_GamePassModule.h"
#include "Impl/Generated/RGN/Modules/GamePass/G_GamePassModule_Admin.h"
#include "Impl/Generated/RGN/Modules/GameProgress/G_GameProgressModule.h"
#include "Impl/Generated/RGN/Modules/Inventory/G_InventoryModule.h"
#include "Impl/Generated/RGN/Modules/Leaderboard/G_LeaderboardModule.h"
#include "Impl/Generated/RGN/Modules/Leaderboard/G_LeaderboardModule_Admin.h"
#include "Impl/Generated/RGN/Modules/Matchmaking/G_MatchmakingModule.h"
#include "Impl/Generated/RGN/Modules/Matchmaking/G_MatchmakingModule_Admin.h"
#include "Impl/Generated/RGN/Modules/Messaging/G_MessagingModule.h"
#include "Impl/Generated/RGN/Modules/Store/G_StoreModule.h"
#include "Impl/Generated/RGN/Modules/Store/G_StoreModule_Admin.h"
#include "Impl/Generated/RGN/Modules/UserProfile/G_UserProfileModule.h"
#include "Impl/Generated/RGN/Modules/VirtualItems/G_VirtualItemsModule.h"
#include "Impl/Generated/RGN/Modules/VirtualItems/G_VirtualItemsModule_Admin.h"
#include "Impl/Generated/RGN/Modules/Wallets/G_WalletsModule.h"
// Godot deps
#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/classes/engine.hpp>

// Module singletons
static G_AchievementsModule * _g_achievementsModule;
static G_AchievementsModule_Admin * _g_achievementsModuleAdmin;
static G_AnalyticsModule * _g_analyticsModule;
static G_CreatorModule * _g_creatorModule;
static G_CurrencyModule * _g_currencyModule;
static G_GamePassModule * _g_gamePassModule;
static G_GamePassModule_Admin * _g_gamePassModuleAdmin;
static G_GameProgressModule * _g_gameProgressModule;
static G_InventoryModule * _g_inventoryModule;
static G_LeaderboardModule * _g_leaderboardModule;
static G_LeaderboardModule_Admin * _g_leaderboardModule_Admin;
static G_MatchmakingModule * _g_matchmakingModule;
static G_MatchmakingModule_Admin * _g_matchmakingModule_Admin;
static G_MessagingModule * _g_messagingModule;
static G_StoreModule * _g_storeModule;
static G_StoreModule_Admin * _g_storeModule_Admin;
static G_UserProfileModule * _g_userProfileModule;
static G_VirtualItemsModule * _g_virtualItemsModule;
static G_VirtualItemsModule_Admin * _g_virtualItemsModule_Admin;
static G_WalletsModule * _g_walletsModule;

void register_core() {
	// Register core classes
	godot::ClassDB::register_class<G_RGNCore>();
	godot::ClassDB::register_class<G_RGNConfigurationData>();
	godot::ClassDB::register_class<G_CancellationToken>();
	godot::ClassDB::register_class<G_CancellationTokenSource>();
	godot::ClassDB::register_class<G_Timer>();
}

void unregister_core() {
}

void register_modules() {
	// Register module classes
	godot::ClassDB::register_class<G_AchievementsModule>();
	godot::ClassDB::register_class<G_AchievementsModule_Admin>();
	godot::ClassDB::register_class<G_AnalyticsModule>();
	godot::ClassDB::register_class<G_CreatorModule>();
	godot::ClassDB::register_class<G_CurrencyModule>();
	godot::ClassDB::register_class<G_GamePassModule>();
	godot::ClassDB::register_class<G_GamePassModule_Admin>();
	godot::ClassDB::register_class<G_GameProgressModule>();
	godot::ClassDB::register_class<G_InventoryModule>();
	godot::ClassDB::register_class<G_LeaderboardModule>();
	godot::ClassDB::register_class<G_LeaderboardModule_Admin>();
	godot::ClassDB::register_class<G_MatchmakingModule>();
	godot::ClassDB::register_class<G_MatchmakingModule_Admin>();
	godot::ClassDB::register_class<G_MessagingModule>();
	godot::ClassDB::register_class<G_StoreModule>();
	godot::ClassDB::register_class<G_StoreModule_Admin>();
	godot::ClassDB::register_class<G_UserProfileModule>();
	godot::ClassDB::register_class<G_VirtualItemsModule>();
	godot::ClassDB::register_class<G_VirtualItemsModule_Admin>();
	godot::ClassDB::register_class<G_WalletsModule>();
	// Instantiate module singletons
	_g_achievementsModule = memnew(G_AchievementsModule);
	_g_achievementsModuleAdmin = memnew(G_AchievementsModule_Admin);
	_g_analyticsModule = memnew(G_AnalyticsModule);
	_g_creatorModule = memnew(G_CreatorModule);
	_g_currencyModule = memnew(G_CurrencyModule);
	_g_gamePassModule = memnew(G_GamePassModule);
	_g_gamePassModuleAdmin = memnew(G_GamePassModule_Admin);
	_g_gameProgressModule = memnew(G_GameProgressModule);
	_g_inventoryModule = memnew(G_InventoryModule);
	_g_leaderboardModule = memnew(G_LeaderboardModule);
	_g_leaderboardModule_Admin = memnew(G_LeaderboardModule_Admin);
	_g_matchmakingModule = memnew(G_MatchmakingModule);
	_g_matchmakingModule_Admin = memnew(G_MatchmakingModule_Admin);
	_g_messagingModule = memnew(G_MessagingModule);
	_g_storeModule = memnew(G_StoreModule);
	_g_storeModule_Admin = memnew(G_StoreModule_Admin);
	_g_userProfileModule = memnew(G_UserProfileModule);
	_g_virtualItemsModule = memnew(G_VirtualItemsModule);
	_g_virtualItemsModule_Admin = memnew(G_VirtualItemsModule_Admin);
	_g_walletsModule = memnew(G_WalletsModule);
    // Register module singletons
    godot::Engine::get_singleton()->register_singleton("AchievementsModule", G_AchievementsModule::get_singleton());
    godot::Engine::get_singleton()->register_singleton("AchievementsModuleAdmin", G_AchievementsModule_Admin::get_singleton());
    godot::Engine::get_singleton()->register_singleton("AnalyticsModule", G_AnalyticsModule::get_singleton());
    godot::Engine::get_singleton()->register_singleton("CreatorModule", G_CreatorModule::get_singleton());
    godot::Engine::get_singleton()->register_singleton("CurrencyModule", G_CurrencyModule::get_singleton());
    godot::Engine::get_singleton()->register_singleton("GamePassModule", G_GamePassModule::get_singleton());
    godot::Engine::get_singleton()->register_singleton("GamePassModuleAdmin", G_GamePassModule_Admin::get_singleton());
    godot::Engine::get_singleton()->register_singleton("GameProgressModule", G_GameProgressModule::get_singleton());
    godot::Engine::get_singleton()->register_singleton("InventoryModule", G_InventoryModule::get_singleton());
    godot::Engine::get_singleton()->register_singleton("LeaderboardModule", G_LeaderboardModule::get_singleton());
    godot::Engine::get_singleton()->register_singleton("LeaderboardModuleAdmin", G_LeaderboardModule_Admin::get_singleton());
    godot::Engine::get_singleton()->register_singleton("MatchmakingModule", G_MatchmakingModule::get_singleton());
    godot::Engine::get_singleton()->register_singleton("MatchmakingModuleAdmin", G_MatchmakingModule_Admin::get_singleton());
    godot::Engine::get_singleton()->register_singleton("MessagingModule", G_MessagingModule::get_singleton());
    godot::Engine::get_singleton()->register_singleton("StoreModule", G_StoreModule::get_singleton());
    godot::Engine::get_singleton()->register_singleton("StoreModuleAdmin", G_StoreModule_Admin::get_singleton());
    godot::Engine::get_singleton()->register_singleton("UserProfileModule", G_UserProfileModule::get_singleton());
    godot::Engine::get_singleton()->register_singleton("VirtualItemsModule", G_VirtualItemsModule::get_singleton());
    godot::Engine::get_singleton()->register_singleton("VirtualItemsModuleAdmin", G_VirtualItemsModule_Admin::get_singleton());
    godot::Engine::get_singleton()->register_singleton("WalletsModule", G_WalletsModule::get_singleton());
}

void unregister_modules() {
	// Unregister module singletons
	godot::Engine::get_singleton()->unregister_singleton("AchievementsModule");
	godot::Engine::get_singleton()->unregister_singleton("AchievementsModuleAdmin");
	godot::Engine::get_singleton()->unregister_singleton("AnalyticsModule");
	godot::Engine::get_singleton()->unregister_singleton("CreatorModule");
	godot::Engine::get_singleton()->unregister_singleton("CurrencyModule");
	godot::Engine::get_singleton()->unregister_singleton("GamePassModule");
	godot::Engine::get_singleton()->unregister_singleton("GamePassModuleAdmin");
	godot::Engine::get_singleton()->unregister_singleton("GameProgressModule");
	godot::Engine::get_singleton()->unregister_singleton("InventoryModule");
	godot::Engine::get_singleton()->unregister_singleton("LeaderboardModule");
	godot::Engine::get_singleton()->unregister_singleton("LeaderboardModuleAdmin");
	godot::Engine::get_singleton()->unregister_singleton("MatchmakingModule");
	godot::Engine::get_singleton()->unregister_singleton("MatchmakingModuleAdmin");
	godot::Engine::get_singleton()->unregister_singleton("MessagingModule");
	godot::Engine::get_singleton()->unregister_singleton("StoreModule");
	godot::Engine::get_singleton()->unregister_singleton("StoreModuleAdmin");
	godot::Engine::get_singleton()->unregister_singleton("UserProfileModule");
	godot::Engine::get_singleton()->unregister_singleton("VirtualItemsModule");
	godot::Engine::get_singleton()->unregister_singleton("VirtualItemsModuleAdmin");
	godot::Engine::get_singleton()->unregister_singleton("WalletsModule");
    // Free module singleton instances
    memdelete(_g_achievementsModule);
    memdelete(_g_achievementsModuleAdmin);
    memdelete(_g_analyticsModule);
    memdelete(_g_creatorModule);
    memdelete(_g_currencyModule);
    memdelete(_g_gamePassModule);
    memdelete(_g_gamePassModuleAdmin);
    memdelete(_g_gameProgressModule);
    memdelete(_g_inventoryModule);
    memdelete(_g_leaderboardModule);
    memdelete(_g_leaderboardModule_Admin);
    memdelete(_g_matchmakingModule);
    memdelete(_g_matchmakingModule_Admin);
    memdelete(_g_messagingModule);
    memdelete(_g_storeModule);
    memdelete(_g_storeModule_Admin);
    memdelete(_g_userProfileModule);
    memdelete(_g_virtualItemsModule);
    memdelete(_g_virtualItemsModule_Admin);
    memdelete(_g_walletsModule);
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
#endif