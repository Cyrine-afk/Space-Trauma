
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <stdio.h>
#include "game.h"

/**
*  @file game2.c
*  @brief menu du jeu
*   @author JJS team
*  @version 0.1
*  @date mai 30 , 2020
* 
* version final du menu
*
*/


void load(SDL_Surface *background[])
{


	background[1] = IMG_Load("star2.png");
	background[2] = IMG_Load("star1.png"); //image ..
	background[3] = IMG_Load("star2.png");
	background[4] = IMG_Load("star3.png");
	background[5] = IMG_Load("butonet1.png");
	background[6] = IMG_Load("setfv1..png");
	background[7] = IMG_Load("volume menu.png");
	background[8] = IMG_Load("bg2.png");
	background[9] = IMG_Load("muett.png");
	background[10] = IMG_Load("exit4.png");
	background[11] = IMG_Load("setting4.png");
	background[12] = IMG_Load("play4.png");

	background[13] = IMG_Load("junior1.png");
	background[14] = IMG_Load("junior2.png");
	background[15] = IMG_Load("junior3.png");
	background[16] = IMG_Load("junior4.png");
	/*background[17] = IMG_Load("spacetrauma.png");*/
	background[18] = IMG_Load("volumee.png");
	background[19] = IMG_Load("ship1.png");
	background[20] = IMG_Load("nejma.png");
	background[21] = IMG_Load("gamemode.png");
	background[22] = IMG_Load("hero.png");

        background[23] = IMG_Load("volume1.png");
        background[24] = IMG_Load("full_screen.png");
        background[25] = IMG_Load("game_mode1.png");
        background[26] = IMG_Load("hero1.png");
        background[27] = IMG_Load("single_player.png");
        background[28] = IMG_Load("multi_player.png");
        background[29] = IMG_Load("keyboard.png");
        background[30] = IMG_Load("mouse.png");
        background[31] = IMG_Load("noah.png");
        background[32] = IMG_Load("kevin.png");




	/*
	SDL_GetMouseState(&x,&y);
	*/

}


void initialise(SDL_Rect position[])
{

	position[1].x = 0;
	position[1].y = 0;

	position[2].x = 0;
	position[2].y = 0;

	position[3].x = 0;
	position[3].y = 0;

	position[4].x = 0;
	position[4].y = 0;

	position[6].x = 0;
	position[6].y = 0;

	position[5].x = 2;
	position[5].y = 180;

	position[7].x = 0;
	position[7].y = 0;

	position[8].x = 0;
	position[8].y = 0;

	position[10].x = 0;
	position[10].y = 409;

	position[9].x = 338;
	position[9].y = 327;



	position[11].x = 0;
	position[11].y = 295;

	position[12].x = 1;
	position[12].y = 175;

	position[13].x = 0;
	position[13].y = 0;

	position[14].x = 0;
	position[14].y = 0;

	position[15].x = 0;
	position[15].y = 0;

	position[16].x = 0;
	position[16].y = 0;

	position[17].x = 130;
	position[17].y = 7;

	position[18].x = 0;
	position[18].y = 0;

	position[19].x = 0;
	position[19].y = 110;


	position[20].x = 367;
	position[20].y = 250;


	position[21].x = 0;
	position[21].y = 0;

	position[22].x = 0;
	position[22].y = 0;

        position[23].x = 270;
	position[23].y = 130;

        position[24].x = 270;
	position[24].y = 208;

        position[25].x = 270;
	position[25].y = 288;

        position[26].x = 270;
	position[26].y = 360;

        position[27].x = 214;
	position[27].y = 170;

        position[28].x = 363;
	position[28].y = 220;

        position[29].x = 214;
	position[29].y = 325;

        position[30].x = 363;
	position[30].y = 375;

        position[31].x = 215;
	position[31].y = 355;

        position[32].x = 385;
	position[32].y = 355;


}
void load_music(Mix_Music *music[])
{



	music[0] = Mix_LoadMUS("intro.mp3");

}


