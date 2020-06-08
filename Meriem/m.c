//.h

typedef struct temps
{
SDL_Surface *texte; /*!< Surface. */
 SDL_Rect position; /*!< Rectangle*/
  
    TTF_Font *police ; /*!< Font*/

 char entree[200]; /*!< Character*/
 int secondesEcoulees; /*!< Integer*/
SDL_Color couleurBleue; /*!< Color*/
time_t t1,t2; /*!< Time*/

}temps;

//gestion de temps
int gestion_temps_jeu (temps tmps);
/** temps **/
void afficher_temps(temps *t, SDL_Surface *Tab[]);
/** temps **/
void initialiser_temps(temps *t);

//fonctions.c
void initialiser_temps(temps *t)
{
 t->texte = NULL;
 t->position.x=625;
 t->position.y=5;
 t->police = NULL;
 t->police = TTF_OpenFont("comic1.ttf", 25);
 strcpy( t->entree,"");
 (t->secondesEcoulees)=0;
 time(&(t->t1)); 
  
 //temps du debut
}

void afficher_temps(temps *t,SDL_Surface *Tab[])
{	
 SDL_Color couleurBleue= {0,0, 255};

 time(&(t->t2));// temps actuel

 t->secondesEcoulees = t->t2 - t->t1;
       
 sprintf(t->entree,"%02d:%02d",(t->secondesEcoulees/60)%60, (t->secondesEcoulees)%60);
      

  t->texte = TTF_RenderUTF8_Solid(t->police, t->entree, couleurBleue);
        //printf("temps=%s   \n",t->entree);// sauvegarde dans le fichier 
      

  SDL_BlitSurface(t->texte, NULL, Tab[0], &(t->position));
  SDL_Flip(Tab[0]);

//SDL_Delay(80);
}


int gestion_temps_enigme (temps *t)
{ 
  
  if ((t->secondesEcoulees/60)%60 == 1) //1 minute
    return 0;
  else 
    return 1;
}


//main.c
/* kharej el boucle du jeu */
temps t;
/**** init temps ****/
initialiser_temps(t);

/** fi west el boucle du jeu **/


afficher_temps(t,Tab);  

  if (gestion_temps_enigme (t)==0)
  {
  continuer=0;
  }
