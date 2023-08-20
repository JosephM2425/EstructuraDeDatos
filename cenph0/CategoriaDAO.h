#pragma once


#ifndef CategoriaDAO_H
#define CategoriaDAO_H

#include <iostream>
#include <string>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include "Categoria.h"
#include "Categorias.h"
#include "Conexion.h"

class CategoriaDAO {
private:
    Conexion conexion;
    sql::Connection* con;
public:
    CategoriaDAO();
    void insertarCategoria(Categoria categoria);
    void actualizarCategoria(Categoria categoria, Categoria nuevaCategoria);
    void eliminarCategoria(std::string nombreCategoria);
    Categorias listarCategorias();
    bool existeCategoria(std::string nombre);
};

#endif

