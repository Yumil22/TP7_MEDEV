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
        
    }
}

Mat DCT_Converter::openBMP(string fileName) {
    return imread(fileName);
}

vector<Mat> DCT_Converter::getDCTMatrixConverted(string fileName) {
    
}