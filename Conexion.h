#pragma once


#ifndef Conexion_H
#define Conexion_H

#include <iostream>
#include <string>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include "Equipo.h"

class Conexion {
private:
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* con;
    std::string host;
    std::string user;
    std::string password;
    std::string schema;

public:
    Conexion();
    ~Conexion();

    sql::Connection* obtenerConexion();
};

#endif
