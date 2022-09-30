//
// Created by 王培峰 on 2022/9/30.
//

#ifndef NATIVEONE_GLUTILS_H
#define NATIVEONE_GLUTILS_H

#include <stdlib.h>
#include <jni.h>
#include <GLES3/gl3.h>
#include <GLES3/gl3ext.h>
#include "LogUtils.h"
#include <android/asset_manager_jni.h>


class GLUtils {
public:
    /**
    * Set Environment parameter
    */
    static void setEnvAndAssetManager(JNIEnv *env, jobject assetManager);

    /**
     *  Loads a file from assets/path into a char array.
     */
    static char *openTextFile(const char *path);

    /**
	 * Create a program with the given vertex and framgent
	 * shader source code.
	 */
    static GLuint createProgram(const char** vertexSource, const char** fragmentSource);

    static void checkGlError(const char* pGLOperation);

    static void printGLString(const char *name, GLenum s) {
        const char *v = (const char *) glGetString(s);
        LOGI("GL %s = %s \n", name, v)
    }

    // Print some OpenGL info
    static void printGLInfo() {
        LOGI("===== Here are some information of your device =====");
        printGLString("Version", GL_VERSION);
        printGLString("GLSL Version", GL_SHADING_LANGUAGE_VERSION);
        printGLString("Vendor", GL_VENDOR);
        printGLString("Renderer", GL_RENDERER);
        printGLString("Extensions", GL_EXTENSIONS);

        GLint iParam[2];
        glGetIntegerv(GL_MAX_VERTEX_UNIFORM_VECTORS, iParam);
        LOGI("Max Vertex Uniform Vectors: %d", iParam[0]);

        glGetIntegerv(GL_MAX_FRAGMENT_UNIFORM_VECTORS, iParam);
        LOGI("Max Fragment Uniform Vectors : %d", iParam[0]);

        glGetIntegerv(GL_MAX_VARYING_VECTORS, iParam);
        LOGI("Max Varying Vectors: %d", iParam[0]);

        glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, iParam);
        LOGI("Max Texture Image Units : %d", iParam[0]);

        glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, iParam);
        LOGI("Max Combined Texture Image Units : %d", iParam[0]);

        glGetIntegerv(GL_MAX_TEXTURE_SIZE, iParam);
        LOGI("Max Texture Size : %d", iParam[0]);

        glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, iParam);
        LOGI("Max Vertex Attribs: %d", iParam[0]);

        glGetIntegerv(GL_MAX_VIEWPORT_DIMS, iParam);
        LOGI("Max Viewport Dims : [%d, %d]", iParam[0], iParam[1]);

        glGetIntegerv(GL_MAX_RENDERBUFFER_SIZE, iParam);
        LOGI("Max Render Buffer Size: %d", iParam[0]);

        glGetIntegerv(GL_STENCIL_BITS, iParam);
        LOGI("Stencil Buffer Bits : %d", iParam[0]);

        glGetIntegerv(GL_ALIASED_POINT_SIZE_RANGE, iParam);
        LOGI("Point Size Range: [%d, %d]", iParam[0], iParam[1]);

        glGetIntegerv(GL_ALIASED_LINE_WIDTH_RANGE, iParam);
        LOGI("Line Width Range: [%d, %d]", iParam[0], iParam[1]);

        glGetIntegerv(GL_DEPTH_BITS, iParam);
        LOGI("Depth Bits: %d", iParam[0]);

        LOGI("===== Information end =====");
    }

};


#endif //NATIVEONE_GLUTILS_H
