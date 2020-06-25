CPP=gcc    #Commande du compilateur
CFLAGS=-O3 #Option d'optimisation du programme
LDFLAGS=-lSDL #-lSDL_mixer #Linker

sdl: obj/chap21_sdl.o
	${CPP} $(CFLAGS) -o chap21_sdl obj/chap21_sdl.o ${LDFLAGS}

deg: obj/chap21_sdl_degrade.o
	${CPP} $(CFLAGS) -o chap21_sdl_degrade obj/chap21_sdl_degrade.o ${LDFLAGS}

obj/chap21_sdl.o: src/chap21_sdl.c inc/chap21_sdl.h
	${CPP} $(CFLAGS) -o obj/chap21_sdl.o -c src/chap21_sdl.c -I inc/  -Wall

obj/chap21_sdl_degrade.o: src/chap21_sdl_degrade.c inc/chap21_sdl.h
	${CPP} $(CFLAGS) -o obj/chap21_sdl_degrade.o -c src/chap21_sdl_degrade.c -I inc/  -Wall

clean:
	rm -rf obj/chap21* chap21_sdl
