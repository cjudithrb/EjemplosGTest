# 📝 EJERCICIOS PRÁCTICOS: UNIT TESTS CON GTEST

## Información del curso
**Asignatura:** Ingeniería de Software  
**Tema:** Pruebas Unitarias con Google Test (GTest)  
**Docente:** Mg. Judiht Rojas  
**Objetivo:** Aplicar los conceptos de testing unitario en casos prácticos reales

---

## 📚 Instrucciones Generales

Para cada ejercicio deberás:

1. **Analizar** la función proporcionada e identificar todos los casos de prueba posibles
2. **Implementar** la función en C++ siguiendo las especificaciones
3. **Escribir** una suite completa de tests usando GTest que cubra:
   - Casos normales (happy path)
   - Casos edge (límites, valores especiales)
   - Casos de error (entradas inválidas)
4. **Documentar** qué está probando cada test con nombres descriptivos
5. **Ejecutar** los tests y verificar que todos pasen

### Criterios de evaluación:
- ✅ **Cobertura completa** de casos (30%)
- ✅ **Nombres descriptivos** en tests (20%)
- ✅ **Uso correcto** de EXPECT vs ASSERT (20%)
- ✅ **Código funcional** que compile y ejecute (20%)
- ✅ **Buenas prácticas** (un test = un comportamiento) (10%)

---

## 🟢 NIVEL BÁSICO

### **Ejercicio 1: Calculadora Básica**

#### Especificación:
Implementa las siguientes funciones matemáticas básicas:

```cpp
int sumar(int a, int b);
int restar(int a, int b);
int multiplicar(int a, int b);
double dividir(int a, int b);  // Lanza excepción si b == 0
```

#### Casos de prueba a considerar:
- Números positivos
- Números negativos
- Uno o ambos operandos en cero
- División por cero (debe lanzar `std::invalid_argument`)
- Resultado con truncamiento (división)

#### Tests mínimos esperados: 12-15

**Ejemplo de test:**
```cpp
TEST(CalculadoraTest, SumaPositivos) {
    EXPECT_EQ(sumar(5, 3), 8);
}

TEST(CalculadoraTest, DivisionPorCero) {
    EXPECT_THROW(dividir(10, 0), std::invalid_argument);
}
```

---

### **Ejercicio 2: Validador de Email**

#### Especificación:
Implementa una función que valide si un email es válido según estos criterios:

```cpp
bool esEmailValido(const std::string& email);
```

**Reglas de validación:**
- Debe contener exactamente un símbolo `@`
- Debe tener al menos un carácter antes del `@`
- Debe tener al menos un carácter después del `@`
- Debe contener al menos un punto `.` después del `@`
- No debe tener espacios en blanco
- No debe estar vacío

#### Casos de prueba a considerar:
- Email válido típico: `usuario@dominio.com`
- Sin `@`: `usuariodominio.com`
- Múltiples `@`: `usuario@@dominio.com`
- Sin parte local: `@dominio.com`
- Sin dominio: `usuario@`
- Sin punto en dominio: `usuario@dominio`
- Con espacios: `usuario @dominio.com`
- Email vacío: `""`
- Solo espacios: `"   "`

#### Tests mínimos esperados: 10-12

**Pista:** Puedes usar funciones de `<string>` como `find()`, `find_first_of()`, `substr()`

---

### **Ejercicio 3: Clasificador de Notas**

#### Especificación:
Implementa una función que clasifique notas numéricas en categorías:

```cpp
std::string clasificarNota(int puntaje);
```

**Escala de clasificación:**
- 90-100: "Excelente"
- 80-89: "Muy Bueno"
- 70-79: "Bueno"
- 60-69: "Suficiente"
- 0-59: "Insuficiente"
- Fuera de rango (< 0 o > 100): Lanzar `std::out_of_range`

#### Casos de prueba a considerar:
- Cada categoría (al menos un valor en el rango)
- Límites exactos (90, 89, 80, 79, 70, 69, 60, 59, 0)
- Valores negativos
- Valores mayores a 100
- Valores extremos (-1000, 1000)

#### Tests mínimos esperados: 15-18

**Nota importante:** Presta especial atención a los valores límite (boundary values). Un puntaje de 89 debe dar "Muy Bueno", pero 90 debe dar "Excelente".

---

## 🟡 NIVEL INTERMEDIO

### **Ejercicio 4: Calculadora de Edad**

