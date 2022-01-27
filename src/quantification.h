#pragma once

/*!
* \file quantification.h
* \author Eugene Castelneau
* \author Marine Czaplinski
* \author Vincent Gallot
* \author Morgan Leskerpit
* \author Luc Pares
* \author Erwan Quinot
*/

#include <math.h>
#include <vector>
#include <opencv2/core.hpp>

using namespace std;
using namespace cv;

/*!
* \brief Fonction de quantification
* 
* 
*/

void quantifier(int facteurQualite, vector<Mat>* entree);


void dequantifier(int facteurQualite, vector<Mat>* entree);

/*!
* 
*/

void creerQ0(int facteurQualite, Mat* q0);

void divisionMat(Mat* coeff, Mat* q0);

