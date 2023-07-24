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
    Categorias(Categoria *inicio, Categoria *final);

    int Agregar(string nombre);
    int Retirar(string nombreCategoria);
    Categoria Consultar(string nombreCategoria);
    Categoria Inicio();
    Categoria Final();
    void Imprimir();
    Categorias ListarCategorias(int orden);
};

#endif //ESTRUCTURADEDATOS_CATEGORIAS_H
