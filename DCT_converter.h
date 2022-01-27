#pragma once

#include <opencv4/opencv2/opencv.hpp>
#include <vector>

using namespace std;
using namespace cv;

/// CLASSE DCT_CONVERTER

class DCT_Converter{

private:
    /// Matrice dct_matrix de taille NxN (8x8) qui correspond à la matrice de la transformée DCT noté P dans le sujet
    Mat dct_matrix;
    /// Matrice dct_matrix de taille NxN (8x8) qui correspond à la transposée de la matrice de la transformée DCT noté tP dans le sujet
    Mat t_dct_matrix;
    /// Matrice rgb_to_yiq de taille 3x3 qui permet de passer du mode RGB au mode YIQ
    Mat rgb_to_yiq;
    /// Matrice yiq_to_rgb de taille 3x3 qui permet de passer du mode YIQ au mode RGB
    Mat yiq_to_rgb;
    /// Entier constant qui définit la taille des blocs (ici 8)
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
