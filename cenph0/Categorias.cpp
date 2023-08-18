#include "Categorias.h"

//Categorias::Categorias() {}
//
//Categorias::Categorias(Categoria *inicio, Categoria *final) : inicio(inicio), final(final) {}
//
//void Categorias::Agregar(string nombre)
//{
//    Categoria* nuevaCategoria = new Categoria();
//    nuevaCategoria->nombre = nombre;
//
//    if (inicio == nullptr)
//    {
//        inicio = nuevaCategoria;
//        final = nuevaCategoria;
//    }
//    else
//    {
//        final->siguiente = nuevaCategoria;
//        nuevaCategoria->anterior = final;
//        final = nuevaCategoria;
//    }
//}
//
//void Categorias::Retirar(string nombre)
//{
//	Categoria* actual = inicio;
//
//	while(actual != nullptr)
//	{
//		if (actual->nombre == nombre)
//		{
//
//		 	if (actual == inicio)
//            {
//                inicio = actual->siguiente;
//                inicio->anterior = nullptr;
//            }
//            else if (actual == final)
//            {
//                final = actual->anterior;
//                final->siguiente = nullptr;
//            }
//            else
//            {
//                actual->anterior->siguiente = actual->siguiente;
//                actual->siguiente->anterior = actual->anterior;
//            }
//        	delete actual;
//		}
//		actual = actual->siguiente;
//	}
//
//}
//
//void Categorias::Modificar(Categorias& lista, string categoria, string categoriaNueva)
//{
//
//	Categoria* actual = list.inicio;
//
//	while(actual != nullptr)
//	{
//		if (actual->nombre == categoria)
//		{
//			actual->nombre = categoriaNueva;
//		}
//		actual = actual->siguiente;
//	}
//}
//
//Categorias Categorias::listarCategoriaAsc(Categorias& lista)
//{
//	Categoria* actual = lista.inicio;
//	while (actual != nullptr)
//    {
//        cout << actual->nombre << endl;
//        actual = actual->siguiente;
//    }
//}
//
//Categorias Categorias::listarCategoriaDesc(Categorias& lista)
//{
//	Categoria* actual = lista.final;
//	while (actual != nullptr)
//    {
//        cout << actual->nombre << endl;
//        actual = actual->siguiente;
//    }
//}



