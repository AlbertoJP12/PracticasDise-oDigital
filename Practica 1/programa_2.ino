const int leds[] = {2, 3, 4, 5, 6, 7, 8, 9};  // Pines conectados a los LEDs
const int numLeds = 8;  // Número de LEDs

void setup() {
    // Configura los pines de los LEDs como salida
    for (int i = 0; i < numLeds; i++) {
        pinMode(leds[i], OUTPUT);
    }
}

void loop() {
    // Prende los LEDs uno por uno de izquierda a derecha
    for (int i = 0; i < numLeds; i++) {
        digitalWrite(leds[i], HIGH);  // Enciende el LED actual
        delay(360);  // Espera 360 ms
        digitalWrite(leds[i], LOW);  // Apaga el LED actual
    }
}
