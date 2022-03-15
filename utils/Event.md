# Description
Cette classe sert à gérer les touches du clavier et de la souris.
# Déclaration
Un Event peut être créé de la manière suivante:
```C++
Event e(window);
```
Une fois l'Event créé on peut faire un listener à l'aide d'un lambda où on spécifie la touche à attendre:
```C++
e.onPress(KEY, []() {
    //Faire quelquechose...
});
```
Pour inclure un GameObject dans le listener, il faut le spécifier de la manière suivante:
```C++
GameObject g;
e.onPress(KEY, g, [](GameObject g1){
    //Faire quelquechose...
});
```
# Membres
| Type          | Membre    | Description                   |
| :------------ | :-------- | :---------------------------- |
| GLFWwindow*   | win       | Spéficie la fenêtre à écouter |

# Méthodes
| Méthode               | Description                                   |
| :-------------------- | :-------------------------------------------- |
| [Event]()             | Constructeur pour la classe Event             |
| [onPress]()           | listener pour une touche du clavier           |
| [onRepeat]()          | Listener pour une touche répétée du clavier   |
| [onRelease]()         | Listener pour une touche relachée du clavier  |
| [onMouseClick]()      | Listener pour un clique de la souris          |
| [getMousePosition]()  | Retourne la position de la souris             |

# Constructeur
## Description
Constructeur pour la classe Event
## Déclaration
Un Event peut être créé de la manière suivante:
```C++
Event e(GLFWwindow*);
```
## Paramètres
| Type          | Paramètre | Description                                       |
| :------------ | :-------- | :------------------------------------------------ |
| GLFWwindow*   | window    | Représente la fenêtre où le listener va attendre  |

# onPress
## Description
Exécute une fonction lorsque une touche du clavier est appuyée.
## Déclaration
La méthode onPress peut être déclaré de 4 manières différentes:
1. On spécifie la touche à attendre ainsi que la fonction a exécuter:
```C++
Event e(window);
e.onPress(GLFW_KEY_A, &func);
```
Ici, lorsque l'utilisateur appuie sur la touche `A` du clavier, la fonction `func` va s'exécuter.
2. On spécifie la touche à attendre et on créé la fonction à exécuter en lambda:
```C++
Event e(window);
e.onPress(GLFW_KEY_A, [](){
    //Faire quelquechose...
});
```
Lorsque l'utilisateur appuie sur la touche `A` le code écrit dans le corps lambda va s'exécuter.
3. On spécifie la touche à attendre, le GameObject à inclure et une fonction ayant un GameObject en paramètre:
```C++
GameObject g;
Event e(window);
e.onPress(GLFW_KEY_A, g, &func);
```
Ici, lorsque l'utilisateur appuie sur la touche `A`, la fonction s'exécute en passant le GameObject g en paramètre.
4. On spéficie la touche à attendre, le GameObject à inclure et on crée la fonction à exécuter en lambda:
```C++
GameObject g;
Event e(window);
e.onPress(GLFW_KEY_A, g, [](GameObject& gameobject){
    //Faire quelquechose...
});
```
## Paramètres
La fonction onPress accepte 2 ensembles de paramètres différents:
#### 1.
| Type | Paramètre | Description |
| :--- | :--- | :--- |
| int  | key | Touche du clavier à écouter |
| void | func | fonction à exécuter |

#### 2.
| Type | Paramètre | Description |
| :--- | :--- | :--- |
| int | key | Touche du clavier à exécuter |
| GameObject | g | GameObject à inclure dans la fonction |
| void | func | fonction à exécuter |

# onRepeat
## Description
Exécute une fonction lorsque une touche du clavier est appuyée de manière répétée.
## Déclaration
La méthode onRepeat peut être déclaré de 4 manières différentes:
1. On spécifie la touche répétée à attendre ainsi que la fonction a exécuter:
```C++
Event e(window);
e.onRepeat(GLFW_KEY_A, &func);
```
Ici, lorsque l'utilisateur appuie sur la touche `A` du clavier de manière répétée, la fonction `func` va s'exécuter.
2. On spécifie la touche répétée à attendre et on créé la fonction à exécuter en lambda:
```C++
Event e(window);
e.onRepeat(GLFW_KEY_A, [](){
    //Faire quelquechose...
});
```
Lorsque l'utilisateur appuie sur la touche `A` de manière répétée, le code écrit dans le corps lambda va s'exécuter.
3. On spécifie la touche répétée à attendre, le GameObject à inclure et une fonction ayant un GameObject en paramètre:
```C++
GameObject g;
Event e(window);
e.onRepeat(GLFW_KEY_A, g, &func);
```
Ici, lorsque l'utilisateur appuie sur la touche `A` de manière répétée, la fonction s'exécute en passant le GameObject g en paramètre.
4. On spéficie la touche répétée à attendre, le GameObject à inclure et on crée la fonction à exécuter en lambda:
```C++
GameObject g;
Event e(window);
e.onRepeat(GLFW_KEY_A, g, [](GameObject& gameobject){
    //Faire quelquechose...
});
```
## Paramètres
La fonction onRepeat accepte 2 ensembles de paramètres différents:
#### 1.
| Type | Paramètre | Description |
| :--- | :--- | :--- |
| int  | key | Touche du clavier à écouter |
| void | func | fonction à exécuter |

