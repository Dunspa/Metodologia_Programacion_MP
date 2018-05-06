//////////////////////////////////////////////////////////////////////////
//
// Metodolog�a de la Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
// Relaci�n de problemas V, Ejercicio 6
// Programa principal
//
// Lee una secuencia indefinida de caracteres de la entrada est�ndar
// y comprime todas las l�neas de la secuencia, eliminando los separadores
// que hubiera en cada l�nea
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int main(){
   char c;

   while (cin.get(c)){

      // Si el caracter no es un separador, se muestra por pantalla
      if (c != ' ' && c != '\t'){

         cout.put(c);

      }
   }

   return 0;

}