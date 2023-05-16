#ifndef ArrayHLP_h
#define ArrayHLP_h
#include <Arduino.h>  // Asegúrate de incluir esta línea

class ArrayHLP {
public:
  ArrayHLP();
  
  /*OBTENER TAMAÑO DE ARRAY*/
  template <typename T, size_t N>
  int getSize(const T (&arr)[N]) {
  return N;
  }
  /*IMPRIMIR UN ARRAY*/
  template <typename T, size_t N>
  void print(const T (&arr)[N]) {
  for (int i = 0; i < N; ++i) {
    Serial.print(arr[i]);
    Serial.print(' ');
  }
  Serial.println();
}
};

#endif
