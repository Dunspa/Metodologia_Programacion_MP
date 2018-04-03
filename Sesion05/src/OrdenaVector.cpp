//////////////////////////////////////////////////////////////////////////
//
// Metodolog�a de la Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
// Relaci�n de problemas I, Ejercicio 20
// Definici�n de la funci�n "OrdenaVector" 
//
// Ordena un vector de enteros de menor a mayor
//
//////////////////////////////////////////////////////////////////////////

#include <cstring>
#include "OrdenaVector.h"

// Ordenaci�n de un vector por inserci�n
void OrdenaVector(int *vector, int total_utilizados){
   int a_desplazar, i;

   for (int izda = 1; izda < total_utilizados; izda++){
      a_desplazar = *(vector + izda);

      for (i = izda; i > 0 && a_desplazar < *(vector + i - 1); i--)
         *(vector + i) = *(vector + i - 1);
      
      *(vector + i) = a_desplazar;
   }
}