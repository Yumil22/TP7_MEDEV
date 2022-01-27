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
        
    }
}

Mat DCT_Converter::openBMP(string fileName) {
    return imread(fileName);
}

vector<Mat> DCT_Converter::getDCTMatrixConverted(string fileName) {
    
}