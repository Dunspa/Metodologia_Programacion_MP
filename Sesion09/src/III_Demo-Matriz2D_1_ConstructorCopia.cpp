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
// Realiza varias pruebas sobre la clase "Matriz2D_1"
//
//////////////////////////////////////////////////////////////////////////

#include "Matriz2D_1_ConstructorCopia.h"
#include <iostream>

using namespace std;

int main(){
   TipoBase valor;
   int fil, col;
   
   // PRECONDICI�N: Filas y columnas positivas
   do{
   
      cout << "Introduzca el n�mero de filas y columnas para la matriz: ";
      cin >> fil >> col;
   
   }while (fil <= 0 || col <= 0);
     
   cout << "Valor para inicializar la matriz: ";
   cin >> valor;

   Matriz2D_1 m1;                   // Matriz vac�a
   Matriz2D_1 m2(fil);              // Matriz cuadrada con las filas pedidas
   Matriz2D_1 m3(fil, col);         // Matriz con filas y columnas pedidas
   Matriz2D_1 m4(fil, col, valor);  // Matriz con filas y columnas inicializada

   // Comprueba si las matrices est�n vac�as

   cout << "Matriz vac�a: 1, Matriz no vac�a: 0" << endl;
   cout << "M1: " << m1.MatrizVacia() << endl;
   cout << "M2: " << m2.MatrizVacia() << endl;
   cout << "M3: " << m3.MatrizVacia() << endl;
   cout << "M4: " << m4.MatrizVacia() << endl;
   
   // Muestra la matriz 4, pide que modifique un valor, y se vuelve a mostrar

   cout << "Matriz 4: " << endl;
   m4.MuestraMatriz();
   
   cout << "Introduzca el nuevo valor de la matriz: ";
   cin >> valor;
   
   // PRECONDICI�N: Filas y columnas correctas
   do{   
   
      cout << "Introduzca la fila y la columna donde desea colocarlo: ";
      cin >> fil >> col;
      
   }while(fil <= 0 || fil > m4.GetFilas() || col <= 0 || col > m4.GetColumnas());
   
   m4.ModificarValor(fil, col, valor);

   cout << "Se ha modificado la fila " << fil << ", columna " << col
        << ". El valor introducido ha sido: " << m4.LeerValor(fil, col) << endl;

   cout << "Matriz 4: " << endl;
   m4.MuestraMatriz();

   return 0;

}