#### Especificación:
Implementa una función que calcule la edad en años dado un año de nacimiento:

```cpp
int calcularEdad(int anioNacimiento, int anioActual = 2026);
```

**Reglas:**
- Si `anioNacimiento` es mayor que `anioActual`: lanzar `std::invalid_argument` ("Año de nacimiento no puede ser futuro")
- Si `anioNacimiento` es menor a 1900: lanzar `std::invalid_argument` ("Año de nacimiento no válido")
- Si `anioActual` es menor a 1900: lanzar `std::invalid_argument` ("Año actual no válido")
- Retornar la edad calculada como `anioActual - anioNacimiento`

#### Casos de prueba a considerar:
- Persona recién nacida (anioActual == anioNacimiento)
- Niño (edad < 18)
- Adulto (edad entre 18-65)
- Adulto mayor (edad > 65)
- Año de nacimiento en el futuro
- Año de nacimiento antes de 1900
- Año actual inválido
- Usar valor por defecto vs especificar año actual

#### Tests mínimos esperados: 12-15

**Ejemplo de test con valor por defecto:**
```cpp
TEST(EdadTest, UsaAnioActualPorDefecto) {
    EXPECT_EQ(calcularEdad(2000), 26);  // Asume año actual 2026
}
```

---

### **Ejercicio 5: Conversor de Temperatura**

#### Especificación:
Implementa funciones para convertir entre Celsius, Fahrenheit y Kelvin:

```cpp
double celsiusAFahrenheit(double celsius);
double fahrenheitACelsius(double fahrenheit);
double celsiusAKelvin(double celsius);
double kelvinACelsius(double kelvin);
```

**Fórmulas:**
- Celsius a Fahrenheit: `F = C × 9/5 + 32`
- Fahrenheit a Celsius: `C = (F - 32) × 5/9`
- Celsius a Kelvin: `K = C + 273.15`
- Kelvin a Celsius: `C = K - 273.15`

**Restricciones:**
- Kelvin no puede ser negativo. Si el resultado sería < 0, lanzar `std::invalid_argument` ("Temperatura bajo cero absoluto")
- Para comparaciones de doubles, usar tolerancia: `EXPECT_NEAR(valor, esperado, 0.01)`

#### Casos de prueba a considerar:
- Puntos de referencia conocidos:
  - Punto de congelación del agua: 0°C = 32°F = 273.15K
  - Punto de ebullición del agua: 100°C = 212°F = 373.15K
  - Cero absoluto: -273.15°C = -459.67°F = 0K
- Temperaturas negativas en Celsius
- Conversiones que resultarían en Kelvin negativo (error)
- Temperaturas decimales
- Conversión ida y vuelta (C→F→C debe dar el mismo valor)

#### Tests mínimos esperados: 15-20

**Ejemplo con tolerancia:**
```cpp
TEST(TemperaturaTest, CelsiusAFahrenheit_Congelacion) {
    EXPECT_NEAR(celsiusAFahrenheit(0.0), 32.0, 0.01);
}
```

---

### **Ejercicio 6: Validador de Fecha**

#### Especificación:
Implementa una función que valide si una fecha es válida:

```cpp
bool esFechaValida(int dia, int mes, int anio);
```

**Reglas:**
- Mes debe estar entre 1 y 12
- Año debe ser positivo (> 0)
- Día debe ser válido según el mes:
  - Enero, Marzo, Mayo, Julio, Agosto, Octubre, Diciembre: 1-31
  - Abril, Junio, Septiembre, Noviembre: 1-30
  - Febrero: 1-28 (o 1-29 en años bisiestos)
- **Año bisiesto:** divisible por 4, EXCEPTO los divisibles por 100, EXCEPTO los divisibles por 400
  - Ejemplos: 2000 es bisiesto, 1900 NO es bisiesto, 2024 es bisiesto

#### Casos de prueba a considerar:
- Fechas válidas en cada mes
- 31 de febrero (inválido)
- 30 de febrero (inválido)
- 29 de febrero en año bisiesto (válido: 2024)
- 29 de febrero en año NO bisiesto (inválido: 2023)
- Meses inválidos (0, 13, -1)
- Días inválidos (0, -5, 32)
- Años inválidos (0, -2000)
- Casos especiales de años bisiestos:
  - 2000 (divisible por 400): bisiesto
  - 1900 (divisible por 100, no por 400): NO bisiesto
  - 2024 (divisible por 4, no por 100): bisiesto

#### Tests mínimos esperados: 20-25

