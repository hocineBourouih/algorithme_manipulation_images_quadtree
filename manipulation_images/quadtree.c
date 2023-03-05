#include"quadtree.h"
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define SUPERIEUR 1
#define INFERIEUR -1
#define EGAL 0


quadTree creer_quadTree(triplet_t t)
{
    quadTree arb = malloc(sizeof(struct quadNode_s));
    arb->triplet = t;
    return arb;
}


void afficher_quadTree(quadTree t)
{
    if(t == NULL) return;

    afficher_triplet(t->triplet);
    for(int i = 0; i < 4; i++) afficher_quadTree(t->enfants[i]);
}


void liberer_quadTree(quadTree t)
{
    if(t == NULL) return;

    for(int i = 0; i < 4; i++)
    {
        liberer_quadTree(t->enfants[i]);
    }

    free(t);
}


quadTree image_vers_quadTree_aux(image_t image, int x, int y, int largeur)
{
    if(image == NULL) return NULL;


    if(tester_zone(image, x, y, largeur) == 1) return creer_quadTree(image[x][y]);

    triplet_t tr = {y, x, largeur};    

    quadTree arb = creer_quadTree(tr);


    int nouv_larg = largeur/2;


    arb->enfants[0] = image_vers_quadTree_aux(image, x, y, nouv_larg);


    arb->enfants[1] = image_vers_quadTree_aux(image, x, y + nouv_larg, nouv_larg);
    
    
    arb->enfants[2] = image_vers_quadTree_aux(image, x + nouv_larg, y, nouv_larg);
    
    
    arb->enfants[3] = image_vers_quadTree_aux(image, x + nouv_larg, y + nouv_larg, nouv_larg);
    
    return arb;
}



quadTree image_vers_quadTree(image_t image, int largeur)
{
    return image_vers_quadTree_aux(image, 0, 0, largeur);
}


int est_AQR(quadTree t)
{
    if(t == NULL) return false; // utile pour le cas t != feuille
    
    
    bool est_feuille = true;
    for(int i = 0; i < 4; i++)
    {
        est_feuille &= t->enfants[i] == NULL;
    }
    if(est_feuille) return true;
    
    
    
    bool est_aqr = true;
    triplet_t max = t->triplet;
    
    for(int i = 0; i < 4; i++)
    {
        if(t->enfants[i] == NULL) return false;
        
        est_aqr &= cmp_triplet(max, t->enfants[i]->triplet) == INFERIEUR;
        max = t->enfants[i]->triplet;
        est_aqr &= est_AQR(t->enfants[i]);
    }
    
    return est_aqr;
}


void remplacer_couleur(quadTree t, triplet_t c1, triplet_t c2)
{
    if(t == NULL) return;
    
    bool est_feuille = true;
    
    for(int i = 0; i < 4; i++)
    {
        est_feuille &= t->enfants[i] == NULL;
        remplacer_couleur(t->enfants[i], c1, c2);
    }
    
    if(!est_feuille) return;
    
    if(cmp_triplet(t->triplet, c1) == EGAL) t->triplet = c2;
}