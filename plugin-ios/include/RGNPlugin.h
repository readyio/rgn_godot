#pragma once

#import "RGNWebView.h"
#include "core/version.h"
#if VERSION_MAJOR == 4
#include "core/object/class_db.h"
#else
#include "core/object.h"
#endif

class RGNPlugin : public Object {
	GDCLASS(RGNPlugin, Object);
private:
	static RGNPlugin *singleton;
	static void _bind_methods();
	RGNWebView* webView;
public:
	static RGNPlugin *get_singleton();
    void setWebviewInstanceId(int64_t instanceId);
    void setWebviewUrlScheme(String urlScheme);
    void setWebviewBackButtonText(String backButtonText);
    void openWebviewUrl(String url);
    String getAppIdentifier();
    String getAppInstallerName();
	RGNPlugin();
	~RGNPlugin();
};

void rgn_plugin_init();
void rgn_plugin_deinit();