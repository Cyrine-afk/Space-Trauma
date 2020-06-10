#include <stdio.h>
#include "SDL/SDL.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "ens.h"
/**
*  @file main.c
*  @brief le mouvement aleaatoire du ennemie  .
*  @author JJS team .
* @version 0.1.
* @date  mai 21 ,2020
*
*version final  
*
*/ 


int main ()
{int x=1;


SDL_Event event;
SDL_Surface *screen=NULL;
ennemie e;

SDL_Init(SDL_INIT_VIDEO);
screen=SDL_SetVideoMode(700,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF);


initialiser(&e);


while(x==1)
{SDL_PollEvent(&event);
   switch(event.type)
        {case SDL_QUIT:
           x = 0;
         break;
        }
deplacer_ennemiealiatoire(&e, screen);
}

frees(e);
}



