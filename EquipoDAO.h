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
#include "Categoria.h"
#include "CategoriaDAO.h"

class EquipoDAO {
private:
    Conexion conexion;
    sql::Connection* con;
    CategoriaDAO categoriaDAO;
public:
    EquipoDAO();
    void insertarEquipo(Equipo equipo);
    void actualizarEquipo(Equipo equipo);
    void alquilerEquipo(Equipo equipo);
    void eliminarEquipo(std::string nombreEquipo);
    Equipos listarEquipos();
    Equipos listarEquiposPorEstado(bool estado);
    Equipos listarEquiposPorCategoria(std::string nombreCategoria);
    bool existeEquipo(std::string nombre);
    bool equipoDisponible(std::string nombre);
    int cantSolicitudes(std::string nombre);
};

#endif

