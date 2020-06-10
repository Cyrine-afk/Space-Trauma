#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#ifndef ENIGME_H_INCLUDED 
#define ENIGME_H_INCLUDED

/**
* @struct enigme
* @brief struct for enigme
*/
typedef struct 
{
SDL_Surface *nm[20];
SDL_Surface *img[20];
SDL_Surface *box[3];
SDL_Surface *card[1];
SDL_Rect poscard[1];
SDL_Rect posnum[20];
SDL_Rect posimg[20];
SDL_Rect posbox[3];
}enigme2;

void init_card (enigme2 *e);
void afficher_card (enigme2 e,SDL_Surface *ecran);

void init_enigme(enigme2 *e);

void nb (int n, int *p, int *number,int *numero, SDL_Surface *img2,SDL_Surface *ecran, SDL_Rect pos1, SDL_Rect pos2,SDL_Rect pos3);


void afficher_enigme (enigme2 e,SDL_Surface *ecran);

void recherchenum(SDL_Surface *fond, int *num,int nclic,char temps1[],char temps2[],char temps3[],char temps4[],char temps5[],SDL_Surface *ecran, int quiz );

int gagne(int *num, int quiz);




#endif 

