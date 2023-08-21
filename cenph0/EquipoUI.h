#pragma once

#ifndef EquipoUI_H
#define EquipoUI_H

#include <iostream>
#include <string>
#include "GestorEquipos.h"
#include "GestorCategorias.h"
#include "EquipoUI.h"
#include "Equipo.h"
#include "Equipos.h"
#include "Categoria.h"
#include "Categorias.h"
#include "AuxiliarUI.h"

class EquipoUI
{
private:
	GestorEquipos gestorEquipos;
	GestorCategorias gestorCategorias;
	AuxiliarUI auxiliarUI;

public:
	void imprimirMenuEquipos();
	void menuEquipos(int opcion);
	void menuEquiposCompleto();
	std::string leerNombreEquipo();
	Equipo leerDatosEquipo();
	void registrarEquipo();
	void modificarEquipo();
	void alquilarEquiipo();
	void eliminarEquipo();
	int leerOpcionParam();
	int leerOpcionOrden();
	std::string leerOpcionCategoria();
	void listarEquipos();
	void listarEquiposPorCategoria();
	void listarEquiposPorEstado(bool estado);
	void listarEquipospH();
	double leerpHMin();
	double leerpHMax();
};

#endif