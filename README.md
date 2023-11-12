# Tourelle Arduino avec Accéléromètre

Ce projet consiste en une tourelle contrôlée par deux servomoteurs en fonction de la position de la main détectée par un accéléromètre MPU6050. La tourelle s'ajuste verticalement et horizontalement pour pointer vers la direction de la main.

## Auteur
- Côme Cervantes

## Matériel nécessaire
- Arduino (compatible avec le code)
- Accéléromètre MPU6050
- Deux servomoteurs
- Fils de connexion
- ...

## Dépendances
- [Adafruit MPU6050 Library](https://github.com/adafruit/Adafruit_MPU6050)
- [Adafruit Sensor Library](https://github.com/adafruit/Adafruit_Sensor)
- ...

## Configuration matérielle
1. Connectez l'accéléromètre MPU6050 aux broches appropriées sur votre Arduino.
2. Connectez les servomoteurs aux broches appropriées sur votre Arduino.
3. Assurez-vous que toutes les dépendances sont installées.

   Broches :
   
   ° servobas = D3
   ° servohaut = D9
   
   ° MPU6050 SDA = A4
   ° MPU6050 SCL = A5


## Installation du code
1. Clonez ce dépôt sur votre ordinateur.
2. Ouvrez le fichier Arduino (.ino) dans l'IDE Arduino.
3. Téléversez le code sur votre carte Arduino.

## Utilisation
1. Alimentez votre Arduino.
2. La tourelle s'ajustera automatiquement en fonction de la position de votre main détectée par l'accéléromètre.

Rappelons que le MPU6050 est orienté de cette manière ; il faudra donc incliner le poignet vers l'avant pour monter le bras et de gauche à droite pour tourner.
![i](https://proteshea.com/wp-content/uploads/2019/07/MPU6050-Axes-1024x683.jpg)

## Contributions
Les contributions sont les bienvenues! Si vous souhaitez améliorer ce projet, n'hésitez pas à créer une pull request.
