//////////////////////////////////////////////////////////////////////////
//
// Metodolog�a de la Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
// Relaci�n de problemas V, Ejercicio 7
// Programa principal
//
// Lee una secuencia indefinida de caracteres de la entrada est�ndar
// y copia en la salida est�ndar las l�neas que NO comienzan por #
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int main(){
   char c;
   bool incorrecta = false;;

   while (cin.get(c)){

      // Nueva l�nea: Puede no ser incorrecta
      if (c == '\n'){

         incorrecta = false;

      }

      // S�lo se muestra el caracter si no es incorrecto 
      // (su linea no empieza por #)
      if (c != '#' && !incorrecta){

         cout.put(c);

      }
      // Empieza por #: L�nea incorrecta
      else{ 

         incorrecta = true;

      }
   }

   return 0;

}