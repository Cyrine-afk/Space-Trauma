#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include "masque3.h"

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


int colis(SDL_Surface *Tab[],SDL_Rect pos[])
{
int verif=0;
int i;
SDL_Color color[8];

color[0]=getpixel(Tab,pos[1].x+pos[2].x,pos[1].y+pos[2].y);

color[1]=getpixel(Tab,pos[1].x+pos[2].x+(int)pos[2].w/2,pos[1].y+pos[2].y);

color[2]=getpixel(Tab,pos[1].x+pos[2].x+pos[2].w,pos[1].y+pos[2].y);

color[3]=getpixel(Tab,pos[1].x+pos[2].x,pos[1].y+pos[2].y+(int)pos[2].h/2);

color[4]=getpixel(Tab,pos[1].x+pos[2].x,pos[1].y+pos[2].y+pos[2].h);

color[5]=getpixel(Tab,pos[1].x+pos[2].x+(int)pos[2].w/2,pos[1].y+pos[2].y+pos[2].h);

color[6]=getpixel(Tab,pos[1].x+pos[2].x+pos[2].w,pos[1].y+pos[2].y+pos[2].h);

color[7]=getpixel(Tab,pos[1].x+pos[2].x+pos[2].w,pos[1].y+pos[2].y+(int)pos[2].h/2);

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


int colis2(SDL_Surface *Tab[],SDL_Rect pos[])
{
int verif=0;
int i;
SDL_Color color[8];

color[0]=getpixel2(Tab,pos[4].x+pos[2].x,pos[4].y+pos[2].y);

color[1]=getpixel2(Tab,pos[4].x+pos[2].x+(int)pos[2].w/2,pos[4].y+pos[2].y);

color[2]=getpixel2(Tab,pos[4].x+pos[2].x+pos[4].w,pos[1].y+pos[2].y);

color[3]=getpixel2(Tab,pos[4].x+pos[2].x,pos[4].y+pos[2].y+(int)pos[2].h/2);

color[4]=getpixel2(Tab,pos[4].x+pos[2].x,pos[4].y+pos[2].y+pos[2].h);

color[5]=getpixel2(Tab,pos[4].x+pos[2].x+(int)pos[2].w/2,pos[4].y+pos[2].y+pos[2].h);

color[6]=getpixel2(Tab,pos[4].x+pos[2].x+pos[2].w,pos[4].y+pos[2].y+pos[2].h);

color[7]=getpixel2(Tab,pos[4].x+pos[2].x+pos[2].w,pos[4].y+pos[2].y+(int)pos[2].h/2);

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




void initialise(SDL_Surface *Tab[],SDL_Rect pos[])
{

Tab[1]=IMG_Load("map3.png");
Tab[2]=IMG_Load("hero2.png");
Tab[3]=IMG_Load("map8masque.png");

Tab[4]=IMG_Load("inside.png");

Tab[5]=IMG_Load("inside3.png");


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

}

void affiche1(SDL_Surface *Tab[],SDL_Rect pos[])
{

SDL_BlitSurface(Tab[3],&pos[1],Tab[0],NULL);
SDL_BlitSurface(Tab[1],&pos[0],Tab[0],NULL);
SDL_BlitSurface(Tab[2],NULL,Tab[0],&pos[2]);
SDL_Flip(Tab[0]);

}

void affiche2(SDL_Surface *Tab[],SDL_Rect pos[])
{

SDL_BlitSurface(Tab[5],&pos[4],Tab[0],NULL);
SDL_BlitSurface(Tab[4],&pos[3],Tab[0],NULL);
SDL_BlitSurface(Tab[2],NULL,Tab[0],&pos[2]);
SDL_Flip(Tab[0]);

}

