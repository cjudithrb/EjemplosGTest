#include <gtest/gtest.h>
#include <iostream>
#include "../src/objeto.cpp"

TEST(ValidacionTest, PunteroValido) {
    Objeto* ptr = crearObjeto();
    // Si esto falla, no tiene sentido continuar

    std::cout<< "\nINICIO DE LA PRUEBA...\n" << std::endl;
    ASSERT_NE(ptr, nullptr);
    std::cout<< "Puntero no es nulo, continuando con las pruebas..." << std::endl;
    //ASSERT_EQ(ptr, nullptr);
    //EXPECT_EQ(ptr, nullptr);

    // Estas líneas solo se ejecutan si ptr es válido
    EXPECT_EQ(ptr->valor, 100);
    std::cout<< "Valor del objeto es correcto - OK" << std::endl;
    EXPECT_TRUE(ptr->estaActivo());
    std::cout<< "El objeto esta activo - OK\n" << std::endl;
    std::cout<< "FIN DE LA PRUEBA...\n" << std::endl;
    delete ptr;
    
}
