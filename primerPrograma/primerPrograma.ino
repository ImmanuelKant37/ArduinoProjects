int numeroDePin(int numPin){return numPin;};
int miNumero = 2;
int counter = 0;
void setup() {
 //Seteos iniciales, se ejecuta solo la primer vez
  counter = 0;
  Serial.begin(9600); // Inicializar el puerto serie a una velocidad de 9600 baudios
  pinMode(numeroDePin(13), OUTPUT); //CONFIGURO EL PIN 13 COMO SALIDA
}

void loop() {
  //Programa permanente
  digitalWrite(numeroDePin(13), HIGH);

  //Coloca un nivel alto en el pin
  delay(1000);
  counter++;
  Serial.println(counter); // Imprimir un mensaje en la consola

  //Espera de un segundo
  digitalWrite(numeroDePin(13), LOW);
  //Baja de tension y espera
  delay(1000);
}
