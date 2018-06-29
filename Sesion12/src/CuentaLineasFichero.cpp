//////////////////////////////////////////////////////////////////////////
//
// Metodolog�a de la Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
// Relaci�n de problemas VI
// Definici�n de la funci�n "CuentaLineasFichero"
//
// Cuenta cu�ntas l�neas tiene un fichero de texto
//
//////////////////////////////////////////////////////////////////////////

#include <fstream>
using namespace std;

int CuentaLineasFichero(const char * nombre){

   ifstream fi;      // Flujo de entrada del fichero
   fi.open(nombre);  // Asociar el flujo de entrada al fichero
   int n;            // N�mero de l�neas

   while (!fi.eof()){

      n++;

   }

   fi.close(); // Desasociar el flujo de entrada del fichero

   return n;

}