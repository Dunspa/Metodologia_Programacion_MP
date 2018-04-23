//////////////////////////////////////////////////////////////////////////
//
// Metodolog�a de la Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
// Relaci�n de problemas I, Ejercicio 19
// Programa principal
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "LeeEntero.h"
using namespace std;

int main(){
   int entero, inicio, fin;

   entero = LeeEntero();
   cout << "N�mero entero de la funci�n sin argumento: " << entero << endl;

   cout << "Introduzca la posici�n final del intervalo: ";
   cin >> fin;

   entero = LeeEntero(fin);
   cout << "N�mero entero de la funci�n con un argumento: " << entero << endl;

   cout << "Introduzca las posiciones inicial y final del intervalo: ";
   cin >> inicio >> fin;

   entero = LeeEntero(inicio, fin);
   cout << "N�mero entero de la funci�n con dos argumentos: " << entero << endl;

   return 0;
}