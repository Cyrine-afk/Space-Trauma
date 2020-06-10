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



void initialisee(SDL_Surface *Tab[],SDL_Rect pos[],map *m)
{
//map1.................
Tab[1]=IMG_Load("map1.png");

Tab[2]=IMG_Load("hero2.png");

Tab[3]=IMG_Load("obstacle1.png");

Tab[4]=IMG_Load("obstacle2.png");

Tab[5]=IMG_Load("obstacle3.png");




pos[0].x=0;
pos[0].y=0;
pos[0].w=730;
pos[0].h=533;


pos[2].x=10;
pos[2].y=220;
pos[2].w=150;
pos[2].h=200;


pos[3].x=987; //obstacle1
pos[3].y=358;


pos[4].x=1205; //obstacle2
pos[4].y=274;

pos[5].x=2133; //obstacle3
pos[5].y=364;




//..........................................


// inside...................................

Tab[6]=IMG_Load("inside.png");


Tab[7]=IMG_Load("3orsa.png");

Tab[8]=IMG_Load("doura map2.png");

Tab[9]=IMG_Load("doura map2.png");

Tab[10]=IMG_Load("mummy-L1.png"); //il kodem

Tab[13]=IMG_Load("mummy-L1.png"); // with 11

Tab[14]=IMG_Load("mummy-R4.png"); // with 10


Tab[11]=IMG_Load("mummy-R4.png"); // il teli

Tab[12]=IMG_Load("3orsa.png");


pos[6].x=0;
pos[6].y=0;
pos[6].w=730;
pos[6].h=533;



pos[7].x=1150; //3orsa
pos[7].y=51;


pos[8].x=930; //question
pos[8].y=340;

pos[9].x=960; //obstacle3
pos[9].y=370;



pos[10].x=1550; //bat1
pos[10].y=520;


pos[11].x=1710; //bat2
pos[11].y=520;

pos[12].x=1800; //3orsa
pos[12].y=51;

//....................................

m->map[1]=IMG_Load("miniinside.png");

m->map[0]=IMG_Load("minimap3.png");

m->map[2]=IMG_Load("image-01.png");

m->posmap[0].x=0;
m->posmap[0].y=0;
m->posmap[0].w=100;   // mini map 1
m->posmap[0].h=150;











m->posmap[1].x=0;
m->posmap[1].y=0;   // mini map2
m->posmap[1].w=100;
m->posmap[1].h=150;

/*




Tab[6]=IMG_Load("diamon.png");

Tab[3]=IMG_Load("doura station.png");


Tab[4]=IMG_Load("walk.png");

Tab[7]=IMG_Load("bat.png");


























/*








*/



}


_Bool colisionn(SDL_Rect *rec1,SDL_Rect *rec2)
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

int colss(SDL_Rect pos ,SDL_Rect pos2)
{
if((pos.x+pos.w < pos2.x) || (pos.x > pos2.x + pos2.w) || (pos.y+pos.h < pos2.y) || (pos.y > pos2.y + pos2.h))  
 
return 0;

else

return 1;



}

void affichee1(SDL_Surface *Tab[],SDL_Rect pos[],SDL_Surface *screen)
{


SDL_BlitSurface(Tab[1],&pos[0],screen,NULL);
SDL_BlitSurface(Tab[2],NULL,screen,&pos[2]);

/*
SDL_BlitSurface(Tab[4],NULL,Tab[0],&pos[4]);

SDL_BlitSurface(Tab[3],NULL,Tab[0],&pos[3]);
*/


}

void affichee2(SDL_Surface *Tab[],SDL_Rect pos[],SDL_Surface *screen)
{


SDL_BlitSurface(Tab[6],&pos[6],screen,NULL);
SDL_BlitSurface(Tab[2],NULL,screen,&pos[2]);
/*
SDL_BlitSurface(Tab[4],NULL,Tab[0],&pos[4]);

SDL_BlitSurface(Tab[3],NULL,Tab[0],&pos[3]);
*/


}

void affichemapsahra(SDL_Surface *Tab[],map m,SDL_Surface *screen)
{

SDL_BlitSurface(m.map[0],NULL,screen,&m.posmap[0]);
SDL_BlitSurface(m.map[2],NULL,screen,&m.posmap[2]);

}


void affichemapinside(SDL_Surface *Tab[],map m,SDL_Surface *screen)
{

SDL_BlitSurface(m.map[1],NULL,screen,&m.posmap[1]);
SDL_BlitSurface(m.map[2],NULL,screen,&m.posmap[2]);

}


