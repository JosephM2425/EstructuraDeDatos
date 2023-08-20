#include <iostream>
#include <string>
#include "GestorEquipos.h"
#include "CategoriaUI.h"
#include "Equipo.h"
#include "Equipos.h"
#include "AuxiliarUI.h"

void CategoriaUI::imprimirMenuCategorias(){
	cout << "[1] Registrar categoria" << endl;
	cout << "[2] Modificar categoria" << endl;
	cout << "[3] Eliminar categoria" << endl;
	cout << "[4] Listar categorias" << endl;
	cout << "[5] Regresar" << endl;
	auxiliarUI.digiteOpcion();
}

void CategoriaUI::menuCategorias(int opcion) {
	switch (opcion) {
	case 1:
	{
		auxiliarUI.encabezado();
		registrarCategoria();
	}
	break;
	case 2:
	{
		auxiliarUI.encabezado();
		modificarCategoria();
	}
	break;
	case 3:
	{
		auxiliarUI.encabezado();
		eliminarCategoria();
	}
	break;
	case 4:
	{
		auxiliarUI.encabezado();
		listarCategorias();
	}
	break;
	case 5:
	{
	}
	break;
	default:
		cout << "Opcion invalida" << endl;
	}
}

void CategoriaUI::menuCategoriasCompleto() {
	int opcion = 0;
	do {
		auxiliarUI.encabezado();
		imprimirMenuCategorias();
		opcion = auxiliarUI.leerNumero();
		menuCategorias(opcion);
	} while (opcion != 5);
}

string CategoriaUI::leerNombreCategoria() {
	string nombre;
	getline(cin, nombre);
	if (nombre!="")
	{
		return nombre;
	}
	else
	{
		cout << "Digite el nombre de la categoria: ";
		return leerNombreCategoria();
	}
}
void CategoriaUI::registrarCategoria() {
	Categoria categoria;
	int resultado;
	do {
		string nombre = leerNombreCategoria();
		categoria.nombre = nombre;
		resultado = gestorCategorias.insertarCategoria(categoria);
		if (resultado == 1) {
			cout << "Ya existe una categoria con ese nombre. Por favor digite otro nombre." << endl;
		}
		else if (resultado == 2) {
			cout << "Ocurrio un error al registrar la categoría. Por favor intentelo de nuevo." << endl;
		}
		else {
			cout << "La categoria se registro exitosamente." << endl;
		}
	} while (resultado != 0);
}

void CategoriaUI::modificarCategoria() {
	Categoria categoria;
	string nombre;
	Categoria nuevaCategoria;
	int resultado;
	bool existeCategoria;
	do {
		do {
			nombre = leerNombreCategoria();
			existeCategoria = gestorCategorias.existeCategoria(nombre);
			if (!existeCategoria) {
				cout << "No existe una categoria con ese nombre. Por favor digite otro nombre." << endl;
			}
		} while (!existeCategoria);
		categoria.nombre = nombre;
		cout << "Digite el nuevo nombre de la categoria: ";
		nombre=leerNombreCategoria();
		nuevaCategoria.nombre = nombre;
		resultado = gestorCategorias.actualizarCategoria(categoria, nuevaCategoria);
		if (resultado == 1) {
			cout << "No existe una categoria con ese nombre. Por favor digite otro nombre." << endl;
		}
		else if (resultado == 2) {
			cout << "Ocurrio un error al actualizar la categoria. Por favor intentelo de nuevo." << endl;
		}
		else {
			cout << "La categoria se actualizo exitosamente." << endl;
		}
	} while (resultado != 0);
}

void CategoriaUI::eliminarCategoria() {
	string nombre;
	int resultado;
	bool existeCategoria;
	do {
		do {
			nombre = leerNombreCategoria();
			existeCategoria = gestorCategorias.existeCategoria(nombre);
			if (!existeCategoria) {
				cout << "No existe un equipo con ese nombre. Por favor digite otro nombre." << endl;
			}
		} while (!existeCategoria);


		resultado = gestorCategorias.eliminarCategoria(nombre);
		if (resultado == 1) {
			cout << "No existe una categoria con ese nombre. Por favor digite otro nombre." << endl;
		}
		else if (resultado == 2) {
			cout << "Ocurrio un error al eliminar la categoria. Por favor intentelo de nuevo." << endl;
		}
		else {
			cout << "La categoria se elimino exitosamente." << endl;
		}
	} while (resultado != 0);
}

int CategoriaUI::leerOpcionOrden() {
	int opcionOrden = 0;
	do {
		cout << "Digite el orden en el que desea ordenar la lista: " << endl;
		cout << "[1] Ascendente" << endl;
		cout << "[2] Descendente" << endl;
		opcionOrden = auxiliarUI.leerNumero();

		if (opcionOrden != 1 && opcionOrden != 2) {
			cout << "Opcion invalida. Por favor digite una opcion valida." << endl;
		}
	} while (opcionOrden != 1 && opcionOrden != 2);

	if (opcionOrden == 2) {
		opcionOrden = -1;
	}
	return opcionOrden;
}

void CategoriaUI::listarCategorias() {
	Categorias listacategorias = gestorCategorias.listarCategorias();
	int opcionOrden = leerOpcionOrden();
	Categorias listaOrdenada = listacategorias.ListarCategorias(opcionOrden);
	listaOrdenada.Imprimir();
}