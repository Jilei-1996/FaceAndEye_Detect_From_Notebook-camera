#include <tchar.h>
#include <iostream>
#include <opencv2\opencv.hpp>
#include "Detect.h"

using namespace cv;


int _tmain(int argc, _TCHAR* argv[])
{
	cvNamedWindow("�ҵ�����ͷ", CV_WINDOW_AUTOSIZE);
	//captue = cvCaptureFromCAM(0);
	VideoCapture captue(0);//����һ������ͷ������ָ������ͷ��ţ�ֻ��һ��д0�Ϳ���
	//captue = cvCreateCameraCapture(0);
	Mat frame;
	Mat grayframe;
	int face_number;
	while (1)
	{


		captue >> frame;
		imshow("�ҵ�����ͷ", frame);
		cvtColor(frame, grayframe, CV_RGB2GRAY);
		face_number = DetectFaceEyes(frame, grayframe);


		waitKey(30);
		//cvDestroyWindow(pstrWindowsBinaryTitle);
	}
	return 0;
}
