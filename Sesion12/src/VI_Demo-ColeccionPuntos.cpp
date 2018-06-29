//////////////////////////////////////////////////////////////////////////
//
// Metodolog�a de la Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
// Relaci�n de problemas VI, Ejercicio 9
// Programa principal
//
// Prueba m�todos de la clase ColeccionPuntos2D
// Toma los puntos de un fichero de texto en el argumento
// PRECONDICI�N: La primera l�nea del fichero contiene "PUNTOS"
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "ColeccionPuntos2D.h"
using namespace std;

int main(int argc, char ** argv){

   // Comprobar que el n�mero de argumentos introducido es correcto
   if (argc != 2){

      cerr << "Error: n�mero de argumentos introducido incorrecto" << endl;

      exit (1);

   }

   const char * nombre = "puntos";

   // Crea la colecci�n a partir del fichero
   ColeccionPuntos2D coleccion (nombre);

   // Muestra los puntos
   for (int i = 0 ; i < coleccion.GetNum() ; i++){

      cout << "Punto " << i << ": " << endl;
      cout << "X: " << coleccion[i].GetX() << " Y: " << coleccion[i].GetY();
      cout << endl;

   }

   return 0;

}