#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <regex>
#include "Equipo.h"
#include "Equipos.h"
#include "Categoria.h"



using namespace std;


Equipos::Equipos()
{
    inicio = nullptr;
    final = nullptr;
}

int Equipos::AgregarAnnio(string nombre, int annio, string descripcion, Categoria categoria, double maxPh, double minPh, bool estado, int cantSolicitudes) {
    Equipo* nuevo = new Equipo();
    nuevo->nombre = nombre;
    nuevo->annio = annio;
    nuevo->descripcion = descripcion;
    nuevo->categoria = categoria;
    nuevo->maxPh = maxPh;
    nuevo->minPh = minPh;
    nuevo->estado = estado;
    nuevo->cantSolicitudes = cantSolicitudes;
    nuevo->anterior = nullptr;
    nuevo->siguiente = nullptr;

    //Lista vacia
    if (inicio == nullptr) {
        inicio = nuevo;
        inicio->siguiente = inicio;
        inicio->anterior = final;
        final = inicio;
        return 1;
    }
    //Lista con nodos
    else {
        //Recorro la lista comparando los annios de los equipos
        Equipo* actual = inicio;
        bool recorridoCompleto = false;

        do {
            if (actual == final) {
                recorridoCompleto = true;
            }

            //Si el annio del equipo nuevo es menor al annio del equipo actual
            if (nuevo->annio < actual->annio) {
                //Si el equipo actual es el inicio
                if (actual == inicio) {
                    nuevo->siguiente = actual;
                    actual->anterior = nuevo;
                    inicio = nuevo;
                    inicio->anterior = final;
                    final->siguiente = inicio;
                }
                else {
                    nuevo->siguiente = actual;
                    nuevo->anterior = actual->anterior;
                    actual->anterior->siguiente = nuevo;
                    actual->anterior = nuevo;
                }
                return 1;
            }
            else if (nuevo->annio > actual->annio) {
                //Si el equipo actual es el final
                if (actual == final) {
                    nuevo->anterior = actual;
                    actual->siguiente = nuevo;
                    nuevo->siguiente = inicio;
                    final = nuevo;
                    inicio->anterior = final;
                    return 1;
                }
            }
            else {
                //Comparo los nombres de los equipos
                //Nombre del equipo nuevo
                string nombreNuevoStr = nuevo->nombre;
                transform(nombreNuevoStr.begin(), nombreNuevoStr.end(), nombreNuevoStr.begin(), ::tolower);
                const char* nombreNuevo = nombreNuevoStr.data();

                //Nombre del equipo actual
                string nombreActualStr = actual->nombre;
                transform(nombreActualStr.begin(), nombreActualStr.end(), nombreActualStr.begin(), ::tolower);
                const char* nombreActual = nombreActualStr.data();

                //Si el nombre del equipo nuevo es menor al nombre del equipo actual
                if (strcmp(nombreNuevo, nombreActual) < 0) {
                    //Si el equipo actual es el inicio
                    if (actual == inicio) {
                        nuevo->siguiente = actual;
                        actual->anterior = nuevo;
                        inicio = nuevo;
                        inicio->anterior = final;
                        final->siguiente = inicio;
                    }
                    else {
                        nuevo->siguiente = actual;
                        nuevo->anterior = actual->anterior;
                        actual->anterior->siguiente = nuevo;
                        actual->anterior = nuevo;
                    }
                    return 1;
                }
                else if (strcmp(nombreNuevo, nombreActual) > 0) {
                    //Si el equipo actual es el final
                    if (actual == final) {
                        nuevo->anterior = actual;
                        actual->siguiente = nuevo;
                        nuevo->siguiente = inicio;
                        final = nuevo;
                        inicio->anterior = final;
                        return 1;
                    }
                }
            }
            actual = actual->siguiente;
        } while (!recorridoCompleto && inicio != final);
        return 0;
    }
}

int Equipos::Agregar(Equipo equipo){
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
        } while (!recorridoCompleto && inicio != final);
    }
    return 0;
}

