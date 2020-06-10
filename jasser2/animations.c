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
* @file [animations.c].
* @author : JJS
* @brief : player animation 
* @date : 2020/06/09
* @version 1
*/



/**
* @brief animation of the player .
* @param h the player
* @param d int
* @return nothing
*/


void animer_personnage(hero *h,int d)
{
  h->tab[0][0]=h->tab[d][h->num_image];
  if(h->num_image==3)
  h->num_image=0;
  else
   h->num_image++;

}

/**
* @brief animation of the player .
* @param h the player
* @param d int
* @return nothing
*/

void animer_personnage_hit(hero *h,int d)
{
  h->tab2[0][0]=h->tab2[d][h->num_image];
  if(h->num_image==3)
  h->num_image=0;
  else
   h->num_image++;

}
/**
* @brief animation of the player 2 .
* @param h the player
* @param d int
* @return nothing
*/
void animer_personnage_2(hero *h,int d)
{
  h->tab3[0][0]=h->tab3[d][h->num_image];
  if(h->num_image==3)
  h->num_image=0;
  else
   h->num_image++;

}






