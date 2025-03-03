const int switches[] = {2, 3, 4, 5, 6, 7, 8, 9}; // Pines conectados a E0-E7
const int leds[] = {10, 11, 12, 13, A0, A1, A2, A3}; // Pines de los LEDs
const int numSwitches = 8;

void setup() {
    Serial.begin(9600);
    
    for (int i = 0; i < numSwitches; i++) {
        pinMode(switches[i], INPUT);  // Configura como entrada sin pull-up
        pinMode(leds[i], OUTPUT);     // Configura los LEDs como salida
    }
}

void loop() {
    Serial.print("Estado: ");
    
    for (int i = 0; i < numSwitches; i++) {
        int estado = digitalRead(switches[i]); // Lee el estado de los switches
        Serial.print(estado);
        Serial.print(" ");
        
        digitalWrite(leds[i], estado); // Enciende o apaga el LED correspondiente
    }
    
    Serial.println();
    delay(500);  // Pequeña pausa para evitar lecturas excesivas
}
