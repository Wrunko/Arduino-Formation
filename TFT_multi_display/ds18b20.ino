#ifdef DS18B20_TEMPERATURE
// Include the libraries we need
#include <OneWire.h>
#include <DallasTemperature.h>
#include "config.h"

// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 6

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);
void setupTemperature() {
  sensors.begin();
}
float readTemperature() {
  sensors.requestTemperatures();
  sensorsValues.temperature = sensors.getTempCByIndex(0);
  return sensorsValues.temperature;
}
#endif