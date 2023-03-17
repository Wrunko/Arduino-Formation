#include "config.h"
#ifdef DUMMY_TEMPERATURE
//dummy start for others components libs complients
void setupTemperature(){}
float readTemperature() {
  sensorsValues.temperature = 0.0F;
  return sensorsValues.temperature;
}
#endif