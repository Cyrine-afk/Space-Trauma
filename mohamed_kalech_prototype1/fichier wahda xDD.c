#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "enigme.h"


int main()
{

 SDL_Surface *ecran;
 SDL_Surface graph,*win,*lose,*ts,*z0,*z1,*z2,*z3,*z4,*z5,*z6,*z7,*z8,*z9,*textereste5,*textewelcome;
  int continuer=1,a,b;
int  n0=0,n1=0,n2=0,n3=0,n4=0,n5=0,n6=0,n7=0,n8=0,n9=0;
    char temps1[100]="";
     char temps2[100]="";
    char temps3[100]="";
     char temps4[100]="";
     char temps5[100]="";
     
 
 

  SDL_Rect   positiongraph ,positionnum1,positionnum2,positionnum3,positionlose,positionwin,positionecran,positionts1,positionts2,positionts3,positionwelcome,positionreste5;
SDL_Event event;
TTF_Font *police = NULL;
    SDL_Color couleurrouge = {255, 0, 0};
   
   int number=0;// stocke le numero proposée par l'utilisateur (retour du scanf)
int nombre_chance =5; // Compteur de coups restants
int p=0,s=0;
int numero=0;
int n;
int nclic=0 ;
enigme2 e;

    


 if(SDL_Init(SDL_INIT_VIDEO)!=0)
{
printf("Unable :%s\n",SDL_GetError());
return(1);

}



 TTF_Init();
ecran=SDL_SetVideoMode(730,530,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
if(ecran==NULL)
{
printf("erreur screen:%s\n",SDL_GetError());
return(1);
}

    positionnum1.x=174;
    positionnum1.y=322;

    positionnum2.x=225;
    positionnum2.y=322;

    positionnum3.x=274;
    positionnum3.y=322;


         init_enigme(&e);
  	 afficher_enigme (e,ecran); 
police = TTF_OpenFont("comic2.ttf",19);
    
    textereste5 = TTF_RenderText_Blended(police, "il vous reste 5 essais", couleurrouge);
        positionreste5.x =442;
        positionreste5.y =95;
        SDL_BlitSurface(textereste5, NULL, ecran, &positionreste5);  
        SDL_Flip(ecran);
        

       textewelcome = TTF_RenderText_Blended(police, "devinez le nombre cache", couleurrouge);
        positionwelcome.x =140;
        positionwelcome.y =95;
        SDL_BlitSurface(textewelcome, NULL, ecran, &positionwelcome);  
        SDL_Flip(ecran);




 
  

while (continuer==1)
{ 
  
 
   

   SDL_WaitEvent(&event);

        switch(event.type)
        {

    case SDL_QUIT:
        continuer= 0;
        break;
    
  
        
        case SDL_KEYDOWN:
    switch(event.key.keysym.sym)
    { 
                case SDLK_ESCAPE:
               

                 continuer=0;
                  
                  break;
    }



{


case SDL_MOUSEBUTTONDOWN:
a=event.motion.x;
b=event.motion.y;
if(a> 217 && a< 240 && b>267 && b<298)//nzel aal 0
{          
         number=0;
 nb(n0,&p,&number,&numero,e.nm[0],ecran,positionnum1,positionnum2,positionnum3);
 n0=1;
      
}
     
	
    
       
if(a> 185 && a< 207 && b>144 && b<175)//nzel aal 1
{
     number=1;
    nb(n1,&p,&number,&numero,e.nm[1],ecran,positionnum1,positionnum2,positionnum3);
n1=1;
        
}

     
	
if(a> 218 && a< 241 && b>144 && b<175)//nzel aal 2    
{
       number=2; 
  nb(n2,&p,&number,&numero,e.nm[2],ecran,positionnum1,positionnum2,positionnum3);
     n2=1;  
}
     

if(a> 252 && a< 275 && b>144 && b<175)//nzel aal 3
{
     number=3;
 nb(n3,&p,&number,&numero,e.nm[3],ecran,positionnum1,positionnum2,positionnum3);
     n3=1;    
}
     
if(a> 185 && a< 206 && b>185 && b<214)//nzel aal 4
{
     number=4;
 nb(n4,&p,&number,&numero,e.nm[4],ecran,positionnum1,positionnum2,positionnum3);
   n4=1; 
}
     
if(a> 218 && a< 241 && b>185 && b<214)//nzel aal 5
{


  number=5;
 nb(n5,&p,&number,&numero,e.nm[5],ecran,positionnum1,positionnum2,positionnum3);
n5=1;
        
}
     

if(a> 251 && a< 274 && b>185 && b<214)//nzel aal 6
{
    number=6;
 nb(n6,&p,&number,&numero,e.nm[6],ecran,positionnum1,positionnum2,positionnum3);
 n6=1;
              
}
     
if(a> 185 && a< 207 && b>226 && b<256)//nzel aal 7
{
     number=7;
 nb(n7,&p,&number,&numero,e.nm[7],ecran,positionnum1,positionnum2,positionnum3);
 n7=1;
        
}
     
if(a> 218 && a< 241 && b>225 && b<257)//nzel aal 8
{
          number=8;
 nb(n8,&p,&number,&numero,e.nm[8],ecran,positionnum1,positionnum2,positionnum3);
 n8=1;
        
}
     
if(a> 252 && a<275&& b>226 && b<256)//nzel aal 9
{
     number=9;
 nb(n9,&p,&number,&numero,e.nm[9],ecran,positionnum1,positionnum2,positionnum3);
 n9=1;
        
}

     

 if(a>230 && a< 316 && b>360 && b<384)//postion mtaa el okay

         { 
             
             
             nclic++;

                nombre_chance--;
                 SDL_Flip(ecran);
            
recherchenum(e.img[0],&numero,nclic,temps1,temps2,temps3,temps4,temps5,ecran,quiz);
             p=0;
            
            n0=0,n1=0,n2=0,n3=0,n4=0,n5=0,n6=0,n7=0,n8=0,n9=0;

            SDL_BlitSurface( e.box[0],NULL,ecran,&e.posbox[0]);
	    SDL_Flip(ecran);
            SDL_BlitSurface( e.box[0],NULL,ecran,&e.posbox[1]);
	    SDL_Flip(ecran);
            SDL_BlitSurface( e.box[0],NULL,ecran,&e.posbox[2]);
	    SDL_Flip(ecran);
            
           
           if(gagne(&numero)==1) 
  {
        SDL_BlitSurface(e.img[1],NULL,ecran,&e.posimg[1]);

	SDL_Flip(ecran);
     //rba7

  }
  if ((nombre_chance==0)&&(gagne(&numero)!=1))
{

              SDL_BlitSurface(e.img[2],NULL,ecran,&e.posimg[2]);

	      SDL_Flip(ecran);
             //khsar


  }
          
      numero=0;      
         }
            
break;
//}while (p!=3);

        
 }    
          
}//switch
         
	



}//while


   
    


       return 0;

}






