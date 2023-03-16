#if !defined(_TFT_POSITIONS_H_)
#define _TFT_POSITIONS_H_

#include <Adafruit_ST77xx.h>


#define ST77XX_PINK 0xEAEB
/******************** RESOLUTION ECRAN *************************/
#define LARGEUR_ECRAN 128.0F
#define LONGUEUR_ECRAN 160.0F

/**
* Pour positionnement relatif des cadres
**/
#define CADRE_FROMREF_TITLE_X 2
#define CADRE_FROMREF_TITLE_Y 6
#define CADRE_TITLE_SIZE 1
#define CADRE_GRAND_TITLE_SIZE 2
#define CADRE_TITLE_TEXT_COLOR ST77XX_WHITE
#define CADRE_VALUE_TEXT_COLOR ST77XX_BLACK
#define CADRE_TITLE_COLOR ST77XX_WHITE
#define CADRE_VALUE_SIZE 2
#define CADRE_FROMREF_VALUE_RECT_X 2
#define CADRE_FROMREF_VALUE_RECT_Y 20


/******************* DIMENSION GENERIQUE CADRE **************************/
#define CADRE_GENERIC_W LARGEUR_ECRAN / 2.0F
#define CADRE_GENERIC_H (LONGUEUR_ECRAN - 25) / 2.0F
#define CADRE_GENERIC_VALUE_PRECISION 2

/******************* DIMENSION GRAND CADRE **************************/
#define CADRE_GRAND_W LARGEUR_ECRAN
#define CADRE_GRAND_H (LONGUEUR_ECRAN - 25) / 2.0F
#define CADRE_GRAND_VALUE_PRECISION 2

/******************** A0 *************************/
#define CADRE_A0_X 0
#define CADRE_A0_Y 10

/******************** A1 *************************/
#define CADRE_A1_X LARGEUR_ECRAN / 2.0F
#define CADRE_A1_Y 10

/******************** A2 *************************/
#define CADRE_A2_X 0
#define CADRE_A2_Y (LONGUEUR_ECRAN) / 2.0F

#define DECALAGE_CADRE_TEXTE_X 15
#define DECALAGE_CADRE_TEXTE_Y 30

#define DECALAGE_GRAND_CADRE_TEXTE_X 40
#define DECALAGE_GRAND_CADRE_TEXTE_Y 30

#endif