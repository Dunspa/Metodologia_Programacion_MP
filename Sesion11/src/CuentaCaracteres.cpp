//////////////////////////////////////////////////////////////////////////
//
// Metodolog�a de la Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
// Relaci�n de problemas V, Ejercicio 3
// Programa principal
//
// Lee una secuencia indefinida de caracteres de la entrada est�ndar
// y muestra en la salida est�ndar el n�mero total de caracteres le�dos
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int main(){
   char c;
   int total = 0;

   while (cin >> c){

      total++;

   }

   cout << "Total de caracteres le�dos: " << total << endl;

   return 0;

}