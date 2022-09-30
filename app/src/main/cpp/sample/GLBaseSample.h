//
// Created by 王培峰 on 2022/9/30.
//

#ifndef NATIVEONE_GLBASESAMPLE_H
#define NATIVEONE_GLBASESAMPLE_H

#include "../utils/GLUtils.h"
#include "GLBaseSampleType.h"

class GLBaseSample {
public:
    GLBaseSample() {
        VERTEX_SHADER = GL_NONE;
        FRAGMENT_SHADER = GL_NONE;
        m_ProgramObj = 0;
        m_Width = 0;
        m_Height = 0;
    }

    virtual ~GLBaseSample() {}

    virtual void Create() {}

    virtual void Draw() {}

    virtual void ShutDown() {
        if (m_ProgramObj) {
            glDeleteProgram(m_ProgramObj);
            m_ProgramObj = GL_NONE;
        }
        if (VERTEX_SHADER != nullptr) {
            delete[] VERTEX_SHADER;
            VERTEX_SHADER = nullptr;
        }
        if (FRAGMENT_SHADER != nullptr) {
            delete[] FRAGMENT_SHADER;
            FRAGMENT_SHADER = nullptr;
        }
    }

    virtual void Change(int width, int height) {
        LOGD("Change() width = %d , height = %d\n", width, height)
        m_Width = width;
        m_Height = height;
        // Set the viewport
        // 通知OpenGL ES 用于绘制的2D渲染表面的原点、宽度和高度。
        // 在OpenGL ES 中，视口(Viewport) 定义所有OpenGL ES 渲染操作最终显示的2D矩形
        // 视口(Viewport) 由原点坐标(x,y)和宽度(width) 、高度(height)定义。
        glViewport(0, 0, m_Width, m_Height);
    }

protected:
    /**
   * 程序对象
   */
    GLuint m_ProgramObj;

    /**
     * 顶点着色器
     */
    const char *VERTEX_SHADER;
    /**
     * 片段着色器脚本
     */
    const char *FRAGMENT_SHADER;

    /**
     * 屏幕宽度
     */
    int m_Width;
    /**
     * 屏幕高度
     */
    int m_Height;
};

#endif //NATIVEONE_GLBASESAMPLE_H
