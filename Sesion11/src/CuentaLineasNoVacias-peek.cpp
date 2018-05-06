//////////////////////////////////////////////////////////////////////////
//
// Metodolog�a de la Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
// Relaci�n de problemas V, Ejercicio 4
// Programa principal
//
// Lee una secuencia indefinida de caracteres de la entrada est�ndar
// y muestra en la salida est�ndar el n�mero de l�neas no vac�as 
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int main(){
   char c;
   int total = 0;

   while (cin.get(c)){

      // Si el car�cter no indica una nueva l�nea
      if (c != '\n'){

         // Se comprueba si se ha acabado la l�nea, que sabemos que no es vacia
         if (cin.peek() == '\n'){

            total++;

         }
      }
   }

   cout << "Total de l�neas no vac�as: " << total << endl;

   return 0;

}