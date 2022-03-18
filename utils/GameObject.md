# Description
La classe GameObject représente un objet du jeu. 

# Déclaration
Un GameObject peut être créé de la manière suivante:
```C++
GameObject g(position, scale, rotation, texture);
```
La position représente la position du GameObject, le scale représente la taille du GameObject, la rotation représente la rotation du GameObject et la texture représente le nom de la texture du GameObject.

# Membres
| Type      | Membre    | Description                                                       |
| :-------- | :-------- | :---------------------------------------------------------------- |
| Mesh      | mesh      | Représente le mesh du GameObject                                  |
| Texture   | texture   | Représente la texture du GameObject                               |
| Shader    | shader    | Représente le shader du GameObject                                |
| Light     | light     | Représente le light du GameObject                                 |
| glm::vec3 | position  | Représente la position en x, y et z du GameObject dans la scène   |
| glm::vec3 | scale     | Représente la taille en x, y et z du GameObject dans la scène     |
| glm::vec3 | rotation  | Représente la rotation en x, y et z du GameObject dans la scène   |
| Collider  | collider  | Représente le collider du GameObject                              |

# Méthodes
| Méthode                                                                                   | Description                                           |
| :---------------------------------------------------------------------------------------- | :---------------------------------------------------- |
| [GameObject](https://github.com/CGOAT24/GOAT_ENGINE/wiki/Classe-GameObject#constructeur)  | Constructeur pour la classe GameObject                |
| [getPosition](https://github.com/CGOAT24/GOAT_ENGINE/wiki/Classe-GameObject#getPosition)  | Retourne la position du GameObject                    |
| [getScale](https://github.com/CGOAT24/GOAT_ENGINE/wiki/Classe-GameObject#getScale)        | Retourne la taille du GameObject                      |
| [getRotation](https://github.com/CGOAT24/GOAT_ENGINE/wiki/Classe-GameObject#getRotation)  | Retourne la rotation du GameObject                    |
| [render](https://github.com/CGOAT24/GOAT_ENGINE/wiki/Classe-GameObject#render)            | Sert à afficher le GameObject dans la scène           |
| [translate](https://github.com/CGOAT24/GOAT_ENGINE/wiki/Classe-GameObject#translate)      | Sert à déplacer le GameObject en x, y et z            |
| [setScale](https://github.com/CGOAT24/GOAT_ENGINE/wiki/Classe-GameObject#setScale)        | Sert à modifier la taille du GameObject en x, y et z  |
| [rotateX](https://github.com/CGOAT24/GOAT_ENGINE/wiki/Classe-GameObject#rotateX)          | Sert à faire tourner le GameObject selon l'axe des x  |
| [rotateY](https://github.com/CGOAT24/GOAT_ENGINE/wiki/Classe-GameObject#rotateY)          | Sert à faire tourner le GameObject selon l'axe des y  |
| [rotateZ](https://github.com/CGOAT24/GOAT_ENGINE/wiki/Classe-GameObject#rotateZ)          | Sert à faire tourner le GameObject selon l'axe des z  |

# Constructeur
## Description
Constructeur pour la classe GameObject.
## Déclaration
Une variable de type GameObject peut être instancié de la manière suivante:
```C++
GameObject g(position, scale, rotation, texName);
```
## Paramètres
| Type          | Paramètre | Description                                                   |
| :------------ | :-------- | :------------------------------------------------------------ |
| glm::vec2     | position  | Représente la position en x et y du GameObject dans la scène  |
| glm::vec2     | scale     | Représente la taille en x et y du GameObject dans la scène    |
| glm::vec3     | rotation  | Représente la rotation du GameObject dans la scène            |
| const char*   | texName   | Représente le nom de la texture du GameObject                 |

---
# getPosition
## Description
Accesseur pour le membre position.
## Déclaration
La méthode peut est déclaré de la manière suivante:
```C++
GameObject g;
glm::vec3 position = g.getPosition();
```
## Retour
Retourne un vecteur3 de type glm::vec3 représentant la position du GameObject dans la scène.

---
# getScale
## Description
Accesseur pour le membre scale.
## Déclaration
La méthode peut être déclaré de la manière suivante:
```C++
GameObject g;
glm::vec2 scale = g.getScale();
```
## Retour
Retourne un vecteur2 de type glm::vec2 représentant la taille en x et y du GameObject dans la scène.

---
# getRotation
## Description
Accesseur pour le membre rotation
## Déclaration
La méthode peut être déclaré de la manière suivante:
```C++
GameObject g;
glm::vec3 rotation = g.getRotation();
```
## Retour
Retourne un vecteur3 de type glm::vec3 représentant la rotation en x, y et z du GameObject dans la scène.

---
# render
## Description
Sert à afficher le GameObject dans la scène.
## Déclaration
La méthode peut être déclaré de la manière suivante:
```C++
Camera c;
GameObject g;
g.render(c);
```
## Paramètres
| Type                                                                  | Paramètre | Description                                           |
| :-------------------------------------------------------------------- | :-------- | :---------------------------------------------------- |
| [Camera](https://github.com/CGOAT24/GOAT_ENGINE/wiki/Classe-Camera)   | camera    | Représente la caméra qui va afficher le GameObject    |

---
# translate
## Description
Sert à déplacer le GameObject dans la scène.
## Déclaration
La méthode peut être déclaré de la manière suivante:
```C++
GameObject g;
glm::vec2 v;
g.translate(v);
```
## Paramètres
| Type      | Paramètre | Description                                   |
| :-------- | :-------- | :-------------------------------------------- |
| glm::vec2 | movement  | Force du déplacement du GameObject en x et y  |

---
# setScale
## Description
Sert à définir la taille en x et y du GameObject.
## Déclaration
La méthode peut être déclaré de la manière suivante:
```C++
GameObject g;
glm::vec2 scale;
g.setScale(scale);
```
## Paramètres
| Type      | Paramètre | Description                               |
| :-------- | :-------- | :---------------------------------------- |
| glm::vec2 | scale     | Nouvelle taille en x et y du GameObject   |

---
# rotateX
## Description
Sert à appliquer un rotation au GameObject selon l'axe des X.
## Déclaration
La méthode peut être déclaré de la manière suivante:
```C++
GameObject g;
float angle;
g.rotateX(angle);
```
## Paramètres
| Type  | Paramètre | Description                                       |
| :---  | :-------- | :------------------------------------------------ |
| float | angle     | Force de rotation en degrés en x du GameObject    |

---
# rotateY
## Description
Sert à appliquer une rotation au GameObject selon l'axe des y.
## Déclaration
La méthode peut être déclaré de la manière suivante:
```C++
GameObject g;
float angle;
g.rotateY(angle);
```
## Paramètres
| Type  | Paramètre | Description                                       |
| :---  | :-------- | :------------------------------------------------ |
| float | angle     | Force de rotation en degrés en y du GameObject    |

---
# rotateZ
## Description
Sert à appliquer une rotation au GameObject selon l'axe des z.
## Déclaration
```C++
GameObject g:
float angle;
g.rotateZ(angle);
```
## Paramètres
| Type  | Paramètre | Description                                       |
| :---  | :-------- | :------------------------------------------------ |
| float | angle     | Force de rotation en degrés en z du GameObject    |