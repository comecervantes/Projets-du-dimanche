// Déclaration des broches pour le capteur et les registres à décalage
#define PIN_CAPTEUR A7
#define nb_74hc595s 1
#define nbPinsRegistre nb_74hc595s * 8
#define PIN_SER 2
#define PIN_RCLK 3
#define PIN_SRCLK 4

// Initialisation des registres à décalage
boolean registres[nbPinsRegistre] = {0, 0, 0};

int nbLeds; // Variable pour stocker le nombre de LEDs à allumer

// Configuration initiale des broches
void setup()
{
  pinMode(PIN_CAPTEUR, INPUT);
  pinMode(PIN_SER, OUTPUT);
  pinMode(PIN_RCLK, OUTPUT);
  pinMode(PIN_SRCLK, OUTPUT);
  Serial.begin(9600); // Initialisation de la communication série
}

// Fonction pour vider les registres à décalage
void viderRegistres()
{
  for (int i = nbPinsRegistre - 1; i >= 0; i--)
  {
    registres[i] = LOW;
  }
}

// Fonction pour écrire dans les registres à décalage
void ecrireRegistres()
{
  digitalWrite(PIN_RCLK, LOW);
  for (int i = nbPinsRegistre - 1; i >= 0; i--)
  {
    digitalWrite(PIN_SRCLK, LOW);
    int val = registres[i];
    digitalWrite(PIN_SER, val);
    digitalWrite(PIN_SRCLK, HIGH);
  }
  digitalWrite(PIN_RCLK, HIGH);
}

// Fonction pour définir l'état d'un pin dans les registres à décalage
void definirPinRegistre(int index, int valeur)
{
  registres[index] = valeur;
}

void loop()
{
  // Lecture de la valeur du capteur et affichage
  Serial.print(analogRead(PIN_CAPTEUR));
  Serial.print(",");

  // Mapping de la valeur du capteur au nombre de LEDs à allumer
  nbLeds = map(analogRead(PIN_CAPTEUR), 0, 1023, 0, 8);
  Serial.println(nbLeds); // Affichage du nombre de LEDs à allumer

  // Réinitialisation des registres à décalage
  for (int i = 0; i < 8; i++)
  {
    definirPinRegistre(i, LOW);
    ecrireRegistres();
  }

  // Allumage des LEDs correspondant au nombre calculé
  for (int i = 0; i < nbLeds; i++)
  {
    definirPinRegistre(i, HIGH);
    ecrireRegistres();
  }

  delay(100); // Délai pour limiter la fréquence de mise à jour des LEDs
}
