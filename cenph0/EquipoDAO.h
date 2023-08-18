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

class EquipoDAO {
private:
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* con;

public:
    EquipoDAO(const std::string& host, const std::string& user, const std::string& password, const std::string& schema);
    ~EquipoDAO();

    void insertarEquipo(Equipo equipo);
    void actualizarEquipo(Equipo equipo, int idEquipo);
    void eliminarEquipo(int idEquipo);

};

#endif

