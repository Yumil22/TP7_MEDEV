#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;


void RLCDecompression(string codage, Mat& matrice) {

    bool isValue = true;
    string value = "0";
    int valueInt;
    string count = "0";
    int nombreTraite = 0;
    for (size_t i = 0; i < codage.length(); i++) {
        char car = codage[i];
        if (car == ':') {
            isValue = false;
            //Traitement du nombre
            valueInt = stoi(value);
        }
        else if (car == ',') {
            isValue = true;
            // traitement du nombre
            int countInt = stoi(count);
            // remplir la matrice
            int futurNombreTraite = nombreTraite + countInt;
            int k = 0;
            int n = matrice.rows;
            for (int i = 0; i < 2 * n; ++i) {
                for (int j = (i < n) ? 0 : i - n + 1; j <= i && j < n; ++j) {
                    if (k >= nombreTraite && k < futurNombreTraite) {
                        if (i % 2 == 1) {
                            matrice.at<int>(j, i - j) = valueInt;
                        }
                        else {
                            matrice.at<int>(i-j, j) = valueInt;
                        }
                    }
                    k++;
                }
            }
            nombreTraite = futurNombreTraite;
        }
        else {
            if (isValue) {
                value += car;
            }
            else {
                count += car;
            }
        }
    }

}






