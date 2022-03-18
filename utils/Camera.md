# Description
La classe Camera représente la caméra de la scène. La camera a pour but d'afficher les GameObjects depuis une certaine position et d'un certain angle.

# Déclaration
Une camera peut être créé de la manière suivante:
```C++
Camera c(width, height, position);
```
le width représente la largeur de la camera, le height représente la hauteur de la camera et la position représente la position de la camera.

# Membres
| Type      | Membre        | Description                                       |
| :-------- | :------------ | :------------------------------------------------ |
| glm::vec3 | position      | Représente la position de la camera dans la scène |
| glm::mat4 | cameraMatrix  | Représente la matrice de la caméra                |
| int       | width         | Représente la largeur de la camera                |
| int       | height        | Représente la hauteur de la camera                |
| float     | speed         | Représente la vitesse de déplacement de la caméra |

# Méthodes
| Méthode                                                                                 | Description                                               |
| :-------------------------------------------------------------------------------------- | :-------------------------------------------------------- |
| [Camera](https://github.com/CGOAT24/GOAT_ENGINE/wiki/Classe-Camera#constructeur)        | Constructeur pour la classe Camera                        |
| [updateMatrix](https://github.com/CGOAT24/GOAT_ENGINE/wiki/Classe-Camera#updateMatrix)  | Sert à mettre à jour la position et l'angle de la camera  |
| [move](https://github.com/CGOAT24/GOAT_ENGINE/wiki/Classe-Camera#move)                  | Sert à déplacer la caméra                                 |

# Constructeur
## Description
Constructeur pour la classe Camera.
## Déclaration
Une variable de type Camera peut être instancié de la manière suivante:
```C++
Camera c(width, height, position);
```
## Paramètres
| Type      | Paramètre | Description                                       |
| :-------- | :-------- | :------------------------------------------------ |
| int       | width     | Représente la largeur de la camera                |
| int       | height    | Représente la hauteur de la camera                |
| glm::vec3 | position  | Représente la position de la camera dans la scène |

# updateMatrix
## Description
Sert à mettre à jour la position et la rotation de la camera.
## Déclaration
La méthode peut être déclarée de la manière suivante:
```C++
Camera c;
float fov, minDraw, maxDraw;
c.updateMatrix(fov, minDraw, maxDraw);
```
## Paramètres
| Type  | Paramètre | Description                                                                           |
| :---- | :-------- | :------------------------------------------------------------------------------------ |
| float | fov       | angle d'ouverture de la caméra                                                        |
| float | minDraw   | distance minimale entre un GameObject et la camera pour que le GameObject s'affiche   |
| float | maxdraw   | distance maximale entre un GameObject et la camera pour que le GameObject s'affiche   |

# move
## Description
Sert à déplacer la caméra dans la scène
## Déclaration
La méthode peut être déclarée de la manière suivante:
```C++
Camera c;
GLFWwindow* window;
c.move(window);
```
## Paramètres
| Type      | Paramètre | Description                       |
| :-------- | :-------- | :-------------------------------- |
GLFWwindow* | window    | La fenêtre où la caméra se trouve |