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
* @file [initialiser.c].
* @author : JJS
* @brief : Game Project
* @date : 2020/05/29
* @version 1
*/


/**
* @brief Initialize hero .
* @param *h for hero
* @return Nothing
*/

void initialiser_personnage(hero *h)
{
   h->score=10;
   h->vie=2;
   h->nb_enigmes_max=4;
   h->nb_enigmes=0;
   h->etat=0;
   //h->lifem=3;
  //init image
   //init Right walk
    h->tab[0][0]=IMG_Load("./noah/pos1.png");
    h->tab[0][1]=IMG_Load("./noah/pos2.png");
    h->tab[0][2]=IMG_Load("./noah/pos3.png");
    h->tab[0][3]=IMG_Load("./noah/pos4.png");
    //init Left walk
    h->tab[1][0]=IMG_Load("./noah/pos1(1).png");
    h->tab[1][1]=IMG_Load("./noah/pos2(1).png");
    h->tab[1][2]=IMG_Load("./noah/pos3(1).png");
    h->tab[1][3]=IMG_Load("./noah/pos4(1).png");


   // h->imgA=IMG_Load("./noah/pos1.png");
  //init position
  h->position.x=0;
  h->position.w=125;
  h->position.h=125;
  h->position.y=0;
  //num
  h->num_image=0;
  h->gravite=5;
}


/**
* @brief Initialize maps .
* @param *Tab[] for Surface
* @param pos[] for Rectangle
* @return Nothing
*/

void initialise(SDL_Surface *Tab[],SDL_Rect pos[])
{

Tab[1]=IMG_Load("./levels/map1.png");

Tab[4]=IMG_Load("./levels/map2.png");



pos[0].x=0;
pos[0].y=0;
pos[0].w=730;
pos[0].h=530;


pos[1].x=0;
pos[1].y=0;
pos[1].w=730;
pos[1].h=530;


pos[3].x=0;
pos[3].y=0;
pos[3].w=730;
pos[3].h=530;

pos[4].x=0;
pos[4].y=0;
pos[4].w=730;
pos[4].h=530;

}



/**
* @brief Initialize obstacles .
* @param *e for es
* @return Nothing
*/

void initialiser(es *e)
{
e->obj[0]=IMG_Load("./objects/fire.png"); 
e->obj[1]=IMG_Load("./objects/ev.png");

//position 
e->posobj[0].x=1100;
e->posobj[0].y=310;

e->posobj[1].x=1312;
e->posobj[1].y=200;

}



/**
* @brief Initialize diamonds .
* @param *d for score
* @return Nothing
*/

void init_dms (score *d)
{
int k=0;

  d->dmd= IMG_Load("./objects/dmd0.png");

  d->image[0]=IMG_Load("./objects/dmd1.png"); 
  d->image[1]=IMG_Load("./objects/dmd2.png");
  d->image[2]=IMG_Load("./objects/dmd3.png");
  d->image[3]=IMG_Load("./objects/dmd4.png");
  d->image[4]=IMG_Load("./objects/dmd5.png");
  d->image[5]=IMG_Load("./objects/dmd6.png");
  d->image[6]=IMG_Load("./objects/dmd7.png");
  d->image[7]=IMG_Load("./objects/dmd8.png");

  d->posd.x=0;
  d->posd.y=10;

  d->position[0].x=273;
  d->position[0].y=357;
  d->position[0].w=45;
  d->position[0].h=40;

  d->position[1].x=628;
  d->position[1].y=357;
  d->position[1].w=45;
  d->position[1].h=40;

  d->position[2].x=1100;
  d->position[2].y=275;
  d->position[2].w=45;
  d->position[2].h=40;
 
  d->position[3].x=1549;
  d->position[3].y=357;
  d->position[3].w=45;
  d->position[3].h=40;

  d->position[4].x=1836;
  d->position[4].y=377;
  d->position[4].w=45;
  d->position[4].h=40;

  d->position[5].x=200;
  d->position[5].y=400;
  d->position[5].w=45;
  d->position[5].h=40;
 
  d->position[6].x=500;
  d->position[6].y=400;
  d->position[6].w=45;
  d->position[6].h=40;

  d->position[7].x=900;
  d->position[7].y=400;
  d->position[7].w=45;
  d->position[7].h=40;

  for (k=0;k<20;k++)
{
 d->tab[k]=0;
}
}



/**
* @brief Initialize hearts .
* @param *v for vie
* @return Nothing
*/

void init_hearts (vie *v)
{
  int k,i;

  v->hrt=IMG_Load("./objects/coeur0.png");
 
  v->image[0]=IMG_Load("./objects/coeur2.png"); 
  v->image[1]=IMG_Load("./objects/coeur2.png");

  v->posh.x=0;
  v->posh.y=45;

  v->position[0].x=2208;
  v->position[0].y=179;
 
  v->position[1].x=60;
  v->position[1].y=450;

  for (k=0;k<10;k++)
  {
   v->tab[k]=0;
  }
  
  for (i=0;i<20;i++)
  {
   v->tab2[i]=0;
  }
}



