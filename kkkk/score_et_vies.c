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






void scoreinside (hero *h,score *d, SDL_Surface *screen, SDL_Rect location, SDL_Rect relativ3, SDL_Rect relativ4 )

{

 if(d->tab[15]==0)
  {
    if(colision(&location,&d->position[15])) // screen diamonds
    {

      if(!cols(h->position,relativ3))

      SDL_BlitSurface(d->image[15],NULL,screen,&relativ3);

      else if(cols(h->position,relativ3))
      {
       h->score=h->score+1;
       printf("\n score = %d \n",h->score);
       d->tab[15]=1;
}
  }//if cols location et diamond1

  }//if d->tab[i]==0



 if(d->tab[16]==0)
  {
    if(colision(&location,&d->position[16])) // screen diamonds
    {

      if(!cols(h->position,relativ4))

      SDL_BlitSurface(d->image[16],NULL,screen,&relativ4);

      else if(cols(h->position,relativ4))
      {
       h->score=h->score+1;
       printf("\n score = %d \n",h->score);
       d->tab[16]=1;
}
  }//if cols location et diamond1

  }//if d->tab[i]==0




}





void scorerobots (hero *h,score *d, SDL_Surface *screen, SDL_Rect location,SDL_Rect relativ, SDL_Rect relativ2, SDL_Rect relativ3)
{

 if(d->tab[12]==0)
  {
    if(colision(&location,&d->position[12])) // screen diamonds
    {

      if(!cols(h->position,relativ))

      SDL_BlitSurface(d->image[12],NULL,screen,&relativ);

      else if(cols(h->position,relativ))
      {
       h->score=h->score+1;
       printf("\n score = %d \n",h->score);
       d->tab[12]=1;
      }

  }//if cols location et diamond1

  }//if d->tab[i]==0

 if(d->tab[13]==0)
  {
    if(colision(&location,&d->position[13])) // screen diamonds
    {

      if(!cols(h->position,relativ2))

      SDL_BlitSurface(d->image[13],NULL,screen,&relativ2);

      else if(cols(h->position,relativ2))
      {
       h->score=h->score+1;
       printf("\n score = %d \n",h->score);
       d->tab[13]=1;
      }
  }//if cols location et diamond1

  }//if d->tab[i]==0


 if(d->tab[14]==0)
  {
    if(colision(&location,&d->position[14])) // screen diamonds
    {

      if(!cols(h->position,relativ3))

      SDL_BlitSurface(d->image[14],NULL,screen,&relativ3);

      else if(cols(h->position,relativ3))
      {
       h->score=h->score+1;
       printf("\n score = %d \n",h->score);
       d->tab[14]=1;
}
  }//if cols location et diamond1

  }//if d->tab[i]==0

 
 }


/**
* @brief To manage score .
* @param *h for hero
* @param *d for score
* @param *Tab[] for Surface
* @return Nothing
*/
void scoree (hero *h,score *d, SDL_Surface *screen, SDL_Rect location, SDL_Rect relativ, SDL_Rect relativ2, SDL_Rect relativ3, SDL_Rect relativ4, SDL_Rect relativ5)
{
  if(d->tab[0]==0)
  {
    if(colision(&location,&d->position[0])) // screen diamonds
    {

      if(!cols(h->position,relativ))

      SDL_BlitSurface(d->image[0],NULL,screen,&relativ);

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

      SDL_BlitSurface(d->image[1],NULL,screen,&relativ2);

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

      SDL_BlitSurface(d->image[2],NULL,screen,&relativ3);

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

      SDL_BlitSurface(d->image[3],NULL,screen,&relativ4);

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

      SDL_BlitSurface(d->image[4],NULL,screen,&relativ5);

      else if(cols(h->position,relativ5))
      {
       h->score=h->score+1;
       printf("\n score = %d \n",h->score);
       d->tab[4]=1;
      }

    }//if cols location et diamond5

  }//if d->tab[i]==0
}


//mochklet diamant map2 diamant 2 & 3
void scoree2 (hero *h,score *d, SDL_Surface *screen, SDL_Rect location, SDL_Rect relativ6, SDL_Rect relativ7, SDL_Rect relativ8)
{
   if(d->tab[5]==0)
  {
    if(colision(&location,&d->position[5])) // screen diamonds
    {

      if(!cols(h->position,relativ6))

      SDL_BlitSurface(d->image[5],NULL,screen,&relativ6);

      else if(cols(h->position,relativ6))
      {
       h->score=h->score+1;
       printf("\n score = %d \n",h->score);
       d->tab[5]=1;
      }

    }//if cols location et diamond6

  }//if d->tab[i]==0

  if(d->tab[6]==0)
  {
    if(colision(&location,&d->position[6])) // screen diamonds
    {

      if(!cols(h->position,relativ7))

      SDL_BlitSurface(d->image[6],NULL,screen,&relativ7);

      else if(cols(h->position,relativ7))
      {
       h->score=h->score+1;
       printf("\n score = %d \n",h->score);
       d->tab[6]=1;
      }

    }//if cols location et diamond7

  }//if d->tab[i]==0

  if(d->tab[7]==0)
  {
    if(colision(&location,&d->position[7])) // screen diamonds
    {

      if(!cols(h->position,relativ8))

      SDL_BlitSurface(d->image[7],NULL,screen,&relativ8);

      else if(cols(h->position,relativ8))
      {
       h->score=h->score+1;
       printf("\n score = %d \n",h->score);
       d->tab[7]=1;
      }

    }//if cols location et diamond8

  }//if d->tab[i]==0
}


