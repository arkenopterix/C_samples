CPP=gcc    #Commande du compilateur
CFLAGS=-O3 #Option d'optimisation du programme
LDFLAGS=-lSDL -lSDL_image #Linker

sdl: obj/chap22_sdlImage.o
	${CPP} $(CFLAGS)  -o chap22_sdlImage obj/chap22_sdlImage.o ${LDFLAGS}

deg: obj/chap21_sdl_degrade.o
	${CPP} $(CFLAGS) -o chap21_sdl_degrade obj/chap21_sdl_degrade.o ${LDFLAGS}

obj/chap22_sdlImage.o: src/chap22_sdlImage.c inc/chap22_sdlImage.h
	${CPP} $(CFLAGS) -o obj/chap22_sdlImage.o -c src/chap22_sdlImage.c -I inc/ -I /usr/include/SDL/ -Wall

obj/chap21_sdl_degrade.o: src/chap21_sdl_degrade.c inc/chap21_sdl.h
	${CPP} $(CFLAGS) -o obj/chap21_sdl_degrade.o -c src/chap21_sdl_degrade.c -I inc/  -Wall

clean:
	rm -rf obj/chap22_sdlImage* chap22_sdlImage
