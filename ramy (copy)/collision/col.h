#ifndef ENS_H_
#define ENS_H_

#include "SDL/SDL.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
/*
* @struct collision 
* @brief struct for collition
*
*/

typedef struct player
{
SDL_Surface *tab[4];
SDL_Rect pos[4];
SDL_Event event;
}player;

void initialiser(player *p);
int colis(player *p);
void afficher(player p,SDL_Surface *screen);
void frees(player p);

#endif
