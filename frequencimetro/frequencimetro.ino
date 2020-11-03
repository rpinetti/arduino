/***************************************\
**   ROBOCORE ARDUINO KIT INICIANTE   **
*                                      *
**      Projeto Frequencímetro        **
\***************************************/
#include <LiquidCrystal.h>

const int botao1 = 8;
const int botao2 = 9;
const int buzzer = 6;

int ligarBuzzer = LOW;
int freq = 0;
int estadoBotao1 = 0;
int estadoBotao2 = 0;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {

  // Texto inicial do LCD
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Frequencia = ");
  lcd.setCursor(6,1 );
  lcd.print("Hz");

  // Define a função das portas
  pinMode(botao1, OUTPUT);
  pinMode(botao2, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
} // void setup()

void loop() {
  
  estadoBotao1 = digitalRead(botao1);
  estadoBotao2 = digitalRead(botao2);

  if (estadoBotao1 == HIGH) {
    freq += 100;  
  }

  if (estadoBotao2 == HIGH) {
    freq -= 100;  
  } 

  Serial.println("buzzer = " + ligarBuzzer);
  
  if (freq <= 0) {
    freq = 0;
    digitalWrite(buzzer, LOW);
  } else {

    if (freq == 100) {
      digitalWrite(buzzer, HIGH); 
    }
    
  }

  if (freq >= 20000) {
    freq = 20000;
  }

  if (freq <= 99) {
    lcd.setCursor(0,1);
    lcd.print(" ");
    lcd.setCursor(1,1);
    lcd.print(" ");
    lcd.setCursor(2,1);
    lcd.print(" ");
    lcd.setCursor(3,1);
  }

  if (freq >= 100) {
    lcd.setCursor(0,1);
    lcd.print(" ");
    lcd.setCursor(1,1);
    lcd.print(" ");
    lcd.setCursor(2,1);
  }

  if (freq >= 1000) {
    lcd.setCursor(0,1);
    lcd.print(" ");
    lcd.setCursor(1,1);
  }

  if (freq >= 1000) {
    lcd.setCursor(0,1);
  }

  lcd.print(freq);
  tone(buzzer, freq);

  delay(100);
  
} // void loop()
