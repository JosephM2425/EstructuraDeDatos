#include <iostream>
#include <string>
#include "GeneralUI.h"
#include "EquipoUI.h"
#include "AuxiliarUI.h"

using namespace std;

void GeneralUI::imprimirMenuGeneral() {
	cout << "[1] Equipos" << endl;
	cout << "[2] Categorias" << endl;
	cout << "[3] Salir" << endl;
	auxiliarUI.digiteOpcion();
}

void GeneralUI::menuGeneral(int opcion) {
	switch (opcion) {
	case 1:
	{
		equipoUI.menuEquiposCompleto();
	}
	break;
	case 2:
	{

	}
	break;
	case 3:
	{
		cout << "Gracias por usar el sistema." << endl;
		exit(0);
	}
	break;
	default:
		cout << "Opcion invalida." << endl;
	}
}

void GeneralUI::menuGeneralCompleto() {
	int opcion = 0;
	do {
		auxiliarUI.encabezado();
		imprimirMenuGeneral();
		opcion = auxiliarUI.leerNumero();
		menuGeneral(opcion);
	} while (opcion != 3);
}