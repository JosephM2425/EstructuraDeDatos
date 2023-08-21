#include "Categorias.h"
#include <algorithm>
#include <iostream>

Categorias::Categorias()
{
    inicio = nullptr;
    final = nullptr;
}

int Categorias::Agregar(string nombre)
{
    Categoria* nuevo = new Categoria();
    nuevo->nombre = nombre;
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
        Categoria* actual = inicio;
        string nombreNuevoStr = nuevo->nombre;
        transform(nombreNuevoStr.begin(), nombreNuevoStr.end(), nombreNuevoStr.begin(), ::tolower);
        const char* nombreNuevo = nombreNuevoStr.data();
        bool recorridoCompleto = false;

        do
        {
            if (actual == final)
            {
                recorridoCompleto = true;
            }

            string nombreActualStr = actual->nombre;
            transform(nombreActualStr.begin(), nombreActualStr.end(), nombreActualStr.begin(), ::tolower);
            const char* nombreActual = nombreActualStr.data();

            //Si el nombre del equipo nuevo es menor al nombre del equipo actual
            if (strcmp(nombreNuevo, nombreActual) < 0)
            {
                //Si la categoria actual es el inicio
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
                    //Si la categoria actual es el final
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
        } while (!recorridoCompleto && inicio != final);
    }
    return 0;
}

int Categorias::Retirar(string nombre)
{
    //Almacendando el nombre del equipo como puntero y el uso de la función .data() para poder usarlo en la comparación
    const char* nombreCategoriaPtr = nombre.data();

    //Si la lista está vacía
    if (inicio == nullptr)
    {
        return 0;
    }
    else {
        Categoria* actual = inicio;
        bool recorridoCompleto = false;

        do {
            if (actual == final)
            {
                recorridoCompleto = true;
            }

            const  char* nombreCategoriaActualPtr = actual->nombre.data();
            //Comparando los valores de nombre, si es cero se cumple.
            if (strcmp(nombreCategoriaPtr, nombreCategoriaActualPtr) == 0) {
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

        } while (!recorridoCompleto && inicio != final);
        return 0;
    }

}

int Categorias::Modificar(string nombre)
{
    //Lista vacia
    if (inicio == nullptr) {
        return 0;
    }
    //Lista con nodos
    else {
        //Recorro la lista para ver si existe el equipo
        Categoria* actual = inicio;
        string nombreNuevoStr = nombre;
        transform(nombreNuevoStr.begin(), nombreNuevoStr.end(), nombreNuevoStr.begin(), ::tolower);
        const char* nombreNuevo = nombreNuevoStr.data();
        bool recorridoCompleto = false;

        do {
            if (actual == final) {
                recorridoCompleto = true;
            }

            string nombreActualStr = actual->nombre;
            transform(nombreActualStr.begin(), nombreActualStr.end(), nombreActualStr.begin(), ::tolower);
            const char* nombreActual = nombreActualStr.data();

            //Si el nombre del equipo nuevo es igual al nombre del equipo actual
            if (strcmp(nombreNuevo, nombreActual) == 0) {
                actual->nombre = nombre;
                return 1;
            }
            else {
                if (actual->siguiente == inicio) {
                    return 2;
                }
                actual = actual->siguiente;
            }
        } while (!recorridoCompleto && inicio != final);
        return 0;
    }
}

Categorias Categorias::ListarCategorias(int param)
{
    //Orden = 1 ordenar ascendentemente
    //Orden = -1 ordenar descendentemente

    Categorias categoriasOrdenados; //Lista auxiliar
    bool recorridoCompleto = false;

    if (param == 1) { //Ordenar por nombre ascendentemente
        categoriasOrdenados = CopiarLista();
    }
    else if (param == -1) //Ordenar por nombre descendentemente
    {
        Categoria* actual = final;
        do
        {
            if (actual == inicio) {
                recorridoCompleto = true;
            }

            Categoria* nuevo = new Categoria();
            nuevo->nombre = actual->nombre;
            nuevo->anterior = nullptr;
            nuevo->siguiente = nullptr;

            //Si la lista está vacía
            if (categoriasOrdenados.inicio == nullptr) {
                categoriasOrdenados.inicio = nuevo;
                categoriasOrdenados.final = nuevo;
            }
            else //Si ya tiene algún nodo
            {
                nuevo->anterior = categoriasOrdenados.final;
                nuevo->siguiente = categoriasOrdenados.inicio;
                categoriasOrdenados.final->siguiente = nuevo;
                categoriasOrdenados.final = nuevo;
            }

            actual = actual->anterior;
        } while (!recorridoCompleto && inicio != final);
    }
    return categoriasOrdenados;
}

Categorias Categorias::CopiarLista() 
{
        Categorias categoriasCopia; //Lista auxiliar
        Categoria* actual = inicio; //nodo actual de lista original
        bool recorridoCompleto = false;
        //Para hacer una copia de la lista
        do {
            if (actual == final) {
                recorridoCompleto = true;
            }

            //Lista vacia
            if (inicio == nullptr) {
                //no se hace nada
            }
            else//Lista con nodos
            {
                Categoria* nuevo = new Categoria();
                nuevo->nombre = actual->nombre;
                nuevo->anterior = nullptr;
                nuevo->siguiente = nullptr;

                //Si la lista está vacía
                if (categoriasCopia.inicio == nullptr) {
                    categoriasCopia.inicio = nuevo;
                    categoriasCopia.final = nuevo;
                }
                else //Si ya tiene algún nodo
                {
                    nuevo->anterior = categoriasCopia.final;
                    nuevo->siguiente = categoriasCopia.inicio;
                    categoriasCopia.final->siguiente = nuevo;
                    categoriasCopia.final = nuevo;
                }
            }
            actual = actual->siguiente;
        } while (!recorridoCompleto && inicio != final);
        return categoriasCopia;
}

void Categorias::Imprimir()
{
    Categoria* actual = inicio;
    Categoria* inicio = this->inicio;
    Categoria* final = this->final;

    bool recorridoCompleto = false;

    cout << "==========================================================================" << endl;
    cout << "||                      Lista de Categorias | cen-ph0                   ||" << endl;
    cout << "==========================================================================" << endl;

    do
    {
        if (actual == final)
        {
            recorridoCompleto = true;
        }

        cout << "Nombre: " << actual->nombre << "\n";
        cout << "==========================================================================\n";
        actual = actual->siguiente;
    } while (!recorridoCompleto && inicio != final);
}

