#ifndef ESTRUCTURADEDATOS_EQUIPOS_H
#define ESTRUCTURADEDATOS_EQUIPOS_H

#include <string>
#include "Equipo.h"
#include "Categoria.h"


using namespace std;

class Equipos
{
private:
    Equipo* inicio;
    Equipo* final;
    int AgregarAnnio(string nombre, int annio, string descripcion, string categoria, int maxPh, int minPh, bool estado, int cantSolicitudes);

public:
    Equipos();
    int Agregar(string nombre, int annio, string descripcion, string categoria, int maxPh, int minPh);
    int Retirar(string nombreEquipo);
    int Modificar(string nombre, int annio, string descripcion, string categoria, int maxPh, int minPh, bool estado, int cantSolicitudes);
    Equipo Consultar(string nombreEquipo);
    Equipo Inicio();
    Equipo Final();
    int Cantidad();
    void Imprimir();
    Equipos CopiarLista();
    Equipos ListarEquipos(int param, int orden);
    Equipos ListarEquiposBuscarNombre(string hilera);
    Equipos ListarEquiposRangoAnnios(int annioInicial, int annioFinal);
    Equipos ListarEquiposCantSolicitudes(int cantSolicitudes);
    Equipos EliminarEquiposCantSolicitudes(int cantSolicitudes);
};

#endif //ESTRUCTURADEDATOS_EQUIPOS_H
