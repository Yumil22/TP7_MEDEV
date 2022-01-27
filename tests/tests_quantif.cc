#include <gtest/gtest.h>
#include <quantification.h>

TEST(tests_quantif, test_q0) {
	uint8_t q0testtab[8][8] = {
		{3,5,7,9,11,13,15,17},
		{5,7,9,11,13,15,17,19},
		{7,9,11,13,15,17,19,21},
		{9,11,13,15,17,19,21,23},
		{11,13,15,17,19,21,23,25},
		{13,15,17,19,21,23,25,27},
		{15,17,19,21,23,25,27,29},
		{17,19,21,23,25,27,29,31}
	};
	Mat q0test = Mat::Mat(Size(8, 8), CV_8UC1, &q0testtab);
	Mat q0;
	creerQ0(2, &q0);
	EXPECT_EQ(q0test,q0);
	}

TEST(tests_quantif, test_division) {
	uint8_t diviseurtab[8][8] = {
		{3,5,7,9,11,13,15,17},
		{5,7,9,11,13,15,17,19},
		{7,9,11,13,15,17,19,21},
		{9,11,13,15,17,19,21,23},
		{11,13,15,17,19,21,23,25},
		{13,15,17,19,21,23,25,27},
		{15,17,19,21,23,25,27,29},
		{17,19,21,23,25,27,29,31}
	};
	Mat diviseurtest = Mat::Mat(Size(8, 8), CV_8UC1, &diviseurtab);
	uint8_t dividendetab[8][8] = {
		{1,1,1,9,11,13,15,17},
		{1,1,9,11,13,15,17,19},
		{7,1,11,13,15,17,19,21},
		{9,11,13,15,17,19,21,23},
		{11,13,15,17,19,21,23,25},
		{13,15,17,19,21,23,250,270},
		{15,17,19,21,23,25,270,290},
		{17,19,21,23,25,27,290,310}
	};
	Mat dividendetest = Mat::Mat(Size(8, 8), CV_8UC1, &dividendetab);
	uint8_t resulttesttab[8][8] = {
		{3,5,7,1,1,1,1,1},
		{5,7,1,1,1,1,1,1},
		{1,9,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,0,0},
		{1,1,1,1,1,1,0,0},
		{1,1,1,1,1,1,0,0}
	};
	Mat resulttest = Mat::Mat(Size(8, 8), CV_8UC1, &resulttesttab);
	divisionMat(&dividendetest, &diviseurtest);
	EXPECT_EQ(resulttest, dividendetest);
}