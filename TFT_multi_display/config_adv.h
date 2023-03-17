#ifndef _CONFIG_AVD_H_
  #define _CONFIG_AVD_H_

  #if defined(BMP180_TEMPERATURE) && !defined(BMP180)
    #undef BMP180_TEMPERATURE
    #define DUMMY_TEMPERATURE
  #endif

//protection multiples sonde de temperatures defined
  #if (defined(BMP180_TEMPERATURE) && defined(DUMMY_TEMPERATURE))|| (defined(DS18B20_TEMPERATURE)&&defined(BMP180_TEMPERATURE))||(defined(DS18B20_TEMPERATURE)&&defined(DUMMY_TEMPERATURE))
    #undef DUMMY_TEMPERATURE
    #undef BMP180_TEMPERATURE
  #endif


  #if defined(BMP180_TEMPERATURE) || defined(DUMMY_TEMPERATURE)|| defined(DS18B20_TEMPERATURE)
    #define TEMPERATURE_SENSOR
  #endif

  #if defined(BMP180)
    #define PRESSURE_SENSOR
  #endif

  #if defined(ST7735)
    #define OUTPUT_ACTIONNER
  #endif

  #if defined(DHT11_SENSOR)

    #define DHT11_SENSOR
    
    #if defined(DHT11_HUMIDITY)
      #define HUMIDITY_SENSOR
    #endif

    #if defined(DHT11_TEMPERATURE)
      #define TEMPERATURE_SENSOR
    #endif

  #endif

  #if defined(SDCARDINOUT)
    #define SDCARDINOUT
  #endif

#endif