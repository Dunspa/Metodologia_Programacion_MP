//////////////////////////////////////////////////////////////////////////
//
// Metodolog�a de la Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
// Relaci�n de problemas II
// Definici�n de funciones
//
// Funciones relativas a una lista din�mica de datos TipoBase
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Lista.h"
#include "GeneradorAleatorios.h"
using namespace std;

// Lee valores y los introduce en una lista din�mica
void LeeLista(Lista & l){

	TipoBase n;
	// Punteros
	PNodo primero;  // Puntero al primer nodo
	PNodo fin;      // Puntero al �ltimo nodo

	cout << "Introduzca un valor en la lista (negativo para terminar): ";
	cin >> n;

	if (n >= 0){
		
		// Pedimos memoria para el primer nodo
		primero = new Nodo;
		
		primero->valor = n;	// Guardar "n" en el nuevo nodo
		primero->sig = 0;		// Este nodo es, por ahora, el �ltimo

		// El �ltimo tambi�n es el primero (solo hay uno)
		fin = primero;

		cout << "Introduzca un valor en la lista (negativo para terminar): ";
		cin >> n;

		while (n >= 0){
			
			// Pedimos memoria para el siguiente nodo, y enlazamos
			fin->sig = new Nodo;

			fin = fin->sig;	// Actualizar posici�n del �ltimo

			fin->valor = n;	// Guardar "n" en el nuevo nodo
			fin->sig = 0;		// Este nodo es, por ahora, el �ltimo

			cout << "Introduzca un valor en la lista (negativo para terminar): ";
			cin >> n;

		}
			
	}	
	
	// La lista empieza con el primer nodo
	l = primero;
	
}

// Muestra una lista completa por pantalla
void PintaLista(const Lista l){

	// Comprobar si la lista est� vac�a antes de pintarla
	if (!ListaVacia(l)){

		PNodo aux = l;	// Colocar "aux" al principio

		cout << "Lista: " << endl;
		while (aux != 0){
		
			cout << (aux->valor) << endl;	// Mostrar valor
			aux = aux->sig;					// Adelantar aux          
		
		}	
	}

	cout << endl;
}

// Libera la memoria de una lista
void LiberaLista(Lista & l){

	// Comprobar si la lista esta vac�a antes de borrar nada
	if (!ListaVacia(l)){

		PNodo aux = l;	// Colocar "aux" al principio

		while (aux != 0){

			aux = aux->sig;	// Actualizar "aux"
			delete l;			// Borrar el nodo
			l = aux;				// Adelantar "l"

		}

		delete l;	// Borrar el �nico nodo que queda
	}

	// Puntero que da acceso a la lista se convierte en nulo
	l = 0;
}

// Comprueba si una lista est� vac�a o no
bool ListaVacia(const Lista l){

	// Se comprueba si el puntero a la lista est� vac�o
	return (l == 0);

}

// Calcula cuantos elementos tiene una lista
int CuentaElementos(const Lista l){

	// Contador del n�mero de elementos
	int elementos = 0;

	// Comprueba antes si la lista est� vac�a
	if (!ListaVacia(l)){
		
		PNodo aux = l;	// Colocar "aux" al principio

		while (aux != 0){

			elementos++;		// Se incrementa el n�mero de elementos de la lista
			aux = aux->sig;	// Actualizar "aux"

		}
	}

	return elementos;
}

// Crea una lista con n�meros aleatorios entre un m�nimo y un m�ximo
void CreaListaAleatoria(Lista & l, int min, int max, int tamanio){

	GeneradorAleatorioEnteros generador(min, max);
	TipoBase n;

	// Punteros
	PNodo primero;  // Puntero al primer nodo
	PNodo fin;      // Puntero al �ltimo nodo
		
	// Pedimos memoria para el primer nodo
	primero = new Nodo;
	
	// Genera un n�mero aleatorio
	n = generador.Siguiente();

	primero->valor = n;	// Guardar "n" en el nuevo nodo
	primero->sig = 0;		// Este nodo es, por ahora, el �ltimo

	// El �ltimo tambi�n es el primero (solo hay uno)
	fin = primero;

	for (int i = 1 ; i < tamanio ; i++){

		// Genera un n�mero aleatorio
		n = generador.Siguiente();

		fin->sig = new Nodo;

		fin = fin->sig;	// Actualizar posici�n del �ltimo
		fin->valor = n;	// Guardar "n" en el nuevo nodo
		fin->sig = 0;		// Este nodo es, por ahora, el �ltimo

	}
	
	// La lista empieza con el primer nodo
	l = primero;

}

// Comprueba si la lista est� ordenada
bool EstaOrdenada(const Lista l){

	bool ordenada = true;	// Controla si la lista est� ordenada

	// Comprobar si la lista esta vac�a 
	if (!ListaVacia(l)){

		PNodo aux = l;							// Colocar "aux" al principio
		TipoBase anterior = aux->valor;	// Valor del primer nodo

		while (aux != 0 && ordenada){
			
			if (anterior <= aux->valor){
				// Se va actualizando el valor anterior siempre que sea menor 
				anterior = aux->valor;	

				aux = aux->sig;	// Adelantar "aux"
			}
			else{
				ordenada = false; // Si el anterior no es menor, no est� ordenada
			}

		}
	}

	return ordenada;
}

