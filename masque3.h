#include "SDL/SDL.h"
#include <stdio.h>
#include <SDL/SDL_image.h>



#ifndef MASQUE3_H_
#define MASQUE3_H_
SDL_Color getpixel(SDL_Surface *Tab[],int x,int y);
int colis(SDL_Surface *Tab[],SDL_Rect pos[]);
SDL_Color getpixel2(SDL_Surface *Tab[],int x,int y);
int colis2(SDL_Surface *Tab[],SDL_Rect pos[]);
void initialise(SDL_Surface *Tab[],SDL_Rect pos[]);
void affiche1(SDL_Surface *Tab[],SDL_Rect pos[]);
void affiche2(SDL_Surface *Tab[],SDL_Rect pos[]);
#endif
