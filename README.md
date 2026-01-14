# Ejemplos Google Test (GTest)

Proyecto estructurado para crear y ejecutar tests unitarios con Google Test.

## Estructura del proyecto

```
EjemplosGTest/
├── README.md
├── .vscode/
│   ├── launch.json
│   └── tasks.json
├── src/
│   └── suma.cpp          # Implementación de funciones
├── tests/
│   └── suma_testb.cpp    # Tests unitarios
└── build/
    └── suma_test.exe     # Ejecutable compilado
```

## Compilar y ejecutar tests

### Opción 1: Usar VS Code (Recomendado)
Presiona **Ctrl + Shift + B** para compilar y ejecutar automáticamente

### Opción 2: Terminal manual
```bash
g++ -std=c++17 tests/suma_test_basic.cpp -o build/suma_test -lgtest -lgtest_main
.\build\suma_test.exe
```

g++ -std=c++17 tests/contrasena_test.cpp -o build/contrasena_test -lgtest -lgtest_main
.\build\contrasena_test.exe

## Cómo agregar nuevas funciones

1. **Crea tu función en `src/`**
   ```cpp
   // src/multiplicacion.cpp
   int multiplicacion(int a, int b) {
       return a * b;
   }
   ```

2. **Crea los tests en `tests/`**
   ```cpp
   // tests/multiplicacion_test.cpp
   #include <gtest/gtest.h>
   #include "../src/multiplicacion.cpp"
   
   TEST(MultiplicacionTest, NumeroPositivos) {
       EXPECT_EQ(multiplicacion(3, 4), 12);
   }
   ```

3. **Compila con Ctrl + Shift + B**

## Estándar C++

Se usa **C++17** por los requisitos de Google Test 1.17.0

## Notas

- Los tests están en `tests/` separados del código fuente
- Los ejecutables compilados van en `build/`
- Cada archivo de test incluye su correspondiente archivo de implementación

