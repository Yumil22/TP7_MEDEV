#ifndef COMPRESSION_RLC
#define COMPRESSION_RLC

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include <iostream>
#include <fstream>
#include <string>

string compressionrlc(cv::Mat im);

vector<int> lecture(cv::Mat im);

string comp(vector<int> vec);




#endif