**Función auxiliar sugerida:**
```cpp
bool esAnioBisiesto(int anio) {
    if (anio % 400 == 0) return true;
    if (anio % 100 == 0) return false;
    if (anio % 4 == 0) return true;
    return false;
}
```

---

## 🔴 NIVEL AVANZADO

### **Ejercicio 7: Analizador de Cadenas**

#### Especificación:
Implementa una clase `AnalizadorCadenas` con los siguientes métodos:

```cpp
class AnalizadorCadenas {
public:
    AnalizadorCadenas(const std::string& texto);
    
    int contarPalabras() const;
    int contarVocales() const;
    int contarConsonantes() const;
    bool esPalindromo() const;  // Ignora espacios y mayúsculas
    std::string invertir() const;
    int frecuenciaCaracter(char c) const;  // Case-insensitive
};
```

#### Casos de prueba a considerar:

**contarPalabras():**
- Texto vacío
- Una palabra
- Múltiples palabras separadas por espacios
- Espacios múltiples entre palabras
- Espacios al inicio/final

**contarVocales() / contarConsonantes():**
- Solo vocales
- Solo consonantes
- Mezcla de ambos
- Con mayúsculas y minúsculas
- Con números y símbolos (no deberían contarse)

**esPalindromo():**
- Palíndromos simples: "oso", "anilina"
- Palíndromos con espacios: "anita lava la tina"
- Palíndromos con mayúsculas: "A man a plan a canal Panama"
- No palíndromos
- Cadena vacía (considerar palindromo)
- Una letra (palindromo)

**invertir():**
- Cadena normal
- Cadena vacía
- Una letra
- Con espacios

**frecuenciaCaracter():**
- Carácter que aparece múltiples veces
- Carácter que no aparece
- Case-insensitive ('A' y 'a' cuentan juntos)

#### Tests mínimos esperados: 25-30

**Ejemplo de test de clase:**
```cpp
TEST(AnalizadorCadenasTest, ContarPalabras_TextoSimple) {
    AnalizadorCadenas analizador("Hola mundo");
    EXPECT_EQ(analizador.contarPalabras(), 2);
}

TEST(AnalizadorCadenasTest, EsPalindromo_ConEspacios) {
    AnalizadorCadenas analizador("anita lava la tina");
    EXPECT_TRUE(analizador.esPalindromo());
}
```

---

### **Ejercicio 8: Sistema de Carrito de Compras**

#### Especificación:
Implementa una clase `CarritoCompras` que maneje productos y calcule totales:

```cpp
struct Producto {
    std::string nombre;
    double precio;
    int cantidad;
};

class CarritoCompras {
public:
    void agregarProducto(const std::string& nombre, double precio, int cantidad);
    void eliminarProducto(const std::string& nombre);
    void actualizarCantidad(const std::string& nombre, int nuevaCantidad);
    
    double calcularSubtotal() const;
    double calcularImpuesto(double tasaImpuesto) const;  // Ej: 0.18 para 18%
    double calcularTotal(double tasaImpuesto) const;
    
    int contarProductos() const;  // Número de líneas de productos
    int contarUnidades() const;   // Suma de todas las cantidades
    
    bool estaVacio() const;
    void vaciar();
    
    bool contieneProducto(const std::string& nombre) const;
    Producto obtenerProducto(const std::string& nombre) const;
};
```

**Reglas de negocio:**
- Precio debe ser > 0, si no lanzar `std::invalid_argument`
- Cantidad debe ser > 0, si no lanzar `std::invalid_argument`
- Si se elimina un producto que no existe, lanzar `std::runtime_error`
- Si se actualiza cantidad de producto inexistente, lanzar `std::runtime_error`
- Si se intenta obtener producto inexistente, lanzar `std::runtime_error`
- La tasa de impuesto debe estar entre 0.0 y 1.0, si no lanzar `std::invalid_argument`

#### Casos de prueba a considerar:

**Agregar productos:**
- Agregar un producto nuevo
- Agregar producto con precio inválido (negativo, cero)
- Agregar producto con cantidad inválida (negativa, cero)
- Agregar múltiples productos

**Eliminar productos:**
- Eliminar producto existente
- Eliminar producto inexistente (debe lanzar error)
- Eliminar de carrito vacío

**Actualizar cantidad:**
- Actualizar a cantidad mayor
- Actualizar a cantidad menor
- Actualizar a cantidad inválida
- Actualizar producto inexistente

