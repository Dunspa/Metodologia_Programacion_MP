//////////////////////////////////////////////////////////////////////////
//
// Metodolog�a de la Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
// Relaci�n de problemas II
// Definici�n de la funci�n MuestraVector
//
// Muestra un vector completo por pantalla
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "MuestraVector.h"
using namespace std;

void MuestraVector(int * p, int num_datos, int num_datos_linea){
	cout << "El vector es: ";

	for (int i = 0 ; i < num_datos ; i++){
		char separador = (((i + 1) % num_datos_linea) == 0) ? '\n':' ';
		cout << p[i] << separador;
	}

	cout << endl;
}