int Equipos::Retirar(std::string nombreEquipo) {

    //Almacendando el nombre del equipo como puntero y el uso de la función .data() para poder usarlo en la comparación
    const char* nombreEquipoPtr = nombreEquipo.data();

    //Si la lista está vacía
    if (inicio == nullptr)
    {
        return 0;
    }
    else {
        Equipo* actual = inicio;
        bool recorridoCompleto = false;

        do {
            if (actual == final)
            {
                recorridoCompleto = true;
            }

            const  char* nombreEquipoActualPtr = actual->nombre.data();
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

        } while (!recorridoCompleto && inicio != final);
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
        const char* nombreABuscar = nombreABuscarStr.data();
        bool recorridoCompleto = false;

        do {
            if (actual == final) {
                recorridoCompleto = true;
            }

            string nombreActualStr = actual->nombre;
            transform(nombreActualStr.begin(), nombreActualStr.end(), nombreActualStr.begin(), ::tolower);
            const char* nombreActual = nombreActualStr.data();

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
                equipo.anterior = actual->anterior;
                equipo.siguiente = actual->siguiente;
                return equipo;
            }
            else {
                if (actual->siguiente == inicio) {
                    return equipo;
                }
                actual = actual->siguiente;
            }
        } while (!recorridoCompleto && inicio != final);
        return equipo;
    }
}

int Equipos::Modificar(Equipo equipo) {
    //Lista vacia
    if (inicio == nullptr) {
        return 0;
    }
    //Lista con nodos
    else {
        //Recorro la lista para ver si existe el equipo
        Equipo* actual = inicio;
        string nombreNuevoStr = equipo.nombre;
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
                actual->annio = equipo.annio;
                actual->descripcion = equipo.descripcion;
                actual->categoria = equipo.categoria;
                actual->maxPh = equipo.maxPh;
                actual->minPh = equipo.minPh;
                actual->estado = equipo.estado;
                actual->cantSolicitudes = equipo.cantSolicitudes;
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
    bool recorridoCompleto = false;
    do
    {
        if (actual == final)
        {
            recorridoCompleto = true;
        }

        cantidad++;
        actual = actual->siguiente;
    } while (!recorridoCompleto && inicio != final);
    return cantidad;
}

void Equipos::Imprimir()
{
    Equipo* actual = inicio;
    Equipo* inicio = this->inicio;
    Equipo* final = this->final;

    bool recorridoCompleto = false;

    cout << "==========================================================================" << endl;
    cout << "||                      Lista de Equipos | cen-ph0                      ||" << endl;
    cout << "==========================================================================" << endl;

    if (inicio == nullptr)
    {
		cout << "No hay equipos en la lista." << endl;
		return;
    }
    else 
    {
        do
        {
            if (actual == final)
            {
                recorridoCompleto = true;
            }

            cout << "Nombre: " << actual->nombre << "\n";
            cout << "Anio: " << actual->annio << "\n";
            cout << "Descripcion: " << actual->descripcion << "\n";
            cout << "Categoria: " << actual->categoria.nombre << "\n";
            cout << "Max pH: " << actual->maxPh << "\n";
            cout << "Min pH: " << actual->minPh << "\n";
            cout << "Estado: " << ((actual->estado == 1) ? "Alquilado." : "Disponible.") << "\n";
            cout << "Cantidad de solicitudes: " << actual->cantSolicitudes << "\n";
            cout << "==========================================================================\n";
            actual = actual->siguiente;
        } while (!recorridoCompleto && inicio != final);
	}
}

Equipos Equipos::CopiarLista() {
    Equipos equiposCopia; //Lista auxiliar
    Equipo* actual = inicio; //nodo actual de lista original
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
            if (equiposCopia.inicio == nullptr) {
                equiposCopia.inicio = nuevo;
                equiposCopia.final = nuevo;
            }
            else //Si ya tiene algún nodo
            {
                nuevo->anterior = equiposCopia.final;
                nuevo->siguiente = equiposCopia.inicio;
                equiposCopia.final->siguiente = nuevo;
                equiposCopia.final = nuevo;
            }
        }
        actual = actual->siguiente;
    } while (!recorridoCompleto && inicio != final);
    return equiposCopia;
}

