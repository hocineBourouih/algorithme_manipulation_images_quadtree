# algorithme_manipulation_images_quadtree
Algorithme utilisant les quadtrees pour manipuler des images (En C)

- Ce projet est réalisé dans le cadre d'un cours d'algorithme en L2 Informatique.

- L'objectif principal de ce projet est de manipuler des image en implémentant une structure de données arborescente "Quadtree",
en mettant en pratique les arbres binaire plus précisément les AQR (arbre binaire de recherche), les concepts de pointeur, liberer la mémoir
(vu l'absence du collecte garbage en C) et le traitement d'image.

- Le code est implémenté en langage C.

* Présentation du projet
- Le projet est constitué :

  - image.h : ce fichier contient les définitions des types de données utilisés, les prototypes des fonctions qui sont utilisées pour manipuler les images
  - image.c : contient les implémentations des fonctions pour manipuler les images
  - quadtree.h : ce fichier contient les définitions des types de données utilisés dans le projet, ainsi que les prototypes 
des fonctions qui sont utilisées pour manipuler les quadtrees
  - quadtree.c : ce fichier contient les implémentations des fonctions pour manipuler les quadtrees
  - main.c : contient le code principal qui utilise les fonctions implémentées pour créer une image, 
la transformer en quadtree, la modifier et l'afficher dans un terminal.

* Utilité du projet :
  - Le projet consiste à manipuler des images en utilisant la structure algorithmique quadtree. 
  - L'algorithme quadtree divise une image en plusieurs zones carrées qui peuvent être facilement manipulées. 
En utilisant cette technique, il est possible de compresser des images,
de modifier leur taille ou leur résolution, de réaliser des filtres et de manipuler des images de manière efficace et rapide.

* points techniques :
  - La structure quadtree est une structure de données arborescente qui divise une image en plusieurs zones 
carrées de tailles différentes. Chaque nœud de l'arbre représente une zone carrée de l'image et chaque feuille 
représente une zone d'une seule et même couleur. Les trois entiers stockés dans la feuille représentent simplement 
les niveaux rouge/vert/bleu de la couleur de cette zone.
  - Pour manipuler les images, on utilise les pixels qui sont des triplets d'entiers représentant les niveaux rouge/vert/bleu de chaque point de l'image.

* comilation et execution : 
  - J'ai ajouté un fichier exécutable appelé 'program.exe'. 
Vous pouvez l'exécuter directement pour voir le résultat du code, ou bien compiler et créer un autre fichier exécutable.

* Amélioration et visibilité : 
  - J'ai ajouté deux images que vous pouvez consulter. L'une représente l'image obtenue, et l'autre représente le quad tree obtenu à partir de cette image. Il est difficile de comprendre l'affichage sur un terminal.
