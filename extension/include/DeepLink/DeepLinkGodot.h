#if ANDROID_ENABLED
#include <jni.h>

extern "C" {
    JNIEXPORT void JNICALL Java_io_getready_rgn_iac_RGNPlugin_onInvocation(JNIEnv* env, jobject instance, jstring Payload);
}
#endif