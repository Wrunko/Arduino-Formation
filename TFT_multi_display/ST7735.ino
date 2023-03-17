#include "config.h"
#ifdef ST7735
#include "tft_positions.h"
#include <Adafruit_GFX.h>     // Core graphics library
#include <Adafruit_ST7735.h>  // Hardware-specific library for ST7735
#include <SPI.h>
#define TFT_CS 10
#define TFT_RST 8  // Or set to -1 and connect to Arduino RESET pin
#define TFT_DC 9

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
void screenSetup() {
  tft.fillScreen(0x0);
  tft.setCursor(34, 10);
  tft.setTextSize(2);
  tft.setTextColor(0x7FB8);
  tft.print("Orsys");
  tft.setCursor(5, 50);
  tft.setTextSize(1);
  tft.setTextColor(0x7FB8);
  tft.setCursor(15, 140);
  tft.print("copyright 2023");
}
void screenCadreBase() {
  #ifdef TEMPERATURE_SENSOR
    makeCadre(CADRE_A0_X, CADRE_A0_Y, CADRE_GENERIC_W, CADRE_GENERIC_H, "T°c");
  #endif
  #ifdef PRESSURE_SENSOR
    makeCadre(CADRE_A1_X, CADRE_A1_Y, CADRE_GENERIC_W, CADRE_GENERIC_H, "HPascal");
  #endif
  #ifdef HUMIDITY_SENSOR
    makeCadre(CADRE_A2_X, CADRE_A2_Y, CADRE_GENERIC_W, CADRE_GENERIC_H, "%rH");
  #endif
}
void setupOutput() {
  // put your setup code here, to run once:
  tft.initR(INITR_BLACKTAB);
  screenSetup();
  delay(1000);
  tft.fillScreen(TFT_BACKGROUND_COLOR);
  screenCadreBase();
}
void loopOutput() {
  #ifdef TEMPERATURE_SENSOR
    setFloatValueInCadre(CADRE_A0_X, CADRE_A0_Y,CADRE_GENERIC_W, CADRE_GENERIC_H, sensorsValues.temperature,CADRE_GENERIC_VALUE_PERCISION);
  #endif
  #ifdef PRESSURE_SENSOR
    setFloatValueInCadre(CADRE_A1_X, CADRE_A1_Y,CADRE_GENERIC_W, CADRE_GENERIC_H, sensorsValues.pressure,0);
  #endif
  #ifdef HUMIDITY_SENSOR
    setFloatValueInCadre(CADRE_A2_X, CADRE_A2_Y,CADRE_GENERIC_W, CADRE_GENERIC_H, sensorsValues.humidity,0);
  #endif

}
#endif