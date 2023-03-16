#include <Arduino.h>
#include "tft_positions.h"

#include <Adafruit_ST7735.h>  // Hardware-specific library for ST7735
#include <Adafruit_ST77xx.h>

void makeCadre(uint8_t x, uint8_t y, uint8_t largeur, uint8_t hauteur, const char* titre) {

  tft.setCursor(CADRE_FROMREF_TITLE_X + x, CADRE_FROMREF_TITLE_Y + y);
  tft.setTextSize(CADRE_TITLE_SIZE);
  tft.setTextColor(CADRE_TITLE_TEXT_COLOR);
  tft.print(titre);
  //tft.drawRect(2 + x, y + 18, tft.width()/2 - 4, height - 18, 0xFFFF);
  tft.fillRect(x + CADRE_FROMREF_VALUE_RECT_X, y + CADRE_FROMREF_VALUE_RECT_Y, largeur - CADRE_FROMREF_VALUE_RECT_X * 2, hauteur - CADRE_FROMREF_VALUE_RECT_Y - 2, CADRE_TITLE_COLOR);
}


void setFloatValueInCadre(uint8_t x, uint8_t y, uint8_t largeur, uint8_t hauteur, float value, uint8_t precision) {

  tft.fillRect(x + CADRE_FROMREF_VALUE_RECT_X, y + CADRE_FROMREF_VALUE_RECT_Y, largeur - CADRE_FROMREF_VALUE_RECT_X * 2, hauteur - CADRE_FROMREF_VALUE_RECT_Y - 2, CADRE_TITLE_COLOR);
  if (largeur == CADRE_GRAND_W) {
    tft.setCursor(x + CADRE_FROMREF_TITLE_X + DECALAGE_GRAND_CADRE_TEXTE_X, y + CADRE_FROMREF_TITLE_Y + DECALAGE_GRAND_CADRE_TEXTE_Y);
    tft.setTextSize(CADRE_GRAND_TITLE_SIZE);
  } else {
    tft.setCursor(x + CADRE_FROMREF_TITLE_X + DECALAGE_CADRE_TEXTE_X, y + CADRE_FROMREF_TITLE_Y + DECALAGE_CADRE_TEXTE_Y);
    tft.setTextSize(CADRE_TITLE_SIZE);
  }
  
  tft.setTextColor(CADRE_VALUE_TEXT_COLOR);
  char buffer[precision + 4];
  tft.print(dtostrf(value, 2, precision, buffer));
}