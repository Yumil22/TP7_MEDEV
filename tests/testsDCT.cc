#include <gtest/gtest.h>
#include "DCT_converted.f"

//Test constructeur DCT_Converted
TEST(Test_Constructeur, DCT_Constr){
	DCT_Converter DCT1;
	EXPECT_EQ(DCT1.getrRGB_to_YIQ(), DCT1.getrYIQ_to_RGB().transpose());
	EXPECT_EQ(DCT1.getrRGB_to_YIQ().cols, 3);
	EXPECT_EQ(DCT1.getrRGB_to_YIQ().rows, 3);
	EXPECT_EQ(DCT1.getL()%8,0);
	EXPECT_EQ(DCT1.getH()%8,0);
}

//