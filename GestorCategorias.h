#pragma once
#ifndef GestorCategorias_H
#define GestorCategorias_H

#include <iostream>
#include <string>
#include "Categoria.h"
#include "Categorias.h"
#include "CategoriaDAO.h"


class GestorCategorias {
private:
    CategoriaDAO categoriaDAO;
public:
    int insertarCategoria(Categoria categoria);
    int actualizarCategoria(Categoria categoria, Categoria nuevaCategoria);
    int eliminarCategoria(std::string nombreCategoria);
    bool existeCategoria(std::string nombreCategoria);
    Categorias listarCategorias();
    int obtenerIdCategoria(std::string nombreCategoria);
};

#endif
