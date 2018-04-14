//////////////////////////////////////////////////////////////////////////
//
// Metodolog�a de la Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
// Relaci�n de problemas II
// Declaraci�n de funciones
//
// Funciones relativas a una matriz din�mica de datos TipoBase
//
//////////////////////////////////////////////////////////////////////////

#ifndef MATRIZ2D_1
#define MATRIZ2D_1

typedef int TipoBase;

typedef struct{
   TipoBase ** datos;
   TipoBase fils;
   TipoBase cols;
} Matriz2D_1;

Matriz2D_1 CreaMatriz2DVacia(int, int);
void LiberaMatriz2D_1(Matriz2D_1 &);
Matriz2D_1 CreaMatriz2DLlena(int, int);
Matriz2D_1 CreaMatriz2DAleatoria(int, int);
void MuestraMatriz2D(Matriz2D_1);
Matriz2D_1 CopiaMatriz2D(Matriz2D_1);
Matriz2D_1 ExtraeSubmatriz2D(Matriz2D_1, int, int, int, int);
Matriz2D_1 EliminaFilaMatriz2D(Matriz2D_1, int);
Matriz2D_1 EliminaColumnaMatriz2D(Matriz2D_1, int);
Matriz2D_1 TraspuestaMatriz2D(Matriz2D_1);
Matriz2D_1 InvierteFilasMatriz2D(Matriz2D_1);

#endif