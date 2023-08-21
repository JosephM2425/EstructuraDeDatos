#ifndef CATEGORIAS_H
#define CATEGORIAS_H

#include <string>
#include "Categoria.h"

using namespace std;

class Categorias
{
private:
    Categoria* inicio;
    Categoria* final;
    Categorias CopiarLista();
public:
    Categorias();
    int Agregar(Categoria categoria);
    int Retirar(string nombreCategoria);
    Categoria Consultar(string nombreCategoria);
    int Modificar(string nombre);
    Categoria Inicio();
    Categoria Final();
    void Imprimir();
    Categorias ListarCategorias(int orden);
};

#endif //ESTRUCTURADEDATOS_CATEGORIAS_H
