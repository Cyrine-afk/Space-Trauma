prog:main.o fct.o
	gcc main.o fct.o -lSDL -lSDL_image -lSDL_ttf -lSDL_gfx -o prog
main.o:main.c
	gcc main.c  -lSDL -lSDL_image -lSDL_ttf -lSDL_gfx -c
fct.o:fct.c
	gcc -c fct.c
SDL_rotozoom.o:SDL_rotozoom.c
	gcc -c SDL_rotozoom.c
