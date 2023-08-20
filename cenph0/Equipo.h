#ifndef EQUIPO_H
#define EQUIPO_H

#include <string>
#include "Categoria.h"

using namespace std;

class Equipo
{
public:
    Equipo* anterior;
    string nombre;
    int annio;
    string descripcion;
    string categoria; //como prueba
    double maxPh;
    double minPh;
    bool estado;
    int cantSolicitudes;
    Equipo* siguiente;
};

#endif //ESTRUCTURADEDATOS_EQUIPO_H
