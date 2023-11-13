# 🚀 Projets du Dimanche


## 👨‍🚀 Auteur
- [Côme Cervantes](https://www.linkedin.com/in/côme-cervantes)

## À propos de ce projet

Bienvenue sur mon espace dédié à l'ingénierie créative ! Je suis passionné par l'électronique, la mécanique et tout ce qui touche au vaste domaine de l'ingénierie. Sur cette page Git, je partage mes petites aventures hebdomadaires à travers des projets divers et variés, tous liés à l'univers de la conception et de la réalisation.

## Ce que vous trouverez ici

🔍 **Exploration hebdomadaire :** Chaque semaine, je me lance dans un nouveau projet, explorant les frontières de l'électronique, de la mécanique et d'autres domaines connexes. Vous pourrez suivre l'évolution de mes idées, de la conception à la réalisation.

🛠️ **Conception collaborative :** L'ingénierie est une discipline collaborative. J'encourage la participation, les commentaires et les idées. N'hésitez pas à partager vos réflexions, suggestions ou même à contribuer directement aux projets en cours.

📚 **Apprentissage continu :** Chaque projet est une occasion d'apprendre quelque chose de nouveau. Vous trouverez des ressources, des tutoriels et des retours d'expérience qui pourront vous être utiles dans vos propres projets.

## 📖 Table des matières
- [Projet 1 - Tourelle contrôlée par un accéléromètre](#projet-1---tourelle-contrôlée-par-un-accéléromètre)

## 🤝 Contributions
Les contributions sont les bienvenues! Si vous souhaitez améliorer ce projet, n'hésitez pas à créer une pull request.
Si vous avez des questions ou des remarques c'est avec plaisir que je vous répondrai.

# Projet 1 - Tourelle contrôlée par un accéléromètre
Ce projet consiste en une tourelle contrôlée par deux servomoteurs en fonction de la position de la main détectée par un accéléromètre MPU6050. La tourelle s'ajuste verticalement et horizontalement pour pointer vers la direction de la main.

Le but ici était de se familiariser avec l'utilisation de l'accéléromètre et de l'intégrer dans un projet, pour rendre cela plus visuel j'ai décidé de faire une tourelle avec deux servomoteurs.

### Matériel nécessaire
- Arduino (compatible avec le code)
- Accéléromètre MPU6050
- Deux servomoteurs
- Fils de connexion
- Breadboard

### Dépendances
- [Adafruit MPU6050 Library](https://github.com/adafruit/Adafruit_MPU6050)
- [Adafruit Sensor Library](https://github.com/adafruit/Adafruit_Sensor)

### Configuration matérielle
1. Connectez l'accéléromètre MPU6050 aux broches appropriées sur votre Arduino.
2. Connectez les servomoteurs aux broches appropriées sur votre Arduino.
3. Assurez-vous que toutes les dépendances sont installées.


   **Broches :**

   
    servobas = D3
    servohaut = D9
    MPU6050 SDA = A4
    MPU6050 SCL = A5


### Installation du code
1. Clonez ce [dépôt](Tourelle) sur votre ordinateur.
2. Ouvrez le fichier Arduino (.ino) dans l'IDE Arduino.
3. Téléversez le code sur votre carte Arduino.

### Utilisation
1. Alimentez votre Arduino.
2. La tourelle s'ajustera automatiquement en fonction de la position de votre main détectée par l'accéléromètre.

Rappelons que le MPU6050 est orienté de cette manière ; il faudra donc incliner le poignet vers l'avant pour monter le bras et de gauche à droite pour tourner.

![i](https://proteshea.com/wp-content/uploads/2019/07/MPU6050-Axes-1024x683.jpg)
![i](./files/poignet.png)
On peut facilement imaginer de faire un gant sur lequel on fixerait l'accéléromètre pour avoir une meilleure précision.

Ici en fonction de la rotation en X et en Y du capteur nos deux servomoteurs vont s'ajuster pour pointer vers la direction de la main. Dans une version future, il serait bien que l'axe Z soit utilisé pour rendre le mouvement plus simple. 

A noter que lors du développement du capteur, j'ai remarqué dans la datasheet du MPU6050 que le composant possède un thermomètre intégré dont je questionne l'utilité. 