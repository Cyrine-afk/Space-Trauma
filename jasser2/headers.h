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

/**
* @struct hero
* @brief hero initialisation
*/
typedef struct hero
{
int score;
int etat;
int gravite;
int vie;
int lifem;
SDL_Surface *tab[2][4],*tab2[2][4],*tab3[2][4];
SDL_Surface *imgA;
SDL_Rect position;
int num_image;
int nb_enigmes;
}hero;

/**
* @struct input
* @brief input
*/

typedef struct Input
{
int left,right,jump,down,up,escape;

}Input;




//menu


//main jeu
void main();


//initialisations
/** personnage **/
void initialiser_personnage(hero *h);
void initialiser_personnage_hit(hero *h);
void initialiser_personnage_2(hero *h);
/** background **/
void initialise(SDL_Surface *Tab[],SDL_Rect pos[]);
SDL_Color getpixel(SDL_Surface *Tab[],int x,int y);
SDL_Color getpixel2(SDL_Surface *Tab[],int x,int y);



//affichage
/** personnage **/
void afficher_personnage(hero h,SDL_Surface *Tab[]);
void afficher_personnage_hit(hero h,SDL_Surface *Tab[]);
void afficher_personnage_2(hero h,SDL_Surface *Tab[]);
/** background **/
void affiche1(SDL_Surface *Tab[],SDL_Rect pos[]);
void affiche2(SDL_Surface *Tab[],SDL_Rect pos[]);

//animations
/** personnage **/
void animer_personnage(hero *h,int d);
void animer_personnage_hit(hero *h,int d);
void animer_personnage_2(hero *h,int d);




#endif


