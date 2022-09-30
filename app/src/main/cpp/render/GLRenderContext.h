//
// Created by 王培峰 on 2022/9/30.
//

#ifndef NATIVEONE_GLRENDERCONTEXT_H
#define NATIVEONE_GLRENDERCONTEXT_H

#include <jni.h>
#include "../utils/LogUtils.h"
#include "../sample/GLBaseSample.h"

class GLRenderContext {
    GLRenderContext();

    ~GLRenderContext();

public:
    void SetRenderType(int sampleCategoryType, int renderSampleType);

    void OnSurfaceCreated(JNIEnv *env, jobject assetManager);

    void OnSurfaceChanged(int width, int height);

    void OnDrawFrame();

    static GLRenderContext *GetInstance();

    static void DestroyInstance();

private:
    static GLRenderContext *m_pContext;
    GLBaseSample *p_sample;
};

#endif //NATIVEONE_GLRENDERCONTEXT_H
