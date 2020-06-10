#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"

#include "headers.h"
#include "defs.h"


void initialiseee(SDL_Surface *Tab[],SDL_Rect pos[],map *m)
{

Tab[1]=IMG_Load("witches2.png");

Tab[5]=IMG_Load("hajra map 3.png");

Tab[2]=IMG_Load("hero2.png");

Tab[6]=IMG_Load("diamon.png");

Tab[3]=IMG_Load("doura station.png.png");


Tab[4]=IMG_Load("question.png");

Tab[7]=IMG_Load("bat.png");


m->map[0]=IMG_Load("miniwitches.png");
m->map[2]=IMG_Load("image-01.png");

/*

m->map[1]=IMG_Load("minimap2.png");

*/



pos[0].x=0;
pos[0].y=0;
pos[0].w=730;
pos[0].h=533;


pos[5].x=1350; //hajra
pos[5].y=205;

pos[2].x=10;
pos[2].y=220;
pos[2].w=150;
pos[2].h=200;

pos[6].x=1360;  // diamond
pos[6].y=164;


pos[3].x=2650; //portal
pos[3].y=418;


pos[4].x=595; //hajra
pos[4].y=350;


pos[7].x=1000; //bat
pos[7].y=215;


m->posmap[2].x=30; //minihero
m->posmap[2].y=90;


m->posmap[0].x=0;
m->posmap[0].y=0;
m->posmap[0].w=100;   // mini map 1
m->posmap[0].h=150;


/*
pos[1].x=0;
pos[1].y=0;
pos[1].w=700;
pos[1].h=570;















m->posmap[1].x=0;
m->posmap[1].y=0;   // mini map2
m->posmap[1].w=100;
m->posmap[1].h=150;





*/



}


_Bool colisionnn(SDL_Rect *rec1,SDL_Rect *rec2)
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


int colsss(SDL_Rect pos ,SDL_Rect pos2)
{
if((pos.x+pos.w < pos2.x) || (pos.x > pos2.x + pos2.w) || (pos.y+pos.h < pos2.y) || (pos.y > pos2.y + pos2.h))  
 
return 0;

else

return 1;



}



void afficheee1(SDL_Surface *Tab[],SDL_Rect pos[],SDL_Surface *screen)
{


SDL_BlitSurface(Tab[1],&pos[0],screen,NULL);
//SDL_BlitSurface(Tab[4],NULL,Tab[0],&pos[4]);
SDL_BlitSurface(Tab[2],NULL,screen,&pos[2]);
SDL_BlitSurface(Tab[3],NULL,screen,&pos[3]);



}

void affichemapwitches(SDL_Surface *Tab[],map m,SDL_Surface *screen)
{

SDL_BlitSurface(m.map[0],NULL,screen,&m.posmap[0]);
SDL_BlitSurface(m.map[2],NULL,screen,&m.posmap[2]);

}




