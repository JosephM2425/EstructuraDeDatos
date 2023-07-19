#ifndef ESTRUCTURADEDATOS_EQUIPOS_H
#define ESTRUCTURADEDATOS_EQUIPOS_H

#include <string>
#include "Equipo.h"

using namespace std;

class Equipos
{
private:
    Equipo* inicio;
    Equipo* final;

public:
    Equipos();
    int Agregar(string nombre, int annio, string descripcion, Categoria categoria, int maxPh, int minPh);
    int Retirar(string nombreEquipo);
    int Modificar(string nombreEquipo);
    Equipo Consultar(string nombreEquipo);
    Equipo Inicio();
    Equipo Final();
    Equipos ListarEquipos(int param, int orden);
    Equipos ListarEquiposBuscarNombre(string hilera);
    Equipos ListarEquiposRangoAnnios(int annioInicial, int annioFinal);
    Equipos ListarEquiposCantSolicitudes(int cantSolicitudes);
    int EliminarEquiposCantSolicitudes(int cantSolicitudes);
};

#endif //ESTRUCTURADEDATOS_EQUIPOS_H
