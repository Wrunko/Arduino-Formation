#include <LiquidCrystal.h>

#define PIN_MESURE_TENSION A0
#define R1 2000
#define R2 560

/**
* defnition des variables pour gérer l'écran
*/
const int rs = 12, en = 11, d4 = 7, d5 = 6, d6 = 5, d7 = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


/**
*Calcul de la tension d'entre a partir des resistances et Vout
*/
float calculVin(float tensionVOUT){

  float tensionVIN;

  tensionVOUT = 5.0F/1024.0F*tensionVOUT;
  tensionVIN = tensionVOUT*((R1+R2)/R2);

  return tensionVIN;

}



void setup() {

  Serial.begin(9600);
  /** set up the LCD's number of columns and rows: */
  lcd.begin(16, 2);
  /** Print a message to the LCD. */
  lcd.print("Orsys");
  lcd.setCursor(0, 1);
  lcd.print("Voltmetre");
  delay(2000);

  lcd.clear();
  
  pinMode(PIN_MESURE_TENSION, INPUT);

}

void loop() {

  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  uint16_t mesureAnalogique = analogRead(PIN_MESURE_TENSION);
  lcd.setCursor(0,0);
  lcd.print("Voltmetre");
  lcd.setCursor(0,1);
  lcd.print(calculVin(mesureAnalogique));
  lcd.print(" V");
  
  // print the tension value:
  delay(500);
  
}

