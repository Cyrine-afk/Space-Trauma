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
* @file [enigmestat.c].
* @author : Mohamed Kalech
* @brief : Game Project
* @date : 2020/05/29
* @version 1
*/

void nb (int n, int *p, int *number,int *numero,SDL_Surface *img2,SDL_Surface *screen, SDL_Rect pos1, SDL_Rect pos2, SDL_Rect pos3)
{




     
    if ((n)==0)//variable lzem yetbadel
      { (n)=1;
        (*p)++;
       
      if ((*p)==1)
{      
       
      SDL_BlitSurface(img2,NULL,screen,&pos1);
	SDL_Flip(screen);
        (*numero)=(*numero)+(*number)*100;
        
}
        if  ((*p)==2)
{       
       SDL_BlitSurface(img2,NULL,screen,&pos2);
	SDL_Flip(screen); 
          (*numero)=(*numero)+(*number)*10;
         
}
         if ((*p)==3)
{     
        SDL_BlitSurface(img2,NULL,screen,&pos3);
	SDL_Flip(screen);
        (*numero)=(*numero)+(*number);
         
}
   //printf("%d",numero);      
 
     
       
 }
  
}




void recherchenum(SDL_Surface *fond, int *num,int nclic,char temps1[],char temps2[],char temps3[],char temps4[],char temps5[],SDL_Surface *screen,int quiz )
{
    
 
/************************/

SDL_Surface  *texte1 = NULL,*texte2 = NULL,*texte3 = NULL,*texte4 = NULL,*texte5 = NULL,*textereste4,*textereste3,*textereste2,*textereste1,*textereste5,*textewelcome;

SDL_Rect position1,position,position2,position3,position4,position5,positionreste1,positionreste2,positionreste3,positionreste4,positionwelcome;

    TTF_Init();

    


TTF_Font *police = NULL,*police2 = NULL;

    SDL_Color couleurNoire = {0, 0, 0};
    SDL_Color couleurrouge = {255, 0, 0};

 police = TTF_OpenFont("comic1.ttf",18);
 police2 = TTF_OpenFont("comic2.ttf",19);
 
position.x =0;
 position.y =0;
  


 position1.x =300;
 position1.y =150;
 position2.x =300;
 position2.y =200;
 position3.x =300;
 position3.y =250;
 position4.x =300;
 position4.y =300;
 position5.x =300;
 position5.y =350;
 positionreste1.x=442;
 positionreste1.y=95;
 positionreste2.x=442;
 positionreste2.y=95;
 positionreste3.x=442;
 positionreste3.y=95;
 positionreste4.x=442;
 positionreste4.y=95;
 
    positionwelcome.x=140;
    positionwelcome.y=95;
 
 /*************************/
   
int i=0,j=0,m=0;
int a,b,c,x,y,z;
a=(*num)/100; b=((*num)%100)/10; c=((*num)%100)%10;
x=(quiz)/100; y=((quiz)%100)/10; z=((quiz)%100)%10;
       

if (a==x)
{
i++;
j++;
}

else if (a==y)
{

i++;
m++;
}

else if (a==z)
{
i++;
m++;
}


if (b==y)
{
i++;
j++;
}
else if (b==x)
{
i++;
m++;
}

else if (b==z)
{
i++;
m++;
}



if (c==z)
{
i++;
j++;
}
else if (c==x)
{
i++;
m++;
}
else if (c==y)
{
i++;
m++;
}
//}
printf("correct %d bien place %d mal place %d ",i,j,m);
textereste5= TTF_RenderText_Blended(police2, "il vous reste 5 essais", couleurrouge); 
    
textereste4= TTF_RenderText_Blended(police2, "il vous reste 4 essais", couleurrouge);

textereste3= TTF_RenderText_Blended(police2, "il vous reste 3 essais", couleurrouge);

textereste2= TTF_RenderText_Blended(police2, "il vous reste 2 essais", couleurrouge);

textereste1= TTF_RenderText_Blended(police2, "il vous reste 1 essai", couleurrouge);

textewelcome=TTF_RenderText_Blended(police2, "devinez le nombre cache", couleurrouge);



if (nclic==1)
{
     
        sprintf(temps1," %d chifre(s) correct %d bien place et %d mal place",i,j,m);
        texte1 = TTF_RenderText_Blended(police,temps1, couleurNoire);
         SDL_BlitSurface(fond, NULL, screen, &position);
        SDL_BlitSurface(texte1, NULL, screen, &position1); 
        
     SDL_BlitSurface(textereste4, NULL, screen, &positionreste4);
      SDL_BlitSurface(textewelcome, NULL, screen, &positionwelcome);
         
}
if (nclic==2)
{      
         
          sprintf(temps2," %d chifre(s) correct %d bien place et %d mal place",i,j,m);
    texte1 = TTF_RenderText_Blended(police,temps1, couleurNoire);
    texte2 = TTF_RenderText_Blended(police,temps2, couleurNoire);

SDL_BlitSurface(fond, NULL, screen, &position);
         
         SDL_BlitSurface(texte1, NULL, screen, &position1);
        SDL_BlitSurface(texte2, NULL, screen, &position2); 


                    /*****************/
       SDL_BlitSurface(textereste3, NULL, screen, &positionreste3); 
       SDL_BlitSurface(textewelcome, NULL, screen, &positionwelcome);
          
}


if (nclic==3)
{
  sprintf(temps3," %d chifre(s) correct %d bien place et %d mal place",i,j,m);
    texte1 = TTF_RenderText_Blended(police,temps1, couleurNoire);
    texte2 = TTF_RenderText_Blended(police,temps2, couleurNoire);
    texte3 = TTF_RenderText_Blended(police,temps3, couleurNoire);
    

SDL_BlitSurface(fond, NULL, screen, &position);

        
         SDL_BlitSurface(texte1, NULL, screen, &position1);
         SDL_BlitSurface(texte2, NULL, screen, &position2);
         SDL_BlitSurface(texte3, NULL, screen, &position3); 
                     /*****************/
         
        SDL_BlitSurface(textereste2, NULL, screen, &positionreste2);
        SDL_BlitSurface(textewelcome, NULL, screen, &positionwelcome);
       
}
if (nclic==4)
{
sprintf(temps4," %d chifre(s) correct %d bien place et %d mal place",i,j,m);
    texte1 = TTF_RenderText_Blended(police,temps1, couleurNoire);
    texte2 = TTF_RenderText_Blended(police,temps2, couleurNoire);
    texte3 = TTF_RenderText_Blended(police,temps3, couleurNoire);
    texte4 = TTF_RenderText_Blended(police,temps4, couleurNoire);

SDL_BlitSurface(fond, NULL, screen, &position);

        
         SDL_BlitSurface(texte1, NULL, screen, &position1);
         SDL_BlitSurface(texte2, NULL, screen, &position2);
         SDL_BlitSurface(texte3, NULL, screen, &position3);
         SDL_BlitSurface(texte4, NULL, screen, &position4);
                   /*****************/
       
          SDL_BlitSurface(textereste1, NULL, screen, &positionreste1);
          SDL_BlitSurface(textewelcome, NULL, screen, &positionwelcome);
}

  

       
SDL_Flip(screen);       
}



