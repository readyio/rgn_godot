#import "readygg_plugin.h"
#import "readygg_webview.h"

#if VERSION_MAJOR == 4
#import "core/config/engine.h"
#else
#import "core/engine.h"
#endif

READYggWebviewPlugin *plugin;

void godot_plugin_init() {
    plugin = memnew(READYggWebviewPlugin);
	Engine::get_singleton()->add_singleton(Engine::Singleton("READYggWebview", plugin));
}

void godot_plugin_deinit() {
    if (plugin) {
		memdelete(plugin);
	}
}
