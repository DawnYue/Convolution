#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

//练习2
Mat  g_dstImage;

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
		frame.copyTo(g_dstImage);		
		blur(frame, g_dstImage, Size(11, 11), Point(-1, -1));
		if (!rSucess)
		{
			std::cout << "不能从视频中读取帧" << std::endl;
			break;
		}
		else
		{
			imshow("均值滤波", g_dstImage);
		}
		waitKey(30); //延时30ms

	}
	return 0;
}