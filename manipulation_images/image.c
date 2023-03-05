#include"image.h"
#include<stdio.h>
#include<stdlib.h>

#define SUPERIEUR 1
#define INFERIEUR -1
#define EGAL 0


triplet_t green = {0, 255, 0};
triplet_t yellow = {255, 255, 0};
triplet_t blue = {0, 0, 255};
triplet_t white = {255, 255, 255};


triplet_t creer_triplet(int x, int y, int z)
{
    struct triplet_s tripl;
    tripl.x = x;
    tripl.y = y;
    tripl.z = z;

    return tripl;
}

void afficher_triplet(triplet_t t)
{
    printf("(%d,%d,%d)", t.x, t.y, t.z);
}

int cmp_triplet(triplet_t t1, triplet_t t2)
{
	if(t1.x < t2.x || (t1.x == t2.x && (t1.y < t2.y || (t1.y == t2.y && t1.z > t2.z))))
	{
		return -1;
	}

	if(t1.x == t2.x && t1.y == t2.y && t1.z == t2.z)
		return 0;

	return 1;
}


image_t creer_image_carre(int largeur)
{
    triplet_t ** img;
    img = (triplet_t **) malloc(largeur*sizeof(triplet_t*)); // crée le pointeur de pointeurs
    for(int i = 0; i < largeur; i++)
    {
        img[i] = (triplet_t*) malloc(largeur*sizeof(triplet_t));
    }
    return img;
}

void liberer_image(image_t img, int largeur)
{
    for(int i = 0; i < largeur; i++)
    {
        free(img[i]);
    }
    free(img);
}

void remplir_zone(image_t image, int x, int y, int largeur, triplet_t couleur)
{
    for(int i = 0; i < largeur; i++)
    {
        for(int j = 0; j < largeur; j++)
        {
            image[x+i][y+j] = couleur;
        }
    }
}

void afficher_image(triplet_t ** image, int largeur)
{
    for(int i = 0; i < largeur; i++)
    {
        for(int j = 0; j < largeur; j++)
        {
            triplet_t t = image[i][j];
            if(cmp_triplet(t, green) == EGAL)
                afficher_pixel_vert();
            else if(cmp_triplet(t, blue) == EGAL)
                afficher_pixel_bleu();
            else if(cmp_triplet(t, yellow) == EGAL)
                afficher_pixel_jaune();
            else
                afficher_pixel_blanc();
        }
        printf("\n");
    }
}

image_t  image_figure()
{
    triplet_t ** img = creer_image_carre(16);

    remplir_zone(img, 0, 0, 16, white);
    remplir_zone(img, 8, 0, 8, yellow);
    remplir_zone(img, 10, 2, 4, white);

    remplir_zone(img, 4, 0, 4, blue);
    remplir_zone(img, 4, 4, 4, blue);

    remplir_zone(img, 0, 4, 4, yellow);

    remplir_zone(img, 0, 8, 8, green);

    remplir_zone(img, 8, 8, 4, blue);
    remplir_zone(img, 12, 8, 4, blue);
    remplir_zone(img, 8, 12, 4, yellow);


    return img;
}

int tester_zone(image_t image, int x, int y, int largeur)
{
    triplet_t couleur = image[x][y];

    for(int i = 0; i < largeur; i++)
    {
        for(int j = 0; j < largeur; j++)
        {
            if(cmp_triplet(image[i+x][j+y], couleur) != EGAL) return 0;
        }
    }

    return 1;
}




void afficher_pixel_blanc(){
    printf("\e[107m \e[49m");
}

void afficher_pixel_vert(){
    printf("\e[102m \e[49m");
}

void afficher_pixel_bleu(){
    printf("\e[44m \e[49m");
}

void afficher_pixel_jaune(){
    printf("\e[103m \e[49m");
}