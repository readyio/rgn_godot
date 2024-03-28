#include "DeepLink/DeepLink.h"
#if ANDROID_ENABLED
#include "Godot/DeepLink/DeepLinkGodot.h"
#endif
#include <queue>

namespace RGN {
    struct DeepLinkBufferItem {
        bool canceled;
        std::string url;
    };

    Utility::FunctionEvent<void(bool, std::string)>DeepLink::_deepLinkOpenEvent;
    std::queue<DeepLinkBufferItem> _buffer;
    bool isListening = false;

    void DeepLink::Initialize() {
    }

    void DeepLink::Start() {
        isListening = true;
    }

    void DeepLink::Stop() {
        isListening = false;
    }

    void DeepLink::Listen(std::function<void(bool, std::string)> callback) {
        _deepLinkOpenEvent.bind(callback);
        while (!_buffer.empty()) {
            DeepLinkBufferItem bufferItem = _buffer.front();
            _buffer.pop();
            OnDeepLink(bufferItem.canceled, bufferItem.url);
        }
    }

    void DeepLink::OnDeepLink(bool canceled, std::string url) {
        if (!isListening) {
            _buffer.push(DeepLinkBufferItem{canceled = canceled, url = url});
            return;
        }
        _deepLinkOpenEvent.raise_and_unbind(canceled, url);
    }
}

#if ANDROID_ENABLED
void JNICALL Java_io_getready_rgn_iac_RGNPlugin_onInvocation(JNIEnv* env, jobject instance, jstring Url) {
    const char* urlChars = env->GetStringUTFChars(Url, nullptr);
    std::string urlString = std::string(urlChars);
    RGN::DeepLink::OnDeepLink(false, urlString);
}
#endif