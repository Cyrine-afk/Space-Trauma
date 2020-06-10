#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "fct.h"
int enigmewi(SDL_Surface *ecran,int *eng,int *eng2)
{
    SDL_Init;
    TTF_Init;
    char string1[100];
    char string2[20];
    int nombre_mot=0;
    int j;
   SDL_Surface *positioncar[20]={NULL},*texte = NULL, *fond = NULL,*Enigm=NULL,*pp=NULL,*nn=NULL;
    SDL_Surface *message2=NULL;
    char pas[11];
    SDL_Rect position,post,choix,position_msg;
    SDL_Event event;
    TTF_Font *police = NULL;
    TTF_Font *po=NULL;
    

    nombre_mot=piocherMot(string1);

    for(j=0;j<nombre_mot-1;j++)
    {
    string2[j]=string1[j];
    pas[j]='*';
    }
    string2[nombre_mot]='\0'; 
     pas[nombre_mot]='\0'; 
    SDL_Color couleurBlanche = {0,0,0};
   	char let='&';
        char st[255];

    int nombre_chance=nombre_mot+3;
    char nombre = (char)nombre_chance;
    int continuer = 1;
    
    post.x=15;
    post.y=15;
    choix.x=30;
    choix.y=30;
    position_msg.x=260;
    position_msg.y=280;
   
    /*
    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(730, 530, 32, SDL_HWSURFACE);*/
    SDL_WM_SetCaption("Enigme", NULL);
     TTF_Init();
     enigme3 e ;
     init_enigmewi (&e);
    
    char lettre = 0; // Stocke la lettre proposée par l'utilisateur (retour du scanf)
    char motSecret[100] = {0}; // Ce sera le mot à trouver
    int *lettreTrouvee = NULL; // Un tableau de booléens. Chaque case correspond à une lettre du mot secret. 0 = lettre non trouvée, 1 = lettre trouvée
    long coupsRestants = 10; // Compteur de coups restants (0 = mort)
    long i = 0; // Une petite variable pour parcourir les tableaux
    long tailleMot = 0;
      fond = IMG_Load("em2.png");
     police = TTF_OpenFont("fente.ttf", 25);
     texte = TTF_RenderText_Blended(police, "welcome ", couleurBlanche);
     
     
      
     po = TTF_OpenFont("fente.ttf", 20);
     Enigm = TTF_RenderText_Blended(po, " guess the hidden word", couleurBlanche);
     
     
      
     po = TTF_OpenFont("fente.ttf", 29);
    pp = TTF_RenderText_Blended(po, pas, couleurBlanche);
     
     
     
     
     while (continuer)
    {
        while(SDL_PollEvent(&event))
        switch(event.type)
        {
              
    case SDL_QUIT:
        continuer = 0;
        break;
    case SDL_MOUSEBUTTONUP: /* Clic de la souris */
        break;
        case SDL_KEYDOWN:
                 
    switch(event.key.keysym.sym)
    {                      
	case SDLK_a:
	let='a';
	break;
	case SDLK_b:
	let='b';
	break;
	case SDLK_c:
	let='c';
	break;
	case SDLK_d:
	let='d';
	break;
	case SDLK_e:
	let='e';
	break;
	case SDLK_f:
	let='f';
	break;
	case SDLK_g:
	let='g';
	break;
	case SDLK_h:
	let='h';
	break;
	case SDLK_i:
	let='i';
	break;
	case SDLK_j:
	let='j';
	break;
	case SDLK_k:
	let='k';
	break;
	case SDLK_l:
	let='l';
	break;
	case SDLK_m:
	let='m';
	break;
	case SDLK_n:
	let='n';
	break;
	case SDLK_o:
	let='o';
	break;
	case SDLK_p:
	let='p';
	break;
	case SDLK_q:
	let='q';
	break;
	case SDLK_r:
	let='r';
	break;
	case SDLK_s:
	let='s';
	break;
	case SDLK_t:
	let='t';
	break;
	case SDLK_u:
	let='u';
	break;
	case SDLK_v:
	let='v';
	break;
	case SDLK_y:
	let='y';
	break;
	case SDLK_w:
	let='w';
	break;
	case SDLK_x:
	let='x';
	break;
	case SDLK_z:
	let='z';
	break;
	case SDLK_BACKSPACE:
	break;
	default:
	let='&';
	break;
        }
        //printf("testttttttttt");
 if(nombre_chance>=0){
             if(rechercheLettre(let,string2,nombre_mot)!=-1){
          fprintf(stderr,"%c\n",let);
         for(j=0;j<nombre_mot;j++){
          
             if(string2[j]==let){
                 pas[j]=let;
             }
         }
             SDL_FreeSurface(pp);
         pp = TTF_RenderText_Blended(po, pas, couleurBlanche);
         SDL_FreeSurface(message2);
    sprintf(st,"you have  %d tries left ",nombre_chance);
    message2=TTF_RenderText_Blended(po,st, couleurBlanche);
     }
     else{
         nombre_chance--; 
         SDL_FreeSurface(message2);
    sprintf(st,"you have %d tries left",nombre_chance);
    message2=TTF_RenderText_Blended(po,st, couleurBlanche);
     }
 }
    break;     
        }
  
  if(verifier_reponse(pas,string2,nombre_mot)==1 && nombre_chance>0){
         
SDL_FreeSurface(message2);


    message2=TTF_RenderText_Blended(po,"you won", couleurBlanche);
   *eng=1;
   return 1; 

  }



  if(nombre_chance<=0){

             SDL_FreeSurface(message2);
             sprintf(st,"you lost answer:  %s",string2);

    message2=TTF_RenderText_Blended(po,st, couleurBlanche); 
  *eng2=1;
   return 1;
    
  }
        //SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
        afficher_enigmewi (e,ecran);
        position.x = 78;
        position.y = 268;
        //SDL_BlitSurface(texte, NULL, ecran, &position); /* Blit du texte */ //welcome
        
        post.x = 295;
        post.y = 63;
        SDL_BlitSurface(Enigm, NULL, ecran, &post); 
        
        
        choix.x = 355; // position mtaa el mot el bech ytalaaha 
        choix.y = 188;
        SDL_BlitSurface(pp, NULL, ecran, &choix); /* Blit du texte */
        SDL_BlitSurface(message2,NULL,ecran,&position_msg);

        //return gagnewi(lettreTrouvee,tailleMot);
        
         SDL_Flip(ecran);
    }

   
    
    TTF_CloseFont(police);
    TTF_CloseFont(po);
    TTF_Quit();
    SDL_FreeSurface(texte);
    SDL_FreeSurface(Enigm);
    SDL_Quit;
    
        

        EXIT_SUCCESS;
    
       
        
}
