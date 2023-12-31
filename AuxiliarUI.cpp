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

//para leer el anio y que este entre 1985 y 2023
int AuxiliarUI::leerAnio() {
	int numeroIngresado = leerNumero();

	if( numeroIngresado > 1985 && numeroIngresado < 2023)
	{
		return numeroIngresado;
		
	}
	else
	{
		cout << "Digite un anio valido (entre 1985 y 2023): ";
		return leerNumero();
	}
	
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
	cin >> cadena;
	if (cadena != "")
	{
		if (esPhValido(cadena))
		{
			return stod(cadena);
		}
		else
		{
			cout << "Digite un pH valido (entre 0.0 y 14.0): ";
			return leerpH();
		}
	}
	else
	{
		cout << "Digite un pH valido (entre 0.0 y 14.0): ";
		return leerpH();
	}
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