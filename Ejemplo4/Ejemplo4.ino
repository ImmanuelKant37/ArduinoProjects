#include "Helper.h"
#include "ArrayHLP.h"
int BOTON_ENCENDIDO = false;
int BRILLO   = 0;
int PULSADOR = 2; 
int LED=3; 
int ESTADO=LOW; 
int PIN_DE_SALIDA = 3;
int CONTADOR = 0;

Helper hlp;
ArrayHLP arrayHLP;

void setup(){
  Serial.begin(9600);
  hlp.print("Iniciando...");
  
}
void loop (){ 
   // efectoLuz();
    if (CONTADOR == 0 && botonPresionado()){
      CONTADOR = 1;
      hlp.print("ENCENDIDO");
      efectoLuz();
    }
    else if (CONTADOR == 1){
      hlp.print("APAGADO");
      CONTADOR = 0;
    }
    delay(100); 
}
bool botonPresionado(){
  static bool estadoAnterior = false;
  bool estadoActual = digitalRead(PULSADOR);
  if (estadoActual == HIGH && estadoAnterior == LOW){
    estadoAnterior = true;
    digitalWrite(LED, LOW);
    return true;
  }
  estadoAnterior = estadoActual;
  return false;
}

void efectoLuz(){
  bool encendiendo = true;
  int brillo = 0;
  int incremento = 1;

  while (true) {
    analogWrite(PIN_DE_SALIDA, brillo);

    if (botonPresionado()) {
      analogWrite(PIN_DE_SALIDA, LOW);
      break;
    }

    delay(2);

   brillo = encendiendo ? brillo + incremento : brillo - incremento;
   encendiendo = (brillo >= 255) ? false : (brillo <= 0) ? true : encendiendo; 

  }
}

