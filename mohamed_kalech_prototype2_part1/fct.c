#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "fichier.h"
/**
*  @file fct.c 
*  @brief enigme2 stage2.
*  @author Mohamed kalech .
* @version 0.1.
* @date  mai 21 ,2020
*
*version final  
*
*/


/** 
*  @brief to initialize enigme e.
*  @param e enigme
* @return nothing 
*/

void init_enigme (enigme3 *e)
{
   e->posem3[0].x=0; 
   e->posem3[0].y=0;
   
  e->em3[0]=IMG_Load("em3.png");
        if(e->em3[0]==NULL)
{
printf("erreur fel fond :%s\n",SDL_GetError());

}

}

/** 
*  @brief to show enigme e.
*  @param e enigme
*  @param ecran screen 
* @return nothing 
*/

void afficher_enigme (enigme3 e,SDL_Surface *ecran)
{

 SDL_BlitSurface(e.em3[0], NULL, ecran,&e.posem3[0]);
 //SDL_Flip(ecran);

}

/** 
*  @brief to get the random serect word  
*  @param motpioche is the chosen word  
* @return length of the word 
*/

int piocherMot(char *motPioche)
{

    FILE* dico = NULL; 
    int nombreMots = 0, numMotChoisi = 0, i = 0;
    int caractereLu = 0;
    dico = fopen("dico.txt", "r"); 
    if (dico == NULL)
    {
        printf("\nImpossible de charger le dictionnaire de mots");
    }
    do
    {
        caractereLu = fgetc(dico);
        if (caractereLu == '\n')
            nombreMots++;
    } while(caractereLu != EOF);
    numMotChoisi = nombreAleatoire(nombreMots); 
    rewind(dico);
    while (numMotChoisi > 0)
    {
        caractereLu = fgetc(dico);
        if (caractereLu == '\n')
            numMotChoisi--;
    }
    fgets(motPioche, 100, dico); //100 max
    motPioche[strlen(motPioche) - 1] = '\0';       //toul el kemla 
    fclose(dico);
    return strlen(motPioche);           
}


/** 
*  @brief get a random number between 1 and nombremax 
*  @param nombreMax is the number of words in file deco  
* @return ramdom number 
*/

int nombreAleatoire(int nombreMax)
{
    srand(time(NULL));
    return (rand() % nombreMax);
}

/** 
*  @brief verify if the set (letter) is right or not 
*  @param lettre input of player
*  @param motsecrect the word to guess
*  @param nombre length of word   
* @return 0 exist -1 not  
*/
int rechercheLettre(char lettre, char motSecret[],int nombre)
{
    long i = 0;
    // lettre eli dakhaltou bech verifih maoujoud fel mot secret wale
    for (i = 0 ;i<nombre; i++)
    {
        if (lettre == motSecret[i]) // idha maoujoud 
        {
           
            return i;
        }   
}
return -1;
}

/** 
*  @brief verify answer 
*  @param m1 input  
*  @param m2 secret word 
*  @param nombre length of word   
* @return 0 lose 1 win  
*/
int verifier_reponse(char *m1,char *m2,int nombre){
 int i;
 
 for(i=0;i<nombre;i++){
     if(m1[i]!=m2[i]){
      return 0;   
     }
 }
 return 1;
}
