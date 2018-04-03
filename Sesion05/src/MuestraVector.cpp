//////////////////////////////////////////////////////////////////////////
//
// Metodolog�a de la Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
// Relaci�n de problemas I
// Definici�n de la funci�n "MuestraVector" necesaria para el programa:
// I_MezclaVectores
//
// Muestra el contenido de un vector junto a un mensaje
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "MuestraVector.h"
using namespace std;

void MuestraVector(const char *mensaje, int v[], int util, int n){
   int n_datos = n;
   cout << mensaje << endl;

   for (int i = 0 ; i < util ; i++){
      // Si se han pintado n n�mero de datos, se pasa a una siguiente l�nea
      if (n_datos == n){
         cout << endl;
         n_datos = 0;
      }
      
      // Aumenta el contador de datos por l�nea y se pinta ese dato
      n_datos++;
      cout << " " << *(v + i);
   }

   cout << endl;
}