int mapwitches(SDL_Surface *screen ,int noah,int kevin,int *fin)
{



//init ttf
 TTF_Init();

//timer
SDL_Init(SDL_INIT_TIMER);
//.......

int x=1,t=0,y=0,p=0,k=0,verif=0,c=0,ee=0,vv=0,l=0,ba=0,g=0,o=0,w=0,engw=0,eng=0,eng2=0;
int niveau=2;
int continuer=0;

SDL_Surface *Tab[13];
SDL_Rect pos[13];
SDL_Event event;
int a=0;
const int speed=4;
const int speed2=23;

int q;
int flag_store=0;
int tm=4000;
int dkhal;
int motion_a,motion_b;

int motion_a1,motion_b1;
int bouton_save=0,SAVE=0,flag_save=0;
int check_save=1;


_Bool b[7]={0,0,0,0,0,0,0};


save sv;
es e;
vie v;
map m;
hero h;
hero2 h2;

score d;
temps tmps;
store st;
ennemie enmy;
SDL_Rect max;
max.y=425; //definition niveau sol

musique msc;


/*
if(SDL_Init(SDL_INIT_VIDEO)!=0)
{
printf("Unable :%s\n",SDL_GetError());
}

Tab[0]=SDL_SetVideoMode(730,530,0,SDL_SWSURFACE|SDL_DOUBLEBUF);
*/


//affichage ttf vies
SDL_Surface *text, *hrt;
 SDL_Rect position_msg, posh;
 TTF_Font *po;
 SDL_Surface *scr;
 SDL_Color couleurBleue = {0,0, 255}; 
 char vi[50]="";
 char nb[20]="";
 position_msg.x=27;
 position_msg.y=35;

po = TTF_OpenFont("comic1.ttf", 25);

//affichage ttf score
SDL_Rect position_msg1, posd;
 TTF_Font *po1;
 SDL_Surface *text1, *dmd;
 SDL_Color couleurBleue1 = {0,0,255}; 
 char sc[50]="";
 char nb1[20]="";
 position_msg1.x=27;
 position_msg1.y=5;

 po1 = TTF_OpenFont("comic1.ttf", 25);


/**** music ****/
//Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);


initialiseee(Tab,pos,&m);


initialiser_personnage(&h);

initialiser_personnage2(&h2);


/**** init temps ****/
initialiser_temps(&tmps);

/**** init store + help  ****/
init_store (&st);


/**** init diamonds ****/
init_dms (&d);

/**** init hearts ****/
init_hearts (&v);


 /**** save*****/

init_save(&sv);



while(x==1)
{

//musicwitches(&msc);

SDL_PollEvent(&event);

switch(event.type)
{
case SDL_QUIT:
x=0;
break;
case SDL_MOUSEBUTTONDOWN:
    flag_store=1;
    flag_save=1;
    motion_a=event.motion.x;
    motion_b=event.motion.y;
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

    
    case SDL_MOUSEBUTTONUP:
     flag_store=0;
     flag_save=0;
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

      case SDLK_SPACE:
      b[4]=0;
      break;
    }// end switch key up
     break;


}// end switch (event type)
/*************/
if(t==0)
{
afficheee1(Tab,pos,screen);

/**** bouton save ****/
afficher_bouton_save (&sv, screen);
masque_bouton_save (&sv,screen,motion_a1,motion_b1);



/**** boutons store et help ****/

affiche_bouton_store (&st,screen);
affiche_button_help (&st,screen);


/**** afficher diamonds and hearts on background ****/
affiche_diamond (&d,screen);
affiche_heart (&v,screen);



SDL_Rect location ={a,c,730,530};

SDL_Rect relativ ={pos[5].x-a,pos[5].y-c};



SDL_Rect relativ3 ={v.position[2].x-a,v.position[2].y-c};

SDL_Rect relativ4 ={pos[4].x-a,pos[4].y-c};

SDL_Rect relativ5 ={d.position[9].x-a,d.position[9].y-c}; //diamond5

SDL_Rect relativ2 ={d.position[11].x-a,d.position[11].y-c};

SDL_Rect relativ6 ={d.position[10].x-a,d.position[10].y-c}; //diamond5

SDL_Rect relativ7 ={ v.position[3].x-a,v.position[3].y-c}; //heart
 

SDL_Rect relativbat ={pos[7].x-a,pos[7].y-c};//bat

if(ba==0)
{
if(colisionnn(&location,&pos[7])) // screen bat
{
if(g==0)
{
if(!colsss(h.position,relativ3))
{
SDL_BlitSurface(Tab[7],NULL,screen,&relativ3);


pos[7].x--;

}


if(colsss(pos[2],relativ3))
g=1;
printf("life-5");

}

if(g==1)
{
pos[7].y+=4;
SDL_BlitSurface(Tab[7],NULL,screen,&relativ3);
}

if(pos[7].x==0 || pos[7].y>=520)
ba=1;




}// screen bat

}//bat==0


// diamonds map witches


scorewitches (&h,&d,screen,location, relativ5, relativ6,relativ2,pos[5]);

vv=vieswitches (&h,&v,&e, screen,location, relativ3,relativ7,0);




if(colisionnn(&location,&pos[5])) // screen obstacle
{

SDL_BlitSurface(Tab[5],NULL,screen,&relativ);

max.y=pos[5].y;
if(pos[5].x>1440)
{
ee=1;
}

if(pos[5].x<1250)
{
ee=0;
}


if(ee==0)
{

pos[5].x++;
/*
if(colsss(h.position,relativ))
{
pos[5].x--;
}
*/

}
else
{

pos[5].x--;
/*
if(colsss(h.position,relativ))
{
pos[5].x++;
}
*/


}






}// if colis obsta

max.y=420;




if(colisionnn(&location,&pos[4])) // screen question
{

SDL_BlitSurface(Tab[4],NULL,screen,&relativ4);

if(engw==0)
{

if(colsss(h.position,relativ4))
{
printf("question");
t=1;

}

}




}// screen question





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


}//switch minimap1


if(k==1)
{

affichemapwitches(Tab,m,screen);

}


///////////////////////////////////////
if(b[0])
{

a+=speed;
pos[0].x+=speed;

if(colsss(h.position,relativ))
{
m.posmap[2].x-=1;
a-=speed;
pos[0].x-=speed;
}

if(pos[0].x>=2500-400)
{
pos[0].x=2500-400;
a=2500-400;
}

}




//////////////
 if(b[1])
{

a-=speed;
pos[0].x-=speed;

if(colsss(h.position,relativ))
{
m.posmap[2].x+=1;
a+=speed;
pos[0].x+=speed;
}

if(pos[0].x<=0)
{
pos[0].x=0;
a=0;
}

}
//////

/*
if(b[0])
{

if(pos[2].x<200)
pos[2].x+=speed;

else if(pos[0].x>=2500-400)

pos[2].x+=speed;


if(m.posmap[2].x<580)
m.posmap[2].x+=1;



if(colsss(pos[2],relativ))
{
pos[2].x-=speed;

m.posmap[2].x-=1;
}






}


if(b[1])
{

pos[2].x-=speed;


if(m.posmap[2].x>0)
m.posmap[2].x-=1;



if(colsss(pos[2],relativ))
{

pos[2].x+=speed;

m.posmap[2].x+=1;

}

}

if(b[2])
{
pos[2].y-=speed;
if(colsss(pos[2],relativ) )
pos[2].y+=speed;
}

if(b[3])
{
pos[2].y+=speed;
if(colsss(pos[2],relativ)|| colsss(pos[2],pos[4]))
pos[2].y-=speed;
}

*/



if(b[0])
    {
     if(h.position.x<=200)
     h.position.x+=speed;


     else if(pos[0].x>=2500-400)
     {
      h.position.x+=speed;
     }

if(m.posmap[2].x<580)
m.posmap[2].x+=1;



if(colsss(h.position,relativ))
{
h.position.x-=speed;

m.posmap[2].x-=1;
}

    }





h.position.y+=h.gravite;
h.gravite++;

if (h.gravite==20 )
			{h.gravite=20;}

	if(h.position.y + 150 >= max.y )
		{
                            
			h.gravite=0;
			h.position.y=max.y-150;


		}
               if(colsss(h.position,relativ))
{                             
                h.gravite=0;

}

if(b[4]==1){
                        h.position.y-=speed2;




     							 
}
if(b[1]==1){
h.position.x=-speed;

if(m.posmap[2].x>0)
m.posmap[2].x-=1;



if(colsss(h.position,relativ))
{

h.position.x+=speed;

m.posmap[2].x+=1;

}

                          q=1;
                             if(noah==1)
                            animer_personnage(&h,q);
}

if(b[0]==1){
                          q=0;
                            if(kevin==1)
                            animer_personnage2(&h2,q);
}
//
if(noah==1)
afficher_personnage(h,screen);

if(kevin==1)
afficher_personnage3(h,h2,screen);


/**** afficher score et vies ****/
 sprintf(vi,"Vies: %d",h.vie);
 text = TTF_RenderText_Blended(po,vi, couleurBleue);

 sprintf(sc,"Score: %d",h.score);
 text1 = TTF_RenderText_Blended(po1,sc, couleurBleue1);

 SDL_BlitSurface(text1, NULL, screen, &position_msg1);
 SDL_BlitSurface(text, NULL,screen, &position_msg);

/**** afficher temps ****/
afficher_temps(&tmps,screen);


/**** afficher save ****/
if (b[5]==1)
{
 afficher_save_escape(&sv,screen,&msc);
}

if (flag_save ==1)
{
 if (SAVE==0)
 {
   afficher_save (&sv,screen,motion_a,motion_b,&msc);
   check_save=Lunch_SaveGame (motion_a,motion_b,&msc,"SaveGame.txt","level.txt",h,pos,tmps,enmy,niveau);
   if (check_save==0)
   {  x=0; }
   
   SAVE=1;
 }
}

SAVE=0;


/**** afficher help ****/

if (flag_store ==1)
{
 if (l==0)
 {
   afficher_help (&st,screen,motion_a,motion_b);
   l=1;
 }
}

l=0;

/**** afficher store ****/

if (flag_store ==1)
{
 if (w==0)
 {
  aff_store_1 (screen,st,&dkhal,motion_a,motion_b,&h,tm); 
   w=1;
 }

if (/*dkhal == 1 &&*/ w==1)
{
gest_store (screen,st,&h,&tm,motion_a,motion_b,&dkhal);
}

}//flag 

w=0;



//end 
if(h.position.x>=490 && h.position.y>=216)
{
b[0]=0;
b[1]=0;
b[2]=0;
b[4]=0;
b[3]=0;

x=0;

printf("lvl finish");
return 1;

}

continuer=cond_fin_jeu( vv, &h, tmps);
if(continuer==0)
{

finjeu(screen);
*fin=1;
return  1; 

}

SDL_Flip(screen);

}//t===0

if(t==1)
{

engw=enigmewi(screen,&eng,&eng2);

printf("\nengw1::%d\n",engw);
if(engw==1)
{
b[0]=0;

b[1]=0;

b[2]=0;

b[4]=0;

printf("rja3");
t=0;

}

printf("\nengw2::%d\n",engw);

printf("\neng::%d\n",eng);

printf("\neng2::%d\n",eng2);
}

}//while

TTF_Quit();

free_temps(&tmps);

SDL_FreeSurface(Tab[1]);

SDL_FreeSurface(Tab[2]);

SDL_FreeSurface(Tab[5]);






}





