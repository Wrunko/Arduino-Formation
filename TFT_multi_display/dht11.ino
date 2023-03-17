#include "config.h"

#ifdef DHT11_SENSOR

#include "DHT.h"
#include "structure.h"

#define DHTPIN 5
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
  
  #ifdef DHT11_HUMIDITY
    // Pass our oneWire reference to Dallas Temperature.
    void setupHumidity() {
    dht.begin();
    }
    float readHumidity() {
    return dht.readHumidity();
    }
  #endif

  #ifdef DHT11_TEMPERATURE
    // Pass our oneWire reference to Dallas Temperature.

    float readTemperature() {
    return dht.readTemperature();
    }
  #endif

#endif