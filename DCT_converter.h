#pragma once

#include <opencv4/opencv2/opencv.hpp>
#include <vector>

using namespace std;
using namespace cv;


class DCT_Converter{

private:
    Mat dct_matrix;
    Mat t_dct_matrix;
    Mat tgb_to_yiq;
    Mat yiq_to_rgb;
    const int N = 8;

    Mat openBMP(string fileName);
    Mat YIQ_conversion(Mat rgb_matrix);
    Mat RGB_conversion(Mat yiq_matrix);
    vector<Mat> separateMatrix(Mat yiq_matrix);
    Mat recombineMatrix(vector<Mat> split_matrix);

public:
    DCT_Converter();
    vector<Mat> getDCTMatrixConverted(string fileName);
    Mat deconvert(vector<Mat> dequantified_matrix);
};