//////////////////////////////////////////////////////////////////////////
//
// Metodolog�a de la Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
// Relaci�n de problemas II, Ejercicio 13
// Programa principal
//
// Demostraci�n de las funciones desarrolladas en la biblioteca de Listas:
// EstaOrdenada y OrdenaSeleccionLista
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Lista.h"
using namespace std;

int main(){
   Lista lista;

   // Se pide una lista de n�meros y se muestra 
   LeeLista(lista);
   PintaLista(lista);

   if (EstaOrdenada(lista)){
      cout << "La lista est� ordenada" << endl;
   }
   else{
      cout << "La lista no est� ordenada" << endl;
   }

   // Se ordena la lista, se muestra, y comprueba si est� ordenada
   OrdenaSeleccionLista(lista);
   PintaLista(lista);

   if (EstaOrdenada(lista)){
      cout << "La lista est� ordenada" << endl;
   }
   else{
      cout << "La lista no est� ordenada" << endl;
   }

   return 0;
}