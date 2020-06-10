#include <stdio.h>
#include "SDL/SDL.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "partage.h"
/**
*  @file main.c
*  @brief deviser l'ecran en deux pour multijoueur  .
*  @author JJS team .
* @version 0.1.
* @date  mai 21 ,2020
*
*version final  
*
*/


int main ()
{ SDL_Surface *screen=NULL,*trait=NULL;
    joueur j1,j2;
    background b1,b2;
int continuer = 1;

_Bool b[4]={0,0,0,0};
_Bool bl[4]={0,0,0,0};




    SDL_Rect camera1, camera2, p_trait;

    camera1.x=0;
    camera1.y=100;
    camera1.w=largeur/2;
    camera1.h=hauteur;

    camera2.x=0;
    camera2.y=100;
    camera2.w=largeur/2;
    camera2.h=hauteur;

    p_trait.x=largeur/2;
    p_trait.y=0;

    SDL_Init(SDL_INIT_VIDEO);

    screen=SDL_SetVideoMode(largeur,hauteur,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    initialiser_background1(&b1);
    initialiser_background2(&b2);
    initialiser_joueur1(&j1);
    initialiser_joueur2(&j2);
    
    trait = IMG_Load("trait.png");

    
    SDL_Event event;

    while(continuer)
    {
    SDL_BlitSurface(b1.background,&camera1,screen,&b1.pb);
    SDL_BlitSurface(b2.background,&camera2,screen,&b2.pb);
    SDL_BlitSurface(j1.p[0],NULL,screen,&j1.pp);
    SDL_BlitSurface(j2.p[1],NULL,screen,&j2.pp);
    
    SDL_BlitSurface(trait,NULL,screen,&p_trait);
    SDL_Flip(screen);

        SDL_PollEvent(&event);
        switch(event.type)
        {
    case SDL_QUIT:
        continuer=0;
        break;
        case SDL_KEYDOWN :
            switch(event.key.keysym.sym)
            {
                case SDLK_ESCAPE :
                continuer = 0;
                break;
case SDLK_RIGHT:
b[0]=1;
break;
case SDLK_LEFT:
b[1]=1;
break;
case SDLK_UP:
b[2]=1;
break;
case SDLK_DOWN:
b[3]=1;
break;
}
break;
case SDL_KEYUP:
switch(event.key.keysym.sym)
{
case SDLK_RIGHT:
b[0]=0;
break;
case SDLK_LEFT:
b[1]=0;
break;
case SDLK_UP:
b[2]=0;
break;
case SDLK_DOWN:
b[3]=0;
break;
}
break;           
}

if(b[0])
{
if(j1.pp.x <=(largeur/2)-140)
{
j1.pp.x++;
}
}

if(b[1])
{
j1.pp.x--;
}

if(b[2])
{
j1.pp.y--;
}

if(b[3])
{
if(j1.pp.y <= hauteur-300)
{
j1.pp.y++;
}
}

switch(event.type)
        {
    case SDL_QUIT:
        continuer=0;
        break;
        case SDL_KEYDOWN :
            switch(event.key.keysym.sym)
            {
                case SDLK_ESCAPE :
                continuer = 0;
                break;
case SDLK_d:
bl[0]=1;
break;
case SDLK_q:
bl[1]=1;
break;
case SDLK_z:
bl[2]=1;
break;
case SDLK_s:
bl[3]=1;
break;
}
break;
case SDL_KEYUP:
switch(event.key.keysym.sym)
{
case SDLK_d:
bl[0]=0;
break;
case SDLK_q:
bl[1]=0;
break;
case SDLK_z:
bl[2]=0;
break;
case SDLK_s:
bl[3]=0;
break;
}
break;
}


if(bl[0])
{
j2.pp.x++;
}

if(bl[1])
{
if(j2.pp.x >=largeur/2)
{
j2.pp.x--;
}
}

if(bl[2])
{
j2.pp.y--;
}

if(bl[3])
{
if(j2.pp.y <= hauteur-300)
{
j2.pp.y++;
}
}

    }

}


