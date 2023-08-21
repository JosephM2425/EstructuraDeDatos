#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/driver.h>
#include "Conexion.h"


Conexion::Conexion() {
    host = "tcp://127.0.0.1:3306";
    user = "root";
    password = "1234";
    schema = "cenph0db";
    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect(host, user, password);
    con->setSchema(schema);
}

Conexion::~Conexion() {
    delete con;
}

sql::Connection* Conexion::obtenerConexion() {
    return con;
}