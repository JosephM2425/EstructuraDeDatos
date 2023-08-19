#pragma once


#ifndef EquipoDAO_H
#define EquipoDAO_H

#include <iostream>
#include <string>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include "Equipo.h"
#include "Equipos.h"
#include "Conexion.h"

class EquipoDAO {
private:
    Conexion conexion;
    sql::Connection* con;
public:
    EquipoDAO();
    void insertarEquipo(Equipo equipo);
    void actualizarEquipo(Equipo equipo);
    void eliminarEquipo(std::string nombreEquipo);
    Equipos listarEquipos();
    bool existeEquipo(std::string nombre);
};

#endif

