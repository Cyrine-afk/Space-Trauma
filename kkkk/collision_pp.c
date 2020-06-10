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
* @file [collision_pp.c].
* @author : Ahmed Missaoui
* @brief : Game Project
* @date : 2020/05/29
* @version 1
*/

SDL_Color getpixel(SDL_Surface *Tab[],int x,int y)
{
SDL_Color color;
Uint32 col=0;
char *position=(char*)Tab[3]->pixels;

position +=(Tab[3]->pitch*y);

position +=(Tab[3]->format->BytesPerPixel*x);

memcpy(&col,position,Tab[3]->format->BytesPerPixel);

SDL_GetRGB(col,Tab[3]->format,&color.r,&color.g,&color.b);

return (color);


}


int colis(SDL_Surface *Tab[],SDL_Rect pos[], hero h)
{
int verif=0;
int i;
SDL_Color color[8];

color[0]=getpixel(Tab,pos[1].x+h.position.x,pos[1].y+h.position.y);

color[1]=getpixel(Tab,pos[1].x+h.position.x+(int)h.position.w/2,pos[1].y+h.position.y);

color[2]=getpixel(Tab,pos[1].x+h.position.x+h.position.w,pos[1].y+h.position.y);

color[3]=getpixel(Tab,pos[1].x+h.position.x,pos[1].y+h.position.y+(int)h.position.h/2);

color[4]=getpixel(Tab,pos[1].x+h.position.x,pos[1].y+h.position.y+h.position.h);

color[5]=getpixel(Tab,pos[1].x+h.position.x+(int)h.position.w/2,pos[1].y+h.position.y+h.position.h);

color[6]=getpixel(Tab,pos[1].x+h.position.x+h.position.w,pos[1].y+h.position.y+h.position.h);

color[7]=getpixel(Tab,pos[1].x+h.position.x+h.position.w,pos[1].y+h.position.y+(int)h.position.h/2);

for(i=0;i<8;i++)
{
if((color[i].r==0)&&(color[i].g==0)&&(color[i].b==0))
{

verif=1;
break;

}//if
}//for

return verif;
}




SDL_Color getpixel2(SDL_Surface *Tab[],int x,int y)
{
SDL_Color color;
Uint32 col=0;
char *position=(char*)Tab[5]->pixels;

position +=(Tab[5]->pitch*y);

position +=(Tab[5]->format->BytesPerPixel*x);

memcpy(&col,position,Tab[5]->format->BytesPerPixel);

SDL_GetRGB(col,Tab[5]->format,&color.r,&color.g,&color.b);

return (color);


}


int colis2(SDL_Surface *Tab[],SDL_Rect pos[], hero h)
{
int verif=0;
int i;
SDL_Color color[8];

color[0]=getpixel2(Tab,pos[4].x+h.position.x,pos[4].y+h.position.y);

color[1]=getpixel2(Tab,pos[4].x+h.position.x+(int)h.position.w/2,pos[4].y+h.position.y);

color[2]=getpixel2(Tab,pos[4].x+h.position.x+pos[4].w,pos[1].y+h.position.y);

color[3]=getpixel2(Tab,pos[4].x+h.position.x,pos[4].y+h.position.y+(int)h.position.h/2);

color[4]=getpixel2(Tab,pos[4].x+h.position.x,pos[4].y+h.position.y+h.position.h);

color[5]=getpixel2(Tab,pos[4].x+h.position.x+(int)h.position.w/2,pos[4].y+h.position.y+h.position.h);

color[6]=getpixel2(Tab,pos[4].x+h.position.x+h.position.w,pos[4].y+h.position.y+h.position.h);

color[7]=getpixel2(Tab,pos[4].x+h.position.x+h.position.w,pos[4].y+h.position.y+(int)h.position.h/2);

for(i=0;i<8;i++)
{
if((color[i].r==0)&&(color[i].g==0)&&(color[i].b==0))
{

verif=1;
break;

}//if
}//for

return verif;
}

