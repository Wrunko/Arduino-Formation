#include <LiquidCrystal_I2C.h>
#include <Wire.h> 

#define PIN_MESURE_TENSION A0
#define R1 2000
#define R2 560

LiquidCrystal_I2C lcd(0x27,16,2);

/**
*Calcul de la tension d'entre a partir des resistances et Vout
*/
float calculVin(float tensionVOUT) {

  float tensionVIN;

  tensionVOUT = 5.0F / 1024.0F * tensionVOUT;
  tensionVIN = tensionVOUT * ((R1 + R2) / R2);

  return tensionVIN;
}

byte Omega[8] = {
  B00000,
  B00000,
  B01110,
  B10001,
  B10001,
  B01010,
  B11011,
};

void setup() {

  Serial.begin(9600);

  lcd.init();
  lcd.createChar(1, Omega);
  lcd.backlight();   
}

void loop() {

  uint16_t mesureAnalogique = analogRead(PIN_MESURE_TENSION);

  /* Affichage HUD et tension */
  lcd.setCursor(0, 0);
  lcd.write((byte)1);
  delay(2000);
  lcd.setCursor(0, 1);
  lcd.print(calculVin(mesureAnalogique));
  lcd.print(" V");

  // print the tension value:
  delay(500);
}