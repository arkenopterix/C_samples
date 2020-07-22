CPP=gcc    #Commande du compilateur
CFLAGS=-O3 #Option d'optimisation du programme
LDFLAGS=-lSDL -lSDL_image #Linker

sobo: obj/utils.o obj/main.o obj/map.o
	${CPP} $(CFLAGS) -o Sobokan obj/utils.o obj/map.o obj/main.o ${LDFLAGS}

obj/map.o: src/map.c
	${CPP} $(CFLAGS) -DDEBUG -o obj/map.o -c src/map.c -I inc/ -I /usr/include/SDL/  ${LDFLAGS}

obj/utils.o: src/utils.c
	${CPP} $(CFLAGS) -DDEBUG -o obj/utils.o -c src/utils.c -I inc/ -I /usr/include/SDL/  ${LDFLAGS}

obj/main.o: src/main.c inc/utils.h inc/map.h
	${CPP} $(CFLAGS) -DDEBUG -o obj/main.o -c src/main.c -I inc/ -I /usr/include/SDL/   ${LDFLAGS}

clean:
	rm -rf obj/utils.o obj/main.o obj/map.o sobo
