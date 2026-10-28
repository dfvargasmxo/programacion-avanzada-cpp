#include <algorithm>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

// Salida esperada:
// Dias sedentarios: 2
// Dias que cumplieron la meta: 3
// Primer dia que cumplio la meta: dia 4 (7500 pasos)
// Tres mejores dias: 10200 7500 6100
// Pasos en orden original: 4200 1800 3300 7500 2900 10200 6100

// Un dia es sedentario si tiene menos de 3000 pasos.
// TODO: escribe la funcion bool esDiaSedentario(int pasosDelDia).

bool esDiaSedentario(int paso) {
    if (paso < 3000){
        return true;
    } else {
        return false;
    }
}
int main() {
    std::vector<int> pasos = {4200, 1800, 3300, 7500, 2900, 10200, 6100};
    int meta = 5000;

    // TODO: cuenta los dias sedentarios con std::count_if y la funcion
    // esDiaSedentario. Imprime "Dias sedentarios: ".
    int DiasSedentarios = std::count_if(pasos.begin(), pasos.end(), esDiaSedentario);
    std::cout << "Dias sedentarios: " << DiasSedentarios << std::endl;

    // TODO: cuenta los dias con al menos "meta" pasos con std::count_if y
    // una lambda que capture meta. Imprime "Dias que cumplieron la meta: ".
    int diasMeta = std::count_if(pasos.begin(), pasos.end(), [meta](int p){ return p >= meta; });
    std::cout << "Dias que cumplieron la meta: " << diasMeta << std::endl;

    // TODO: con std::find_if y una lambda, busca el primer dia con al
    // menos "meta" pasos. Imprime "Primer dia que cumplio la meta: dia N
    // (P pasos)", con N contando desde 1.
    int primerDiaMeta = std::find_if(pasos.begin(), pasos.end(), [meta](int p){ return p >= meta; }) - pasos.begin() + 1;
    std::cout << "Primer dia que cumplio la meta: dia " << primerDiaMeta << " (" << pasos[primerDiaMeta - 1] << " pasos)" << std::endl;

    // TODO: copia pasos en un vector nuevo llamado ordenados, ordenalo de
    // mayor a menor con std::sort y una lambda de comparacion, e imprime
    // "Tres mejores dias:" con sus tres primeros elementos, cada uno
    // precedido de un espacio.
    std::vector<int> ordenados = {4200, 1800, 3300, 7500, 2900, 10200, 6100};
    std::sort(ordenados.begin(), ordenados.end(), [](int P1, int P2){ return P1 > P2; });
    std::cout << "Tres mejores días: " << ordenados[0] << " " << ordenados[1] << " " << ordenados[2] << std::endl;

    std::cout << "Pasos en orden original:";
    for (int p : pasos) {
        std::cout << " " << p;
    }
    std::cout << std::endl;

    return 0;
}