void play_music(Mix_Music *music[])
{
	Mix_PlayMusic(music[0], -1);

}



void intro(SDL_Surface *background[], SDL_Rect position[])
{
	SDL_BlitSurface(background[13], NULL, background[0], &position[13]);
	SDL_Flip(background[0]);
	SDL_Delay(700);

	SDL_BlitSurface(background[14], NULL, background[0], &position[14]);
	SDL_Flip(background[0]);
	SDL_Delay(700);

	SDL_BlitSurface(background[15], NULL, background[0], &position[15]);
	SDL_Flip(background[0]);
	SDL_Delay(700);

	SDL_BlitSurface(background[16], NULL, background[0], &position[16]);
	SDL_Flip(background[0]);
	SDL_Delay(700);

}


int ful_screen(SDL_Surface *background[])
{



	background[0] = SDL_SetVideoMode(850, 700, 0, SDL_HWSURFACE | SDL_SWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);
	return 1;


}


int normal_screen(SDL_Surface *background[])
{

	SDL_QuitSubSystem(SDL_INIT_VIDEO);
	background[0] = SDL_SetVideoMode(850, 700, 0, SDL_HWSURFACE | SDL_SWSURFACE | SDL_DOUBLEBUF);
	return 1;

}

/*

int mouse_mot()
{
int a,b;
SDL_Event event;
a=event.motion.x;
b=event.motion.y;

if(a> 18 && a< 230 && b>220 && b<277)
{
return 1;

}



else  if(a> 18 && a< 182 && b>330&& b<386)
{
return 2;
}
else if(a> 18 && a< 179 && b>468 && b<526)
{
return 3;

}
else
{
return 0;

}


}
*/
void normal_back(SDL_Surface *background[], SDL_Rect position[])
{

	SDL_BlitSurface(background[1], NULL, background[0], &position[1]);
	SDL_BlitSurface(background[17], NULL, background[0], &position[17]);
	SDL_BlitSurface(background[5], NULL, background[0], &position[5]);
	SDL_BlitSurface(background[19], NULL, background[0], &position[19]);
	SDL_Flip(background[0]);
}

/*
void animation(SDL_Surface *background[],SDL_Rect position[])
{

SDL_BlitSurface(background[2],NULL,background[0],&position[2]);
SDL_BlitSurface(background[17],NULL,background[0],&position[17]);
SDL_BlitSurface(background[5],NULL,background[0],&position[5]);
SDL_Flip(background[0]);

SDL_BlitSurface(background[3],NULL,background[0],&position[3]);
SDL_BlitSurface(background[17],NULL,background[0],&position[17]);
SDL_BlitSurface(background[5],NULL,background[0],&position[5]);
SDL_Flip(background[0]);


SDL_BlitSurface(background[4],NULL,background[0],&position[4]);
SDL_BlitSurface(background[17],NULL,background[0],&position[17]);
SDL_BlitSurface(background[5],NULL,background[0],&position[5]);
SDL_Flip(background[0]);


SDL_BlitSurface(background[1],NULL,background[0],&position[1]);
SDL_BlitSurface(background[17],NULL,background[0],&position[17]);
SDL_BlitSurface(background[5],NULL,background[0],&position[5]);

SDL_Flip(background[0]);



}
*/

void play(SDL_Surface *background[], SDL_Rect position[])
{

	SDL_BlitSurface(background[1], NULL, background[0], &position[1]);
	SDL_BlitSurface(background[17], NULL, background[0], &position[17]);
	SDL_BlitSurface(background[5], NULL, background[0], &position[5]);
	SDL_BlitSurface(background[12], NULL, background[0], &position[12]);
	SDL_BlitSurface(background[19], NULL, background[0], &position[19]);

	SDL_Flip(background[0]);
}
void settings(SDL_Surface *background[], SDL_Rect position[])
{
	SDL_BlitSurface(background[1], NULL, background[0], &position[1]);
	SDL_BlitSurface(background[17], NULL, background[0], &position[17]);
	SDL_BlitSurface(background[5], NULL, background[0], &position[5]);
	SDL_BlitSurface(background[11], NULL, background[0], &position[11]);
	SDL_BlitSurface(background[19], NULL, background[0], &position[19]);

	SDL_Flip(background[0]);

}
void exite(SDL_Surface *background[], SDL_Rect position[])
{

	SDL_BlitSurface(background[1], NULL, background[0], &position[1]);
	SDL_BlitSurface(background[17], NULL, background[0], &position[17]);
	SDL_BlitSurface(background[5], NULL, background[0], &position[5]);
	SDL_BlitSurface(background[10], NULL, background[0], &position[10]);
	SDL_BlitSurface(background[19], NULL, background[0], &position[19]);

	SDL_Flip(background[0]);
}


