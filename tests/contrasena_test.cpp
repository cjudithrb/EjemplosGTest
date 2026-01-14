#include <gtest/gtest.h>
#include "../src/contrasena.cpp"

// Test 1: Contraseña muy corta
TEST(PasswordTest, MuyCorta) {
    EXPECT_FALSE(esPasswordSegura("Ab1"));
}

// Test 2: Sin mayúscula
TEST(PasswordTest, SinMayuscula) {
    EXPECT_FALSE(esPasswordSegura("password123"));
}

// Test 3: Sin número
TEST(PasswordTest, SinNumero) {
    EXPECT_FALSE(esPasswordSegura("Password"));
}

// Test 4: Contraseña válida
TEST(PasswordTest, Valida) {
    EXPECT_TRUE(esPasswordSegura("Password123"));
}