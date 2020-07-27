
#include <iostream>
#include <string>
#include "Detect.h"

using namespace std;
using namespace cv;

int DetectFaceEyes(Mat heying, Mat hyGray)
{

	equalizeHist(hyGray, hyGray);        //ֱ��ͼ���Ȼ�

	vector<Rect> faces, eyes;
	const char *faceCascadeFilename = "D:\\BaiduNetdiskDownload\\ana\\haarcascade_frontalface_alt2.xml";
	const char *eyeCascadeFilename = "D:\\BaiduNetdiskDownload\\ana\\haarcascade_eye_tree_eyeglasses.xml";
	CascadeClassifier faceCascade;
	CascadeClassifier eyeCascade;
	if (!faceCascade.load(faceCascadeFilename))
	{
		cout << "������⼶��������û�ҵ�����" << endl;
		return -1;
	}
	if (!eyeCascade.load(eyeCascadeFilename))
	{
		cout << "�۾���⼶��������û�ҵ�����" << endl;
		return -1;
	}
	faceCascade.detectMultiScale(hyGray, faces, 1.2, 5, 0, Size(30, 30));
	for (auto b : faces)
	{
		cout << "�������λ�ã�(x,y):" << "(" << b.x << "," << b.y << "),\
            (width,heigh):(" << b.width << "," << b.height << ")\n";
	}
	if (faces.size() > 0)
	{
		for (size_t i = 0; i < faces.size(); i++)
		{
			// putText(heying,"xxx", cvPoint(faces[i].x, faces[i].y - 10), FONT_HERSHEY_PLAIN, 2.0, Scalar(0, 0, 255));
			rectangle(heying, Point(faces[i].x, faces[i].y), Point(faces[i].x + faces[i].width, faces[i].y + faces[i].height), Scalar(0, 0, 255), 1, 8);
			cout << faces[i] << endl;

			Mat face_ = hyGray(faces[i]);    // ѡ�������Ļ����϶�λ�۾�
			eyeCascade.detectMultiScale(face_, eyes, 1.2, 2, 0, Size(30, 30));
			for (size_t j = 0; j < eyes.size(); j++)
			{
				// ��ԭͼ�ϱ�ע�۾�����Ҫ������ԭͼ�ϵ�����
				Point eyeCenter(faces[i].x + eyes[j].x + eyes[j].width / 2, faces[i].y + eyes[j].y + eyes[j].height / 2);
				int radius = cvRound((eyes[j].width + eyes[j].height)*0.25);
				circle(heying, eyeCenter, radius, Scalar(65, 105, 255), 4, 8, 0);
			}
		}
	}
	imshow("result", heying);
	//waitKey(5000);
	return 0;
}