// Côme Cervantes 12/11/2023 ᕕ( ᐛ )ᕗ

// Inclusion des bibliothèques nécessaires
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <Servo.h>

// Déclaration des objets Servo et MPU6050
Servo servobas;    // Servomoteur pour le mouvement vertical
Servo servohaut;   // Servomoteur pour le mouvement horizontal
Adafruit_MPU6050 srituhobby;  // Capteur MPU6050

// Configuration initiale
void setup(void) {
  Serial.begin(115200);
  
  // Attribution des broches aux servomoteurs
  servobas.attach(3);
  servohaut.attach(9);
  
  // Initialisation de la communication I2C
  Wire.begin();
  srituhobby.begin();
  
  // Position initiale des servomoteurs
  servobas.write(0);
  servohaut.write(0);

  // Configuration du capteur MPU6050
  srituhobby.setAccelerometerRange(MPU6050_RANGE_8_G);
  srituhobby.setGyroRange(MPU6050_RANGE_500_DEG);
  srituhobby.setFilterBandwidth(MPU6050_BAND_21_HZ);

  delay(100);
}

// Boucle principale
void loop() {
  // Lecture des données du capteur MPU6050
  sensors_event_t a, g, temp;
  srituhobby.getEvent(&a, &g, &temp);

  // Récupération des valeurs d'accélération en X et Y
  int value1 = a.acceleration.x;
  int value2 = a.acceleration.y;

  // Mappage des valeurs d'accélération aux angles des servomoteurs
  value1 = map(value1, -10, 10, 180, 0);
  value2 = map(value2, -10, 10, 180, 0);

  // Déplacement des servomoteurs en fonction des valeurs d'accélération
  servobas.write(value2);
  servohaut.write(value1);

  // Affichage des valeurs dans le moniteur série
  Serial.print(value1);
  Serial.print("  ");
  Serial.println(value2);

  // Pause pour éviter une lecture trop rapide
  delay(10);
}