#### 2.
| Type | Paramètre | Description |
| :--- | :--- | :--- |
| int | key | Touche du clavier à exécuter |
| GameObject | g | GameObject à inclure dans la fonction |
| void | func | fonction à exécuter |

# onRelease
## Description
Exécute une fonction lorsque une touche est relachée. 
## Déclaration
La méthode onRelease peut être déclaré de 4 manières différentes:
1. On spécifie la touche à attendre ainsi que la fonction a exécuter:
```C++
Event e(window);
e.onRelease(GLFW_KEY_A, &func);
```
Ici, lorsque l'utilisateur relâche la touche `A` du clavier, la fonction `func` va s'exécuter.
2. On spécifie la touche à attendre et on créé la fonction à exécuter en lambda:
```C++
Event e(window);
e.onRelease(GLFW_KEY_A, [](){
    //Faire quelquechose...
});
```
Lorsque l'utilisateur relâche la touche `A` le code écrit dans le corps lambda va s'exécuter.
3. On spécifie la touche à attendre, le GameObject à inclure et une fonction ayant un GameObject en paramètre:
```C++
GameObject g;
Event e(window);
e.¸onRelease(GLFW_KEY_A, g, &func);
```
Ici, lorsque l'utilisateur relâche la touche `A`, la fonction s'exécute en passant le GameObject g en paramètre.
4. On spéficie la touche à attendre, le GameObject à inclure et on crée la fonction à exécuter en lambda:
```C++
GameObject g;
Event e(window);
e.onRelease(GLFW_KEY_A, g, [](GameObject& gameobject){
    //Faire quelquechose...
});
```
## Paramètres
La fonction onRelease accepte 2 ensembles de paramètres différents:
#### 1.
| Type | Paramètre | Description |
| :--- | :--- | :--- |
| int  | key | Touche du clavier à écouter |
| void | func | fonction à exécuter |

#### 2.
| Type | Paramètre | Description |
| :--- | :--- | :--- |
| int | key | Touche du clavier à exécuter |
| GameObject | g | GameObject à inclure dans la fonction |
| void | func | fonction à exécuter |

# getMousePosition
## Description
Sert à obtenir la position de la souris en x et en y 
## Déclaration
La méthode est déclarée de la manière suivante:
```C++
Event e(window);
glm::vec2 position = e.getMousePosition();
```
## Retour
La méthode retourne une variable de type glm::vec2 représentant la position de la souris en x et en y.

# onMouseClick
## Description
Exécute une fonction lorsque une touche du clavier est appuyée.
## Déclaration
La méthode peut être déclarée de 4 manières différentes:
1. On spécifie la touche à attendre ainsi que la fonction a exécuter:
```C++
Event e(window);
e.onMouseClick(GLFW_MOUSE_BUTTON_LEFT, &func);
```
Ici, lorsque l'utilisateur appuie sur le clic gauche de la souris, la fonction `func` va s'exécuter.
2. On spécifie la touche à attendre et on créé la fonction à exécuter en lambda:
```C++
Event e(window);
e.onMouseClick(GLFW_MOUSE_BUTTON_RIGHT, [](){
    //Faire quelquechose...
});
```
Lorsque l'utilisateur appuie sur le clic droit de la souris, le code écrit dans le corps lambda va s'exécuter.
3. On spécifie la touche à attendre, le GameObject à inclure et une fonction ayant un GameObject en paramètre:
```C++
GameObject g;
Event e(window);
e.onMouseClick(GLFW_MOUSE_BUTTON_LEFT, g, &func);
```
Ici, lorsque l'utilisateur appuise sur le clic gauche de la souris, la fonction s'exécute en passant le GameObject g en paramètre.
4. On spéficie la touche à attendre, le GameObject à inclure et on crée la fonction à exécuter en lambda:
```C++
GameObject g;
Event e(window);
e.onMouseClick(GLFW_MOUSE_BUTTON_LEFT, g, [](GameObject& gameobject){
    //Faire quelquechose...
});
```
## Paramètres
La fonction onMouseClick accepte 2 ensembles de paramètres différents:
#### 1.
| Type | Paramètre | Description |
| :--- | :--- | :--- |
| int  | key | Touche de la souris à écouter |
| void | func | fonction à exécuter |

#### 2.
| Type | Paramètre | Description |
| :--- | :--- | :--- |
| int | key | Touche de la souris à écouter |
| GameObject | g | GameObject à inclure dans la fonction |
| void | func | fonction à exécuter |