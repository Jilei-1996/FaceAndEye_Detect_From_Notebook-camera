#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#ifndef DETECT_H
#define DETECT_H
int DetectFaceEyes(cv::Mat heying, cv::Mat hyGray);    //检测人脸定位人眼
#endif // !DETECT_H
