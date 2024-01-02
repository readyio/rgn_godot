#include "G_RGNCore.h"
#include "Http.h"
#include "DeepLink.h"
#include "Os.h"
#include "SharedPrefs.h"
#include <string>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

G_RGNCore *G_RGNCore::singleton = nullptr;

void G_RGNCore::_bind_methods()
{
	godot::ClassDB::bind_method(godot::D_METHOD("test_read"), &G_RGNCore::test_read);
	godot::ClassDB::bind_method(godot::D_METHOD("test_write"), &G_RGNCore::test_write);
}

G_RGNCore *G_RGNCore::get_singleton()
{
	return singleton;
}

G_RGNCore::G_RGNCore()
{
	ERR_FAIL_COND(singleton != nullptr);
	singleton = this;

	DeepLink::Initialize();
	DeepLink::Start();
	DeepLink::Listen([this](std::string payload) {
		godot::UtilityFunctions::print("DEEPLINK RECEIVED IN RGNCORE! LOLOMG");
	});
}

G_RGNCore::~G_RGNCore()
{
	ERR_FAIL_COND(singleton != this);
	singleton = nullptr;
}

void G_RGNCore::test_read()
{
	std::string out;
	if (SharedPrefs::Load("test", out)) {
		godot::UtilityFunctions::print("Shared prefs file loaded and readed.");
		godot::String gout = godot::String(out.c_str());
		godot::UtilityFunctions::print(gout);
	} else {
		godot::UtilityFunctions::print("Shared prefs file can't be loaded.");
	}
}

void G_RGNCore::test_write()
{
	SharedPrefs::Save("test", "Hello from Arthur");
	godot::UtilityFunctions::print("Shared prefs file saved.");
}

// Os::OpenURL("https://google.com");
// HttpHeaders headers;
// headers.add("Content-type", "application/json");
// Http::Request("https://random-d.uk/api/v2/random", HttpMethod::GET, headers, "", [](HttpResponse httpResponse) {
// 	godot::String responseBody = godot::String(httpResponse.getResponseBody().c_str());
// 	godot::UtilityFunctions::print(responseBody);
// });
// Http::Request("https://random-d.uk/api/v2/random", HttpMethod::GET, headers, "", [](HttpResponse httpResponse) {
// 	godot::String responseBody = godot::String(httpResponse.getResponseBody().c_str());
// 	godot::UtilityFunctions::print(responseBody);
// });