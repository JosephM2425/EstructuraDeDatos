#pragma once
#ifndef CategoriaUI_H
#define CategoriaUI_H

#include <iostream>
#include <string>
#include "GestorCategorias.h"
#include "Categoria.h"
#include "AuxiliarUI.h"


class CategoriaUI{
private:
	GestorCategorias gestorCategorias;
	AuxiliarUI auxiliarUI;

public:
	void imprimirMenuCategorias();
	void menuCategorias(int opcion);
	void menuCategoriasCompleto();
	std::string leerNombreCategoria();
	void registrarCategoria();
	void modificarCategoria();
	void eliminarCategoria();
	int leerOpcionOrden();
	int leerOpcionParam();
	int leerOpcionOrden();
	void listarCategorias();
};

#endif