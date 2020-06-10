#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"

#include "headers.h"
#include "defs.h"

/**
* @file [music.c].
* @author : Cyrine Trabelsi
* @brief : Game Project
* @date : 2020/05/29
* @version 1
*/


/**
* @brief To make music1 .
* @param *msc for musique
* @return Nothing
*/

void music (musique *msc)
{
 msc->music=Mix_LoadMUS("./music/song1.mp3");
 Mix_PlayMusic(msc->music,-1);
 Mix_VolumeMusic(100);
}

/**
* @brief To make music2 .
* @param *msc for musique
* @return Nothing
*/
void music2 (musique *msc)
{
 msc->music=Mix_LoadMUS("./music/song2.mp3");
 Mix_PlayMusic(msc->music,-1);
 Mix_VolumeMusic(100);
}

/**
* @brief To make music3 .
* @param *msc for musique
* @return Nothing
*/
void music3 (musique *msc)
{
 msc->music=Mix_LoadMUS("./music/song3.mp3");
 Mix_PlayMusic(msc->music,-1);
 Mix_VolumeMusic(100);
}
