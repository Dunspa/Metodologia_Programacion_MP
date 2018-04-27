//////////////////////////////////////////////////////////////////////////
//
// Metodolog�a de la Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
// Relaci�n de problemas III
// Declaraci�n de la clase "Lista"
//
// Clase que trabaja con listas din�micas de datos de tipo TipoBase
//
//////////////////////////////////////////////////////////////////////////

#ifndef LISTA
#define LISTA

// Definici�n del tipo de datos

typedef int TipoBase;

// Declaraci�n de la clase Lista y el TipoNodo

struct TipoNodo{

   TipoBase valor;
	TipoNodo * sig;

};

class Lista{
   private:

      TipoNodo * primero;	// Puntero al primer nodo
      int num_nodos;    	// N�mero total de nodos

   public:

      // Constructor sin argumentos:
      // Crea una lista vac�a
      Lista();

      // Constructor con un argumento:
      // Crea una lista con el n�mero de nodos indicados en el argumento
      Lista(int);

      // Constructor con dos argumentos:
      // Crea una lista con el n�mero de nodos indicados en el primer argumento 
      // e inicia todos ellos al valor indicado en el segundo argumento
      Lista(int, TipoBase);

      // Constructor de copia
      Lista(const Lista &);

      // Destructor
      ~Lista();

      // Consulta si la lista est� vac�a
      bool ListaVacia() const;

      // Consulta el n�mero de nodos de la lista
      int GetNumNodos() const;

      // Inserta un valor en la lista
		// PRECONDICI�N: Posici�n del nodo correcta
      void Insertar(TipoBase, int);

      // Borra un nodo en la lista
      void Borrar(int pos);
      
      // A�ade un valor al final de la lista
      void AniadirValor(TipoBase);
      
      // Leer el valor de una posici�n
	// PRECONDICI�N: Posici�n del nodo correcta
      TipoBase LeerValor(int pos) const;

      // PRECONDICI�N: Posici�n del nodo correcta
      // Escribir un valor en una posici�n
      void ModificarValor(int pos, TipoBase val);
      
      // Pinta por completo una lista
      void PintaLista();

   private:

      // Inicializa todos los nodos al valor indicado como argumento
      void InicializaLista(TipoBase);
      
      // Reserva memoria para n nodos
      void ReservaMemoria(int);

      // Libera la memoria de una lista
      void LiberaMemoria();

      // Copia una lista en otra
      void CopiaLista(const Lista &);

};

typedef TipoNodo * PNodo;	// Para los punteros a nodos

#endif