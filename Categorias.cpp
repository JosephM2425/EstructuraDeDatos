#include "Categorias.h"

Categorias::Categorias() {}

Categorias::Categorias(Categoria *inicio, Categoria *final) : inicio(inicio), final(final) {}

void Categorias::Agregar(string nombre)
{
    Categoria* nuevaCategoria = new Categoria();
    nuevaCategoria->nombre = nombre;

    if (inicio == nullptr)
    {
        inicio = nuevaCategoria;
        final = nuevaCategoria;
    }
    else
    {
        final->siguiente = nuevaCategoria;
        nuevaCategoria->anterior = final;
        final = nuevaCategoria;
    }
}
