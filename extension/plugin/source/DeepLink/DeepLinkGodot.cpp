#include "DeepLink.h"

std::vector<std::function<void(std::string)>> DeepLink::_callbacks;
bool isListening = false;

void DeepLink::Initialize() {
}

void DeepLink::Start() {
    isListening = true;
}

void DeepLink::Stop() {
    isListening = false;
}

void DeepLink::Listen(std::function<void(std::string)> callback) {
    _callbacks.push_back(callback);
}

void DeepLink::OnDeepLink(std::string payload) {
    if (!isListening) {
        return;
    }
    for (auto callback : _callbacks) {
        callback(payload);
    }
    _callbacks.clear();
}