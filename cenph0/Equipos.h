#ifndef EQUIPOS_H
#define EQUIPOS_H

#include <string>
#include "Equipo.h"
#include "Categoria.h"


using namespace std;

class Equipos
{
private:
    Equipo* inicio;
    Equipo* final;
    int AgregarAnnio(string nombre, int annio, string descripcion, string categoria, double maxPh, double minPh, bool estado, int cantSolicitudes);

public:
    Equipos();
    int Agregar(Equipo nuevo);
    int Retirar(string nombreEquipo);
    int Modificar(string nombre, int annio, string descripcion, string categoria, double maxPh, double minPh, bool estado, int cantSolicitudes);
    Equipo Consultar(string nombreEquipo);
    Equipo Inicio();
    Equipo Final();
    int Cantidad();
    void Imprimir();
    Equipos CopiarLista();
    Equipos ListarEquipos(int param, int orden);
    Equipos ListarEquiposBuscarNombre(string hilera);
    Equipos ListarEquiposRangopH(double pHMinp, double pHMaxp);
    Equipos ListarEquiposRangoAnnios(int annioInicial, int annioFinal);
    Equipos ListarEquiposCantSolicitudes(int cantSolicitudes);
    Equipos EliminarEquiposCantSolicitudes(int cantSolicitudes);
};

#endif
