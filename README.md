opencv简单实践5：中值滤波、均值滤波（普通滤波 高斯滤波）、边缘提取和磨皮程序

cap.open("E:\\1.FLV");       cap.open("E:\\2.mp4"); \\


练习1 中值滤波：

读取摄像头图像，并对摄像头图像进行中值滤波

1.输入，灰度图或彩色图2.输出3.中值区域size，3,5,7等


练习2 均值滤波：

读取摄像头图像，并对摄像头图像进行均值滤波

1.输入，灰度图或彩色图 2.输出3.卷积尺寸Size格式 4.锚点，默认为（-1，-1），即中心5.边缘像素，一般设为默认


练习3 均值滤波：

读取摄像头图像，并对摄像头图像进行均值滤波

1.输入，灰度图或彩色图 2.输出3.卷积尺寸，Size格式4.X方向的sigma5.Y方向的sigma6.边缘像素，一般设为默认


练习4 

边缘提取读取摄像头图像，并对摄像头图像进行边缘提取，分别提取x，y方向上的边缘，观察结果有何区别。

1.输入，灰度图或彩色图 2.输出 3.输出图像的类型4 and 5. x方向和y方向的微分阶数6.卷积核尺寸7.卷积核尺寸，输出微分值的缩放因数8.附加值，加载输出结果上。9.边缘像素，


练习4 

边缘提取Sobel函数，后3个参数与一般使用默认。

1,0表示x方向求1一阶微分，y方向求0阶，即求x方向的边缘 同理，表示求y方向的边缘


练习5 磨皮程序

使用已经学过的算法，实现一个简单的磨皮程序，即人物皮肤的部分显得光滑。（mask，卷积，HSV范围限制）
