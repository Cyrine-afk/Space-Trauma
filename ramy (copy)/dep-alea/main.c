#include <stdio.h>
#include "SDL/SDL.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "ens.h"
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
{int x=1;
const int v=2;
int dis=0;
SDL_Event event;
SDL_Surface *screen=NULL;
ennemie e;
_Bool b[4]={0,0,0,0};

SDL_Init(SDL_INIT_VIDEO);
screen=SDL_SetVideoMode(900,650,32,SDL_HWSURFACE | SDL_DOUBLEBUF);


initialiser(&e);


while(x==1)
{SDL_PollEvent(&event);
   switch(event.type)
        {case SDL_QUIT:
           x = 0;
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

}
 
 
if(b[0])
{
e.pos[3].x+=v;
/*if(colis(p))
{
p.pos[1].x--;
SDL_BlitSurface(p.tab[3],NULL,screen,&p.pos[3]);
}*/
}

if(b[1])
{
e.pos[3].x-=v;
}

if(b[2])
{
e.pos[3].y-=v;
}

if(b[3])
{
e.pos[3].y+=v;
}

    
deplacer_ennemiealiatoire(&e, screen,dis);
}

frees(e);
}



