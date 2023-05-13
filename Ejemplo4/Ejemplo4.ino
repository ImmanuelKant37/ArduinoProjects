#include <Arduino_Threads.h>

int BOTON_ENCENDIDO = false;
int BRILLO   = 0;
int PULSADOR = 2; 
int LED=3; 
int ESTADO=LOW; 

template<typename T>
void print ( const T& toPrint ){
    Serial.println(String(toPrint)); // imprimir la cadena en la consola
}

void myThreadFunction() {
  while (true) {
      leerEstadoBotonApagado();

      ESTADO = digitalRead(LED); 		// leo estado del LED para saber si esta encendido o apagado
      digitalWrite(LED, !ESTADO); 		// escribo en la salida el valor apuesto al leido con anterioridad

      leerEstadoBotonEncendido();
  }
}
Thread myThread = Thread();

void configureThread() {
myThread.onRun(myThreadFunction);  // Asignar la función al hilo
myThread.setInterval(100);         // Ejecutar cada 100ms
myThread.enable();                 // Habilitar el hilo
}


void setup(){ 
Serial.begin(9600); // Inicializar el puerto serie a una velocidad de 9600 baudios
pinMode(PULSADOR, INPUT); 
pinMode(LED, OUTPUT); 
digitalWrite(LED, LOW);
configureThread();

 } 
void leerEstadoBotonEncendido(){
  int counter = 0;
  while(digitalRead(PULSADOR) == 1){ 	// espera infinitamente hasta que se presione el pulsador       
       if (counter == 0) {
          counter = 1;
          if (digitalRead(LED) == 0){
             print("APAGADO");
          }
          delay(50);
       }
     }
   }

void leerEstadoBotonApagado(){
  int counter = 0;
  while(digitalRead(PULSADOR) == 0){ 	// espera infinitamente hasta que se presione el pulsador

       if (counter == 0) {
          counter = 1;
          if (digitalRead(LED) == 1){

          print("ENCENDIDO");
         }        
        delay(50);
       }
     }
   }

void loop (){ 
   ThreadController.run();

}

void efectoLuz(){
   while (digitalRead(2) == 1) {
          for (BRILLO = 0; BRILLO < 256; BRILLO ++){
            analogWrite(PIN_DE_SALIDA, BRILLO);
            delay(15);
          }
          for (BRILLO = 255; BRILLO >= 0; BRILLO --){
            analogWrite(PIN_DE_SALIDA, BRILLO);
            delay(15);
          }
}
}