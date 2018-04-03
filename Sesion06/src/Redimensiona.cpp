//////////////////////////////////////////////////////////////////////////
//
// Metodolog�a de la Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
// Relaci�n de problemas II
// Definici�n de la funci�n Redimensiona
//
// Funci�n que realoja y redimensiona un vector din�mico, ampli�ndolo, cuando no
// haya espacio para almacenar un nuevo valor. 
// Se puede realizar de tres maneras:
// En una casilla, en bloques o duplicando su tama�o 
//
//////////////////////////////////////////////////////////////////////////

#include <cstring>
#include "Redimensiona.h"

// Redimensiona un vector de enteros
int * Redimensiona(int * p, TipoRedimension tipo, int & cap){
	const int TAM_BLOQUE = 5;
	int usados = cap;

	if (tipo == TipoRedimension::DeUnoEnUno){
		cap++;
	}
	else if (tipo == TipoRedimension::EnBloques){
		cap += TAM_BLOQUE;
	}
	else if (tipo == TipoRedimension::Duplicando){
		cap *= 2;
	}

	p = AumentaVector(p, cap, usados);

	return p;
}

// Aumenta la capacidad de un vector
int * AumentaVector(int * p, int capacidad, int usados){
	int * q = new int [capacidad];
	memcpy(q, p, usados*sizeof(int));
	delete [] p;

	return q;
}