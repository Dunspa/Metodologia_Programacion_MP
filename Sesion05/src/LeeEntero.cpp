//////////////////////////////////////////////////////////////////////////
//
// Metodolog�a de la Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
// Relaci�n de problemas I, Ejercicio 19
// Definici�n de las distintas funciones sobrecargadas: "LeeEntero" necesarias
// para I_LeeEntero.cpp
//
// Lee y devuelve un n�mero entero usando una cadena de caracteres.
// Comprueba que todos los caracteres son d�gitos para convertirlos a enteros. 
// Si es correcto los devuelve, si no, vuelve a pedirlos
//
//////////////////////////////////////////////////////////////////////////

#include <cstring>
#include <cctype>
#include <iostream>
using namespace std;

int LeeEntero(){
   const int TAMANIO = 100;
   int i = 0;
   char cadena_enteros[TAMANIO];
   bool correcto = false;

   cout << "Introduzca el n�mero entero: ";
   cin.getline(cadena_enteros, TAMANIO);

   /* Algoritmo: Se analiza caracter a caracter viendo si es un entero.
   Mientras la cadena de caracteres no sea correcta (no contenga �nicamente 
   n�meros enteros) se volver� a pedir una cadena */
   while (!correcto){
      // �nicamente si se ha analizado toda la cadena se termina el bucle
      if (i == strlen(cadena_enteros)){
         correcto = true;
      }
      else if (isdigit(cadena_enteros[i])){
         i++; // Correcto. Sigue la comprobaci�n con el siguiente car�cter
      }
      else{
         cout << "Incorrecto. Introduzca de nuevo el n�mero entero: ";
         cin.getline(cadena_enteros, TAMANIO);
         i = 0; // Se reinicia el contador de la cadena
      }
   }

   // Devoluci�n de la cadena transformada a entero
   return atoi(cadena_enteros);
}

int LeeEntero(int pos_final){
   int numero;
   const int TAMANIO = 100;
   char cadena_enteros[TAMANIO];
   bool correcto = false;

   /* Algoritmo: Llamada a LeeEnteros sin argumentos para asegurarnos de que la 
   cadena sea un n�mero entero, y luego nos aseguramos de que est� dentro del 
   intervalo. Si no lo est�, se sigue pidiendo hasta que est� */
   numero = LeeEntero();
   while(!correcto){
      /* S�lo cuando el n�mero est� entre el 0 y la posici�n final, entonces se
      saldr� del bucle y se terminar� de pedir el n�mero */
      if (numero >= 0 && numero <= pos_final){
         correcto = true;
      }
      else{
         numero = LeeEntero();
      }
   }

   return numero;
}

int LeeEntero(int pos_inicial, int pos_final){
   int numero;
   const int TAMANIO = 100;
   char cadena_enteros[TAMANIO];
   bool correcto = false;

   /* Algoritmo: Llamada a LeeEnteros sin argumentos para asegurarnos de que la 
   cadena sea un n�mero entero, y luego nos aseguramos de que est� dentro del 
   intervalo. Si no lo est�, se sigue pidiendo hasta que est� */
   numero = LeeEntero();
   while(!correcto){
      /* S�lo cuando el n�mero est� entre la posici�n inicial y la posici�n 
      final, entonces se saldr� del bucle y se terminar� de pedir el n�mero */
      if (numero >= pos_inicial && numero <= pos_final){
         correcto = true;
      }
      else{
         cout << "Incorrecto. Introduzca de nuevo el n�mero del intervalo: ";
         cin >> numero;
      }
   }

   return numero;
}