#include <jni.h>
#include <string>
#include "render/GLRenderContext.h"

extern "C"
JNIEXPORT void JNICALL
Java_com_beaven_nativeone_NativeRender_nativeSurfaceCreate(JNIEnv *env, jobject thiz, jobject asset_manager) {
    LOGI("nativeSurfaceCreate")
    GLRenderContext::GetInstance()->OnSurfaceCreated(env, asset_manager);
}
extern "C"
JNIEXPORT void JNICALL
Java_com_beaven_nativeone_NativeRender_nativeSurfaceChange(JNIEnv *env, jobject thiz, jint width, jint height) {
    LOGE("nativeSurfaceChange->width:%d,height:%d", width, height)
    GLRenderContext::GetInstance()->OnSurfaceChanged(width, height);
}
extern "C"
JNIEXPORT void JNICALL
Java_com_beaven_nativeone_NativeRender_nativeDrawFrame(JNIEnv *env, jobject thiz) {
    LOGI("nativeDrawFrame")
    GLRenderContext::GetInstance()->OnDrawFrame();
}
extern "C"
JNIEXPORT void JNICALL
Java_com_beaven_nativeone_NativeRender_nativeSetRenderType(JNIEnv *env, jobject thiz, jint sample_category_type, jint render_sample_type) {
    LOGW("nativeSetRenderType->%d", render_sample_type)
    GLRenderContext::GetInstance()->SetRenderType(sample_category_type, render_sample_type);
}
extern "C"
JNIEXPORT void JNICALL
Java_com_beaven_nativeone_NativeRender_nativeOnDestroy(JNIEnv *env, jobject thiz) {
    LOGI("nativeOnDestroy")
    GLRenderContext::DestroyInstance();
}