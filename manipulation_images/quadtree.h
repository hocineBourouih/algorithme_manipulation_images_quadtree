#ifndef __QUADTREE__H__
#define __QUADTREE__H__
#include"image.h"


struct quadNode_s{
  triplet_t triplet;
  struct quadNode_s* enfants[4];
};
typedef struct quadNode_s* quadTree;



/**
   Fonction qui alloue l'espace mémoire pour stocker un quadNoeud et l'initialise avec
   le triplet passé en entrée.
   Complexité en temps et en espace: O(1) 
   @param t est le triplet qui sera une couleur si le noeud est une feuille ou un couple (coordonnées, largeur) sinon.
   @return un pointeur sur un quadNoeud, donc un quadTree
*/
quadTree creer_quadTree(triplet_t t);

/**
   Fonction qui vérifie si le quadNoeud passé en entrée est une feuille ou un noeud interne.
   Complexité en temps et en espace: O(1) 
   @param t est un pointeur sur le quadNoeud à tester
   @return 1 si t est une feuille, 0 si c'est un noeud interne.
 */
int est_feuille(quadTree t);

/**
   Procédure permettant d'afficher les noeuds d'un quadTree selon l'ordre préfixe.
   Complexité en temps: O(|t|) où |t| désigne le nombre de noeuds dans l'arbre
   Complexité en espace: O(1)
   @param t est l'arbre à afficher
*/
void afficher_quadTree(quadTree t);

/**
   Procédure permettant de libérer l'espace mémoire utilisé par un quadTree
   Complexité en temps: O(|t|) où |t| désigne le nombre de noeuds dans l'arbre
   Complexité en espace: O(1)
   @param t est l'arbre à libérer
*/
void liberer_quadTree(quadTree t);


/**
   Fonction de conversion d'une image en quadTree
   Complexité en temps: O(largeur^2) dans le meilleur des cas et O(largeur^2* log_2(largeur^2)) dans le pire des cas.
   Complexité en espace: O(|t|) où |t| est le nombre de noeuds dans l'arbre, soit O(largeur^2* log_2(largeur^2)) dans le pire des cas et O(1) dans le meilleur des cas   
   @param image est un tableau carré de triplet_t
   @param largeur est la largeur de l'image carré
   @return un quadTree correspondant à l'image passée en entrée
*/
quadTree image_vers_quadTree(image_t image, int largeur);

/**
   Fonction qui vérifie si un quadTree est un AQR.
   Complexité en temps: O(|t|) dans le pire des cas, O(1) sinon.
   Complexité en espace: O(1)
   @param t est un quadTree
   @return 1 si t est un AQR, 0 sinon.
*/
int est_AQR(quadTree t);

/**
   Procédure permettant de changer toutes les occurrences de couleurs d'une image.
   Complexité en temps: O(|t|)
   Complexité en espace: O(1)
   @param t est le quadtree à modifier
   @param c1 est la couleur que l'on souhaite remplacer
   @param c2 est la nouvelle couleur.
 */
void remplacer_couleur(quadTree t, triplet_t c1, triplet_t c2);



#endif