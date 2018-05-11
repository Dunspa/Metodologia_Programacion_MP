//////////////////////////////////////////////////////////////////////////
//
// Metodolog�a de la Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
// Relaci�n de problemas IV, Ejercicio 4
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

      /*******************************************************************/
      // Constructor sin argumentos:
      // Crea una lista vac�a
      Lista();

      /*******************************************************************/
      // Constructor con un argumento:
      // Crea una lista con el n�mero de nodos indicados en el argumento
      Lista(int);

      /*******************************************************************/
      // Constructor con dos argumentos:
      // Crea una lista con el n�mero de nodos indicados en el primer argumento 
      // e inicia todos ellos al valor indicado en el segundo argumento
      Lista(int, TipoBase);

      /*******************************************************************/
      // Constructor de copia
      Lista(const Lista &);

      /*******************************************************************/
      // Destructor
      ~Lista();

      /*******************************************************************/
      // Consulta si la lista est� vac�a
      bool ListaVacia() const;

      /*******************************************************************/
      // Consulta el n�mero de nodos de la lista
      int GetNumNodos() const;

      /*******************************************************************/
      // Inserta un valor en la lista
		// PRECONDICI�N: Posici�n del nodo correcta
      void Insertar(TipoBase, int);

      /*******************************************************************/
      // Borra un nodo en la lista
      void Borrar(int pos);
      
      /*******************************************************************/
      // A�ade un valor al final de la lista
      void AniadirValor(TipoBase);

		/*******************************************************************/
      // Busca la primera aparici�n de un valor y elimina el nodo
      void EliminarValor(TipoBase);
      
      /*******************************************************************/
      // Leer el valor de una posici�n
		// PRECONDICI�N: Posici�n del nodo correcta
      TipoBase LeerValor(int pos) const;

      /*******************************************************************/
      // PRECONDICI�N: Posici�n del nodo correcta
      // Escribir un valor en una posici�n
      void ModificarValor(int pos, TipoBase val);
      
      /*******************************************************************/
      // Pinta por completo una lista
      void PintaLista();

		/*******************************************************************/
      // Sobrecarga del operador =
		// Realiza una copia profunda
      Lista & operator = (const Lista &);
		// Inicia toda la lista al valor especificado
		Lista & operator = (const TipoBase);

		/*******************************************************************/
      // Sobrecarga del operador []
		// Acceso a los elementos de la lista como rvalue y lvalue
		TipoBase & operator [] (const int);

		/*******************************************************************/
      // Sobrecarga de los operadores combinados += y -=
		// A�ade un nodo con el valor indicado
		Lista & operator += (const TipoBase);
		// Elimina un nodo con el valor indicado
		Lista & operator -= (const TipoBase);

		/*******************************************************************/
      // Sobrecarga de los operadores binarios + y -
		// Une a la lista el contenido completo de la segunda
		friend Lista operator + (const Lista &, const Lista &); 
		// A�ade un nodo con el valor indicado
		friend Lista operator + (const Lista &, const TipoBase);
		friend Lista operator + (const TipoBase, const Lista &);
		// Elimina de la lista la primera aparici�n de los valores de la segunda
		friend Lista operator - (const Lista &, const Lista &);
		// Elimina un nodo con el valor indicado
		friend Lista operator - (const TipoBase, const Lista &);
		friend Lista operator - (const TipoBase, const Lista &);

		/*******************************************************************/
      // Sobrecarga de los operadores relacionales >, >=, <, <=, == y !=
		// Compara si dos listas son iguales (seg�n valores)
		bool operator == (const Lista &);
		// Compara si dos listas son distintas (seg�n valores)
		bool operator != (const Lista &);
		// Compara si una cadena es mayor que otra
		bool operator > (const Lista &);
		// Compara si una cadena es mayor o igual que otra
		bool operator >= (const Lista &);
		// Compara si una cadena es menor que otra
		bool operator < (const Lista &);
		// Compara si una cadena es menor o igual que otra
		bool operator <= (const Lista &);

   private:

      /*******************************************************************/
      // Inicializa todos los nodos al valor indicado como argumento
      void InicializaLista(TipoBase);
      
      /*******************************************************************/
      // Reserva memoria para n nodos
      void ReservaMemoria(int);

      /*******************************************************************/
      // Libera la memoria de una lista
      void LiberaMemoria();

      /*******************************************************************/
      // Copia una lista en otra
      void CopiaLista(const Lista &);

};

typedef TipoNodo * PNodo;	// Para los punteros a nodos

#endif