#include <gtest/gtest.h>
#include "../src/suma.cpp"

// Casos básicos
TEST(SumaTest, NumerosPositivos) {
    EXPECT_EQ(suma(2, 3), 5);
}
