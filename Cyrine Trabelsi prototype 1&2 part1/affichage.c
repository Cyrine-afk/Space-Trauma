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

/**
* @brief Afficher hero .
* @param h for hero
* @param *Tab[] for Surface
* @return Nothing
*/

void afficher_personnage(hero h,SDL_Surface *Tab[])
{
  SDL_BlitSurface(h.tab[0][0],NULL,Tab[0],&h.position);

}

/**
* @brief Afficher 1ere background .
* @param *Tab[] for Surface
* @param pos[] for Rectangle
* @return Nothing
*/

void affiche1(SDL_Surface *Tab[],SDL_Rect pos[])
{

SDL_BlitSurface(Tab[1],&pos[0],Tab[0],NULL);

}

/**
* @brief Afficher 2eme background .
* @param *Tab[] for Surface
* @param pos[] for Rectangle
* @return Nothing
*/

void affiche2(SDL_Surface *Tab[],SDL_Rect pos[])
{

SDL_BlitSurface(Tab[4],&pos[3],Tab[0],NULL);
}

/**
* @brief Afficher diamant .
* @param d for score
* @param *Tab[] for Surface
* @return Nothing
*/

void affiche_diamond (score *d, SDL_Surface *Tab[])
{

  SDL_BlitSurface(d->dmd,NULL,Tab[0],&d->posd);

}

/**
* @brief Afficher coeur.
* @param v for vie
* @param *Tab[] for Surface
* @return Nothing
*/

void affiche_heart (vie *v, SDL_Surface *Tab[])
{
  
  SDL_BlitSurface(v->hrt,NULL,Tab[0],&v->posh);

}


/**
* @brief Afficher obstacles .
* @param e for es
* @param *Tab[] for Surface
* @param a for int
* @param c for int
* @param relativobj for Rectangle
* @param relativobj2 for Rectangle
* @return Nothing
*/

void affiche_ents (es *e, SDL_Surface *Tab[], int a, int c, SDL_Rect relativobj,SDL_Rect relativobj2)
{
  
  SDL_BlitSurface(e->obj[0],NULL,Tab[0],&relativobj);
  SDL_BlitSurface(e->obj[1],NULL,Tab[0],&relativobj2);
}


/**
* @brief Afficher enigme .
* @param e for enigme2
* @param *Tab[] for Surface
* @return Nothing
*/

void afficher_enigme (enigme2 e,SDL_Surface *Tab[])
{
  
  
 SDL_BlitSurface(e.img[0],NULL,Tab[0],&e.posimg[0]);
 SDL_Flip(Tab[0]);


}

/**
* @brief Afficher cards enigme .
* @param e for enigme2
* @param *Tab[] for Surface
* @return Nothing
*/

void afficher_card (enigme2 e,SDL_Surface *Tab[])
{
  
  
 SDL_BlitSurface(e.card[0],NULL,Tab[0],&e.poscard[0]);
 SDL_Flip(Tab[0]);


}


/**
* @brief Afficher temps .
* @param *t for temps
* @param *Tab[] for Surface
* @return Nothing
*/

void afficher_temps(temps *t,SDL_Surface *Tab[])
{	
 SDL_Color couleurBleue= {0,0, 255};

 time(&(t->t2));// temps actuel

 t->secondesEcoulees = t->t2 - t->t1;
       
 sprintf(t->entree,"%02d:%02d",(t->secondesEcoulees/60)%60, (t->secondesEcoulees)%60);
      

  t->texte = TTF_RenderUTF8_Solid(t->police, t->entree, couleurBleue);
           

  SDL_BlitSurface(t->texte, NULL, Tab[0], &(t->position));
  SDL_Flip(Tab[0]);

}


/**
* @brief Afficher bouton score .
* @param *st for store
* @param *Tab[] for Surface
* @return Nothing
*/

void affiche_bouton_store (store *st, SDL_Surface *Tab[])
{
  SDL_BlitSurface(st->button[0],NULL,Tab[0],&st->posbtn[0]);

}


/**
* @brief Afficher store .
* @param *st for store
* @param *Tab[] for Surface
* @return Nothing
*/

void affiche_store (store *st, SDL_Surface *Tab[])
{
  SDL_BlitSurface(st->image[0],NULL,Tab[0],&st->position[0]);
}


/**
* @brief Afficher store1 .
* @param *Tab[] for Surface
* @param *st for store
* @param *dkhal for integer
* @param motion_a for integer
* @param motion_b for integer
* @return Nothing
*/
void aff_store_1 (SDL_Surface *Tab[], store st, int *dkhal, int motion_a, int motion_b,  hero *h, int tm)
{
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
       affiche_store (&st,Tab);

       sprintf(sc,"Score: %d",h->score);
       text1 = TTF_RenderText_Blended(po1,sc, couleurBlanche1);
       SDL_BlitSurface(text1, NULL, Tab[0], &position_msg1);

       SDL_Flip(Tab[0]);

       *dkhal=1; //dkhal
       SDL_Delay (tm);
     } 
     else
       *dkhal=0; //madkhalch
}


/**
* @brief Afficher bouton help .
* @param *st for store
* @param *Tab[] for Surface
* @return Nothing
*/

void affiche_button_help (store *st, SDL_Surface *Tab[])
{
  SDL_BlitSurface(st->button[1],NULL,Tab[0],&st->posbtn[1]);

}


/**
* @brief Afficher help .
* @param *st for store
* @param *Tab[] for Surface
* @param motion_a for integer
* @param motion_b for integer
* @return Nothing
*/
void afficher_help (store *st, SDL_Surface *Tab[], int motion_a, int motion_b)
{
  if (motion_a>0 && motion_a<30 && motion_b>490 && motion_b<510)
  {
    SDL_BlitSurface(st->image[1],NULL,Tab[0],&st->position[1]);
    SDL_Flip(Tab[0]);
    SDL_Delay (3000);
  }
}
