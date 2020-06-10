#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <SDL/SDL_stdinc.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>


typedef struct personnage
{
int score;
int vie;
int lifem;
SDL_Surface *imgA;
SDL_Rect position;
} personnage;

typedef struct es 
{
SDL_Surface *imgA[5];
SDL_Rect position[5];
}es;


typedef struct score 
{
SDL_Surface *image[7]; 
SDL_Rect position[7];
  int tab[20];
}score;

typedef struct vie
{
  SDL_Rect position[2];
  SDL_Surface *image[2]; 
}vie;

typedef struct store 
{
  SDL_Surface *button; 
  SDL_Rect posbtn;
  SDL_Surface *image; 
  SDL_Rect position;
} store;


void init_store (store *st)
{
  st->button= IMG_Load("str.png");
  st->image=IMG_Load("store.png"); 
  
  st->posbtn.x=700;
  st->posbtn.y=10;

  st->position.x=0;
  st->position.y=0;
}

void affiche_bouton (store *st, SDL_Surface *screen)
{
  SDL_BlitSurface(st->button,NULL,screen,&st->posbtn);

  SDL_Flip(screen);
}

void affiche_store (store *st, SDL_Surface *screen)
{
  SDL_BlitSurface(st->image,NULL,screen,&st->position);
  SDL_Flip(screen);
}


void aff_store_1 (SDL_Surface *screen, store st, int *dkhal, SDL_Event event, personnage *p)
{
  int a,b;
  int tm=3000;
  SDL_Rect position_msg1, posd;


printf("\n gestion \n");


  TTF_Init();

  TTF_Font *po1;
 SDL_Surface *text1, *dmd;
 SDL_Color couleurBlanche1 = {0,0,255}; 
 char sc[50]="";
 char nb1[20]="";

 dmd= IMG_Load("dmd0.png");

 position_msg1.x=20;
 position_msg1.y=15;

 po1 = TTF_OpenFont("fente.ttf", 15);
    //case SDL_MOUSEBUTTONDOWN:
     a=event.motion.x;
     b=event.motion.y;
     
     if (a>700 && a<730 && b>10 && b<30)
     {
       affiche_store (&st,screen);
       


 SDL_BlitSurface(dmd,NULL,screen,&posd);
 sprintf(sc,"score: %d",p->score);
 text1 = TTF_RenderText_Blended(po1,sc, couleurBlanche1);

 SDL_BlitSurface(text1, NULL, screen, &position_msg1);
  
 SDL_Flip(screen);
       *dkhal=1; //dkhal
       SDL_Delay (tm);
     } 
     else
       *dkhal=0; //madkhalch
}


void gest_store (SDL_Surface *screen, store st, personnage *p, int tm, SDL_Event event)
{

  int a1,b1;
  SDL_Rect position_msg1, posd;


printf("\n gestion \n");


  
  
    //case SDL_MOUSEBUTTONDOWN:
     a1=event.motion.x;
     b1=event.motion.y;

     if (a1<7 && a1>85 && b1<480 && b1>516 ) //back
     { 
       //tm=0;
     }  
     
     if (a1<629 && a1>672 && b1<45 && b1>65 /*&& p->score>=10*/) //hearts
     { 
       /*p->score-=10;
       p->vie+=3;*/
       printf("\n Condition \n");
       /*printf("\n score = %d \n",p->score);
       printf("\n vies = %d \n",p->vie);*/
     }  

     if (a1<629 && a1>672 && b1<110 && b1>133 /*&& p->score>=10*/) //sle7 1
     { 
       p->score-=10;
       printf("\n Condition \n");
       printf("\n score = %d \n",p->score);
       //p->attack a modifier
     }  

     if (a1<629 && a1>672 && b1<184 && b1>205 /*&& p->score>=20*/) //sle7 2
     { 
       p->score-=20;
       printf("\n Condition \n");
       printf("\n score = %d \n",p->score);
       //p->attack a modifier
     }  
    
     if (a1<629 && a1>672 && b1<257 && b1>277 /*&& p->score>=30*/) //sle73
     { 
       p->score-=30;
       printf("\n Condition \n");
       printf("\n score = %d \n",p->score);
       //p->attack a modifier
     }     

}


