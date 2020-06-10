#include <stdio.h>
#include "SDL/SDL.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "col.h"
/**
*  @file main.c
*  @brief apparaitre d'un enigme a cause d'une collision .
*  @author JJS team .
* @version 0.1.
* @date  mai 21 ,2020
*
*version final  
*
*/

int main()
{
int x=1;
SDL_Surface *tab[4];
SDL_Surface *screen;
SDL_Rect pos[4];
SDL_Event event;
_Bool b[4]={0,0,0,0};
player p;



SDL_Init(SDL_INIT_VIDEO);
screen=SDL_SetVideoMode(700,600,32,SDL_SWSURFACE|SDL_DOUBLEBUF);

initialiser(&p);


while(x==1)
{
afficher( p,screen);
SDL_PollEvent(&event);

switch(event.type)
{
case SDL_QUIT:
x=0;
break;
case SDL_KEYDOWN:
switch(event.key.keysym.sym)
{
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

}//switch1



if(b[0])
{
p.pos[1].x++;
if(colis(&p))
{
p.pos[1].x--;
SDL_BlitSurface(p.tab[3],NULL,screen,&p.pos[3]);
}
}

if(b[1])
{
p.pos[1].x--;
if(colis(&p))
{
p.pos[1].x++;
SDL_BlitSurface(p.tab[3],NULL,screen,&p.pos[3]);
}
}

if(b[2])
{
p.pos[1].y--;
if(colis(&p))
{
p.pos[1].y++;
SDL_BlitSurface(p.tab[3],NULL,screen,&p.pos[3]);
}
}

if(b[3])
{
p.pos[1].y++;
if(colis(&p))
{
p.pos[1].y--;
SDL_BlitSurface(p.tab[3],NULL,screen,&p.pos[3]);
}
}

SDL_Flip(screen);
}

frees( p);
}






