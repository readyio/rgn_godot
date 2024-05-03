#pragma once

#include "core/version.h"
#if VERSION_MAJOR == 4
#include "core/object/class_db.h"
#else
#include "core/object.h"
#endif

class READYggWebviewPlugin : public Object {
	GDCLASS(READYggWebviewPlugin, Object);

	static void _bind_methods();

public:
	static READYggWebviewPlugin *get_singleton();

    void setInstanceId(int64_t instanceId);
    void setUrlScheme(String urlScheme);
    void setBackButtonText(String backButtonText);
    void openUrl(String url);

	READYggWebviewPlugin();
	~READYggWebviewPlugin();
};