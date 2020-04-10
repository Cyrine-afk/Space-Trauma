/*
************enigme mohamed***********
************      lvl1 *****************
************sans partition**********
**************sans ttf **************


*/
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>


void recherchenum(int num )//n bech tji bahdha el nm el fouk
{
    int n=316;
int i=0,j=0,m=0;
int a,b,c,x,y,z;
a=(num)/100; b=((num)%100)/10; c=((num)%100)%10;
x=(n)/100; y=((n)%100)/10; z=((n)%100)%10;

if (a==x)
{
i++;
j++;
}

else {
 if (a==y)
{
i++;
m++;
}

else if (a==z)
{
i++;
m++;
}
}

if (b==y)
{
i++;
j++;
}
else {
  if (b==x)
{
i++;
m++;
}

else if (b==z)
{
i++;
m++;
}
}


if (c==z)
{
i++;
j++;
}
else {
 if (c==x)
{
i++;
m++;
}
else if (c==y)
{
i++;
m++;
}
}





printf(" %d chifre(s) correct %d bien place et %d mal place",i,j,m);
}


int gagne(int num)//bech tji bahdha el nm el fouk
{
    int i = 0;
    int joueurGagne = 0;
     int n=316 ;
    int a,b,c,x,y,z;
    a=(num)/100; b=((num)%100)/10; c=((num)%100)%10;
    x=(n)/100; y=((n)%100)/10; z=((n)%100)%10;


        if ((x==a)&&(y==b)&&(z==c))
{
            joueurGagne = 1;
}

    return joueurGagne;
}