**Cálculos:**
- Subtotal con un producto
- Subtotal con múltiples productos
- Impuesto con diferentes tasas (18%, 10%, 0%)
- Total = subtotal + impuesto
- Tasa de impuesto inválida (< 0 o > 1)

**Estado del carrito:**
- Carrito vacío
- Contar productos vs contar unidades (3 productos con 2 unidades c/u = 3 productos, 6 unidades)
- Vaciar carrito
- Verificar si contiene producto específico

#### Tests mínimos esperados: 30-35

**Ejemplo de test con fixture:**
```cpp
class CarritoComprasTest : public ::testing::Test {
protected:
    void SetUp() override {
        carrito.agregarProducto("Laptop", 1200.00, 1);
        carrito.agregarProducto("Mouse", 25.50, 2);
    }
    
    CarritoCompras carrito;
};

TEST_F(CarritoComprasTest, CalculaSubtotalCorrectamente) {
    // 1200 + (25.50 * 2) = 1251.00
    EXPECT_NEAR(carrito.calcularSubtotal(), 1251.00, 0.01);
}

TEST_F(CarritoComprasTest, CalculaImpuesto18Porciento) {
    double subtotal = 1251.00;
    double impuesto = carrito.calcularImpuesto(0.18);
    EXPECT_NEAR(impuesto, subtotal * 0.18, 0.01);
}
```

---

### **Ejercicio 9: Sistema de Reservas de Hotel**

#### Especificación:
Implementa un sistema que gestione reservas de habitaciones:

```cpp
struct Fecha {
    int dia;
    int mes;
    int anio;
};

enum class TipoHabitacion {
    SIMPLE,
    DOBLE,
    SUITE
};

class SistemaReservas {
public:
    SistemaReservas(int numeroHabitaciones);
    
    bool reservarHabitacion(int numHabitacion, const Fecha& checkIn, 
                           const Fecha& checkOut, TipoHabitacion tipo);
    
    bool cancelarReserva(int numHabitacion, const Fecha& checkIn);
    
    bool habitacionDisponible(int numHabitacion, const Fecha& checkIn, 
                             const Fecha& checkOut) const;
    
    double calcularCosto(TipoHabitacion tipo, int numNoches) const;
    
    int contarReservasActivas() const;
    
    std::vector<int> obtenerHabitacionesDisponibles(const Fecha& checkIn,
                                                     const Fecha& checkOut) const;
};
```

**Reglas de negocio:**
- Precios por noche: SIMPLE=$50, DOBLE=$80, SUITE=$150
- CheckOut debe ser posterior a CheckIn
- Número de habitación debe ser válido (1 a numeroHabitaciones)
- No se pueden hacer reservas solapadas en la misma habitación
- No se pueden hacer reservas en fechas pasadas (comparar con fecha actual)
- Mínimo 1 noche de estadía

#### Casos de prueba a considerar:

**Validación de fechas:**
- CheckIn posterior a CheckOut (inválido)
- CheckIn igual a CheckOut (inválido, mínimo 1 noche)
- Fechas válidas
- Fechas inválidas (31 de febrero)

**Reservas:**
- Reserva exitosa en habitación disponible
- Reserva en habitación ocupada (solapamiento total)
- Reserva con solapamiento parcial (inicio o fin)
- Reserva en habitación inexistente
- Reservas consecutivas sin solapamiento (deben ser posibles)

**Cancelaciones:**
- Cancelar reserva existente
- Cancelar reserva inexistente
- Cancelar en habitación incorrecta

**Disponibilidad:**
- Habitación completamente libre
- Habitación ocupada
- Múltiples habitaciones disponibles

**Cálculos de costo:**
- 1 noche en cada tipo de habitación
- Múltiples noches (5 noches en SUITE = $750)
- Validar cálculo con diferentes tipos

#### Tests mínimos esperados: 25-30

**Función auxiliar para comparar fechas:**
```cpp
bool esFechaPosterior(const Fecha& f1, const Fecha& f2) {
    if (f1.anio != f2.anio) return f1.anio > f2.anio;
    if (f1.mes != f2.mes) return f1.mes > f2.mes;
    return f1.dia > f2.dia;
}
```

---

### **Ejercicio 10: Validador de Contraseñas Avanzado** ⭐

#### Especificación:
Implementa un validador de contraseñas con múltiples niveles de seguridad:

