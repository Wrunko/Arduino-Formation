#ifndef _CONFIG_AVD_H_
  #define _CONFIG_AVD_H_

  #if defined(BMP180_TEMPERATURE) && !defined(BMP180)
    #undef BMP180_TEMPERATURE
    #define DUMMY_TEMPERATURE
  #endif


  #if defined(BMP180_TEMPERATURE) && defined(DUMMY_TEMPERATURE)
    #undef DUMMY_TEMPERATURE
    #define BMP180_TEMPERATURE
  #endif


  #if defined(BMP180_TEMPERATURE) || defined(DUMMY_TEMPERATURE)
    #define TEMPERATURE_SENSOR
  #endif
  #if defined(BMP180)
    #define PRESSURE_SENSOR
  #endif

  #if defined(ST7735)
    #define OUTPUT_ACTIONNER
  #endif


#endif