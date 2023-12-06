#include "DeepLink.h"
#if ANDROID_ENABLED
#include "DeepLinkGodot.h"
#endif
#include <queue>

std::vector<std::function<void(std::string)>> DeepLink::_callbacks;
std::queue<std::string> _buffer;
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
    while (!_buffer.empty()) {
        std::string payload = _buffer.front();
        _buffer.pop();
        OnDeepLink(payload);
    }
}

void DeepLink::OnDeepLink(std::string payload) {
    if (!isListening) {
        _buffer.push(payload);
        return;
    }
    for (auto callback : _callbacks) {
        callback(payload);
    }
    _callbacks.clear();
}

#if ANDROID_ENABLED
void JNICALL Java_io_getready_rgn_iac_RGNPlugin_onInvocation(JNIEnv* env, jobject instance, jstring Payload) {
    const char* payloadChars = env->GetStringUTFChars(Payload, nullptr);
    std::string payloadString = std::string(payloadChars);
    DeepLink::OnDeepLink(payloadString);
}
#endif