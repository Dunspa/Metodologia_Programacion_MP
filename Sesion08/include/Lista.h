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
// Funciones relativas a una lista din�mica de datos TipoBase
//
//////////////////////////////////////////////////////////////////////////

#ifndef LISTA
#define LISTA

typedef double TipoBase;

struct Nodo{
	TipoBase valor;
	Nodo * sig;
};

typedef Nodo * PNodo;	// Para los punteros a nodos
typedef Nodo * Lista;	// Para la lista

void LeeLista(Lista &);
void PintaLista(const Lista);
void LiberaLista(Lista &);
bool ListaVacia(const Lista);
int CuentaElementos(const Lista);
bool EstaOrdenada (const Lista);
void OrdenaSeleccionLista (Lista &);
void CreaListaAleatoria(Lista &, int, int, int);
bool EstaOrdenada (const Lista);
void OrdenaSeleccionLista (Lista &);
void InsertaOrdenadamente (Lista &, TipoBase);
void EliminaValor (Lista &, TipoBase);
void MezclaListas (Lista &, Lista &, Lista &);

#endif
