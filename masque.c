#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include "masque3.h"






int main()
{
int x=1,t=1,y=0;
SDL_Surface *Tab[8];
SDL_Rect pos[8];
SDL_Event event;
int a;
const int speed=2;
_Bool b[4]={0,0,0,0};


if(SDL_Init(SDL_INIT_VIDEO)!=0)
{
printf("Unable :%s\n",SDL_GetError());
}

Tab[0]=SDL_SetVideoMode(700,570,0,SDL_SWSURFACE|SDL_DOUBLEBUF);

initialise(Tab,pos);

while(x==1)
{


SDL_PollEvent(&event);
switch(event.type)
{
case SDL_QUIT:
x=0;
break;
case SDL_KEYDOWN:
switch(event.key.keysym.sym)
{
case SDLK_RIGHT:
b[0]=1;
break;
case SDLK_LEFT:
b[1]=1;
break;
case SDLK_UP:
b[2]=1;
break;
case SDLK_DOWN:
b[3]=1;
break;
}
break;
case SDL_KEYUP:
switch(event.key.keysym.sym)
{
case SDLK_RIGHT:
b[0]=0;
break;
case SDLK_LEFT:
b[1]=0;
break;
case SDLK_UP:
b[2]=0;
break;
case SDLK_DOWN:
b[3]=0;
break;

}
break;


}//switch1
if(t==1)
{
if(b[0])
{
if(pos[2].x==200)
{
a+=speed;
pos[0].x+=speed;
pos[1].x+=speed;

if(pos[0].x>=2500-400)
{
pos[0].x=2500-400;
pos[1].x=2500-400;
}
}
}
 if(b[1])
{

a-=speed;
pos[0].x-=speed;
pos[1].x-=speed;

if(pos[0].x<=0)
{
pos[0].x=0;
pos[1].x=0;
}

}



if(b[0])
{
if(pos[2].x<200)
pos[2].x+=speed;
if(colis(Tab,pos))
pos[2].x-=speed;

else if(pos[0].x>=2500-400)
{
pos[2].x+=speed;
}
}


if(b[1])
{

pos[2].x-=speed;
if(colis(Tab,pos))
pos[2].x+=speed;
}
if(b[2])
{
pos[2].y-=speed;
if(colis(Tab,pos))
pos[2].y+=speed;
}
if(b[3])
{
pos[2].y+=speed;
if(colis(Tab,pos))
pos[2].y-=speed;
}

if(pos[2].x==500 && pos[2].y<=510)
{
t=0;
pos[2].x=10;
pos[2].y=300;

}
affiche1(Tab,pos);

}//ift==1

if(t==0)
{


if(b[0])
{
if(pos[2].x==200)
{
a+=speed;
pos[3].x+=speed;
pos[4].x+=speed;

/*if(pos[0].x>=2500-400)
{
pos[3].x=2500-400;
pos[4].x=2500-400;
}*/
}
}
 if(b[1])
{

a-=speed;
pos[3].x-=speed;
pos[4].x-=speed;

if(pos[3].x<=0)
{
pos[3].x=0;
pos[4].x=0;
}

}



if(b[0])
{
if(pos[2].x<200)
pos[2].x+=speed;
if(colis2(Tab,pos))
pos[2].x-=speed;


}


if(b[1])
{

pos[2].x-=speed;
if(colis2(Tab,pos))
pos[2].x+=speed;
}
if(b[2])
{
pos[2].y-=speed;
if(colis2(Tab,pos))
pos[2].y+=speed;
}
if(b[3])
{
pos[2].y+=speed;
if(colis2(Tab,pos))
pos[2].y-=speed;
}









affiche2(Tab,pos);

}//ift==0

}//while



return 0;


}
