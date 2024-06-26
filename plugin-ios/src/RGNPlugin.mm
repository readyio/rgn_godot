#include "RGNPlugin.h"
#include "RGNAppInfo.h"
#include "core/version.h"
#if VERSION_MAJOR == 4
#include "core/config/engine.h"
#else
#include "core/engine.h"
#endif

RGNPlugin *RGNPlugin::singleton = nullptr;

RGNPlugin *RGNPlugin::get_singleton() {
	return singleton;
}

void RGNPlugin::_bind_methods() {
	ClassDB::bind_method(D_METHOD("setWebviewInstanceId", "instanceId"), &RGNPlugin::setWebviewInstanceId);
	ClassDB::bind_method(D_METHOD("setWebviewUrlScheme", "urlScheme"), &RGNPlugin::setWebviewUrlScheme);
	ClassDB::bind_method(D_METHOD("setWebviewBackButtonText", "backButtonText"), &RGNPlugin::setWebviewBackButtonText);
	ClassDB::bind_method(D_METHOD("openWebviewUrl", "url"), &RGNPlugin::openWebviewUrl);
	ClassDB::bind_method(D_METHOD("getAppIdentifier"), &RGNPlugin::getAppIdentifier);
	ClassDB::bind_method(D_METHOD("getAppInstallerName"), &RGNPlugin::getAppInstallerName);
}

void RGNPlugin::setWebviewInstanceId(int64_t instanceId) {
    if (webView) {
        webView.instanceId = instanceId;
    }
}

void RGNPlugin::setWebviewUrlScheme(String urlScheme) {
	if (webView) {
        NSString *nsUrlScheme = [NSString stringWithCString:urlScheme.utf8().get_data() encoding:[NSString defaultCStringEncoding]];
        webView.urlScheme = nsUrlScheme;
    }
}

void RGNPlugin::setWebviewBackButtonText(String backButtonText) {
    if (webView) {
        NSString *nsBackButtonText = [NSString stringWithCString:backButtonText.utf8().get_data() encoding:[NSString defaultCStringEncoding]];
        webView.backButtonText = nsBackButtonText;
    }
}

void RGNPlugin::openWebviewUrl(String url) {
	if (webView) {
		[webView openURL:[NSString stringWithCString:url.utf8().get_data() encoding:[NSString defaultCStringEncoding]]];
    }
}

String RGNPlugin::getAppIdentifier() {
	return String(getApplicationIdentifier());
}

String RGNPlugin::getAppInstallerName() {
	return String(getApplicationInstallerName());
}

RGNPlugin::RGNPlugin() {
	singleton = this;
	webView = [[RGNWebView alloc] init];
}

RGNPlugin::~RGNPlugin() {
	singleton = nullptr;
}

RGNPlugin* plugin = nullptr;

void rgn_plugin_init() {
    plugin = memnew(RGNPlugin);
	Engine::get_singleton()->add_singleton(Engine::Singleton("RGNPluginMobile", plugin));
}

void rgn_plugin_deinit() {
    if (plugin) {
		memdelete(plugin);
	}
}