#include "Helper.h"
#include "ArrayHLP.h"
int BOTON_ENCENDIDO = false;
int BRILLO1   = 0;
int BRILLO2   = 0;
int BRILLO_REAL=0;
int PULSADOR = 2; 
int LED=3; 
int ESTADO=LOW; 
int PIN_DE_SALIDA = 3;
int CONTADOR = 0;
int POT = 0;
Helper hlp;
ArrayHLP arrayHLP;

void setup(){
  Serial.begin(9600);
  hlp.print("MODO INICIADO");
  
}

void loop (){ 
    if (CONTADOR == 0 && botonPresionado()){
      CONTADOR = 1;
      hlp.print("MODO REGULABLE");
      setValorPotenciometro();
    }
    
    else if (CONTADOR == 1){
      hlp.print("MODO CRECIENTE");
      efectoLuz();
      CONTADOR = 2;
    }
    else if (CONTADOR == 2){
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
void setValorPotenciometro(){
    while (true) {

    BRILLO1 = analogRead(POT) / 4;
    delay(200);
    BRILLO2 = analogRead(POT) / 4;
    if (BRILLO1 == BRILLO2 - 1 || BRILLO1 == BRILLO2 +1){
      BRILLO2 = BRILLO1;
    }
    bool HUBO_CAMBIO = BRILLO1 != BRILLO2;
    if (HUBO_CAMBIO){
    analogWrite(LED, BRILLO2);
    hlp.print("BRILLO : "+String(BRILLO1));
    }
    if (botonPresionado()) {
        analogWrite(PIN_DE_SALIDA, LOW);
        break;
    }
  }
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

