//////////////////////////////////////////////////////////////////////////
//
// Metodolog�a de la Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
// Relaci�n de problemas IV, Ejercicio 9
// Declaraci�n de las clases "ColeccionPuntos2D", "Circunferencia" y "Punto2D"
//
// Clase que trabaja con una colecci�n de puntos
//
//////////////////////////////////////////////////////////////////////////

#ifndef COLECCIONPUNTOS2D
#define COLECCIONPUNTOS2D

// Declaraci�n de la clase Punto2D

class Punto2D{
   private:

      // Coordenadas de un punto 2D
      int x;
      int y;   

   public:

      /*******************************************************************/
      // Constructor sin argumentos
      Punto2D();

      /*******************************************************************/
      // Constructor con dos argumentos:
      // Crea un punto mediante las dos coordenadas dadas
      Punto2D(double, double);

      /*******************************************************************/
      // Obtiene la coordenada X del punto
      int GetX();

      /*******************************************************************/
      // Obtiene la coordenada Y del punto
      int GetY();

      /*******************************************************************/
      // Sobrecarga de los operadores relacionales == y !=
      // Tiene en cuenta sus dos coordenadas
      // Compara si dos puntos son iguales
      bool operator == (const Punto2D &) const;
      // Compara si dos puntos son distintos
      bool operator != (const Punto2D &) const;

};

// Declaraci�n de la clase Circunferencia

class Circunferencia{
   private:

      Punto2D centro;
      double radio;

   public:

      /*******************************************************************/
      // Constructor sin argumentos
      Circunferencia();

      /*******************************************************************/
      // Constructor con dos argumentos:
      // Crea una circunferencia a partir de un centro y un radio
      Circunferencia(Punto2D, double);

      /*******************************************************************/
      // Obtiene la longitud del radio
      double GetRadio();

      /*******************************************************************/
      // Obtiene el centro de la circunferencia
      Punto2D GetCentro();

      /*******************************************************************/
      // Calcula si un punto est� en la circunferencia
      bool Contiene(Punto2D);

};

// Declaraci�n de la clase ColeccionPuntos2D

class ColeccionPuntos2D{
   private:

      Punto2D * p;   // Vector de puntos
      int num;       // N�mero de puntos

   public:

      /*******************************************************************/
      // Constructor sin argumentos:
      // Crea un conjunto de puntos vac�o
      ColeccionPuntos2D();
      
      /*******************************************************************/
      // Constructor de copia:
      // Crea un conjunto de puntos copia de otro
      ColeccionPuntos2D(const ColeccionPuntos2D &);

      /*******************************************************************/
      // Constructor con un argumento:
      // Recibe el nombre de un fichero con las coordenadas de los puntos
      ColeccionPuntos2D(const char *);

      /*******************************************************************/
      // Destructor
      ~ColeccionPuntos2D();

      /*******************************************************************/
      // Obtiene el n�mero de puntos
      int GetNum();

      /*******************************************************************/
      // Copia un conjunto de puntos en otro
      void CopiaColeccionPuntos2D(const ColeccionPuntos2D &);

      /*******************************************************************/
      // A�ade un punto a la ColeccionPuntos2D
      void AniadePunto(const Punto2D);

      /*******************************************************************/
      // Sobrecarga del operador []
      // Permite acceder a un dato de tipo Punto2D en una ColeccionPuntos2D
      Punto2D & operator [] (const int) const;

      /*******************************************************************/
      // Sobrecarga de los operadores relacionales == y !=
      // Tiene en cuenta el n�mero de puntos, si son iguales y si est�n en orden
      // Compara si dos datos ColeccionPuntos2D son iguales
      bool operator == (const ColeccionPuntos2D &) const;
      // Compara si dos datos ColeccionPuntos2D son distintos
      bool operator != (const ColeccionPuntos2D &) const;

      /*******************************************************************/
      // Sobrecarga del operador binario +
      // A�ade un punto al final de una colecci�n de puntos
      friend ColeccionPuntos2D operator + (const ColeccionPuntos2D &, const Punto2D &);
      // A�ade un punto al principio de una colecci�n de puntos
      friend ColeccionPuntos2D operator + (const Punto2D &, const ColeccionPuntos2D &);

   private:

      /*******************************************************************/
      // Reserva memoria para el vector de punteros
      void ReservaMemoria(int);

      /*******************************************************************/
      // Libera la memoria del vector de puntos
      void LiberaMemoria();

      /*******************************************************************/
      // Redimensiona el vector de puntos
      void Redimensiona(int);

};

#endif