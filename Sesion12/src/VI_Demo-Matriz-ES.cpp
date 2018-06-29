//////////////////////////////////////////////////////////////////////////
//
// Metodolog�a de la Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
// Relaci�n de problemas VI, Ejercicio 7
// Programa principal
//
// Prueba tres nuevos m�todos de la clase Matriz2D_1 que usan un fichero de 
// texto en el que los datos est�n separados por el fin de l�nea
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Matriz2D_1.h"
using namespace std;

int main(){

   const char * nombre = "datosmatriz1";

   // Crea una matriz con los datos de un fichero
   Matriz2D_1 m(nombre);

   cout << "Matriz: " << endl;
   MuestraMatriz(m);

   // Guarda en un fichero el contenido de la matriz
   nombre = "copiamatriz";
   m.EscribirMatriz2D_1(nombre);

   // Sustituye el contenido de la matriz por los valores de un fichero
   nombre = "datosmatriz2";
   m.LeerMatriz2D_1(nombre);

   cout << "Matriz nueva: " << endl;
   MuestraMatriz(m);

   return 0;

}