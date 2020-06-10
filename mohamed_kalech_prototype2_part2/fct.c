#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL/SDL_rotozoom.h>
#include <string.h>
#include "fichier.h"
/**
*  @file fct.c 
*  @brief enigme2 stage2.
*  @author Mohamed kalech .
* @version 0.1.
* @date  mai 21 ,2020
*
*version final  
*
*/


/** 
*  @brief to rotate the ball 
*  @param screen is screen 
*  @param image is a ball 
*  @param rotation 
* @return nothing 
*/
void roto(SDL_Surface *screen,SDL_Surface *image, SDL_Surface *rotation ,SDL_Rect rect)
{
	int tempsActuel = 0; int tempsPrecedent = 0; int done;
	Uint32 oldTime = SDL_GetTicks();
	done = 1; int angle = 0;
            int i;
           for (i = 0; i < 180; i++)
   {
	SDL_Surface*rotation = rotozoomSurface(image, i, 1, 3);
							SDL_BlitSurface(rotation, NULL, screen, &rect);
							SDL_FreeSurface(rotation);
	SDL_Flip(screen);
		}

	
    }

