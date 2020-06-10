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

/**
* @file [main.c].
* @author : Cyrine Trabelsi
* @brief : Game Project
* @date : 2020/05/29
* @version 1
*/

void main() //int stage1(SDL_Surface *Tab[])
{

//init ttf
 TTF_Init();

//timer
SDL_Init(SDL_INIT_TIMER);

/**** declarations de variables ****/

//structs
hero h;
vie v;
es e;
enigme en;
score d;
temps tmps;
store st;
musique msc;
SDL_Rect max;
max.y=450; //definition niveau sol

//SDL
SDL_Surface *Tab[8];
SDL_Rect pos[8];
SDL_Event event;
SDL_Surface *dead;
SDL_Rect posdead;

//other
int enm;
char image[8];
int running, run;
int alea, ss=0, r;
int h0,h1,e1,e2;
int indice;
int num;
int x=1,t=1,y=0;
int continuer=1;
const int speed=20;
_Bool b[8]={0,0,0,0,0,0,0,0};
int argc;
char** argv;
int vv;
int sens=0,senspred=0;
int res_en;
int q;
int m=0;
int t_rest;
int dkhal;
int tm=4000;
int flag_store=0;
int motion_a,motion_b;
int w=0;
int l=0;
int a=0,c=0;
int cont;
int en2;

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

/**** save ****/
//LoadGame("save.txt",&h,pos,d,v,b);

/**** screen ****/
if(SDL_Init(SDL_INIT_VIDEO)!=0)
{
printf("Unable :%s\n",SDL_GetError());
}

Tab[0]=SDL_SetVideoMode(730,530,0,SDL_SWSURFACE|SDL_DOUBLEBUF);

/**** music ****/
Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);


/**** init background ****/
initialise(Tab,pos);

/**** init hero ****/
initialiser_personnage(&h);
initialiser(&e);




/**** init diamonds ****/
init_dms (&d);

/**** init hearts ****/
init_hearts (&v);

/**** init dead  ****/
dead=IMG_Load("gameover.jpg");
posdead.x=0;
posdead.y=0;


/**** init temps ****/
initialiser_temps(&tmps);

/**** init store ****/
init_store (&st);


/**** musique ****/
music (&msc); 

