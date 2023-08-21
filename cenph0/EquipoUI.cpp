#include <iostream>
#include <string>
#include "GestorEquipos.h"
#include "EquipoUI.h"
#include "Equipo.h"
#include "Equipos.h"
#include "AuxiliarUI.h"


void EquipoUI::imprimirMenuEquipos() {
	cout << "[1] Registrar equipo" << endl;
	cout << "[2] Modificar equipo" << endl;
	cout << "[3] Eliminar equipo" << endl;
	cout << "[4] Listar equipos " << endl;
	cout << "[5] Listar por hilera" << endl;
	cout << "[6] Listar equipos por categoria" << endl;
	cout << "[7] Listar equipos por rango de pH" << endl;
	cout << "[8] Listar equipos por rango de anios" << endl;
	cout << "[9] Alquilar equipo" << endl;
	cout << "[10] Devolver equipo" << endl;
	cout << "[11] Regresar" << endl;
	auxiliarUI.digiteOpcion();
}

void EquipoUI::menuEquipos(int opcion) {
	switch (opcion) {
	case 1:
	{
		auxiliarUI.encabezado();
		registrarEquipo();
	}
	break;
	case 2:
	{
		auxiliarUI.encabezado();
		modificarEquipo();
	}
	break;
	case 3:
	{
		auxiliarUI.encabezado();
		eliminarEquipo();
	}
	break;
	case 4:
	{
		auxiliarUI.encabezado();
		listarEquipos();
	}
	break;
	case 5:
	{
		auxiliarUI.encabezado();

	}
	break;
	case 6:
	{
		auxiliarUI.encabezado();

	}
	break;
	case 7:
	{
		auxiliarUI.encabezado();
		listarEquipospH();

	}
	break;
	case 8:
	{
		auxiliarUI.encabezado();
	}
	break;
	case 9:
	{
		auxiliarUI.encabezado();
	}
	break;
	case 10:
	{
		auxiliarUI.encabezado();

	}
	break;
	case 11:
	{

	}
	break;
	default:
		cout << "Opcion invalida" << endl;
	}
}

void EquipoUI::menuEquiposCompleto() {
	int opcion = 0;
	do {
		auxiliarUI.encabezado();
		imprimirMenuEquipos();
		opcion = auxiliarUI.leerNumero();
		menuEquipos(opcion);
	} while (opcion != 5);
}

string EquipoUI::leerNombreEquipo() {
	string nombre;
	getline(cin, nombre);
	if (nombre != "")
	{
		return nombre;
	}
	else
	{
		cout << "Digite el nombre del equipo: ";
		return leerNombreEquipo();
	}
}

Equipo EquipoUI::leerDatosEquipo() {
	cout << "Digite el anio del equipo: ";
	int anio;
	anio = auxiliarUI.leerNumero();
	cout << "Digite la descripcion del equipo: ";
	string descripcion;
	cin >> descripcion;
	cout << "Digite el pH maximo que puede medir el equipo: ";
	double phMaximo;
	phMaximo = auxiliarUI.leerpH();
	cout << "Digite el pH minimo que puede medir el equipo: ";
	double phMinimo;
	phMinimo = auxiliarUI.leerpH();
	cout << "Digite la categoria del equipo: ";
	string categoria;
	cin >> categoria;

	Equipo equipo;
	equipo.annio = anio;
	equipo.descripcion = descripcion;
	equipo.maxPh = phMaximo;
	equipo.minPh = phMinimo;
	equipo.categoria = categoria;
	equipo.estado = false;
	equipo.cantSolicitudes = 0;

	return equipo;
}

void EquipoUI::registrarEquipo() {
	Equipo equipo;
	int resultado;
	do {
		string nombre = leerNombreEquipo();
		equipo = leerDatosEquipo();
		equipo.nombre = nombre;
		resultado = gestorEquipos.insertarEquipo(equipo);
		if (resultado == 1) {
			cout << "Ya existe un equipo con ese nombre. Por favor digite otro nombre." << endl;
		}
		else if (resultado == 2) {
			cout << "Ocurrio un error al registrar el equipo. Por favor intentelo de nuevo." << endl;
		}
		else {
			cout << "El equipo se registro exitosamente." << endl;
		}
	} while (resultado != 0);
}

