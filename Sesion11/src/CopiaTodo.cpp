//////////////////////////////////////////////////////////////////////////
//
// Metodolog�a de la Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
// Relaci�n de problemas V, Ejercicio 1
// Programa principal
//
// Lee una secuencia indefinida de caracteres de la entrada est�ndar y los
// copia literalmente en la salida est�ndar
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int main(){
   char c;
   
   c = cin.get(); 

   while (!cin.eof()){

      cout.put(c);
      c = cin.get(); 

   }
   
   return 0;

}