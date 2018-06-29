//////////////////////////////////////////////////////////////////////////
//
// Metodolog�a de la Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
// Relaci�n de problemas VI, Ejercicio 3
// Programa principal
//
// Recibe como par�metros tres nombres de ficheros de texto
// Los dos primeros ficheros contienen n�meros reales y est�n ordenados
// El programa toma los datos de esos ficheros y los copia ordenadamente
// en el tercer fichero
// PRECONDICI�N: Los datos de los ficheros est�n ordenados
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char ** argv){
   
   // Comprobar que el n�mero de argumentos introducido es correcto
   if (argc != 4){

      cerr << "Error: n�mero de argumentos introducidos incorrecto" << endl
           << "Debe introducir tres nombres de fichero" << endl;

      exit (1);

   }

   ifstream fi1;  // Flujo de entrada del primer fichero
   ifstream fi2;  // Flujo de entrada del segundo fichero
   ofstream fo;   // Flujo de salida

   // Asociar el flujo de entrada al primer y segundo fichero
   fi1.open(argv[1]);
   fi2.open(argv[2]);

   // Asociar el flujo de salida al tercer fichero
   fo.open(argv[3]);

   // Comprobaci�n de fallos
   if (fi1.fail() || fi2.fail()){

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

   // Se lee el primer valor de cada fichero
   int n1, n2;
   fi1 >> n1;
   fi2 >> n2;
   
   // Copia todas las lineas de los ficheros de entrada al de salida
   while (!fi1.eof() && !fi2.eof()){

      if (n1 < n2){  // Compara cual de los dos es mayor y se copia

         fo << n1 << endl;
         fi1 >> n1;

      }
      else{

         fo << n2 << endl;
         fi2 >> n2;

      }
   } 

   // Terminamos de a�adir los n�meros que quedan si fi1 no ha acabado
   while (!fi1.eof()){

      fo << n1 << endl;
      fi1 >> n1;

   }

   // Terminamos de a�adir los n�meros que quedan si fi2 no ha acabado
   while (!fi2.eof()){

      fo << n2 << endl;
      fi2 >> n2;

   }

   // Desasociar flujos de entrada y salida de los ficheros
   fi1.close();
   fi2.close();
   fo.close();

   return 0;

}