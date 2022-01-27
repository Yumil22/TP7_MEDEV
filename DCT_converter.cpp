#include "DCT_converter.h"

//fonction qui convertit l'image RGB en YIQ
Mat DCT_Converter::YIQ_conversion(Mat rgb_matrix)
{
	Mat image_YIQ;
	float Y,I,Q;
	for (int i = 0; i < rgb_matrix.rows; i++)
	{
		for (int j = 0; j < rgb_matrix.cols; j++)
		{
			for (int l = 0; l < 3; l++)
			{
				Y += rgb_to_yiq.at<float>(0, l) * rgb_matrix.at<Vec3b>(i, j)[l];
				I += rgb_to_yiq.at<float>(1, l) * rgb_matrix.at<Vec3b>(i, j)[l];
				Q += rgb_to_yiq.at<float>(2, l) * rgb_matrix.at<Vec3b>(i, j)[l];
			}
			image_YIQ.at<Vec3b>(i, j)[0] = Y;
			image_YIQ.at<Vec3b>(i, j)[1] = I;
			image_YIQ.at<Vec3b>(i, j)[2] = Q;

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
    Mat image = openBMP(fileName);
    
}


///Pour effectuer la transformée inverse, nous avons récupérer les coordonnée YIQ de chaque bloc, dans des matrices de float, pour pouvoir les multiplier facilement avec les matrices de transformées.
///Ensuite, nous avons restocker chaque valeur de YIQ transformées dans une matrice contenant des vecteurs 3 (matrice image YIQ = DCT_Reverse_Output)
Mat DCT_Converter::deconvert(vector<Mat> dequantified_matrix){
	Mat DCT_Reverse;
	vector<Mat> DCT_Reverse_Matrixs;
	Mat DCT_Reverse_Output;
	Mat DCT_Reverse_Output_Y;
	Mat DCT_Reverse_Output_I;
	Mat DCT_Reverse_Output_Q;
	//Pour chaque bloc de matrices contenu dans le vecteur dequantified_matrix, on applique la DCT inverse, et on stocke les nouveaux blocs dans le vecteur DCT_Reverse_Matrixs
	for (int i=0;i<dequantified_matrix.size();i++){
		for (int j=0;j<dequantified_matrix[i].cols;j++){
			for (int k=0;k<dequantified_matrix[i].rows;k++){
				DCT_Reverse_Output_Y.at<float>(j,k)=dequantified_matrix[i].at<vec3b>(j,k)[0];
				DCT_Reverse_Output_I.at<float>(j,k)=dequantified_matrix[i].at<vec3b>(j,k)[1];
				DCT_Reverse_Output_Q.at<float>(j,k)=dequantified_matrix[i].at<vec3b>(j,k)[2];
			}
		}
		multiply(dct_matrix, DCT_Reverse_Output_Y, DCT_Reverse_Output_Y);
		multiply(dct_matrix, DCT_Reverse_Output_I, DCT_Reverse_Output_I);
		multiply(dct_matrix, DCT_Reverse_Output_Q, DCT_Reverse_Output_Q);

		multiply(DCT_Reverse_Output_Y, t_dct_matrix, DCT_Reverse_Output_Y);
		multiply(DCT_Reverse_Output_I, t_dct_matrix, DCT_Reverse_Output_I);
		multiply(DCT_Reverse_Output_Q, t_dct_matrix, DCT_Reverse_Output_Q);

		for (int j=0;j<dequantified_matrix[i].cols;j++){
			for (int k=0;k<dequantified_matrix[i].rows;k++){
				DCT_Reverse_Output.at<vec3b>(j,k)[0]=DCT_Reverse_Output_Y.at<float>(j,k);
				DCT_Reverse_Output.at<vec3b>(j,k)[1]=DCT_Reverse_Output_I.at<float>(j,k);
				DCT_Reverse_Output.at<vec3b>(j,k)[2]=DCT_Reverse_Output_Q.at<float>(j,k);
			}
		}

		DCT_Reverse_Matrixs.push_back(DCT_Reverse_Output);
	}
	
	DCT_Reverse = recombineMatrix(DCT_Reverse_Matrixs);
	DCT_Reverse = RGB_conversion(DCT_Reverse);

	return DCT_Reverse;

}

/**
 * Sépare la matrice d'entrée en blocs de taille N*N. On suppose que la matrice d'entrée a une taille multiple de N (lignes et colonnes).
 */
vector<Mat> DCT_converter::separateMatrix(Mat yiq_matrix) {
	vector<Mat> blocks;
	int n = yiq_matrix.rows/8;
	int p = yiq_matrix.cols/8;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < p; j++) {
			Rect r(i*N, j*N, N, N);
			// Copie le contenu de la matrice recouvert par le rectangle
			Mat bloc = yiq_matrix(r).clone();
			blocks.push_back(bloc);
		}
	}

	return blocks;
}

//fonction qui convertit l'image YIQ en RGB
Mat DCT_converter::RGB_conversion(Mat yiq_matrix)
{
	Mat image_RGB;
	for (int i = 0; i < yiq_matrix.rows; i++)
	{
		for (int i = 0; i < yiq_matrix.cols; j++)
		{
			image_RGB.at<Vec3b>(i, j) = yiq_to_rgb * yiq_matrix.at<Vec3b>(i, j);
		}
	}

	return image_RGB;
}

