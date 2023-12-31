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

void EquipoUI::imprimirMenuEquipos()
{
	cout << "[1] Registrar equipo" << endl;
	cout << "[2] Modificar equipo" << endl;
	cout << "[3] Eliminar equipo" << endl;
	cout << "[4] Listar equipos " << endl;
	cout << "[5] Listar por hilera en el nombre" << endl;
	cout << "[6] Listar equipos por categoria" << endl;
	cout << "[7] Listar equipos por rango de pH" << endl;
	cout << "[8] Listar equipos por rango de anios" << endl;
	cout << "[9] Alquilar equipo" << endl;
	cout << "[10] Devolver equipo" << endl;
	cout << "[11] Regresar" << endl;
	auxiliarUI.digiteOpcion();
}

void EquipoUI::menuEquipos(int opcion)
{
	switch (opcion)
	{
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
		listarEquiposPorHilera();
	}
	break;
	case 6:
	{
		auxiliarUI.encabezado();
		listarEquiposPorCategoria();
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
		listarEquiposPorAnio();
	}
	break;
	case 9:
	{
		auxiliarUI.encabezado();
		alquilarEquipo();
	}
	break;
	case 10:
	{
		auxiliarUI.encabezado();
		devolverEquipo();
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

void EquipoUI::menuEquiposCompleto()
{
	int opcion = 0;
	do
	{
		auxiliarUI.encabezado();
		imprimirMenuEquipos();
		opcion = auxiliarUI.leerNumero();
		menuEquipos(opcion);
	} while (opcion != 11);
}

string EquipoUI::leerNombreEquipo()
{
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

string EquipoUI::leerHileraCaracteres()
{
	string hileraC;
	getline(cin, hileraC);
	if (hileraC != "")
	{
		return hileraC;
	}
	else
	{
		cout << "Digite la hilera de caracteres a buscar: ";
		return leerHileraCaracteres();
	}
}

Equipo EquipoUI::leerDatosEquipo()
{
	cout << "Digite el anio del equipo: ";
	int anio;
	anio = auxiliarUI.leerNumero();
	cout << "Digite la descripcion del equipo: ";
	string descripcion;
	getline(cin, descripcion);
	cout << "Digite el pH maximo que puede medir el equipo: ";
	double phMaximo;
	phMaximo = auxiliarUI.leerpH();
	cout << "Digite el pH minimo que puede medir el equipo: ";
	double phMinimo;
	phMinimo = auxiliarUI.leerpH();
	Categorias categorias = gestorCategorias.listarCategorias();
	categorias.Imprimir();
	cout << "Digite el nombre de la categoria del equipo: ";
	string categoria = leerOpcionCategoria();

	Equipo equipo;
	equipo.annio = anio;
	equipo.descripcion = descripcion;
	equipo.maxPh = phMaximo;
	equipo.minPh = phMinimo;
	equipo.categoria.nombre = categoria;
	equipo.estado = false;
	equipo.cantSolicitudes = 0;

	return equipo;
}

void EquipoUI::registrarEquipo()
{
	Equipo equipo;
	int resultado;
	do
	{
		string nombre = leerNombreEquipo();
		equipo = leerDatosEquipo();
		equipo.nombre = nombre;
		resultado = gestorEquipos.insertarEquipo(equipo);
		if (resultado == 1)
		{
			cout << "Ya existe un equipo con ese nombre. Por favor digite otro nombre." << endl;
		}
		else if (resultado == 2)
		{
			cout << "Ocurrio un error al registrar el equipo. Por favor intentelo de nuevo." << endl;
		}
		else
		{
			cout << "El equipo se registro exitosamente." << endl;
		}
	} while (resultado != 0);
}

void EquipoUI::modificarEquipo()
{
	Equipo equipo;
	string nombre;
	int resultado;
	bool existeEquipo;
	do
	{
		do
		{
			nombre = leerNombreEquipo();
			existeEquipo = gestorEquipos.existeEquipo(nombre);
			if (!existeEquipo)
			{
				cout << "No existe un equipo con ese nombre. Por favor digite otro nombre: ";
			}
		} while (!existeEquipo);

		equipo = leerDatosEquipo();
		equipo.nombre = nombre;
		resultado = gestorEquipos.actualizarEquipo(equipo);
		if (resultado == 1)
		{
			cout << "No existe un equipo con ese nombre. Por favor digite otro nombre." << endl;
		}
		else if (resultado == 2)
		{
			cout << "Ocurrio un error al actualizar el equipo. Por favor intentelo de nuevo." << endl;
		}
		else
		{
			cout << "El equipo se actualizo exitosamente." << endl;
		}
	} while (resultado != 0);
}

void EquipoUI::alquilarEquipo()
{
	Equipo equipo;
	string nombre;
	int resultado;
	bool equipoDisponible;
	int cantSolicitudes;
	bool existeEquipo;

	listarEquiposPorEstado(false);

	do
	{
		nombre = leerNombreEquipo();
		existeEquipo = gestorEquipos.existeEquipo(nombre);
		equipoDisponible = gestorEquipos.equipoDisponible(nombre);
		if (!equipoDisponible)
		{
			cout << "No hay un equipo disponible con ese nombre. Por favor digite otro nombre: ";
		}
	} while (!equipoDisponible || !existeEquipo);

	cantSolicitudes = gestorEquipos.cantSolicitudes(nombre);

	equipo.nombre = nombre;
	equipo.estado = true;
	equipo.cantSolicitudes = cantSolicitudes + 1;
	resultado = gestorEquipos.alquilerEquipo(equipo);

	if (resultado == 2)
	{
		cout << "Ocurrio un error al alquilar el equipo. Por favor intentelo de nuevo." << endl;
	}
	else
	{
		cout << "El equipo se alquilo exitosamente." << endl;
	}
}

void EquipoUI::devolverEquipo()
{
	Equipo equipo;
	string nombre;
	int resultado;
	bool equipoDisponible;
	bool existeEquipo;
	int cantSolicitudes;

	listarEquiposPorEstado(true);

	do
	{
		nombre = leerNombreEquipo();
		existeEquipo = gestorEquipos.existeEquipo(nombre);
		equipoDisponible = gestorEquipos.equipoDisponible(nombre);
		if (equipoDisponible)
		{
			cout << "No hay un equipo alquilado con ese nombre. Por favor digite otro nombre: ";
		}
	} while (equipoDisponible || !existeEquipo);

	cantSolicitudes = gestorEquipos.cantSolicitudes(nombre);
	equipo.nombre = nombre;
	equipo.cantSolicitudes = cantSolicitudes;
	equipo.estado = false;
	resultado = gestorEquipos.alquilerEquipo(equipo);

	if (resultado == 2)
	{
		cout << "Ocurrio un error al devolver el equipo. Por favor intentelo de nuevo." << endl;
	}
	else
	{
		cout << "El equipo se devolvio exitosamente." << endl;
	}
}

void EquipoUI::eliminarEquipo()
{
	string nombre;
	int resultado;
	bool existeEquipo;
	do
	{
		do
		{
			nombre = leerNombreEquipo();
			existeEquipo = gestorEquipos.existeEquipo(nombre);
			if (!existeEquipo)
			{
				cout << "No existe un equipo con ese nombre. Por favor digite otro nombre." << endl;
			}
		} while (!existeEquipo);

		resultado = gestorEquipos.eliminarEquipo(nombre);
		if (resultado == 1)
		{
			cout << "No existe un equipo con ese nombre. Por favor digite otro nombre." << endl;
		}
		else if (resultado == 2)
		{
			cout << "Ocurrio un error al eliminar el equipo. Por favor intentelo de nuevo." << endl;
		}
		else
		{
			cout << "El equipo se elimino exitosamente." << endl;
		}
	} while (resultado != 0);
}

int EquipoUI::leerOpcionParam()
{
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

int EquipoUI::leerOpcionOrden()
{
	int opcionOrden = 0;

	cout << "[1] Ascendente" << endl;
	cout << "[2] Descendente" << endl;
	cout << "Digite el orden en el que desea ordenar la lista: " << endl;
	opcionOrden = auxiliarUI.leerNumero();
	if (opcionOrden == 1 || opcionOrden == 2)
	{
		if (opcionOrden == 2)
		{
			opcionOrden = -1;
		}

		return opcionOrden;
	}
	else
	{
		cout << "Opcion invalida. Por favor digite una opcion valida: ";
		return leerOpcionOrden();
	}
}

string EquipoUI::leerOpcionCategoria()
{
	string opcionCategoria;
	getline(cin, opcionCategoria);
	if (opcionCategoria != "")
	{
		if (!gestorCategorias.existeCategoria(opcionCategoria))
		{
			cout << "La categoria no existe. Por favor digite una categoria valida: ";
			return leerOpcionCategoria();
		}
		else
		{
			return opcionCategoria;
		}
	}
	else
	{
		cout << "Digite el nombre de la categoria: ";
		return leerOpcionCategoria();
	}
}

void EquipoUI::listarEquipos()
{
	Equipos listaEquipos = gestorEquipos.listarEquipos();
	int opcionParam = leerOpcionParam();
	int opcionOrden = leerOpcionOrden();
	Equipos listaOrdenada = listaEquipos.ListarEquipos(opcionParam, opcionOrden);
	listaOrdenada.Imprimir();
}

void EquipoUI::listarEquiposPorCategoria()
{
	Categorias categorias = gestorCategorias.listarCategorias();
	categorias.Imprimir();
	string opcionCategoria = leerOpcionCategoria();
	Equipos listaFiltrada = gestorEquipos.listarEquiposPorCategoria(opcionCategoria);
	listaFiltrada.Imprimir();
}

void EquipoUI::listarEquiposPorEstado(bool estado)
{
	Equipos listaFiltrada = gestorEquipos.listarEquiposPorEstado(estado);
	listaFiltrada.Imprimir();
}

void EquipoUI::listarEquipospH()
{
	Equipos listaEquipos = gestorEquipos.listarEquipos();
	double phMinimo = leerpHMin();
	double pHMaximo = leerpHMax();
	Equipos listaOrdenadapH = listaEquipos.ListarEquiposRangopH(phMinimo, pHMaximo);
	listaOrdenadapH.Imprimir();
}

double EquipoUI::leerpHMin()
{

	cout << "Digite el valor minimo de pH del rango a buscar: ";
	double phMinimo = 0.0;
	phMinimo = auxiliarUI.leerpH();

	return phMinimo;
}

double EquipoUI::leerpHMax()
{

	cout << "Digite el valor maximo de pH del rango a buscar: ";
	double pHMaximo = 0.0;
	pHMaximo = auxiliarUI.leerpH();

	return pHMaximo;
}

void EquipoUI::listarEquiposPorAnio()
{
	Equipos listaEquipos = gestorEquipos.listarEquipos();
	int anioInicial = leerAnioInicial();
	int anioFinal = leerAnioFinal();
	Equipos listaOrdenadaAnnio = listaEquipos.ListarEquiposRangoAnnios(anioInicial, anioFinal);
	listaOrdenadaAnnio.Imprimir();
}

int EquipoUI::leerAnioInicial()
{

	cout << "Digite el anio inicial del rango a buscar: ";
	int anioInicial = 0;
	anioInicial = auxiliarUI.leerNumero();
	return anioInicial;
}

int EquipoUI::leerAnioFinal()
{
	cout << "Digite el anio final del rango a buscar: ";
	int anioFinal = 0;
	anioFinal = auxiliarUI.leerNumero();
	return anioFinal;
}

void EquipoUI::listarEquiposPorHilera()
{

	Equipos listaEquipos = gestorEquipos.listarEquipos();
	string hileraC = leerHileraCaracteres();
	Equipos listaOrdenadaHilera = listaEquipos.ListarEquiposBuscarNombre(hileraC);
	listaOrdenadaHilera.Imprimir();
}
