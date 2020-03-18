CPP=gcc    #Commande du compilateur
CFLAGS=-O3 #Option d'optimisation du programme
LDFLAGS=-lSDL #-lSDL_mixer #Linker

sdl: obj/chap21_sdl.o
	${CPP} $(CFLAGS) -o chap21_sdl obj/chap21_sdl.o ${LDFLAGS}


obj/chap21_sdl.o: src/chap21_sdl.c inc/chap21_sdl.h
	${CPP} $(CFLAGS) -o obj/chap21_sdl.o -c src/chap21_sdl.c -I inc/  -Wall

clean:
	rm -rf obj/chap21_sdl.o  chap21_sdl