//////////////////////////////////////////////////////////////////////////
//
// Metodolog�a de la Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
// Relaci�n de problemas VII, Ejercicio 1
// Programa principal
//
// Recibe el nombre de dos ficheros. El programa copiar�, en el mismo orden,
// los n�meros que contiene el fichero de entrada en el fichero de salida
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

   int num;       // Cada n�mero del fichero
   int total = 0; // Total de n�meros en el fichero

   // Procesamiento de ficheros: cada escritura transfiere �nicamente un dato
   while (fi >> num){
      
      fo.write((const char *) &num, sizeof(int));
      total++;

   }

   // Desasociar flujos de entrada y salida de los ficheros
   fi.close();
   fo.close();

   cout << "Se han le�do " << total << " n�meros del fichero de entrada"
        << " y se han copiado en el fichero de salida " << argv[2] << endl;

   return 0;

}