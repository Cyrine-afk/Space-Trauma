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
* @file [affichage.c].
* @author : JJS
* @brief : afficher le joueur
* @date : 2020/06/09
* @version 1
*/

/**
* @brief afficher le joueur .
* @param h the player
* @param tab the url of the image
* @return nothing
*/

void afficher_personnage(hero h,SDL_Surface *Tab[])
{
  SDL_BlitSurface(h.tab[0][0],NULL,Tab[0],&h.position);

}

/**
* @brief afficher le joueur .
* @param h the player
* @param tab the url of the image
* @return nothing
*/
void afficher_personnage_hit(hero h,SDL_Surface *Tab[])
{
  SDL_BlitSurface(h.tab2[0][0],NULL,Tab[0],&h.position);

}

/**
* @brief afficher le joueur 2 .
* @param h the player
* @param tab the url of the image
* @return nothing
*/

void afficher_personnage_2(hero h,SDL_Surface *Tab[])
{
  SDL_BlitSurface(h.tab3[0][0],NULL,Tab[0],&h.position);

}



/**
* @brief afficher le bg .
* @param h the player
* @param tab the url of the image
* @return nothing
*/

void affiche1(SDL_Surface *Tab[],SDL_Rect pos[])
{

SDL_BlitSurface(Tab[3],&pos[1],Tab[0],NULL);
SDL_BlitSurface(Tab[1],&pos[0],Tab[0],NULL);

}
/**
* @brief afficher le bg .
* @param h the player
* @param tab the url of the image
* @return nothing
*/

void affiche2(SDL_Surface *Tab[],SDL_Rect pos[])
{

SDL_BlitSurface(Tab[5],&pos[4],Tab[0],NULL);
SDL_BlitSurface(Tab[4],&pos[3],Tab[0],NULL);
}



