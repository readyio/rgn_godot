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
    #if defined(LINUXBSD_ENABLED) || defined(WINDOWS_ENABLED) || defined(MACOS_ENABLED)
        Http::WaitForInRequest(0, [](std::string url) {
            OnWebFormRedirect(false, url);
        }, _editorCurrBoundedPort);
        redirectUrl = "http://127.0.0.1:" + std::to_string(_editorCurrBoundedPort) + "/";
    #else
        redirectUrl = "rgn" + RGNCore::GetAppId();
        DeepLink::Listen([](bool canceled, std::string url) {
            OnWebFormRedirect(canceled, url);
        });
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
        Os::OpenURL(url);
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
    }

    void WebForm::Update() {
        G_RGNCore::get_singleton()->onFocusEvent.bind(CancelRedirectWaitDelay);
    }
}