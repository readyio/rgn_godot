#include "Http/Http.h"
#include "Impl/Http/HttpRequestImpl.h"
#include <vector>
#include <algorithm>
#include <map>

namespace RGN {
    std::vector<HttpRequestImpl> requests;
    std::vector<HttpRequestImpl> pendingRequests;
    std::map<int32_t, HttpListener*> listeners;

    void Http::Request(std::string url, HttpMethod method, HttpHeaders& headers, std::string body,
        const std::function<void(HttpResponse)>& callback) {
        HttpRequestImpl request;
        request.setUrl(url);
        request.setMethod(method);
        request.setHeaders(headers);
        request.setBody(body);
        request.setCallback(callback);
        if (request.processRequest()) {
            pendingRequests.push_back(std::move(request));
        }
    }

    bool Http::WaitForInRequest(int32_t port, const std::function<void(std::string)>& callback, int32_t& boundedToPort) {
        if (port != 0) {
            auto it = listeners.find(port);
            if (it != listeners.end()) {
                return false;
            }
        }
		HttpListener* listener = new HttpListener();
		int32_t listenerPort;
		bool listenerStartedSuccessfully = listener->startListen(port, callback, listenerPort);
		boundedToPort = listenerPort;
		if (!listenerStartedSuccessfully) {
			delete listener;
			return false;
		}
		listeners[boundedToPort] = listener;
		return true;
	}

	void Http::CancelWaitForInRequest(int32_t boundedToPort) {
		auto it = listeners.find(boundedToPort);
		if (it == listeners.end()) {
			return;
		}
		HttpListener* listener = it->second;
		listener->stopListen();
	}

    void Http::Update() {
        requests.insert(requests.end(), std::make_move_iterator(pendingRequests.begin()), std::make_move_iterator(pendingRequests.end()));
        pendingRequests.clear();
        for (auto it = requests.begin(); it != requests.end();) {
            bool keepRequest = it->update();
            if (keepRequest) {
                ++it;
            } else {
                it = requests.erase(it);
            }
        }
        for (auto it = listeners.begin(); it != listeners.end();) {
			HttpListener* listener = it->second;
			if (!listener || !listener->isListening()) {
				it = listeners.erase(it);
				if (listener) {
					delete listener;
				}
				continue;
			}
			listener->poll();
			++it;
		}
    }
}