#include "Http.h"
#include "HttpGodot.h"
#include "HttpGodotRequest.h"
#include <godot_cpp/classes/http_client.hpp>
#include <godot_cpp/classes/tls_options.hpp>
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/packed_byte_array.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <string>
#include <functional>
#include <algorithm>

void Http::Request(std::string url, HttpMethod method, HttpHeaders& headers, std::string body,
	const std::function<void(HttpResponse)>& callback) {
    HttpGodot::Request(url, method, headers, body, callback);
}

std::vector<HttpGodotRequest> HttpGodot::requests;

void HttpGodot::Request(std::string url, HttpMethod method, HttpHeaders& headers, std::string body,
	const std::function<void(HttpResponse)>& callback) {
    HttpGodotRequest request;
    request.setUrl(url);
    request.setMethod(method);
    request.setHeaders(headers);
    request.setBody(body);
    request.setCallback(callback);
    if (request.processRequest()) {
        requests.push_back(std::move(request));
    }
}

void HttpGodot::Poll() {
    for (decltype(requests)::iterator it = requests.begin(); it != requests.end();) {
        if ((*it).poll()) {
            ++it;
        } else {
            it = requests.erase(it);
        }
    }
}