#include "config.h"
#ifdef ST7735

#include <Adafruit_GFX.h>     // Core graphics library
#include <Adafruit_ST7735.h>  // Hardware-specific library for ST7735
#include <Adafruit_ST77xx.h>

#include "tft_positions.h"

#include "tft_positions.h"
#include "config.h"

#define TFT_CS 10
#define TFT_RST 8  // Or set to -1 and connect to Arduino RESET pin
#define TFT_DC 9


Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void screenSetup() {
  tft.fillScreen(ST77XX_BLACK);
  tft.setCursor(34, 10);
  tft.setTextSize(2);
  tft.setTextColor(0x7FB8);
  tft.print("Orsys");

  tft.setTextSize(1);
  tft.setTextColor(0x7FB8);
  tft.setCursor(15, 140);
  tft.print("copyright 2023");
}

void makeBandeau() {

  tft.fillRect(0, 0, tft.width(), 10, ST77XX_PINK);
  tft.fillRect((tft.width() / 2) - 20, 0, 40, 10, ST77XX_PINK);
}

void screenCadreBase(){
  
  #ifdef TEMPERATURE_SENSOR
  makeCadre(CADRE_A0_X, CADRE_A0_Y, CADRE_GENERIC_W, CADRE_GENERIC_H, "T°C");
  #endif

  #ifdef PRESSURE_SENSOR
  makeCadre(CADRE_A1_X, CADRE_A1_Y, CADRE_GENERIC_W, CADRE_GENERIC_H, "Hpascal");
  #endif

  makeCadre(CADRE_A2_X, CADRE_A2_Y, CADRE_GRAND_W, CADRE_GRAND_H, "X en A2");

}


void setupOutput() {

  tft.initR(INITR_BLACKTAB);
  screenSetup();
  delay(2000);
  tft.fillScreen(ST77XX_BLACK);
  screenCadreBase();
}


void loopOutput() {

  #ifdef TEMPERATURE_SENSOR
  setFloatValueInCadre(CADRE_A0_X, CADRE_A0_Y, CADRE_GENERIC_W, CADRE_GENERIC_H, sensorsValues.temperature, CADRE_GENERIC_VALUE_PRECISION);
  #endif

  #ifdef PRESSURE_SENSOR
  setFloatValueInCadre(CADRE_A1_X, CADRE_A1_Y, CADRE_GENERIC_W, CADRE_GENERIC_H, sensorsValues.pressure, CADRE_GENERIC_VALUE_PRECISION);
  #endif
  
  setFloatValueInCadre(CADRE_A2_X, CADRE_A2_Y, CADRE_GRAND_W, CADRE_GRAND_H, 1.2, CADRE_GRAND_VALUE_PRECISION);

}

#endif