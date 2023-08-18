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


//esta funcion es temporal para probar si se puede comparar los strings de esta manera
int Equipos::AgregarTemp(Equipo equipo)
{
    Equipo* nuevo = new Equipo();
    nuevo->nombre = equipo.nombre;
    nuevo->annio = equipo.annio;
    nuevo->descripcion = equipo.descripcion;
    nuevo->categoria = equipo.categoria;
    nuevo->maxPh = equipo.maxPh;
    nuevo->minPh = equipo.minPh;
    nuevo->estado = equipo.estado;
    nuevo->cantSolicitudes = equipo.cantSolicitudes;
    nuevo->anterior = nullptr;
    nuevo->siguiente = nullptr;

    //Lista vacia
    if (inicio == nullptr)
    {
        inicio = nuevo;
        inicio->siguiente = inicio;
        inicio->anterior = final;
        final = inicio;
        return 1;
    }
    //Lista con nodos
    else
    {
        //Recorro la lista comparando los nombres de los equipos
        Equipo* actual = inicio;
        string nombreNuevoStr = nuevo->nombre;
        do
        {
            string nombreActualStr = actual->nombre;

            //Si el nombre del equipo nuevo es menor al nombre del equipo actual
            if (nombreNuevoStr < nombreActualStr)
            {
                //Si el equipo actual es el inicio
                if (actual == inicio)
                {
                    nuevo->siguiente = actual;
                    actual->anterior = nuevo;
                    inicio = nuevo;
                    inicio->anterior = final;
                    final->siguiente = inicio;
                }
                else
                {
                    nuevo->siguiente = actual;
                    nuevo->anterior = actual->anterior;
                    actual->anterior->siguiente = nuevo;
                    actual->anterior = nuevo;
                }
                return 1;
            }
            else
                if (nombreNuevoStr < nombreActualStr)
                {
                    //Si el equipo actual es el final
                    if (actual == final)
                    {
                        nuevo->anterior = actual;
                        actual->siguiente = nuevo;
                        nuevo->siguiente = inicio;
                        final = nuevo;
                        inicio->anterior = final;
                        return 1;
                    }
                    actual = actual->siguiente;
                }
                else
                {
                    return 2;
                }
        } while (actual != inicio);
    }
    return 0;
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
        inicio->anterior = final;
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
                    inicio->anterior = final;
                    final->siguiente = inicio;
                }
                else
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
                        inicio->anterior = final;
                        return 1;
                    }
                    actual = actual->siguiente;
                }
                else
                {
                    return 2;
                }
        } while (actual != inicio);
    }
    return 0;
}

int Equipos::Retirar(std::string nombreEquipo) {

    //Almacendando el nombre del equipo como puntero y el uso de la función .data() para poder usarlo en la comparación
    char* nombreEquipoPtr = nombreEquipo.data();

    //Si la lista está vacía
    if (inicio == nullptr)
    {
        return 0;
    }
    else {
        Equipo* actual = inicio;
        do {
            char* nombreEquipoActualPtr = actual->nombre.data();
            //Comparando los valores de nombre, si es cero se cumple.
            if (strcmp(nombreEquipoPtr, nombreEquipoActualPtr) == 0) {
                //Si es el nodo inicial
                if (actual == inicio)
                {
                    actual->siguiente->anterior = actual->siguiente;
                    inicio = actual->siguiente;
                    final = actual->siguiente;
                }//si es el nodo final
                else if (actual == final)
                {
                    actual->anterior->siguiente = inicio;
                    final = actual->anterior;
                }
                else //si es cualquier otro nodo
                {
                    actual->anterior->siguiente = actual->siguiente;
                    actual->siguiente->anterior = actual->anterior;
                }//en cualquier situación se elimina el nodo y se retorna 1 como código de éxito.
                delete actual;
                return 1;
            }//en caso de llegar al final y no encontrar un nodo con el nombre ingresado
            if (actual->siguiente == inicio)
            {
                return 2;
            }//para moverse al nodo siguiente
            actual = actual->siguiente;

        } while (actual != inicio);
        return 0;
    }
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
        Equipo* actual = inicio;
        string nombreABuscarStr = nombreEquipo;
        transform(nombreABuscarStr.begin(), nombreABuscarStr.end(), nombreABuscarStr.begin(), ::tolower);
        char* nombreABuscar = nombreABuscarStr.data();
        do {
            string nombreActualStr = actual->nombre;
            transform(nombreActualStr.begin(), nombreActualStr.end(), nombreActualStr.begin(), ::tolower);
            char* nombreActual = nombreActualStr.data();

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
            }
            else {
                if (actual->siguiente == inicio) {
                    return equipo;
                }
                actual = actual->siguiente;
            }
        } while (actual != inicio);
        return equipo;
    }
}

