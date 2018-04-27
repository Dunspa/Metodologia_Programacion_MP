//////////////////////////////////////////////////////////////////////////
//
// Metodolog�a de la Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
// Relaci�n de problemas III
// Declaraci�n de la clase "VectorDinamico"
//
// Clase que trabaja con vectores din�micos de TipoBase
//
//////////////////////////////////////////////////////////////////////////

#ifndef VECTORDINAMICO
#define VECTORDINAMICO

// Definici�n del tipo de datos

typedef int TipoBase;

enum TipoRedimension {DeUnoEnUno, EnBloques, Duplicando, Ajustar};

// Declaraci�n de la clase VectorDinamico

class VectorDinamico{
   private:
      static const int TAM_INICIAL = 5;

      TipoBase * vector;
      int ocupadas;
      int reservadas;
      TipoRedimension tipo_redimension;

   public:

      // Constructor sin argumentos:
      // Crea un vector din�mico con un n�mero de casillas predeterminado 
      VectorDinamico();

      // Constructor con un argumento:
      // Crea un vector din�mico con el n�mero de casillas del argumento
      // PRECONDICI�N: N�mero de casillas positivo
      VectorDinamico(int);

      // Constructor de copia
      VectorDinamico(const VectorDinamico &);

      // Destructor
      ~VectorDinamico();

      // Consulta si el vector est� vac�o
      bool VectorVacio() const;

      // Consulta el n�mero de casillas ocupadas
      int GetCasillasOcupadas() const;

      // Consulta el n�mero de casillas reservadas
      int GetCasillasReservadas() const;

      // Devuelve el valor que ocupa una posici�n dada
      // PRECONDICI�N: Posici�n positiva y correcta
      TipoBase GetValor(int) const;

      // A�ade un valor. Si no hay espacio, redimensiona el vector
      void SetValor(TipoBase);

      // Asigna un tipo de redimensi�n
      void SetTipoRedimension(TipoRedimension);

      // Consulta el tipo de redimensi�n
      TipoRedimension GetTipoRedimension() const;

   private:

      // Redimensiona un vector
      void Redimensiona();

      // Ajusta el tama�o del vector 
      // Su capacidad coincidir� con el n�mero de casillas ocupadas
      void AjustaTamanio();

      // Reserva memoria para un vector
      // PRECONDICI�N: N�mero de casillas positivo
      void ReservaMemoria(int);

      // Libera la memoria de un vector
      void LiberaMemoria();

      // Copia un vector en otro
      void CopiaVector(const VectorDinamico &);

};

#endif