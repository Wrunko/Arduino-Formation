#ifndef _STRUCTURE_H_
#define _STRUCTURE_H_

#include "config.h"

struct SensorsValues {

  #ifdef PRESSURE_SENSOR
    uint16_t pressure;
  #endif

  #ifdef TEMPERATURE_SENSOR
    float temperature;
  #endif
};

#endif
