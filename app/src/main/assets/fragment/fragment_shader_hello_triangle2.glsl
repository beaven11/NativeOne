#version 300 es
// 浮点默认精度
precision mediump float;
// 顶点着色器传过来的颜色值
in vec4 v_color;
// 输出到颜色缓冲器的值
out vec4 o_fragColor;

void main() {
    o_fragColor = v_color;
}
