#pragma once

#ifndef AuxiliarUI_H
#define AuxiliarUI_H

#include <iostream>
#include <string>

class AuxiliarUI
{
public:
	void encabezado();
	void digiteOpcion();
	int leerNumero();
	bool esNumero(std::string cadena);
	double leerpH();
	bool esPhValido(std::string cadena);
};

#endif