/**** boucle du jeu ****/

 while(continuer)
 {



/**** collision avec question mark ****/
int o=collisionTrigoObj(h.position,&e,3);


  //menu 
   SDL_PollEvent(&event);

   switch(event.type)
   {
    case SDL_QUIT:
    continuer=0;
    break;

    case SDL_MOUSEBUTTONDOWN:
    flag_store=1;
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
    

    if(t==1)
    {
     if(b[0])
     {
      if(h.position.x>=200)
      {
       a+=speed;
       pos[0].x+=speed;
       pos[1].x+=speed;

       if(pos[0].x>=2500-400)
       {a=2500-400;
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
     {a=0;
      pos[0].x=0;
      pos[1].x=0;
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
    }



    if(h.position.x==500 && h.position.y<=510)
    {
     t=2;
     h.position.x=10;
     h.position.y=300;
    }

/**** localisation hero ****/
SDL_Rect location ={a,c,730,530};

/**** init score ****/ //yetbadlou fel stage 2
SDL_Rect relativ ={d.position[0].x-a,d.position[0].y-c}; //diamond1
SDL_Rect relativ2 ={d.position[1].x-a,d.position[1].y-c}; //diamond2
SDL_Rect relativ3 ={d.position[2].x-a,d.position[2].y-c}; //diamond3
SDL_Rect relativ4 ={d.position[3].x-a,d.position[3].y-c}; //diamond4
SDL_Rect relativ5 ={d.position[4].x-a,d.position[4].y-c}; //diamond5

/**** init vies ****/
SDL_Rect rltv1 ={v.position[0].x-a,v.position[0].y-c}; //heart1

/**** bcg ***/
affiche1(Tab,pos);


/**** boutons store et help ****/
affiche_bouton_store (&st,Tab);
affiche_button_help (&st,Tab);


/**** afficher diamonds and hearts on background ****/
affiche_diamond (&d,Tab);
affiche_heart (&v,Tab);

/**** init obstacles ****/
SDL_Rect relativobj ={e.posobj[0].x-a,e.posobj[0].y-c}; //objet1
SDL_Rect relativobj2 ={e.posobj[1].x-a,e.posobj[1].y-c}; //objet2

/**** gestion de score et de vie ****/
scoree (&h,&d,Tab,location,relativ ,relativ2,relativ3, relativ4, relativ5);
vv=vies (&h,&v,&e, Tab,location, rltv1,0,relativobj,relativobj2);



/**** afficher obstacles ****/
affiche_ents (&e,Tab,a,c,relativobj,relativobj2); //stage 2 mafamech

/**** afficher et animer hero ****/

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
                        h.position.y-=speed;
     							 }
if(b[1]==1){
h.position.x=0;
    

                          q=1;
                            animer_personnage(&h,q);
}

if(b[0]==1){
                          q=0;

                            animer_personnage(&h,q);
}
//

afficher_personnage(h,Tab);

/**** deplacer personnage par souris ****/
//s=souris ( argc, argv, &h, screen, &d, Tab, pos);



/**** afficher score et vies ****/
 sprintf(vi,"Vies: %d",h.vie);
 text = TTF_RenderText_Blended(po,vi, couleurBleue);

 sprintf(sc,"Score: %d",h.score);
 text1 = TTF_RenderText_Blended(po1,sc, couleurBleue1);

 SDL_BlitSurface(text1, NULL, Tab[0], &position_msg1);
 SDL_BlitSurface(text, NULL, Tab[0], &position_msg);

/**** afficher temps ****/
afficher_temps(&tmps,Tab);

/**** afficher help ****/

if (flag_store ==1)
{
 if (l==0)
 {
   afficher_help (&st,Tab,motion_a,motion_b);
   l=1;
 }
}

l=0;

/**** afficher store ****/

if (flag_store ==1)
{
 if (w==0)
 {
  aff_store_1 (Tab,st,&dkhal,motion_a,motion_b,&h,tm); 
   w=1;
 }

if (/*dkhal == 1 &&*/ w==1)
{
gest_store (Tab,st,&h,&tm,motion_a,motion_b,&dkhal);
}

}//flag 

w=0;

/**** conditions de fin du jeu ****/
cont= cond_fin_jeu (vv,h,tmps);
if (cont==0)
{ 
 continuer=0;
}

/**** save ****/
//SaveGame("save.txt",&h,pos,d,v,b);

/**** flip ****/    
    SDL_Flip(Tab[0]);



   }//if t==1





if (t==2) //enigme loula
{ 
     h.nb_enigmes++;
     enm=enigme_num (screen,&tmps);  
    if (enm==1)
    {
       t=0;
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
     t=1;
     h.score-=3;

   b[0]=0;
   b[1]=0;
   b[2]=0;
   b[3]=0;
   b[4]=0;
    }
}


   if(t==0)
   {
     max.y=500; //definition niveau sol
     c=0;
     a=0;
    if(b[0])
    {
     if(h.position.x>=200)
     {
      a+=speed;
      pos[3].x+=speed;
      pos[4].x+=speed;
      //entitee secondaire
      /*affiche_ents (&e,Tab);
      deplacer_ennemiealiatoire(&e,Tab);*/

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
     if(h.position.x<200)
     h.position.x+=speed;
/*if (m==0){
     if(colis2(Tab,pos,h))
     h.position.x-=speed;}*/
    }


    if(b[1])
    {
     //h.position.x-=speed;
/*if (m==0){
     if(colis2(Tab,pos,h))
     h.position.x+=speed;}*/
    }

    if(b[2])
    {
      h.position.y-=speed;
/*if (m==0){
      if(colis2(Tab,pos,h))
      h.position.y+=speed;}*/
    }

    if(b[3])
    {
      h.position.y+=speed;
/*if (m==0) {
      if(colis2(Tab,pos,h))
      h.position.y-=speed; }*/
    }
  /* if (o==1) 
  {t=2;} */



/**** localisation hero ****/
SDL_Rect location2 ={a,c,730,530};



/**** init score ****/
SDL_Rect relativ6 ={d.position[5].x-a,d.position[5].y-c}; //diamond6
SDL_Rect relativ7 ={d.position[6].x-a,d.position[6].y-c}; //diamond7
SDL_Rect relativ8 ={d.position[7].x-a,d.position[7].y-c}; //diamond8


/**** bcg ***/
affiche2(Tab,pos);


/**** init vies ****/
SDL_Rect rltv2 ={v.position[1].x-a,v.position[1].y-c}; //heart2

/**** gestion de score et de vie ****/
scoree2 (&h,&d,Tab,location2,relativ6 ,relativ7,relativ8);
//vv=vies (&h,&v,&e, Tab,location2, rltv2,1);

/**** boutons store et help ****/
affiche_bouton_store (&st,Tab);
affiche_button_help (&st,Tab);

/**** afficher diamonds and hearts on background ****/
affiche_diamond (&d,Tab);
affiche_heart (&v,Tab);



/**** afficher et animer hero ****/
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
                        h.position.y-=15;
/*if (colis(Tab,pos,h))
                        h.position.y+=15;*/
     							 }
if(b[1]==1){
                          q=1;
                            animer_personnage(&h,q);
}

if(b[0]==1){
                          q=0;

                            animer_personnage(&h,q);
}

//
afficher_personnage(h,Tab);

/**** deplacer personnage par souris ****/
//s=souris ( argc, argv, &h, screen, &d, Tab, pos);

/**** gestion de score et de vie ****/
/*vv=vies(&h,&v,&e, h0, h1,  e1, e2, Tab, dead, posdead);
scoree(&h,&d, Tab);*/

/**** afficher score et vies ****/
 sprintf(vi,"Vies: %d",h.vie);
 text = TTF_RenderText_Blended(po,vi, couleurBleue);

 sprintf(sc,"Score: %d",h.score);
 text1 = TTF_RenderText_Blended(po1,sc, couleurBleue1);

 SDL_BlitSurface(text1, NULL, Tab[0], &position_msg1);
 SDL_BlitSurface(text, NULL, Tab[0], &position_msg);

/**** afficher temps ****/
afficher_temps(&tmps,Tab);

/**** afficher help ****/

if (flag_store ==1)
{
 if (l==0)
 {
   afficher_help (&st,Tab,motion_a,motion_b);
   l=1;
 }
}

l=0;

/**** afficher store ****/

if (flag_store ==1)
{
 if (w==0)
 {
  aff_store_1 (Tab,st,&dkhal,motion_a,motion_b,&h,tm); 
   w=1;
 }

if (/*dkhal == 1 &&*/ w==1)
{
gest_store (Tab,st,&h,&tm,motion_a,motion_b,&dkhal);
}

}//flag 

w=0;


/**** save ****/
//SaveGame("save.txt",&h,pos,d,v,b);

/**** flip ****/    
    SDL_Flip(Tab[0]);
    
  }//ift==0 

   



  //khedmet enigme 
   /*res_en=enigme_File (Tab, &en);
   if (res_en == 0)
     h.score-=3;
   else if (res_en == 1)
    {
      t=0;
      m=1;
    }*/
    
  //if rba7 => t=0 // m=1 

cond_fin_jeu(int vv, hero h, temps t)

 } //end while (continuer)


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

}//end main



