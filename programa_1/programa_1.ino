const int switches[] = {2, 3, 4, 5, 6, 7, 8, 9}; // Pines conectados a E0-E7
const int numSwitches = 8;

void setup() {
    Serial.begin(9600);

    for (int i = 0; i < numSwitches; i++) {
        pinMode(switches[i], INPUT);  // Configura como entrada sin pull-up
    }
}

void loop() {
    Serial.print("Estado: ");
    
    for (int i = 0; i < numSwitches; i++) {
        Serial.print(digitalRead(switches[i]));  // Lee el estado de los switches
        Serial.print(" ");
    }
    
    Serial.println();
    delay(500);  // Pequeña pausa para evitar lecturas excesivas
}
