
/**
 @file [<masque.c>]
*@brief scrolling/colision
*@author jjs team
*@date 30/05/2020
*/

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include "masque3.h"






int main()
{
int x=1,t=1,y=0,p=0,k=0,verif=0;
SDL_Surface *Tab[13];
SDL_Rect pos[13];
SDL_Event event;
int a;
const int speed=4;

_Bool b[4]={0,0,0,0};

map m;


if(SDL_Init(SDL_INIT_VIDEO)!=0)
{
printf("Unable :%s\n",SDL_GetError());
}

Tab[0]=SDL_SetVideoMode(700,570,0,SDL_SWSURFACE|SDL_DOUBLEBUF);

initialise(Tab,pos,&m);

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
affiche1(Tab,pos);



if(b[0])
{

a+=speed;
pos[0].x+=speed;
pos[1].x+=speed;
pos[5].x-=speed;//diamond1

if(colis(Tab,pos))
{
a-=speed;
pos[0].x-=speed;
pos[1].x-=speed;
}

if(pos[0].x>=2500-400)
{
pos[0].x=2500-400;
pos[1].x=2500-400;
}
}

 if(b[1])
{

a-=speed;
pos[0].x-=speed;
pos[1].x-=speed;

if(colis(Tab,pos))
{
a+=speed;
pos[0].x+=speed;
pos[1].x+=speed;
}

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



if(m.posmap[2].x<580)
m.posmap[2].x+=1;



if(colis(Tab,pos))
{
pos[2].x-=speed;

m.posmap[2].x-=1;
}

else if(pos[0].x>=2500-400)

pos[2].x+=speed;




}


if(b[1])
{

pos[2].x-=speed;


if(m.posmap[2].x>0)
m.posmap[2].x-=1;



if(colis(Tab,pos))
{

pos[2].x+=speed;

m.posmap[2].x+=1;

}

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







switch(event.type)
{

case SDL_KEYDOWN:

switch(event.key.keysym.sym)
{
case SDLK_m:

p=1;


break;

case SDLK_ESCAPE:

p=0;

break;

}

break;


}//switch minimap1


if(p==1)
{

affichemap1(Tab,m);

}




if(pos[2].x>=480 && pos[2].y<=510)
{
printf("okkkk");
t=0;
pos[2].x=25;
pos[2].y=300;


m.posmap[2].x=0;
m.posmap[2].y=150;

}


SDL_Flip(Tab[0]);

}//ift==1

if(t==0)
{

affiche2(Tab,pos);

if(b[0])
{
if(pos[2].x>=200)
{
a+=speed;
pos[3].x+=5;
pos[4].x+=5;

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
pos[3].x-=5;
pos[4].x-=5;

if(pos[3].x<=0)
{
pos[3].x=0;
pos[4].x=0;
}

}



if(b[0])
{
m.posmap[2].x+=1;

if(pos[2].x<200)
pos[2].x+=5;
if(colis2(Tab,pos))
{
pos[2].x-=5;
m.posmap[2].x-=1;
}

}


if(b[1])
{

pos[2].x-=5;
m.posmap[2].x-=1;
if(colis2(Tab,pos))
{
pos[2].x+=5;
m.posmap[2].x+=1;
}

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



switch(event.type)
{

case SDL_KEYDOWN:

switch(event.key.keysym.sym)
{
case SDLK_m:

k=1;


break;

case SDLK_ESCAPE:

k=0;

break;

}

break;


}//switch minimap2

if(k==1)
{

affichemap2(Tab,m);

}








SDL_Flip(Tab[0]);


}//ift==0

}//while


SDL_FreeSurface(Tab[1]);
SDL_FreeSurface(Tab[2]);
SDL_FreeSurface(Tab[3]);
SDL_FreeSurface(Tab[4]);
SDL_FreeSurface(Tab[5]);


return 0;



}