Equipos Equipos::ListarEquipos(int param, int orden) {
    //Param = 1 ordenar por nombre
    //Param = 2 ordenar por annio
    //Orden = 1 ordenar ascendentemente
    //Orden = -1 ordenar descendentemente

    Equipos equiposOrdenados; //Lista auxiliar
    bool recorridoCompleto = false;

    if (param == 1 && orden == 1) { //Ordenar por nombre ascendentemente
        equiposOrdenados = CopiarLista();
    }
    else if (param == 1 && orden == -1) //Ordenar por nombre descendentemente
    {
        Equipo* actual = final;
        do
        {
            if (actual == inicio) {
                recorridoCompleto = true;
            }

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
        } while (!recorridoCompleto && inicio != final);
    }
    else if (param == 2 && orden == 1) //Ordenar por annio ascendentemente
    {
        Equipo* actual = inicio;
        do
        {
            if (actual == final) {
                recorridoCompleto = true;
            }
            equiposOrdenados.AgregarAnnio(actual->nombre, actual->annio, actual->descripcion, actual->categoria, actual->maxPh, actual->minPh, actual->estado, actual->cantSolicitudes);
            actual = actual->siguiente;
        } while (!recorridoCompleto && inicio != final);
    }
    else if (param == 2 && orden == -1) //Ordenar por annio descendentemente
    {
        Equipos equiposAux;
        Equipo* actual = inicio;
        do
        {
            if (actual == final) {
                recorridoCompleto = true;
            }
            equiposAux.AgregarAnnio(actual->nombre, actual->annio, actual->descripcion, actual->categoria, actual->maxPh, actual->minPh, actual->estado, actual->cantSolicitudes);
            actual = actual->siguiente;
        } while (!recorridoCompleto && inicio != final);

        recorridoCompleto = false;
        actual = equiposAux.final;

        //Agrego los equipos en la lista de equipos ordenados
        do
        {
            if (actual == equiposAux.inicio) {
                recorridoCompleto = true;
            }

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
        } while (!recorridoCompleto && inicio != final);
    }
    return equiposOrdenados;
}

Equipos Equipos::ListarEquiposBuscarNombre(std::string hilera) {
    Equipos equiposBuscados; //Lista auxiliar
    string hileraLC = hilera;
    transform(hileraLC.begin(), hileraLC.end(), hileraLC.begin(), ::tolower);
    regex regEx(hileraLC);

    //Lista vacia
    if (inicio == nullptr) {
        return equiposBuscados;
    }
    //Lista con nodos
    else {
        //Recorro la lista para ver si existe el equipo
        Equipo* actual = inicio;
        bool recorridoCompleto = false;

        do {
            if (actual == final) {
                recorridoCompleto = true;
            }

            string nombreActualLC = actual->nombre;
            transform(nombreActualLC.begin(), nombreActualLC.end(), nombreActualLC.begin(), ::tolower);

            //Si el nombre del equipo nuevo es igual al nombre del equipo actual
            if (regex_search(nombreActualLC, regEx)) {
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
                if (equiposBuscados.inicio == nullptr) {
                    equiposBuscados.inicio = nuevo;
                    equiposBuscados.final = nuevo;
                }
                else //Si ya tiene algún nodo
                {
                    nuevo->anterior = equiposBuscados.final;
                    nuevo->siguiente = equiposBuscados.inicio;
                    equiposBuscados.final->siguiente = nuevo;
                    equiposBuscados.final = nuevo;
                    equiposBuscados.inicio->anterior = equiposBuscados.final;
                }
            }
            actual = actual->siguiente;
        } while (!recorridoCompleto && inicio != final);
        return equiposBuscados;
    }
}

Equipos Equipos::ListarEquiposRangoAnnios(int annioInicial, int annioFinal) {
    Equipos equiposBuscados; //Lista auxiliar

    //Lista vacia
    if (inicio == nullptr) {
        return equiposBuscados;
    }
    //Lista con nodos
    else {
        //Recorro la lista para ver si existe el equipo
        Equipo* actual = inicio;
        bool recorridoCompleto = false;

        do {
            if (actual == final) {
                recorridoCompleto = true;
            }

            if (actual->annio >= annioInicial && actual->annio <= annioFinal) {
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
                if (equiposBuscados.inicio == nullptr) {
                    equiposBuscados.inicio = nuevo;
                    equiposBuscados.final = nuevo;
                }
                else //Si ya tiene algún nodo
                {
                    nuevo->anterior = equiposBuscados.final;
                    nuevo->siguiente = equiposBuscados.inicio;
                    equiposBuscados.final->siguiente = nuevo;
                    equiposBuscados.final = nuevo;
                    equiposBuscados.inicio->anterior = equiposBuscados.final;
                }
            }
            actual = actual->siguiente;
        } while (!recorridoCompleto && inicio != final);
        return equiposBuscados;
    }
}

