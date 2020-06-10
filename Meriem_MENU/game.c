#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <stdio.h>
#include "game.h"
/**
*  @file game.c
*  @brief menu du jeu
*   @author JJS team
*  @version 0.1
*  @date mai 30 , 2020
* 
* version final du menu
*
*/
int main()
{

	int x = 1;
	int a = 0, b = 0, c = 0, d = 0, e = 0, m = 0, t = 1, u = 0, vol = 120, z = 0,w=0, r=0,l=0,s=0,k=0;
	SDL_Surface *background[30];
	SDL_Rect position[30];
	SDL_Event event;
	Mix_Music *music[2];

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("Unable :%s\n", SDL_GetError());
	}



background[0] = SDL_SetVideoMode(730, 530, 0, SDL_HWSURFACE | SDL_SWSURFACE | SDL_DOUBLEBUF);


	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
	{
		printf("erreur:%s\n", Mix_GetError());
	}

	load(background);
	initialise(position);

//......................................
	intro(background, position);
//......................................
	load_music(music);
	play_music(music);
//......................................
	while (x == 1)
	{

		if (t == 1)
		{

			SDL_Delay(40);

			switch (m)
			{
			case 0:
				normal_back(background, position);
				break;
			case 1:
				play(background, position);
				break;
			case 2:
				settings(background, position);
				break;
			case 3:
				exite(background, position);
				break;
			default:
				normal_back(background, position);
				break;

			}

			


			SDL_PollEvent(&event);

			switch (event.type)
			{
			case SDL_QUIT:
				x = 0;
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
				case SDLK_f:
					a = ful_screen(background);
					break;
				case SDLK_n:
					b = normal_screen(background);
					break;
				case SDLK_DOWN:
					m++;
					if (m == 4)
						m = 1;
					break;


				}//switch2
				break;

			case SDL_MOUSEMOTION:
				a = event.motion.x;
				b = event.motion.y;

				if (a > 14 && a < 222  && b > 188 && b < 244)
				{
					m = 1;

				}
				else  if (a > 14 && a < 222 && b > 308 && b < 365)
				{
					m = 2;
				}
				else if (a > 14 && a < 222 && b > 425 && b < 482)
				{
					m = 3;

				}
				else
				{
					m = 0;

				}
				break;

			case SDL_MOUSEBUTTONDOWN:
//setting:
				a = event.motion.x;
				b = event.motion.y;

				if (a > 14 && a < 222  && b > 188 && b < 244)
				{
					t = 2;
					bgg(background, position);

				}
		else if (a > 14 && a < 222 && b > 425 && b < 482)

				{

					x = 0;
				}
		else  if (a > 14 && a < 222 && b > 308 && b < 365)
				{

					setting2(background, position);
					t = 3;
				}
				break;





			}//switch1



		}//if1


		if (t == 2)
		{
			SDL_PollEvent(&event);

			switch (event.type)
			{
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
				case SDLK_ESCAPE:

					t = 1;
					break;

				}
				break;

			}
		}//if2


