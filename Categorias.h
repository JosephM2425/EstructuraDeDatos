#ifndef ESTRUCTURADEDATOS_CATEGORIAS_H
#define ESTRUCTURADEDATOS_CATEGORIAS_H

#include <string>
#include "Categoria.h"

using namespace std;

class Categorias
{
private:
    Categorias* inicio;
    Categorias* final;

public:
    Categorias();
    int Agregar(string nombre);
    int Retirar(string nombreCategoria);
    int Modificar(string nombreCategoria);
    Categoria Consultar(string nombreCategoria);
    Categoria Inicio();
    Categoria Final();
    Categorias ListarCategorias(int orden);
};

#endif //ESTRUCTURADEDATOS_CATEGORIAS_H
