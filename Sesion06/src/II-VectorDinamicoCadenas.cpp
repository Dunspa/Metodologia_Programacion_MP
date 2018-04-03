//////////////////////////////////////////////////////////////////////////
//
// Metodolog�a de la Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
// Relaci�n de problemas II, Ejercicio 4
// Programa principal
//
// Lee una secuencia indeterminada de cadenas de caracteres mediante redirecci�n
// de entrada con un fichero "prueba" y las guarda en memoria de manera que sean 
// accesibles a trav�s de un vector din�mico de cadenas cl�sicas. 
// El programa muestra el n�mero total de l�neas, l�neas no vac�as y p�rrafos
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

char ** Redimensiona(char **, int &);

int main(){
   int TAMANIO = 10;
	char ** v  = new char * [TAMANIO];
   int num_lineas = 0, vacias = 0, num_parrafos = 0, utilizados = 0;
   string cadena;
	bool fin_linea = false;

	while (getline(cin, cadena)){
      /* Vector din�mico de caracteres con la capacidad estrictamente necesaria
      de cada l�nea le�da en cada vuelta */
      char * caracteres = new char [cadena.size() + 1];
      strcpy(caracteres, cadena.c_str());
		utilizados += strlen(caracteres) + 1;

		while (utilizados >= TAMANIO){
			v = Redimensiona(v, TAMANIO);
		}

		// Se almacena la direcci�n de memoria del primer elemento de la cadena
		v[num_lineas] = caracteres;

		num_lineas++;
	}
	
	for (int i = 0 ; i < num_lineas ; i++){
		/* Esta l�nea est� vac�a */
		if (*(*(v + i)) == '\0'){
			/* El caracter anterior es un \0, lo cual significa que hemos cambiado 
			de parrafo */
			if (fin_linea){
				num_parrafos++;
			}

			// N�mero de l�neas vac�as
			vacias++;
		}
		else{
			fin_linea = false;
		}
		for (int j = 0 ; j <= strlen(*(v + i)) ; j++){
			// Indicamos que se ha terminado la l�nea
			if(*(*(v + i) + j) == '\0'){
				fin_linea = true;
			}
		}
	}
	
	// Liberaci�n de memoria
	delete [] v;
	
   cout << endl << "N�mero total de l�neas: " << num_lineas << endl;
	cout << "N�mero de l�neas no vac�as: " << num_lineas - vacias << endl;
	cout << "N�mero total de p�rrafos: " << num_parrafos << endl;
}

// Redimensiona un vector de punteros a punteros a char
char ** Redimensiona(char ** p, int & cap){
	// Redimensi�n de uno en uno
	cap++;

	char ** q = new char * [cap];
	memcpy(q, p, cap*sizeof(char));
	delete [] p;
	memcpy(p, q, cap*sizeof(char));
	delete [] q;

	return p;
}