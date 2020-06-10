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
* @file [collisionTrigo.c].
* @author : Cyrine Trabelsi
* @brief : Game Project
* @date : 2020/05/29
* @version 1
*/


/**
* @brief To check for collision with diamonds .
* @param p1 for Rectangle
* @param *d for score
* @param indice for Integer
* @return Integer
*/

int collisionTrigo(SDL_Rect p1,score *d,int indice)
{
 int i;
int xc1=p1.x+100;
int yc1=p1.y+100;
int xc2=d->position[indice].x+100;
int yc2=d->position[indice].y+100;
int a=xc1-xc2;
int b=yc1-yc2;
float h;
h=sqrt((a*a)+(b*b));
if((int)h<=150)
{
indice=i;
return 1;
}
else
return 0;
}

/**
* @brief To check for collision with hearts .
* @param p1 for Rectangle
* @param *v for vie
* @param indice for Integer
* @return Integer
*/

int collisionTrigoVie(SDL_Rect p1,vie *v,int indice)
{
 int i;
int xc1=p1.x+100;
int yc1=p1.y+100;
int xc2=v->position[indice].x+100;
int yc2=v->position[indice].y+100;
int a=xc1-xc2;
int b=yc1-yc2;
float h;
h=sqrt((a*a)+(b*b));
if((int)h<=150)
{
indice=i;
return 1;
}
else
return 0;
}

/**
* @brief To check for collision with entitee secondaire .
* @param p1 for Rectangle
* @param *e for es
* @param indice for Integer
* @return Integer
*/

int collisionTrigoEs(SDL_Rect p1,es *e,int indice)
{
 int i;
int xc1=p1.x+100;
int yc1=p1.y+100;
int xc2=e->posenm[indice].x+100;
int yc2=e->posenm[indice].y+100;
int a=xc1-xc2;
int b=yc1-yc2;
float h;
h=sqrt((a*a)+(b*b));
if((int)h<=150)
{
indice=i;
return 1;
}
else
return 0;
}

/**
* @brief To check for collision with objects .
* @param p1 for Rectangle
* @param *e for es
* @param indice for Integer
* @return Integer
*/

int collisionTrigoObj(SDL_Rect p1,es *e/*hajra*/,int indice)
{
 int i;
int xc1=p1.x+100;
int yc1=p1.y+100;
int xc2/*hajra*/=e->posobj[indice].x+100;
int yc2=e->posobj[indice].y+100;
int a=xc1-xc2;
int b=yc1-yc2;
float h;
h=sqrt((a*a)+(b*b));
if((int)h<=150)
{
indice=i;
return 1;
}
else
return 0;
}


