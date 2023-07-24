#include <iostream>
#include <string>
#include "Equipos.h"

using namespace std;

int main() {
    Equipos equipos;

    equipos.Agregar("Ana", 1992, "Hola", "Hola", 7, 3);
    equipos.Agregar("Andrea", 2013, "Hola", "Hola", 5, 3);
    equipos.Agregar("Carolina", 2023, "Hola", "Hola", 6, 5);
    equipos.Agregar("Manuel", 2023, "Hola", "Hola", 6, 5);
    equipos.Agregar("Luis", 2005, "Hola", "Hola", 7, 3);
    equipos.Agregar("Luisa", 1995, "Hola", "Hola", 1, 3);
    equipos.Agregar("NX6000", 1999, "Hola", "Hola", 4, 2);
    equipos.Agregar("Xiomara", 1989, "Hola", "Hola", 7, 3);
    equipos.Imprimir();
    return 0;
}
