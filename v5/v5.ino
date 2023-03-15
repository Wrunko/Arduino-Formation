#include <Adafruit_GFX.h> 
#include <Adafruit_ST7735.h>
#include <Adafruit_ST77xx.h>
#include <SPI.h>

#define TFT_CS        10
#define TFT_RST        8
#define TFT_DC         9

#define PIN_MESURE_TENSION A0
#define R1 2000
#define R2 560

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

float p = 3.1415926;



float calculVin(float tensionVOUT) {

  float tensionVIN;

  tensionVOUT = 5.0F / 1024.0F * tensionVOUT;
  tensionVIN = tensionVOUT * ((R1 + R2) / R2);

  return tensionVIN;
}


void interfaceVoltmetre(){

  tft.drawRect(tft.width()/2-tft.width()/4, tft.height()/2 , 80, 40, ST77XX_WHITE);
  tft.setCursor(tft.width()/2-tft.width()/8, tft.height()/4);
  tft.setTextColor(ST77XX_GREEN);
  tft.setTextSize(1);
  tft.print("VOLTMETRE");

  tft.setCursor(tft.width()/2-tft.width()/8, tft.height()/2 + tft.height()/3);
  tft.setTextColor(ST77XX_RED);
  tft.setTextSize(2);
  tft.print("VOLT");    
}

void interfaceAccueil(){
  
  tft.fillScreen(ST77XX_BLUE);
  tft.setCursor(tft.width()/2-tft.width()/8, tft.height()/4);
  tft.setTextColor(ST77XX_GREEN);
  tft.print("ORSYS");
  
  delay(500);
}

void setup() {

  Serial.begin(9600);
  pinMode(PIN_MESURE_TENSION, INPUT);

  Serial.print(F("Hello! ST77xx TFT Test"));
  tft.initR(INITR_BLACKTAB); 
   
}

void loop() {
  
  uint16_t mesureAnalogique = analogRead(PIN_MESURE_TENSION);
  tft.setCursor(tft.width()/2-tft.width()/8, tft.height()/2+tft.width()/8);
  tft.setTextSize(2);
  tft.print(calculVin(mesureAnalogique));

  interfaceVoltmetre();
  
  delay(800);
  tft.fillScreen(ST77XX_DARK);
  
}
