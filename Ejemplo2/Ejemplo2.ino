int PIN_DE_ENTRADA = 2;
int PIN_DE_SALIDA  = 3;
int LED_DE_TESTEO  = 13;

template<typename T>
void print ( const T& toPrint ){
    Serial.println(String(toPrint)); // imprimir la cadena en la consola
}

void setPinModes(){
  
   pinMode(PIN_DE_ENTRADA, INPUT); //CONFIGURO EL PIN 2 COMO ENTRADA
   pinMode(PIN_DE_SALIDA,  OUTPUT); //CONFIGURO EL PIN 3 COMO SALIDA
   pinMode(LED_DE_TESTEO,  OUTPUT); //CONFIGURO EL PIN 13 COMO SALIDA

}
void setup() {
 //Seteos iniciales, se ejecuta solo la primer vez
   Serial.begin(9600); // Inicializar el puerto serie a una velocidad de 9600 baudios
   setPinModes();
}

void leerEstadoBoton( int estado ){
  int counter = 0;
  while (digitalRead(2) == estado){
       digitalWrite(3,  estado );
       digitalWrite(13, estado );
     
       if (counter == 0 && estado == 1) {
         print("ENCENDIDO");
         counter++;
       }
       else if (counter == 0 && estado == 0){
         print("APAGADO");
         counter++;
       }
   }
}
void loop() {
  leerEstadoBoton(0);
  leerEstadoBoton(1);
}
