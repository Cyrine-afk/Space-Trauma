#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include "headers.h"



void initialisestat(SDL_Surface *Tab[],SDL_Rect pos[])
{

Tab[1]=IMG_Load("station.png");


//Tab[2]=IMG_Load("hero2.png");


Tab[3]=IMG_Load("doura station.png");

Tab[4]=IMG_Load("doura station.png");

Tab[5]=IMG_Load("doura station.png");

pos[0].x=0;
pos[0].y=0;
pos[0].w=730;
pos[0].h=533;

/*
pos[2].x=10;
pos[2].y=220;
pos[2].w=150;
pos[2].h=200;
*/


pos[3].x=515; //obstacle1 515
pos[3].y=390;


pos[4].x=890; //obstacle2
pos[4].y=390;

pos[5].x=1280; //obstacle3
pos[5].y=390;

/*
Tab[5]=IMG_Load("hajra map 3.png");



Tab[6]=IMG_Load("diamon.png");

Tab[3]=IMG_Load("doura station.png");


Tab[4]=IMG_Load("walk.png");

Tab[7]=IMG_Load("bat.png");


m->map[0]=IMG_Load("miniwitches.png");
m->map[2]=IMG_Load("image-01.png");
m->map[1]=IMG_Load("minimap2.png");











pos[6].x=1360;  // diamond
pos[6].y=164;


pos[3].x=2650; //portal
pos[3].y=418;


pos[4].x=0; //hajra
pos[4].y=420;


pos[7].x=1000; //bat
pos[7].y=215;


m->posmap[2].x=15; //minimap
m->posmap[2].y=90;



pos[1].x=0;
pos[1].y=0;
pos[1].w=700;
pos[1].h=570;

*/










/*
m->posmap[0].x=0;
m->posmap[0].y=0;
m->posmap[0].w=100;   // mini map 1
m->posmap[0].h=150;

m->posmap[1].x=0;
m->posmap[1].y=0;   // mini map2
m->posmap[1].w=100;
m->posmap[1].h=150;





*/



}


_Bool colisionstat(SDL_Rect *rec1,SDL_Rect *rec2)
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

int colsstat(SDL_Rect pos ,SDL_Rect pos2)
{
if((pos.x+pos.w < pos2.x) || (pos.x > pos2.x + pos2.w) || (pos.y+pos.h < pos2.y) || (pos.y > pos2.y + pos2.h))  
 
return 0;

else

return 1;



}


void affichestat(SDL_Surface *Tab[],SDL_Rect pos[],SDL_Surface *screen)
{


SDL_BlitSurface(Tab[1],&pos[0],screen,NULL);

/*
SDL_BlitSurface(Tab[4],NULL,Tab[0],&pos[4]);

SDL_BlitSurface(Tab[3],NULL,Tab[0],&pos[3]);
*/


}


void main()
{

hero h;
hero2 h2;

int x=1,t=1,y=0,p=0,k=0,verif=0,c=0,e=0,v=0,l=0,ba=0,g=0,n1=0,n2=0,n3=0;
SDL_Surface *Tab[13];
SDL_Surface *screen;
SDL_Rect pos[13];
SDL_Event event;
int a;
const int speed=4;
const int speed2=15;

int noah=0; 
int kevin=0;
int hero=0;
int fin=0;

SDL_Rect max;
max.y=450; //definition niveau sol
int q;

int no,ke;

_Bool b[5]={0,0,0,0,0};







if(SDL_Init(SDL_INIT_VIDEO)!=0)
{
printf("Unable :%s\n",SDL_GetError());
}

screen=SDL_SetVideoMode(730,530,0,SDL_SWSURFACE|SDL_DOUBLEBUF);

initialisestat(Tab,pos);

initialiser_personnage(&h);

initialiser_personnage2(&h2);

while(x==1)
{


SDL_PollEvent(&event);

switch(event.type)
{
case SDL_QUIT:
x=0;
break;
case SDL_MOUSEBUTTONDOWN:
no=event.motion.x;
ke=event.motion.y;
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

      case SDLK_SPACE:
      b[4]=1;
      break;

     } // end switch event key
    break;

    /*
     case SDL_MOUSEBUTTONUP:
     flag_store=0;
     break;   
*/

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

      case SDLK_SPACE:
      b[4]=0;
      break;
    }// end switch key up
     break;


}// end switch (event type)
/*************/
affichestat(Tab,pos,screen);
/**************/



//motion

if(hero==0)
{

if(no >8 && no<125 && ke>208 && ke<250)
{

noah=1;

hero=1;

}



else if(no>143 && no<260 && ke>208 && ke<250)
{

kevin=1;

hero=1;

}

}//hero




