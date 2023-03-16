#include <Adafruit_GFX.h>     // Core graphics library
#include <Adafruit_ST7735.h>  // Hardware-specific library for ST7735
// #include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>



#include "tft_positions.h"



#define TFT_CS 10
#define TFT_RST 8  // Or set to -1 and connect to Arduino RESET pin
#define TFT_DC 9

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

#define PIN_VOLTMETRE A0

/**
* Pour calcul pont de diviseur
*/
#define MAX_VOLTS_INPUT 22.857F
#define RATION_VOLT (float)(22.857F / 5.0F)
#define RATIO_ADC (float)(5.0F / 1024.0F)


void screenSetup() {
  tft.setCursor(34, 10);
  tft.setTextSize(2);
  tft.setTextColor(0x7FB8);
  tft.print("Orsys");
  tft.setCursor(5, 50);
  tft.setTextColor(0xFFFF);
  tft.print("Volts");
  tft.setCursor(60, 70);
  tft.print("Metre");
  tft.setTextSize(1);
  tft.setTextColor(0x7FB8);
  tft.setCursor(15, 140);
  tft.print("copyright 2023");
}
// void screenCadreY(uint8_t x, uint8_t y, uint8_t height, const char *title) {
//   tft.setCursor(10 + x, 2 + y);
//   tft.setTextSize(1);
//   tft.setTextColor(0x7777);
//   tft.print(title);
//   tft.drawRect(2 + x, y + 18, tft.width()/2 - 4, height - 18, 0xFFFF);
//   tft.fillRect(4 + x, y + 20, tft.width()/2 - 8, height - 22, 0xFFFF);
// }
// void printInScreenCadre(uint8_t cadreX, uint8_t cadreY, uint8_t cadreHeight, const char *value) {
//   tft.fillRect(cadreX + 4, cadreY + 20, tft.width()/2 - 8, cadreHeight - 22, 0xFFFF);
//   tft.setCursor(cadreX + 15, cadreY + cadreHeight - 25);
//   tft.setTextColor(0x0);
//   tft.setTextSize(1);
//   tft.print(value);
//}
void screenVoltMetreBase() {
  tft.fillScreen(0x0);

  //screenCadreY(0, 5, 60, "Volts A0");
  //screenCadreY(0 ,75, 60, "Volts A0");
  //screenCadreY(tft.width()/2, 5, 60, "Volts A0");
  //screenCadreY(tft.width()/2, 75, 60, "Volts A0");

}
void setup() {
  // put your setup code here, to run once:
  tft.initR(INITR_BLACKTAB);
  tft.fillScreen(ST77XX_BLACK);
  screenSetup();
  delay(4000);
  tft.fillScreen(ST77XX_BLACK);
  //screenVoltMetreBase();
  makeCadre(CADRE_A0_X, CADRE_A0_Y, CADRE_GENERIC_W, CADRE_GENERIC_H, "V en A0");
  makeCadre(CADRE_A1_X, CADRE_A1_Y, CADRE_GENERIC_W, CADRE_GENERIC_H, "V en A1");
  makeCadre(CADRE_A2_X, CADRE_A2_Y, CADRE_GRAND_W, CADRE_GRAND_H, "V en A2");

}
/**
* caluculate final value of vin before kirshoff bridge
* @param vADC value on ADC pin
*/
float calculateVin(uint16_t vADC) {
  return RATIO_ADC * (float)vADC * RATION_VOLT;
}
void loop() {
  char buffer[6];
  setFloatValueInCadre(CADRE_A0_X, CADRE_A0_Y, CADRE_GENERIC_W, CADRE_GENERIC_H, calculateVin(analogRead(PIN_VOLTMETRE)), CADRE_GENERIC_VALUE_PRECISION);
  setFloatValueInCadre(CADRE_A1_X, CADRE_A1_Y, CADRE_GENERIC_W, CADRE_GENERIC_H, calculateVin(analogRead(PIN_VOLTMETRE)), CADRE_GRAND_VALUE_PRECISION);
  //printInScreenCadre(0, 75, 60, dtostrf(calculateVin(analogRead(A1)), 2, 2, buffer));

  //printInScreenCadre(tft.width()/2, 5, 60, dtostrf(calculateVin(analogRead(A1)), 2, 2, buffer));
  //printInScreenCadre(tft.width()/2, 75, 60, dtostrf(calculateVin(analogRead(A1)), 2, 2, buffer));

  delay(800);
  // put your main code here, to run repeatedly:
}
