//////////////////////////////////////////////////////////////////////////
//
// Metodolog�a de la Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
// Relaci�n de problemas II
// Declaraci�n de la funci�n Redimensiona
//
// Funci�n que realoja y redimensiona un vector din�mico, ampli�ndolo, cuando no
// haya espacio para almacenar un nuevo valor. 
// Se puede realizar de tres maneras:
// En una casilla, en bloques o duplicando su tama�o 
//
//////////////////////////////////////////////////////////////////////////

enum TipoRedimension {DeUnoEnUno, EnBloques, Duplicando};

int * Redimensiona(int *, TipoRedimension, int &);
int * AumentaVector(int *, int, int);