int Equipos::Modificar(string nombre, int annio, string descripcion, string categoria, int maxPh, int minPh, bool estado, int cantSolicitudes) {
    //Lista vacia
    if (inicio == nullptr) {
        return 0;
    }
    //Lista con nodos
    else {
        //Recorro la lista para ver si existe el equipo
        Equipo* actual = inicio;
        string nombreNuevoStr = nombre;
        transform(nombreNuevoStr.begin(), nombreNuevoStr.end(), nombreNuevoStr.begin(), ::tolower);
        char* nombreNuevo = nombreNuevoStr.data();
        do {
            string nombreActualStr = actual->nombre;
            transform(nombreActualStr.begin(), nombreActualStr.end(), nombreActualStr.begin(), ::tolower);
            char* nombreActual = nombreActualStr.data();

            //Si el nombre del equipo nuevo es igual al nombre del equipo actual
            if (strcmp(nombreNuevo, nombreActual) == 0) {
                actual->annio = annio;
                actual->descripcion = descripcion;
                actual->categoria = categoria;
                actual->maxPh = maxPh;
                actual->minPh = minPh;
                actual->estado = estado;
                actual->cantSolicitudes = cantSolicitudes;
                return 1;
            }
            else {
                if (actual->siguiente == inicio) {
                    return 2;
                }
                actual = actual->siguiente;
            }
        } while (actual != inicio);
        return 0;
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

Equipos Equipos::ListarEquipos(int param, int orden) {
    //Param = 0 ordenar por nombre
    //Param = 1 ordenar por annio
    //Orden = 0 ordenar ascendentemente
    //Orden = 1 ordenar descendentemente

    Equipos equiposOrdenados; //Lista auxiliar

    if (param == 0 && orden == 0) { //Ordenar por nombre ascendentemente
        Equipo* actual = inicio; //nodo actual de lista original
        //Para hacer una copia de la lista
        do {
            //Lista vacia
            if (inicio == nullptr) {
                //no se hace nada
            }
            else//Lista con nodos
            {
                Equipo* nuevo = new Equipo();
                nuevo->nombre = actual->nombre;
                nuevo->annio = actual->annio;
                nuevo->descripcion = actual->descripcion;
                nuevo->categoria = actual->categoria;
                nuevo->maxPh = actual->maxPh;
                nuevo->minPh = actual->minPh;
                nuevo->estado = actual->estado;
                nuevo->cantSolicitudes = actual->cantSolicitudes;
                nuevo->anterior = nullptr;
                nuevo->siguiente = nullptr;

                // equiposOrdenados.Agregar(actual->nombre,actual->annio,actual->descripcion,actual->categoria,actual->maxPh,actual->minPh);
                //Si la lista está vacía
                if (equiposOrdenados.inicio == nullptr) {
                    equiposOrdenados.inicio = nuevo;
                    equiposOrdenados.final = nuevo;
                }
                else //Si ya tiene algún nodo
                {
                    nuevo->anterior = equiposOrdenados.final;
                    nuevo->siguiente = equiposOrdenados.inicio;
                    equiposOrdenados.final->siguiente = nuevo;
                    equiposOrdenados.final = nuevo;
                }
            }
            actual = actual->siguiente;
        } while (actual != inicio);
    }
    else if (param == 0 && orden == 1) //Ordenar por nombre descendentemente
    {
        Equipo* actual = final;
        do {
            //Lista vacia
            Equipo* nuevo = new Equipo();
            nuevo->nombre = actual->nombre;
            nuevo->annio = actual->annio;
            nuevo->descripcion = actual->descripcion;
            nuevo->categoria = actual->categoria;
            nuevo->maxPh = actual->maxPh;
            nuevo->minPh = actual->minPh;
            nuevo->estado = actual->estado;
            nuevo->cantSolicitudes = actual->cantSolicitudes;
            nuevo->anterior = nullptr;
            nuevo->siguiente = nullptr;

            //Si la lista está vacía
            if (equiposOrdenados.inicio == nullptr) {
                equiposOrdenados.inicio = nuevo;
                equiposOrdenados.final = nuevo;
            }
            else //Si ya tiene algún nodo
            {
                nuevo->anterior = equiposOrdenados.final;
                nuevo->siguiente = equiposOrdenados.inicio;
                equiposOrdenados.final->siguiente = nuevo;
                equiposOrdenados.final = nuevo;
            }

            actual = actual->anterior;
        } while (actual != final);
    }
    else if (param == 1 && orden == 0)//Ordenar por año ascendentemente
    {
        //Para copiar la lista
        Equipo* actual = inicio; //nodo actual de lista original
        //Para hacer una copia de la lista
        do {
            //Lista vacia
            if (inicio == nullptr) {
                //no se hace nada
            }
            else//Lista con nodos
            {
                Equipo* nuevo = new Equipo();
                nuevo->nombre = actual->nombre;
                nuevo->annio = actual->annio;
                nuevo->descripcion = actual->descripcion;
                nuevo->categoria = actual->categoria;
                nuevo->maxPh = actual->maxPh;
                nuevo->minPh = actual->minPh;
                nuevo->estado = actual->estado;
                nuevo->cantSolicitudes = actual->cantSolicitudes;
                nuevo->anterior = nullptr;
                nuevo->siguiente = nullptr;

                // equiposOrdenados.Agregar(actual->nombre,actual->annio,actual->descripcion,actual->categoria,actual->maxPh,actual->minPh);
                //Si la lista está vacía
                if (equiposOrdenados.inicio == nullptr) {
                    equiposOrdenados.inicio = nuevo;
                    equiposOrdenados.final = nuevo;
                }
                else //Si ya tiene algún nodo
                {
                    nuevo->anterior = equiposOrdenados.final;
                    nuevo->siguiente = equiposOrdenados.inicio;
                    equiposOrdenados.final->siguiente = nuevo;
                    equiposOrdenados.final = nuevo;
                }
            }
            actual = actual->siguiente;
        } while (actual != inicio);

        //Ordenando por año ascendentemente


        if (equiposOrdenados.inicio == equiposOrdenados.final && equiposOrdenados.inicio == nullptr) {
            //Lista vacía
        }
        else
        {
            Equipo* actualC = equiposOrdenados.inicio->siguiente; // Comienza en el segundo nodo (Salta el nodo dummy)
            while (actualC != equiposOrdenados.inicio) {
                int valor = actualC->annio;
                Equipo* nodoAnterior = actualC->anterior;

                // Encuentra la posición correcta para ubicar el nodo actual
                while (nodoAnterior != equiposOrdenados.inicio && nodoAnterior->annio > valor) {
                    nodoAnterior->siguiente->annio = nodoAnterior->annio;
                    nodoAnterior = nodoAnterior->anterior;
                }

                //Inserta el nodo actual en su posición correcta
                nodoAnterior->siguiente->annio = valor;

                //Se mueve para el nodo siguiente para la siguiente interación
                actualC = actualC->siguiente;
            }
        }

    }
    else if (param == 1 && orden == 1)//Ordenar por año descendentemente
    {
        Equipo* actual = final;
        do {
            //Lista vacia
            Equipo* nuevo = new Equipo();
            nuevo->nombre = actual->nombre;
            nuevo->annio = actual->annio;
            nuevo->descripcion = actual->descripcion;
            nuevo->categoria = actual->categoria;
            nuevo->maxPh = actual->maxPh;
            nuevo->minPh = actual->minPh;
            nuevo->estado = actual->estado;
            nuevo->cantSolicitudes = actual->cantSolicitudes;
            nuevo->anterior = nullptr;
            nuevo->siguiente = nullptr;

            //Si la lista está vacía
            if (equiposOrdenados.inicio == nullptr) {
                equiposOrdenados.inicio = nuevo;
                equiposOrdenados.final = nuevo;
            }
            else //Si ya tiene algún nodo
            {
                nuevo->anterior = equiposOrdenados.final;
                nuevo->siguiente = equiposOrdenados.inicio;
                equiposOrdenados.final->siguiente = nuevo;
                equiposOrdenados.final = nuevo;
            }

            actual = actual->anterior;
        } while (actual != final);

        if (equiposOrdenados.inicio == equiposOrdenados.final && equiposOrdenados.inicio == nullptr) {
            //Lista vacía
        }
        else
        {
            Equipo* actualC = equiposOrdenados.inicio->siguiente; // Comienza en el segundo nodo (Salta el nodo dummy)
            while (actualC != equiposOrdenados.inicio) {
                int valor = actualC->annio;
                Equipo* nodoAnterior = actualC->anterior;

                // Encuentra la posición correcta para ubicar el nodo actual
                while (nodoAnterior != equiposOrdenados.inicio && nodoAnterior->annio < valor) {
                    nodoAnterior->siguiente->annio = nodoAnterior->annio;
                    nodoAnterior = nodoAnterior->anterior;
                }

                //Inserta el nodo actual en su posición correcta
                nodoAnterior->siguiente->annio = valor;

                //Se mueve para el nodo siguiente para la siguiente interación
                actualC = actualC->siguiente;
            }
        }

        return equiposOrdenados;
    }

    return equiposOrdenados;
}



