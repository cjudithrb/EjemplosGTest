#include <gtest/gtest.h>
#include "../src/suma.cpp"

// Casos básicos
TEST(SumaTest, NumerosPositivos) {
    EXPECT_EQ(suma(2, 3), 5);
}

TEST(SumaTest, NumerosNegativos) { 
    EXPECT_EQ(suma(-2, -3), -5); 
}

TEST(SumaTest, NumerosNegativosFailed) { 
    EXPECT_EQ(suma(-2, -3), -4); 
}