SDL_Rect location ={a,c,730,530};

SDL_Rect relativ ={pos[3].x-a,pos[3].y-c};

SDL_Rect relativ2 ={pos[4].x-a,pos[4].y-c};

SDL_Rect relativ3 ={pos[5].x-a,pos[5].y-c};

if(colisionstat(&location,&pos[3])) // screen obstacle1
{



SDL_BlitSurface(Tab[3],NULL,screen,&relativ);


/*
if(n1==0)
{
if(cols(h.position,relativ) || colsstat(h2.position,relativ))
{


printf("sahra");


n1=mapsahra(screen,noah,kevin,&fin);


if(fin==1)
x=0;

}



}*/

}

if(colisionstat(&location,&pos[4])) // screen obstacle2
{


SDL_BlitSurface(Tab[4],NULL,screen,&relativ2);


/*
if(n2==0)
{
if(colsstat(h.position,relativ2) || colsstat(h2.position,relativ2))
{

printf("witches");

n2=mapwitches(screen,noah,kevin,&fin);

if(fin==1)
x=0;


}

}*/

}

if(colisionstat(&location,&pos[5])) // screen obstacle3
{

SDL_BlitSurface(Tab[5],NULL,screen,&relativ3);

if(n3==0)
{
if(colsstat(h.position,relativ3) || colsstat(h2.position,relativ3))
{

printf("robots");


n3=maprobots(screen,noah,kevin,&fin);

if(fin==1)
x=0;



}

}

}

//SDL_BlitSurface(Tab[2],NULL,Tab[0],&pos[2]);
/****************/
if(b[0])
{

a+=speed;
pos[0].x+=speed;
/*
if(cols(pos[2],relativ))
{
m.posmap[2].x-=1;
a-=speed;
pos[0].x-=speed;
}
*/
if(pos[0].x>=1500-400)
{
pos[0].x=1500-400;
a=1500-400;
}

}




//////////////
 if(b[1])
{

a-=speed;
pos[0].x-=speed;
/*
if(cols(pos[2],relativ))
{
m.posmap[2].x+=1;
a+=speed;
pos[0].x+=speed;
}
*/
if(pos[0].x<=0)
{
pos[0].x=0;
a=0;
}

}

if(noah==1)
{
 if(b[0])
    {
     if(h.position.x<=200)
     h.position.x+=speed;


     else if(pos[0].x>=2500-400)
     {
      h.position.x+=speed;
     }
    }





h.position.y+=h.gravite;
h.gravite++;

if (h.gravite==20 )
			{h.gravite=20;}

	if(h.position.y + 150 >= max.y)
		{
			h.gravite=0;
			h.position.y=max.y-150;

		}
if(b[4]==1){
                        h.position.y-=speed2;
     							 }
if(b[1]==1){
h.position.x=-speed;
    

                          q=1
;
                            if(noah==1)
                            animer_personnage(&h,q);
                             

                             if(kevin==1)
                                  animer_personnage2(&h2,q);
}

if(b[0]==1){
                          q=0;
                             
                              if(noah==1)
                            animer_personnage(&h,q);

                               if(kevin==1)
                                  animer_personnage2(&h2,q);
                                 
}
//

if(noah==1)
afficher_personnage(h,screen);

if(kevin==1)
afficher_personnage2(h2,screen);

}


if(kevin==1)
{
 if(b[0])
    {
     if(h2.position.x<=200)
     h2.position.x+=speed;


     else if(pos[0].x>=2500-400)
     {
      h2.position.x+=speed;
     }
    }





h2.position.y+=h2.gravite;
h2.gravite++;

if (h2.gravite==20 )
			{h2.gravite=20;}

	if(h2.position.y + 150 >= max.y)
		{
			h2.gravite=0;
			h2.position.y=max.y-150;

		}
if(b[4]==1){
                        h2.position.y-=speed2;
     							 }
if(b[1]==1){
h2.position.x=-speed;
    

                          q=1
;
                            if(noah==1)
                            animer_personnage(&h,q);
                             

                             if(kevin==1)
                                  animer_personnage2(&h2,q);
}

if(b[0]==1){
                          q=0;
                             
                              if(noah==1)
                            animer_personnage(&h,q);

                               if(kevin==1)
                                  animer_personnage2(&h2,q);
                                 
}
//

if(noah==1)
afficher_personnage(h,screen);

if(kevin==1)
afficher_personnage2(h2,screen);
}



SDL_Flip(screen);



}//while



SDL_FreeSurface(Tab[1]);

SDL_FreeSurface(Tab[3]);

SDL_FreeSurface(Tab[4]);

SDL_FreeSurface(Tab[5]);





}