```cpp
enum class NivelSeguridad {
    MUY_DEBIL,
    DEBIL,
    MEDIA,
    FUERTE,
    MUY_FUERTE
};

class ValidadorPassword {
public:
    static bool cumpleRequisitosMinimos(const std::string& password);
    static NivelSeguridad evaluarSeguridad(const std::string& password);
    static std::vector<std::string> obtenerSugerencias(const std::string& password);
    static int calcularPuntuacion(const std::string& password);
    static bool esPasswordComun(const std::string& password);
};
```

**Requisitos mínimos:**
- Al menos 8 caracteres
- Al menos una mayúscula
- Al menos una minúscula
- Al menos un número
- Al menos un carácter especial (!@#$%^&*()_+-=[]{}|;:,.<>?)

**Sistema de puntuación (0-100):**
- Longitud: +1 punto por cada carácter (max 20 puntos)
- Mayúsculas: +10 puntos si tiene al menos una
- Minúsculas: +10 puntos si tiene al menos una
- Números: +10 puntos si tiene al menos uno
- Caracteres especiales: +15 puntos si tiene al menos uno
- Diversidad: +15 puntos si tiene más de 3 tipos diferentes de caracteres
- Longitud > 12: +10 puntos bonus
- Longitud > 16: +10 puntos bonus adicional

**Niveles de seguridad:**
- 0-20 puntos: MUY_DEBIL
- 21-40 puntos: DEBIL
- 41-60 puntos: MEDIA
- 61-80 puntos: FUERTE
- 81-100 puntos: MUY_FUERTE

**Contraseñas comunes a rechazar:**
- "password", "123456", "qwerty", "abc123", "password123"
- "admin", "letmein", "welcome", "monkey", "dragon"
(Lista completa a tu criterio)

**Sugerencias:**
- Si falta longitud: "Usa al menos 8 caracteres"
- Si falta mayúscula: "Agrega al menos una letra mayúscula"
- Si falta minúscula: "Agrega al menos una letra minúscula"
- Si falta número: "Incluye al menos un número"
- Si falta especial: "Incluye al menos un carácter especial"
- Si es común: "Esta contraseña es muy común, elige otra"

#### Casos de prueba a considerar:

**Requisitos mínimos:**
- Password que cumple todo
- Falta cada requisito individualmente
- Falta múltiples requisitos
- Password vacía
- Solo espacios

**Nivel de seguridad:**
- Password muy débil (< 4 caracteres, solo letras)
- Password débil (8 caracteres, solo letras y números)
- Password media (10 caracteres, letras, números, mayúsculas)
- Password fuerte (12 caracteres, todos los tipos)
- Password muy fuerte (16+ caracteres, alta diversidad)

**Sugerencias:**
- Password sin mayúsculas debe sugerir agregar mayúsculas
- Password corta debe sugerir más caracteres
- Password común debe advertir
- Password fuerte no debe dar sugerencias (lista vacía)

**Contraseñas comunes:**
- Cada contraseña de la lista común debe ser rechazada
- Variaciones con números ("password123") deben ser rechazadas
- Contraseñas únicas deben pasar

**Puntuación:**
- Password mínima válida (8 chars, todos requisitos) ~60 puntos
- Password ideal (16+ chars, alta diversidad) ~95-100 puntos
- Verificar bonificaciones por longitud

#### Tests mínimos esperados: 35-40

**Ejemplo de tests:**
```cpp
TEST(ValidadorPasswordTest, CumpleRequisitosMinimos_PasswordFuerte) {
    EXPECT_TRUE(ValidadorPassword::cumpleRequisitosMinimos("P@ssw0rd!"));
}

TEST(ValidadorPasswordTest, NivelSeguridad_MuyFuerte) {
    std::string pwd = "MyV3ry$ecur3P@ssw0rd!2024";
    EXPECT_EQ(ValidadorPassword::evaluarSeguridad(pwd), NivelSeguridad::MUY_FUERTE);
}

TEST(ValidadorPasswordTest, PasswordComun_Rechazada) {
    EXPECT_TRUE(ValidadorPassword::esPasswordComun("password123"));
}

TEST(ValidadorPasswordTest, Sugerencias_SinMayuscula) {
    auto sugerencias = ValidadorPassword::obtenerSugerencias("passw0rd!");
    EXPECT_FALSE(sugerencias.empty());
    
    bool tieneSugerenciaMayuscula = false;
    for (const auto& sug : sugerencias) {
        if (sug.find("mayúscula") != std::string::npos) {
            tieneSugerenciaMayuscula = true;
        }
    }
    EXPECT_TRUE(tieneSugerenciaMayuscula);
}
```

---

## 📦 EJERCICIO INTEGRADOR (Proyecto Final)

### **Ejercicio 11: Sistema Bancario Completo**

#### Especificación:
Crea un sistema bancario con las siguientes clases:

```cpp
class Cuenta {
protected:
    std::string numeroCuenta;
    std::string titular;
    double saldo;
    std::vector<std::string> historialTransacciones;
    
public:
    Cuenta(const std::string& numero, const std::string& titular, double saldoInicial);
    virtual ~Cuenta() = default;
    
    virtual bool depositar(double monto);
    virtual bool retirar(double monto);
    bool transferir(Cuenta& destino, double monto);
    
    double consultarSaldo() const;
    std::string consultarTitular() const;
    std::vector<std::string> obtenerHistorial() const;
};

class CuentaAhorros : public Cuenta {
private:
    double tasaInteres;  // Ej: 0.05 para 5% anual
    int retirosGratis;
    int retirosRealizados;
    
public:
    CuentaAhorros(const std::string& numero, const std::string& titular, 
                  double saldoInicial, double tasa);
    
    bool retirar(double monto) override;  // Cobra $5 después de retirosGratis
    void aplicarIntereses();  // Aplica tasa de interés al saldo
    void resetearRetirosGratis();  // Reinicia contador mensual
};

class CuentaCorriente : public Cuenta {
private:
    double limiteCredito;  // Puede estar en negativo hasta este límite
    double comisionMantenimiento;
    
public:
    CuentaCorriente(const std::string& numero, const std::string& titular,
                   double saldoInicial, double limite);
    
    bool retirar(double monto) override;  // Permite saldo negativo hasta límite
    void cobrarMantenimiento();  // Cobra comisión mensual
    double consultarDisponible() const;  // Saldo + crédito disponible
};

class Banco {
private:
    std::vector<std::unique_ptr<Cuenta>> cuentas;
    
public:
    void abrirCuenta(std::unique_ptr<Cuenta> cuenta);
    Cuenta* buscarCuenta(const std::string& numeroCuenta);
    bool cerrarCuenta(const std::string& numeroCuenta);
    
    int contarCuentas() const;
    int contarCuentasAhorros() const;
    int contarCuentasCorrientes() const;
    
    double totalDineroEnBanco() const;
};
```

**Reglas de negocio:**

**Cuenta base:**
- Saldo inicial debe ser >= 0
- Depósito debe ser > 0
- Retiro debe ser > 0 y <= saldo
- Transferencia debe cumplir reglas de retiro en origen y depósito en destino
- Historial registra todas las operaciones

**Cuenta Ahorros:**
- Tasa de interés entre 0% y 15% (0.0 - 0.15)
- 3 retiros gratis por mes, luego $5 por retiro
- Aplicar intereses aumenta saldo en saldo * tasaInteres
- No puede tener saldo negativo

**Cuenta Corriente:**
- Límite de crédito >= 0
- Puede retirar hasta saldo + límiteCredito
- Comisión mantenimiento: $10/mes
- Consultar disponible = saldo + crédito no usado

**Banco:**
- No puede haber dos cuentas con mismo número
- Cerrar cuenta solo si saldo == 0
- Total dinero = suma de todos los saldos (positivos y negativos)

#### Casos de prueba sugeridos:

**Cuenta base (20 tests):**
- Crear cuenta con datos válidos/inválidos
- Depositar montos válidos/inválidos
- Retirar con saldo suficiente/insuficiente
- Transferir entre cuentas
- Verificar historial de transacciones

**Cuenta Ahorros (15 tests):**
- Retiros dentro del límite gratuito
- Retiros que cobran comisión
- Aplicar intereses correctamente
- Resetear contador de retiros
- Validar tasa de interés

**Cuenta Corriente (15 tests):**
- Retiros dentro del saldo
- Retiros usando crédito
- Retiros que exceden límite total
- Cobro de mantenimiento
- Consultar disponible en diferentes escenarios

**Banco (20 tests):**
- Abrir cuentas de diferentes tipos
- Buscar cuentas existentes/inexistentes
- Cerrar cuentas con saldo cero/diferente de cero
- Contar cuentas por tipo
- Calcular total de dinero
- Prevenir duplicados de número de cuenta

#### Tests mínimos esperados: 