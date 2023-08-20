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

    Categorias(Categorias* inicio, Categorias* final);

    Categorias(Categoria* inicio, Categoria* final);

    int Agregar(string nombre);
    int Retirar(string nombreCategoria);
    int Modificar(string nombreCategoria);
    Categoria Consultar(string nombreCategoria);
    Categoria Inicio();
    Categoria Final();
    Categorias CopiarLista();
    Categorias ListarCategorias(int param, int orden);
};

#endif //ESTRUCTURADEDATOS_CATEGORIAS_H
