#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/driver.h>
#include "Equipo.h"
#include "EquipoDAO.h"
#include "Equipos.h"
#include "Conexion.h"

EquipoDAO::EquipoDAO() {
    con = conexion.obtenerConexion();
}

void EquipoDAO::insertarEquipo(Equipo equipo) {
    try
    {
        std::string queryEquipo = "INSERT INTO equipo (nombreEquipo, annio,descripcion,minPh,maxPh,estado,cantSolicitudes,idCategoria) VALUES (?,?,?,?,?,?,?,?)";

        sql::PreparedStatement* stmtEquipo = con->prepareStatement(queryEquipo);

        stmtEquipo->setString(1, equipo.nombre);
        stmtEquipo->setInt(2, equipo.annio);
        stmtEquipo->setString(3, equipo.descripcion);
        stmtEquipo->setDouble(4, equipo.minPh);
        stmtEquipo->setDouble(5, equipo.maxPh);
        stmtEquipo->setBoolean(6, equipo.estado);
        stmtEquipo->setInt(7, equipo.cantSolicitudes);
        stmtEquipo->setInt(8, stoi(equipo.categoria));
        stmtEquipo->execute();
        delete stmtEquipo;
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Exception: " << e.what() << " (MySQL error code: " << e.getErrorCode() << ")" << std::endl;
    }
    catch (std::runtime_error& e) {
        std::cerr << "Runtime Error: " << e.what() << std::endl;

    }
}

void EquipoDAO::actualizarEquipo(Equipo equipo) {
    try
    {
        std::string queryEquipo = "UPDATE equipo SET annio=?, descripcion=?, minPh=?, maxPh=?, idCategoria=? WHERE nombreEquipo=? ";

        sql::PreparedStatement* stmtEquipo = con->prepareStatement(queryEquipo);

        
        stmtEquipo->setInt(1, equipo.annio);
        stmtEquipo->setString(2, equipo.descripcion);
        stmtEquipo->setDouble(3, equipo.minPh);
        stmtEquipo->setDouble(4, equipo.maxPh);
        stmtEquipo->setInt(5, stoi(equipo.categoria));
        stmtEquipo->setString(6, equipo.nombre);
        stmtEquipo->execute();
        delete stmtEquipo;
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Exception: " << e.what() << " (MySQL error code: " << e.getErrorCode() << ")" << std::endl;
    }
    catch (std::runtime_error& e) {
        std::cerr << "Runtime Error: " << e.what() << std::endl;

    }
}

void EquipoDAO::alquilerEquipo(Equipo equipo) {
    try
    {
        std::string queryEquipo = "UPDATE equipo SET estado=?, cantSolicitudes=? WHERE nombreEquipo=? ";

        sql::PreparedStatement* stmtEquipo = con->prepareStatement(queryEquipo);


        stmtEquipo->setBoolean(1, equipo.estado);
        stmtEquipo->setInt(2, equipo.cantSolicitudes);
        stmtEquipo->setString(3, equipo.nombre);
        stmtEquipo->execute();
        delete stmtEquipo;
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Exception: " << e.what() << " (MySQL error code: " << e.getErrorCode() << ")" << std::endl;
    }
    catch (std::runtime_error& e) {
        std::cerr << "Runtime Error: " << e.what() << std::endl;

    }
}

void EquipoDAO::eliminarEquipo(std::string nombreEquipo) {
    try
    {
        std::string queryEquipo = "DELETE FROM equipo WHERE nombreEquipo=? ";

        sql::PreparedStatement* stmtEquipo = con->prepareStatement(queryEquipo);

        stmtEquipo->setString(1, nombreEquipo);
        stmtEquipo->execute();

        delete stmtEquipo;
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Exception: " << e.what() << " (MySQL error code: " << e.getErrorCode() << ")" << std::endl;
    }
    catch (std::runtime_error& e) {
        std::cerr << "Runtime Error: " << e.what() << std::endl;

    }
}


Equipos EquipoDAO::listarEquipos() {
    try {

        std::string queryEquipo = "SELECT nombreEquipo, annio, descripcion, minPh, maxPh, estado, cantSolicitudes,nombreCategoria FROM equipo INNER JOIN categoria ON equipo.idCategoria = categoria.idCategoria; ";
        sql::PreparedStatement* stmtEquipo = con->prepareStatement(queryEquipo);

        sql::ResultSet* res = stmtEquipo->executeQuery();

        //Instanciando la lista donde se guardarán los equipos de la base de datos
        Equipos listaEquipos;

        while (res->next()) {

            //Instanciando un equipo para asignarle los valores de las columnas
            Equipo nuevo;
            nuevo.nombre = res->getString("nombreEquipo");
            nuevo.annio = res->getInt("annio");
            nuevo.descripcion = res->getString("descripcion");
            nuevo.minPh = res->getDouble("minPh");
            nuevo.maxPh = res->getDouble("maxPh");
            nuevo.estado = res->getBoolean("estado");
            nuevo.cantSolicitudes = res->getInt("cantSolicitudes");
            nuevo.categoria = res->getString("nombreCategoria");

            //Agregando el nuevo equipo a la lista
            listaEquipos.Agregar(nuevo);
        }
        delete res;
        delete stmtEquipo;
        
        return listaEquipos;
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Exception: " << e.what() << " (MySQL error code: " << e.getErrorCode() << ")" << std::endl;
    }
    catch (std::runtime_error& e) {
        std::cerr << "Runtime Error: " << e.what() << std::endl;
    }
}

bool EquipoDAO::existeEquipo(std::string nombre) {
    try {
        bool existeEquipo = false;
        std::string nombreBD;

        std::string queryEquipo = "SELECT nombreEquipo FROM equipo WHERE nombreEquipo = ?;";
        sql::PreparedStatement* stmtEquipo = con->prepareStatement(queryEquipo);       
        stmtEquipo->setString(1, nombre);
        sql::ResultSet* res = stmtEquipo->executeQuery();

        while (res->next()) {
            nombreBD = res->getString("nombreEquipo");
        }

        delete res;
        delete stmtEquipo;
        
        if (nombreBD.size() > 0) {
            existeEquipo = true;
        }

        return existeEquipo;
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Exception: " << e.what() << " (MySQL error code: " << e.getErrorCode() << ")" << std::endl;
    }
    catch (std::runtime_error& e) {
        std::cerr << "Runtime Error: " << e.what() << std::endl;
    }
}









