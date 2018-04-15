//////////////////////////////////////////////////////////////////////////
//
// Metodolog�a de la Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
// Relaci�n de problemas II, Ejercicio 12
// Programa principal
//
// Demostraci�n de las funciones desarrolladas en la biblioteca de Listas:
// LeeLista, PintaLista, LiberaLista, ListaVacia y CuentaElementos
//
// Adem�s desarrolla los siguientes c�lculos ajenos a la biblioteca:
// Media, Varianza
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cmath>
#include "Lista.h"

using namespace std;

double Media(const Lista);
double Varianza(const Lista);

int main(){
   Lista lista, aleatoria;
   int tamanio, min, max;

   // Lectura de una lista
   LeeLista(lista);

   // Muestra por pantalla la lista
   PintaLista(lista);

   // Muestra cuantos elementos tiene la lista
   cout << "La lista tiene " << CuentaElementos(lista) << " elementos" << endl;

   // Muestra la media de la lista
   cout << "Media de la lista: " << Media(lista) << endl;

   // Muestra la varianza de la lista
   cout << "Varianza de la lista: " << Varianza(lista) << endl;

   // Se libera el espacio en memoria de la lista
   LiberaLista(lista);

   // Comprueba si la lista est� vac�a o no
   if (ListaVacia(lista)){
      cout << "La lista est� vac�a" << endl;
   }
   else{
      cout << "La lista no est� vac�a" << endl;
   }

	// Crea una lista con n�meros aleatorios
	cout << "Introduzca entre qu� valores rellenar la lista: ";
	cin >> min >> max;
	cout << "Introduzca el tama�o de la lista: ";
	cin >> tamanio;
	CreaListaAleatoria(aleatoria, min, max, tamanio);
	PintaLista(aleatoria);

   return 0;
}

// Calcula la media de los datos de una lista
double Media(const Lista l){

   // Comprueba antes si la lista est� vac�a
	if (!ListaVacia(l)){
      
      double total = 0;
		PNodo aux = l;    // Colocar "aux" al principio

		while (aux != 0){

			total += aux->valor; // Sumatoria de todos los valores de la lista
			aux = aux->sig;      // Actualizar "aux"

		}

      return (total/CuentaElementos(l));
	}
   else{
      return NAN; // Si la lista est� vac�a, devuelve NAN
   }
}

// Calcula la varianza de los datos de una lista
double Varianza(const Lista l){

   // Comprueba antes si la lista est� vac�a
	if (!ListaVacia(l)){

      double total = 0;
		PNodo aux = l;    // Colocar "aux" al principio

		while (aux != 0){

			total += pow(aux->valor, 2); // Sumatoria de todos los valores de la lista
			aux = aux->sig;      // Actualizar "aux"

		}

      return (total/CuentaElementos(l) - pow(Media(l), 2));
	}
   else{
      return NAN; // Si la lista est� vac�a, devuelve NAN
   }
}