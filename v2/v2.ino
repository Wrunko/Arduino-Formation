#define PIN_GREEN 4
#define PIN_YELLOW 5
#define PIN_RED 6
#define PIN_BUTTON 2
#define PIN_POT A0

/**
*Temps min d'allumage feux pieton
*/
#define TEMP_MIN 2000

/**
*Temps MAX d'allumage feux pieton
*/
#define TEMP_MAX 2000
 
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

  if (buttonState>0) {
   
    Serial.println("Activated");
    
    int potValue= analogRead(PIN_POT);
    float timeToWaitOnRed = map(potValue, 0, 1023, TEMP_MIN, TEMP_MAX);
    Serial.println(potValue);


    digitalWrite(PIN_GREEN, HIGH);
    delay(1000);

    digitalWrite(PIN_YELLOW, HIGH);
    digitalWrite(PIN_GREEN, LOW);
    delay(1000);

    digitalWrite(PIN_RED, HIGH);
    digitalWrite(PIN_YELLOW, LOW);

    Serial.println("Temps attente :");
    
    Serial.println(timeToWaitOnRed);
    delay(timeToWaitOnRed);
    
    digitalWrite(PIN_RED, LOW);
  } else {
    Serial.println("Not activated");
  }

  
  //Serial.println("Tension : ");
  //Serial.println(potValue);
  //Serial.println(calculRatio(potValue));
  delay(1000);



}
