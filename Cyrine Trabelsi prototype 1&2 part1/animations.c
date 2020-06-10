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
* @brief : Game Project
* @date : 2020/05/29
* @version 1
*/

void animer_personnage(hero *h,int d)
{
  h->tab[0][0]=h->tab[d][h->num_image];
  if(h->num_image==3)
  h->num_image=0;
  else
   h->num_image++;

}



