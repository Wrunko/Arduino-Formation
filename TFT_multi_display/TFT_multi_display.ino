#include <DS1307RTC.h>
#include <Timelib.h>
#include "config.h"
#include "structure.h"

struct SensorsValues sensorsValues;

#define INTERRUPT_PIN_2 2
#define INTERRUPTION_LED 4

// void actionInterruption(){
//   digitalWrite(INTERRUPTION_LED, ! digitalRead(INTERRUPTION_LED));
//   while (digitalRead(INTERRUPT_PIN_2) == LOW) {
//   }
// }

volatile bool runloop = true;

void actionInterruption() {
  runloop = !runloop;
}

void setup() {

  pinMode(INTERRUPTION_LED, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN_2), actionInterruption, RISING);

#ifdef OUTPUT_ACTIONNER
  setupOutput();
#endif
#ifdef PRESSURE_SENSOR
  setupPressureUnit();
#endif
#ifdef TEMPERATURE_SENSOR
  setupTemperature();
#endif
#ifdef HUMIDITY_SENSOR
  setupHumidity();
#endif
#ifdef SDCARDINOUT
  setupSDCARD();
  lireText("data");
#endif
  delay(900);
  //tft.fillScreen(TFT_BACKGROUND_COLOR);
  readAndShowDatetime();
}

void loop() {
  if (runloop) {
    digitalWrite(INTERRUPTION_LED, HIGH);
    readAndShowDatetime();
#ifdef PRESSURE_SENSOR
    sensorsValues.pressure = readPressure();
#endif
#ifdef TEMPERATURE_SENSOR
    sensorsValues.temperature = readTemperature();
#endif
#ifdef HUMIDITY_SENSOR
    sensorsValues.humidity = readHumidity();
#endif
#ifdef OUTPUT_ACTIONNER
    loopOutput();
#endif

    char result[7];

#ifdef SDCARDINOUT
#ifdef HUMIDITY_SENSOR
    ecrireText("data.csv", dtostrf(sensorsValues.humidity, 5, 2, result));
#endif

#ifdef TEMPERATURE_SENSOR
    ecrireText("data.csv", dtostrf(sensorsValues.temperature, 5, 2, result));
#endif

#ifdef PRESSURE_SENSOR
    ecrireText("data.csv", dtostrf(sensorsValues.pressure, 5, 2, result));
#endif

    ecrireRetourText("data.csv");
#endif
  }else
  {
    digitalWrite(INTERRUPTION_LED, LOW);
  }

  delay(1000);
}
