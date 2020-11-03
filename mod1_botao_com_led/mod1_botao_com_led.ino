/***************************************\
**    ROBOCORE ARDUINO KIT INICIANTE   **
*                                       *
**              Módulo 1               **
\***************************************/

const int ledPin = 13; // LED no pino 13
const int botao = 2;  // botao no pino 2
int estadoBotao = 0; // Variavel para ler o status do botão 

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(ledPin, OUTPUT);
  pinMode(botao, INPUT);
} // setup()

// the loop function runs over and over again forever
void loop() {

  // novo estado do botão vai ser igual ao que Arduino ler no pino onde está o botão. Poderá ser ALTO (HIGH)se o botão estiver Pressionado, ou BAIXO (LOW),se o botão estiver solto
  estadoBotao = digitalRead(botao);

  if (estadoBotao == HIGH) { // Se botão estiver pressionado (HIGH)
    digitalWrite(ledPin, HIGH); // acende o led do pino 13.
  } else { //se não estiver pressionado
    digitalWrite(ledPin, LOW); //deixa o led do pino 13 apagado
  } // if (estadoBotao == HIGH)

}