int souris ( int argc, char** argv, personnage *p, SDL_Surface *screen, score *d, SDL_Surface *bg, SDL_Rect posbg)
{
    int continuer=1 ;
    SDL_Event event ;
    
    SDL_EnableKeyRepeat(10, 10);
        while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {

         case SDL_QUIT:
                continuer = 0;
                break;
       
         case SDL_MOUSEBUTTONUP:
             if(event.button.button==SDL_BUTTON_LEFT)
              {
              p->position.x = event.button.x;
              p->position.y = event.button.y;
              }
              else if (event.button.button==SDL_BUTTON_RIGHT)
              continuer=0 ;

              break ;
         case SDL_ACTIVEEVENT :/*gestion de fenetre*/
                  if ((event.active.state & SDL_APPMOUSEFOCUS) == SDL_APPMOUSEFOCUS)/*tester l etat de la souris */
{
      if (event.active.gain == 0)  /*la souris est sorti de la fenetre*/
        {
         p->position.x++ ;
         p->position.y++ ;
        }
      else if (event.active.gain == 1)  /*la souris est dans la fenetre*/
        {
         p->position.x ++ ;
         p->position.y++ ;
        }
}
            break ;


        }

        /* On efface l'écran */
        
        SDL_BlitSurface(bg,NULL,screen,&posbg);

        SDL_BlitSurface(d->image[0],NULL,screen,&d->position[0]);
        //SDL_BlitSurface(d->image[1],NULL,screen,&d->position[1]);
        SDL_BlitSurface(d->image[2],NULL,screen,&d->position[2]);
        //SDL_BlitSurface(d->image[3],NULL,screen,&d->position[3]);
        SDL_BlitSurface(d->image[4],NULL,screen,&d->position[4]);
       //SDL_BlitSurface(d->image[5],NULL,screen,&d->position[5]);
        SDL_BlitSurface(d->image[6],NULL,screen,&d->position[6]);        

        /* placer hero à sa nouvelle position */
        SDL_BlitSurface(p->imgA, NULL, screen , &p->position);
        /* mise à jour affichage */
        SDL_Flip(screen);
    }

 SDL_Flip(screen);

    return 0;
}


int collisionTrigo(SDL_Rect p1,score *d,int indice)
{
 int i;
int xc1=p1.x+100;
int yc1=p1.y+100;
int xc2=d->position[indice].x+100;
int yc2=d->position[indice].y+100;
int a=xc1-xc2;
int b=yc1-yc2;
float h;
h=sqrt((a*a)+(b*b));
if((int)h<=150)
{
indice=i;
return 1;
}
else
return 0;
}


int collisionTrigoVie(SDL_Rect p1,vie *v,int indice)
{
 int i;
int xc1=p1.x+100;
int yc1=p1.y+100;
int xc2=v->position[indice].x+100;
int yc2=v->position[indice].y+100;
int a=xc1-xc2;
int b=yc1-yc2;
float h;
h=sqrt((a*a)+(b*b));
if((int)h<=150)
{
indice=i;
return 1;
}
else
return 0;
}


void scoree(personnage *p,score *d, SDL_Surface *screen)
{

int i;

if (d->tab[0]==0)
{
 if (!collisionTrigo(p->position,d,0))
 {
  SDL_BlitSurface(d->image[0],NULL,screen,&d->position[0]);
 }

 if(collisionTrigo(p->position,d,0))
 {
  p->score=p->score+1;
  d->position[0].y=2000;
  d->tab[0]=1;
  printf("\n score = %d \n",p->score);
 }
}

if (d->tab[1]==0)
{
 if (!collisionTrigo(p->position,d,1))
 {
  SDL_BlitSurface(d->image[1],NULL,screen,&d->position[1]);
 }

 if(collisionTrigo(p->position,d,1))
 {
  p->score=p->score+1;
  d->position[1].y=2000;
  d->tab[1]=1;
  printf("\n score = %d \n",p->score);
 }
}

}



