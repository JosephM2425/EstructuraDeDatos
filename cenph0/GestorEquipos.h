#pragma once


#ifndef GestorEquipos_H
#define GestorEquipos_H

#include <iostream>
#include <string>
#include "Equipo.h"
#include "Equipos.h"
#include "EquipoDAO.h"


class GestorEquipos {
private:
    EquipoDAO equipoDAO;
public:
    int insertarEquipo(Equipo equipo);
    int actualizarEquipo(Equipo equipo);
    int alquilerEquipo(Equipo equipo);
    int eliminarEquipo(std::string nombreEquipo);
    bool existeEquipo(std::string nombreEquipo);
    bool equipoDisponible(std::string nombreEquipo);
    int cantSolicitudes(std::string nombreEquipo);
    Equipos listarEquipos();
    Equipos listarEquiposPorCategoria(std::string nombreCategoria);
    Equipos listarEquiposPorEstado(bool estado);
};

#endif
