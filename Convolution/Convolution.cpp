#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

//练习5
int main(int argc, char*argv)
{	
	//HSV
	double scale = 0.5;
	//0-180肤色
	double i_minH = 0;
	double i_maxH = 20;
	//0-255
	double i_minS = 43;
	double i_maxS = 255;
	//0-255
	double i_minV = 55;
	double i_maxV = 255;

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
		cv::Mat hsvMat;
		cv::Mat detectMat;
		cv::Mat medMat;
		cv::Mat dipMat;
		bool rSucess = cap.read(frame);				
		if (!rSucess)
		{
			std::cout << "不能从视频中读取帧" << std::endl;
			break;
		}
		else
		{	
			Size ResImgSiz = Size(frame.cols*scale, frame.rows*scale);
			Mat rFrame = Mat(ResImgSiz, frame.type());
			resize(frame, rFrame, ResImgSiz, INTER_LINEAR);

			cvtColor(rFrame, hsvMat, COLOR_BGR2HSV);

			rFrame.copyTo(detectMat);
			cv::inRange(hsvMat, Scalar(i_minH, i_minS, i_minV), Scalar(i_maxH, i_maxS, i_maxV), detectMat);
			cv::GaussianBlur(rFrame, medMat, Size(5,5), 3, 3);

			rFrame.copyTo(dipMat);
			medMat.copyTo(dipMat, detectMat);

			imshow("while :in the range", detectMat);
			imshow("display", dipMat);
			imshow("frame", rFrame);
			waitKey(30);
		}
		waitKey(30); //延时30ms

	}
	return 0;
}