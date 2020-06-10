#ifndef ENS_H_
#define ENS_H_

#include "SDL/SDL.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
/*
* @struct dep-alea 
* @brief struct for partage
*
*/



typedef struct ennemie
{
SDL_Surface *tab[6] ;
SDL_Rect pos[6];
int direc;
}ennemie;

void initialiser(ennemie *e);
void deplacer_ennemiealiatoire(ennemie *e,SDL_Surface *screen,int dis);
void frees(ennemie e);

#endif
