const int segmentos[] = {2, 3, 4, 5, 6, 7, 8}; 
const int catodos[] = {10, 11, 12, 13, A0, A1};  

const byte numeros[10] = {
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

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(segmentos[i], OUTPUT);
  }
  for (int i = 0; i < 6; i++) {
    pinMode(catodos[i], OUTPUT);
    digitalWrite(catodos[i], LOW);
  }
}

void loop() {
  // Encender un display a la vez en orden
  for (int i = 0; i < 6; i++) {
    apagarTodosLosDigitos();
    mostrarNumero(i + 1);  // Mostrar su posición (1-6)
    digitalWrite(catodos[i], HIGH); // Encender el display
    delay(500);
  }

  // Mantener todos encendidos
  for (int i = 0; i < 6; i++) {
    mostrarNumero(i + 1);
    digitalWrite(catodos[i], HIGH);
  }
  while (true); // Detener el loop
}

void mostrarNumero(int num) {
  byte valor = numeros[num];
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentos[i], bitRead(valor, i));
  }
}

void apagarTodosLosDigitos() {
  for (int i = 0; i < 6; i++) {
    digitalWrite(catodos[i], LOW);
  }
}