void buton(SDL_Surface *background[], SDL_Rect position[])
{
	SDL_BlitSurface(background[1], NULL, background[0], &position[1]);
	SDL_BlitSurface(background[17], NULL, background[0], &position[17]);
	SDL_BlitSurface(background[5], NULL, background[0], &position[5]);
	SDL_BlitSurface(background[19], NULL, background[0], &position[19]);

}


void setting2(SDL_Surface *background[], SDL_Rect position[])
{
        
	SDL_BlitSurface(background[6], NULL, background[0], &position[6]);
	SDL_Flip(background[0]);

}

void bgg(SDL_Surface *background[], SDL_Rect position[])
{

	SDL_BlitSurface(background[8], NULL, background[0], &position[8]);
	SDL_Flip(background[0]);

}

void volume(SDL_Surface *background[], SDL_Rect position[])
{
	SDL_BlitSurface(background[18], NULL, background[0], &position[18]);
	SDL_Flip(background[0]);

}

void muet_vol(SDL_Surface *background[], SDL_Rect position[], int *d)
{
	if (*d == 0)
	{
		Mix_PauseMusic();
		SDL_BlitSurface(background[9], NULL, background[0], &position[9]);
		SDL_BlitSurface(background[20], NULL, background[0], &position[20]);
		SDL_Flip(background[0]);
		(*d) = 1;
		SDL_Delay(1000);
	}
	else
	{
		Mix_ResumeMusic();
		SDL_BlitSurface(background[18], NULL, background[0], &position[18]);
		SDL_BlitSurface(background[20], NULL, background[0], &position[20]);
		SDL_Flip(background[0]);
		(*d) = 0;
		SDL_Delay(1000);
	}



}

void backy(SDL_Surface *background[], SDL_Rect position[])
{


	SDL_BlitSurface(background[6], NULL, background[0], &position[6]);
	SDL_Flip(background[0]);


}


void meteor(SDL_Surface *background[], SDL_Rect position[])
{

	position[19].x += 2;
	position[19].y -= 1;

	if (position[19].x >= 1050)
	{
		position[19].x = 0;
	}


}


void free_back(SDL_Surface *background[])
{


	SDL_FreeSurface( background[1]);
	SDL_FreeSurface( background[2]);
	SDL_FreeSurface( background[3]);
	SDL_FreeSurface( background[4]);
	SDL_FreeSurface( background[5]);
	SDL_FreeSurface( background[6]);
	SDL_FreeSurface( background[7]);
	SDL_FreeSurface( background[8]);
	SDL_FreeSurface( background[9]);
	SDL_FreeSurface( background[10]);
	SDL_FreeSurface( background[11]);
	SDL_FreeSurface( background[12]);
	SDL_FreeSurface( background[13]);
	SDL_FreeSurface( background[14]);
	SDL_FreeSurface( background[15]);
	SDL_FreeSurface( background[16]);
	SDL_FreeSurface( background[17]);



}

void gamemode(SDL_Surface *background[],SDL_Rect position[])
{
	SDL_BlitSurface(background[21],NULL,background[0],&position[21]);
	SDL_Flip(background[0]);
}
void hero(SDL_Surface *background[],SDL_Rect position[])
{
	SDL_BlitSurface(background[22],NULL,background[0],&position[22]);
	SDL_Flip(background[0]);
}


