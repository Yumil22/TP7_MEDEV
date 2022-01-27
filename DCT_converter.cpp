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