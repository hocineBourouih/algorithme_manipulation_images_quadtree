#include"quadtree.h"
#include"image.h"
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include <stdbool.h>

// remarque : image est de taille 16*16 soit 256 pixels
#define LARGEUR 16

int main(int argc, char ** argv)
{
    // création des triplet de pixel de l'image 
    triplet_t green = {0, 255, 0};
    triplet_t yellow = {255, 255, 0};
    triplet_t blue = {0, 0, 255};
    triplet_t white = {255, 255, 255};
    triplet_t red = {255, 0, 0};
 
    // Création de l'image
    image_t image = image_figure();
    
    // Affichage de l'image avant la conversion en quadtree
    printf("\nImage avant la conversion en quadtree:\n\n");
    afficher_image(image, LARGEUR);
    
    // Conversion de l'image en quadtree
    quadTree quad = image_vers_quadTree(image, LARGEUR);
    
    // Affichage du quadtree
    printf("\n\nQuadtree obtenu:\n\n");
    afficher_quadTree(quad);

    
    // Libération de l'espace mémoire alloué
    liberer_image(image, LARGEUR);
    liberer_quadTree(quad);
    
    return EXIT_SUCCESS;
}