int mapsahra(SDL_Surface *screen,int noah ,int kevin,int *fin)
{

//init ttf
 TTF_Init();

//timer
SDL_Init(SDL_INIT_TIMER);




int x=1,t=0,y=0,p=0,k=0,verif=0,c=0,ee=0,vw=0,l=0,ba=0,g=0,w=0,enm=0,vv=0,enm2;
int  niveau=1;
int continuer=0;

int ins=0,ins2=0;

int mum=0,mum2=0;

int mumy=0,mumy2=1;



int max1=0;
int max2=0;
SDL_Surface *Tab[20];
SDL_Rect pos[20];
SDL_Event event;
int a=0;
const int speed=4;
const int speed2=20;

int q;
int flag_store=0;
int tm=4000;
int dkhal;
int motion_a,motion_b;
int motion_a1,motion_b1;
int bouton_save=0,SAVE=0,flag_save=0;
int check_save=1;

int vie2=0,vie1=0;

_Bool b[7]={0,0,0,0,0,0,0};

map m;

//structs
save sv;
hero h;
hero2 h2;

vie v;
es e;
enigme en;
score d;
temps tmps;
store st;
musique msc;
ennemie enmy;
SDL_Rect max;
max.y=450; //definition niveau sol



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







/*
if(SDL_Init(SDL_INIT_VIDEO)!=0)
{
printf("Unable :%s\n",SDL_GetError());
}

Tab[0]=SDL_SetVideoMode(730,530,0,SDL_SWSURFACE|SDL_DOUBLEBUF);
*/

initialisee(Tab,pos,&m);

/***/
initialiser_personnage(&h);

initialiser_personnage2(&h2);


initialiser(&e);

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

/*****************/

/**** music ****/
//Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);

while(x==1)
{

//music(&msc);
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

 case SDL_MOUSEMOTION:
    motion_a1=event.motion.x;
    motion_b1=event.motion.y;
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


      case SDLK_ESCAPE:
      b[5]=1;
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
 

      case SDLK_ESCAPE:
      b[5]=0;
      break;


    }// end switch key up
     break;


}// end switch (event type)
/*************/

