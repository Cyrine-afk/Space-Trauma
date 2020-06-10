#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>

void initialise(SDL_Surface *Tab[],SDL_Rect pos[])
{

Tab[1]=IMG_Load("map3.png");

Tab[2]=IMG_Load("hero2.png");

Tab[3]=IMG_Load("diamon.png");

pos[0].x=0;
pos[0].y=0;
pos[0].w=700;
pos[0].h=570;


pos[2].x=10;
pos[2].y=300;
pos[2].w=150;
pos[2].h=200;

pos[3].x=100;
pos[3].y=200;//diamond1
pos[3].w=50;
pos[3].h=50;


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

int cols(SDL_Rect pos ,SDL_Rect pos2)
{
if((pos.x+pos.w < pos2.x) || (pos.x > pos2.x + pos2.w) || (pos.y+pos.h < pos2.y) || (pos.y > pos2.y + pos2.h))  
 
return 0;

else

return 1;

}


int main()
{
int x=1,t=1,y=0,p=0,l=0;
SDL_Surface *Tab[13];
SDL_Rect pos[13];
SDL_Event event;
int a=0,c=0;
const int speed=4;
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

if(b[0])
{

a+=speed;
pos[0].x+=speed;


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






else if(pos[0].x>=2500-400)
{
pos[2].x+=speed;


}
}


if(b[1])
{

pos[2].x-=speed;



}
if(b[2])
{
pos[2].y-=speed;

}
if(b[3])
{
pos[2].y+=speed;

}




SDL_Rect location ={a,c,700,570};

SDL_Rect relativ ={pos[3].x-a,pos[3].y-c}; //diamond1

//SDL_Rect relativ2 ={pos[4].x-a,pos[4].y-c}; //diamond2

SDL_BlitSurface(Tab[1],&pos[0],Tab[0],NULL); //map

if(l==0)
{
if(colision(&location,&pos[3])) // screen diamonds
{

if(!cols(pos[2],relativ))

SDL_BlitSurface(Tab[3],NULL,Tab[0],&relativ);

else if(cols(pos[2],relativ))
{
printf("10");
l=1;
}

}//if cols location et diamond1

}//if l

SDL_BlitSurface(Tab[2],NULL,Tab[0],&pos[2]);
SDL_Flip(Tab[0]);

}//while

SDL_FreeSurface(Tab[1]);
SDL_FreeSurface(Tab[2]);
SDL_FreeSurface(Tab[3]);
return 0;
}
