CPP=gcc    #Commande du compilateur
CFLAGS=-O3 #Option d'optimisation du programme
LDFLAGS=-lSDL -lSDL_image -lSDL_ttf #Linker

sdl: obj/chap26_sdlTtf.o
	${CPP} $(CFLAGS)  -o chap26_sdlTtf obj/chap26_sdlTtf.o ${LDFLAGS}

deg: obj/chap21_sdl_degrade.o
	${CPP} $(CFLAGS) -o chap21_sdl_degrade obj/chap21_sdl_degrade.o ${LDFLAGS}

obj/chap26_sdlTtf.o: src/chap26_sdlTtf.c inc/chap26_sdlTtf.h
	${CPP} $(CFLAGS) -o obj/chap26_sdlTtf.o -c src/chap26_sdlTtf.c -I inc/ -I /usr/include/SDL/ -Wall

obj/chap21_sdl_degrade.o: src/chap21_sdl_degrade.c inc/chap21_sdl.h
	${CPP} $(CFLAGS) -o obj/chap21_sdl_degrade.o -c src/chap21_sdl_degrade.c -I inc/  -Wall

clean:
	rm -rf obj/chap26_sdlTtf* chap26_sdlTtf
