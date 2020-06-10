jeu: main.o   initialiser.o  affichage.o  animations.o          
	gcc main.o initialiser.o  affichage.o  animations.o -o jeu -g -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lm
main.o: main.c
	gcc -c main.c -g

initialiser.o: initialiser.c
	gcc -c initialiser.c -g
affichage.o: affichage.c
	gcc -c affichage.c -g 
animations.o: animations.c
	gcc -c animations.c -g

