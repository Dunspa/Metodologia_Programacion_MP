//////////////////////////////////////////////////////////////////////////
//
// Metodolog�a de la Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
// Examen pr�cticas 1 (2016 - 2017)
// Definici�n de la funci�n "Lista"
//
// Funciones que trabajan con listas din�micas de datos de tipo TipoBase
//
//////////////////////////////////////////////////////////////////////////

#include "Lista.h"
#include <iostream>

using namespace std;

void LeeLista(Lista & l){
   PNodo primero; // Para el primer nodo 
   PNodo fin;     // Para el �ltimo nodo
   TipoBase valor;

   cout << "Introduzca un valor en la lista (negativo para terminar): ";
   cin >> valor;

   if (valor >= 0){

      // El primer nodo se procesa distinto a los dem�s
      primero = new Nodo;
      primero->valor = valor;
      primero->sig = 0; // Este nodo es, de momento, el �ltimo

      fin = primero;

      cout << "Introduzca un valor en la lista (negativo para terminar): ";
      cin >> valor;

      while (valor >= 0){

         fin->sig = new Nodo; // Reservar memoria para el siguiente nodo
         fin = fin->sig;      // Actualizar nodo

         fin->valor = valor;
         fin->sig = 0;        // Este nodo es, de momento, el �ltimo         

         cout << "Introduzca un valor en la lista (negativo para terminar): ";
         cin >> valor;   

      }

      l = primero;   // Se accede a la lista con el primer nodo

   }
}

void LiberaLista(Lista & l){

   // Comprueba previamente que la lista no est� vac�a
   if (!ListaVacia(l)){

      PNodo aux = l; // Para recorrer los nodos

      while (aux != 0){

         aux = aux->sig;
         delete l;
         l = aux;

      }

      delete l;   // Se borra el �ltimo nodo que queda

   }

   l = 0;   // El puntero que da acceso a la lista queda con valor 0

}

void PintaLista(const Lista l){

   // Comprueba previamente que la lista no est� vac�a
   if (!ListaVacia(l)){

      PNodo aux = l; // Auxiliar para recorrer los nodos

      cout << "Lista: " << endl;
      while (aux != 0){

         cout << (aux->valor) << endl;
         aux = aux->sig;

      }
   }
}

int CuentaElementos(const Lista l){

   int elementos = 0;

   if (!ListaVacia(l)){

      PNodo aux = l; // Auxiliar para recorrer los nodos

      while (aux != 0){

         elementos++;
         aux = aux->sig;

      }
   }

   return elementos;

}

bool ListaVacia(const Lista l){

   return (l == 0);

}

// Devuelve una nueva lista, nueva, conteniendo algunos valores seleccionados 
// de la lista l. Los valores seleccionados en la nueva lista est�n en el 
// mismo orden en el que aparecen en la lista l.
// La lista l no se modifica.
// El criterio de selecci�n es el siguiente: se selecciona el nodo de la 
// posici�n "inicio", despu�s el que est� "salto" posiciones por delante, 
// y as� sucesivamente.
void Selecciona(Lista & nueva, const Lista l, const int inicio, const int salto){

   // Comprueba previamente que la lista no est� vac�a
   if (!ListaVacia(l)){

      PNodo aux = l; // Auxiliar para recorrer los nodos de la lista

      // El primer nodo se procesa distinto a los dem�s
      nueva = new Nodo;
      nueva->valor = l->valor;
      nueva->sig = 0;   // Este nodo es, de momento, el �ltimo
      aux = aux->sig;

      PNodo n_aux = nueva; // Auxiliar para recorrer los nodos de la nueva lista
      int n = 1;           // Va contando cuantos nodos se van recorriendo

      while (aux != 0){

         if (n % salto == 0){

            n_aux->sig = new Nodo;  // Reservar memoria para el siguiente nodo
            n_aux = n_aux->sig;

            n_aux->valor = aux->valor;
            n_aux->sig = 0;         // Este nodo es, de momento, el �ltimo
         
         }

         aux = aux->sig;
         n++;

      }
   }
}