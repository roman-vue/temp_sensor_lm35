

// Declaracion de variables globales
int LED_RED = 12;
int LED_GREEN = 13;
float tempC; // Variable para almacenar el valor obtenido del sensor (0 a 1023)
int pinLM35 = 0; // Variable del pin de entrada del sensor (A0)


void setup() {
  // Configuramos el puerto serial a 9600 bps
  Serial.begin(9600);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);

}

void loop() {
  // Con analogRead leemos el sensor, recuerda que es un valor de 0 a 1023
  tempC = analogRead(pinLM35);

  // Calculamos la temperatura con la fórmula
  tempC = (5.0 * tempC * 100.0) / 1023.0;

  // Envia el dato al puerto serial


  if (tempC != 0 || tempC != 0.00) {
    Serial.println(tempC);
  } else {
    // Salto de línea
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_GREEN, LOW);
  }

  if (tempC > 18.00) {
    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_GREEN, LOW);
  } else {
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_RED, LOW);
  }



  // Esperamos un tiempo para repetir el loop
  delay(2000);
}
