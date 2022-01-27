#include "DTC_converter.h"

vector<Mat> DTC_converter::separateMatrix(Mat yiq_matrix) {

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