void scorewitches (hero *h,score *d, SDL_Surface *screen, SDL_Rect location, SDL_Rect relativ5, SDL_Rect relativ6, SDL_Rect relativ2, SDL_Rect hajra)
{

 if(d->tab[9]==0)
  {
    if(colision(&location,&d->position[9])) // screen diamonds
    {

      if(!cols(h->position,relativ5))

      SDL_BlitSurface(d->image[9],NULL,screen,&relativ5);

      else if(cols(h->position,relativ5))
      {
       h->score=h->score+1;
       printf("\n score = %d \n",h->score);
       d->tab[9]=1;
      }

    }//if cols location et diamond8

  }//if d->tab[i]==0


if(d->tab[10]==0)
  {
    if(colision(&location,&d->position[10])) // screen diamonds
    {

      if(!cols(h->position,relativ6))

      SDL_BlitSurface(d->image[10],NULL,screen,&relativ6);

      else if(cols(h->position,relativ6))
      {
       h->score=h->score+1;
       printf("\n score = %d \n",h->score);
       d->tab[10]=1;
      }

    }//if cols location et diamond8

  }//if d->tab[i]==0

if(d->tab[11]==0)
  {
    if(colision(&location,&d->position[11])) // screen diamonds
    {

      if(!cols(h->position,relativ2))
{
      SDL_BlitSurface(d->image[11],NULL,screen,&relativ2);
      d->position[11].x=hajra.x;
}
      else if(cols(h->position,relativ2))
      {
       h->score=h->score+1;
       printf("\n score = %d \n",h->score);
       d->tab[11]=1;
      }

    }//if cols location et diamond8

  }//if d->tab[i]==0



}



