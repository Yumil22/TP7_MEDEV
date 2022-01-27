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


    ///Méthode openBMP qui prend en argument le nom du fichier cible, qui l'ouvre et qui le stocke dans une matrice. 
    ///Le mode est initialement en RGB.
    Mat openBMP(string fileName);
    ///Méthode YIQ_conversion qui prend en argument une matrice d'image en mode RGB et qui la convertit en une matrice d'image en mode YIQ
    Mat YIQ_conversion(Mat rgb_matrix);
    ///Méthode RGB_conversion qui prend en argument une matrice d'image en mode YIQ et qui la convertit en une matrice d'image en mode RGB
    Mat RGB_conversion(Mat yiq_matrix);
    ///Méthode separateMatrix qui prend en argument une matrice d'image en mode YIQ, et qui va la diviser en blocs de matrice de taille NxN (8x8).
    ///Les blocs ainsi obtenus seront stockés dans un vecteur de matrices.
    vector<Mat> separateMatrix(Mat yiq_matrix);
    ///MéthoderecombineMatrix qui prend en argument un vecteur de matrices blocs NxN YIQ, et qui les recombine lors de la décompression. 
    Mat recombineMatrix(vector<Mat> split_matrix);

public:
    ///Constructeur 
    DCT_Converter();
    ///Méthode principale en mode compression qui va comprendre, l'ouverture de fichier, la conversion RGB vers YIQ, puis la transformée DCT par blocs.
    vector<Mat> getDCTMatrixConverted(string fileName);
    ///Méthode principale en mode décompression qui va comprendre, le transformée inverse DCT de chaque blocs déqquantifiés, puis la recombinaison des blocs, en enfin la conversion YIQ vers RGB.
    Mat deconvert(vector<Mat> dequantified_matrix);
};
