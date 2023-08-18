#ifndef ESTRUCTURADEDATOS_CATEGORIA_H
#define ESTRUCTURADEDATOS_CATEGORIA_H

#include <string>

using namespace std;

class Categoria
{
public:
    Categoria* anterior;
    string nombre;
    Categoria* siguiente;
};

#endif //ESTRUCTURADEDATOS_CATEGORIA_H
