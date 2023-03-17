#include <DS1307RTC.h>
#include <Timelib.h>
#include "config.h"
#include "structure.h"

struct SensorsValues sensorsValues;


void setup() {

#ifdef OUTPUT_ACTIONNER
  setupOutput();
#endif
#ifdef PRESSURE_SENSOR
  setupPressureUnit();
#endif
#ifdef TEMPERATURE_SENSOR
  setupTemperature();
#endif
#ifdef HUMIDITY_SENSOR
  setupHumidity();
#endif
#ifdef SDCARDINOUT
  setupSDCARD();
  lireText("data");
#endif
  delay(900);
  //tft.fillScreen(TFT_BACKGROUND_COLOR);
  readAndShowDatetime();
  
}

void loop() {

  readAndShowDatetime();
#ifdef PRESSURE_SENSOR
  sensorsValues.pressure = readPressure();
#endif
#ifdef TEMPERATURE_SENSOR
  sensorsValues.temperature = readTemperature();
#endif
#ifdef HUMIDITY_SENSOR
  sensorsValues.humidity = readHumidity();
#endif
#ifdef OUTPUT_ACTIONNER
  loopOutput();
#endif

char result[7];

#ifdef SDCARDINOUT
    #ifdef HUMIDITY_SENSOR
      ecrireText("data.csv",dtostrf(sensorsValues.humidity, 5, 2, result));
    #endif

    #ifdef TEMPERATURE_SENSOR
      ecrireText("data.csv",dtostrf(sensorsValues.temperature, 5, 2, result));
    #endif

    #ifdef PRESSURE_SENSOR
      ecrireText("data.csv",dtostrf(sensorsValues.pressure, 5, 2, result));
    #endif

    ecrireRetourText("data.csv");
#endif

  
  delay(1000);
}
