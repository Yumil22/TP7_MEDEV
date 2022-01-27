
#include "quantification.h"

void quantifier(int facteurQualite, vector<Mat>* entree) {
	Mat q0;
	creerQ0(facteurQualite, &q0);
	int n = entree->size();
	for (int i = 0; i < n; i++) {
        divisionMat(&(*entree)[i], &q0);
	}
}

void dequantifier(int facteurQualite, vector<Mat>* entree) {
    Mat q0;
    creerQ0(facteurQualite, &q0);
    int n = entree->size();
    for (int i = 0; i < n; i++) {
        multiply(entree[i], q0, entree[i]);
    }
}

void creerQ0(int facteurQualite, Mat* q0) {
    /*
    Size S = (*q0).size();
    int w = S.width;
    int h = S.height;
    Mat quantification(h, w, CV_8UC1, Scalar(0));
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < w; j++) {
            quantification.at<uchar>(j, i) = 1 + (i+j+1)*facteurQualite;
            (*q0).at<uchar>(j, i) = round((*q0).at<uchar>(j, i) / quantification.at<uchar>(j, i));
        }
    }*/

    // SI ON SAIT QUE LA MATRICE EST DE TAILLE 8 ET QU'IL FAUT JUSTE LA MODIFIER, CE CODE LA PEUT SUFFIRE
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            q0->at<uchar>(i, j) = 1 + (i + j + 1) * facteurQualite;
        }
    }
}

void divisionMat(Mat* coeff, Mat* q0) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            coeff->at<uchar>(i, j) = round(coeff->at<uchar>(i, j) / ((float)q0->at<uchar>(i, j)));
        }
    }
}