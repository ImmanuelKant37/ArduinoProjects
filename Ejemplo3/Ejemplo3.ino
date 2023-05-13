int PULSADOR = 2; 
int LED=3; 
int ESTADO=LOW; 
template<typename T>
void print ( const T& toPrint ){
    Serial.println(String(toPrint)); // imprimir la cadena en la consola
}
void setup(){ 
Serial.begin(9600); // Inicializar el puerto serie a una velocidad de 9600 baudios
pinMode(PULSADOR, INPUT); 
pinMode(LED, OUTPUT); 
digitalWrite(LED, LOW);
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
 leerEstadoBotonApagado();

ESTADO = digitalRead(LED); 		// leo estado del LED para saber si esta encendido o apagado
digitalWrite(LED, !ESTADO); 		// escribo en la salida el valor apuesto al leido con anterioridad

leerEstadoBotonEncendido();
}