int viesrobots (hero *h,vie *v, es *e, SDL_Surface *screen, SDL_Rect location, SDL_Rect relativ4)
{

if (v->tab2[5]==0)
{
    if(colision(&location,&v->position[4])) // screen objects
    {

  SDL_BlitSurface( v->image[4],NULL,screen,&relativ4);

      if(cols(h->position,relativ4))
      {
       h->vie++;
       printf("\n vies = %d \n",h->vie);
       v->tab2[5]=1;
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




/**
* @brief To manage lives .
* @param *h for hero
* @param *v for vie
* @param *e for es
* @param *Tab[] for Surface
* @return Integer
*/

int vies (hero *h,vie *v, es *e, SDL_Surface *screen, SDL_Rect location, SDL_Rect rltv1, int indice, SDL_Rect relativobj,SDL_Rect relativobj2)
{
/**** ajout de vies ****/
  if(v->tab[indice]==0)
  {
    if(colision(&location,&v->position[indice])) // screen hearts
    {

      if(!cols(h->position,rltv1))

      SDL_BlitSurface(v->image[indice],NULL,screen,&rltv1);

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
       /*if ((h->lifem < (3)) && (h->lifem > (-5)))
       { 
         h->vie--;
         h->lifem=0;
       }*/
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
       /*if ((h->lifem < (3)) && (h->lifem > (-5)))
       { 
         h->vie--;
         h->lifem=0;
       }*/
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


int vieswitches (hero *h,vie *v, es *e, SDL_Surface *screen, SDL_Rect location, SDL_Rect relativ3,SDL_Rect relativ7, int indice )
{

if (v->tab2[2]==0)
{
    if(colision(&location,&v->position[2])) // screen hearts
    {

 if (v->tab2[3]==0)
{

if(!cols(h->position,relativ3))
      {

      SDL_BlitSurface(v->image[2],NULL,screen,&relativ3);
      v->position[2].x--;

      }

       if(cols(h->position,relativ3))
      {

         v->tab2[3]=1;
        h->vie--;
       printf("\n vies = %d \n",h->vie);
      
      }

}//v-tab33==0

 if (v->tab2[3]==1)
{

 v->position[2].y++;
SDL_BlitSurface(v->image[2],NULL,screen,&relativ3);

}//v-tab33==1

if(v->position[2].x==0 || v->position[2].y>=520)
v->tab[2]=1;


    }//if cols location et heart1

  }//if v->tab[2]==0






if (v->tab2[4]==0)
{
    if(colision(&location,&v->position[3])) // screen objects
    {

  SDL_BlitSurface( v->image[3],NULL,screen,&relativ7);

      if(cols(h->position,relativ7))
      {
       h->vie++;
       printf("\n vies = %d \n",h->vie);
       v->tab2[4]=1;
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

/*int vies(hero *h,vie *v,es *e, int h0,int h1, int e1, int e2, SDL_Surface *Tab[], SDL_Surface *dead, SDL_Rect posdead)
{
int i;

if (h0==0)
{
if(!collisionTrigoVie(h->position,v,0)) 
{
SDL_BlitSurface(v->image[0],NULL,Tab[0],&v->position[0]);
}
 if(collisionTrigoVie(h->position,v,0))
{
h->vie++;
v->position[0].x=8000;
h0=1;
}
}// end if h0==0

if (h1==0)
{
if(!collisionTrigoVie(h->position,v,1))
{
SDL_BlitSurface(v->image[1],NULL,Tab[0],&v->position[1]);
}
 if(collisionTrigoVie(h->position,v,1))
{
h->vie++;
v->position[1].x=8000;
h1=1;
}
}// end if h1==0


//i=colis(e,h);

if (e1==0)
{
if (collisionTrigoEs(h->position,e,0))// (i==1)
{ 
 h->lifem--;
e1=1;
} 
}

if (e2==0)
{
if (collisionTrigoEs(h->position,e,1))// (i==1)
{ 
 h->lifem--;
 e2=1;
} 
}

if ( (h->lifem <= (-145)) && (h->lifem >= (-165)) )
 {
   h->vie--;
   h->lifem=0;
 }

if (h->vie <= 0)
{
  SDL_BlitSurface(dead,NULL,Tab[0],&posdead);
  return 1; //mort
}
else 
  return 0; //pas mort 

}*/

/*void scoree(hero *h,score *d, SDL_Surface *Tab[])
{

int i;

if (d->tab[0]==0)
{
 if (!collisionTrigo(h->position,d,0))
 {
  SDL_BlitSurface(d->image[0],NULL,Tab[1],&d->position[0]);
 }

 if(collisionTrigo(h->position,d,0))
 {
  h->score=h->score+1;
  //d->position[0].x=-2000;
  d->tab[0]=1;
  printf("\n score = %d \n",h->score);
 }
}

if (d->tab[1]==0)
{
 if (!collisionTrigo(h->position,d,0))
 {
  SDL_BlitSurface(d->image[1],NULL,Tab[1],&d->position[1]);
 }

 if(collisionTrigo(h->position,d,1))
 {
  h->score=h->score+1;
  //d->position[1].x=-2000;
  d->tab[1]=1;
  printf("\n score = %d \n",h->score);
 }
}

if (d->tab[2]==0)
{
 if (!collisionTrigo(h->position,d,2))
 {
  SDL_BlitSurface(d->image[2],NULL,Tab[1],&d->position[2]);
 }

 if(collisionTrigo(h->position,d,2))
 {
  h->score=h->score+1;
  //d->position[2].x=-2000;
  d->tab[2]=1;
  printf("\n score = %d \n",h->score);
 }
}

if (d->tab[3]==0)
{
 if (!collisionTrigo(h->position,d,3))
 {
  SDL_BlitSurface(d->image[3],NULL,Tab[1],&d->position[3]);
 }

 if(collisionTrigo(h->position,d,3))
 {
  h->score=h->score+1;
  //d->position[3].x=2000;
  d->tab[3]=1;
  printf("\n score = %d \n",h->score);
 }
}

if (d->tab[4]==0)
{
 if (!collisionTrigo(h->position,d,4))
 {
  SDL_BlitSurface(d->image[4],NULL,Tab[1],&d->position[4]);
 }

 if(collisionTrigo(h->position,d,4))
 {
  h->score=h->score+1;
  //d->position[4].x=2000;
  d->tab[4]=1;
  printf("\n score = %d \n",h->score);
 }
}

if (d->tab[5]==0)
{
 if (!collisionTrigo(h->position,d,5))
 {
  SDL_BlitSurface(d->image[5],NULL,Tab[1],&d->position[5]);
 }

 if(collisionTrigo(h->position,d,5))
 {
  h->score=h->score+1;
  //d->position[5].x=2000;
  d->tab[5]=1;
  printf("\n score = %d \n",h->score);
 }
}

if (d->tab[6]==0)
{
 if (!collisionTrigo(h->position,d,6))
 {
  SDL_BlitSurface(d->image[6],NULL,Tab[1],&d->position[6]);
 }

 if(collisionTrigo(h->position,d,6))
 {
  h->score=h->score+1;
  //d->position[6].x=2000;
  d->tab[6]=1;
  printf("\n score = %d \n",h->score);
 }
}

if (d->tab[7]==0)
{
 if (!collisionTrigo(h->position,d,7))
 {
  SDL_BlitSurface(d->image[7],NULL,Tab[1],&d->position[7]);
 }

 if(collisionTrigo(h->position,d,7))
 {
  h->score=h->score+1;
  //d->position[7].x=2000;
  d->tab[7]=1;
  printf("\n score = %d \n",h->score);
 }
}
 
}*/
