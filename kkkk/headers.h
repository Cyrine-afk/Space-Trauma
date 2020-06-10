#ifndef HEADERS_H
#define HEADERS_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"


//structures

typedef enum STATE STATE;
enum STATE{WAITING,FOLLOWING,ATTACKING,FOLLOWING2};

typedef struct hero
{
int score;
int etat;
int gravite;
int vie;
int lifem;
SDL_Surface *tab[2][4];
SDL_Surface *imgA;
SDL_Rect position;
int num_image;
int nb_enigmes_max;
int nb_enigmes;
}hero;


typedef struct hero2
{
int score;
int etat;
int gravite;
int vie;
int lifem;
SDL_Surface *tab[2][4];
SDL_Surface *imgA;
SDL_Rect position;
int num_image;
int nb_enigmes_max;
int nb_enigmes;
}hero2;


/*typedef struct Input
{
int left,right,jump,down,up,escape;

}Input;*/



typedef struct save
{  
  SDL_Surface *image[5]; /*!< Surface. */
  SDL_Rect position[5]; /*!< Rectangle*/ 
}  save;




typedef struct es
{
SDL_Surface *enm[4], *obj[5];
SDL_Rect posenm[4], posobj[5];
SDL_Event event;
int direc;
}es;


/**
* @struct score
* @brief struct for score
*/
typedef struct score 
{
SDL_Surface *image[20], *dmd; /*!< Surface. */
SDL_Rect position[20], posd; /*!< Rectangle*/
  int tab[20]; /*!< Integer*/
}score;


/**
* @struct vie
* @brief struct for vie
*/
typedef struct vie
{
  SDL_Rect position[10], posh; /*!< Rectangle*/
  SDL_Surface *image[10], *hrt; /*!< Surface. */
  int tab[10]; /*!< Integer*/
  int tab2[20]; /*!< Integer*/
}vie;

typedef struct enigme //enigme meriem lvl2
{
 SDL_Surface * img;
 SDL_Rect p;
}enigme;

typedef struct enigme2 //enigme mohamed lvl1
{
SDL_Surface *nm[20];
SDL_Surface *img[20];
SDL_Surface *box[3];
SDL_Surface *card[1];
SDL_Rect poscard[1];
SDL_Rect posnum[20];
SDL_Rect posimg[20];
SDL_Rect posbox[3];
}enigme2;


/**
* @struct temps
* @brief struct for temps
*/
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


/**
* @struct store
* @brief struct for store
*/
typedef struct store 
{
  SDL_Surface *button[2]; /*!< Surface. */
  SDL_Rect posbtn[2]; /*!< Rectangle*/
  SDL_Surface *image[2]; /*!< Surface. */
  SDL_Rect position[2]; /*!< Rectangle*/
} store;


/**
* @struct musique
* @brief struct for musique
*/

typedef struct musique
{  
 Mix_Music *music; /*!< Music*/
 Mix_Music *music2;
 Mix_Music *music3;
 Mix_Chunk *son; /*!< Music chunk*/
}  musique;

typedef struct ennemie
{
SDL_Surface *tab[6];
SDL_Rect pos[6];
int direc;
SDL_Event event;
int etat;
}ennemie;



typedef struct 
{

SDL_Surface *map[5]; 
SDL_Rect posmap[5]; 

}map;


//menu


//main jeu
void main();

//void tangiza(hero *h,SDL_Surface *Tab[],SDL_Surface *screen,SDL_Rect location,SDL_Rect relativ5,SDL_Rect *hajra,int x);

//staion

int mapwitches(SDL_Surface *screen ,int noah,int kevin,int *fin);



int mapsahra(SDL_Surface *screen,int noah ,int kevin,int *fin);
int maprobots(SDL_Surface *screen,int noah,int kevin,int *fin);


void affichemapsahra(SDL_Surface *Tab[],map m,SDL_Surface *screen);
void affichemapinside(SDL_Surface *Tab[],map m,SDL_Surface *screen);
void affichemapwitches(SDL_Surface *Tab[],map m,SDL_Surface *screen);
void affichemaprobot(SDL_Surface *Tab[],map m,SDL_Surface *screen);


