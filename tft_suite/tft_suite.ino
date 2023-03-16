#include <TimeLib.h>
#include <SPI.h>
#include "structure.h"
#include "config.h"

struct SensorsValues sensorsValues;





/*void writeTime(tmElements_t tm){

  makeBandeau();

  tft.setCursor(0,1);
  tft.setTextSize(1);
  tft.setTextColor(ST77XX_BLACK);
  
  char buffer[11];
  sprintf(buffer, "%02d/%02d/%d", tm.Day, tm.Month, tmYearToCalendar(tm.Year));
  tft.print(buffer);

  tft.setCursor((tft.width() / 2) ,1);
  sprintf(buffer, "%02d:%02d", tm.Hour, tm.Minute);
  tft.print(buffer);
}*/



/*void screenVoltMetreBase() {
  tft.fillScreen(0x0);

}*/
void setup() {

  #ifdef OUTPUT_ACTIONNER
    setupOutput();
  #endif
  
  setupPressureUnit();
  delay(4000);

}

void loop() {

  //readAndShowDateTime();

  #ifdef TEMPERATURE_SENSOR
    readTemperature();
  #endif

  #ifdef PRESSURE_SENSOR
    readPressure();
  #endif
    
  #ifdef OUTPUT_ACTIONNER
    loopOutput();
  #endif

  delay(1000);

}
