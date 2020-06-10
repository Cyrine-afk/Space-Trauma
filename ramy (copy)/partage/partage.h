#ifndef ENS_H_
#define ENS_H_

#include "SDL/SDL.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#define largeur 1200
#define hauteur 600
/*
* @struct partage 
* @brief struct for partage
*
*/

typedef struct joueur joueur;

struct joueur{
SDL_Surface *p[6];
SDL_Rect pp;
};

typedef struct background background;

struct background{
SDL_Surface *background;
SDL_Rect pb;
};

void initialiser_joueur1(joueur *j);
void initialiser_joueur2(joueur *j);

void initialiser_background1(background *b);
void initialiser_background2(background *b);

#endif
