#include <stdio.h>
#include "SDL/SDL.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "ens.h"
/**
*  @file ens.c
*  @brief le mouvement aleaatoire du ennemie  .
*  @author JJS team .
* @version 0.1.
* @date  mai 21 ,2020
*
*version final  
*
*/ 

/**
* @brief initialise the enemies .
* @param e the ennemi
* @param url the url of the image
* @return nothing
*/
void initialiser(ennemie *e)
{
e->tab[0]=IMG_Load("Attack1_000(1).png");//vers le gauche
e->tab[1]=IMG_Load("Attack_000(1).png");//vers le droit 
e->tab[2]=IMG_Load("background.png");//background

//position 
e->pos[0].x=150;
e->pos[0].y=230;

e->pos[1].x=400;
e->pos[1].y=230;

e->pos[2].x=0;
e->pos[2].y=0;
}

/**
* @brief aleatory movement .
* @param e the enemie
* @param url the url of the image
* @return nothing
*/
void deplacer_ennemiealiatoire(ennemie *e,SDL_Surface *screen)
{ 
SDL_BlitSurface(e->tab[2],NULL,screen,&e->pos[2]);

if(e->pos[0].x>300)
{
e->direc=1;
}

if(e->pos[0].x<150)
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
SDL_Flip(screen);
}

void frees(ennemie e)
{
SDL_FreeSurface(e.tab[0]);
SDL_FreeSurface(e.tab[1]);
}



