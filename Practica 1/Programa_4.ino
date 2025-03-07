const int SEGMENTOS[] = {2, 3, 4, 5, 6, 7, 8}; 
const int DIGITOS[] = {10, 11, 12, 13, A0, A1};  

const byte NUMEROS[10] = {
  B0111111, // 0
  B0000110, // 1
  B1011011, // 2
  B1001111, // 3
  B1100110, // 4
  B1101101, // 5
  B1111101, // 6
  B0000111, // 7
  B1111111, // 8
  B1101111  // 9
};

void configurarPines() {
  for (int i = 0; i < 7; i++) {
    pinMode(SEGMENTOS[i], OUTPUT);
  }
  for (int i = 0; i < 6; i++) {
    pinMode(DIGITOS[i], OUTPUT);
    digitalWrite(DIGITOS[i], LOW);
  }
}

void mostrarNumero(int num) {
  byte valor = NUMEROS[num];
  for (int i = 0; i < 7; i++) {
    digitalWrite(SEGMENTOS[i], bitRead(valor, i));
  }
}

void apagarTodosLosDigitos() {
  for (int i = 0; i < 6; i++) {
    digitalWrite(DIGITOS[i], LOW);
  }
}

void setup() {
  configurarPines();
}

void loop() {
  // Mostrar los números 1,2,3,4,5,6 en los 6 displays
  for (int i = 0; i < 6; i++) {
    apagarTodosLosDigitos();
    mostrarNumero(i + 1);  // Mostrar número correspondiente al display
    digitalWrite(DIGITOS[i], HIGH); // Encender el display
    delay(1); // Breve retardo para multiplexado
  }
}
