//////////////////////////////////////////////////////////////////////////
//
// Metodolog�a de la Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
// Relaci�n de problemas V, Ejercicio 13
// Programa principal
//
// Lee una secuencia indefinida de caracteres de la entrada est�ndar
// Recibe como argumento desde la l�nea de ordenes un dato de tipo int
// Muestra en la salida est�ndar el n�mero de palabras le�das de la 
// entrada est�ndar cuya longitud sea igual al argumento suministrado
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char ** argv){
   // Si el n�mero de argumentos no es correcto, muestra un mensaje de error
   if (argc != 2){

      cerr << "N�mero de argumentos introducidos incorrecto."
           << " Debe introducir un �nico argumento." << endl;
      
      exit (1);

   }

   const int TAMANIO = 100;
   char c[TAMANIO];
   int num_lineas = 0;
   int longitud = atoi(argv[1]);

   cout << "Introduzca l�neas de caracteres: ";
   cin.getline(c, TAMANIO);

   while (!cin.eof()){

      if (strlen(c) == longitud){

         num_lineas++;

      }

      cin.getline(c, TAMANIO);

   }

   cout << "Hay " << num_lineas << " l�neas de longitud " << longitud;
   cout << endl;

   return 0;

}