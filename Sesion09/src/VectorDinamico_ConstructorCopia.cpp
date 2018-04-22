//////////////////////////////////////////////////////////////////////////
//
// Metodolog�a de la Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
// Relaci�n de problemas III
// Definici�n de la clase "VectorDinamico"
//
// Clase que trabaja con vectores din�micos de TipoBase
//
//////////////////////////////////////////////////////////////////////////

#include <cstring>
#include "VectorDinamico_ConstructorCopia.h"

// a) Constructor sin argumentos:
// Crea un vector din�mico con un n�mero de casillas predeterminado 
VectorDinamico :: VectorDinamico()
   : ocupadas(0), reservadas(TAM_INICIAL)
{

   ReservaMemoria(TAM_INICIAL);

}

// b) Constructor con un argumento:
// Crea un vector din�mico con un n�mero de casillas indicado en el argumento
VectorDinamico :: VectorDinamico(int num_casillas)
   : ocupadas(0), reservadas(num_casillas)
{

   ReservaMemoria(num_casillas);

}

// c) Constructor de copia
VectorDinamico :: VectorDinamico(const VectorDinamico & v)
   : ocupadas(v.ocupadas), reservadas(v.reservadas)
{

   ReservaMemoria(v.reservadas);
   CopiaVector(v);

}

// d) Destructor
VectorDinamico :: ~VectorDinamico(){

   LiberaMemoria();

}

// e) Consulta si el vector est� vac�o
bool VectorDinamico :: EstaVacio(){

   return (ocupadas == 0);

}

// f) Consulta el n�mero de casillas ocupadas/reservadas
int VectorDinamico :: GetCasillasOcupadas(){

   return ocupadas;

}

int VectorDinamico :: GetCasillasReservadas(){

   return reservadas;

}

// g) Devuelve el valor que ocupa una posici�n dada
TipoBase VectorDinamico :: GetValor(int pos){
	
	// Controla que la posici�n introducida es correcta
	if (pos < ocupadas){

   	return vector[pos];

	}

}

// h) A�ade un valor. Si no hay espacio, redimensiona el vector
void VectorDinamico :: SetValor(TipoBase valor){

	if (reservadas == ocupadas){

   	Redimensiona();

	}

	vector[ocupadas] = valor;
	ocupadas++;

}

// i) Ajusta el tama�o del vector 
// De esta forma su capacidad coincidir� con el n�mero de casillas ocupadas
void VectorDinamico :: AjustaTamanio(){

   tipo_redimension = Ajustar;
	
	Redimensiona();

}

// j) Establece/consulta el tipo de redimensionamiento
void VectorDinamico :: SetTipoRedimension(TipoRedimension tipo){

   tipo_redimension = tipo;

}

TipoRedimension VectorDinamico :: GetTipoRedimension(){

   return tipo_redimension;

}

void VectorDinamico :: ReservaMemoria(int tamanio){

   vector = new TipoBase [tamanio];

   reservadas = tamanio;

}

void VectorDinamico :: LiberaMemoria(){

   delete [] vector;

   reservadas = 0;
   ocupadas = 0;

}

void VectorDinamico :: CopiaVector(const VectorDinamico & v){

   memcpy(vector, v.vector, ocupadas*sizeof(TipoBase));

}

void VectorDinamico :: Redimensiona(){
   const int TAM_BLOQUE = 3;

   // Se reservan tantas casillas seg�n el tipo de redimensi�n
   if (tipo_redimension == DeUnoEnUno){
      reservadas++;
   }  
   else if (tipo_redimension == EnBloques){
      reservadas += TAM_BLOQUE;
   }
   else if (tipo_redimension == Duplicando){
      reservadas *= 2;
   }
	else if (tipo_redimension == Ajustar){
		reservadas = ocupadas;
	}

   // Copia del vector en el temporal
   VectorDinamico tmp (*this);

   // Liberaci�n del vector
   LiberaMemoria();

   // Se reserva de nuevo memoria para el vector
   ReservaMemoria(tmp.reservadas);

   // Se devuelven los datos al vector
   ocupadas = tmp.ocupadas;
   CopiaVector(tmp);

}