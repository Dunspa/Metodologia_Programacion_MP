//////////////////////////////////////////////////////////////////////////
//
// Metodolog�a de la Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
// Relaci�n de problemas IV, Ejercicio 11
// Programa principal
//
// Realiza varias pruebas sobre la clase "RedCiudades"
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "RedCiudades.h"

using namespace std;

int main(){
   // Inicializa la red con los datos del problema mediante el constructor adhoc
   RedCiudades red (5);

   cout << "Red de ciudades: ";
   for (int i = 0 ; i < red.NumCiudades() ; i++){

      for (int j = 0 ; j < red.NumCiudades() ; j++){

         cout << red.Distancia(i, j) << " ";

      }

      cout << endl;

   }

   cout << "La ciudad mejor conectada es la ciudad n�mero: " 
        << red.CiudadMejorConectada() << endl;

   cout << "La ciudad intermedia m�s econ�mica entre la 2 y la 5 es la n�mero: "
        << red.MejorEscalaEntre(1, 4) << endl; 

   return 0;

}