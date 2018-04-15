//////////////////////////////////////////////////////////////////////////
//
// Metodolog�a de la Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
// Relaci�n de problemas II, Ejercicio 14
// Programa principal
//
// Demostraci�n de las funciones desarrolladas en la biblioteca de Listas:
// InsertaOrdenadamente y EliminaValor
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Lista.h"

using namespace std;

int main(){
   Lista lista;
   TipoBase insertar, eliminar;

   // Se lee una lista y se muestra
   LeeLista(lista);
   PintaLista(lista);

   // Se pide un valor de la lista a insertar
   cout << "Introduzca el valor que quiere insertar en la lista: ";
   cin >> insertar;
   InsertaOrdenadamente(lista, insertar);
   PintaLista(lista);

   // Se pide un valor de la lista a eliminar
   cout << "Introduzca el valor que quiere eliminar de la lista: ";
   cin >> eliminar;
   EliminaValor(lista, eliminar);
   PintaLista(lista);

   return 0;
}