//initialisations
/** personnage **/
void initialiser_personnage(hero *h);
void initialiser_personnage2(hero2 *h2);

/** background **/
void initialise(SDL_Surface *Tab[],SDL_Rect pos[]);
SDL_Color getpixel(SDL_Surface *screen,int x,int y);
SDL_Color getpixel2(SDL_Surface *screen,int x,int y);
/** hearts and diamonds **/ 
void init_dms (score *d);
void init_hearts (vie *v);
/** entitee secondaire **/
void initialiser(es *e);
/** enigme + fichier **/ //meriem
void init_enigme(enigme * en) ;
/** enigme sans fichier **/ //mohamed
void init_card (enigme2 *e);
void init_enigmee(enigme2 *e);
int enigmewi(SDL_Surface *ecran,int *eng,int *eng2); // enigme map witches
/** temps **/
void initialiser_temps(temps *t);
/** store **/
void init_store (store *st);


//affichage
/** personnage **/
void afficher_personnage(hero h,SDL_Surface *screen);
void afficher_personnage2(hero2 h2,SDL_Surface *screen);
void afficher_personnage3(hero h,hero2 h2,SDL_Surface *screen);
/** background **/

/** hearts and diamonds **/ 
void affiche_diamond (score *d, SDL_Surface *screen);
void affiche_heart (vie *v, SDL_Surface *screen);
void  generate_afficher (SDL_Surface *screen  , char image[], enigme *en,int *alea) ;
/** enigme + fichier **/
int afficher_resultat (SDL_Surface *screen,int s,int r,enigme *en) ;
/** entitee secondaire **/
void affiche_ents (es *e, SDL_Surface *screen, int a , int c, SDL_Rect relativobj,SDL_Rect relativobj2);
/** enigme sans fichier **/
void afficher_card (enigme2 e,SDL_Surface *screen);
void afficher_enigme (enigme2 e,SDL_Surface *screen);
/** temps **/
void afficher_temps(temps *t, SDL_Surface *screen);
/** store **/
void affiche_bouton_store (store *st, SDL_Surface *screen);
void affiche_store (store *st, SDL_Surface *screen);
void aff_store_1 (SDL_Surface *screen, store st, int *dkhal, int motion_a, int motion_b, hero *h, int tm);
/** help **/
void affiche_button_help (store *st, SDL_Surface *screen);
void afficher_help (store *st, SDL_Surface *screen, int motion_a, int motion_b);

//gestion du store 
void gest_store (SDL_Surface *screen, store st, hero *h, int *tm,int motion_a,int motion_b, int *dkhal);


//gestion de temps
int gestion_temps_jeu (temps tmps);
int gestion_temps_enigme (temps *t);


//animations
/** personnage **/
void animer_personnage(hero *h,int d);
void animer_personnage2(hero2 *h2,int d);
/** entitee secondaire **/
void deplacer_ennemiealiatoire(es *e,SDL_Surface *screen);


//collisions
int colis(SDL_Surface *screen,SDL_Rect pos[], hero h);
int colis2(SDL_Surface *screen,SDL_Rect pos[], hero h);
int collisionTrigo(SDL_Rect p1,score *d,int indice);
int collisionTrigoEs(SDL_Rect p1,es *e,int indice);
int collisionTrigoVie(SDL_Rect p1,vie *v,int indice);
int collisionTrigoObj(SDL_Rect p1,es *e,int indice);
int colis_es(es e);
//int CollisionParfaite(SDL_Surface* backgroundMask, SDL_Rect frame, SDL_Rect position); 
int cols(SDL_Rect pos ,SDL_Rect pos2);
_Bool colision(SDL_Rect *rec1,SDL_Rect *rec2);

