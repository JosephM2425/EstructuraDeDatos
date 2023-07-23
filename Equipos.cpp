#include <iostream>
#include <string>
#include "Equipo.h"
#include "Equipos.h"
#include "Categoria.h"
#include <cstring>
#include <algorithm>

using namespace std;


Equipos::Equipos()
{
    inicio = nullptr;
    final = nullptr;
}

int Equipos::Agregar(string nombre, int annio, string descripcion, string categoria, int maxPh, int minPh)
{
    Equipo* nuevo = new Equipo();
    nuevo->nombre = nombre;
    nuevo->annio = annio;
    nuevo->descripcion = descripcion;
    nuevo->categoria = categoria;
    nuevo->maxPh = maxPh;
    nuevo->minPh = minPh;
    nuevo->estado = false;
    nuevo->cantSolicitudes = 0;
    nuevo->anterior = nullptr;
    nuevo->siguiente = nullptr;

    //Lista vacia
    if (inicio == nullptr)
    {
        inicio = nuevo;
        inicio->siguiente = inicio;
        inicio->anterior = inicio;
        final = inicio;
        return 1;
    }
    //Lista con nodos
    else
    {
        //Recorro la lista comparando los nombres de los equipos
        Equipo* actual = inicio;
        string nombreNuevoStr = nuevo->nombre;
        transform(nombreNuevoStr.begin(), nombreNuevoStr.end(), nombreNuevoStr.begin(), ::tolower);
        char* nombreNuevo = nombreNuevoStr.data();
        do
        {
            string nombreActualStr = actual->nombre;
            transform(nombreActualStr.begin(), nombreActualStr.end(), nombreActualStr.begin(), ::tolower);
            char* nombreActual = nombreActualStr.data();

                //Si el nombre del equipo nuevo es menor al nombre del equipo actual
                if (strcmp(nombreNuevo, nombreActual) < 0)
                {
                    //Si el equipo actual es el inicio
                    if (actual == inicio)
                    {
                        nuevo->siguiente = actual;
                        actual->anterior = nuevo;
                        inicio = nuevo;
                        final->siguiente = inicio;
                    } else
                    {
                        nuevo->siguiente = actual;
                        nuevo->anterior = actual->anterior;
                        actual->anterior->siguiente = nuevo;
                        actual->anterior = nuevo;
                    }
                    return 1;
                }
                else
                if (strcmp(nombreNuevo, nombreActual) > 0)
                {
                    //Si el equipo actual es el final
                    if (actual == final)
                    {
                        nuevo->anterior = actual;
                        actual->siguiente = nuevo;
                        nuevo->siguiente = inicio;
                        final = nuevo;
                        return 1;
                    }
                    actual = actual->siguiente;
                } else
                {
                    return 2;
                }
        } while (actual != inicio);
    }
    return 0;
}

Equipo Equipos::Consultar(string nombreEquipo) {
    Equipo equipo;
    //Lista vacia
    if (inicio == nullptr) {
        return equipo;
    }
        //Lista con nodos
    else {
        //Recorro la lista para ver si existe el equipo
        Equipo *actual = inicio;
        string nombreABuscarStr = nombreEquipo;
        transform(nombreABuscarStr.begin(), nombreABuscarStr.end(), nombreABuscarStr.begin(), ::tolower);
        char *nombreABuscar = nombreABuscarStr.data();
        do {
            string nombreActualStr = actual->nombre;
            transform(nombreActualStr.begin(), nombreActualStr.end(), nombreActualStr.begin(), ::tolower);
            char *nombreActual = nombreActualStr.data();

            //Si el nombre del equipo nuevo es igual al nombre del equipo actual
            if (strcmp(nombreABuscar, nombreActual) == 0) {
                equipo.nombre = actual->nombre;
                equipo.annio = actual->annio;
                equipo.descripcion = actual->descripcion;
                equipo.categoria = actual->categoria;
                equipo.maxPh = actual->maxPh;
                equipo.minPh = actual->minPh;
                equipo.estado = actual->estado;
                equipo.cantSolicitudes = actual->cantSolicitudes;
                return equipo;
            } else {
                if (actual->siguiente == inicio) {
                    return equipo;
                }
                actual = actual->siguiente;
            }
        } while (actual != inicio);
        return equipo;
    }
}

Equipo Equipos::Inicio()
{
    return *inicio;
}

Equipo Equipos::Final()
{
    return *final;
}

int Equipos::Cantidad()
{
    int cantidad = 0;
    Equipo* actual = inicio;
    while (actual != nullptr)
    {
        cantidad++;
        actual = actual->siguiente;
    }
    return cantidad;
}

void Equipos::Imprimir()
{
    Equipo* actual = inicio;
    do
    {
        cout << "Nombre: " << actual->nombre << "\n";
        cout << "Annio: " << actual->annio << "\n";
        cout << "Descripcion: " << actual->descripcion << "\n";
        cout << "Categoria: " << actual->categoria << "\n";
        cout << "Max pH: " << actual->maxPh << "\n";
        cout << "Min pH: " << actual->minPh << "\n";
        cout << "Estado: " << actual->estado << "\n";
        cout << "Cantidad de solicitudes: " << actual->cantSolicitudes << "\n";
        cout << "\n";
        actual = actual->siguiente;
    } while (actual != inicio);
}


