#pragma once

#ifndef GeneralUI_H
#define GeneralUI_H

#include <iostream>
#include <string>
#include "AuxiliarUI.h"
#include "EquipoUI.h"
#include "CategoriaUI.h"

class GeneralUI
{
	private:
		EquipoUI equipoUI;
		AuxiliarUI auxiliarUI;
		CategoriaUI categoriaUI;
	public:
		void imprimirMenuGeneral();
		void menuGeneral(int opcion);
		void menuGeneralCompleto();	
};

#endif