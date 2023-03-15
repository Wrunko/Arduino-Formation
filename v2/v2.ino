#define PIN_GREEN 4
#define PIN_YELLOW 5
#define PIN_RED 6
#define PIN_BUTTON 2
#define PIN_POT A0
 
void setup() {

  Serial.begin(9600);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_YELLOW, OUTPUT);
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_POT, INPUT);

}

/**
*Fonction du calcul du ratio via l'entree pot
*/

float calculRatio(uint16_t valeurPOT, float vRef = 5.0F)
{
  float ratio =(vRef/1024.0F)*(float)valeurPOT;
  return ratio;
}

// the loop function runs over and over again forever
void loop() {

  int buttonState = digitalRead(PIN_BUTTON);

  int potValue = analogRead(PIN_POT);
  Serial.println("Tension : ");
  //Serial.println(potValue);
  Serial.println(calculRatio(potValue));
  delay(1000);

}