int main()//bech nhot el n
{
 SDL_Surface *ecran;
 SDL_Surface *graph,*win,*lose,*ts,*z0,*z1,*z2,*z3,*z4,*z5,*z6,*z7,*z8,*z9;
  int continuer=1,a,b;
int  n0=0,n1=0,n2=0,n3=0,n4=0,n5=0,n6=0,n7=0,n8=0,n9=0;
 

  SDL_Rect   positiongraph ,positionnum1,positionnum2,positionnum3,positiont,positionlose,positionwin,positionecran,positionts1,positionts2,positionts3 ;
SDL_Event event;
    


 if(SDL_Init(SDL_INIT_VIDEO)!=0)
{
printf("Unable :%s\n",SDL_GetError());
return(1);

}
ecran=SDL_SetVideoMode(730,530,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
if(ecran==NULL)
{
printf("erreur screen:%s\n",SDL_GetError());
return(1);
}
positionecran.x=0;
positionecran.y=0;
 
    positionnum1.x=174;
    positionnum1.y=322;

    positionnum2.x=225;
    positionnum2.y=322;

    positionnum3.x=274;
    positionnum3.y=322;


    positiont.x = 60;
    positiont.y = 370;
    positionlose.x=0;
    positionlose.y=0;
     positionwin.x=0;
    positionwin.y=0;
    positiongraph.x=0;
    positiongraph.y=0;

    positionts1.x=153;
    positionts1.y=312;
  
    positionts2.x=205;
    positionts2.y=312;

    positionts3.x=257;
    positionts3.y=312;
        

    	


        win=IMG_Load("win.png");
        if(win==NULL)
{
printf("erreur win:%s\n",SDL_GetError());
return(1);
}


  z0=IMG_Load("0.png");
        if(z0==NULL)
{
printf("erreur fel 0:%s\n",SDL_GetError());
return(1);
}

z1=IMG_Load("1.png");
        if(z1==NULL)
{
printf("erreur fel 1:%s\n",SDL_GetError());
return(1);
}

z2=IMG_Load("2.png");
        if(z2==NULL)
{
printf("erreur fel 2:%s\n",SDL_GetError());
return(1);
}

z3=IMG_Load("3.png");
        if(z3==NULL)
{
printf("erreur fel 3:%s\n",SDL_GetError());
return(1);
}

z4=IMG_Load("4.png");
        if(z4==NULL)
{
printf("erreur fel 4:%s\n",SDL_GetError());
return(1);
}

z5=IMG_Load("5.png");
        if(z5==NULL)
{
printf("erreur fel 5:%s\n",SDL_GetError());
return(1);
}

z6=IMG_Load("6.png");
        if(z6==NULL)
{
printf("erreur fel 6:%s\n",SDL_GetError());
return(1);
}

z7=IMG_Load("7.png");
        if(z7==NULL)
{
printf("erreur fel 7:%s\n",SDL_GetError());
return(1);
}
z8=IMG_Load("8.png");
        if(z8==NULL)
{
printf("erreur fel 8:%s\n",SDL_GetError());
return(1);
}
z9=IMG_Load("9.png");
        if(z9==NULL)
{
printf("erreur fel 9:%s\n",SDL_GetError());
return(1);
}


        lose=IMG_Load("lose.png");
if(lose==NULL)
{
printf("erreur lose:%s\n",SDL_GetError());
return(1);
}
        graph=SDL_LoadBMP("em3.bmp");
        if(graph==NULL)
{
printf("erreur graph:%s\n",SDL_GetError());
return(1);
}


        ts=IMG_Load("ts.png");
if(ts==NULL)
{
printf("erreur ts:%s\n",SDL_GetError());
return(1);
}
 
 
SDL_BlitSurface(graph,NULL,ecran,&positiongraph);
	SDL_Flip(ecran);

  	
//bel ttf printf("il vous reste %d coups",nombre_chance);




int number;// stocke le numero proposée par l'utilisateur (retour du scanf)
int nombre_chance =7; // Compteur de coups restants
int p=0,s=0;
int numero=0;
int n=0;






  

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


//while (gagne(numero)==0)
{
do {
case SDL_MOUSEBUTTONDOWN:
a=event.motion.x;
b=event.motion.y;
if(a> 217 && a< 240 && b>267 && b<298)//nzel aal 0
{
     
    if (n0==0)
      { n0=1;
        p++;
         number=0;
      if (p==1)
{
      SDL_BlitSurface(z0,NULL,ecran,&positionnum1);
	SDL_Flip(ecran);
       
         numero=numero+number*100;
}
        if  (p==2)
{
       SDL_BlitSurface(z0,NULL,ecran,&positionnum2);
	SDL_Flip(ecran);
         numero=numero+number*10;
}
       if (p==3)
{
        SDL_BlitSurface(z0,NULL,ecran,&positionnum3);
	SDL_Flip(ecran);
         numero=numero+number;
}
       if (p>=4)
{
        printf("lezem tvalidi 3 arkam kahaw");
       //p==0;
}
 
        
 }

         
        
}
     
	
    
       
if(a> 185 && a< 207 && b>144 && b<175)//nzel aal 1
{
     
    if (n1==0)//variable lzem yetbadel
      { n1=1;
        p++;
         number=1;
      if (p==1)
{      
       
      SDL_BlitSurface(z1,NULL,ecran,&positionnum1);
	SDL_Flip(ecran);
       
         numero=numero+number*100;
}
        if  (p==2)
{       
       SDL_BlitSurface(z1,NULL,ecran,&positionnum2);
	SDL_Flip(ecran);
         numero=numero+number*10;
}
         if (p==3)
{     
        SDL_BlitSurface(z1,NULL,ecran,&positionnum3);
	SDL_Flip(ecran);
         numero=numero+number;
}
        if (p>=4)
{
        printf("lezem tvalidi 3 arkam kahaw");
       //p==0;
}
 
        
 }

         
        
}
     
	
if(a> 218 && a< 241 && b>144 && b<175)//nzel aal 2    
{
     
    if (n2==0)
      { n2=1;
        p++;
         number=2;
      if (p==1)
{
      SDL_BlitSurface(z2,NULL,ecran,&positionnum1);
	SDL_Flip(ecran);
       
         numero=numero+number*100;
}
        if  (p==2)
{
       SDL_BlitSurface(z2,NULL,ecran,&positionnum2);
	SDL_Flip(ecran);
         numero=numero+number*10;
}
        if (p==3)
{
        SDL_BlitSurface(z2,NULL,ecran,&positionnum3);
	SDL_Flip(ecran);
         numero=numero+number;
}
        if (p>=4)
{
        printf("lezem tvalidi 3 arkam kahaw");
       //p==0;
}
 
        
 }

         
        
}
     

if(a> 252 && a< 275 && b>144 && b<175)//nzel aal 3
{
     
    if (n3==0)
      { n3=1;
        p++;
         number=3;
      if (p==1)
{
      SDL_BlitSurface(z3,NULL,ecran,&positionnum1);
	SDL_Flip(ecran);
       
         numero=numero+number*100;
}
        if  (p==2)
{
       SDL_BlitSurface(z3,NULL,ecran,&positionnum2);
	SDL_Flip(ecran);
         numero=numero+number*10;
}
        if (p==3)
{
        SDL_BlitSurface(z3,NULL,ecran,&positionnum3);
	SDL_Flip(ecran);
         numero=numero+number;
}
        if (p>=4)
{
        printf("lezem tvalidi 3 arkam kahaw");
       //p==0;
}
 
        
 }

         
        
}
     
if(a> 185 && a< 206 && b>185 && b<214)//nzel aal 4
{
     
    if (n4==0)
      { n4=1;
        p++;
         number=4;
      if (p==1)
{
      SDL_BlitSurface(z4,NULL,ecran,&positionnum1);
	SDL_Flip(ecran);
       
         numero=numero+number*100;
}
        if  (p==2)
{
       SDL_BlitSurface(z4,NULL,ecran,&positionnum2);
	SDL_Flip(ecran);
         numero=numero+number*10;
}
        if (p==3)
{
        SDL_BlitSurface(z4,NULL,ecran,&positionnum3);
	SDL_Flip(ecran);
         numero=numero+number;
}
        if (p>=4)
{
        printf("lezem tvalidi 3 arkam kahaw");
       //p==0;
}
 
        
 }

         
        
}
     
if(a> 218 && a< 241 && b>185 && b<214)//nzel aal 5
{
     
    if (n5==0)
      { n5=1;
        p++;
         number=5;
      if (p==1)
{
      SDL_BlitSurface(z5,NULL,ecran,&positionnum1);
	SDL_Flip(ecran);
       
         numero=numero+number*100;
}
        if  (p==2)
{
       SDL_BlitSurface(z5,NULL,ecran,&positionnum2);
	SDL_Flip(ecran);
         numero=numero+number*10;
}
        if (p==3)
{
        SDL_BlitSurface(z5,NULL,ecran,&positionnum3);
	SDL_Flip(ecran);
         numero=numero+number;
}
        if (p>=4)
{
        printf("lezem tvalidi 3 arkam kahaw");
       //p==0;
}
 
        
 }

         
        
}
     

if(a> 251 && a< 274 && b>185 && b<214)//nzel aal 6
{
     
    if (n6==0)
      { n6=1;
        p++;
         number=6;
      if (p==1)
{
      SDL_BlitSurface(z6,NULL,ecran,&positionnum1);
	SDL_Flip(ecran);
       
         numero=numero+number*100;
}
        if  (p==2)
{
       SDL_BlitSurface(z6,NULL,ecran,&positionnum2);
	SDL_Flip(ecran);
         numero=numero+number*10;
}
        if (p==3)
{
        SDL_BlitSurface(z6,NULL,ecran,&positionnum3);
	SDL_Flip(ecran);
         numero=numero+number;
}
        if (p>=4)
{
        printf("lezem tvalidi 3 arkam kahaw");
      // p==0;
}
 
        
 }

         
        
}
     
if(a> 185 && a< 207 && b>226 && b<256)//nzel aal 7
{
     
    if (n7==0)
      { n7=1;
        p++;
         number=7;
      if (p==1)
{
      SDL_BlitSurface(z7,NULL,ecran,&positionnum1);
	SDL_Flip(ecran);
       
         numero=numero+number*100;
}
        if  (p==2)
{
       SDL_BlitSurface(z7,NULL,ecran,&positionnum2);
	SDL_Flip(ecran);
         numero=numero+number*10;
}
        if (p==3)
{
        SDL_BlitSurface(z7,NULL,ecran,&positionnum3);
	SDL_Flip(ecran);
         numero=numero+number;
}
        if (p>=4)
{
        printf("lezem tvalidi 3 arkam kahaw");
      // p==0;
}
 
        
 }

         
        
}
     
if(a> 218 && a< 241 && b>225 && b<257)//nzel aal 8
{
     
    if (n8==0)
      { n8=1;
        p++;
         number=8;
      if (p==1)
{
      SDL_BlitSurface(z8,NULL,ecran,&positionnum1);
	SDL_Flip(ecran);
       
         numero=numero+number*100;
}
        if  (p==2)
{
       SDL_BlitSurface(z8,NULL,ecran,&positionnum2);
	SDL_Flip(ecran);
         numero=numero+number*10;
}
        if (p==3)
{
        SDL_BlitSurface(z8,NULL,ecran,&positionnum3);
	SDL_Flip(ecran);
         numero=numero+number;
}
        if (p>=4)
{
        printf("lezem tvalidi 3 arkam kahaw");
      // p==0;
}
 
        
 }

         
        
}
     
if(a> 252 && a<275&& b>226 && b<256)//nzel aal 9
{
     
    if (n9==0)
      { n9=1;
        p++;
         number=9;
      if (p==1)
{
      SDL_BlitSurface(z9,NULL,ecran,&positionnum1);
	SDL_Flip(ecran);
       
         numero=numero+number*100;
}
        if  (p==2)
{
       SDL_BlitSurface(z9,NULL,ecran,&positionnum2);
	SDL_Flip(ecran);
         numero=numero+number*10;
}
        if (p==3)
{
        SDL_BlitSurface(z9,NULL,ecran,&positionnum3);
	SDL_Flip(ecran);
         numero=numero+number;
}
        if (p>=4)
{
        printf("lezem tvalidi 3 arkam kahaw");
       //p==0;
}
 
        
 }

         
        
}
     
        
        





 


 if(a>230 && a< 316 && b>360 && b<384)//postion mtaa el okay

         { 

             nombre_chance--;
            //flip lel ttf mtaa nbr de chance

            recherchenum(numero );  //update lel parametre mtaa recherchnum
            
              p=0;
            n0=0,n1=0,n2=0,n3=0,n4=0,n5=0,n6=0,n7=0,n8=0,n9=0;
            

            SDL_BlitSurface(ts,NULL,ecran,&positionts1);
	    SDL_Flip(ecran);
            SDL_BlitSurface(ts,NULL,ecran,&positionts2);
	    SDL_Flip(ecran);
            SDL_BlitSurface(ts,NULL,ecran,&positionts3);
	    SDL_Flip(ecran);
            
           
           if((gagne(numero)==1)&&(nombre_chance>=1)) //update lel parametre mtaa gagne
  {
        SDL_BlitSurface(win,NULL,ecran,&positionwin);

	SDL_Flip(ecran);
     //rba7

  }
  if ((nombre_chance==0)&&(gagne(numero)!=1))//update lel parametre mtaa gagne
{

              SDL_BlitSurface(lose,NULL,ecran,&positionlose);

	      SDL_Flip(ecran);
             //khsar


  }
          
      numero=0;      
         }
            
break;
}while (p!=3);

        
 }    
          
}//switch
         
	








}//while


    SDL_FreeSurface(ecran);
    SDL_Quit;


       return 0;

}





/*int maint() 
{
int x=1,n;

}*/
