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
* @brief : player initialition
* @date : 2020/06/09
* @version 1
*/



/**
* @brief to initialise the players .
* @param h the player 
* @return nothing
*/
void initialiser_personnage(hero *h)
{
  //init score
   h->score=10;
  //init vie
   h->vie=3;
   h->nb_enigmes=4;
   h->lifem=3;
  //init image
   //init Right
    h->tab[0][0]=IMG_Load("./noah/pos1.png");
    h->tab[0][1]=IMG_Load("./noah/pos2.png");
    h->tab[0][2]=IMG_Load("./noah/pos3.png");
    h->tab[0][3]=IMG_Load("./noah/pos4.png");
    //init Left
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
* @brief to initialise the players .
* @param h the player
* @return nothing
*/
void initialiser_personnage_hit(hero *h)
{
  //init score
   h->score=10;
  //init vie
   h->vie=3;
   h->nb_enigmes=4;
   //h->lifem=3;
  //init image
   //init Right
    h->tab2[0][0]=IMG_Load("./noah/posl(1).png");
    h->tab2[0][1]=IMG_Load("./noah/posl(2).png");
    h->tab2[0][2]=IMG_Load("./noah/posl(3).png");
    h->tab2[0][3]=IMG_Load("./noah/posl(4).png");
    //init Left
    h->tab2[1][0]=IMG_Load("./noah/posl(1).png");
    h->tab2[1][1]=IMG_Load("./noah/posl(2).png");
    h->tab2[1][2]=IMG_Load("./noah/posl(3).png");
    h->tab2[1][3]=IMG_Load("./noah/posl(4).png");

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
* @brief to initialise the players 2 .
* @param h the player
* @return nothing
*/


void initialiser_personnage_2(hero *h)
{
  //init score
   h->score=10;
  //init vie
   h->vie=3;
   h->nb_enigmes=4;
   //h->lifem=3;
  //init image
   //init Right
    h->tab3[0][0]=IMG_Load("./noah/pos10.png");
    h->tab3[0][1]=IMG_Load("./noah/pos20.png");
    h->tab3[0][2]=IMG_Load("./noah/pos30.png");
    h->tab3[0][3]=IMG_Load("./noah/pos40.png");
    //init Left
    h->tab3[1][0]=IMG_Load("./noah/pos10(1).png");
    h->tab3[1][1]=IMG_Load("./noah/pos20(1).png");
    h->tab3[1][2]=IMG_Load("./noah/pos30(1).png");
    h->tab3[1][3]=IMG_Load("./noah/pos40(1).png");

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
* @brief to initialise the bg .
* @param tab the bg
* @param pos the position of bg
* @return nothing
*/

void initialise(SDL_Surface *Tab[],SDL_Rect pos[])
{

Tab[1]=IMG_Load("./levels/map3.png");
//Tab[2]=IMG_Load("hero2.png");  // hero Ahmed
Tab[3]=IMG_Load("./levels/map8masque.png");

Tab[4]=IMG_Load("./levels/inside.png");

Tab[5]=IMG_Load("./levels/inside3.png");


pos[0].x=0;
pos[0].y=0;
pos[0].w=730;
pos[0].h=530;


pos[1].x=0;
pos[1].y=0;
pos[1].w=730;
pos[1].h=530;

/*pos[2].x=10;
pos[2].y=300;
pos[2].w=150;
pos[2].h=200;*/

pos[3].x=0;
pos[3].y=0;
pos[3].w=730;
pos[3].h=530;

pos[4].x=0;
pos[4].y=0;
pos[4].w=730;
pos[4].h=530;

}



