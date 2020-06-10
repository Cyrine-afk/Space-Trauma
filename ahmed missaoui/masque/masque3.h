#include "SDL/SDL.h"
#include <stdio.h>
#include <SDL/SDL_image.h>


#ifndef MASQUE3_H_
#define MASQUE3_H_

/**
* @struct minimap
* @brief struct for mini map
*/
typedef struct 
{

SDL_Surface *map[5]; /*! <Surface */
SDL_Rect posmap[5]; /*! <Rectangle */

}map;


void initialise(SDL_Surface *Tab[],SDL_Rect pos[],map *m);

SDL_Color getpixel(SDL_Surface *img,int x,int y);
int colis(SDL_Surface *Tab[],SDL_Rect pos[]);
int colis2(SDL_Surface *Tab[],SDL_Rect pos[]);
int colis3(SDL_Surface *Tab[],SDL_Rect pos[]);

void affiche1(SDL_Surface *Tab[],SDL_Rect pos[]);
void affiche2(SDL_Surface *Tab[],SDL_Rect pos[]);


void affichemap1(SDL_Surface *Tab[],map m);
void affichemap2(SDL_Surface *Tab[],map m);


#endif