void EquipoUI::modificarEquipo() {
	Equipo equipo;
	string nombre;
	int resultado;
	bool existeEquipo;
	do {
		do {
			nombre = leerNombreEquipo();
			existeEquipo = gestorEquipos.existeEquipo(nombre);
			if (!existeEquipo) {
				cout << "No existe un equipo con ese nombre. Por favor digite otro nombre." << endl;
			}
		} while (!existeEquipo);
		
		equipo = leerDatosEquipo();
		equipo.nombre = nombre;
		resultado = gestorEquipos.actualizarEquipo(equipo);
		if (resultado == 1) {
			cout << "No existe un equipo con ese nombre. Por favor digite otro nombre." << endl;
		}
		else if (resultado == 2) {
			cout << "Ocurrio un error al actualizar el equipo. Por favor intentelo de nuevo." << endl;
		}
		else {
			cout << "El equipo se actualizo exitosamente." << endl;
		}
	} while (resultado != 0);
}

void EquipoUI::eliminarEquipo() {
	string nombre;
	int resultado;
	bool existeEquipo;
	do {
		do {
			nombre = leerNombreEquipo();
			existeEquipo = gestorEquipos.existeEquipo(nombre);
			if (!existeEquipo) {
				cout << "No existe un equipo con ese nombre. Por favor digite otro nombre." << endl;
			}
		} while (!existeEquipo);

		
		resultado = gestorEquipos.eliminarEquipo(nombre);
		if (resultado == 1) {
			cout << "No existe un equipo con ese nombre. Por favor digite otro nombre." << endl;
		}
		else if (resultado == 2) {
			cout << "Ocurrio un error al eliminar el equipo. Por favor intentelo de nuevo." << endl;
		}
		else {
			cout << "El equipo se elimino exitosamente." << endl;
		}
	} while (resultado != 0);
}

int EquipoUI::leerOpcionParam() {
	int opcionParam = 0;

	cout << "[1] Nombre" << endl;
	cout << "[2] Anio" << endl;
	cout << "Digite el parametro por el cual desea ordenar la lista: ";
	opcionParam = auxiliarUI.leerNumero();
	if (opcionParam == 1 || opcionParam == 2)
	{
		return opcionParam;
	}
	else
	{
		cout << "Opcion invalida. Por favor digite una opcion valida." << endl;
		return leerOpcionParam();
	}
}

int EquipoUI::leerOpcionOrden() {
	int opcionOrden = 0;
	
	cout << "[1] Ascendente" << endl;
	cout << "[2] Descendente" << endl;
	cout << "Digite el orden en el que desea ordenar la lista: " << endl;
	opcionOrden = auxiliarUI.leerNumero();
	if (opcionOrden == 1 || opcionOrden == 2)
	{
		if (opcionOrden == 2) {
			opcionOrden = -1;
		}

		return opcionOrden;
	}
	else
	{
		cout << "Opcion invalida. Por favor digite una opcion valida." << endl;
		return leerOpcionOrden();
	}
}

void EquipoUI::listarEquipos() {
	Equipos listaEquipos = gestorEquipos.listarEquipos();
	int opcionParam = leerOpcionParam();
	int opcionOrden = leerOpcionOrden();
	Equipos listaOrdenada = listaEquipos.ListarEquipos(opcionParam, opcionOrden);
	listaOrdenada.Imprimir();
}



void EquipoUI::listarEquipospH() {
	Equipos listaEquipos = gestorEquipos.listarEquipos();
	double phMinimo = leerpHMin();
	double pHMaximo = leerpHMax();
	Equipos listaOrdenadapH = listaEquipos.ListarEquiposRangopH(phMinimo, pHMaximo);
	listaOrdenadapH.Imprimir();
}

double EquipoUI::leerpHMin() {
	
	cout << "Digite el valor minimo de pH del rango a buscar: ";
	double phMinimo = 0.0;
	phMinimo = auxiliarUI.leerpH();

	return phMinimo;
}

double EquipoUI::leerpHMax() {

	cout << "Digite el valor maximo de pH del rango a buscar: ";
	double pHMaximo = 0.0;
	pHMaximo = auxiliarUI.leerpH();

	return pHMaximo;
}