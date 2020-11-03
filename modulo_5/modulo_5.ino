/***************************************\
**   ROBOCORE ARDUINO KIT INICIANTE   **
*                                      *
**              Módulo 5              **
* O potenciometro controla a intencidade da letra              
\***************************************/
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Arduino!!!");
  lcd.setCursor(0,1);
  lcd.print("Bob :)");
}

void loop() {
  // put your main code here, to run repeatedly:

}
