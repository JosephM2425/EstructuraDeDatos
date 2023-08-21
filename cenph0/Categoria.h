#ifndef CATEGORIA_H
#define CATEGORIA_H

#include <string>

using namespace std;

class Categoria
{
public:
    Categoria* anterior;
    int id;
    string nombre;
    Categoria* siguiente;
};

#endif //ESTRUCTURADEDATOS_CATEGORIA_H
