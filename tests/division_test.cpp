#include <gtest/gtest.h>
#include "../src/division.cpp"

TEST(DivisionTest, DivisionNormal) {
    EXPECT_EQ(dividir(10, 2), 5);
}

TEST(DivisionTest, ConTruncamiento) {
    EXPECT_EQ(dividir(7, 2), 3);
}

TEST(DivisionTest, NumerosNegativos) {
    EXPECT_EQ(dividir(-10, 2), -5);
}

TEST(DivisionTest, DividendoMenor) {
    EXPECT_EQ(dividir(2, 10), 0);
}

/*
TEST(DivisionTest, DivisionPorCero) {
    EXPECT_THROW(dividir(10, 0), std::invalid_argument);
}*/