/**
* @brief Initialize enigma2's cards .
* @param *en for enigme2
* @return Nothing
*/

void init_card (enigme2 *e)
{
    
   e->poscard[0].x=0; 
   e->poscard[0].y=0;
   
   e->card[0]=SDL_LoadBMP("./enigmes/em2.bmp");
        if(e->card[0]==NULL)
{
printf("erreur fel taswiret el cards:%s\n",SDL_GetError());

}

}




/**
* @brief Initialize enigma2 .
* @param *en for enigme2
* @return Nothing
*/

void init_enigmee(enigme2 *e)
{

 
    


    e->posimg[0].x=0; 
    e->posimg[0].y=0; //graph
    e->posimg[1].x=0;
    e->posimg[1].y=0;    //win
    e->posimg[2].x=0; //lose
    e->posimg[2].y=0;
    e->posbox[0].x=153;
    e->posbox[0].y=312;  //ts1
    e->posbox[1].x=205;
    e->posbox[1].y=312; //ts2
    e->posbox[2].x=257;
    e->posbox[2].y=312; //ts3


    
    
        

    	
e->img[0]=SDL_LoadBMP("./enigmes/em3.bmp");
        if(e->img[0]==NULL)
{
printf("erreur graph:%s\n",SDL_GetError());

}

        e->img[1]=SDL_LoadBMP("./enigmes/win.bmp");
        if(e->img[1]==NULL)
{
printf("erreur win:%s\n",SDL_GetError());

}

e->img[2]=SDL_LoadBMP("./enigmes/lose.bmp");
if(e->img[2]==NULL)
{
printf("erreur lose:%s\n",SDL_GetError());

}


  e->nm[0]=IMG_Load("./enigmes/0.png");
        if(e->nm[0]==NULL)
{
printf("erreur fel 0:%s\n",SDL_GetError());

}

e->nm[1]=IMG_Load("./enigmes/1.png");
        if(e->nm[1]==NULL)
{
printf("erreur fel 1:%s\n",SDL_GetError());

}

e->nm[2]=IMG_Load("./enigmes/2.png");
        if(e->nm[2]==NULL)
{
printf("erreur fel 2:%s\n",SDL_GetError());

}

e->nm[3]=IMG_Load("./enigmes/3.png");
        if(e->nm[3]==NULL)
{
printf("erreur fel 3:%s\n",SDL_GetError());

}

e->nm[4]=IMG_Load("./enigmes/4.png");
        if(e->nm[4]==NULL)
{
printf("erreur fel 4:%s\n",SDL_GetError());

}

e->nm[5]=IMG_Load("./enigmes/5.png");
        if(e->nm[5]==NULL)
{
printf("erreur fel 5:%s\n",SDL_GetError());

}

e->nm[6]=IMG_Load("./enigmes/6.png");
        if(e->nm[6]==NULL)
{
printf("erreur fel 6:%s\n",SDL_GetError());

}

e->nm[7]=IMG_Load("./enigmes/7.png");
        if(e->nm[7]==NULL)
{
printf("erreur fel 7:%s\n",SDL_GetError());

}
e->nm[8]=IMG_Load("./enigmes/8.png");
        if(e->nm[8]==NULL)
{
printf("erreur fel 8:%s\n",SDL_GetError());

}
e->nm[9]=IMG_Load("./enigmes/9.png");
        if(e->nm[9]==NULL)
{
printf("erreur fel 9:%s\n",SDL_GetError());

}


        

        e->box[0]=IMG_Load("./enigmes/ts.png");
if( e->box[0]==NULL)
{
printf("erreur ts:%s\n",SDL_GetError());

}


}


/**
* @brief Initialize enigma .
* @param *en for enigme
* @return Nothing
*/

void init_enigme(enigme * en)
{
	en->p.x=0;
	en->p.y=0;	
	en->img=NULL;
}


/**
* @brief Initialize time .
* @param *t for temps
* @return Nothing
*/

void initialiser_temps(temps *t)
{
 t->texte = NULL;
 t->position.x=650;
 t->position.y=5;
 t->police = NULL;
 t->police = TTF_OpenFont("comic1.ttf", 25);
 strcpy( t->entree,"");
 (t->secondesEcoulees)=0;
 time(&(t->t1)); 
  
 //temps du debut
}


/**
* @brief Initialize .
* @param *st for store
* @return Nothing
*/

void init_store (store *st)
{
  st->button[0]= IMG_Load("./shm/str.png");
  st->button[1]= IMG_Load("./shm/help.png");
  st->image[0]=IMG_Load("./shm/store.png"); 
  st->image[1]=IMG_Load("./shm/Help.png");

  st->posbtn[0].x=0;
  st->posbtn[0].y=510;

  st->posbtn[1].x=0;
  st->posbtn[1].y=490;

  st->position[0].x=0;
  st->position[0].y=0;

  st->position[1].x=70;
  st->position[1].y=20;
}

