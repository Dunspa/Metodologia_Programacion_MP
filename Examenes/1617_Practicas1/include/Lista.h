//////////////////////////////////////////////////////////////////////////
//
// Metodolog�a de la Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
// Examen pr�cticas 1 (2016 - 2017)
// Declaraci�n de la funci�n "Lista"
//
// Funciones que trabajan con listas din�micas de datos de tipo TipoBase
//
//////////////////////////////////////////////////////////////////////////

#ifndef LISTA
#define LISTA

typedef int TipoBase;

struct Nodo{
   TipoBase valor;
   Nodo * sig;
};

typedef Nodo * PNodo;   // Para los punteros a nodos
typedef Nodo * Lista;   // Para la lista

// Crea una lista y rellena sus nodos con los valores leidos de cin.
// El n�mero de valores es indefinido --> en esta implementaci�n la lectura 
// se detiene al leer un valor negativo
void LeeLista(Lista &);

// Libera la memoria ocupada por los nodos de una lista
void LiberaLista(Lista &);
 
// Muestra los valores guardados en los nodos de una lista enlazada
void PintaLista(const Lista);

// Cuenta el n�mero de nodos de la lista
int CuentaElementos(const Lista);

// Consulta si una lista est� vac�a (sin nodos)   
bool ListaVacia(const Lista);

// Devuelve una nueva lista, nueva, conteniendo algunos valores seleccionados 
// de la lista l. Los valores seleccionados en la nueva lista est�n en el 
// mismo orden en el que aparecen en la lista l.
// La lista l no se modifica.
// El criterio de selecci�n es el siguiente: se selecciona el nodo de la 
// posici�n "inicio", despu�s el que est� "salto" posiciones por delante, 
// y as� sucesivamente.
// Recibe y devuelve (a trav�s de referencia): 
//			nueva, la lista que crea la funci�n.
//			l, la lista original. No se modifica.
// Recibe:  inicio, posici�n del primer nodo de la selecci�n.
//			salto, n�mero de nodos entre cada dos nodos seleccionados. 

void Selecciona(Lista &, const Lista, const int, const int);

#endif