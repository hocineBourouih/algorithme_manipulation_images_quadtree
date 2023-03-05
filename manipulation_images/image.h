#ifndef __IMAGE__H__
#define __IMAGE__H__


struct triplet_s{
  int x;
  int y;
  int z;
};
typedef struct triplet_s triplet_t;
typedef triplet_t ** image_t;


/**
   Fonction d'initialisation d'un triplet 
   Complexité temps et espace: 0(1)
   @param x première valeur du triplet
   @param y deuxième valeur du triplet
   @param y troisième valeur du triplet
   @return un triplet (x,y,z)
 */
triplet_t creer_triplet(int x, int y, int z);

/**
   Procédure d'affichage d'un triplet.
   Complexité temps et espace: 0(1)
   @param t triplet à afficher.
 */
void afficher_triplet(triplet_t t);

/**
   Fonction qui compare deux triplet t1 et t2 selon la définition fournie dans la première
   partie du sujet.
   Complexité temps et espace: 0(1)
   @param t1 premier triplet
   @param t2 deuxième triplet
   @return une valeur négative si t1<t2, positive si t2<t1 et 0 si t1=t2
 */
int cmp_triplet(triplet_t t1, triplet_t t2);

/**
   Procédure permettant de colorier une zone carrée d'une image en une couleur donnée
   Complexité en temps: O(largeur^2)
   Complexité en espace: O(1)
   @param image est l'image à colorier
   @param x est la l'abcisse du point en haut à gauche de la zone à colorier
   @param y est la l'ordonnée du point en haut à gauche de la zone à colorier
   @param largeur est la largeur de la zone à colorier.
   @param couleur est la couleur dans laquelle on veut colorier la zone.
 */
void remplir_zone(image_t image, int x, int y, int largeur, triplet_t couleur);

/**
   Procédure permettant de tester si une zone est composée d'une unique couleur.
   Complexité en temps: O(largeur^2)
   Complexité en espace: O(1)
   @param image est l'image à colorier
   @param x est la l'abcisse du point en haut à gauche de la zone à tester
   @param y est la l'ordonnée du point en haut à gauche de la zone à tester
   @param largeur est la largeur de la zone à tester.
   @return 1 si la zone est composée d'une unique couleur et 0 sinon.
 */
int tester_zone(image_t image, int x, int y, int largeur);

/**
   Fonction qui alloue l'espace mémoire nécesaire pour manipuler une image largeurxlargeur.
   Complexité en temps: O(largeur)
   Complexité en espace: O(largeur^2)
   @param largeur est la largeur du coté de l'image carrée.
   @return une image carré (double pointeur sur un triplet) non initialisée.
*/
image_t creer_image_carre(int largeur);

/**
   Fonction qui libère l'espace mémoire utilisée par une image.
   Complexité en temps: O(largeur)
   Complexité en espace: O(1)
   @param image est l'image que l'on souhaite détruire.
   @param largeur est la largeur du coté de l'image carrée.
*/
void liberer_image(image_t image, int largeur);

/**
   Fonction prennant en entrée un tableau 16x16 de pixel et le remplit pour obtenir
   la Figure 1 du sujet du devoir.
   Complexité en temps et espace: O(1)
   @param image est l'image que l'on souhaite remplir.
 */
image_t  image_figure();



void afficher_pixel_blanc();

void afficher_pixel_vert();

void afficher_pixel_bleu();

void afficher_pixel_jaune();

void afficher_image(triplet_t ** image, int largeur);

#endif