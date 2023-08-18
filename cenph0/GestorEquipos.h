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
    int eliminarEquipo(std::string nombreEquipo);
    bool existeEquipo(std::string nombreEquipo);
    Equipos listarEquipos();
};

#endif
