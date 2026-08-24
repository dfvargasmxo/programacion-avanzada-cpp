// Ejercicio 2:

// Objetivo: el mismo comportamiento del ejercicio 1, pero base y altura
// viven juntos dentro de un objeto Rectangulo, y area(), perimetro() y
// escalar() son metodos de ese objeto: ya no se pasan como parametros
// sueltos, y no existe forma de mezclar la base de un rectangulo con la
// altura de otro.
//
// Usamos struct (no class): en C++ ambas definen una clase en el sentido
// de la sesion de hoy (agrupan atributos y metodos), la diferencia lo veremos la siguiente clase
//
// Salida esperada:
// Area: 50
// Perimetro: 30
// Despues de escalar x2 -> base: 20, altura: 10
//
// Compilar:  g++ -std=c++20 -Wall -Wextra -g ejercicio2_struct_rectangulo.cpp -o bin/ejercicio2
// Ejecutar:  ./bin/ejercicio2

#include <iostream>

struct Rectangulo {
    double base;
    double altura;

    double area() {
        return base * altura;
    }

    double perimetro() {
        return 2 * (base + altura);
    }

    double escalar(double factor) {
        base *= factor;
        altura *= factor;
    }
};

int main() {
    Rectangulo rectangulo{10.0, 5.0};

    std::cout << "Area: " << rectangulo.area() << std::endl;
    std::cout << "Perimetro: " << rectangulo.perimetro() << std::endl;

    rectangulo.escalar(2.0);

    std::cout << "Despues de escalar x2 -> base: "
              << rectangulo.base
              << ", altura: "
              << rectangulo.altura
              << std::endl;

    return 0;
}
