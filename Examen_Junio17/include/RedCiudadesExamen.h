//////////////////////////////////////////////////////////////////////////
//
// Metodolog�a de la Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
// Examen Convocatoria Ordinaria - 14 de Junio de 2017
// Declaraci�n de la clase RedCiudades
//
//////////////////////////////////////////////////////////////////////////

#ifndef REDCIUDADES
#define REDCIUDADES

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct InfoCiudad{

   char * nombre; // Nombre
   int poblacion; // N�mero de habitantes

};

class RedCiudades{

   private:

      int num_ciudades;    // N�mero de ciudades
      InfoCiudad * info;   // info[i]: info de la ciudad i
      double ** distancia; // distancia[i][j]: distancia
                           // entre las ciudades i y j

   public:

      /*******************************************************************/
      // Constructor por defecto: Crea una red vac�a
      RedCiudades();

      /*******************************************************************/
      // Constructor con un argumento: Recibe el nombre de un fichero de texto
      // con la informaci�n sobre una red
      RedCiudades(const char *);

      /*******************************************************************/
      // Constructor de copia
      RedCiudades(RedCiudades &);

      /*******************************************************************/
      // Destructor
      ~RedCiudades();

      /*******************************************************************/
      // Devuelve el n�mero de ciudades
      int NumCiudades();

      /*******************************************************************/
      // Devuelve la distancia entre dos ciudades
      double Distancia(int, int);

      /*******************************************************************/
      // Devuelve el nombre de una ciudad (en realidad, la direcci�n de inicio)
      char * NombreCiudad(int);

      /*******************************************************************/
      // Devuelve el n�mero de habitantes de una ciudad
      int PoblacionCiudad(int);

      /*******************************************************************/
      // Indica si una red est� vac�a
      bool EstaVacia();

      /*******************************************************************/
      // Actualiza el contenido de una red con los datos de un fichero de texto
      void LeerRedCiudades(const char *);

      /*******************************************************************/
      // Guarda el contenido de una red en un fichero de texto
      void EscribirRedCiudades(const char *);

      /*******************************************************************/
      // Permite obtener el �ndice de la ciudad con mayor n�mero de conexiones
      int CiudadMejorConectada();

      /*******************************************************************/
      // Dadas dos ciudades no conectadas directamente, devuelve aquella
      // ciudad intermedia que permita hacer el trayecto de la forma m�s
      // econ�mica posible
      int MejorEscalaEntre(int, int);

      /*******************************************************************/
      // Sobrecarga del operador de salida << para poder insertar en un flujo
      // de salida el contenido de una red en formato texto
      friend ostream & operator << (ostream &, const RedCiudades &);

      /*******************************************************************/
      // Sobrecarga del operador de entrada >> para poder obtener desde un flujo
      // de entrada el contenido de un objeto
      friend istream & operator >> (istream &, RedCiudades &);

   private:

      /*******************************************************************/
      // Reserva memoria para una red de ciudades
      void ReservaMemoria();

      /*******************************************************************/
      // Libera la memoria de una red de ciudades
      void LiberaMemoria();
      
      /*******************************************************************/
      // Copia una red en otra
      void CopiaRed(RedCiudades &);

};

#endif