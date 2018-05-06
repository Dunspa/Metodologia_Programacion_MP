//////////////////////////////////////////////////////////////////////////
//
// Metodolog�a de la Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
// Relaci�n de problemas V, Ejercicio 10
// Programa principal
//
// Lee una serie indefinida de n�meros de la entrada est�ndar, separados
// por el caracter '*' y los copia en el mismo orden en la salida est�ndar
// separados por un salto de l�nea
// PRECONDICI�N: El �ltimo car�cter es '*'
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int main(){
   const int TAMANIO = 100;
   char c[TAMANIO];

   cout << "Introduzca secuencias de n�meros separadas por el caracter *: ";
   cin.getline(c, TAMANIO, '*');

   while (!cin.eof()){

      cout << atoi(c) << endl;

      // Lee la cadena hasta encontrar el delimitador '*'
      cin.getline(c, TAMANIO, '*');

   }

   return 0;

}