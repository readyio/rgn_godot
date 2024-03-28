#include "Http/Http.h"
#include "Godot/Http/HttpRequestGodot.h"
#include <vector>
#include <algorithm>

namespace RGN {
    std::vector<HttpRequestGodot> requests;

    void Http::Request(std::string url, HttpMethod method, HttpHeaders& headers, std::string body,
        const std::function<void(HttpResponse)>& callback) {
        HttpRequestGodot request;
        request.setUrl(url);
        request.setMethod(method);
        request.setHeaders(headers);
        request.setBody(body);
        request.setCallback(callback);
        if (request.processRequest()) {
            requests.push_back(std::move(request));
        }
    }

    void Http::Update() {
        for (decltype(requests)::iterator it = requests.begin(); it != requests.end();) {
            if ((*it).update()) {
                ++it;
            } else {
                it = requests.erase(it);
            }
        }
    }
}