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
* @file [gestion_temps.c].
* @author : Cyrine Trabelsi
* @brief : Game Project
* @date : 2020/05/29
* @version 1
*/

/**
* @brief To manage game's time .
* @param tmps for temps
* @return Integer
*/
int gestion_temps_jeu (temps tmps)
{

  if ((tmps.secondesEcoulees/60)%60 == 7) //15 minutes
    return 0;
  else 
    return 1;
}

/**
* @brief To manage enigma's time .
* @return Nothing
*/
int gestion_temps_enigme (temps *t)
{ 
  
  if ((t->secondesEcoulees/60)%60 == 1) //1 minute
    return 0;
  else 
    return 1;
}

/**
* @brief To manage game's end .
* @return Integer
*/
int cond_fin_jeu (int vv, hero *h, temps t)
{ 
 int continuer;
 if (vv==1)
 { 
  h->etat=1;
  continuer=0;
 }
 else if (gestion_temps_jeu (t)==0)
 { 
  continuer=0;
 }
 else if (h->nb_enigmes==h->nb_enigmes_max)
 {
  continuer=0;
 }

 else 
 continuer =1;

 return continuer;
}

