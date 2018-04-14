//////////////////////////////////////////////////////////////////////////
//
// Metodolog�a de la Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
// Relaci�n de problemas II, Ejercicio 9
// Programa principal
//
// (Examen ordinario FP 2018) El Problema de la Asignaci�n:
// Una empresa dispone de n t�cnicos y n pedidos por atender, con una matriz 
// B de precios y una matriz X que asigna cada pedido a un �nico t�cnico.
// El programa resuelve el problema asignado a cada t�cnico el pedido m�s 
// econ�mico entre los disponibles y muestra el coste de la asignaci�n.
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Matriz2D_1.h"
using namespace std;

int main(){
   const int MAX_COSTE = 100;
   int n, pos_min, min, coste = 0;

   // Se pide el tama�o de la matriz
   cout << "N�mero de pedidos/t�cnicos: ";
   cin >> n;

   // Creaci�n de la matriz de costes
   cout << "Introduzca los valores de la matriz de costes B: ";
   Matriz2D_1 B = CreaMatriz2DLlena(n, n);

   // Creaci�n de la matriz de asignaciones
   Matriz2D_1 X = CreaMatriz2DVacia(n, n);

   // Vector que indica si esa columna no ha tenido un pedido asignado
   bool * ya_asignados = new bool [n];
   ya_asignados[n] = {false};

   // Se asigna a cada t�cnico el pedido m�s econ�mico entre los disponibles
   for (int i = 0 ; i < n ; i++){
      // Se inicializa el m�nimo a un valor que cualquier otro pueda superar
      min = MAX_COSTE + 1;
      for (int j = 0 ; j < n ; j++){
         /* Si esa columna no ha sido asignada previamente, se puede comprobar 
         si ah� hay un valor m�nimo */
         if (!ya_asignados[j]){
            if (B.datos[i][j] < min){
               min = B.datos[i][j];
               pos_min = j;
            }
         }
      }
      ya_asignados[pos_min] = true;
      X.datos[i][pos_min] = 1;
      coste += + B.datos[i][pos_min];
   }

   cout << "Matriz de costes B: " << endl;
   MuestraMatriz2D(B);
   cout << "Matriz de asignaciones X: " << endl;
   MuestraMatriz2D(X);
   cout << "El coste de dicha asignaci�n es: " << coste << endl;

   return 0;
}