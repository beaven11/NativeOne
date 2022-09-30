//
// Created by 王培峰 on 2022/9/30.
//

#ifndef NATIVEONE_LOGUTILS_H
#define NATIVEONE_LOGUTILS_H

#include <android/log.h>
#include <string.h>
#include <sys/time.h>

// 文件名
#define __FILENAME__ (strrchr(__FILE__, '/') + 1)

// 定义LOG 标签
#define TAG "GL_NDK"
#define LOGD(format, ...) __android_log_print(ANDROID_LOG_DEBUG, TAG,\
        "[%s][%s][%d]: " format, __FILENAME__, __FUNCTION__, __LINE__, ##__VA_ARGS__);
#define LOGI(format, ...) __android_log_print(ANDROID_LOG_INFO, TAG,\
        "[%s][%s][%d]: " format, __FILENAME__, __FUNCTION__, __LINE__, ##__VA_ARGS__);
#define LOGW(format, ...) __android_log_print(ANDROID_LOG_WARN, TAG,\
        "[%s][%s][%d]: " format, __FILENAME__, __FUNCTION__, __LINE__, ##__VA_ARGS__);
#define LOGE(format, ...) __android_log_print(ANDROID_LOG_ERROR, TAG,\
        "[%s][%s][%d]: " format, __FILENAME__, __FUNCTION__, __LINE__, ##__VA_ARGS__);
#endif //NATIVEONE_LOGUTILS_H
