//////////////////////////////////////////////////////////////////////////
//
// Metodolog�a de la Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
// Relaci�n de problemas III
// Declaraci�n de la clase "Matriz2D_1"
//
// Clase que trabaja con matrices din�micas de datos de tipo TipoBase
//
//////////////////////////////////////////////////////////////////////////

#ifndef MATRIZ2D_1
#define MATRIZ2D_1

// Definici�n del tipo de datos

typedef int TipoBase;

// Declaraci�n de la clase Matriz2D_1

class Matriz2D_1{
	private:
	
		TipoBase ** matriz;  // Puntero a la matriz de datos de tipo TipoBase
		int filas;           // N�mero de filas de la matriz
		int columnas;        // N�mero de columnas de la matriz

	public:
	
		// Constructor sin argumentos: 
		// Crea una matriz vac�a
		Matriz2D_1();

		// Constructor con un argumento: 
		// Crea una matriz cuadrado con mismo n�mero de filas y columnas
		// PRECONDICI�N: Filas y columnas positivas
		Matriz2D_1(int);

		// Constructor con dos argumentos:
		// Crea una matriz con un n�mero de filas y columnas
		// PRECONDICI�N: Filas y columnas positivas
		Matriz2D_1(int, int);

		// Constructor con tres argumentos:
      // Crea una matriz con un n�mero de filas y columnas
      // Inicia todas las casillas a un valor indicado
		Matriz2D_1(int, int, TipoBase);
		
		// Constructor de copia
		Matriz2D_1(const Matriz2D_1 &);
		
		// Destructor
		~Matriz2D_1();
		
		// Proporciona el n�mero de filas
		int GetFilas() const;
		
		// Proporciona el n�mero de columnas
		int GetColumnas() const;
		
		// Consulta si la matriz est� vac�a
		bool MatrizVacia() const;
		
		// Escribir un valor
		void ModificarValor(int, int, TipoBase) const;
		
		// Modificar un valor
		// PRECONDICI�N: Filas y columnas positivas y correctas
		TipoBase LeerValor(int, int) const;
		
		// Inicializa todas las casillas de la matriz al valor del argumento
      // Si no se especifica ninguno, inicia todas las casillas al valor nulo
		void InicializaMatriz(TipoBase);
		void InicializaMatriz();
		
		// Muestra por completo una matriz
		void MuestraMatriz() const;

	private:
	
	   // Reserva memoria para una matriz
		// PRECONDICI�N: Filas y columnas positivas
		void ReservaMemoria(const int, const int);
		
		// Libera por completo la memoria de una matriz
		void LiberaMemoria();
		
		// Copia una matriz en otra
		void CopiaMatriz(const Matriz2D_1 &);
		
		// Rellena una matriz por completo a un valor
		void RellenaMatriz(TipoBase);

};

#endif
