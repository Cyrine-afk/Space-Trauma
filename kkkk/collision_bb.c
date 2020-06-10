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
* @file [collision_bb.c].
* @author : Ramy Ben Hassine
* @brief : Game Project
* @date : 2020/05/29
* @version 1
*/

int cols(SDL_Rect pos ,SDL_Rect pos2)
{
if((pos.x+pos.w < pos2.x) || (pos.x > pos2.x + pos2.w) || (pos.y+pos.h < pos2.y) || (pos.y > pos2.y + pos2.h))  
 
return 0;

else

return 1;

}


_Bool colision(SDL_Rect *rec1,SDL_Rect *rec2)
{
if(rec1->y >= rec2->y + rec2->h)
return 0;

if(rec1->x >= rec2->x + rec2->w)
return 0;

if(rec1->y + rec1->h  <= rec2->y)
return 0;

if(rec1->x + rec1->w  <= rec2->x)
return 0;

return 1;

}



/*int colis_es(es e)
{

if((p.pos[1].x + p.pos[1].w < p.pos[0].x)||(p.pos[1].x > p.pos[0].x + p.pos[0].w)||(p.pos[1].y + p.pos[1].h < p.pos[0].y)||(p.pos[1].y > p.pos[0].y + p.pos[0].h))
return 0;
else 
return 1;

}*/

/*int colis1(es *e, hero h) 
{

if( (h.position.x + p.imgA->w) < e->position[0].x ) //
   return 0;

else if( h.position.x > (e->position[0].x + e->imgA[0]->w) )
   return 0;

else if( (h.position.y + p.imgA->h) < e->position[0].y )//
   return 0;

else if ( h.position.y > (e->position[0].y + e->imgA[0]->h ) )//
   return 0; //pas de collision

else 
return 1; // collision

}*/
