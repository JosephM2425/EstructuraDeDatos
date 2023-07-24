#include <iostream>
#include <string>
#include "Equipos.h"

using namespace std;

int main() {
    Equipos equipos;

   // cout << equipos.Modificar("Luisa", 2013, "Hola", "Hola", 7, 3, true, 5) << endl;

    equipos.Agregar("nX6000", 1999, "Hola", "Hola", 6, 2);
    equipos.Agregar("NX6000", 1999, "Hola", "Hola", 6, 2);
    equipos.Agregar("Luisa", 1999, "Hola", "Hola", 7, 3);
    equipos.Agregar("Xiomara", 1999, "Hola", "Hola", 7, 3);
    equipos.Agregar("Andrea", 1999, "Hola", "Hola", 7, 3);
    equipos.Agregar("Carolina", 1999, "Hola", "Hola", 7, 5);
    equipos.Agregar("Luis", 1999, "Hola", "Hola", 7, 3);
    equipos.Agregar("Ana", 1999, "Hola", "Hola", 7, 3);

    equipos.Imprimir();

    cout << "---------------------------------------------------------------" << endl;
//    cout << equipos.Modificar("Luisa", 2013, "Hola", "Hola", 7, 3, true, 5) << endl;
//    cout << equipos.Modificar("Andres", 2013, "Hola", "Hola", 7, 3, true, 5) << endl;
//    equipos.Imprimir();
//
//    cout << "---------------------------------------------------------------" << endl;
//
//    Equipo equipoABuscar = equipos.Consultar("Luisa");
//    if (equipoABuscar.nombre.empty()) {
//        cout << "No existe." << endl;
//    }
//    else {
//        cout << equipoABuscar.nombre << endl;
//    }
//
//    int equipoARetirar = equipos.Retirar("Luisa");;
//
//    if (equipoARetirar == 0) {
//        cout << "La lista esta vacia." << endl;
//    }
//    else {
//        if (equipoARetirar == 1) {
//            cout << "Se retiro correctamente" << endl;
//        } else {
//            cout << "No existe" << endl;
//        }
//    }
//
//    Equipo equipoABuscar1 = equipos.Consultar("Luisa");
//    if (equipoABuscar1.nombre.empty()) {
//        cout << "No existe." << endl;
//    }
//    else {
//        cout << equipoABuscar1.nombre << endl;
//    }

    Equipos equiposCopia =  equipos.ListarEquipos(0,0); //por nombre a como estan
    cout << "-----------------------Orden ascendente por nombre ------------------------" << endl;
    equiposCopia.Imprimir();
//    //por nombre desc
//    Equipos equiposCopiaDesc =  equipos.ListarEquipos(0,1);
//    cout << "-----------------------Orden descendente por nombre ------------------------" << endl;
//    equiposCopiaDesc.Imprimir();

    return 0;
}
