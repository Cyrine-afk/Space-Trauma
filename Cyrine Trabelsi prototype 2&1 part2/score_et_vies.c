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
* @file [score_et_vies.c].
* @author : Cyrine Trabelsi
* @brief : Game Project
* @date : 2020/05/29
* @version 1
*/



/**
* @brief To manage score .
* @param *h for hero
* @param *d for score
* @param *Tab[] for Surface
* @param location for Rectangle
* @param relativ for Rectangle
* @param relativ3 for Rectangle
* @param relativ4 for Rectangle
* @param relativ5 for Rectangle
* @return Nothing
*/
void scoree (hero *h,score *d, SDL_Surface *Tab[], SDL_Rect location, SDL_Rect relativ, SDL_Rect relativ2, SDL_Rect relativ3, SDL_Rect relativ4, SDL_Rect relativ5)
{
  if(d->tab[0]==0)
  {
    if(colision(&location,&d->position[0])) // screen diamonds
    {

      if(!cols(h->position,relativ))

      SDL_BlitSurface(d->image[0],NULL,Tab[0],&relativ);

      else if(cols(h->position,relativ))
      {
       h->score=h->score+1;
       printf("\n score = %d \n",h->score);
       d->tab[0]=1;
      }

    }//if cols location et diamond1

  }//if d->tab[i]==0

  if(d->tab[1]==0)
  {
    if(colision(&location,&d->position[1])) // screen diamonds
    {

      if(!cols(h->position,relativ2))

      SDL_BlitSurface(d->image[1],NULL,Tab[0],&relativ2);

      else if(cols(h->position,relativ2))
      {
       h->score=h->score+1;
       printf("\n score = %d \n",h->score);
       d->tab[1]=1;
      }

    }//if cols location et diamond2

  }//if d->tab[i]==0

  if(d->tab[2]==0)
  {
    if(colision(&location,&d->position[2])) // screen diamonds
    {

      if(!cols(h->position,relativ3))

      SDL_BlitSurface(d->image[2],NULL,Tab[0],&relativ3);

      else if(cols(h->position,relativ3))
      {
       h->score=h->score+1;
       printf("\n score = %d \n",h->score);
       d->tab[2]=1;
      }

    }//if cols location et diamond3

  }//if d->tab[i]==0

  if(d->tab[3]==0)
  {
    if(colision(&location,&d->position[3])) // screen diamonds
    {

      if(!cols(h->position,relativ4))

      SDL_BlitSurface(d->image[3],NULL,Tab[0],&relativ4);

      else if(cols(h->position,relativ4))
      {
       h->score=h->score+1;
       printf("\n score = %d \n",h->score);
       d->tab[3]=1;
      }

    }//if cols location et diamond4

  }//if d->tab[i]==0

  if(d->tab[4]==0)
  {
    if(colision(&location,&d->position[4])) // screen diamonds
    {

      if(!cols(h->position,relativ5))

      SDL_BlitSurface(d->image[4],NULL,Tab[0],&relativ5);

      else if(cols(h->position,relativ5))
      {
       h->score=h->score+1;
       printf("\n score = %d \n",h->score);
       d->tab[4]=1;
      }

    }//if cols location et diamond5

  }//if d->tab[i]==0
}


void scoree2 (hero *h,score *d, SDL_Surface *Tab[], SDL_Rect location, SDL_Rect relativ6)
{
   if(d->tab[5]==0)
  {
    if(colision(&location,&d->position[5])) // screen diamonds
    {

      if(!cols(h->position,relativ6))

      SDL_BlitSurface(d->image[5],NULL,Tab[0],&relativ6);

      else if(cols(h->position,relativ6))
      {
       h->score=h->score+1;
       printf("\n score = %d \n",h->score);
       d->tab[5]=1;
      }

    }//if cols location et diamond6

  }//if d->tab[i]==0

}


/**
* @brief To manage lives .
* @param *h for hero
* @param *v for vie
* @param *e for es
* @param *Tab[] for Surface
* @param location for Rectangle
* @param rltv1 for Rectangle
* @param indice for Integer
* @param relativobj for Rectangle
* @param relativobj2 for Rectangle
* @return Integer
*/

int vies (hero *h,vie *v, es *e, SDL_Surface *Tab[], SDL_Rect location, SDL_Rect rltv1, int indice, SDL_Rect relativobj,SDL_Rect relativobj2)
{
/**** ajout de vies ****/
  if(v->tab[indice]==0)
  {
    if(colision(&location,&v->position[indice])) // screen hearts
    {

      if(!cols(h->position,rltv1))

      SDL_BlitSurface(v->image[indice],NULL,Tab[0],&rltv1);

      else if(cols(h->position,rltv1))
      {
       h->vie=h->vie+1;
       printf("\n vies = %d \n",h->vie);
       v->tab[indice]=1;
      }

    }//if cols location et heart1

  }//if v->tab[i]==0

 
/**** decrementation de vies ****/
if (v->tab2[0]==0)
{
    if(colision(&location,&e->posobj[0])) // screen objects
    {
      if(cols(h->position,relativobj))
      {
       h->vie--;
       printf("\n vies = %d \n",h->vie);
       v->tab2[0]=1;
      }

    }//if cols location et object
}

if (v->tab2[1]==0)
{
    if(colision(&location,&e->posobj[1])) // screen objects
    {
      if(cols(h->position,relativobj2))
      {
       h->vie--;
       printf("\n vies = %d \n",h->vie);
       v->tab2[1]=1;
      }

    }//if cols location et object
}

if (h->vie <= 0)
{
  return 1; //mort
}
else 
  return 0; //pas mort

}


