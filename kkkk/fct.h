#ifndef FICHIER_H
#define FICHIER_H

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <ctype.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_ttf.h>
#include <string.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
typedef struct 
{

SDL_Surface *em3[2];
SDL_Rect posem3[2];

}enigme3;


/*************enigme3*************/
void init_enigmewi (enigme3 *e);
void afficher_enigmewi (enigme3 e,SDL_Surface *ecran);
int piocherMot(char *motPioche);
int nombreAleatoire(int nombreMax);
char lireCaractere();
int gagnewi(int lettreTrouvee[], long tailleMot);
int rechercheLettre(char lettre, char motSecret[],int nombre);
int verifier_reponse(char *m1,char *m2,int nombre);
char lireCaractere();


#endif


