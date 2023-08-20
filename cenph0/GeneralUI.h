#pragma once

#ifndef GeneralUI_H
#define GeneralUI_H

#include <iostream>
#include <string>
#include "AuxiliarUI.h"
#include "EquipoUI.h"

class GeneralUI
{
	private:
		EquipoUI equipoUI;
		AuxiliarUI auxiliarUI;
	public:
		void imprimirMenuGeneral();
		void menuGeneral(int opcion);
		void menuGeneralCompleto();	
};

#endif