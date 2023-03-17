#ifndef _TFT_POSITIONS_H_
#include <Adafruit_ST77xx.h>
#define ST77XX_PINK 0xEAEB
#define _TFT_POSITIONS_H_
#define TFT_WIDTH 128.0F
#define TFT_HEIGHT 160.0F
#define TFT_BACKGROUND_COLOR ST77XX_BLACK
/******************************************
  * def des position relative dans un cadre *
  *******************************************/
#define CADRE_FROMREF_TITLE_X 2
#define CADRE_FROMREF_TITLE_Y 6

#define CADRE_TITLE_SIZE 1
#define CADRE_VALUE_SIZE 2
#define CADRE_TITLE_COLOR ST77XX_WHITE
#define CADRE_VALUE_COLOR ST77XX_BLACK
#define CADRE_VALUE_SIZE 2

#define CADRE_FROMREF_VALUE_RECT_X 2
#define CADRE_FROMREF_VALUE_RECT_Y 20
#define CADRE_FROMREF_VALUE_X CADRE_FROMREF_VALUE_RECT_X + 2
#define CADRE_FROMREF_VALUE_Y CADRE_FROMREF_VALUE_RECT_Y + (CADRE_VALUE_SIZE * 8)
/******CADRE GENERIC CONFIG***************/
#define CADRE_GENERIC_W TFT_WIDTH / 2.0F
#define CADRE_GENERIC_H (TFT_HEIGHT - 25.0F) / 2.0F
#define CADRE_GENERIC_VALUE_PERCISION 2
/***********CADRE VALUE A0****************/
#define CADRE_A0_X 0
#define CADRE_A0_Y 10
/***********CADRE VALUE A1****************/
#define CADRE_A1_X CADRE_GENERIC_W
#define CADRE_A1_Y 10
/***********CADRE VALUE A1****************/
#define CADRE_A2_X CADRE_GENERIC_W
#define CADRE_A2_Y CADRE_GENERIC_H + 15

#endif