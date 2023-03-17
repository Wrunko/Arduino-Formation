
#include "config.h"

  #ifdef BMP180
  #include "structure.h"
  #include <Adafruit_BMP085.h>

  Adafruit_BMP085 bmp;

  bool setupPressureUnit() {
    return bmp.begin();
  }
  
  #ifdef BMP180
  bool readPressure() {
    sensorsValues.pressure = bmp.readPressure()/100L;
    return sensorsValues.pressure;
  }
  #endif
  #ifdef BMP180_TEMPERATURE
  void setupTemperature(){}
  float readTemperature(){
    sensorsValues.temperature = bmp.readTemperature();
    return sensorsValues.temperature;
  }
  #endif

#endif