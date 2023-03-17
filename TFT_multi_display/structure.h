#ifndef _STRUCTURE_H_
#define _STRUCTURE_H_
  #include "config.h"
  #include "config_adv.h"
  struct SensorsValues{
    #ifdef PRESSURE_SENSOR
    uint16_t pressure;
    #endif
    #ifdef TEMPERATURE_SENSOR
    float temperature;
    #endif
    #ifdef HUMIDITY_SENSOR
    uint8_t humidity;
    #endif
  };
#endif
