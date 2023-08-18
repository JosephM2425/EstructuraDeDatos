// cenph0.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include "EquipoDAO.h"

int main() {git
    EquipoDAO equipoDao("tcp://cenph0.mysql.database.azure.com:3306", "francisco", "stevenChaves123.", "equiposdb");

    // Call methods
    Equipo equipoPrueba;
    equipoPrueba.nombre = "TestpH";
    equipoPrueba.annio = 1999;
    equipoPrueba.descripcion = "Usado para medir la exactitud del balance de pH";
    equipoPrueba.minPh = 1;
    equipoPrueba.maxPh = 7;
    equipoPrueba.estado = true;
    equipoPrueba.cantSolicitudes = 7;
    equipoPrueba.categoria = "1";
    equipoDao.insertarEquipo(equipoPrueba);

    //para hacer el update
    Equipo equipoPrueba2;
    equipoPrueba2.nombre = "MediopH";
    equipoPrueba2.annio = 1990;
    equipoPrueba2.descripcion = "Usado para medir los medios";
    equipoPrueba2.minPh = 9;
    equipoPrueba2.maxPh = 9;
    equipoPrueba2.estado = false;
    equipoPrueba2.cantSolicitudes = 7;
    equipoPrueba2.categoria = "1";
   // equipoDao.actualizarEquipo(equipoPrueba2, 3);

    //para borrar un equipo
    //equipoDao.eliminarEquipo();

    //para generar lista ordenada alfabeticamente con los equipos en la base de datos
    equipoDao.listarEquipos();
    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
