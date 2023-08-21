#include <string>
#include "Equipo.h"
#include "Equipos.h"
#include "EquipoDAO.h"
#include "GestorEquipos.h"

int GestorEquipos::insertarEquipo(Equipo equipo) {
	try {
		if (existeEquipo(equipo.nombre)) {
			return 1;
		}
		else {
			equipoDAO.insertarEquipo(equipo);
			return 0;
		}
	}
	catch (exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
		return 2;
	}
}

int GestorEquipos::eliminarEquipo(std::string nombreEquipo) {
	try {
		if (!existeEquipo(nombreEquipo)) {
			return 1;
		}
		else {
			equipoDAO.eliminarEquipo(nombreEquipo);
			return 0;
		}
	}
	catch (exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
		return 2;
	}
}

int GestorEquipos::actualizarEquipo(Equipo equipo) {
	try {
		if (!existeEquipo(equipo.nombre)) {
			return 1;
		}
		else {
			equipoDAO.actualizarEquipo(equipo);
			return 0;
		}
	}
	catch (exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
		return 2;
	}
}

int GestorEquipos::alquilerEquipo(Equipo equipo) {
	try {
		if (!existeEquipo(equipo.nombre)) {
			return 1;
		}
		else {
			equipoDAO.alquilerEquipo(equipo);
			return 0;
		}
	}
	catch (exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
		return 2;
	}
}

bool GestorEquipos::existeEquipo(std::string nombreEquipo) {
	return equipoDAO.existeEquipo(nombreEquipo);
}

Equipos GestorEquipos::listarEquipos() {
	return equipoDAO.listarEquipos();
}