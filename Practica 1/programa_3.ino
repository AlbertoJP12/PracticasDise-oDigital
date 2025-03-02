const int botones[] = {2, 3, 4, 5};  // Pines de los botones
const int leds[] = {6, 7, 8, 9};     // Pines de los LEDs
const int numBotones = 4;

void setup() {
    for (int i = 0; i < numBotones; i++) {
        pinMode(botones[i], INPUT);   // Botones como entradas
        pinMode(leds[i], OUTPUT);     // LEDs como salidas
    }
}

void loop() {
    for (int i = 0; i < numBotones; i++) {
        if (digitalRead(botones[i]) == HIGH) {  
            digitalWrite(leds[i], HIGH);  // Enciende el LED correspondiente
        } else {
            digitalWrite(leds[i], LOW);   // Apaga el LED si no se presiona el botón
        }
    }
}
