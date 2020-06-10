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
* @file [save.c].
* @author : Cyrine Trabelsi
* @brief : Game Project
* @date : 2020/05/29
* @version 1
*/


/**
* @brief To Save game infos .
* @param * nomFich for Character
* @param *h for hero
* @param pos[] for Rectangle
* @param d for score
* @param v for vie
* @param b[] for Integer
* @return Nothing
*/
void SaveGame(char* nomFich,hero *h,SDL_Rect pos[],score d,vie v,int b[])
{
FILE* f=NULL;
f=fopen(nomFich,"w");
fprintf(f,"%d %d %d %d %d %hd %hd\n",h->score,h->vie,b[0],b[1],b[2],h->position.x,h->position.y);
/*fprintf(f,"%hd %hd %hd %hd %hd %hd\n",position.x,position.y,b.position_collision.x,b.position_collision.y,b.scroll.x,b.scroll.y);*/
fclose(f);
}


/**
* @brief To Load game infos .
* @param * nomFich for Character
* @param *h for hero
* @param pos[] for Rectangle
* @param d for score
* @param v for vie
* @param b[] for Integer
* @return Nothing
*/
void LoadGame(char* nomFich,hero *h,SDL_Rect pos[],score d,vie v,int b[])
{
FILE* f=NULL;
f=fopen(nomFich,"r");
fscanf(f,"%d %d %d %d %d %hd %hd\n",h->score,h->vie,b[0],b[1],b[2],h->position.x,h->position.y);
/*fscanf(f,"%hd %hd %hd %hd %hd %hd\n",&b->position.x,&b->position.y,&b->position_collision.x,&b->position_collision.y,&b->scroll.x,&b->scroll.y);*/
fclose(f);
}

/**
* @brief To Save level infos .
* @param * nomFich for Character
* @param x for Integer
* @return Nothing
*/
void SaveGamestage(char* nomFich,int x)
{
FILE* f=NULL;
f=fopen(nomFich,"w");
fprintf(f,"%d \n",x);
fclose(f);
}

/**
* @brief To Load level infos .
* @param * nomFich for Character
* @param x for Integer
* @return Nothing
*/
void LoadGamestage(char* nomFich,int *x)
{
FILE* f=NULL;
f=fopen(nomFich,"r");
fscanf(f,"%d \n",x);
fclose(f);
}
