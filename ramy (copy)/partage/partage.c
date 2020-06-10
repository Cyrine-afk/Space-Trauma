#include <stdio.h>
#include "SDL/SDL.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "partage.h"
/**
*  @file partage.c
*  @brief deviser l'ecran en deux pour multijoueur  .
*  @author JJS team .
* @version 0.1.
* @date  mai 21 ,2020
*
*version final  
*
*/ 


/**
* @brief initialiser le premier joueur .
* @param j le joueur
* @param url the url of the image
* @return nothing
*/
void initialiser_joueur1(joueur *j)
{
    j->p[0]=IMG_Load("Attack_000(1).png");

    j->pp.x = 20;
    j->pp.y = 280;

}

/**
* @brief initialiser le deuxieme joueur .
* @param j le joueur
* @param url the url of the image
* @return nothing
*/
void initialiser_joueur2(joueur *j)
{
    j->p[1]=IMG_Load("Attack_000(1).png");

    j->pp.x = largeur/2 + 10;
    j->pp.y = 280;

}

/**
* @brief initialiser le premier background .
* @param b le background
* @param url the url of the image
* @return nothing
*/
void initialiser_background1(background *b)
{
    b->background=IMG_Load("background.png");
    b->pb.x=0;
    b->pb.y=0;
    b->pb.w=largeur/2;
    b->pb.h=hauteur;
}

/**
* @brief initialiser le deuxieme background .
* @param b le background
* @param url the url of the image
* @return nothing
*/
void initialiser_background2(background *b)
{
    b->background=IMG_Load("background.png");
    b->pb.x=largeur/2;
    b->pb.y=0;
    b->pb.w=largeur/2;
    b->pb.h=hauteur;
}


