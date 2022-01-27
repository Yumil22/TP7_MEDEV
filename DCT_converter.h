#pragma once

#include <opencv4/opencv2/opencv.hpp>
#include <vector>

using namespace std;
using namespace cv;

/// CLASSE DCT_CONVERTER

class DCT_Converter{

private:
    // Matrix P de taille NxN
    Mat dct_matrix;
    // Transform de Matrix P
    Mat t_dct_matrix;

    // Matrix de transformation entre image RGB et YIQ
    Mat rgb_to_yiq;
    Mat yiq_to_rgb;

    // Taille de DCT
    const int N = 8;

    // Compression : Lecture de fichier image (BMP)
    Mat openBMP(string fileName);

    // Compression : Convertir image RGB à YIQ
    Mat YIQ_conversion(Mat rgb_matrix);

    // Décompresiion : Convertir image YIQ à RGB
    Mat RGB_conversion(Mat yiq_matrix);

    // Compression : Découper matrice principale en taille NxN
    vector<Mat> separateMatrix(Mat yiq_matrix);

    // Décompression : Regrouper les matrices séparées
    Mat recombineMatrix(vector<Mat> split_matrix);

public:
    DCT_Converter();
    vector<Mat> getDCTMatrixConverted(string fileName);
    Mat deconvert(vector<Mat> dequantified_matrix);
};
