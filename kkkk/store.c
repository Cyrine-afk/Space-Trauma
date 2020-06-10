#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"

#include "headers.h"
#include "defs.h"

/**
* @file [store.c].
* @author : Cyrine Trabelsi
* @brief : Game Project
* @date : 2020/05/29
* @version 1
*/

/**
* @brief To manage score .
* @param *Tab[] for Surface
* @param st for store
* @param *h for hero
* @param *tm for Integer
* @param motion_a for Integer
* @param motion_b for Integer
* @param *dkhal for Integer
* @return Nothing
*/
void gest_store (SDL_Surface *Tab[], store st, hero *h, int *tm,int motion_a,int motion_b, int *dkhal)
{
  printf("\n dkhal 2\n");

  if (motion_a>7 && motion_a<85 && motion_b>480 && motion_b<516 ) //back
           { 
            printf("\n touche back \n");
            tm=0; 
           }  
     
  if (motion_a>629 && motion_a<672 && motion_b>45 && motion_b<65 && h->score>=10) //hearts
           { 
             h->score-=10;
             h->vie+=3;
             printf("\n Condition \n");
             /*printf("\n score = %d \n",h->score);
              printf("\n vies = %d \n",h->vie);*/
           }  

   if (motion_a>629 && motion_a<672 && motion_b>110 && motion_b<133 && h->score>=10) //sle7 1
           { 
             h->score-=10;
             printf("\n Condition \n");
             printf("\n score = %d \n",h->score);
             //h->attack a modifier
           }  

    if (motion_a>629 && motion_a<672 && motion_b>184 && motion_b<205 && h->score>=20) //sle7 2
           { 
             h->score-=20;
             printf("\n Condition \n");
             printf("\n score = %d \n",h->score);
             //p->attack a modifier
           }   
    
    if (motion_a>629 && motion_a<672 && motion_b>257 && motion_b<277 && h->score>=30) //sle7 3
           { 
             h->score-=30;
             printf("\n Condition \n");
             printf("\n score = %d \n",h->score);
             //h->attack a modifier
           }
}



