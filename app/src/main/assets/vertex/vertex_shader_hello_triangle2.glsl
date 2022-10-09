#version 300 es
// 位置属性
layout(location=0) in vec4 a_position;
// 颜色输入
layout(location=1) in vec4 a_color;
// 颜色输出到片段着色器
out vec4 v_color;

void main() {
    v_color = a_color;
    gl_Position = a_position;
}