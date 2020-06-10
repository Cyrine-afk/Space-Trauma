#include <stdio.h>
#include <stdlib.h>

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
* @file [enig_file.c].
* @author : Meriem Nour Ghozzi
* @brief : Game Project
* @date : 2020/05/29
* @version 1
*/

 
void generate_afficher (SDL_Surface *screen  , char image [],enigme *en,int *alea)
{ 
	int test=*alea ;
    srand(time(NULL));
do{
 *alea = 1;
}while(*alea==test) ;
 sprintf(image ,"./enigmes/mimou%d.png",*alea);
en->img = IMG_Load(image);
 SDL_BlitSurface(en->img,NULL,screen,&(en->p)) ;
  SDL_Flip(screen) ;
}


 int solution_e (char image [])
 {
 	int solution =0 ;

 	if(strcmp(image,"1.png")==0)
 	{
     		solution =1 ;
 	}
 /*	else  	if(strcmp(image,"2.png")==0)
 	{
 		solution =1;

 	}
/* 	else 	if(strcmp(image,"3.png")==0)
 	{
 		solution =3;	
 	}
	else  	if(strcmp(image,"4.png")==0)
 	{
 		solution =3;

 	}
 	else 	if(strcmp(image,"5.png")==0)
 	{
 		solution =3;	
 	}
	else  	if(strcmp(image,"6.png")==0)
 	{
 		solution =3;

 	}
 	*/

 	return solution;
 }

int resolution (int * running,int *run )
{
	SDL_Event event ;
  int r=0 ;
	SDL_PollEvent(&event);
	switch(event.type)
	{
		

       case SDL_KEYDOWN : 
            switch( event.key.keysym.sym )
                {
			  case  SDLK_a: 
			  r= 1;
			   break ;
			   case  SDLK_z :
			   r= 2;
			   break;
			   case SDLK_e: 
			   r=3 ;
			   break;
		          
			    }
       break ;

                 
	}
  return r ;
}

 int afficher_resultat (SDL_Surface * screen,int s,int r,enigme *en)
 {

 	if (r==s)
 	{
 		en->img=SDL_LoadBMP("./enigmes/win.bmp");
 		SDL_BlitSurface(en->img, NULL, screen, &(en->p)) ;
        SDL_Flip(screen);
        return 1;
 	}
 	else
 	{
 		en->img=SDL_LoadBMP("./enigmes/lose.bmp");
 		SDL_BlitSurface(en->img, NULL, screen, &(en->p)) ;
        SDL_Flip(screen);
        return 0;
 	}
 }

int enigme_File ( SDL_Surface *screen, enigme *en) //1:rbe7 0:khsar
{
	SDL_Surface *image1;
	FILE *f ;
	int s=3,r=0,run =1,running=1,alea,t=0;
	char image[30]="";
	SDL_Event event;
        f=fopen("test.txt","a"); 
        
/**** init enigme + file ****/
init_enigme(en);

	 if(en->img==NULL)
	 {
	 	fprintf(f,"%d\n",1800) ;

	 }
	 while (run)
	 {
		 running=1;
        	fprintf(f,"%d\n",en->p.x) ;
	         fprintf(f,"%d\n",en->p.y) ;

         generate_afficher ( screen , image ,en,&alea) ;
	        fprintf(f,"%s\n",image) ;

     // s=solution_e (image );
			do{
			r=resolution (&running,&run);
			}while((r>3 || r<1) && running!=0) ;
			fprintf(f,"run=%d\n",run) ;
         fprintf(f,"s= %d\nr=%d\n",s,r) ;
       t=afficher_resultat (screen,s,r,en) ;


  
/*while(running)
{

	
                   
		  SDL_WaitEvent(&event);
        switch(event.type)
        {
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

		} // switch 2
	    break ;
        }// switch 1
          

	} // while running*/

   } // while run
	 fclose(f) ;
      //SDL_FreeSurface(Tab);
      //SDL_Quit();

	return t;
}
