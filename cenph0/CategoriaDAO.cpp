#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/driver.h>
#include "Categoria.h"
#include "CategoriaDAO.h"
#include "Categorias.h"
#include "Conexion.h"

CategoriaDAO::CategoriaDAO(){
	con = conexion.obtenerConexion();
}


void CategoriaDAO::insertarCategoria(Categoria categoria){
	try{
		std::string queryCategoria = "INSERT INTO categoria (nombreCategoria) VALUES (?)";

		sql::PreparedStatement* stmtCategoria = con->prepareStatement(queryCategoria);

		stmtCategoria->setString(1,categoria.nombre);
		stmtCategoria->execute();
		delete stmtCategoria;

	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Exception: " << e.what() << " (MySQL error code: " << e.getErrorCode() << ")" << std::endl;
	}
	catch (std::runtime_error& e) {
		std::cerr << "Runtime Error: " << e.what() << std::endl;

	}
}

void CategoriaDAO::actualizarCategoria(Categoria categoria, Categoria nuevaCategoria){
	try{
		std::string queryCategoria = "UPDATE categoria SET nombreCategoria = ? WHERE nombreCategoria = ?";

		sql::PreparedStatement* stmtCategoria = con->prepareStatement(queryCategoria);

		stmtCategoria->setString(1,nuevaCategoria.nombre);
		stmtCategoria->setString(2,categoria.nombre);
		stmtCategoria->execute();
		delete stmtCategoria;

	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Exception: " << e.what() << " (MySQL error code: " << e.getErrorCode() << ")" << std::endl;
	}
	catch (std::runtime_error& e) {
		std::cerr << "Runtime Error: " << e.what() << std::endl;

	}
}

void CategoriaDAO::eliminarCategoria(std::string nombreCategoria){
	try{
		std::string queryCategoria = "DELETE FROM categoria WHERE nombreCategoria = ?";

		sql::PreparedStatement* stmtCategoria = con->prepareStatement(queryCategoria);

		stmtCategoria->setString(1,nombreCategoria);
		stmtCategoria->execute();
		delete stmtCategoria;

	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Exception: " << e.what() << " (MySQL error code: " << e.getErrorCode() << ")" << std::endl;
	}
	catch (std::runtime_error& e) {
		std::cerr << "Runtime Error: " << e.what() << std::endl;

	}
}


Categorias CategoriaDAO::listarCategorias(){
	try{
		std::string queryCategoria = "SELECT * FROM categoria";

		sql::PreparedStatement* stmtCategoria = con->prepareStatement(queryCategoria);

		sql::ResultSet* res = stmtCategoria->executeQuery();

		//Instanciando la lista donde se guardarán las categorias de la base de datos
		Categorias listaCategorias;

		while(res->next()){
			std::string nombre;
			nombre = res->getString("nombre");
			
			//Agregando la nueva categoria a la lista
			listaCategorias.Agregar(nombre);
		}
		delete stmtCategoria;
		delete res;
		return listaCategorias;

	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Exception: " << e.what() << " (MySQL error code: " << e.getErrorCode() << ")" << std::endl;
	}
	catch (std::runtime_error& e) {
		std::cerr << "Runtime Error: " << e.what() << std::endl;

	}
}

bool CategoriaDAO::existeCategoria(std::string nombre) {
	try {
		bool existeCategoria = false;
		std::string nombreBD;

		std::string queryCategoria = "SELECT nombreCategoria FROM categoria WHERE nombreCategoria = ?;";
		sql::PreparedStatement* stmtCategoria = con->prepareStatement(queryCategoria);
		stmtCategoria->setString(1, nombre);
		sql::ResultSet* res = stmtCategoria->executeQuery();

		while (res->next()) {
			nombreBD = res->getString("nombreCategoria");
		}

		delete res;
		delete stmtCategoria;

		if (nombreBD.size() > 0) {
			existeCategoria = true;
		}

		return existeCategoria;
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Exception: " << e.what() << " (MySQL error code: " << e.getErrorCode() << ")" << std::endl;
	}
	catch (std::runtime_error& e) {
		std::cerr << "Runtime Error: " << e.what() << std::endl;
	}
}
