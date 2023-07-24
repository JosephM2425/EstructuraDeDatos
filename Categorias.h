#ifndef ESTRUCTURADEDATOS_CATEGORIAS_H
#define ESTRUCTURADEDATOS_CATEGORIAS_H

#include <string>
#include "Categoria.h"

using namespace std;

class Categorias
{
private:
    Categoria* inicio;
    Categoria* final;

public:
    Categorias();

    Categorias(Categorias *inicio, Categorias *final);

    Categorias(Categoria *inicio, Categoria *final);

    void Agregar(string nombre);
    void Retirar(string nombreCategoria);
    void Modificar(string categoria, string nombreCategoria);
    Categoria Consultar(string nombreCategoria);
    Categoria Inicio();
    Categoria Final();
    Categorias listarCategoriaAsc();
    Categorias listarCategoriaDesc();
};

#endif //ESTRUCTURADEDATOS_CATEGORIAS_H
