//////////////////////////////////////////////////////////////////////////
//
// Metodolog�a de la Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
// Relaci�n de problemas I
// Definici�n de la funci�n "VectorAleatorio" necesaria para los programas:
// I_MaxMin_Array, I_PosMayor y I_MezclaArrays 
//
// Rellena un vector de n�meros enteros aleatorios entre dos valores dados
//
//////////////////////////////////////////////////////////////////////////

#include "VectorAleatorio.h"
#include <cstdlib>
#include <ctime>

void VectorAleatorio(int *v, int izda, int dcha, int min, int max){
   const int MY_MAX_RAND = max;
   time_t t;

   srand ((int) time(&t)); // Inicializa el generador con
                           // el reloj del sistema
   for (int i = izda ; i < dcha ; i++)
      v[i] = (rand() % MY_MAX_RAND + min);
}