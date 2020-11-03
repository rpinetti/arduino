/***************************************\
**    ROBOCORE ARDUINO KIT INICIANTE   **
*                                       *
**            Projeto Piano            **
\***************************************/

const int verdePin = 12;
const int amareloPin = 11;
const int vermelhoPin = 13;
const int btnVerde = 4;
const int btnAmarelo = 5;
const int btnVermelho = 6;
const int buzzer = 10;

const int tomVerde = 100;
const int tomAmarelo = 200;
const int tomVermelho = 500;

int estadoBtnVerde = 0;
int estadoBtnAmarelo = 0;
int estadoBtnVermelho = 0;
int tom = 0;

/**
 * Estado inicial das portas
 */
void setup() {
  pinMode(verdePin, OUTPUT);
  pinMode(btnVerde, INPUT);
  pinMode(amareloPin, OUTPUT);
  pinMode(btnAmarelo, INPUT);
  pinMode(vermelhoPin, OUTPUT);
  pinMode(btnVermelho, INPUT);
  pinMode(buzzer, OUTPUT);
} // void setup()

/**
 * Rotina principal 
 */
void loop() {

  estadoBtnVerde = digitalRead(btnVerde);
  estadoBtnAmarelo = digitalRead(btnAmarelo);
  estadoBtnVermelho = digitalRead(btnVermelho);

  // Quando o btnVerde for apertado liga o led verde
  if (estadoBtnVerde && !estadoBtnAmarelo && !estadoBtnVermelho) {
    tom = tomVerde;
    digitalWrite(verdePin, HIGH);
  }
  
  // Quando o btnAmarelo for apertado liga o led amarelo
  if (!estadoBtnVerde && estadoBtnAmarelo && !estadoBtnVermelho) {
    tom = tomAmarelo;
    digitalWrite(amareloPin, HIGH);
  }

  // Quando o btnVermelho for apertado liga o led vermelho
  if (!estadoBtnVerde && !estadoBtnAmarelo && estadoBtnVermelho) {
    tom = tomVermelho;
    digitalWrite(vermelhoPin, HIGH);
  }

  // Quando o btnVerde + btnAmarelo for apertado liga o led verde e amarelo
  if (estadoBtnVerde && estadoBtnAmarelo && !estadoBtnVermelho) {
    tom = tomVerde + tomAmarelo;
    digitalWrite(verdePin, HIGH);
    digitalWrite(amareloPin, HIGH);
  }  

  // Quando o btnVerde + btnVermelho for apertado liga o led verde e vermelho
  if (estadoBtnVerde && !estadoBtnAmarelo && estadoBtnVermelho) {
    tom = tomVerde + tomVermelho;
    digitalWrite(verdePin, HIGH);
    digitalWrite(vermelhoPin, HIGH);
  }  

  // Quando o btnVermelho + btnAmarelo for apertado liga o led vermelho e amarelo
  if (!estadoBtnVerde && estadoBtnAmarelo && estadoBtnVermelho) {
    tom = tomAmarelo + tomVermelho;
    digitalWrite(amareloPin, HIGH);
    digitalWrite(vermelhoPin, HIGH);
  }  

  // Faz barulho
  if (tom > 0) {
    digitalWrite(buzzer, HIGH); // Liga o buzzer
    delayMicroseconds(tom); // Espera o tempo proporcional ao comprimento de onda da nota musical em milisegundos
    digitalWrite(buzzer, LOW);  // Desliga o buzzer
    delayMicroseconds(tom); // Espera o tempo proporcional ao comprimento de onda da nota musical em milisegundos
    tom = 0;
    digitalWrite(verdePin, LOW);
    digitalWrite(amareloPin, LOW);
    digitalWrite(vermelhoPin, LOW);
  }
  
} // void loop()
