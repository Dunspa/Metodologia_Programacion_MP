//////////////////////////////////////////////////////////////////////////
//
// Metodolog�a de la Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
// Relaci�n de problemas VII, Ejercicio 2
// Programa principal
//
// Recibe el nombre de dos ficheros. El programa copiar�, en el mismo orden,
// los n�meros que contiene el fichero de entrada en el fichero de salida
// en bloques de 512 bytes
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char ** argv){

   if (argc != 3){

      cerr << "Error: Debe introducir dos argumentos, el nombre de dos ficheros"
           << endl;

      exit(1);

   }

   ifstream fi;   // Flujo de entrada
   ofstream fo;   // Flujo de salida

   // Asociar el flujo de entrada al primer fichero
   fi.open(argv[1]);

   // Asociar el flujo de salida al segundo fichero (binario)
   fo.open(argv[2], ios::binary);

   // Comprobaci�n de fallos
   if (fi.fail()){

      cerr << "Error: no pudo abrirse el primer fichero" << endl
           << "No existe o no existe permiso de lectura" << endl;

      exit (1);

   }

   if (fo.fail()){

      cerr << "Error: no pudo crearse el segundo fichero" << endl
           << "No hay espacio disponible o no existe permiso de escritura" 
           << endl;

      exit (1);

   }

   const int TAM_BUFFER = 512;  // N�mero de bytes del buffer de lectura

   // N�mero m�ximo de int que caben en el buffer
   const int MAX_BUFFER = TAM_BUFFER / sizeof(int);   

   char buffer [MAX_BUFFER];     // Buffer de lectura

   int num;                      // Cada n�mero del fichero
   int total = 0;                // Total de n�meros en el fichero
   int total_buffer = 0;         // Total de n�meros copiados al buffer

   // Procesamiento de ficheros: cada escritura transfiere �nicamente un dato
   while (fi >> num){

      // Si a�n caben enteros en el buffer, se introduce el n�mero le�do      
      if (total_buffer < MAX_BUFFER){

         buffer[total_buffer] = num;
         total_buffer++;

      }
      // El buffer est� lleno, se escribe en la salida y se vac�a
      else{

         // Se copia un bloque de 512 bytes
         fo.write((const char *) buffer, TAM_BUFFER);

         // Actualizar n�mero de datos totales
         total += TAM_BUFFER;

         // Se guarda el �ltimo n�mero le�do y se reinicia el buffer
         buffer[0] = num;
         total_buffer = 1;

      }
   }

   // Se escribe lo que queda en el buffer
   fo.write((const char *) buffer, total_buffer*sizeof(int));
   total += total_buffer;

   // Desasociar flujos de entrada y salida de los ficheros
   fi.close();
   fo.close();

   cout << "Se han transferido " << total << " datos"
        << " (" << total * sizeof(int) << " bytes)" << endl;

   return 0;

}