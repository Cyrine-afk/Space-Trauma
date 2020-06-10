#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"

#include "headers.h"
#include "defs.h"

/**
* @file [new.c].
* @author : Cyrine Trabelsi
* @brief : Game Project
* @date : 2020/05/29
* @version 1
*/


/**
* @brief Initialize save .
* @param *sv for save
* @return Nothing
*/

void init_save (save *sv)
{
  sv->image[0]= IMG_Load("./shm/save1m.png");
  sv->image[1]= IMG_Load("./shm/save1.png");
  sv->image[2]= IMG_Load("./shm/save.png");  

  sv->position[0].x=560;
  sv->position[0].y=5;

  sv->position[1].x=560;
  sv->position[1].y=5;

  sv->position[2].x=200;
  sv->position[2].y=100;

}



/**
* @brief Show button save .
* @param *sv for save
* @param *Tab[] for Surface
* @return Nothing
*/
void afficher_bouton_save (save *sv, SDL_Surface *Tab[])
{
  SDL_BlitSurface(sv->image[0],NULL,Tab[0],&sv->position[0]);
}


/**
* @brief Show button save's masq .
* @param *sv for save
* @param *Tab[] for Surface
* @param  motion_a1 for integer
* @param  motion_b1 for integer
* @return Nothing
*/
void masque_bouton_save (save *sv, SDL_Surface *Tab[],  int motion_a1, int motion_b1)
{
  if (motion_a1>560 && motion_a1<640 && motion_b1>5 && motion_b1<43)
  {
    SDL_BlitSurface(sv->image[1],NULL,Tab[0],&sv->position[1]);
  }
}



/**
* @brief Show save .
* @param *sv for save
* @param *Tab[] for Surface
* @param  motion_a1 for integer
* @param  motion_b1 for integer
* @param *msc for musique
* @return Nothing
*/
void afficher_save (save *sv, SDL_Surface *Tab[], int motion_a1, int motion_b1, musique *msc)
{
  if (motion_a1>560 && motion_a1<640 && motion_b1>5 && motion_b1<43)
  {
    SDL_BlitSurface(sv->image[2],NULL,Tab[0],&sv->position[2]);
    SDL_Flip(Tab[0]);
    Mix_PlayChannel(1, msc->son ,0);
    SDL_Delay (5000);
  }
}


/**
* @brief Show save with escape button .
* @param *sv for save
* @param *Tab[] for Surface
* @param *msc for musique
* @return Nothing
*/

void afficher_save_escape(save *sv, SDL_Surface *Tab[],musique *msc)
{
  SDL_BlitSurface(sv->image[2],NULL,Tab[0],&sv->position[2]);
    SDL_Flip(Tab[0]);
    Mix_PlayChannel(1, msc->son ,0);
    SDL_Delay (5000);
}




/**
* @brief Save level .
* @param * nomFich2 for character
* @param niveau for Integer
* @return Nothing
*/
void SaveLevel(char* nomFich2, int niveau)
{
 FILE * f;
  f=fopen(nomFich2,"w") ;
	if (f==NULL)
	{
	   
		printf("Erreur d'ouverture du fichier \n");
	}
	
	else
	{
          fprintf(f, "%d\n",niveau);
          fclose(f);
	}
}


/**
* @brief Save game .
* @param * nomFich for character
* @param h for hero
* @param pos[] for Rectangle
* @param t for temps
* @param enmy for enmy
* @return Nothing
*/
void SaveGame(char* nomFich, hero h, SDL_Rect pos[], temps t,ennemie enmy)
{
  int i,j;
  FILE * f;
  f=fopen(nomFich,"w") ;
	if (f==NULL)
	{
	   
		printf("Erreur d'ouverture du fichier \n");
	}
	
	else
	{


	//1st hero 
    fprintf(f,"%d\n",h.position.x);
    fprintf(f,"%d\n",h.position.y);
    fprintf(f,"%d\n",h.position.w);
    fprintf(f,"%d\n",h.position.h);
    fprintf(f,"%d\n",h.num_image);
    fprintf(f,"%d\n",h.gravite);
    fprintf(f,"%d\n",h.etat); //1: dead ou 0: alive
    fprintf(f,"%d\n",h.vie);
    fprintf(f,"%d\n",h.score);
    fprintf(f,"%d\n",h.nb_enigmes);

	//background 
    fprintf(f,"%d\n",pos[0].x);
    fprintf(f,"%d\n",pos[0].y);

        //time
    fprintf(f,"%d\n",(t.secondesEcoulees)%60); //secondes


	//ennemy 
    for (j=0;j<6;j++)
    {
     fprintf(f,"%d\n",enmy.pos[j].x);
     fprintf(f,"%d\n",enmy.pos[j].y);
    }
    fprintf(f,"%d\n",enmy.direc);
    fprintf(f,"%d\n",enmy.etat);

    fclose(f);
	}
}

