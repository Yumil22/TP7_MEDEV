#include <gtest/gtest.h>
#include "compression_rlc.h"

TEST(Tester_la_bonne_lecture_de_la_matrice, size_vecteur_intermediaire) {
	cv::Mat im = cv::Mat(8, 8, CV_8UC3);
	std::vector<int> v = lecture(im);
	ASSERT_TRUE(v.size() == (64 * 3));
}