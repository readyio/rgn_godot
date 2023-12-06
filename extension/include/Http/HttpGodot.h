#include "HttpMethod.h"
#include "HttpGodotRequest.h"
#include <godot_cpp/classes/http_client.hpp>
#include <string>
#include <vector>

#pragma once

class HttpGodot {
private:
    static std::vector<HttpGodotRequest> requests;
    static godot::HTTPClient::Method GetGodotRequestMethod(HttpMethod method);
public:
    static void Request(std::string url, HttpMethod method, HttpHeaders& headers, std::string body,
        const std::function<void(HttpResponse)>& callback);
    static void Poll();
};