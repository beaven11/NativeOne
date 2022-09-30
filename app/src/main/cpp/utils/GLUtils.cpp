//
// Created by 王培峰 on 2022/9/30.
//

#include "GLUtils.h"

static JNIEnv *sEnv = nullptr;
static jobject sAssetManager = nullptr;

static AAsset *loadAsset(const char *path) {
    AAssetManager *manager = AAssetManager_fromJava(sEnv, sAssetManager);
    if (manager == nullptr) {
        return nullptr;
    }
    return AAssetManager_open(manager, path, AASSET_MODE_UNKNOWN);
}

/**
 * Loads the given source code as a shader of the given type.
 *
 * 负责 加载着色器源代码、编译并检查错误。他返回一个着色器对象
 */
static GLuint loadShader(GLenum shaderType, const char **source) {
    // Create the shader object
    GLuint shader;
    shader = glCreateShader(shaderType);
    if (shader == 0) {
        return 0;
    }
    GLint compiled;
    // Load the shader source
    glShaderSource(shader, 1, source, nullptr);
    // Compile the shader
    glCompileShader(shader);
    // Check the compile status
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
    if (!compiled) {
        GLint infoLen = 0;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen);
        if (infoLen > 1) {
            char *infoLog = (char *) malloc(sizeof(char) * infoLen);
            if (infoLog) {
                // 检索信息日志
                glGetShaderInfoLog(shader, infoLen, nullptr, infoLog);
                LOGE("GLUtils::loadShader error compiling shader:\n%s\n", infoLog)
                free(infoLog);
            }
        }
        // 删除Shader
        glDeleteShader(shader);
        return 0;
    }
    return shader;
}

void GLUtils::setEnvAndAssetManager(JNIEnv *env, jobject assetManager) {
    sEnv = env;
    sAssetManager = assetManager;
}

char *GLUtils::openTextFile(const char *path) {
    char *buffer;
    LOGI("GLUtils::openTextFile path [%s]", path)
    AAsset *aAsset = loadAsset(path);
    if (aAsset == nullptr) {
        LOGE("Couldn't load %s", path)
        return nullptr;
    }
    off_t length = AAsset_getLength(aAsset);
    buffer = new char[length + 1];
    int result = AAsset_read(aAsset, buffer, length);
    AAsset_close(aAsset);
    if (result != length) {
        LOGE("Couldn't read %s", path)
        delete[] buffer;
        return nullptr;
    }
    buffer[length] = '\0';
    return buffer;
}

GLuint GLUtils::createProgram(const char **vertexSource, const char **fragmentSource) {
    GLuint program = 0;
    // Load the Vertex shader
    GLuint vertexShader = loadShader(GL_VERTEX_SHADER, vertexSource);
    if (vertexShader == 0) {
        return 0;
    }
    // Load the Fragment shader
    GLuint fragmentShader = loadShader(GL_FRAGMENT_SHADER, fragmentSource);
    if (fragmentShader == 0) {
        return 0;
    }

    // Create the program object
    program = glCreateProgram();
    if (program == 0) {
        return 0;
    }

    // Bind the vertex shader to the program
    glAttachShader(program, vertexShader);
    checkGlError("glAttachShader");
    // Bind the fragment shader to the program.
    glAttachShader(program, fragmentShader);
    checkGlError("glAttachShader");
    // Link the program
    glLinkProgram(program);

    // Check the link status
    GLint linkStatus;
    glGetProgramiv(program, GL_LINK_STATUS, &linkStatus);
    if (!linkStatus) {
        // Retrieve compiler error message when linking fails
        GLint infoLen = 0;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLen);
        if (infoLen > 1) {
            char *infoLog = (char *) malloc(sizeof(char) * infoLen);
            if (infoLog) {
                //获取信息
                glGetProgramInfoLog(program, infoLen, nullptr, infoLog);
                LOGE("GLUtils::createProgram error linking program:\n%s\n", infoLog)
                free(infoLog);
            }
        }
        // 删除程序对象
        glDeleteProgram(program);
        return 0;
    }
    // Free up no longer needed shader resources
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    return program;
}

void GLUtils::checkGlError(const char *pGLOperation) {
    for (GLenum error = glGetError(); error; error = glGetError()) {
        LOGE("GLUtils::CheckGLError after GL Operation %s() glError (0x%x)\n", pGLOperation, error);
    }
}
