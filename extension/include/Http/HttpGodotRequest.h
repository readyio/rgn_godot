#pragma once

#include "HttpMethod.h"
#include "HttpHeaders.h"
#include "HttpResponse.h"
#include <string>
#include <functional>
#include <godot_cpp/classes/http_client.hpp>

class HttpGodotRequest {
private:
    std::string url;
    HttpMethod method;
    HttpHeaders headers;
    std::string body;
    std::function<void(HttpResponse)> callback;
    godot::Ref<godot::TLSOptions> httpTLS;
    godot::HTTPClient* httpClient;
    static godot::HTTPClient::Method GetGodotRequestMethod(HttpMethod method);
public:
    HttpGodotRequest();
    HttpGodotRequest(const HttpGodotRequest& request);
    HttpGodotRequest& operator=(const HttpGodotRequest& other);
    HttpGodotRequest(HttpGodotRequest&& other) noexcept;
    HttpGodotRequest& operator=(HttpGodotRequest&& other) noexcept;
    ~HttpGodotRequest();
    void setUrl(std::string url);
    void setMethod(HttpMethod method);
    void setHeaders(HttpHeaders headers);
    void addHeader(std::string key, std::string value);
    void setBody(std::string body);
    void setCallback(const std::function<void(HttpResponse)>& callback);
    bool processRequest();
    bool poll();
};