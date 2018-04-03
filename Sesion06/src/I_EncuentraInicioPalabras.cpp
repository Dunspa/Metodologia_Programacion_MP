//////////////////////////////////////////////////////////////////////////
//
// Metodolog�a de la Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
// Relaci�n de problemas I, Ejercicio 17
// Programa principal
//
// Lee una cadena de caracteres, encuentra y registra el inicio de cada palabra 
// y muestra el n�mero de palabras y el primer car�cter de cada una
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
using namespace std;

const int MAX_CARACTERES = 100;
const int MAX_PALABRAS = 10;

int encuentra_palabras(char **, char *);

int main(){
   char la_cadena[MAX_CARACTERES];
   char * las_palabras[MAX_PALABRAS];

   cout << "Introduzca distintas palabras: " << endl;
   cin.getline(la_cadena, MAX_CARACTERES);

   int num_palabras = encuentra_palabras(las_palabras, la_cadena);

   cout << "La cadena introducida tiene " << num_palabras 
        << " palabras" << endl;
   for (int i = 0 ; i < num_palabras ; i++){
      cout << "Primera letra de la palabra " << i + 1 << ":" 
           << **(las_palabras + i) << endl;
   }

   return 0;
}

int encuentra_palabras(char ** palabras, char * cadena){
   const char ESPACIO = ' ';
   int primera_letra = 0, num_palabras = 0;
   bool lleno = false;

   /* Algoritmo: Se recorre toda la cadena. Va guardando la posici�n siguiente 
   a la cual encuentra un espacio. Entonces, si a la siguiente vuelta se 
   encuentra con una letra, se guarda la direcci�n de memoria de esa primera
   letra */
   for (int i = 0 ; i < strlen(cadena) && !lleno ; i++){
      if (num_palabras == MAX_PALABRAS){
         lleno = true;
      }
      /* Cada vez que encuentre un espacio, se guarda la posici�n siguiente 
      esperando que no sea un espacio */
      else if (cadena[i] == ESPACIO){
         primera_letra = i + 1;
      }
      // Se controla que s�lo se guarde la primera letra de cada palabra
      else if (primera_letra == i){
         palabras[num_palabras] = &cadena[i];
         num_palabras++;
      }

      // Si no es espacio, ni es la primera letra, simplemente seguir� avanzando
   }

   // Si se llena el array de punteros, se muestra un mensaje de aviso
   if (lleno){
      cerr << "El array de punteros de palabras est� lleno " 
           << "por lo que no se considerar�n m�s de " << num_palabras 
           << " palabras" << endl;
   }

   return num_palabras;
}