#include "WebForm/WebForm.h"
#include "Core/RGNCore.h"
#include "Core/RGNAuth.h"
#include "DeepLink/DeepLink.h"
#include "Os/Os.h"
#include "Http/Http.h"
#include <vector>

namespace RGN {
    Utility::FunctionEvent<void(bool, std::string)> WebForm::_redirectEvent;

    void WebForm::OpenSignIn(std::string idToken, std::function<void(bool, std::string)> callback) {
        OpenWebForm(idToken, "", callback);
    }

    void WebForm::OpenCreateWallet(std::string idToken, std::function<void(bool, std::string)> callback) {
        OpenWebForm(idToken, "createwallet", callback);
    }

    void WebForm::OpenWebForm(std::string idToken, std::string view, std::function<void(bool, std::string)> callback) {
        // TODO
    }

    void WebForm::OnWebFormRedirect(bool canceled, std::string url) {
        // TODO
    }

    void WebForm::Initialize() {
        // TODO
    }

    void WebForm::Update() {
        // TODO
    }
}