#include <stdio.h>
#include "SDL/SDL.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "col.h"
/**
*  @file col.c
*  @brief apparaitre d'un enigme a cause d'une collision  .
*  @author JJS team .
* @version 0.1.
* @date  mai 21 ,2020
*
*version final  
*
*/ 

/**
* @brief to initialise the players .
* @param p the player
* @param url the url of the image
* @return nothing
*/
void initialiser(player *p)
{
p->tab[0]=IMG_Load("Attack1_000(1).png");
p->tab[1]=IMG_Load("Attack_000(1).png");
p->tab[2]=IMG_Load("background.png");
p->tab[3]=IMG_Load("fighter.png");

//position
p->pos[0].x=300;
p->pos[0].y=250;
p->pos[0].w=100;
p->pos[0].h=200;


p->pos[1].x=50;
p->pos[1].y=250;
p->pos[1].w=100;
p->pos[1].h=200;

p->pos[2].x=0;
p->pos[2].y=0;

p->pos[3].x=500;
p->pos[3].y=200;
}


/**
* @brief to do the collision .
* @param p the player
* @param url the url of the image
* @return nothing
*/
int colis(player *p)
{
if((p->pos[1].x + p->pos[1].w < p->pos[0].x)||(p->pos[1].x > p->pos[0].x + p->pos[0].w)||(p->pos[1].y + p->pos[1].h < p->pos[0].y)||(p->pos[1].y > p->pos[0].y + p->pos[0].h))
return 0;
else 
return 1;
}

/**
* @brief to show the images .
* @param p the player
* @param url the url of the image
* @return nothing
*/
void afficher(player p,SDL_Surface *screen)
{
SDL_BlitSurface(p.tab[2],NULL,screen,&p.pos[2]);
SDL_BlitSurface(p.tab[0],NULL,screen,&p.pos[0]);
SDL_BlitSurface(p.tab[1],NULL,screen,&p.pos[1]);
}


void frees(player p)
{
SDL_FreeSurface(p.tab[0]);
SDL_FreeSurface(p.tab[1]);
}