//score et vies
void scoree (hero *h,score *d, SDL_Surface *screen, SDL_Rect location, SDL_Rect relativ,SDL_Rect relativ2, SDL_Rect relativ3, SDL_Rect relativ4, SDL_Rect relativ5);
void scoree2 (hero *h,score *d, SDL_Surface *screen, SDL_Rect location, SDL_Rect relativ6, SDL_Rect relativ7, SDL_Rect relativ8);

void scorewitches (hero *h,score *d, SDL_Surface *screen, SDL_Rect location, SDL_Rect relativ5, SDL_Rect relativ6, SDL_Rect relativ2, SDL_Rect hajra);


void scorerobots (hero *h,score *d, SDL_Surface *screen, SDL_Rect location,SDL_Rect relativ, SDL_Rect relativ2, SDL_Rect relativ3);



void scoreinside (hero *h,score *d, SDL_Surface *screen, SDL_Rect location, SDL_Rect relativ3, SDL_Rect relativ4 );

int vies (hero *h,vie *v, es *e, SDL_Surface *screen, SDL_Rect location, SDL_Rect rltv, int indice, SDL_Rect relativobj,SDL_Rect relativobj2);


int vieswitches (hero *h,vie *v, es *e, SDL_Surface *screen, SDL_Rect location, SDL_Rect relativ3, SDL_Rect relativ7,int indice );

int viesrobots (hero *h,vie *v, es *e, SDL_Surface *screen, SDL_Rect location, SDL_Rect relativ4);


/*void scoree(hero *h,score *d, SDL_Surface *screen);
int vies(hero *h,vie *v,es *e, int h0,int h1, int e1, int e2, SDL_Surface *screen, SDL_Surface *dead, SDL_Rect posdead);*/


// deplacer personnage par souris
int souris ( int argc, char** argv, hero *h, score *d, SDL_Surface *screen, SDL_Rect pos[]);


//enigme + fichier
int solution_e (char image []) ;
int resolution (int * running,int *run);
int enigme_File (SDL_Surface *screen, enigme *en);


//enigme sans fichier
void nb (int n, int *p, int *number,int *numero, SDL_Surface *img2,SDL_Surface *screen, SDL_Rect pos1, SDL_Rect pos2,SDL_Rect pos3);
void recherchenum(SDL_Surface *fond, int *num,int nclic,char temps1[],char temps2[],char temps3[],char temps4[],char temps5[],SDL_Surface *screen, int quiz );
int gagne(int *num, int quiz);
int enigme_num (SDL_Surface *screen, temps *t);


//musique
//void music (musique *msc);
//void musicwitches(musique *msc);
//void musicrobots(musique *msc);


//save
//void SaveGame(char* nomFich,hero *h,SDL_Rect pos[],score d,vie v,int b[]);
//void LoadGame(char* nomFich,hero *h,SDL_Rect pos[],score d,vie v,int b[]);


//conditions de fin du jeu
int cond_fin_jeu (int vv, hero *h, temps t);





//NEW PART
void init_save (save *sv);
void afficher_bouton_save (save *sv, SDL_Surface *screen);
void masque_bouton_save (save *sv, SDL_Surface *screen,  int motion_a1, int motion_b1);
void afficher_save (save *sv, SDL_Surface *screen, int motion_a1, int motion_b1, musique *msc);
void afficher_save_escape(save *sv, SDL_Surface *screen,musique *msc);
void SaveLevel(char* nomFich2, int niveau);
void SaveGame(char* nomFich,hero h, SDL_Rect pos[], temps t,ennemie enmy);
int Lunch_SaveGame (int motion_a, int motion_b, musique *msc,char* nomFich,char* nomFich2,hero h, SDL_Rect pos[], temps t, ennemie enmy, int niveau);
void LoadGame(char* nomFich,hero *h, SDL_Rect *pos[], temps *t,ennemie *enmy);
void LoadLevel(char* nomFich2, int *niveau);








//free
void frees(es *e);
void freeHearts (vie *v);
void freeDiamonds (score *d);
void freeText (TTF_Font *po, TTF_Font *po1, SDL_Surface *text1, SDL_Surface *text);
void free_temps(temps *t);
void finjeu (SDL_Surface *screen);

#endif


