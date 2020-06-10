#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED


void load(SDL_Surface *background[]);
void initialise(SDL_Rect position[]);
void intro(SDL_Surface *background[],SDL_Rect position[]);
void load_music(Mix_Music *music[]);
void play_music(Mix_Music *music[]);
int ful_screen(SDL_Surface *background[]);
int normal_screen(SDL_Surface *backgound[]);
int mouse_mot();
void normal_back(SDL_Surface *background[],SDL_Rect position[]);


void animation(SDL_Surface *background[],SDL_Rect position[]);
void buton(SDL_Surface *background[],SDL_Rect position[]);


void play(SDL_Surface *background[],SDL_Rect position[]);
void settings(SDL_Surface *background[],SDL_Rect position[]);
void exite(SDL_Surface *background[],SDL_Rect position[]);

void setting2(SDL_Surface *background[],SDL_Rect position[]);
void bgg(SDL_Surface *background[],SDL_Rect position[]);

void volume(SDL_Surface *background[],SDL_Rect position[]);
void muet_vol(SDL_Surface *background[],SDL_Rect position[],int *d);

void backy(SDL_Surface *background[],SDL_Rect position[]);

void meteor(SDL_Surface *background[],SDL_Rect position[]);




void free_back(SDL_Surface *background[]);
void gamemode(SDL_Surface *background[],SDL_Rect position[]);
void hero(SDL_Surface *background[],SDL_Rect position[]);

#endif


