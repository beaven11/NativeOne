//
// Created by 王培峰 on 2022/9/30.
//

#include "GLRenderContext.h"
#include "../sample/NativeTriangle.h"
#include "../sample/NativeTriangle2.h"
#include "../sample/NativeTriangle3.h"

GLRenderContext *GLRenderContext::m_pContext = nullptr;

GLRenderContext::GLRenderContext() {
    LOGD("GLRenderContext init")
    p_sample = nullptr;
}

GLRenderContext::~GLRenderContext() {
    LOGD("GLRenderContext unInit")
    if (p_sample) {
        p_sample->ShutDown();
        delete p_sample;
        p_sample = nullptr;
    }
}

void GLRenderContext::SetRenderType(int sampleCategoryType, int renderSampleType) {
    if (sampleCategoryType == SAMPLE_TYPE) {
        switch (renderSampleType) {
            case SAMPLE_TYPE_KEY_TRIANGLE:
                p_sample = new NativeTriangle();
                break;
            case SAMPLE_TYPE_KEY_TRIANGLE2:
                p_sample = new NativeTriangle2();
                break;
            case SAMPLE_TYPE_KEY_TRIANGLE3:
                p_sample = new NativeTriangle3();
                break;
            default:
                p_sample = nullptr;
                break;
        }
    }
    LOGI("GLRenderContext SetRenderType:%d, sample:%d", renderSampleType, p_sample == nullptr)
}

void GLRenderContext::OnSurfaceCreated(JNIEnv *env, jobject assetManager) {
    LOGI("GLRenderContext OnSurfaceCreated")
    GLUtils::setEnvAndAssetManager(env, assetManager);
    if (p_sample) {
        p_sample->Create();
    }
}

void GLRenderContext::OnSurfaceChanged(int width, int height) {
    LOGI("GLRenderContext OnSurfaceChanged")
    if (p_sample) {
        p_sample->Change(width, height);
    }
}

void GLRenderContext::OnDrawFrame() {
    LOGI("GLRenderContext OnDrawFrame")
    if (p_sample) {
        p_sample->Draw();
    }
}

GLRenderContext *GLRenderContext::GetInstance() {
    if (m_pContext == nullptr) {
        m_pContext = new GLRenderContext();
    }
    return m_pContext;
}

void GLRenderContext::DestroyInstance() {
    if (m_pContext) {
        delete m_pContext;
        m_pContext = nullptr;
    }
}