/**
* @brief Execute Function Save .
* @param motion_a for Integer
* @param motion_b for Integer
* @param *msc for musique
* @param * nomFich for character
* @param * nomFich2 for character
* @param h for hero
* @param pos[] for Rectangle
* @param t for temps
* @param enmy for enmy
* @param niveau for Integer
* @return Integer
*/
int Lunch_SaveGame (int motion_a, int motion_b, musique *msc,char* nomFich,char* nomFich2,hero h, SDL_Rect pos[], temps t,ennemie enmy, int niveau)
{
 if (motion_a>226 && motion_a<306 && motion_b>165 && motion_b<202)
  {
    Mix_PlayChannel(1, msc->son ,0);
    SaveGame(nomFich,h,pos,t,enmy);
    SaveLevel(nomFich2,niveau);
    return 0;
  }
 else if (motion_a>331 && motion_a<412 && motion_b>165 && motion_b<202)
  {
    Mix_PlayChannel(1, msc->son ,0);
    return 1;
  }
} 


/**
* @brief Load Level .
* @param * nomFich2 for character
* @param *niveau for Integer
* @return Nothing
*/

void LoadLevel(char* nomFich2, int *niveau)
{
  char file[20];
  FILE* f = fopen(nomFich2,"r");
  int niveauu;
   
  strcpy(file,nomFich2);


   if(f!=NULL)
   {
    while(!feof(f))
    {
     fscanf(f, "%d\n",&niveauu);
    } 
    fclose(f);
   }

else 
{
	printf("Erreur d'ouverture du fichier \n");
}
  *niveau=niveauu;
}


/**
* @brief Load Game .
* @param * nomFich for character
* @param *h for hero
* @param *pos[] for Rectangle
* @param *t for temps
* @param *enmy for enmy
* @return Nothing
*/
void LoadGame(char* nomFich,hero *h/*, SDL_Rect *pos[]*/, temps *t,ennemie *enmy)
{
	char file[20];

    FILE* f = fopen(nomFich,"r");

//1er hero
int hpositionx,hpositiony,hpositionw,hpositionh,hnum_image,hgravite,hetat,hvie,hscore,hnb_enigmes; 

//background
int pos0x,pos0y; 

//time
int minutes, secondes;

//ennemy
int enmyposx[7],enmyposy[7],j; 
int enmydirec, enmyetat;

strcpy(file,nomFich);


if(f!=NULL)
{
while(!feof(f))
{

	//read 1er hero 
    fscanf(f, "%d\n",&hpositionx);
    fscanf(f, "%d\n",&hpositiony);
    fscanf(f, "%d\n",&hpositionw);
    fscanf(f, "%d\n",&hpositionh);
    fscanf(f, "%d\n",&hnum_image);
    fscanf(f, "%d\n",&hgravite);
    fscanf(f, "%d\n",&hetat);
    fscanf(f, "%d\n",&hvie);
    fscanf(f, "%d\n",&hscore);
    fscanf(f, "%d\n",&hnb_enigmes);

	//read background 
    fscanf(f, "%d\n",&pos0x);
    fscanf(f, "%d\n",&pos0y);

	//read time
    fscanf(f, "%d\n",&secondes);

	//read ennemy
    /*for (j=0;j<6;j++)
    {
     fscanf(f, "%d\n",&enmyposx[j]);
     fscanf(f, "%d\n",&enmyposy[j]);
    }
    fscanf(f, "%d\n",&enmydirec);
    fscanf(f, "%d\n",&enmyetat);*/

} 
fclose(f);
}

else 
{
	printf("Erreur d'ouverture du fichier \n");
}


//load 1er hero
h->position.x=hpositionx;
h->position.y=hpositiony;
h->position.h=hpositionh;
h->position.w=hpositionw;
h->num_image=hnum_image;
h->gravite=hgravite;
h->etat=hetat;
h->vie=hvie;
h->score=hscore;
h->nb_enigmes=hnb_enigmes;

//load background
//pos[0]->x=pos0x;
//pos[0]->y=pos0y;

//load time
t->secondesEcoulees=secondes;

//load ennemy
/*for (j=0;j<6;j++)
    {
     enmy->pos[j].x=enmyposx[j];
     enmy->pos[j].y=enmyposy[j];
    }
    enmy->direc=enmydirec;
    enmy->etat=enmyetat;*/
	

}



/**
* @brief Execute Function Save .
* @param *Tab[] for Surface
* @return Nothing
*/
void finjeu (SDL_Surface *Tab[])
{
		SDL_Surface *T[31];
		int i; char ch[200]; 
  Tab[0] = SDL_SetVideoMode(730, 530, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
		for (i=1; i<=31;i++)
		{	
			sprintf (ch, "animation/anim%d.png", i+1);
			T[i]= IMG_Load(ch);
		}

		for(i=1;i<=31;i++)
		{	SDL_BlitSurface(T[i],NULL, Tab[0],NULL);	
		SDL_Flip(Tab[0]);
		SDL_Delay(500);
		}
   SDL_Flip(Tab[0]);
}



