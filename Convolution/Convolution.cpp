#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

//练习1
Mat g_srcImage, g_dstImage1, g_dstImage2, g_dstImage3, g_dstImage4, g_dstImage5;
int g_nMeanBlurValue = 10;  //均值滤波内核值
int g_nGaussianBlurValue = 6;  //高斯滤波内核值
int g_nMedianBlurValue = 10;  //中值滤波参数值
static void on_MeanBlur(int, void *);		//均值块滤波器
static void on_GaussianBlur(int, void *);			//高斯滤波器
static void on_MedianBlur(int, void *);			//中值滤波器

int main(int argc, char*argv)
{
	Mat src, dst, dst1, dst2;
	src = imread("E:\\coin.png", 0);
	//cv::Mat srcMat = imread("E:\\IMG.jpg", 0);
	if (!src.data)
	{
		printf("could not load image...\n");
		return -1;
	}

	src.copyTo(g_dstImage1);
	src.copyTo(g_dstImage2);
	src.copyTo(g_dstImage3);
	src.copyTo(g_dstImage4);

	blur(src, g_dstImage2, Size(g_nMeanBlurValue + 1, g_nMeanBlurValue + 1), Point(-1, -1));
	imshow("均值滤波", g_dstImage2);
	GaussianBlur(src, g_dstImage3, Size(g_nGaussianBlurValue * 2 + 1, g_nGaussianBlurValue * 2 + 1), 0, 0);
	imshow("高斯滤波", g_dstImage3);
	medianBlur(src, g_dstImage4, g_nMedianBlurValue * 2 + 1);
	imshow("中值滤波", g_dstImage4);
	waitKey(0);

	namedWindow("input", CV_WINDOW_AUTOSIZE);
	namedWindow("border process", CV_WINDOW_AUTOSIZE);
	imshow("input", src);

	int c = 0;
	int top = (0.05*src.rows);
	int bottom = (0.05*src.rows);
	int left = 0.05*src.cols;
	int right = 0.05*src.cols;
	int bordertype = BORDER_DEFAULT;//openCV中默认的处理方法
	//opencv里面卷积操作实际过程：在卷积开始之前增加边缘像素，填充的像素值为0或者RGB黑色，比如3x3在四周各填充1个像素的边缘，这样就确保图像的边缘被处理，在卷积处理之后再去掉这些边缘。（填充边缘opencv里面有四种）
	RNG rng(12345);
	while (true)
	{
		c = waitKey(500);
		//ESC键
		if ((char)c == 27)		{
			break;
		}
		else if ((char)c == 'r')		{
			bordertype = BORDER_REPLICATE;//填充边缘像素用已知的边缘像素值。
		}
		else if ((char)c == 'w')		{
			bordertype = BORDER_WRAP;//用另外一边的像素来补偿填充
		}
		else if ((char)c == 'c')		{
			bordertype = BORDER_CONSTANT;//填充边缘用指定像素值
		}
		Scalar color = (rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		//给图像添加边缘
		copyMakeBorder(src, dst, top, bottom, left, right, bordertype, color);
		imshow("border process", dst);
	}
	waitKey(0);
	return 0;
}

//		描述：均值滤波操作的回调函数
static void on_MeanBlur(int, void *)
{
	blur(g_srcImage, g_dstImage2, Size(g_nMeanBlurValue + 1, g_nMeanBlurValue + 1), Point(-1, -1));
	imshow("【<2>均值滤波】", g_dstImage2);

}

//		描述：高斯滤波操作的回调函数
static void on_GaussianBlur(int, void *)
{
	GaussianBlur(g_srcImage, g_dstImage3, Size(g_nGaussianBlurValue * 2 + 1, g_nGaussianBlurValue * 2 + 1), 0, 0);
	imshow("【<3>高斯滤波】", g_dstImage3);
}

//		描述：中值滤波操作的回调函数
static void on_MedianBlur(int, void *)
{
	medianBlur(g_srcImage, g_dstImage4, g_nMedianBlurValue * 2 + 1);
	imshow("【<4>中值滤波】", g_dstImage4);
}
