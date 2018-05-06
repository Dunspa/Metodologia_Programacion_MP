//////////////////////////////////////////////////////////////////////////
//
// Metodolog�a de la Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
// Relaci�n de problemas V, Ejercicio 11
// Programa principal
//
// Lee una serie indefinida de n�meros de la entrada est�ndar y muestra
// en la salida est�ndar la suma de todos esos n�meros
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int main(){
   const int TAMANIO = 100;
   char c[TAMANIO];
   int suma = 0;

   cout << "Introduzca secuencias de n�meros separadas por el fin de l�nea: ";
   cin.getline(c, TAMANIO);

   while (!cin.eof()){

      // Suma de todos los n�meros que lee
      suma += atoi(c);

      // Lee la cadena hasta encontrar el delimitador '\n'
      cin.getline(c, TAMANIO);

   }

   cout << "La suma de todos los n�meros es: " << suma << endl;

   return 0;

}