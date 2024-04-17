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

#if ANDROID_ENABLED
#include <jni.h>
static JavaVM *jvm = NULL;

extern "C" {
    JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
        JNIEnv *env;
        if (vm->GetEnv((void **)&env, JNI_VERSION_1_6) != JNI_OK) {
            return JNI_ERR;
        }
        jvm = vm;
        return JNI_VERSION_1_6;
    }

    JNIEXPORT void JNICALL Java_io_getready_android_WebformPlugin_onWebformRedirect(JNIEnv* env, jobject instance, jstring Url) {
        const char* urlChars = env->GetStringUTFChars(Url, nullptr);
        std::string urlString = std::string(urlChars);
        if (urlString.find("canceled") != std::string::npos) {
            RGN::WebForm::OnWebFormRedirect(true, "");
        } else {
            RGN::WebForm::OnWebFormRedirect(false, urlString);
        }
    }
}
#endif

namespace RGN {
    Utility::FunctionEvent<void(bool, std::string)> WebForm::_redirectEvent;
    int32_t _editorCurrBoundedPort = 0;

#if ANDROID_ENABLED
    void OpenWebFormAndroid(std::string url, std::string redirectScheme) {
        JNIEnv *env;
        jint result = jvm->GetEnv((void **)&env, JNI_VERSION_1_6);
        if (result != JNI_OK) {
            return;
        }
        jclass clazz = env->FindClass("io/getready/android/WebformPlugin");
        if (clazz != NULL) {
            jmethodID methodID = env->GetStaticMethodID(clazz, "launch", "(Ljava/lang/String;Ljava/lang/String;)V");
            if (methodID != NULL) {
                jstring jurl = env->NewStringUTF(url.c_str());
                jstring jredirectScheme = env->NewStringUTF(redirectScheme.c_str());
                env->CallStaticVoidMethod(clazz, methodID, jurl, jredirectScheme);
                env->DeleteLocalRef(jurl);
                env->DeleteLocalRef(jredirectScheme);
            }
        }
    }
#endif

#if IOS_ENABLED
    void OpenWebFormIOS(std::string url, std::string redirectScheme) {

    }
#endif

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
    #if defined(ANDROID_ENABLED)
        OpenWebFormAndroid(url, redirectUrl);
    #elif defined(IOS_ENABLED)
        OpenWebFormIOS(url, redirectUrl);
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
    }

    void WebForm::Update() {
        G_RGNCore::get_singleton()->onFocusEvent.bind(CancelRedirectWaitDelay);
    }
}