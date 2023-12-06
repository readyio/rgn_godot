#include "Godot/G_RGNCore.h"
#include "Http/Http.h"
#include "DeepLink/DeepLink.h"
#include <string>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

G_RGNCore *G_RGNCore::singleton = nullptr;

void G_RGNCore::_bind_methods()
{
	godot::ClassDB::bind_method(godot::D_METHOD("test"), &G_RGNCore::test);
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

void G_RGNCore::test()
{
	HttpHeaders headers;
    headers.add("Content-type", "application/json");
	Http::Request("https://random-d.uk/api/v2/random", HttpMethod::GET, headers, "", [](HttpResponse httpResponse) {
		godot::String responseBody = godot::String(httpResponse.getResponseBody().c_str());
		godot::UtilityFunctions::print(responseBody);
	});
	Http::Request("https://random-d.uk/api/v2/random", HttpMethod::GET, headers, "", [](HttpResponse httpResponse) {
		godot::String responseBody = godot::String(httpResponse.getResponseBody().c_str());
		godot::UtilityFunctions::print(responseBody);
	});
}