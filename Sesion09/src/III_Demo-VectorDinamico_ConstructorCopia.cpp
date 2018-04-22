//////////////////////////////////////////////////////////////////////////
//
// Metodolog�a de la Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
// Relaci�n de problemas III
// Programa principal
//
// Realiza varias pruebas sobre la clase "VectorDinamico"
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "VectorDinamico_ConstructorCopia.h"
using namespace std;

int main(){
   VectorDinamico v1;      // Vector con un n�mero de casillas predeterminado
   VectorDinamico v2 (10); // Vector con un n�mero de casillas indicado
   VectorDinamico v3 (v2); // Vector copia de v2

   // Se comprueban las casillas ocupadas y reservadas de cada uno

   cout << "El vector 1 tiene " << v1.GetCasillasOcupadas() 
        << " casillas ocupadas" << " y " << v1.GetCasillasReservadas() 
        << " casillas reservadas" << endl;
   
   cout << "El vector 2 tiene " << v2.GetCasillasOcupadas() 
        << " casillas ocupadas" << " y " << v2.GetCasillasReservadas() 
        << " casillas reservadas" << endl;
   
   cout << "El vector 3 tiene " << v3.GetCasillasOcupadas() 
        << " casillas ocupadas" << " y " << v3.GetCasillasReservadas() 
        << " casillas reservadas" << endl;

   // Comprobaci�n de si el vector 1 est� vac�o

   if (v1.EstaVacio()){
      cout << "El vector 1 est� vac�o" << endl;
   }
   else{
      cout << "El vector 1 no est� vac�o" << endl;
   }

   // Comprobaci�n del tipo de redimensi�n

   int tipo;
   cout << "�C�mo quiere redimensionar el vector 1? Introduzca 0, 1 o 2. ";
   cin >> tipo;
   
   if (tipo == 0){

      v1.SetTipoRedimension(DeUnoEnUno);
      cout << "El tipo de redimensi�n escogido es: " << v1.GetTipoRedimension()
           << endl; 

   }
   else if (tipo == 1){

      v1.SetTipoRedimension(EnBloques);
      cout << "El tipo de redimensi�n escogido es: " << v1.GetTipoRedimension()
           << endl;

   }
   else if (tipo == 2){

      v1.SetTipoRedimension(Duplicando);
      cout << "El tipo de redimensi�n escogido es: " << v1.GetTipoRedimension()
           << endl;

   }

   /* Comprobaci�n de introducir un valor en el vector
   Se introduce un n�mero de valores indeterminado, para comprobar que el vector
   redimensiona bien */

   TipoBase valor;
	cout << endl << "Introduzca un valor en el vector 1 (0 para terminar): ";
   cin >> valor;

   while (valor != 0){

		v1.SetValor(valor);


      cout << endl << "Introduzca un valor en el vector 1 (0 para terminar): ";
      cin >> valor;

   } 

	cout << "Vector 1: ";
   for (int i = 0 ; i < v1.GetCasillasOcupadas() ; i++){

      cout << v1.GetValor(i) << " ";

   }
	cout << endl;

	cout << "El vector 1 tiene " << v1.GetCasillasOcupadas() 
        << " casillas ocupadas" << " y " << v1.GetCasillasReservadas() 
        << " casillas reservadas" << endl;

   // Comprobaci�n de si el vector devuelve el valor seg�n la posici�n

   int pos;
   cout << "�Qu� posici�n del vector 1 desea consultar?: ";
   cin >> pos;
   cout << "Valor de la posicion " << pos << ": " << v1.GetValor(pos) << endl;

   return 0;

}