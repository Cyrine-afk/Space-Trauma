#ifndef ENS_H_
#define ENS_H_

#include "SDL/SDL.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
/*
* @struct ens 
* @brief struct for ens
*
*/

typedef struct ennemie
{
SDL_Surface *tab[3];
SDL_Rect pos[3];
int direc;
}ennemie;

void initialiser(ennemie *e);
void deplacer_ennemiealiatoire(ennemie *e,SDL_Surface *screen);
void frees(ennemie e);

#endif
