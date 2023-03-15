#define PIN_MESURE_TENSION A0
#define R1 2000
#define R2 560

float calculVin(float tensionVOUT){

  float tensionVIN;

  tensionVOUT = 5.0F/1024.0F*tensionVOUT;
  tensionVIN = tensionVOUT*((R1+R2)/R2);

  return tensionVIN;

}

void setup() {

  Serial.begin(9600);
  pinMode(PIN_MESURE_TENSION, INPUT);

}

void loop() {

  uint16_t mesureAnalogique = analogRead(PIN_MESURE_TENSION);
  Serial.println(calculVin(mesureAnalogique));
  delay(1000);
}
