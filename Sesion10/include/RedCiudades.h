//////////////////////////////////////////////////////////////////////////
//
// Metodolog�a de la Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
// Relaci�n de problemas IV, Ejercicio 11
// Declaraci�n de la clase "RedCiudades"
//
// Clase que trabaja con una red de ciudades
//
//////////////////////////////////////////////////////////////////////////

#ifndef REDCIUDADES
#define REDCIUDADES

// Definici�n del struct InfoCiudad

struct InfoCiudad{

   char * nombre; // Nombre de la ciudad
   int poblacion; // N�mero de habitantes

};

// Declaraci�n de la clase RedCiudades

class RedCiudades{
   private:

      int num_ciudades;    // N�mero de ciudades
      InfoCiudad * info;   // info[i]: info de la ciudad i
      double ** distancia; // distancia[i][j]: distancia entre las ciudades i, j

   public:

      /*******************************************************************/
      // Constructor sin argumentos:
      // Crea una red vac�a
      RedCiudades();

      /*******************************************************************/
      // Constructor ad-hoc:
      // Inicializa la red con los datos del problema
      RedCiudades(int);

      /*******************************************************************/
      // Constructor de copia
      RedCiudades(const RedCiudades &);

      /*******************************************************************/
      // Destructor
      ~RedCiudades();

      /*******************************************************************/
      // Asigna una distancia entre dos ciudades
      void SetDistancia(int, int, double);

      /*******************************************************************/
      // Devuelve el n�mero de ciudades
      int NumCiudades();

      /*******************************************************************/
      // Devuelve la distancia entre dos ciudades
      double Distancia(int, int);

      /*******************************************************************/
      // Devuelve el nombre de una ciudad (la direcci�n de inicio)
      char * NombreCiudad(int);

      /*******************************************************************/
      // Devuelve el n�mero de habitantes de una ciudad
      int PoblacionCiudad(int);

      /*******************************************************************/
      // Indica si una red est� vac�a
      bool EstaVacia();

      /*******************************************************************/
      // Obtiene el �ndice de la ciudad con mayor n�mero de conexiones directas
      int CiudadMejorConectada();

      /*******************************************************************/
      // Devuelve la ciudad intermedia entre dos ciudades que permite
      // hacer el trayecto de la forma m�s econ�mica
      // Devuelve -1 si no existe dicha ciudad intermedia
      int MejorEscalaEntre(int, int);

   private:

      /*******************************************************************/
      // Reserva memoria para n ciudades
      void ReservaMemoria(const int);

      /*******************************************************************/
      // Libera la memoria del vector de InfoCiudad y la matriz de distancias
      void LiberaMemoria();

      /*******************************************************************/
      // Copia el vector de InfoCiudad
      void CopiarDatos(const RedCiudades &);

};

#endif