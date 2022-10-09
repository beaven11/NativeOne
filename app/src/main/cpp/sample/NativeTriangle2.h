//
// Created by 王培峰 on 2022/10/9.
//

#ifndef NATIVEONE_NATIVETRIANGLE2_H
#define NATIVEONE_NATIVETRIANGLE2_H

#include "GLBaseSample.h"

class NativeTriangle2 : public GLBaseSample {

public:
    NativeTriangle2() = default;

    virtual ~NativeTriangle2() = default;

    virtual void Create();

    virtual void Draw();

    virtual void ShutDown();
};


#endif //NATIVEONE_NATIVETRIANGLE2_H
