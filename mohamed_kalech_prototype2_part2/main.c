#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_rotozoom.h>
#include <SDL/SDL_ttf.h>
#include "fichier.h"

/**
*  @file main.c 
*  @brief rotozoom stage3.
*  @author Mohamed kalech .
* @vesion 0.1.
* @date  mai 21 ,2020
*
* version final  
*
*/

void main()
{
    SDL_Init;
    
    SDL_Surface *ecran=NULL;
    SDL_Surface *image;
    
    SDL_Rect position;
    SDL_Event event;
    position.x=0;
    position.y=0;

 image=SDL_LoadBMP("em3.bmp");
    
   
    

 
    int continuer = 1;
    
   
    
    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(730, 530, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Enigme", NULL);
     TTF_Init();
     enigme3 e ;


     
    

     
     
     while (continuer)
    {
        SDL_BlitSurface(image, NULL, ecran,&position);
        roto(ecran,image,image,position);
        //continuer=0;
        

        while(SDL_PollEvent(&event))
        switch(event.type)
        {
              
    case SDL_QUIT:
        continuer = 0;
        break;
   
  }
}
    
   
   
    SDL_Quit;
    
        
        EXIT_SUCCESS;
    
          
        
}
