#version 300 es
// 表示OpenGL ES着色器语言V3.00

// 声明着色器中浮点变量的默认精度
precision mediump float;
// 声明一个输出变量fragColor，这是一个4分量的向量，
// 写入这个变量的值将被输出到颜色缓冲器
out vec4 fragColor;

void main()
{
	//在计算机图形中颜色被表示为有4个元素的数组：红色、绿色、蓝色和alpha(透明度)分量，
	//通常缩写为RGBA。当在OpenGL或GLSL中定义一个颜色的时候，
	//我们把颜色每个分量的强度设置在0.0到1.0之间。

	//比如说我们设置红为1.0f，绿为1.0f，我们会得到两个颜色的混合色，即黄色。
	//这三种颜色分量的不同调配可以生成超过1600万种不同的颜色！

	// 所有片段的着色器输出都是红色( 1.0, 0.0, 0.0, 1.0 )
	fragColor = vec4 ( 1.0, 0.0, 0.0, 1.0 );

	// 会输出橘黄色
	// fragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
}