#include "Categorias.h"
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;


Categorias::Categorias() {
    inicio = nullptr;
    final = nullptr;
}

Categorias::Categorias(Categoria *inicio, Categoria *final) : inicio(inicio), final(final) {}

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
        final = nuevo;
        return 1;
    }//Lista con nodos
    else
    {
        //Recorro la lista comparando los nombres de las categorias
        Categoria* actual = inicio;
        string nombreNuevoStr = nuevo->nombre;
        transform(nombreNuevoStr.begin(), nombreNuevoStr.end(), nombreNuevoStr.begin(), ::tolower);
        char* nombreNuevo = nombreNuevoStr.data();
        bool recorridoCompleto = false;

        do
        {
            if (actual == final)
            {
                recorridoCompleto = true;
            }

            string nombreActualStr = actual->nombre;
            transform(nombreActualStr.begin(), nombreActualStr.end(), nombreActualStr.begin(), ::tolower);
            char* nombreActual = nombreActualStr.data();

            //Si el nombre de la categoria nueva es menor al nombre de la categoria actual
            if (strcmp(nombreNuevo, nombreActual) < 0)
            {
                //Si la categoria actual es el inicio
                if (actual == inicio)
                {
                    nuevo->siguiente = actual;
                    actual->anterior = nuevo;
                    inicio = nuevo;
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
                //Si la categoria actual es el final
                if (actual == final)
                {
                    nuevo->anterior = actual;
                    actual->siguiente = nuevo;
                    final = nuevo;
                    return 1;
                }
                actual = actual->siguiente;
            } else
            {
                return 2;
            }
        } while (!recorridoCompleto);
    }
    return 0;
}

int Categorias::Retirar(std::string nombreCategoria)
{

    //Almacendando el nombre de la categoria como puntero y el uso de la función .data() para poder usarlo en la comparación
    char* nombreCategoriaPtr = nombreCategoria.data();

    //Si la lista está vacía
    if (inicio == nullptr)
    {
        return 0;
    }
    else {
        Categoria* actual = inicio;
        bool recorridoCompleto = false;

        do{
            if (actual == final)
            {
                recorridoCompleto = true;
            }

            char* nombreCategoriaActualPtr = actual->nombre.data();
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
                    actual->anterior->siguiente= inicio;
                    final=actual->anterior;
                }
                else //si es cualquier otro nodo
                {
                    actual->anterior->siguiente=actual->siguiente;
                    actual->siguiente->anterior=actual->anterior;
                }//en cualquier situación se elimina el nodo y se retorna 1 como código de éxito.
                delete actual;
                return 1;
            }//en caso de llegar al final y no encontrar un nodo con el nombre ingresado
            if(actual->siguiente == inicio)
            {
                return 2;
            }//para moverse al nodo siguiente
            actual=actual->siguiente;

        } while(!recorridoCompleto);
        return 0;
    }
}

Categoria Categorias::Consultar(string nombreCategoria) {
    Categoria categoria;
    //Lista vacia
    if (inicio == nullptr) {
        return categoria;
    }
        //Lista con nodos
    else {
        //Recorro la lista para ver si existe la categoria
        Categoria *actual = inicio;
        string nombreABuscarStr = nombreCategoria;
        transform(nombreABuscarStr.begin(), nombreABuscarStr.end(), nombreABuscarStr.begin(), ::tolower);
        char *nombreABuscar = nombreABuscarStr.data();
        bool recorridoCompleto = false;

        do {
            if (actual == final) {
                recorridoCompleto = true;
            }

            string nombreActualStr = actual->nombre;
            transform(nombreActualStr.begin(), nombreActualStr.end(), nombreActualStr.begin(), ::tolower);
            char *nombreActual = nombreActualStr.data();

            //Si el nombre del categoria nuevo es igual al nombre del categoria actual
            if (strcmp(nombreABuscar, nombreActual) == 0) {
                categoria.nombre = actual->nombre;
                categoria.anterior = actual->anterior;
                categoria.siguiente = actual->siguiente;
                return categoria;
            } else {
                if (actual->siguiente == nullptr) {
                    return categoria;
                }
                actual = actual->siguiente;
            }
        } while (!recorridoCompleto);
        return categoria;
    }
}

void Categorias::Imprimir()
{
    Categoria* actual = inicio;

    bool recorridoCompleto = false;
    do
    {
        if (actual == final)
        {
            recorridoCompleto = true;
        }

        cout << "Nombre: " << actual->nombre << "\n";
        cout << "\n";
        actual = actual->siguiente;
    } while (!recorridoCompleto);
}

Categoria Categorias::Inicio()
{
    return *inicio;
}

Categoria Categorias::Final()
{
    return *final;
}

Categorias Categorias::ListarCategorias(int orden) {
    //Orden = 1 ordenar ascendentemente
    //Orden = -1 ordenar descendentemente

    Categorias categoriasOrdenadas; //Lista auxiliar
    bool recorridoCompleto = false;

    if(orden == 1){ //Ordenar por nombre ascendentemente
        Categoria *actual = inicio; //nodo actual de lista original
        //Para hacer una copia de la lista
        do {
            if (actual == final) {
                recorridoCompleto = true;
            }

            //Lista vacia
            if(inicio == nullptr){
                //no se hace nada
            }
            else//Lista con nodos
            {
                Categoria* nuevo = new Categoria();
                nuevo->nombre = actual->nombre;
                nuevo->anterior = nullptr;
                nuevo->siguiente = nullptr;

                //Si la lista está vacía
                if(categoriasOrdenadas.inicio == nullptr){
                    categoriasOrdenadas.inicio = nuevo;
                    categoriasOrdenadas.final = nuevo;
                }
                else //Si ya tiene algún nodo
                {
                    nuevo->anterior = categoriasOrdenadas.final;
                    categoriasOrdenadas.final = nuevo;
                }
            }
            actual = actual->siguiente;
        } while (!recorridoCompleto);
    }
    else if(orden ==-1) //Ordenar por nombre descendentemente
    {
        Categoria *actual = final;
        do
        {
            if (actual == inicio) {
                recorridoCompleto = true;
            }

            Categoria* nuevo = new Categoria();
            string nombreActualStr = actual->nombre;

            nuevo->nombre = actual->nombre;
            string nombreNuevoStr = nuevo->nombre;
            nuevo->anterior = nullptr;
            nuevo->siguiente = nullptr;

            //Si la lista está vacía
            if(categoriasOrdenadas.inicio == nullptr){
                categoriasOrdenadas.inicio = nuevo;
                categoriasOrdenadas.final = nuevo;
            }
            else //Si ya tiene algún nodo
            {
                categoriasOrdenadas.final->siguiente = nuevo;
                nuevo->anterior = categoriasOrdenadas.final;
                categoriasOrdenadas.final = nuevo;
            }
            actual = actual->anterior;
        } while (!recorridoCompleto);
    }
    return categoriasOrdenadas;
}



