//////////////////////////////////////////////////////////////////////////
//
// Metodolog�a de la Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
// Relaci�n de problemas I, Ejercicio 17
// Definici�n de la funci�n "MaximoMinimo" necesaria para I_MaxMin_Array.cpp
//
// Calcula el m�nimo y el m�ximo valor de un vector
// Recibe las posiciones inicial y final entre las que realizar la b�squeda y
// el m�nimo y el m�ximo por referencia
// Devuelve mediante referencias los valores de m�nimo y m�ximo calculados
//
//////////////////////////////////////////////////////////////////////////

void MaximoMinimo(int *pos_izda, int *pos_dcha, int &minimo, int &maximo){
   // Se inicializan el m�ximo y el m�nimo al primer valor
   minimo = *pos_izda;
   maximo = *pos_izda;

   /* Algoritmo: Se recorre el vector delimitado por los dos extremos izda y 
   dcha. Se va adelantando el puntero de izquierda a derecha hasta llegar al 
   final delimitado, y se va controlando si se encuentra un valor menor que el
   m�nimo o mayor que el m�ximo y se almacena por referencia */
   while (pos_izda <= pos_dcha){
      if (*pos_izda > maximo){
         maximo = *pos_izda;
      }
      
      if (*pos_izda < minimo){
         minimo = *pos_izda;
      }

      pos_izda++;
   }
}