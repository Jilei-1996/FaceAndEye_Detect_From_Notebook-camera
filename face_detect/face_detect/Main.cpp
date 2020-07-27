#include <tchar.h>
#include <iostream>
#include <opencv2\opencv.hpp>
#include "Detect.h"

using namespace cv;


int _tmain(int argc, _TCHAR* argv[])
{
	cvNamedWindow("我的摄像头", CV_WINDOW_AUTOSIZE);
	//captue = cvCaptureFromCAM(0);
	VideoCapture captue(0);//创建一个摄像头对象并且指定摄像头编号，只有一个写0就可以
	//captue = cvCreateCameraCapture(0);
	Mat frame;
	Mat grayframe;
	int face_number;
	while (1)
	{


		captue >> frame;
		imshow("我的摄像头", frame);
		cvtColor(frame, grayframe, CV_RGB2GRAY);
		face_number = DetectFaceEyes(frame, grayframe);


		waitKey(30);
		//cvDestroyWindow(pstrWindowsBinaryTitle);
	}
	return 0;
}
