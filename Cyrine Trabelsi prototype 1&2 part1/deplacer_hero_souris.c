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
* @file [deplacer_hero_souris.c].
* @author : Cyrine Trabelsi
* @brief : Game Project
* @date : 2020/05/29
* @version 1
*/


/**
* @brief To make animation with mouse .
* @param pos[] for Rectangle
* @param argc for Integer
* @param ** argv for Character
* @param *h for hero
* @param *d for score
* @param *Tab[] for Surface
* @return Integer
*/
/*int souris ( int argc, char** argv, hero *h, score *d, SDL_Surface *Tab[], SDL_Rect pos[], vie *v, es *e, )
{
    int continuer=1 ;
    SDL_Event event ;

    SDL_EnableKeyRepeat(10, 10);
        while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
        case SDL_MOUSEBUTTONUP:
             if(event.button.button==SDL_BUTTON_LEFT)
              {
              h->sprite.frame.x = event.button.x;
              h->sprite.frame.y = event.button.y;
              }
              else if (event.button.button==SDL_BUTTON_RIGHT)
              continuer=0 ;

              break ;
         case SDL_ACTIVEEVENT :/*gestion de fenetre*/
                /*  if ((event.active.state & SDL_APPMOUSEFOCUS) == SDL_APPMOUSEFOCUS)/*tester l eat de la souris */
/*{
      if (event.active.gain == 0)  /*la souris est sortie de la fenetre*/
    /*    {
         h->sprite.frame.x++ ;
         h->sprite.frame.y++ ;
        }
      else if (event.active.gain == 1)  /*la souris est dans la fenetre*/
       /* {
         h->sprite.frame.x ++ ;
         h->sprite.frame.y++ ;
        }
}
            break ;


        }

        /* efface l'hero de l'écran */
      /*  SDL_BlitSurface(Tab[0],NULL,Tab[0],&pos[0]);

        SDL_BlitSurface(d->image[0],NULL,Tab[0],&d->position[0]);
        SDL_BlitSurface(d->image[2],NULL,Tab[0],&d->position[2]);
        SDL_BlitSurface(d->image[4],NULL,Tab[0],&d->position[4]);
        SDL_BlitSurface(d->image[6],NULL,Tab[0],&d->position[6]);        

        /* placer l'hero à sa nouvelle position */
     //   SDL_BlitSurface(h->imgA,NULL,Tab[0],&h->position);
        /* On met à jour l'affichage */
    /*  SDL_Flip(Tab[0]);
    }

 SDL_Flip(Tab[0]);

    return 0;
}*/