if(t==0)
{
affichee1(Tab,pos,screen);


/**** bouton save ****/
afficher_bouton_save (&sv, screen);
masque_bouton_save (&sv,screen,motion_a1,motion_b1);



/**** boutons store et help ****/

affiche_bouton_store (&st,screen);
affiche_button_help (&st,screen);


/**** afficher diamonds and hearts on background ****/
affiche_diamond (&d,screen);
affiche_heart (&v,screen);

/**************/



SDL_Rect location ={a,c,730,530};

/**** init score ****/ //yetbadlou fel stage 2
SDL_Rect relativ10 ={d.position[0].x-a,d.position[0].y-c}; //diamond1
SDL_Rect relativ11 ={d.position[1].x-a,d.position[1].y-c}; //diamond2
SDL_Rect relativ12 ={d.position[2].x-a,d.position[2].y-c}; //diamond3
SDL_Rect relativ13 ={d.position[3].x-a,d.position[3].y-c}; //diamond4
SDL_Rect relativ14={d.position[4].x-a,d.position[4].y-c}; //diamond5

/**** init vies ****/
SDL_Rect rltv1 ={v.position[0].x-a,v.position[0].y-c}; //heart1

/**** init obstacles ****/
SDL_Rect relativobj ={e.posobj[0].x-a,e.posobj[0].y-c}; //objet1
SDL_Rect relativobj2 ={e.posobj[1].x-a,e.posobj[1].y-c}; //objet2

/**** afficher obstacles ****/
affiche_ents (&e,screen,a,c,relativobj,relativobj2); //stage 2 mafamech
/***********/

/**** gestion de score et de vie ****/
scoree (&h,&d,screen,location,relativ10 ,relativ11,relativ12, relativ13, relativ14);
vv=vies (&h,&v,&e, screen,location, rltv1,0,relativobj,relativobj2);




SDL_Rect relativ ={pos[3].x-a,pos[3].y-c};

SDL_Rect relativ2 ={pos[4].x-a,pos[4].y-c};

SDL_Rect relativ3 ={pos[5].x-a,pos[5].y-c};

if(colisionn(&location,&pos[3])) // screen obstacle1
{

SDL_BlitSurface(Tab[3],NULL,screen,&relativ);
}

if(colisionn(&location,&pos[4])) // screen obstacle2
{

SDL_BlitSurface(Tab[4],NULL,screen,&relativ2);
}

if(colisionn(&location,&pos[5])) // screen obstacle3
{

SDL_BlitSurface(Tab[5],NULL,screen,&relativ3);
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


}//switch minimap1


if(k==1)
{

affichemapsahra(Tab,m,screen);

}


/****************/
if(b[0])
{

a+=speed;
pos[0].x+=speed;

if(colss(h.position,relativ) || colss(h.position,relativ2) || colss(h.position,relativ3))
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

if(colss(h.position,relativ) || colss(h.position,relativ2) || colss(h.position,relativ3))
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



if(colss(h.position,relativ) || colss(h.position,relativ2) || colss(h.position,relativ3))
{
h.position.x-=speed;

m.posmap[2].x-=1;
}

}

/*
if(b[2])
{
pos[2].y-=speed;
if(colss(pos[2],relativ)|| colss(pos[2],relativ2) || colss(pos[2],relativ3) )
pos[2].y+=speed;
}

if(b[3])
{
pos[2].y+=speed;
if(colss(pos[2],relativ)||  colss(pos[2],relativ2) || colss(pos[2],relativ3))
pos[2].y-=speed;
}
*/

h.position.y+=h.gravite;
h.gravite++;

if (h.gravite==20 )
			{h.gravite=20;}

	if(h.position.y + 150 >= max.y )
		{
                            
			h.gravite=0;
			h.position.y=max.y-150;


		}


               if(colss(h.position,relativ) || colss(h.position,relativ2) || colss(h.position,relativ3))
{                  
                  
max1=1;

}

else if(!colss(h.position,relativ) || !colss(h.position,relativ2) ||!colss(h.position,relativ3))
{
max1=0;
max2=1;
}



if(max1==1)
{
max.y=370;

}


else if(max2==1)
{
max.y=450;

}

if(b[4]==1){
                        h.position.y-=speed2;




     							 
}
if(b[1]==1){
h.position.x=-speed;

if(m.posmap[2].x>0)
m.posmap[2].x-=1;



if(colss(h.position,relativ) || colss(h.position,relativ2) || colss(h.position,relativ3))
{

h.position.x+=speed;

m.posmap[2].x+=1;

}

                          q=1;
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

continuer=cond_fin_jeu( vv, &h, tmps);
if(continuer==0)
{
finjeu(screen);
*fin=1;
return  1; 

}
//end
if(h.position.x>=470 && h.position.y<=510)
{
a=0;
printf("okkkk");
t=2;
h.position.x=25;
h.position.y=300;
a=0;

b[0]=0;
b[1]=0;

b[4]=0;

m.posmap[2].x=0;
m.posmap[2].y=150;

}



//SDL_Flip(screen);

}//if t==0 map1

if (t==2) //enigme loula
{ 
     h.nb_enigmes++;
     enm=enigme_num (screen,&tmps);  
    if (enm==1)
    {
       t=1;
       h.score+=3;
       h.vie++;

       b[0]=0;
       b[1]=0;
       b[2]=0;
       b[3]=0;
       b[4]=0;
    }
    else 
    {
     t=0;
     h.score-=3;

   b[0]=0;
   b[1]=0;
   b[2]=0;
   b[3]=0;
   b[4]=0;
    }
}




if(t==1)
{

max.y=500;

affichee2(Tab,pos,screen);

/**************/

/**** boutons store et help ****/

affiche_bouton_store (&st,screen);
affiche_button_help (&st,screen);


/**** afficher diamonds and hearts on background ****/
affiche_diamond (&d,screen);
affiche_heart (&v,screen);

/**************/

/**** bouton save ****/
afficher_bouton_save (&sv, screen);
masque_bouton_save (&sv,screen,motion_a1,motion_b1);

/****************************/


SDL_Rect location ={a,c,730,530};

SDL_Rect relativi ={pos[7].x-a,pos[7].y-c};

SDL_Rect relativ2 ={pos[8].x-a,pos[8].y-c};

SDL_Rect relativ3 ={d.position[15].x-a,d.position[15].y-c};

SDL_Rect relativ4 ={d.position[16].x-a,d.position[16].y-c};

SDL_Rect relativ10 ={pos[10].x-a,pos[10].y-c};

SDL_Rect relativ11 ={pos[11].x-a,pos[11].y-c};

SDL_Rect relativ12 ={pos[12].x-a,pos[12].y-c};


scoreinside (&h,&d,screen,location,relativ3 ,relativ4);
//vv=vieinside (&h,&v,&e, screen,location,relativ4 );


if(colisionn(&location,&pos[7])) // screen obstacle1
{

SDL_BlitSurface(Tab[7],NULL,screen,&relativi);

}

if(colisionn(&location,&pos[8])) // screen obstacle2
{

SDL_BlitSurface(Tab[8],NULL,screen,&relativ2);


if(colss(h.position,relativ2))
{

if(pos[7].y<=310)
pos[7].y++;





}

}


if(colisionn(&location,&pos[12])) // screen 3orsa2
{

SDL_BlitSurface(Tab[12],NULL,screen,&relativ12);

}



if(vie1==0)
{
if(colisionn(&location,&pos[10])) // screen minion1
{

SDL_BlitSurface(Tab[10],NULL,screen,&relativ10);

if(colss(h.position,relativi))
{
mum=1;
}

if(mum==1)
{

if(pos[10].y>=300)
{


pos[10].y-=2;

}

if(colss(relativ10,relativi))
{
mumy=0;
}

if(colss(relativ10,relativ12))
{
mumy=1;
}


if(mumy==0)
{

pos[10].x+=2;


}
else
{

pos[10].x-=2;



}//else

}//num==1

if(colss(h.position,relativ10))
{
h.vie--;
vie1=1;


}


}//location

}// vie


if(vie2==0)
{
if(colisionn(&location,&pos[11])) // screen minion2
{


SDL_BlitSurface(Tab[11],NULL,screen,&relativ11);

if(colss(h.position,relativi))
{
mum2=1;
}

if(mum2==1)
{

if(pos[11].y>=300)
{

pos[11].y-=2;
}


if(colss(relativ11,relativi))
{
mumy2=0;
}

if(colss(relativ11,relativ12))
{
mumy2=1;
}


if(mumy2==0)
{

pos[11].x++;


}
else
{

pos[11].x--;



}//else

}//num2==1


if(colss(h.position,relativ11))
{
h.vie--;
vie2=1;


}


}//locat

}//if tsakir vie


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

affichemapinside(Tab,m,screen);

}



/****************/
if(b[0])
{

a+=speed;
pos[6].x+=speed;

if(colss(h.position,relativi))
{
m.posmap[2].x-=1;
a-=speed;
pos[6].x-=speed;
}

if(pos[6].x>=2500-400)
{
pos[6].x=2500-400;
a=2500-400;
}

}




//////////////
 if(b[1])
{

a-=speed;
pos[6].x-=speed;

if(colss(h.position,relativi))
{
m.posmap[2].x+=1;
a+=speed;
pos[6].x+=speed;
}

if(pos[6].x<=0)
{
pos[6].x=0;
a=0;
}

}


if(b[0])
{

if(h.position.x<200)
h.position.x+=speed;

else if(pos[6].x>=2500-400)

h.position.x+=speed;


if(m.posmap[2].x<580)
m.posmap[2].x+=1;





if(colss(h.position,relativi))
{
h.position.x-=speed;

m.posmap[2].x-=1;
}





}


if(b[1])
{

h.position.x-=speed;


if(m.posmap[2].x>0)
m.posmap[2].x-=1;



if(m.posmap[2].x>0)
m.posmap[2].x-=1;

}

/*
if(b[2])
{
pos[2].y-=speed;
if(colss(pos[2],relativ) )
pos[2].y+=speed;
}

if(b[3])
{
pos[2].y+=speed;
if(colss(pos[2],relativ)|| colss(pos[2],pos[4]))
pos[2].y-=speed;
}
*/


h.position.y+=h.gravite;
h.gravite++;

if (h.gravite==20 )
			{h.gravite=20;}

	if(h.position.y + 150 >= max.y)
		{
			h.gravite=0;
			h.position.y=max.y-150;

		}




               if(colss(h.position,relativi))
{                  
                  
ins=1;
h.gravite=0;
}

else if(!colss(h.position,relativi))
{
ins=0;
ins2=1;
}



if(ins==1)
{
max.y=370;

}


else if(ins2==1)
{
max.y=450;

}






if(b[4]==1){
                        h.position.y-=17;

     							 }
if(b[1]==1){



 q=1;
                            if(noah==1)
                            animer_personnage(&h,q);

                                if(kevin==1)
                            animer_personnage2(&h2,q);



if(colss(h.position,relativi))
{

h.position.x+=speed;

m.posmap[2].x+=1;

}

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


continuer=cond_fin_jeu( vv, &h, tmps);
if(continuer==0)
{

finjeu(screen);
*fin=1;
return  1; 

}
// end lvl
if(h.position.x>=470 && h.position.y<=510)
{

//Mix_FadeOutMusic(500);
//SDL_Delay(100);
b[0]=0;
b[1]=0;
b[2]=0;
b[4]=0;

x=0;
return 1;
}







}//if t==1 inside

if(t==3)
{
enm2=enigme_File(screen,&en) ;

if(enm2==1)
t=1;

}

SDL_Flip(screen);

}//while



SDL_FreeSurface(Tab[1]);

SDL_FreeSurface(Tab[3]);

SDL_FreeSurface(Tab[4]);

SDL_FreeSurface(Tab[5]);

SDL_FreeSurface(Tab[6]);


/**** free ****/
TTF_Quit();
Mix_CloseAudio();
//SDL_Quit();
//free_hero(&h);
frees(&e);
freeHearts (&v);
freeDiamonds (&d);
freeText (po,po1,text1,text);
free_temps(&tmps);








}
