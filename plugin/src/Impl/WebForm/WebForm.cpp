#include "WebForm/WebForm.h"
#include "Core/RGNCore.h"
#include "Core/RGNAuth.h"
#include "Impl/Core/G_RGNCore.h"
#include "DeepLink/DeepLink.h"
#include "Os/Os.h"
#include "Http/Http.h"
#include "Utility/Logger.h"
#include <vector>
#include <unordered_map>
#ifdef GODOT3
#include <Engine.hpp>
#else
#include <godot_cpp/classes/engine.hpp>
#endif

namespace RGN {
    Utility::FunctionEvent<void(bool, std::string)> WebForm::_redirectEvent;
    int32_t _editorCurrBoundedPort = 0;

    void CancelRedirectWaitDelay() {
        G_RGNCore::get_singleton()->startTimer(2.5, [](){
            WebForm::OnWebFormRedirect(true, "");
        });
    }

    void WebForm::OpenSignIn(std::string idToken, std::function<void(bool, std::string)> callback) {
        OpenWebForm(idToken, "", callback);
    }

    void WebForm::OpenCreateWallet(std::string idToken, std::function<void(bool, std::string)> callback) {
        OpenWebForm(idToken, "createwallet", callback);
    }

    void WebForm::OpenWebForm(std::string idToken, std::string view, std::function<void(bool, std::string)> callback) {
        _redirectEvent.bind(callback);
        std::string redirectUrl;
    #if defined(PLATFORM_WINDOWS) || (defined(PLATFORM_MACOS) || defined(PLATFORM_OSX))
        Http::WaitForInRequest(0, [](std::string url) {
            OnWebFormRedirect(false, url);
        }, _editorCurrBoundedPort);
        redirectUrl = "http://127.0.0.1:" + std::to_string(_editorCurrBoundedPort) + "/";
    #else
        redirectUrl = "rgn" + RGNCore::GetAppId();
    #endif
        std::string url = RGNCore::GetOAuthUrl() + redirectUrl +
            "&returnSecureToken=true" +
            "&returnRefreshToken=true" +
            "&appId=" + RGNCore::GetAppId();
        if (!idToken.empty()) {
            url = url + "&idToken=" + idToken;
        }
        if (!view.empty()) {
            url = url + "&view=" + view;
        }
    #if defined(PLATFORM_ANDROID) || defined(PLATFORM_IOS)
        godot::Object* webview = godot::Engine::get_singleton()->get_singleton("READYggWebview");
        if (webview != nullptr) {
            webview->call("setInstanceId", G_RGNCore::get_singleton()->get_instance_id());
            webview->call("setUrlScheme", godot::String(redirectUrl.c_str()));
            webview->call("openUrl", godot::String(url.c_str()));
        }
    #else
        Os::OpenURL(url);
    #endif
    }

    void WebForm::OnWebFormRedirect(bool canceled, std::string url) {
        if (_editorCurrBoundedPort > 0) {
            Http::CancelWaitForInRequest(_editorCurrBoundedPort);
            _editorCurrBoundedPort = 0;
        }
        if (canceled) {
            _redirectEvent.raise_and_unbind(canceled, "");
            return;
        }
        std::unordered_map<std::string, std::string> payloadArgs = HttpUtility::ParseUrl(url);
        bool tokenExists = payloadArgs.find("token") != payloadArgs.end();
        if (!tokenExists) {
            _redirectEvent.raise_and_unbind(false, "");
            return;
        }
        std::string refreshToken = payloadArgs.at("token");
        _redirectEvent.raise_and_unbind(false, refreshToken);
    }

    void WebForm::Initialize() {
        G_RGNCore::get_singleton()->onFocusEvent.bind(CancelRedirectWaitDelay);
    }

    void WebForm::Update() {
    }
}