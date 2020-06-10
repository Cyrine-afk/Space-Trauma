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

void animer_personnage2(hero2 *h2,int d)
{
  h2->tab[0][0]=h2->tab[d][h2->num_image];
  if(h2->num_image==3)
  h2->num_image=0;
  else
   h2->num_image++;

}


/*
void deplacer_ennemiealiatoire(es *e,SDL_Surface *Tab[])
{ 
//SDL_BlitSurface(e->tab[2],NULL,Tab,&e->pos[2]);

if(e->posenm[0].x>300)
{
e->direc=1;
}

if(e->posenm[0].x<150)
{
e->direc=0;
}


if(e->direc==0)
{
SDL_BlitSurface(e->enm[1],NULL,Tab[0],&e->posenm[0]);
e->posenm[0].x++;
SDL_Delay(7);
}
else

{
SDL_BlitSurface(e->enm[0],NULL,Tab[0],&e->posenm[0]);
e->posenm[0].x--;
SDL_Delay(7);
}
SDL_Flip(Tab[0]);

}*/

