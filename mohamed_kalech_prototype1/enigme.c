#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "enigme.h"

/**
*  @file enigme.c 
*  @brief enigme1 stage1.
*  @author Mohamed kalech .
* @version 0.1.
* @date  mai 21 ,2020
*
*version final  
*
*/


/** 
*  @brief to initialize the cards of enigme e.
*  @param e enigme
* @return nothing 
*/


void init_card (enigme2 *e)
{
    
   e->poscard[0].x=0; 
   e->poscard[0].y=0;
   
   e->card[0]=SDL_LoadBMP("em2.bmp");
        if(e->card[0]==NULL)
{
printf("erreur fel taswiret el cards:%s\n",SDL_GetError());

}

}

/** 
*  @brief to show the cards of enigme e.
*  @param e enigme
*  @param ecran is the screen 
* @return nothing 
*/

void afficher_card (enigme2 e,SDL_Surface *ecran)
{
  
  
 SDL_BlitSurface(e.card[0],NULL,ecran,&e.poscard[0]);
 SDL_Flip(ecran);


}


/** 
*  @brief to initialize enigme e.
*  @param e enigme
* @return nothing 
*/
void init_enigme(enigme2 *e)
{

 
    


    e->posimg[0].x=0; 
    e->posimg[0].y=0; //graph
    e->posimg[1].x=0;
    e->posimg[1].y=0;    //win
    e->posimg[2].x=0; //lose
    e->posimg[2].y=0;
    e->posbox[0].x=153;
    e->posbox[0].y=312;  //ts1
    e->posbox[1].x=205;
    e->posbox[1].y=312; //ts2
    e->posbox[2].x=257;
    e->posbox[2].y=312; //ts3


    
    
        

    	
e->img[0]=SDL_LoadBMP("em3.bmp");
        if(e->img[0]==NULL)
{
printf("erreur graph:%s\n",SDL_GetError());

}

        e->img[1]=SDL_LoadBMP("win.bmp");
        if(e->img[1]==NULL)
{
printf("erreur win:%s\n",SDL_GetError());

}

e->img[2]=SDL_LoadBMP("lose.bmp");
if(e->img[2]==NULL)
{
printf("erreur lose:%s\n",SDL_GetError());

}


  e->nm[0]=IMG_Load("0.png");
        if(e->nm[0]==NULL)
{
printf("erreur fel 0:%s\n",SDL_GetError());

}

e->nm[1]=IMG_Load("1.png");
        if(e->nm[1]==NULL)
{
printf("erreur fel 1:%s\n",SDL_GetError());

}

e->nm[2]=IMG_Load("2.png");
        if(e->nm[2]==NULL)
{
printf("erreur fel 2:%s\n",SDL_GetError());

}

e->nm[3]=IMG_Load("3.png");
        if(e->nm[3]==NULL)
{
printf("erreur fel 3:%s\n",SDL_GetError());

}

e->nm[4]=IMG_Load("4.png");
        if(e->nm[4]==NULL)
{
printf("erreur fel 4:%s\n",SDL_GetError());

}

e->nm[5]=IMG_Load("5.png");
        if(e->nm[5]==NULL)
{
printf("erreur fel 5:%s\n",SDL_GetError());

}

e->nm[6]=IMG_Load("6.png");
        if(e->nm[6]==NULL)
{
printf("erreur fel 6:%s\n",SDL_GetError());

}

e->nm[7]=IMG_Load("7.png");
        if(e->nm[7]==NULL)
{
printf("erreur fel 7:%s\n",SDL_GetError());

}
e->nm[8]=IMG_Load("8.png");
        if(e->nm[8]==NULL)
{
printf("erreur fel 8:%s\n",SDL_GetError());

}
e->nm[9]=IMG_Load("9.png");
        if(e->nm[9]==NULL)
{
printf("erreur fel 9:%s\n",SDL_GetError());

}


        

        e->box[0]=IMG_Load("ts.png");
if( e->box[0]==NULL)
{
printf("erreur ts:%s\n",SDL_GetError());

}


}




/** 
*  @brief disable occurence of numbers and show numbers on right positions 
*  @param e enigme
*  @param ecran is the screen
*  @param n disable occurance
*  @param p position 
*  @param number is input of player (only1 number)
*  @param numero is input of player (3 numbers)
* @return nothing 
*/

