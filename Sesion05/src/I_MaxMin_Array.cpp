//////////////////////////////////////////////////////////////////////////
//
// Metodolog�a de la Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
// Relaci�n de problemas I, Ejercicio 20
// Programa principal
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "MaximoMinimo.h"
#include "VectorAleatorio.h"
using namespace std;

int main(){
   const int TOPE = 100;
   int vector[TOPE], minimo, maximo, izda, dcha;
   int *ptr_dcha, *ptr_izda;
   
   // Lectura de datos
   cout << "Valores del vector: ";
   cin >> minimo >> maximo;
   cout << "Extremos entre los cuales buscar el m�nimo y el m�ximo: ";
   cin >> izda >> dcha;

   // Llamada a la funci�n que rellena el vector con enteros aleatorios
   VectorAleatorio(vector, izda, dcha, minimo, maximo);

   // Punteros que delimitan donde realizar la b�squeda
   ptr_izda = &vector[izda];
   ptr_dcha = &vector[dcha];

   // Llamada a la funci�n que calcula el m�nimo y el m�ximo valor del vector
   MaximoMinimo(ptr_izda, ptr_dcha, minimo, maximo);

   cout << "M�nimo: " << minimo << endl;
   cout << "M�ximo: " << maximo << endl;

   return 0;
}