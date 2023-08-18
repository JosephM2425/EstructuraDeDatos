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


EquipoDAO::EquipoDAO(const std::string& host, const std::string& user, const std::string& password, const std::string& schema) {

    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect(host, user, password);
    con->setSchema(schema);

    if (con->isValid()) {
        std::cout << "Connected to MySQL server!" << std::endl;
    }
    else {
        std::cout << "Connection failed!" << std::endl;
    }

}

EquipoDAO::~EquipoDAO() {
    delete con;
}



void EquipoDAO::insertarEquipo(Equipo equipo) {

    try
    {

        std::string queryEquipo = "INSERT INTO equipo (nombreEquipo, annio,descripcion,minPh,maxPh,estado,cantSolicitudes,idCategoria) VALUES (?,?,?,?,?,?,?,?)";

        sql::PreparedStatement* stmtEquipo = con->prepareStatement(queryEquipo);

        stmtEquipo->setString(1, equipo.nombre);
        stmtEquipo->setInt(2, equipo.annio);
        stmtEquipo->setString(3, equipo.descripcion);
        stmtEquipo->setInt(4, equipo.minPh);
        stmtEquipo->setInt(5, equipo.maxPh);
        stmtEquipo->setBoolean(6, equipo.estado);
        stmtEquipo->setInt(7, equipo.cantSolicitudes);
        stmtEquipo->setInt(8, stoi(equipo.categoria));
        stmtEquipo->execute();
        std::cout << "se logró" << std::endl;

        delete stmtEquipo;

    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Exception: " << e.what() << " (MySQL error code: " << e.getErrorCode() << ")" << std::endl;
    }
    catch (std::runtime_error& e) {
        std::cerr << "Runtime Error: " << e.what() << std::endl;

    }
}

void EquipoDAO::actualizarEquipo(Equipo equipo, int idEquipo) {
    try
    {

        std::string queryEquipo = "UPDATE equipo SET nombreEquipo=?, annio=?, descripcion=?, minPh=?, maxPh=?, estado=?, cantSolicitudes=?, idCategoria=? WHERE idEquipo=? ";

        sql::PreparedStatement* stmtEquipo = con->prepareStatement(queryEquipo);

        stmtEquipo->setString(1, equipo.nombre);
        stmtEquipo->setInt(2, equipo.annio);
        stmtEquipo->setString(3, equipo.descripcion);
        stmtEquipo->setInt(4, equipo.minPh);
        stmtEquipo->setInt(5, equipo.maxPh);
        stmtEquipo->setBoolean(6, equipo.estado);
        stmtEquipo->setInt(7, equipo.cantSolicitudes);
        stmtEquipo->setInt(8, stoi(equipo.categoria));
        stmtEquipo->setInt(9, idEquipo);
        stmtEquipo->execute();
        std::cout << "se logró" << std::endl;

        delete stmtEquipo;

    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Exception: " << e.what() << " (MySQL error code: " << e.getErrorCode() << ")" << std::endl;
    }
    catch (std::runtime_error& e) {
        std::cerr << "Runtime Error: " << e.what() << std::endl;

    }
}

void EquipoDAO::eliminarEquipo(int idEquipo) {
    try
    {

        std::string queryEquipo = "DELETE FROM equipo WHERE idEquipo=? ";

        sql::PreparedStatement* stmtEquipo = con->prepareStatement(queryEquipo);

        stmtEquipo->setInt(1, idEquipo);
        stmtEquipo->execute();
        std::cout << "se logró" << std::endl;

        delete stmtEquipo;

    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Exception: " << e.what() << " (MySQL error code: " << e.getErrorCode() << ")" << std::endl;
    }
    catch (std::runtime_error& e) {
        std::cerr << "Runtime Error: " << e.what() << std::endl;

    }
       
    }


void EquipoDAO::listarEquipos() {
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
            nuevo.minPh = res->getInt("minPh");
            nuevo.maxPh = res->getInt("maxPh");
            nuevo.estado = res->getBoolean("estado");
            nuevo.cantSolicitudes = res->getInt("cantSolicitudes");
            nuevo.categoria = res->getInt("nombreCategoria");

            //Agregando el nuevo equipo a la lista
            listaEquipos.AgregarTemp(nuevo);
        }
        listaEquipos.Imprimir();
        delete res;
        delete stmtEquipo;
        delete con;
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Exception: " << e.what() << " (MySQL error code: " << e.getErrorCode() << ")" << std::endl;
    }
    catch (std::runtime_error& e) {
        std::cerr << "Runtime Error: " << e.what() << std::endl;
    }
}









