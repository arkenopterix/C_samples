CPP=gcc    #Commande du compilateur
CFLAGS=-O3 #Option d'optimisation du programme
LDFLAGS=-lSDL -lSDL_image #Linker

sdl: obj/chap25_sdlTime.o
	${CPP} $(CFLAGS)  -o chap25_sdlTime obj/chap25_sdlTime.o ${LDFLAGS}

deg: obj/chap21_sdl_degrade.o
	${CPP} $(CFLAGS) -o chap21_sdl_degrade obj/chap21_sdl_degrade.o ${LDFLAGS}

obj/chap25_sdlTime.o: src/chap25_sdlTime.c inc/chap25_sdlTime.h
	${CPP} $(CFLAGS) -o obj/chap25_sdlTime.o -c src/chap25_sdlTime.c -I inc/ -I /usr/include/SDL/ -Wall

obj/chap21_sdl_degrade.o: src/chap21_sdl_degrade.c inc/chap21_sdl.h
	${CPP} $(CFLAGS) -o obj/chap21_sdl_degrade.o -c src/chap21_sdl_degrade.c -I inc/  -Wall

clean:
	rm -rf obj/chap25_sdlTime* chap25_sdlTime
