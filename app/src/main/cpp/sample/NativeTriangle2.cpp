//
// Created by 王培峰 on 2022/10/9.
//

#include "NativeTriangle2.h"

static GLfloat vVertices[] = {
        // 逆时针 三个顶点
        0.0f, 0.5f, 0.0f,            // 上角
        -0.5f, -0.5f, 0.0f,          // 左下角
        0.5f, -0.5f, 0.0f            // 右下角
};
// 设置顶点的颜色值  这里设置成蓝色
static GLfloat color[4] = {0.0f, 0.0f, 1.0f, 1.0f};

void NativeTriangle2::Create() {
    GLUtils::printGLInfo();
    VERTEX_SHADER = GLUtils::openTextFile("vertex/vertex_shader_hello_triangle2.glsl");
    FRAGMENT_SHADER = GLUtils::openTextFile("fragment/fragment_shader_hello_triangle2.glsl");
    m_ProgramObj = GLUtils::createProgram(&VERTEX_SHADER, &FRAGMENT_SHADER);
    if (!m_ProgramObj) {
        LOGE("create program fail")
        return;
    }
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
}

void NativeTriangle2::Draw() {
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(m_ProgramObj);
    //  指定通用顶点属性数组
    // 第一个参数指定我们要配置的顶点属性。因为我们希望把数据传递到这一个顶点属性中，所以这里我们传入0。
    // 第二个参数指定顶点属性的大小。顶点属性是一个vec3，它由3个值组成，所以大小是3。
    // 第三个参数指定数据的类型，这里是GL_FLOAT(GLSL中vec*都是由浮点数值组成的)。
    // 第四个参数定义我们是否希望数据被标准化(Normalize)。如果我们设置为GL_TRUE，所有数据都会被映射到0（对于有符号型signed数据是-1）到1之间。我们把它设置为GL_FALSE。
    // 第五个参数叫做步长(Stride)，它告诉我们在连续的顶点属性组之间的间隔。我们设置为0来让OpenGL决定具体步长是多少（只有当数值是紧密排列时才可用）。
    //      一旦我们有更多的顶点属性，我们就必须更小心地定义每个顶点属性之间的间隔，
    //      （译注: 这个参数的意思简单说就是从这个属性第二次出现的地方到整个数组0位置之间有多少字节）。
    // 最后一个参数的类型是void*，所以需要我们进行这个奇怪的强制类型转换。它表示位置数据在缓冲中起始位置的偏移量(Offset)。
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, vVertices);
    glEnableVertexAttribArray(0);
    // Set the vertex color to red
    // 设置顶点的颜色值
    // 加载index指定的通用顶点属性，加载(x,y,z,w)
    // opengl各个坐标系理解与转换公式 https://blog.csdn.net/grace_yi/article/details/109341926
    // x，y，z，w：指的不是四维，其中w指的是缩放因子
    // X轴为水平方向，Y轴为垂直方向，X和Y相互垂直
    // Z轴同时垂直于X和Y轴。Z轴的实际意义代表着三维物体的深度
    glVertexAttrib4fv(1, color);
    // glDrawArrays函数第一个参数是我们打算绘制的OpenGL图元的类型。我们希望绘制的是一个三角形，这里传递GL_TRIANGLES给它。
    // 第二个参数指定了顶点数组的起始索引，我们这里填0。
    // 最后一个参数指定我们打算绘制多少个顶点，这里是3（我们只从我们的数据中渲染一个三角形，它只有3个顶点长）。
    //        public static final int GL_POINTS                                  = 0x0000;
    //        public static final int GL_LINES                                   = 0x0001;
    //        public static final int GL_LINE_LOOP                               = 0x0002;
    //        public static final int GL_LINE_STRIP                              = 0x0003;
    //        public static final int GL_TRIANGLES                               = 0x0004;
    //        public static final int GL_TRIANGLE_STRIP                          = 0x0005;
    //        public static final int GL_TRIANGLE_FAN                            = 0x0006;
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDisableVertexAttribArray(0);
}

void NativeTriangle2::ShutDown() {
    GLBaseSample::ShutDown();
}