Equipos Equipos::ListarEquiposRangopH(double pHMinp, double pHMaxp) {
    Equipos equiposBuscados; //Lista auxiliar

    //Lista vacia
    if (inicio == nullptr) {
        return equiposBuscados;
    }
    //Lista con nodos
    else {
        //Recorro la lista para ver si existe el equipo
        Equipo* actual = inicio;
        bool recorridoCompleto = false;

        do {
            if (actual == final) {
                recorridoCompleto = true;
            }

            if (actual->minPh >= pHMinp && actual->maxPh <= pHMaxp) {
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
                if (equiposBuscados.inicio == nullptr) {
                    equiposBuscados.inicio = nuevo;
                    equiposBuscados.final = nuevo;
                }
                else //Si ya tiene algún nodo
                {
                    nuevo->anterior = equiposBuscados.final;
                    nuevo->siguiente = equiposBuscados.inicio;
                    equiposBuscados.final->siguiente = nuevo;
                    equiposBuscados.final = nuevo;
                    equiposBuscados.inicio->anterior = equiposBuscados.final;
                }
            }
            actual = actual->siguiente;
        } while (!recorridoCompleto && inicio != final);
        return equiposBuscados;
    }
}

Equipos Equipos::ListarEquiposCantSolicitudes(int cantSolicitudes) {
    Equipos equiposBuscados; //Lista auxiliar

    //Lista vacia
    if (inicio == nullptr) {
        return equiposBuscados;
    }
    //Lista con nodos
    else {
        //Recorro la lista para ver si existe el equipo
        Equipo* actual = inicio;
        bool recorridoCompleto = false;

        do {
            if (actual == final) {
                recorridoCompleto = true;
            }

            if (actual->cantSolicitudes < cantSolicitudes) {
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
                if (equiposBuscados.inicio == nullptr) {
                    equiposBuscados.inicio = nuevo;
                    equiposBuscados.final = nuevo;
                }
                else //Si ya tiene algún nodo
                {
                    nuevo->anterior = equiposBuscados.final;
                    nuevo->siguiente = equiposBuscados.inicio;
                    equiposBuscados.final->siguiente = nuevo;
                    equiposBuscados.final = nuevo;
                    equiposBuscados.inicio->anterior = equiposBuscados.final;
                }
            }
            actual = actual->siguiente;
        } while (!recorridoCompleto && inicio != final);
        return equiposBuscados;
    }
}

Equipos Equipos::EliminarEquiposCantSolicitudes(int cantSolicitudes) {
    Equipos equiposEliminados; //Lista auxiliar

    //Lista vacia
    if (inicio == nullptr) {
        return equiposEliminados;
    }
    //Lista con nodos
    else {
        //Recorro la lista para ver si existe el equipo
        Equipo* actual = inicio;
        bool recorridoCompleto = false;

        do {
            Equipo* borrar = actual;
            if (actual == final) {
                recorridoCompleto = true;
            }

            if (actual->cantSolicitudes < cantSolicitudes) {
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
                if (equiposEliminados.inicio == nullptr) {
                    equiposEliminados.inicio = nuevo;
                    equiposEliminados.final = nuevo;
                }
                else //Si ya tiene algún nodo
                {
                    nuevo->anterior = equiposEliminados.final;
                    nuevo->siguiente = equiposEliminados.inicio;
                    equiposEliminados.final->siguiente = nuevo;
                    equiposEliminados.final = nuevo;
                    equiposEliminados.inicio->anterior = equiposEliminados.final;
                }

                //Eliminando el equipo de la lista original
                //Si es el nodo inicial
                if (actual == inicio)
                {
                    final->siguiente = actual->siguiente;
                    inicio = actual->siguiente;
                    inicio->anterior = final;
                }//si es el nodo final
                else if (actual == final)
                {
                    inicio->anterior = actual->anterior;
                    actual->anterior->siguiente = inicio;
                    final = actual->anterior;
                }
                else //si es cualquier otro nodo
                {
                    actual->anterior->siguiente = actual->siguiente;
                    actual->siguiente->anterior = actual->anterior;
                }
                delete borrar;
            }
            actual = actual->siguiente;
        } while (!recorridoCompleto && inicio != final);
    }
    return equiposEliminados;
}




