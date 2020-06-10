#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "enigme.h"
/**
*  @file g.c 
*  @brief enigme1 stage1.
*  @author Mohamed kalech .
* @vesion 0.1.
* @date  mai 21 ,2020
*
* version final  
*
*/
int main ()
{
SDL_Surface *ecran;
 SDL_Surface graph,*win,*lose,*ts,*z0,*z1,*z2,*z3,*z4,*z5,*z6,*z7,*z8,*z9,*textereste5,*textewelcome;
  int continuer=1,a,b,a1,b1;
  int w1=0,w2=0,w3=0;
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
int numero1,numero2=0,numero3=0;
int n;
int nclic1=0,nclic2=0,nclic3=0 ;
enigme2 e;

int k3=1,k1=1,k2=1;            //k3 mtaa el card el theltha k1 loula w k2 el thnya 



    


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
  init_card (&e);
  afficher_card (e,ecran);

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
if(w1==0)
{
if(a>163 && a<245&& b>222 && b<370)//carta 1
{  
  quiz=169;
  afficher_enigme (e,ecran);	
  
w1=1;


} 
} 

if(w1==1)
{ 

    
    
police = TTF_OpenFont("comic2.ttf",19);
    if (k1==1)
{
    textereste5 = TTF_RenderText_Blended(police, "il vous reste 5 essais", couleurrouge);
        positionreste5.x =442;
        positionreste5.y =95;
        SDL_BlitSurface(textereste5, NULL, ecran, &positionreste5);  
        SDL_Flip(ecran);
k1=0;
}
        

       textewelcome = TTF_RenderText_Blended(police, "devinez le nombre cache", couleurrouge);
        positionwelcome.x =140;
        positionwelcome.y =95;
        SDL_BlitSurface(textewelcome, NULL, ecran, &positionwelcome);  
        SDL_Flip(ecran);






if(a> 217 && a< 240 && b>267 && b<298)//nzel aal 0
{          
         number1=0;
 nb(n10,&p1,&number1,&numero1,e.nm[0],ecran,positionnum1,positionnum2,positionnum3);
 n10=1;
      
}
     
	
    
       
if(a> 185 && a< 207 && b>144 && b<175)//nzel aal 1
{
     number1=1;
    nb(n11,&p1,&number1,&numero1,e.nm[1],ecran,positionnum1,positionnum2,positionnum3);
n11=1;
        
}

     
	
if(a> 218 && a< 241 && b>144 && b<175)//nzel aal 2    
{
       number1=2; 
  nb(n12,&p1,&number1,&numero1,e.nm[2],ecran,positionnum1,positionnum2,positionnum3);
     n12=1;  
}
     

if(a> 252 && a< 275 && b>144 && b<175)//nzel aal 3
{
     number1=3;
 nb(n13,&p1,&number1,&numero1,e.nm[3],ecran,positionnum1,positionnum2,positionnum3);
     n13=1;    
}
     
if(a> 185 && a< 206 && b>185 && b<214)//nzel aal 4
{
     number1=4;
 nb(n14,&p1,&number1,&numero1,e.nm[4],ecran,positionnum1,positionnum2,positionnum3);
   n14=1; 
}
     
if(a> 218 && a< 241 && b>185 && b<214)//nzel aal 5
{


  number1=5;
 nb(n15,&p1,&number1,&numero1,e.nm[5],ecran,positionnum1,positionnum2,positionnum3);
n15=1;
        
}
     

if(a> 251 && a< 274 && b>185 && b<214)//nzel aal 6
{
    number1=6;
 nb(n16,&p1,&number1,&numero1,e.nm[6],ecran,positionnum1,positionnum2,positionnum3);
 n16=1;
              
}
     
if(a> 185 && a< 207 && b>226 && b<256)//nzel aal 7
{
     number1=7;
 nb(n17,&p1,&number1,&numero1,e.nm[7],ecran,positionnum1,positionnum2,positionnum3);
 n17=1;
        
}
     
if(a> 218 && a< 241 && b>225 && b<257)//nzel aal 8
{
          number1=8;
 nb(n18,&p1,&number1,&numero1,e.nm[8],ecran,positionnum1,positionnum2,positionnum3);
 n18=1;
        
}
     
if(a> 252 && a<275&& b>226 && b<256)//nzel aal 9
{
     number1=9;
 nb(n19,&p1,&number1,&numero1,e.nm[9],ecran,positionnum1,positionnum2,positionnum3);
 n19=1;
        
}

     

 if(a>230 && a< 316 && b>360 && b<384)//postion mtaa el okay

         { 
             
             
             nclic1++;

                nombre_chance1--;
                 SDL_Flip(ecran);
            
recherchenum(e.img[0],&numero1,nclic1,temps11,temps12,temps13,temps14,temps15,ecran,quiz);
             p1=0;
            
            n10=0,n11=0,n12=0,n13=0,n14=0,n15=0,n16=0,n17=0,n18=0,n19=0;

            SDL_BlitSurface( e.box[0],NULL,ecran,&e.posbox[0]);
	    SDL_Flip(ecran);
            SDL_BlitSurface( e.box[0],NULL,ecran,&e.posbox[1]);
	    SDL_Flip(ecran);
            SDL_BlitSurface( e.box[0],NULL,ecran,&e.posbox[2]);
	    SDL_Flip(ecran);
            
           
           if(gagne(&numero1,quiz)==1) 
  {
        SDL_BlitSurface(e.img[1],NULL,ecran,&e.posimg[1]);

	SDL_Flip(ecran);
     //rba7

  }
  if ((nombre_chance1==0)&&(gagne(&numero1,quiz)!=1))
{

              SDL_BlitSurface(e.img[2],NULL,ecran,&e.posimg[2]);

	      SDL_Flip(ecran);
             //khsar


  }
          
      numero1=0;      
         }//if
            



}






if(w2==0)
{
if(a>295 && a<384&& b>222 && b<370)//carta 2
{  quiz2=641;
  
  afficher_enigme (e,ecran);	
  
w2=1;


} 
} 

if(w2==1)
{ 

    
    
police = TTF_OpenFont("comic2.ttf",19);
    if (k2==1)
{
    textereste5 = TTF_RenderText_Blended(police, "il vous reste 5 essais", couleurrouge);
        positionreste5.x =442;
        positionreste5.y =95;
        SDL_BlitSurface(textereste5, NULL, ecran, &positionreste5);  
        SDL_Flip(ecran);
k2=0;
}
        

       textewelcome = TTF_RenderText_Blended(police, "devinez le nombre cache", couleurrouge);
        positionwelcome.x =140;
        positionwelcome.y =95;
        SDL_BlitSurface(textewelcome, NULL, ecran, &positionwelcome);  
        SDL_Flip(ecran);






if(a> 217 && a< 240 && b>267 && b<298)//nzel aal 0
{          
         number2=0;
 nb(n20,&p2,&number2,&numero2,e.nm[0],ecran,positionnum1,positionnum2,positionnum3);
 n20=1;
      
}
     
	
    
       
if(a> 185 && a< 207 && b>144 && b<175)//nzel aal 1
{
     number2=1;
    nb(n21,&p2,&number2,&numero2,e.nm[1],ecran,positionnum1,positionnum2,positionnum3);
n21=1;
        
}

     
	
if(a> 218 && a< 241 && b>144 && b<175)//nzel aal 2    
{
       number2=2; 
  nb(n22,&p2,&number2,&numero2,e.nm[2],ecran,positionnum1,positionnum2,positionnum3);
     n22=1;  
}
     

if(a> 252 && a< 275 && b>144 && b<175)//nzel aal 3
{
     number2=3;
 nb(n23,&p2,&number2,&numero2,e.nm[3],ecran,positionnum1,positionnum2,positionnum3);
     n23=1;    
}
     
if(a> 185 && a< 206 && b>185 && b<214)//nzel aal 4
{
     number2=4;
 nb(n24,&p2,&number2,&numero2,e.nm[4],ecran,positionnum1,positionnum2,positionnum3);
   n24=1; 
}
     
if(a> 218 && a< 241 && b>185 && b<214)//nzel aal 5
{


  number2=5;
 nb(n25,&p2,&number2,&numero2,e.nm[5],ecran,positionnum1,positionnum2,positionnum3);
n25=1;
        
}
     

if(a> 251 && a< 274 && b>185 && b<214)//nzel aal 6
{
    number2=6;
 nb(n26,&p2,&number2,&numero2,e.nm[6],ecran,positionnum1,positionnum2,positionnum3);
 n26=1;
              
}
     
if(a> 185 && a< 207 && b>226 && b<256)//nzel aal 7
{
     number2=7;
 nb(n27,&p2,&number2,&numero2,e.nm[7],ecran,positionnum1,positionnum2,positionnum3);
 n27=1;
        
}
     
if(a> 218 && a< 241 && b>225 && b<257)//nzel aal 8
{
          number2=8;
 nb(n28,&p2,&number2,&numero2,e.nm[8],ecran,positionnum1,positionnum2,positionnum3);
 n28=1;
        
}
     
if(a> 252 && a<275&& b>226 && b<256)//nzel aal 9
{
     number2=9;
 nb(n29,&p2,&number2,&numero2,e.nm[9],ecran,positionnum1,positionnum2,positionnum3);
 n29=1;
        
}

     

 if(a>230 && a< 316 && b>360 && b<384)//postion mtaa el okay

         { 
             
             
             nclic2++;

                nombre_chance2--;
                 SDL_Flip(ecran);
   
            
recherchenum(e.img[0],&numero2,nclic2,temps21,temps22,temps23,temps24,temps25,ecran,quiz2);
             p2=0;
            
            n20=0,n21=0,n22=0,n23=0,n24=0,n25=0,n26=0,n27=0,n28=0,n29=0;

            SDL_BlitSurface( e.box[0],NULL,ecran,&e.posbox[0]);
	    SDL_Flip(ecran);
            SDL_BlitSurface( e.box[0],NULL,ecran,&e.posbox[1]);
	    SDL_Flip(ecran);
            SDL_BlitSurface( e.box[0],NULL,ecran,&e.posbox[2]);
	    SDL_Flip(ecran);
            
           
           if(gagne(&numero2,quiz2)==1) 
  {
        SDL_BlitSurface(e.img[1],NULL,ecran,&e.posimg[1]);

	SDL_Flip(ecran);
     //rba7

  }
  if ((nombre_chance2==0)&&(gagne(&numero2,quiz2)!=1))
{

              SDL_BlitSurface(e.img[2],NULL,ecran,&e.posimg[2]);

	      SDL_Flip(ecran);
             //khsar


  }
          
      numero2=0;      
         }//if
            



}




	
if(w3==0)
{
if(a>430 && a<522&& b>222 && b<370)//carta 3
{  quiz3=645;
  
  afficher_enigme (e,ecran);	
  
w3=1;


} 
} 

if(w3==1)
{ 

    
    
police = TTF_OpenFont("comic2.ttf",19);
    if (k3==1)
{
    textereste5 = TTF_RenderText_Blended(police, "il vous reste 5 essais", couleurrouge);
        positionreste5.x =442;
        positionreste5.y =95;
        SDL_BlitSurface(textereste5, NULL, ecran, &positionreste5);  
        SDL_Flip(ecran);
k3=0;
}
        

       textewelcome = TTF_RenderText_Blended(police, "devinez le nombre cache", couleurrouge);
        positionwelcome.x =140;
        positionwelcome.y =95;
        SDL_BlitSurface(textewelcome, NULL, ecran, &positionwelcome);  
        SDL_Flip(ecran);






if(a> 217 && a< 240 && b>267 && b<298)//nzel aal 0
{          
         number3=0;
 nb(n30,&p3,&number3,&numero3,e.nm[0],ecran,positionnum1,positionnum2,positionnum3);
 n30=1;
      
}
     
	
    
       
if(a> 185 && a< 207 && b>144 && b<175)//nzel aal 1
{
     number3=1;
    nb(n31,&p3,&number3,&numero3,e.nm[1],ecran,positionnum1,positionnum2,positionnum3);
n31=1;
        
}

     
	
if(a> 218 && a< 241 && b>144 && b<175)//nzel aal 2    
{
       number3=2; 
  nb(n32,&p3,&number3,&numero3,e.nm[2],ecran,positionnum1,positionnum2,positionnum3);
     n32=1;  
}
     

if(a> 252 && a< 275 && b>144 && b<175)//nzel aal 3
{
     number3=3;
 nb(n33,&p3,&number3,&numero3,e.nm[3],ecran,positionnum1,positionnum2,positionnum3);
     n33=1;    
}
     
if(a> 185 && a< 206 && b>185 && b<214)//nzel aal 4
{
     number3=4;
 nb(n34,&p3,&number3,&numero3,e.nm[4],ecran,positionnum1,positionnum2,positionnum3);
   n34=1; 
}
     
if(a> 218 && a< 241 && b>185 && b<214)//nzel aal 5
{


  number3=5;
 nb(n35,&p3,&number3,&numero3,e.nm[5],ecran,positionnum1,positionnum2,positionnum3);
n35=1;
        
}
     

if(a> 251 && a< 274 && b>185 && b<214)//nzel aal 6
{
    number3=6;
 nb(n36,&p3,&number3,&numero3,e.nm[6],ecran,positionnum1,positionnum2,positionnum3);
 n36=1;
              
}
     
if(a> 185 && a< 207 && b>226 && b<256)//nzel aal 7
{
     number3=7;
 nb(n37,&p3,&number3,&numero3,e.nm[7],ecran,positionnum1,positionnum2,positionnum3);
 n37=1;
        
}
     
if(a> 218 && a< 241 && b>225 && b<257)//nzel aal 8
{
          number3=8;
 nb(n38,&p3,&number3,&numero3,e.nm[8],ecran,positionnum1,positionnum2,positionnum3);
 n38=1;
        
}
     
if(a> 252 && a<275&& b>226 && b<256)//nzel aal 9
{
     number3=9;
 nb(n39,&p3,&number3,&numero3,e.nm[9],ecran,positionnum1,positionnum2,positionnum3);
 n39=1;
        
}

     

 if(a>230 && a< 316 && b>360 && b<384)//postion mtaa el okay

         { 
             
             
             nclic3++;

                nombre_chance3--;
                 SDL_Flip(ecran);
            
recherchenum(e.img[0],&numero3,nclic3,temps31,temps32,temps33,temps34,temps35,ecran,quiz3);
             p3=0;
            
            n30=0,n31=0,n32=0,n33=0,n34=0,n35=0,n36=0,n37=0,n38=0,n39=0;

            SDL_BlitSurface( e.box[0],NULL,ecran,&e.posbox[0]);
	    SDL_Flip(ecran);
            SDL_BlitSurface( e.box[0],NULL,ecran,&e.posbox[1]);
	    SDL_Flip(ecran);
            SDL_BlitSurface( e.box[0],NULL,ecran,&e.posbox[2]);
	    SDL_Flip(ecran);
            
           
           if(gagne(&numero3,quiz3)==1) 
  {
        SDL_BlitSurface(e.img[1],NULL,ecran,&e.posimg[1]);

	SDL_Flip(ecran);
     //rba7

  }
  if ((nombre_chance3==0)&&(gagne(&numero3,quiz3)!=1))
{

              SDL_BlitSurface(e.img[2],NULL,ecran,&e.posimg[2]);

	      SDL_Flip(ecran);
             //khsar


  }
          
      numero3=0;      
         }//if
            



}





     




break;


}//switch

}//while
return 0 ;
}//final
