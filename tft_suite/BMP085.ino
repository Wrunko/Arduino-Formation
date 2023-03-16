#include <Adafruit_BMP085.h>
#include "config.h"

  #ifdef BMP180
  #include "structure.h"

  Adafruit_BMP085 bmp;

  bool setupPressureUnit() {
    return bmp.begin();
  }
  
  #ifdef BMP180
  uint16_t readPressure() {
    sensorsValues.pressure = bmp.readPressure()/100L;
    return sensorsValues.pressure;
  }
  #endif
  #ifdef BMP180_TEMPERATURE
  float readTemperature(){
    sensorsValues.temperature = bmp.readTemperature();
    return sensorsValues.temperature;
  }
  #endif

#endif