// Ordena una lista usando el m�todo de ordenaci�n por selecci�n
void OrdenaSeleccionLista(Lista & l){

	// Comprobar si la lista esta vac�a 
	if (!ListaVacia(l)){

		PNodo primero = l;

		while (primero->sig != 0){
			
			// Se supone que el menor es el primero
			TipoBase minimo = primero->valor;
			PNodo pos_min = primero;   

			PNodo aux = primero->sig;  

			while (aux != 0) {

				if (aux->valor < minimo){

					minimo = aux->valor;
					pos_min = aux;

				}

				aux = aux->sig;  // Avanza "aux"

			}

			// Se intercambia el menor en la posici�n de "primero"
			TipoBase intercambia = primero->valor; 
			primero->valor = pos_min->valor;
			pos_min->valor = intercambia; 

			primero = primero->sig; // Avanza "primero"
		}

	}
}

// Inserta un valor de forma ordenada en la lista
void InsertaOrdenadamente (Lista & l, TipoBase v){

	// Se comprueba si la lista est� vac�a
	if (!ListaVacia(l)){

		// Asegura que la lista est� ordenada
		if (!EstaOrdenada(l)){
			OrdenaSeleccionLista(l);
		}

		PNodo primero = l;		// Guarda la direcci�n del primer nodo
		bool aparicion = false;	// Controla si ha aparecido el valor que se pide

		while (l != 0 && !aparicion){
			
			if (l->valor == v){
				aparicion = true;
			}
			else{
				l = l->sig;	// Actualizar "l"
			}

		}

		PNodo siguiente = l->sig;	// Se guarda el valor del siguiente
		l->sig = new Nodo;			// Nodo para el nuevo valor
		l = l->sig;
		l->valor = v;					// Se almacena el nuevo valor en el nuevo nodo
		/* La siguiente direcci�n del nuevo nodo, es la siguiente al nodo de 
		aparici�n */
		l->sig = siguiente;		

		// La lista empieza con el primer nodo
		l = primero;
	}
}

// Se elimina la celda que contiene un determinado valor
void EliminaValor (Lista & l, TipoBase v){

	// Se comprueba si la lista est� vac�a
	if (!ListaVacia(l)){

		// Asegura que la lista est� ordenada
		if (!EstaOrdenada(l)){
			OrdenaSeleccionLista(l);
		}

		PNodo primero = l;		// Guarda la direcci�n del primer nodo
		PNodo anterior = l;		// Guarda la direcci�n del nodo anterior
		bool eliminado = false;	// Controla si ya se ha eliminado el valor pedido

		while (l != 0 && !eliminado){
			
			if (l->valor == v){
				eliminado = true;
			}
			else{
				anterior = l;	// Se va guardando el anterior
				l = l->sig;		// Actualizar "l"
			}

		}

		// El siguiente al anterior, es el siguiente del borrado
		anterior->sig = l->sig;	
		delete l;

		// La lista empieza con el primer nodo
		l = primero;

	}
}

void MezclaListas (Lista & l, Lista & l1, Lista & l2){

	l = 0;	// Se inicializa la lista mezcla como vac�a

	// Se comprueba si las listas est�n vac�as
	if (!ListaVacia(l1) && !ListaVacia(l2)){

		// Asegura que las listas est�n ordenadas
		if (!EstaOrdenada(l1)){
			OrdenaSeleccionLista(l1);
		}

		if (!EstaOrdenada(l2)){
			OrdenaSeleccionLista(l2);
		}
		
		/* Se procesa el primer nodo
		Se inicializa la lista a la que tiene el primer valor menor */
		if (l1->valor < l2->valor){
			l = l1;	
			l1 = l1->sig;	// Se actualiza l1
		}
		else{
			l = l2;
			l2 = l2->sig;	// Se actualiza l2
		}

		PNodo aux = l;	// Colocar "aux" al principio

		// Las listas se van "vaciando"
		while (!ListaVacia(l1) && !ListaVacia(l2)){
			
			// Se procesa valor a valor, y se va adelantando la que sea menor
			if (l1->valor < l2->valor){
				aux->sig = l1;
				l1 = l1->sig;
			}
			else{
				aux->sig = l2;
				l2 = l2->sig;
			}

			aux = aux->sig;

		}
	}
	// Alguna est� vac�a
	else{
		// Primera vac�a
		if (ListaVacia(l1) && !ListaVacia(l2)){
			l = l2;	// La lista es enteramente l2
			l2 = 0;	// Se "borra" l2
		}
		// Segunda vac�a
		else if (!ListaVacia(l1) && ListaVacia(l2)){
			l = l1;	// La lista es enteramente l1
			l1 = 0;	// Se "borra" l1
		}
	}
}