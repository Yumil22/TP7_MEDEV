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
#include <vector>

/// <summary>
/// Compresse une matrice DTC 8*8 avec la methode RLC
/// </summary>
/// <param name="im"></param>
/// <returns></returns>
std::string compressionrlc(cv::Mat im);

/// <summary>
/// Lis une matrice DTC 8*8 et la stocke sous forme d'un vecteur simple (64 pixels * 3 canaux (RGB))
/// </summary>
/// <param name="im"></param>
/// <returns></returns>
std::vector<int> lecture(cv::Mat im);

/// <summary>
/// Compresse un vecteur d'int en un string avec la methode RLC
/// </summary>
/// <param name="vec"></param>
/// <returns></returns>
std::string comp(std::vector<int> vec);




#endif