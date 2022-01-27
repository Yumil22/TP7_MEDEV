#include "DCT_converter.h"

//fonction qui convertit l'image RGB en YIQ
Mat DCT_Converter::YIQ_conversion(Mat rgb_matrix)
{
	Mat image_YIQ;
	for (int i = 0; i < rgb_matrix.rows; i++)
	{
		for (int i = 0; i < rgb_matrix.cols; j++)
		{
			image_YIQ.at<Vec3b>(i, j) = rgb_to_yiq * rgb_matrix.at<Vec3b>(i, j);
		}
	}

	return image_YIQ;
}

DCT_Converter::DCT_Converter() {
    float c[N];
    c[0] = 1/sqrt(2);
    for (int i = 1; i < N; i++) {
        c[i] = 1;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dct_matrix.at<float>(i,j) = c[j] * sqrt(2 / N) * cos((2 * i + 1) * j * M_PI / 2 / N);
        }
    }
}

Mat DCT_Converter::openBMP(string fileName) {
    return imread(fileName);
}

vector<Mat> DCT_Converter::getDCTMatrixConverted(string fileName) {
    
}


Mat DCT_Converter::deconvert(vector<Mat> dequantified_matrix){
	Mat DCT_Reverse;
	vector<Mat> DCT_Reverse_Matrixs;
	//Pour chaque bloc de matrices contenu dans le vecteur dequantified_matrix, on applique la DCT inverse, et on stocke les nouveaux blocs dans le vecteur DCT_Reverse_Matrixs
	for (int i=0;i<dequantified_matrix.size();i++){
		Mat DCT_Reverse_Output;
		multiply(dct_matrix, dequantified_matrix[i], DCT_Reverse_Output);
		multiply(DCT_Reverse_Output, t_dct_matrix, DCT_Reverse_Output);
		DCT_Reverse_Matrixs.push_back(DCT_Reverse_Output);
	}
	DCT_Reverse = recombineMatrix(DCT_Reverse_Matrixs);
	DCT_Reverse = RGB_conversion(DCT_Reverse);

	return DCT_Reverse;

}

vector<Mat> DCT_converter::separateMatrix(Mat yiq_matrix) {
	vector<Mat> blocks;
	int n = yiq_matrix.rows/8;
	int p = yiq_matrix.cols/8;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < p; j++) {
			Rect r(i*N, j*N, N, N);
			Mat bloc = yiq_matrix(r).clone();
			blocks.push_back(bloc);
		}
	}

	return blocks;
}