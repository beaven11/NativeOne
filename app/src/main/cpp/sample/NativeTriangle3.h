//
// Created by 王培峰 on 2022/10/9.
//

#ifndef NATIVEONE_NATIVETRIANGLE3_H
#define NATIVEONE_NATIVETRIANGLE3_H

#include "GLBaseSample.h"

#define VERTEX_POS_INDEX 0
#define VERTEX_COLOR_INDEX 1
#define VERTEX_POS_SIZE 3 // x y z
#define VERTEX_COLOR_SIZE 4 // r g b a

class NativeTriangle3 : public GLBaseSample {
public:
    NativeTriangle3() = default;

    ~NativeTriangle3() = default;

    virtual void Create();

    virtual void Draw();

    virtual void ShutDown();

private:
    /**
   * 定义顶点数据以后，我们会把它作为输入发送给图形渲染管线的第一个处理阶段：顶点着色器。
   * 它会在GPU上创建内存用于储存我们的顶点数据，还要配置OpenGL如何解释这些内存，并且指定其如何发送给显卡。顶点着色器接着会处理我们在内存中指定数量的顶点。
     我们通过顶点缓冲对象(Vertex Buffer Objects, VBO)管理这个内存，它会在GPU内存（通常被称为显存）中储存大量顶点。
     使用这些缓冲对象的好处是我们可以一次性的发送一大批数据到显卡上，而不是每个顶点发送一次。
     从CPU把数据发送到显卡相对较慢，所以只要可能我们都要尝试尽量一次性发送尽可能多的数据。
     当数据发送至显卡的内存中后，顶点着色器几乎能立即访问顶点，这是个非常快的过程。
   */
    GLuint vboIds[3];
};


#endif //NATIVEONE_NATIVETRIANGLE3_H
