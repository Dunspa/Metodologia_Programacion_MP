//////////////////////////////////////////////////////////////////////////
//
// Metodolog�a de la Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
// Relaci�n de problemas I, Ejercicio 20
// Definici�n de la funci�n "MezclaVectores" necesaria para el programa:
// I_MezclaArrays 
//
// Mezcla ordenadamente los datos de dos vectores y devuelve su tama�o
//
//////////////////////////////////////////////////////////////////////////

#include "OrdenaVector.h"
#include "MezclaVectores.h"

int MezclaVectores (int mezcla[], int v1[], int util_v1, int v2[], int util_v2){
   // El tama�o del vector mezcla es la suma de los dos
   int util_mezcla = util_v1 + util_v2;
   int i;
   
   /* Se introducen en el vector mezcla los valores de v1, y seguidamente los 
   de v2 */
   for (i = 0 ; i < util_v1 ; i++){
      *(mezcla + i) = *(v1 + i);
   }

   for (int j = i ; j < util_v2 ; j++){
      *(mezcla + j) = *(v2 + j);
   }

   // Una vez meclado el vector, se ordena de menor a mayor
   OrdenaVector(mezcla, util_mezcla);

   return util_mezcla;
}