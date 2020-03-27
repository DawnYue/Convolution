#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

//练习2
Mat src, g_dstImage1, g_dstImage2, g_dstImage3, g_dstImage4, g_dstImage5;
int g_nGaussianBlurValue = 6;  //高斯滤波内核值

int main(int argc, char*argv)
{
	//实例化一个videocapture类，名称为cap
	VideoCapture cap;
	//cap(0)表示打开本机的第一个摄像头
	cap.open(0);
	//isOpened()检查视频是否开启，正常开启返回1	
	if (!cap.isOpened())
	{
		std::cout << "不能打开视频文件" << std::endl;
		return -1;
	}
	//获得视频的fps
	double fps = cap.get(CAP_PROP_FPS);
	std::cout << "fps" << fps << std::endl;

	while (1)
	{
		cv::Mat frame;
		bool rSucess = cap.read(frame);		
		//frame.copyTo(g_dstImage3);
		//GaussianBlur(frame, g_dstImage3, Size(g_nGaussianBlurValue * 2 + 1, g_nGaussianBlurValue * 2 + 1), 0, 0);
		//imshow("高斯滤波", g_dstImage3);

		frame.copyTo(g_dstImage2);		
		blur(frame, g_dstImage2, Size(11, 11), Point(-1, -1));
		if (!rSucess)
		{
			std::cout << "不能从视频中读取帧" << std::endl;
			break;
		}
		else
		{
			imshow("均值滤波", g_dstImage2);
		}
		waitKey(30); //延时30ms

	}
	return 0;
}