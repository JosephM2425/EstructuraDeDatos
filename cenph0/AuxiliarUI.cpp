#include <iostream>
#include <string>
#include "AuxiliarUI.h"

using namespace std;

void AuxiliarUI::encabezado() {
    cout << "==========================================================================" << endl;
    cout << "||                Sistema de Gestion de Equipos | cen-ph0               ||" << endl;
    cout << "==========================================================================" << endl;
}
void AuxiliarUI::encabezadoC() {
	cout << "==========================================================================" << endl;
	cout << "||                Sistema de Gestion de Categorias | cen-ph0               ||" << endl;
	cout << "==========================================================================" << endl;
}


void AuxiliarUI::digiteOpcion() {
    cout << "Digite la opcion que desea: ";
}

int AuxiliarUI::leerNumero() {
	string cadena;
	do {
		cin >> cadena;
		if (!esNumero(cadena)) {
			cout << "Digite un numero valido: ";
		}
	} while (!esNumero(cadena));

	return stoi(cadena);
}

bool AuxiliarUI::esNumero(string cadena) {
	if (cadena.size() == 0)
	{
		return false;
	}

	if (cadena[0] == '-')
	{
		return false;
	}

	for (int i = 0; i < cadena.length(); i++) {
		if (!isdigit(cadena[i])) {
			return false;
		}
	}

	return true;
}

double AuxiliarUI::leerpH() {
	string cadena;
	do {
		cin >> cadena;
		if (!esPhValido(cadena)) {
			cout << "Digite un pH valido (entre 0.0 y 14.0): ";
		}
	} while (!esPhValido(cadena));

	return stod(cadena);
}

bool AuxiliarUI::esPhValido(string cadena) {
	if (cadena.size() == 0)
	{
		return false;
	}

	if (cadena[0] == '-')
	{
		return false;
	}

	bool punto = false;
	for (int i = 0; i < cadena.length(); i++) {
		if (!isdigit(cadena[i])) {
			if (cadena[i] == '.' && !punto) {
				punto = true;
			}
			else {
				return false;
			}
		}
	}

	if (stod(cadena) < 0 || stod(cadena) > 14) {
		return false;
	}

	return true;
}