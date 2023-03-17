#ifndef _CONFIG_H_

#define _CONFIG_H_
  /***
  DHT11
  ***/
  #define DHT11_SENSOR
  /***
  PRESSURE
  ***/
  #define BMP180
  /***
  TEMPERATURE
  ***/
  #define BMP180_TEMPERATURE
  //#define DUMMY_TEMPERATURE
  //#define DS18B20_TEMPERATURE
  //#define DHT11_TEMPERATURE
  /***
  HUMIDITY
  ***/
  #define DHT11_HUMIDITY
  /***
  OUTPUT
  ***/
  #define ST7735
  /***
  STORAGE
  ***/  
  #define SDCARDINOUT

//check config for multiple sensor type defined
  #include "config_adv.h"
#endif
