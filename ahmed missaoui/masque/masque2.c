
/**
@file [<masque2.c>]
*@brief scrolling/colision
*@author jjs team
*@date 30/05/2020

*/

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include "masque3.h"

/**
* @brief to initialize 
* @param Tab[] the images
* @param m the minimaps
* @return nothing
 
*/
void initialise(SDL_Surface *Tab[],SDL_Rect pos[],map *m)
{

Tab[1]=IMG_Load("map3.png");
Tab[2]=IMG_Load("hero2.png");
Tab[3]=IMG_Load("map9masque.png");

Tab[4]=IMG_Load("inside.png");

Tab[5]=IMG_Load("inside3.png");
Tab[6]=IMG_Load("diamon.png");

m->map[0]=IMG_Load("minimap1.png");
m->map[1]=IMG_Load("minimap2.png");
m->map[2]=IMG_Load("image-01.png");




pos[0].x=0;
pos[0].y=0;
pos[0].w=700;
pos[0].h=570;


pos[1].x=0;
pos[1].y=0;
pos[1].w=700;
pos[1].h=570;

pos[2].x=10;
pos[2].y=300;
pos[2].w=150;
pos[2].h=200;

pos[3].x=0;
pos[3].y=0;
pos[3].w=700;
pos[3].h=570;

pos[4].x=0;
pos[4].y=0;
pos[4].w=700;
pos[4].h=570;

pos[5].x=150;
pos[5].y=150;//diamond1




m->posmap[0].x=0;
m->posmap[0].y=0;
m->posmap[0].w=100;   // mini map 1
m->posmap[0].h=150;

m->posmap[1].x=0;
m->posmap[1].y=0;   // mini map2
m->posmap[1].w=100;
m->posmap[1].h=150;


m->posmap[2].x=15;
m->posmap[2].y=150;






}


/**
* @brief to return the color of a pixel
* @param img the images 
* @param m the minimaps
* @param x int
* @param y int
* @return color
 
*/

SDL_Color getpixel(SDL_Surface *img,int x,int y)
{
SDL_Color color;
Uint32 col=0;
char *position=(char*)img->pixels;

position +=(img->pitch*y);

position +=(img->format->BytesPerPixel*x);

memcpy(&col,position,img->format->BytesPerPixel);

SDL_GetRGB(col,img->format,&color.r,&color.g,&color.b);

return (color);


}


/**
* @brief to make colision
* @param img the images 
* @param pos[] the rect:position of the hero
* @return int :1 or 0
 
*/


int colis(SDL_Surface *Tab[],SDL_Rect pos[])
{
int verif=0;
int i;
SDL_Color color[8];

color[0]=getpixel(Tab[3],pos[1].x+pos[2].x,pos[1].y+pos[2].y);

color[1]=getpixel(Tab[3],pos[1].x+pos[2].x+(int)pos[2].w/2,pos[1].y+pos[2].y);

color[2]=getpixel(Tab[3],pos[1].x+pos[2].x+pos[2].w,pos[1].y+pos[2].y);

color[3]=getpixel(Tab[3],pos[1].x+pos[2].x,pos[1].y+pos[2].y+(int)pos[2].h/2);

color[4]=getpixel(Tab[3],pos[1].x+pos[2].x,pos[1].y+pos[2].y+pos[2].h);

color[5]=getpixel(Tab[3],pos[1].x+pos[2].x+(int)pos[2].w/2,pos[1].y+pos[2].y+pos[2].h);

color[6]=getpixel(Tab[3],pos[1].x+pos[2].x+pos[2].w,pos[1].y+pos[2].y+pos[2].h);

color[7]=getpixel(Tab[3],pos[1].x+pos[2].x+pos[2].w,pos[1].y+pos[2].y+(int)pos[2].h/2);

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



int colis2(SDL_Surface *Tab[],SDL_Rect pos[])
{
int verif=0;
int i;
SDL_Color color[8];

color[0]=getpixel(Tab[5],pos[4].x+pos[2].x,pos[4].y+pos[2].y);

color[1]=getpixel(Tab[5],pos[4].x+pos[2].x+(int)pos[2].w/2,pos[4].y+pos[2].y);

color[2]=getpixel(Tab[5],pos[4].x+pos[2].x+pos[4].w,pos[1].y+pos[2].y);

color[3]=getpixel(Tab[5],pos[4].x+pos[2].x,pos[4].y+pos[2].y+(int)pos[2].h/2);

color[4]=getpixel(Tab[5],pos[4].x+pos[2].x,pos[4].y+pos[2].y+pos[2].h);

color[5]=getpixel(Tab[5],pos[4].x+pos[2].x+(int)pos[2].w/2,pos[4].y+pos[2].y+pos[2].h);

color[6]=getpixel(Tab[5],pos[4].x+pos[2].x+pos[2].w,pos[4].y+pos[2].y+pos[2].h);

color[7]=getpixel(Tab[5],pos[4].x+pos[2].x+pos[2].w,pos[4].y+pos[2].y+(int)pos[2].h/2);

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


/**
* @brief to blit the images
* @param Tab[] the images 
* @param pos[] the rect:position of the hero
* @return nothing
 
*/

void affiche1(SDL_Surface *Tab[],SDL_Rect pos[])
{

SDL_BlitSurface(Tab[3],&pos[1],Tab[0],NULL);
SDL_BlitSurface(Tab[1],&pos[0],Tab[0],NULL);
SDL_BlitSurface(Tab[2],NULL,Tab[0],&pos[2]);
SDL_BlitSurface(Tab[6],NULL,Tab[0],&pos[5]);



}

/**
* @brief to blit the images
* @param Tab[] the images 
* @param pos[] the rect:position of the hero
* @return nothing
 
*/

void affiche2(SDL_Surface *Tab[],SDL_Rect pos[])
{


SDL_BlitSurface(Tab[5],&pos[4],Tab[0],NULL);
SDL_BlitSurface(Tab[4],&pos[3],Tab[0],NULL);
SDL_BlitSurface(Tab[2],NULL,Tab[0],&pos[2]);


}

/**
* @brief to blit the images
* @param Tab[] the images 
* @param m the images of minimap1
* @return nothing
 
*/

void affichemap1(SDL_Surface *Tab[],map m)
{

SDL_BlitSurface(m.map[0],NULL,Tab[0],&m.posmap[0]);
SDL_BlitSurface(m.map[2],NULL,Tab[0],&m.posmap[2]);

}


/**
* @brief to blit the images
* @param Tab[] the images 
* @param m the images of minimap2
* @return nothing
 
*/

void affichemap2(SDL_Surface *Tab[],map m)
{

SDL_BlitSurface(m.map[1],NULL,Tab[0],&m.posmap[1]); 
SDL_BlitSurface(m.map[2],NULL,Tab[0],&m.posmap[2]);

}



