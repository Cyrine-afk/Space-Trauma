#include <stdio.h>
#include "SDL/SDL.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "ens.h"
/**
*  @file ens.c
*  @brief deplacer l'ennemier dans un trajectoire specific  .
*  @author JJS team .
* @version 0.1.
* @date  mai 21 ,2020
*
*version final  
*
*/ 


/**
* @brief initialiser les ennemies .
* @param e l'ennemie
* @param url the url of the image
* @return nothing
*/
void initialiser(ennemie *e)
{
e->tab[0]=IMG_Load("left (1)(1).png");//vers le gauche
e->tab[1]=IMG_Load("right (1).png");//vers le droit 
e->tab[2]=IMG_Load("background.png");//background
e->tab[3]=IMG_Load("Attack_000(1).png");//hero
e->tab[4]=IMG_Load("left attack (1)(1).png");// attack a gauche
e->tab[5]=IMG_Load("right attack.png");// attack a droite

//position 
e->pos[0].x=650;
e->pos[0].y=300;

e->pos[1].x=400;
e->pos[1].y=300;

e->pos[2].x=0;
e->pos[2].y=0;

e->pos[3].x=50;
e->pos[3].y=260;

e->pos[4].x=155;
e->pos[4].y=300;

e->pos[5].x=900;
e->pos[5].y=300;

}

/**
* @brief deplacer l' ennemie .
* @param e l'ennemie
* @param url the url of the image
* @return nothing
*/
void deplacer_ennemiealiatoire(ennemie *e,SDL_Surface *screen,int dis)
{ int d=0;
  

SDL_BlitSurface(e->tab[2],NULL,screen,&e->pos[2]);
SDL_BlitSurface(e->tab[3],NULL,screen,&e->pos[3]);

d=e->pos[0].x - e->pos[3].x;

if(d > 250)
{

if(e->pos[0].x>650)
{
e->direc=1;
}

if(e->pos[0].x<400)
{
e->direc=0;
}


if(e->direc==0)
{
SDL_BlitSurface(e->tab[1],NULL,screen,&e->pos[0]);
e->pos[0].x++;
SDL_Delay(7);
}
else
{
SDL_BlitSurface(e->tab[0],NULL,screen,&e->pos[0]);
e->pos[0].x--;
SDL_Delay(7);
}
}

else
if((d <= 250)&&(d >100))
{
SDL_BlitSurface(e->tab[0],NULL,screen,&e->pos[0]);
e->pos[0].x--;
}

else 
if((d <= 100)&&(d > 1))
{
 e->pos[4].x=e->pos[0].x;
SDL_BlitSurface(e->tab[4],NULL,screen,&e->pos[0]);
e->pos[0].x--;
}

else//!!!!!!!
if(dis==0)
{
if((d <=1)&&(d >-300))
{
e->pos[4].x=e->pos[0].x;
SDL_BlitSurface(e->tab[4],NULL,screen,&e->pos[0]);
e->pos[0].x--;
dis=1;
}
else
if((d <=-310)&&(d >-600))
{
dis=1;
e->pos[1].x=e->pos[0].x;
SDL_BlitSurface(e->tab[1],NULL,screen,&e->pos[0]);
e->pos[0].x++;

}
}

/*else//!!!!!!!
if(d >-610)
{
if(e->pos[0].x>650)
{
e->direc=1;
}

if(e->pos[0].x<400)
{
e->direc=0;
}


if(e->direc==0)
{
SDL_BlitSurface(e->tab[1],NULL,screen,&e->pos[0]);
e->pos[0].x++;
SDL_Delay(7);
}
else
{
SDL_BlitSurface(e->tab[0],NULL,screen,&e->pos[0]);
e->pos[0].x--;
SDL_Delay(7);
}
}*/

SDL_Flip(screen);
}


void frees(ennemie e)
{
SDL_FreeSurface(e.tab[0]);
SDL_FreeSurface(e.tab[1]);
SDL_FreeSurface(e.tab[3]);
SDL_FreeSurface(e.tab[4]);
SDL_FreeSurface(e.tab[5]);
}