if (t == 3)
{
SDL_PollEvent(&event);

switch (event.type)
{
case SDL_KEYDOWN:
switch (event.key.keysym.sym)
{
case SDLK_ESCAPE:
					
t = 1;
break;

}
break;




case SDL_MOUSEMOTION:
a = event.motion.x;
b = event.motion.y;

if (a>270 && a<460 && b>130 && b<174)
{
//volume
 SDL_BlitSurface(background[23], NULL, background[0], &position[23]);
}


if (a>270 && a<460 && b>208 && b<250)
{
//full screen
SDL_BlitSurface(background[24], NULL, background[0], &position[24]);
}


if (a>270 && a<460 && b>288 && b<330 )
{
//game mode
SDL_BlitSurface(background[25], NULL, background[0], &position[25]);

}
if (a>270 && a<460 && b>360 && b<403)
{
//hero
SDL_BlitSurface(background[26], NULL, background[0], &position[26]);

}
break;




case SDL_MOUSEBUTTONDOWN:
a = event.motion.x;
b = event.motion.y;



if ( a>270 && a<460 && b>130 && b<174 )
{

	z=1;
	volume(background,position);

}

if(  a>270 && a<460 && b>208 && b<250)
{

	u=0;//full screen
}


if( a>270 && a<460 && b>288 && b<330 )
{

	k=2;
	gamemode(background,position);
}


if( a>270 && a<460 && b>360 && b<403)
{

	s=3;
	hero(background,position);
}


if (a > 178  && a < 226  && b > 408 && b < 470)
{
s=0;
settings(background, position);
}

if(k=2)
{


	SDL_PollEvent(&event);

			switch (event.type)
			{
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
				case SDLK_ESCAPE:

					t = 1;
					break;

				}
				break;


case SDL_MOUSEMOTION:
a = event.motion.x;
b = event.motion.y;

if (a > 214 && a < 385  && b > 170  &&   b <  211)
{
//single player
 SDL_BlitSurface(background[27], NULL, background[0], &position[27]);
}


if (a > 363  && a < 540  && b > 220 && b < 260)
{
//multi player
SDL_BlitSurface(background[28], NULL, background[0], &position[28]);
}


if (a > 214 && a < 385  && b > 325  &&   b <  365)
{
//keyboard
SDL_BlitSurface(background[29], NULL, background[0], &position[29]);

}
if (a > 363  && a < 540  && b > 375 && b < 413)
{
//mouse
SDL_BlitSurface(background[30], NULL, background[0], &position[30]);

}
break;





			
case SDL_MOUSEBUTTONDOWN:
a = event.motion.x;
b = event.motion.y;
				

	if (a > 214 && a < 385  && b > 170  &&   b <  211 )
		{
                  	r=0;// single player
		}
	else if (a > 363  && a < 540  && b > 220 && b < 260)
		{
                	r=1;// multiplayer
		}

	else if (a > 214 && a < 385  && b > 325  &&   b <  365 )
		{
                        l=0;// keyboard
		}
	else if (a > 363  && a < 540  && b > 375 && b < 413 )
		{
			l=1;// mouse
		}
        if (a > 177  && a < 230  && b > 410 && b < 471 )
                 {
                        k=0;
                        setting2(background,position);
                 }
 }
}

if(s=3)
{


	SDL_PollEvent(&event);

			switch (event.type)
			{
case SDL_KEYDOWN:
	switch (event.key.keysym.sym)
	{
		case SDLK_ESCAPE:

			t = 1;
		break;

	}
break;



case SDL_MOUSEMOTION:
a = event.motion.x;
b = event.motion.y;

if (a > 215 && a < 340  && b > 355  &&   b <  385)
{
//noah
 SDL_BlitSurface(background[31], NULL, background[0], &position[31]);
}


else  if (a > 385  && a < 515  && b > 355 && b < 385)
{
//kevin
SDL_BlitSurface(background[32], NULL, background[0], &position[32]);
}
break;


			
case SDL_MOUSEBUTTONDOWN:
a = event.motion.x;
b = event.motion.y;
				
                   if (a > 215 && a < 340  && b > 355  &&   b <  385 )
		   {
                	w=0;// noah
		   }
	           if (a > 385  && a < 515  && b > 355 && b < 385)
		   {
			w=1;// kevin
		   }
                   if (a > 178  && a < 226  && b > 408 && b < 470)
                 {
                        s=0;
                         setting2(background,position);
                 }
}
}


				

	if (z == 1)

{
SDL_BlitSurface(background[20], NULL, background[0], &position[20]);
SDL_Flip(background[0]);

	if (a > 348  && a < 412  && b > 331 && b < 397)
	{
		muet_vol(background, position, &d);
	}
 if (a > 219   && a < 243  && b > 434  && b < 468)
	{
		z = 0;
		setting2(background, position);

	}

		}

if (a > 502 && a < 539  && b > 241  && b < 291 ) //+
{
if (position[20].x <= 449)	
{
Mix_VolumeMusic(vol);
vol += 15;
position[20].x += 3;
SDL_BlitSurface(background[18], NULL, background[0], &position[18]);
SDL_BlitSurface(background[20], NULL, background[0], &position[20]);
		SDL_Flip(background[0]);
		}

		}


if (a > 229   && a <  267 && b >  239 && b < 290 ) //-
	{
	if (position[20].x >= 273)
	{
		position[20].x -= 3;	
SDL_BlitSurface(background[18], NULL, background[0], &position[18]);
SDL_BlitSurface(background[20], NULL, background[0], &position[20]);

		SDL_Flip(background[0]);

		Mix_VolumeMusic(vol);
		vol -= 15;
		}

		}


break;
	switch (event.type)
	{
	case SDL_KEYDOWN:
	switch (event.key.keysym.sym)
	{
			case SDLK_a:

			break;

			case SDLK_s:

			break;

	}



	}
	}
  }//if3




	}//while

	free_back(background);
	return 0;
}




