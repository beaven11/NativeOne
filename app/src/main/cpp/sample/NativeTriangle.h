//
// Created by 王培峰 on 2022/9/30.
//

#ifndef NATIVEONE_NATIVETRIANGLE_H
#define NATIVEONE_NATIVETRIANGLE_H

#include "GLBaseSample.h"

class NativeTriangle : public GLBaseSample {
#define VERTEX_POS_INDX       0
public:
    NativeTriangle() = default;

    virtual ~NativeTriangle() = default;

    virtual void Create();

    virtual void Draw();

    virtual void ShutDown();
};


#endif //NATIVEONE_NATIVETRIANGLE_H