void afficher_score (personnage *p, SDL_Surface *screen)
{
 SDL_Rect position_msg;
 TTF_Font *po;
 SDL_Surface *text;
 SDL_Color couleurBlanche = {0,0,255}; 
 char sc[50]="";
 char nb[20]="";

 position_msg.x=20;
 position_msg.y=10;

 TTF_Init();
 po = TTF_OpenFont("fente.ttf", 20);
 sprintf(sc,"score: %d",p->score);
 text = TTF_RenderText_Blended(po,sc, couleurBlanche); 

 SDL_BlitSurface(text, NULL, screen, &position_msg);

}




int collisionTrigoEs(SDL_Rect p1,es *e,int indice)
{
 int i;
int xc1=p1.x+100;
int yc1=p1.y+100;
int xc2=e->position[indice].x+100;
int yc2=e->position[indice].y+100;
int a=xc1-xc2;
int b=yc1-yc2;
float h;
h=sqrt((a*a)+(b*b));
if((int)h<=150)
{
indice=i;
return 1;
}
else
return 0;
}

int colis(es *e, personnage p) 
{

if( (p.position.x + p.imgA->w) < e->position[0].x ) //
   return 0;

else if( p.position.x > (e->position[0].x + e->imgA[0]->w) )
   return 0;

else if( (p.position.y + p.imgA->h) < e->position[0].y )//
   return 0;

else if ( p.position.y > (e->position[0].y + e->imgA[0]->h ) )//
   return 0; //pas de collision

else 
return 1; // collision

}



int vies(personnage *p,vie *v,es *e, int h0,int h1, int e1, int e2, SDL_Surface *screen, SDL_Surface *dead, SDL_Rect posdead)
{
int i;

if (h0==0)
{
if(!collisionTrigoVie(p->position,v,0))
{
SDL_BlitSurface(v->image[0],NULL,screen,&v->position[0]);
}
 if(collisionTrigoVie(p->position,v,0))
{
p->vie++;
v->position[0].y=8000;
h0=1;
}
}// end if h0==0

if (h1==0)
{
if(!collisionTrigoVie(p->position,v,1))
{
SDL_BlitSurface(v->image[1],NULL,screen,&v->position[1]);
}
 if(collisionTrigoVie(p->position,v,1))
{
p->vie++;
v->position[1].y=8000;
h1=1;
}
}// end if h1==0


i=colis(e,*p);

if (e1==0)
{
if (collisionTrigoEs(p->position,e,0))// (i==1)
{ 
 p->lifem--;
e1=1;
} 
}

if ( (p->lifem <= (-145)) && (p->lifem >= (-165)) )
 {
   p->vie--;
   p->lifem=0;
 }

if (p->vie <= 0)
{
  SDL_BlitSurface(dead,NULL,screen,&posdead);
  p->position.x=2000;
  
  return 1; //mort
}
else 
  return 0; //pas mort  

}


/*void afficher_score (personnage *p, SDL_Surface *text1, SDL_Rect position_msg, SDL_Surface *screen, SDL_Color couleurBlanche1, SDL_Surface *sc, TTF_Font *po1)
{
 sprintf(sc,"score: %d",p->score);
 text1 = TTF_RenderText_Blended(po1,sc, couleurBlanche1);
}*/


