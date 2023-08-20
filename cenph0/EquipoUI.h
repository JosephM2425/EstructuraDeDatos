#pragma once

#ifndef EquipoUI_H
#define EquipoUI_H

#include <iostream>
#include <string>
#include "GestorEquipos.h"
#include "Equipo.h"
#include "AuxiliarUI.h"


class EquipoUI
{
	private:
		GestorEquipos gestorEquipos;
		//GeneralUI generalUI;
		AuxiliarUI auxiliarUI;

	public:
		void imprimirMenuEquipos();
		void menuEquipos(int opcion);
		void menuEquiposCompleto();
		std::string leerNombreEquipo();
		Equipo leerDatosEquipo();
		void registrarEquipo();
		void modificarEquipo();
		void eliminarEquipo();
		int leerOpcionParam();
		int leerOpcionOrden();
		void listarEquipos();
};

#endif