int gagne(int *num,int quiz)
{
    int i = 0;
    int joueurGagne = 0;
     
    int a=0,b=0,c=0,x=0,y=0,z=0;
    a=(*num)/100; b=((*num)%100)/10; c=((*num)%100)%10;
    x=(quiz)/100; y=((quiz)%100)/10; z=((quiz)%100)%10;


        if ((x==a)&&(y==b)&&(z==c))
{
            joueurGagne = 1;
}

    return joueurGagne;
}


int enigme_num (SDL_Surface *screen, temps *t)
{
 SDL_Surface graph,*win,*lose,*ts,*z0,*z1,*z2,*z3,*z4,*z5,*z6,*z7,*z8,*z9,*textereste5,*textewelcome;
  int continuer=1,a,b,a1,b1;
  int w1=0,w2=0;
  int quiz2;
  int quiz;
  int quiz3;
  
int  n10=0,n11=0,n12=0,n13=0,n14=0,n15=0,n16=0,n17=0,n18=0,n19=0;
int n20=0,n21=0,n22=0,n23=0,n24=0,n25=0,n26=0,n27=0,n28=0,n29=0;
int n30=0,n31=0,n32=0,n33=0,n34=0,n35=0,n36=0,n37=0,n38=0,n39=0;
    char temps11[100]="";
     char temps12[100]="";
    char temps13[100]="";
     char temps14[100]="";
     char temps15[100]="";
      char temps21[100]="";
     char temps22[100]="";
    char temps23[100]="";
     char temps24[100]="";
     char temps25[100]="";
      char temps31[100]="";
     char temps32[100]="";
    char temps33[100]="";
     char temps34[100]="";
     char temps35[100]="";
     
 
 

  SDL_Rect   positiongraph ,positionnum1,positionnum2,positionnum3,positionlose,positionwin,positionecran,positionts1,positionts2,positionts3,positionwelcome,positionreste5;
SDL_Event event;
TTF_Font *police = NULL;
    SDL_Color couleurrouge = {255, 0, 0};
   
   int number1=0,number2=0,number3=0;// stocke le numero proposée par l'utilisateur (retour du scanf)
int nombre_chance1 =5; // Compteur de coups restants
int nombre_chance2 =5;
int nombre_chance3 =5;
int p1=0,p2=0,p3=0,s=0;
int numero,numero2=0,numero3=0;
int n;
int nclic1=0,nclic2=0,nclic3=0 ;
enigme2 e;

int k3=1,k1=1,k2=1; //k3 mtaa el card el theltha k1 loula w k2 el thnya 

    positionnum1.x=174;
    positionnum1.y=322;

    positionnum2.x=225;
    positionnum2.y=322;

    positionnum3.x=274;
    positionnum3.y=322;

/**** init temps ****/
initialiser_temps(t);

  init_enigmee(&e);
  init_card (&e);
  afficher_card (e,screen);

 int w=0;
while (continuer==1)
{
 

 SDL_WaitEvent(&event);

        switch(event.type)
    {

case SDL_QUIT:
        continuer= 0;
        break;
    

case SDL_MOUSEBUTTONDOWN:

a=event.motion.x;
b=event.motion.y;
if(w==0)
{
if(a>196 && a<310&& b>242 && b<423)//carta 1
{  
  quiz=316;
  afficher_enigme (e,screen);
 
  	
   
afficher_temps(t,screen);  

  if (gestion_temps_enigme (t)==0)
  {
  continuer=0;
  }

w=1;

 

} 
} 

if(w==1)
{ 



police = TTF_OpenFont("comic2.ttf",19);
    if (k1==1)
{
    textereste5 = TTF_RenderText_Blended(police, "il vous reste 5 essais", couleurrouge);
        positionreste5.x =442;
        positionreste5.y =95;
        SDL_BlitSurface(textereste5, NULL, screen, &positionreste5);  
        SDL_Flip(screen);
k1=0;
}
        
afficher_temps(t,screen);  

       textewelcome = TTF_RenderText_Blended(police, "devinez le nombre cache", couleurrouge);
        positionwelcome.x =140;
        positionwelcome.y =95;
        SDL_BlitSurface(textewelcome, NULL, screen, &positionwelcome);  
        SDL_Flip(screen);

if(a> 217 && a< 240 && b>267 && b<298)//nzel aal 0
{          
         number1=0;
 nb(n10,&p1,&number1,&numero,e.nm[0],screen,positionnum1,positionnum2,positionnum3);
 n10=1;
      
}
       
if(a> 185 && a< 207 && b>144 && b<175)//nzel aal 1
{
     number1=1;
    nb(n11,&p1,&number1,&numero,e.nm[1],screen,positionnum1,positionnum2,positionnum3);
n11=1;
        
}

     
	
if(a> 218 && a< 241 && b>144 && b<175)//nzel aal 2    
{
       number1=2; 
  nb(n12,&p1,&number1,&numero,e.nm[2],screen,positionnum1,positionnum2,positionnum3);
     n12=1;  
}
     

if(a> 252 && a< 275 && b>144 && b<175)//nzel aal 3
{
     number1=3;
 nb(n13,&p1,&number1,&numero,e.nm[3],screen,positionnum1,positionnum2,positionnum3);
     n13=1;    
}
     
if(a> 185 && a< 206 && b>185 && b<214)//nzel aal 4
{
     number1=4;
 nb(n14,&p1,&number1,&numero,e.nm[4],screen,positionnum1,positionnum2,positionnum3);
   n14=1; 
}
     
if(a> 218 && a< 241 && b>185 && b<214)//nzel aal 5
{


  number1=5;
 nb(n15,&p1,&number1,&numero,e.nm[5],screen,positionnum1,positionnum2,positionnum3);
n15=1;
        
}
     

if(a> 251 && a< 274 && b>185 && b<214)//nzel aal 6
{
    number1=6;
 nb(n16,&p1,&number1,&numero,e.nm[6],screen,positionnum1,positionnum2,positionnum3);
 n16=1;
              
}
     
if(a> 185 && a< 207 && b>226 && b<256)//nzel aal 7
{
     number1=7;
 nb(n17,&p1,&number1,&numero,e.nm[7],screen,positionnum1,positionnum2,positionnum3);
 n17=1;
        
}
     
if(a> 218 && a< 241 && b>225 && b<257)//nzel aal 8
{
          number1=8;
 nb(n18,&p1,&number1,&numero,e.nm[8],screen,positionnum1,positionnum2,positionnum3);
 n18=1;
        
}
     
if(a> 252 && a<275&& b>226 && b<256)//nzel aal 9
{
     number1=9;
 nb(n19,&p1,&number1,&numero,e.nm[9],screen,positionnum1,positionnum2,positionnum3);
 n19=1;
        
}

     

 if(a>230 && a< 316 && b>360 && b<384)//postion mtaa el okay

         { 
             
             
             nclic1++;

                nombre_chance1--;
                 SDL_Flip(screen);
            
recherchenum(e.img[0],&numero,nclic1,temps11,temps12,temps13,temps14,temps15,screen,quiz);
             p1=0;
            
            n10=0,n11=0,n12=0,n13=0,n14=0,n15=0,n16=0,n17=0,n18=0,n19=0;

            SDL_BlitSurface( e.box[0],NULL,screen,&e.posbox[0]);
	    SDL_Flip(screen);
            SDL_BlitSurface( e.box[0],NULL,screen,&e.posbox[1]);
	    SDL_Flip(screen);
            SDL_BlitSurface( e.box[0],NULL,screen,&e.posbox[2]);
	    SDL_Flip(screen);
            
           
           if(gagne(&numero,quiz)==1) 
  {
        SDL_BlitSurface(e.img[1],NULL,screen,&e.posimg[1]);
	SDL_Flip(screen);
        SDL_Delay(3000);
        return 1;
     //rba7

  }
  if ((nombre_chance1==0)&&(gagne(&numero,quiz)!=1))
{

              SDL_BlitSurface(e.img[2],NULL,screen,&e.posimg[2]);
	      SDL_Flip(screen);
              SDL_Delay(3000);
              return 0;
             //khsar


  }
        afficher_temps(t,screen);  
  
      numero=0;      
         }//if
            



}






if(w1==0)
{
if(a>356 && a<470&& b>242 && b<423)//carta 2
{  quiz2=987;
  
  afficher_enigme (e,screen);	
  
w1=1;


} 
} 

if(w1==1)
{ 

    
    
police = TTF_OpenFont("comic2.ttf",19);
    if (k2==1)
{
    textereste5 = TTF_RenderText_Blended(police, "il vous reste 5 essais", couleurrouge);
        positionreste5.x =442;
        positionreste5.y =95;
        SDL_BlitSurface(textereste5, NULL, screen, &positionreste5);  
        SDL_Flip(screen);
k2=0;
}
        
afficher_temps(t,screen);  

       textewelcome = TTF_RenderText_Blended(police, "devinez le nombre cache", couleurrouge);
        positionwelcome.x =140;
        positionwelcome.y =95;
      
        SDL_BlitSurface(textewelcome, NULL,screen, &positionwelcome);  
        SDL_Flip(screen);






if(a> 217 && a< 240 && b>267 && b<298)//nzel aal 0
{          
         number2=0;
 nb(n20,&p2,&number2,&numero2,e.nm[0],screen,positionnum1,positionnum2,positionnum3);
 n20=1;
      
}
     
	
    
       
if(a> 185 && a< 207 && b>144 && b<175)//nzel aal 1
{
     number2=1;
    nb(n21,&p2,&number2,&numero2,e.nm[1],screen,positionnum1,positionnum2,positionnum3);
n21=1;
        
}

     
	
if(a> 218 && a< 241 && b>144 && b<175)//nzel aal 2    
{
       number2=2; 
  nb(n22,&p2,&number2,&numero2,e.nm[2],screen,positionnum1,positionnum2,positionnum3);
     n22=1;  
}
     

if(a> 252 && a< 275 && b>144 && b<175)//nzel aal 3
{
     number2=3;
 nb(n23,&p2,&number2,&numero2,e.nm[3],screen,positionnum1,positionnum2,positionnum3);
     n23=1;    
}
     
if(a> 185 && a< 206 && b>185 && b<214)//nzel aal 4
{
     number2=4;
 nb(n24,&p2,&number2,&numero2,e.nm[4],screen,positionnum1,positionnum2,positionnum3);
   n24=1; 
}
     
if(a> 218 && a< 241 && b>185 && b<214)//nzel aal 5
{


  number2=5;
 nb(n25,&p2,&number2,&numero2,e.nm[5],screen,positionnum1,positionnum2,positionnum3);
n25=1;
        
}
     

if(a> 251 && a< 274 && b>185 && b<214)//nzel aal 6
{
    number2=6;
 nb(n26,&p2,&number2,&numero2,e.nm[6],screen,positionnum1,positionnum2,positionnum3);
 n26=1;
              
}
     
if(a> 185 && a< 207 && b>226 && b<256)//nzel aal 7
{
     number2=7;
 nb(n27,&p2,&number2,&numero2,e.nm[7],screen,positionnum1,positionnum2,positionnum3);
 n27=1;
        
}
     
if(a> 218 && a< 241 && b>225 && b<257)//nzel aal 8
{
          number2=8;
 nb(n28,&p2,&number2,&numero2,e.nm[8],screen,positionnum1,positionnum2,positionnum3);
 n28=1;
        
}
     
if(a> 252 && a<275&& b>226 && b<256)//nzel aal 9
{
     number2=9;
 nb(n29,&p2,&number2,&numero2,e.nm[9],screen,positionnum1,positionnum2,positionnum3);
 n29=1;
        
}

     
if (gestion_temps_enigme (t) ==0)
  { 
    continuer=0;
  }


 if(a>230 && a< 316 && b>360 && b<384)//postion mtaa el okay

         { 
             
             
             nclic2++;

                nombre_chance2--;
                 SDL_Flip(screen);
   
            
recherchenum(e.img[0],&numero2,nclic2,temps21,temps22,temps23,temps24,temps25,screen,quiz2);
             p2=0;
            
            n20=0,n21=0,n22=0,n23=0,n24=0,n25=0,n26=0,n27=0,n28=0,n29=0;

            SDL_BlitSurface( e.box[0],NULL,screen,&e.posbox[0]);
	    SDL_Flip(screen);
            SDL_BlitSurface( e.box[0],NULL,screen,&e.posbox[1]);
	    SDL_Flip(screen);
            SDL_BlitSurface( e.box[0],NULL,screen,&e.posbox[2]);
	    SDL_Flip(screen);
            
           
           if(gagne(&numero2,quiz2)==1) 
  {
        SDL_BlitSurface(e.img[1],NULL,screen,&e.posimg[1]);
	SDL_Flip(screen);
        SDL_Delay(3000);
        return 1;
     //rba7

  }
  if ((nombre_chance2==0)&&(gagne(&numero2,quiz2)!=1))
{

              SDL_BlitSurface(e.img[2],NULL,screen,&e.posimg[2]);
	      SDL_Flip(screen);
        SDL_Delay(3000);
        return 0;
             //khsar


  }
   afficher_temps(t,screen);  
       
      numero2=0;      
         }//if
            



}




	
if(w2==0)
{
if(a>518 && a<634&& b>242 && b<423)//carta 3
{  quiz3=524;
  
  afficher_enigme (e,screen);	
  
w2=1;


} 
} 

if(w2==1)
{ 

    
    
police = TTF_OpenFont("comic2.ttf",19);
    if (k3==1)
{
    textereste5 = TTF_RenderText_Blended(police, "il vous reste 5 essais", couleurrouge);
        positionreste5.x =442;
        positionreste5.y =95;
        SDL_BlitSurface(textereste5, NULL, screen, &positionreste5);  
        SDL_Flip(screen);
k3=0;
}
        
afficher_temps(t,screen);  

       textewelcome = TTF_RenderText_Blended(police, "devinez le nombre cache", couleurrouge);
        positionwelcome.x =140;
        positionwelcome.y =95;
        SDL_BlitSurface(textewelcome, NULL, screen, &positionwelcome);  
        SDL_Flip(screen);






if(a> 217 && a< 240 && b>267 && b<298)//nzel aal 0
{          
         number3=0;
 nb(n30,&p3,&number3,&numero3,e.nm[0],screen,positionnum1,positionnum2,positionnum3);
 n30=1;
      
}
     
	
    
       
if(a> 185 && a< 207 && b>144 && b<175)//nzel aal 1
{
     number3=1;
    nb(n31,&p3,&number3,&numero3,e.nm[1],screen,positionnum1,positionnum2,positionnum3);
n31=1;
        
}

     
	
if(a> 218 && a< 241 && b>144 && b<175)//nzel aal 2    
{
       number3=2; 
  nb(n32,&p3,&number3,&numero3,e.nm[2],screen,positionnum1,positionnum2,positionnum3);
     n32=1;  
}
     

if(a> 252 && a< 275 && b>144 && b<175)//nzel aal 3
{
     number3=3;
 nb(n33,&p3,&number3,&numero3,e.nm[3],screen,positionnum1,positionnum2,positionnum3);
     n33=1;    
}
     
if(a> 185 && a< 206 && b>185 && b<214)//nzel aal 4
{
     number3=4;
 nb(n34,&p3,&number3,&numero3,e.nm[4],screen,positionnum1,positionnum2,positionnum3);
   n34=1; 
}
     
if(a> 218 && a< 241 && b>185 && b<214)//nzel aal 5
{


  number3=5;
 nb(n35,&p3,&number3,&numero3,e.nm[5],screen,positionnum1,positionnum2,positionnum3);
n35=1;
        
}
     

if(a> 251 && a< 274 && b>185 && b<214)//nzel aal 6
{
    number3=6;
 nb(n36,&p3,&number3,&numero3,e.nm[6],screen,positionnum1,positionnum2,positionnum3);
 n36=1;
              
}
     
if(a> 185 && a< 207 && b>226 && b<256)//nzel aal 7
{
     number3=7;
 nb(n37,&p3,&number3,&numero3,e.nm[7],screen,positionnum1,positionnum2,positionnum3);
 n37=1;
        
}
     
if(a> 218 && a< 241 && b>225 && b<257)//nzel aal 8
{
          number3=8;
 nb(n38,&p3,&number3,&numero3,e.nm[8],screen,positionnum1,positionnum2,positionnum3);
 n38=1;
        
}
     
if(a> 252 && a<275&& b>226 && b<256)//nzel aal 9
{
     number3=9;
 nb(n39,&p3,&number3,&numero3,e.nm[9],screen,positionnum1,positionnum2,positionnum3);
 n39=1;
        
}

     

 if(a>230 && a< 316 && b>360 && b<384)//postion mtaa el okay

         { 
             
             
             nclic3++;

                nombre_chance3--;
                 SDL_Flip(screen);
            
recherchenum(e.img[0],&numero3,nclic3,temps31,temps32,temps33,temps34,temps35,screen,quiz3);
             p3=0;
            
            n30=0,n31=0,n32=0,n33=0,n34=0,n35=0,n36=0,n37=0,n38=0,n39=0;

            SDL_BlitSurface( e.box[0],NULL,screen,&e.posbox[0]);
	    SDL_Flip(screen);
            SDL_BlitSurface( e.box[0],NULL,screen,&e.posbox[1]);
	    SDL_Flip(screen);
            SDL_BlitSurface( e.box[0],NULL,screen,&e.posbox[2]);
	    SDL_Flip(screen);
            
           
           if(gagne(&numero3,quiz3)==1) 
  {
        SDL_BlitSurface(e.img[1],NULL,screen,&e.posimg[1]);
	SDL_Flip(screen);
        SDL_Delay(3000);
        return 1;
     //rba7

  }
  if ((nombre_chance3==0)&&(gagne(&numero3,quiz3)!=1))
{

              SDL_BlitSurface(e.img[2],NULL,screen,&e.posimg[2]);
	      SDL_Flip(screen);
        SDL_Delay(3000);
        return 0;
             //khsar


  }
    afficher_temps(t,screen);  
      
      numero3=0;      
         }//if
            



}









break;

     


}//switch

}//while
//return 0 ;
}//final

