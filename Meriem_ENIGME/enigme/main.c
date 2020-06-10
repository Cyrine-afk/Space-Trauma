#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "enig.h"
/**
*  @file main.c
*  @brief enigme du jeu
*   @author JJS team
*  @version 0.1
*  @date mai 30 , 2020
* 
* version final du menu
*
*/
//int main()
int main ()
{

	SDL_Surface *screen=NULL,*image1,*background ;
	SDL_Rect p ,pos;
	p.x=0 ;
	p.y=0 ;
	enigme e;
	FILE *f ;
	int s=2,r,run =1,running=1,alea,t=0;
	char image[30]="";
	 SDL_Event event;
   f=fopen("test.txt","a") ; 
	 SDL_Init ( SDL_INIT_VIDEO ) ;

	 screen=SDL_SetVideoMode(700,600,32,SDL_HWSURFACE  |  SDL_DOUBLEBUF );
background=SDL_LoadBMP("em3.bmp");
pos.x=0;
pos.y=0;
SDL_BlitSurface(background,NULL,screen,&pos);
SDL_Flip(screen);
	 init_enigme(&e);

	 if(e.img==NULL)
	 {
	 	fprintf(f,"%d\n",1800) ;

	 }
	 while (run)
	 {
		 running=1,r=0 ;
	   SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                run = 0;
	 break ;

        }
        	fprintf(f,"%d\n",e.p.x) ;
	         fprintf(f,"%d\n",e.p.y) ;
/*background=SDL_LoadBMP("em3.bmp");
pos.x=0;
pos.y=0;
SDL_BlitSurface(background,NULL,screen,&pos);
SDL_Flip(screen); */
         generate_afficher ( screen  , image ,&e,&alea) ;
	        fprintf(f,"%s\n",image) ;

      s=solution_e (image );
			do{
			r=resolution (&running,&run);
			}while((r>3 || r<1) && running!=0) ;
			fprintf(f,"run=%d\n",run) ;
			fprintf(f,"s= %d\nr=%d\n",s,r) ;
      while(running){

	t=afficher_resultat (screen,s,r,&e) ;

		  SDL_WaitEvent(&event);
        switch(event.type)
        {
					 case SDL_QUIT :
            running =0 ;
						run=0 ;
					  break ;
            case SDL_KEYDOWN :
                  switch( event.key.keysym.sym )
                {
			             case  SDLK_ESCAPE:
			              running= 0 ;
run=0 ;

			              break ;
case SDLK_SPACE:
running=0;
break;

			          }
						break ;
        }


			}
   }
	 fclose(f) ;
      SDL_FreeSurface(screen);
      SDL_Quit();
	return t;
}
