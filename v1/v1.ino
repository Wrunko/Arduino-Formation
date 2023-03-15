/**
*Fonction d'attente serie pour la saisie
*@param msTimeout ms de timeout pour l'attente
*/
void waitSerialUntilNotAvailable(uint16_t msTimeout = 15000) {
  Serial.flush();

  uint16_t compteurAttente = 0;

  while (Serial.available() == 0 /*&& compteurAttente < msTimeout*/) {

    delay(300);
    compteurAttente = compteurAttente + 300;
    // Serial.println(compteurAttente);
    if (compteurAttente > msTimeout - 300) {
      //Serial.print("fin");
      break;
    }
  }
}

/**
* Variable globale
*/
char prenom[10] = "NONAME";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print("Hello Wordl, entre on nom !\n");

  String reponseEnEntier;
  int tempsAttente = 6000;
  //char prenom[10] = "NONAME";

  waitSerialUntilNotAvailable(tempsAttente);

  if(Serial.available() > 0){

    uint8_t sizeRead = Serial.available();     
    Serial.readBytesUntil('\n', prenom, 10);
    if(sizeRead < 10 ){
      prenom[sizeRead-1] = '\0';
    }
    else{
      prenom[9] = '\0'; 
    }
  }
  else{
    Serial.println("Pas de reponse");
    Serial.println(prenom);
  }

  // while (Serial.available()) {
  //   char reponse = Serial.read();
  //   Serial.println("Caractere : ");
  //   Serial.println(reponse);
  //   reponseEnEntier.concat(reponse);
  //}
}


void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hello World");
  Serial.println(prenom);
  delay(1000);
}