void nb (int n, int *p, int *number,int *numero,SDL_Surface *img2,SDL_Surface *ecran, SDL_Rect pos1, SDL_Rect pos2, SDL_Rect pos3)
{




     
    if ((n)==0)
      { (n)=1;
        (*p)++;
        
       
      if ((*p)==1)
{      
       
      SDL_BlitSurface(img2,NULL,ecran,&pos1);
	SDL_Flip(ecran);
        (*numero)=(*numero)+(*number)*100;
        
}
        else if  ((*p)==2)
{       
       SDL_BlitSurface(img2,NULL,ecran,&pos2);
	SDL_Flip(ecran); 
          (*numero)=(*numero)+(*number)*10;
         
}
         else if ((*p)==3)
{     
        SDL_BlitSurface(img2,NULL,ecran,&pos3);
	SDL_Flip(ecran);
        (*numero)=(*numero)+(*number);
         
}
 else if ((*p)>3)            
{     
        p=0;
        
         
}
        
 
     
       
 }
  
}

/** 
*  @brief to show enigme e.
*  @param e enigme
*  @param ecran is the screen 
*  @param enigme e 
* @return nothing 
*/
void afficher_enigme (enigme2 e,SDL_Surface *ecran)
{
  
  
 SDL_BlitSurface(e.img[0],NULL,ecran,&e.posimg[0]);
 SDL_Flip(ecran);


}


/** 
*  @brief get the correct numbers and wrong ones 
*  @param num is input (3 numbers)
*  @param nclic is how much did the player push on okay botton  
*  @param temps1 2 3 .. chaine that contain number of tries
*  @param quiz is what the player is supposed to guess 
* @return nothing 
*/
void recherchenum(SDL_Surface *fond, int *num,int nclic,char temps1[],char temps2[],char temps3[],char temps4[],char temps5[],SDL_Surface *ecran,int quiz )
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
         SDL_BlitSurface(fond, NULL, ecran, &position);
        SDL_BlitSurface(texte1, NULL, ecran, &position1); 
        
     SDL_BlitSurface(textereste4, NULL, ecran, &positionreste4);
      SDL_BlitSurface(textewelcome, NULL, ecran, &positionwelcome);
         
}
if (nclic==2)
{      
         
          sprintf(temps2," %d chifre(s) correct %d bien place et %d mal place",i,j,m);
    texte1 = TTF_RenderText_Blended(police,temps1, couleurNoire);
    texte2 = TTF_RenderText_Blended(police,temps2, couleurNoire);

SDL_BlitSurface(fond, NULL, ecran, &position);
         
         SDL_BlitSurface(texte1, NULL, ecran, &position1);
        SDL_BlitSurface(texte2, NULL, ecran, &position2); 


                    /*****************/
       SDL_BlitSurface(textereste3, NULL, ecran, &positionreste3); 
       SDL_BlitSurface(textewelcome, NULL, ecran, &positionwelcome);
          
}


if (nclic==3)
{
  sprintf(temps3," %d chifre(s) correct %d bien place et %d mal place",i,j,m);
    texte1 = TTF_RenderText_Blended(police,temps1, couleurNoire);
    texte2 = TTF_RenderText_Blended(police,temps2, couleurNoire);
    texte3 = TTF_RenderText_Blended(police,temps3, couleurNoire);
    

SDL_BlitSurface(fond, NULL, ecran, &position);

        
         SDL_BlitSurface(texte1, NULL, ecran, &position1);
         SDL_BlitSurface(texte2, NULL, ecran, &position2);
         SDL_BlitSurface(texte3, NULL, ecran, &position3); 
                     /*****************/
         
        SDL_BlitSurface(textereste2, NULL, ecran, &positionreste2);
        SDL_BlitSurface(textewelcome, NULL, ecran, &positionwelcome);
       
}
if (nclic==4)
{
sprintf(temps4," %d chifre(s) correct %d bien place et %d mal place",i,j,m);
    texte1 = TTF_RenderText_Blended(police,temps1, couleurNoire);
    texte2 = TTF_RenderText_Blended(police,temps2, couleurNoire);
    texte3 = TTF_RenderText_Blended(police,temps3, couleurNoire);
    texte4 = TTF_RenderText_Blended(police,temps4, couleurNoire);

SDL_BlitSurface(fond, NULL, ecran, &position);

        
         SDL_BlitSurface(texte1, NULL, ecran, &position1);
         SDL_BlitSurface(texte2, NULL, ecran, &position2);
         SDL_BlitSurface(texte3, NULL, ecran, &position3);
         SDL_BlitSurface(texte4, NULL, ecran, &position4);
                   /*****************/
       
          SDL_BlitSurface(textereste1, NULL, ecran, &positionreste1);
          SDL_BlitSurface(textewelcome, NULL, ecran, &positionwelcome);
}

  

       
SDL_Flip(ecran);       
}


/** 
*  @brief win the game or not 
*  @param num is input of (3 numbers)
*  @param quiz is what the player is supposed to guess  
* @return 1 (win)  or 0 (lose) 
*/

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

