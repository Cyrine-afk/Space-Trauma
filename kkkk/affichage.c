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
* @file [affichage.c].
* @author : JJS
* @brief : Game Project
* @date : 2020/05/29
* @version 1
*/

void afficher_personnage(hero h,SDL_Surface *screen)
{
  SDL_BlitSurface(h.tab[0][0],NULL,screen,&h.position);

}

void afficher_personnage2(hero2 h2,SDL_Surface *screen)
{
  SDL_BlitSurface(h2.tab[0][0],NULL,screen,&h2.position);

}

void afficher_personnage3(hero h,hero2 h2,SDL_Surface *screen)
{
  SDL_BlitSurface(h2.tab[0][0],NULL,screen,&h.position);

}





void affiche_diamond (score *d, SDL_Surface *screen)
{

  SDL_BlitSurface(d->dmd,NULL,screen,&d->posd);

}


void affiche_heart (vie *v, SDL_Surface *screen)
{
  
  SDL_BlitSurface(v->hrt,NULL,screen,&v->posh);

}


/*void generate_afficher (SDL_Surface *screen[]  , char image [],enigme *en,int *alea)
{ 
	int test=*alea ;
    srand(time(NULL));
do{
 *alea = 1+ rand()%6;
}while(*alea==test) ;
 sprintf(image ,"%d.png",*alea);
en->img = IMG_Load(image);
 SDL_BlitSurface(en->img,NULL,screen[0],&(en->p)) ;
  SDL_Flip(screen[0]) ;
}*/



void affiche_ents (es *e, SDL_Surface *screen, int a, int c, SDL_Rect relativobj,SDL_Rect relativobj2)
{
  
  SDL_BlitSurface(e->obj[0],NULL,screen,&relativobj);
  SDL_BlitSurface(e->obj[1],NULL,screen,&relativobj2);
}

/*int afficher_resultat (SDL_Surface *screen[],int s,int r,enigme *en)
 {

 	if (r==s)
 	{
 		en->img=IMG_Load("lose.png");
 		SDL_BlitSurface(en->img, NULL, screen[0], &(en->p)) ;
        SDL_Flip(screen[0]);
   return 1;
 	}
 	else
 	{
 		en->img=IMG_Load("win.png");
 		SDL_BlitSurface(en->img, NULL, screen[0], &(en->p)) ;
        SDL_Flip(screen[0]);
return 0;
 	}
 }*/


void afficher_enigme (enigme2 e,SDL_Surface *screen)
{
  
  
 SDL_BlitSurface(e.img[0],NULL,screen,&e.posimg[0]);
 SDL_Flip(screen);


}

void afficher_card (enigme2 e,SDL_Surface *screen)
{
  
  
 SDL_BlitSurface(e.card[0],NULL,screen,&e.poscard[0]);
 SDL_Flip(screen);


}

void afficher_temps(temps *t,SDL_Surface *screen)
{	
 SDL_Color couleurBleue= {0,0, 255};

 time(&(t->t2));// temps actuel

 t->secondesEcoulees = t->t2 - t->t1;
       
 sprintf(t->entree,"%02d:%02d",(t->secondesEcoulees/60)%60, (t->secondesEcoulees)%60);
      

  t->texte = TTF_RenderUTF8_Solid(t->police, t->entree, couleurBleue);
        //printf("temps=%s   \n",t->entree);// sauvegarde dans le fichier 
      

  SDL_BlitSurface(t->texte, NULL, screen, &(t->position));
  SDL_Flip(screen);

//SDL_Delay(80);
}


void affiche_bouton_store (store *st, SDL_Surface *screen)
{
  SDL_BlitSurface(st->button[0],NULL,screen,&st->posbtn[0]);

  //SDL_Flip(screen[0]);
}


void affiche_store (store *st, SDL_Surface *screen )
{
  SDL_BlitSurface(st->image[0],NULL,screen,&st->position[0]);
  //SDL_Flip(screen[0]);
}

void aff_store_1 (SDL_Surface *screen, store st, int *dkhal, int motion_a, int motion_b,  hero *h, int tm)
{
  //int t=2000;
  SDL_Rect position_msg1;

 TTF_Init();

 TTF_Font *po1;
 SDL_Surface *text1;
 SDL_Color couleurBlanche1 = {0,0,255}; 
 char sc[50]="";
 char nb1[20]="";

 position_msg1.x=17;
 position_msg1.y=7;

 po1 = TTF_OpenFont("comic1.ttf", 22);
     
     if (motion_a>0 && motion_a<30 && motion_b>510 && motion_b<530)
     {
       printf("\n dkhal 1\n");
       affiche_store (&st,screen);

       sprintf(sc,"Score: %d",h->score);
       text1 = TTF_RenderText_Blended(po1,sc, couleurBlanche1);
       SDL_BlitSurface(text1, NULL, screen, &position_msg1);

       SDL_Flip(screen);

       *dkhal=1; //dkhal
       SDL_Delay (tm);
     } 
     else
       *dkhal=0; //madkhalch
}

void affiche_button_help (store *st, SDL_Surface *screen)
{
  SDL_BlitSurface(st->button[1],NULL,screen,&st->posbtn[1]);

  //SDL_Flip(screen[0]);
}

void afficher_help (store *st, SDL_Surface *screen, int motion_a, int motion_b)
{
  if (motion_a>0 && motion_a<30 && motion_b>490 && motion_b<510)
  {
    SDL_BlitSurface(st->image[1],NULL,screen,&st->position[1]);
    SDL_Flip(screen);
    SDL_Delay (3000);
  }
  //SDL_Flip(screen[0]);
}
