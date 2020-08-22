CPP=gcc    #Commande du compilateur
CFLAGS=-O3 #Option d'optimisation du programme
LDFLAGS=-lSDL -lSDL_image -lSDL_mixer#Linker

sdl: obj/chap27_sdlMixer.o
	${CPP} $(CFLAGS)  -o chap27_sdlMixer obj/chap27_sdlMixer.o ${LDFLAGS}


obj/chap27_sdlMixer.o: src/chap27_sdlMixer.c inc/chap27_sdlMixer.h
	${CPP} $(CFLAGS) -o obj/chap27_sdlMixer.o -c src/chap27_sdlMixer.c -I inc/ -I /usr/include/SDL/ -Wall


clean:
	rm -rf obj/chap27_sdlMixer* chap27_sdlMixer
