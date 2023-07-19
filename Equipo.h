#ifndef ESTRUCTURADEDATOS_EQUIPO_H
#define ESTRUCTURADEDATOS_EQUIPO_H

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
    Categoria categoria;
    int maxPh;
    int minPh;
    bool estado;
    int cantSolicitudes;
    Equipo* siguiente;
};

#endif //ESTRUCTURADEDATOS_EQUIPO_H