void afficher_vies (personnage *p, vie *v, es *e, SDL_Surface *screen)
{
 SDL_Surface *dead, *text;
 SDL_Rect position_msg, pos;
 TTF_Font *po;
 SDL_Surface *scr;
 SDL_Color couleurBlanche = {0,0, 255}; 
 char vi[50]="";
 char nb[20]="";

 position_msg.x=500;
 position_msg.y=20;

 TTF_Init();
 po = TTF_OpenFont("fente.ttf", 30);
 sprintf(vi,"vies: %d",p->vie);
 text = TTF_RenderText_Blended(po,vi, couleurBlanche); 

 SDL_BlitSurface(text, NULL, screen, &position_msg);

 dead = IMG_Load("gameover.jpg");
 pos.x=0;
 pos.y=0;

}


void main ()
{
//init
 personnage p;
 score d;
 es e;
 vie v;
 store st;
 SDL_Surface *screen, *dead, *snd;
 SDL_Event event;
 SDL_Surface *bg; 
 SDL_Rect posbg, posdead, poss; 
 int dkhal=0,tm;
 int done=1,i,s,h0=0,h1=0,e1=0,e2=0,k,vv;
 int argc;
 char** argv;

snd=IMG_Load("ras.png");
poss.x=100;
poss.y=0;

//personnage
p.imgA=IMG_Load("hero2.png");
 if(!p.imgA)
{ printf("Error: %s\n",SDL_GetError()); } 
p.position.x=0;
p.position.y=380;

//entitee secondaire 
e.imgA[0]=IMG_Load("fire.png");

e.position[0].x=200;
e.position[0].y=400;

//dead
dead=IMG_Load("gameover.jpg");

posdead.x=0;
posdead.y=0;

//init score et vies
p.score=10;
p.vie=3;
p.lifem=0;

//init store
init_store (&st);

//afficher vies
 SDL_Surface *text, *hrt;
 SDL_Rect position_msg, posh;
 TTF_Font *po;
 SDL_Surface *scr;
 SDL_Color couleurBlanche = {0,0, 255}; 
 char vi[50]="";
 char nb[20]="";

 posh.x=0;
 posh.y=45;

 hrt= IMG_Load("coeur0.png");

 position_msg.x=30;
 position_msg.y=40;

 TTF_Init();

 po = TTF_OpenFont("fente.ttf", 20);
 /*po = TTF_OpenFont("fente.ttf", 20);
 sprintf(vi,"vies: %d",p.vie);
 text = TTF_RenderText_Blended(po,vi, couleurBlanche); */

//afficher score
SDL_Rect position_msg1, posd;
 TTF_Font *po1;
 SDL_Surface *text1, *dmd;
 SDL_Color couleurBlanche1 = {0,0,255}; 
 char sc[50]="";
 char nb1[20]="";

 posd.x=0;
 posd.y=10;

 dmd= IMG_Load("dmd0.png");

 position_msg1.x=30;
 position_msg1.y=10;

 po1 = TTF_OpenFont("fente.ttf", 20);

 /*TTF_Init();
 po1 = TTF_OpenFont("fente.ttf", 20);
 sprintf(sc,"score: %d",p.score);
 text1 = TTF_RenderText_Blended(po1,sc, couleurBlanche1);*/ 


//screen
 if(SDL_Init(SDL_INIT_VIDEO)!=0) 
{ printf("Error: %s\n",SDL_GetError()); }

screen = SDL_SetVideoMode(730,530,32,SDL_HWSURFACE|SDL_DOUBLEBUF); 
if(!screen)
 { printf("Error 2: %s\n",SDL_GetError()); }

//bcg
bg = SDL_LoadBMP("BACK.bmp");
if(!bg)
{ printf("Error: %s\n",SDL_GetError()); }
posbg.x=0;
posbg.y=0;


//hearts
v.image[0]=IMG_Load("coeur1.png");
v.image[1]=IMG_Load("coeur2.png");

v.position[0].x=600;
v.position[0].y=150;

v.position[1].x=230;
v.position[1].y=150;

//diamonds
d.image[0]=IMG_Load("dmd.png"); 
d.image[1]=IMG_Load("dmd1.png");
d.image[2]=IMG_Load("diamonds5.png");
d.image[3]=IMG_Load("diamonds7.png");

 d.position[0].x=450;
 d.position[0].y=100;

 d.position[1].x=450;
 d.position[1].y=400;


 d.position[2].x=340;
 d.position[2].y=450;

 
 d.position[3].x=460;
 d.position[3].y=450;

for (k=0;k<12;k++)
{
 d.tab[i]=0;
}


//boucle jeu
while(done==1)
{

SDL_BlitSurface(bg,NULL,screen,&posbg);

SDL_BlitSurface(snd,NULL,screen,&poss);

SDL_BlitSurface(e.imgA[0],NULL,screen,&e.position[0]);

vv=vies(&p,&v,&e,h0,h1,e1,e2,screen,dead,posdead);

//afficher_vies (&p, &v, &e,screen);
scoree(&p,&d,screen);
//afficher_score (&p,screen);

SDL_BlitSurface(d.image[1],NULL,screen,&d.position[1]);/*
SDL_BlitSurface(d.image[2],NULL,screen,&d.position[2]);
SDL_BlitSurface(d.image[3],NULL,screen,&d.position[3]);*/

/*SDL_BlitSurface(v.image[0],NULL,screen,&v.position[0]);
SDL_BlitSurface(v.image[1],NULL,screen,&v.position[1]);*/


//vies
//p.vie=p.vie+p.lifep;
 /*if ( (p.lifem <= (-145)) && (p.lifem >= (-165)) )
 {
   p.vie--;
   p.lifem=0;
 }*/
 SDL_BlitSurface(hrt,NULL,screen,&posh);
 sprintf(vi,"vies: %d",p.vie);
 text = TTF_RenderText_Blended(po,vi, couleurBlanche);
 

//score
 SDL_BlitSurface(dmd,NULL,screen,&posd);
 sprintf(sc,"score: %d",p.score);
 text1 = TTF_RenderText_Blended(po1,sc, couleurBlanche1);

//void afficher_score (p,&text1,position_msg,screen, couleurBlanche1, sc, po1);


SDL_BlitSurface(text, NULL, screen, &position_msg);

 SDL_BlitSurface(text1, NULL, screen, &position_msg1);

SDL_BlitSurface(p.imgA,NULL,screen,&p.position);


affiche_bouton (&st,screen);

/*if (vv=1)
{
 done=0;
}*/


//s= souris ( argc, argv, &p, screen, &d, bg, posbg);

SDL_Flip(screen);



 SDL_PollEvent(&event);

switch(event.type)
{
case SDL_QUIT:
done=0;
break;

case SDL_MOUSEBUTTONDOWN:


printf("\n case \n");

aff_store_1 (screen,st,&dkhal,event,&p);


if (dkhal == 1)
{

printf("dkhal");

gest_store (screen,st,&p,tm,event);

}

break;

case SDL_KEYDOWN:
if((event.key.keysym.sym == SDLK_LEFT ) || (event.key.keysym.sym ==SDLK_q))
 { p.position.x-= 2;
 SDL_BlitSurface(p.imgA,NULL,screen,&p.position); }

if((event.key.keysym.sym == SDLK_RIGHT) || (event.key.keysym.sym ==SDLK_d))
 { p.position.x+= 2;
 SDL_BlitSurface(p.imgA,NULL,screen,&p.position); }

 if((event.key.keysym.sym == SDLK_UP) || (event.key.keysym.sym ==SDLK_z)) 
{ p.position.y-= 2; 
 SDL_BlitSurface(p.imgA,NULL,screen,&p.position); }

 if((event.key.keysym.sym == SDLK_DOWN) || (event.key.keysym.sym ==SDLK_s)) 
{ p.position.y+= 2; 
 SDL_BlitSurface(p.imgA,NULL,screen,&p.position); }

 break;

}//end switch (event.type)




} //end while done


} // end main









