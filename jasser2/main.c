#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"

#include "headers.h"
#include "defs.h"


/**
* @file [main.c].
* @author : jasser chammar
* @brief : Game Project
* @date : 2020/06/09
* @version 1
*/



void main() 
{


//structs
hero h;


SDL_Rect max;

max.y=450; //definition niveau sol

Uint32 t_start=0;

//SDL
SDL_Surface *Tab[8];
SDL_Rect pos[8];
SDL_Event event;
SDL_Surface *dead;
SDL_Rect posdead;

//other

char image[8];
int h0,h1,e1,e2;
int indice;
int num;
int x=1,t=1,y=0;
int continuer=1;
const int speed=20;
_Bool b[8]={0,0,0,0,0,0,0,0};
int argc;
char** argv;
int vv;
int sens=0,senspred=0;
int q;
int m=0;
int a=0,c=0;
int cont;
int i=0;
int niveau=0, check_save=1;




/**** screen ****/
if(SDL_Init(SDL_INIT_VIDEO)!=0)
{
printf("Unable :%s\n",SDL_GetError());
}

Tab[0]=SDL_SetVideoMode(730,530,0,SDL_SWSURFACE|SDL_DOUBLEBUF);


/**** init background ****/
initialise(Tab,pos);

/**** init hero ****/
initialiser_personnage(&h);
initialiser_personnage_hit(&h);

/**** boucle du jeu ****/

 while(continuer)
 {

t_start = SDL_GetTicks();

niveau=1;



  //menu 
   SDL_PollEvent(&event);

   switch(event.type)
   {
    case SDL_QUIT:
    continuer=0;
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

      case SDLK_SPACE:
      b[4]=1;
      break;

      case SDLK_ESCAPE:
      b[5]=1;
      break;

      case SDLK_e:
      b[6]=1;
      break;

     } // end switch event key
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

      case SDLK_SPACE:
      b[4]=0;
      break;

      case SDLK_ESCAPE:
      b[5]=0;
      break;

      case SDLK_e:
      b[6]=0;
      break;

    }// end switch key up
     break;


    }// end switch (event type)
    

    if(t==1)
    {
     if(b[0])
     {
      if(h.position.x>=200)
      {
       a+=speed;
       pos[0].x+=speed;
       pos[1].x+=speed;

       if(pos[0].x>=2500-400)
       {a=2500-400;
        pos[0].x=2500-400;
        pos[1].x=2500-400;
       }
      }
     }

     if(b[1])
    {
     a-=speed;
     pos[0].x-=speed;
     pos[1].x-=speed;

     if(pos[0].x<=0)
     {a=0;
      pos[0].x=0;
      pos[1].x=0;
     }
    }


    if(b[0])
    {
     if(h.position.x<=200)
     h.position.x+=speed;


     else if(pos[0].x>=2500-400)
     {
      h.position.x+=speed;
     }
    }
 

    if(h.position.x==500 && h.position.y<=510)
    {
     t=2;
     h.position.x=10;
     h.position.y=300;
    }


/**** bcg ***/
affiche1(Tab,pos);


/**** afficher et animer hero ****/

h.position.y+=h.gravite;
h.gravite++;

if (h.gravite==20 )
			{h.gravite=20;}

	if(h.position.y + 150 >= max.y)
		{
			h.gravite=0;
			h.position.y=max.y-150;

		}
if(b[4]==1){
                        h.position.y-=speed;
     							 }
if(b[1]==1){
h.position.x=0;
    

                          q=1;
                            animer_personnage(&h,q);
}

if(b[0]==1){
                          q=0;

                            animer_personnage(&h,q);
}

if(b[6]==1){
                          q=0;

                            animer_personnage_hit(&h,q);
                          i=1;
}

if(i==1){

afficher_personnage_2(h,Tab);}
else{  
afficher_personnage(h,Tab);

}
/**** flip ****/    
    SDL_Flip(Tab[0]);



   }



 } //end while (continuer)


/**** free ****/

//SDL_Quit();
//free_hero(&h);

}//end main




