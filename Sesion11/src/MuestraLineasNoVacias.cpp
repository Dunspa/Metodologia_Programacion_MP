//////////////////////////////////////////////////////////////////////////
//
// Metodolog�a de la Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
// Relaci�n de problemas V, Ejercicio 5
// Programa principal
//
// Lee una secuencia indefinida de caracteres de la entrada est�ndar
// y muestra en la salida est�ndar las l�neas no vac�as 
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int main(){
   char c;

   while (cin.get(c)){

      // Si el car�cter no es un salto de l�nea, se muestra por pantalla
      if (c != '\n'){

         cout.put(c);

         // Comprobaci�n de si el siguiente caracter es un salto de l�nea
         if (cin.peek() == '\n'){

            cout << endl;  // Salto de l�nea

         }
      }
   }

   return 0;

}