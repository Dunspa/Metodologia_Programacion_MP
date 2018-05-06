//////////////////////////////////////////////////////////////////////////
//
// Metodolog�a de la Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
// Relaci�n de problemas V, Ejercicio 12
// Programa principal
//
// Lee una secuencia indefinida de caracteres de la entrada est�ndar
// Recibe como argumento desde la l�nea de ordenes un dato de tipo char
// Muestra en la salida est�ndar el n�mero de caracteres le�dos de la 
// entrada est�ndar iguales al argumento suministrado
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int main(int argc, char ** argv){
   // Si el n�mero de argumentos no es correcto, muestra un mensaje de error
   if (argc != 2){

      cerr << "N�mero de argumentos introducidos incorrecto."
           << " Debe introducir un �nico argumento." << endl;
      
      exit (1);

   }

   char c;
   int num_caracteres = 0;
   char caracter = argv[1][0];

   while (cin.get(c)){

      if (c == caracter){

         num_caracteres++;

      }
   }

   cout << "Hay " << num_caracteres << " apariciones del car�cter " << caracter;
   cout << endl;

   return 0;

}