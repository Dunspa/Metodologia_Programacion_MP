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

typedef int TipoBase;

enum TipoRedimension {DeUnoEnUno, EnBloques, Duplicando, Ajustar};

class VectorDinamico{
   private:
      static const int TAM_INICIAL = 5;

      TipoBase * vector;
      int ocupadas;
      int reservadas;
      TipoRedimension tipo_redimension;

   public:
      VectorDinamico();
      VectorDinamico(int);
      VectorDinamico(const VectorDinamico &);
      ~VectorDinamico();
      bool EstaVacio();
      int GetCasillasOcupadas();
      int GetCasillasReservadas();
      TipoBase GetValor(int);
      void SetValor(TipoBase);
      void SetTipoRedimension(TipoRedimension);
      TipoRedimension GetTipoRedimension();

   private:
      TipoBase CasillasReservadas();
      void Redimensiona();
      void AjustaTamanio();
      void ReservaMemoria(int);
      void LiberaMemoria();
      void CopiaVector(const VectorDinamico &);

};

#endif