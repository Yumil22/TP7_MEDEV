///
/// \file RLCDecompression.h
///	\brief Header de la fonction de décompression RLC
///
#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

///
/// \fn void RLCDecompression(std::string codage, cv::Mat& matrice);
/// \brief Décompresse la chaine de carractère de codage pour enregistrer les données dans la matrice
/// \param codage Chaine de caractère des données encodées
/// \param matrice Matrice de résultat. Passage par argument.
///
void RLCDecompression(std::string codage, cv::Mat& matrice);