#include <string>
#include "Categoria.h"
#include "Categorias.h"
#include "CategoriaDAO.h"
#include "GestorCategorias.h"

int GestorCategorias::insertarCategoria(Categoria categoria){
	try {
		if (existeCategoria(categoria.nombre)) {
			return 1;
		}
		else {
			categoriaDAO.insertarCategoria(categoria);
			return 0;
		}
	}
	catch (exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
		return 2;
	}
}

int GestorCategorias::eliminarCategoria(std::string nombreCategoria) {
	try {
		if (!existeCategoria(nombreCategoria)) {
			return 1;
		}
		else {
			categoriaDAO.eliminarCategoria(nombreCategoria);
			return 0;
		}
	}
	catch (exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
		return 2;
	}
}

int GestorCategorias::actualizarCategoria(Categoria categoria) {
	try {
		if (!existeCategoria(categoria.nombre)) {
			return 1;
		}
		else {
			categoriaDAO.actualizarCategoria(categoria);
			return 0;
		}
	}
	catch (exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
		return 2;
	}
}

bool GestorCategorias::existeCategoria(std::string nombreCategoria) {
	return categoriaDAO.existeCategoria(nombreCategoria);
}

Categorias GestorCategorias::listarCategorias() {
	return categoriaDAO.listarCategorias();
}