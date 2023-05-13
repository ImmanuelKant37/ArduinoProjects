#include "Helper.h"
#include "ArrayHLP.h"
int BOTON_ENCENDIDO = false;
int BRILLO   = 0;
int PULSADOR = 2; 
int LED=3; 
int ESTADO=LOW; 
int PIN_DE_SALIDA = 3;
Helper hlp;
ArrayHLP arrayHLP;

void setup(){
  Serial.begin(9600);
  int numeros[] = {1, 2, 3, 4, 5}; // Array de enteros inicializado con los valores 1, 2, 3, 4 y 5
  arrayHLP.print(numeros);
  hlp.print("Test");
// pinMode(PULSADOR, INPUT); 
// pinMode(LED, OUTPUT); 
// digitalWrite(LED, LOW);
}

void leerEstadoBotonApagado(){
  int counter = 0;
  while(digitalRead(PULSADOR) == 1){ 	// espera infinitamente hasta que se presione el pulsador       
       if (counter == 0) {
          counter = 1;
          if (digitalRead(LED) == 0){
             hlp.print("APAGADO");
          }
          delay(50);
       }
     }
   }

void leerEstadoBotonEncendido(){
  int counter = 0;
  while(digitalRead(PULSADOR) == 0){ 	// espera infinitamente hasta que se presione el pulsador
       if (counter == 0) {
          counter = 1;
          if (digitalRead(LED) == 1){
          hlp.print("ENCENDIDO");
         }        
        delay(50);
       }
     }
   }

void loop (){ 
 
  delay(500);
  // leerEstadoBotonApagado();
  // ESTADO = digitalRead(LED); 		// leo estado del LED para saber si esta encendido o apagado
//  digitalWrite(LED, !ESTADO); 		// escribo en la salida el valor apuesto al leido con anterioridad
//  efectoLuz();
//  leerEstadoBotonEncendido();
}

void efectoLuz(){
   while (digitalRead(2) == 1 && BOTON_ENCENDIDO) {
          for (BRILLO = 0; BRILLO < 256; BRILLO ++){
            analogWrite(PIN_DE_SALIDA, BRILLO);
            if (digitalRead(2) == 1){
              BOTON_ENCENDIDO = true;
              hlp.print(BOTON_ENCENDIDO);
            }
            else{  
              BOTON_ENCENDIDO = false;
              break;
            } 
            delay(15);
          }
          for (BRILLO = 255; BRILLO >= 0; BRILLO --){
            analogWrite(PIN_DE_SALIDA, BRILLO);
            hlp.print(BOTON_ENCENDIDO);
            delay(15);
          }
      }
}