#include "config.h"
#ifdef DUMMY_TEMPERATURE

#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS A0

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature tSensors(&oneWire);

  bool setupTemperatureUnit() {
    return tSensors.begin();
  }


float readTemperature(){
  
  tSensors.requestTemperatures();
  sensorsValues.temperature = sensors.getTempCByIndex(0);
  return sensorsValues.temperature;

}
#endif