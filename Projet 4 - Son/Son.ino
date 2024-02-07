// Côme Cervantes 12/11/2023 ᕕ( ᐛ )ᕗ

// Déclaration des constantes et des variables
const int fenetreEchantillon = 50; // Durée de l'échantillonnage en millisecondes
unsigned int echantillon; // Variable pour stocker la valeur de l'échantillon
int db = 30; // Niveau sonore initial

// Définition des broches pour le capteur et les registres à décalage
#define PIN_CAPTEUR A7
#define nb_74hc595s 1
#define nbPinsRegistre nb_74hc595s * 8
#define PIN_SER 2
#define PIN_RCLK 3
#define PIN_SRCLK 4

// Définition des seuils pour le mapping
#define MIN 20
#define MAX 70
#define CTR 50

// Initialisation des registres à décalage
boolean registres[nbPinsRegistre] = {0, 0, 0};

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
  // Début de l'échantillonnage
  unsigned long debutMillis = millis();
  float crete = 0;
  unsigned int signalMax = 0;
  unsigned int signalMin = 1024;

  // Boucle pour effectuer l'échantillonnage pendant la durée spécifiée
  while (millis() - debutMillis < fenetreEchantillon)
  {
    echantillon = analogRead(PIN_CAPTEUR); // Lecture de la valeur du capteur
    if (echantillon < 1024)
    {
      if (echantillon > signalMax)
      {
        signalMax = echantillon;
      }
      else if (echantillon < signalMin)
      {
        signalMin = echantillon;
      }
    }
  }

  // Calcul de la crête
  crete = signalMax - signalMin;

  // Mapping du niveau sonore en fonction de la crête
  if(db < CTR){
    db = map(crete, 20, 900, 20, 80);
  }
  if(db >= CTR){
    db = map(crete, 20, 900, 30, 120);
  }

  // Affichage du niveau sonore
  Serial.println(db);

  // Conversion du niveau sonore en nombre de LEDs allumées
  int nbLeds = map(db, MIN, MAX, 0, 8);

  // Réinitialisation des registres à décalage
  for (int i = 0; i < 8; i++)
  {
    definirPinRegistre(i, LOW);
    ecrireRegistres();
  }

  // Allumage des LEDs correspondant au niveau sonore
  for (int i = 0; i < nbLeds; i++)
  {
    definirPinRegistre(i, HIGH);
    ecrireRegistres();
  }

  delay(100); // Délai pour limiter la fréquence de mise à jour des LEDs
}
