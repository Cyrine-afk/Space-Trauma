#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"

#include "headers.h"
#include "defs.h"

/**
* @file [free.c].
* @author : Cyrine Trabelsi
* @brief : Game Project
* @date : 2020/05/29
* @version 1
*/

/*void free_hero(hero *h)
{
	SDL_FreeSurface(h->sprite.image);
}*/


/**
* @brief To free entitee secondaire .
* @param *e for es
* @return Nothing
*/

void frees(es *e)
{
 int i;
 for (i=0;i<2;i++)
 {
  SDL_FreeSurface(e->enm[i]);
 }
 for (i=0;i<3;i++)
 {
  SDL_FreeSurface(e->obj[i]);
 }
}

/**
* @brief To free hearts .
* @param *v for vie
* @return Nothing
*/

void freeHearts (vie *v)
{ 
 SDL_FreeSurface(v->image[0]);
 SDL_FreeSurface(v->image[1]);
 SDL_FreeSurface(v->hrt);
}

/**
* @brief To free diamonds .
* @param *d for score
* @return Nothing
*/

void freeDiamonds (score *d)
{ 
 int i;
 for (i=0;i<7;i++)
 {
  SDL_FreeSurface(d->image[i]);
 }
 SDL_FreeSurface(d->dmd);
}

/**
* @brief To free text .
* @param *po for Font
* @param *po1 for Font
* @param *text1 for Surface
* @param *text for Surface
* @return Nothing
*/

void freeText (TTF_Font *po, TTF_Font *po1, SDL_Surface *text1, SDL_Surface *text)
{ 
 SDL_FreeSurface(text);
 SDL_FreeSurface(text1);
 TTF_CloseFont(po);
 TTF_CloseFont(po1);
}

/**
* @brief To free temps .
* @param *t for temps
* @return Nothing
*/

void free_temps(temps *t)
{SDL_FreeSurface(t->texte);
 TTF_CloseFont(t->police);
}

