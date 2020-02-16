pendu: obj/utils.o obj/main.o obj/dico.o
	gcc -o JeuPendu obj/utils.o obj/dico.o obj/main.o

obj/dico.o: src/dico.c
	gcc -o obj/dico.o -c src/dico.c -I inc/  -Wall

obj/utils.o: src/utils.c
	gcc -o obj/utils.o -c src/utils.c -I inc/  -Wall

obj/main.o: src/main.c inc/utils.h inc/dico.h
	gcc -o obj/main.o -c src/main.c -I inc/  -Wall

clean:
	rm -rf obj/utils.o obj/main.o obj/dico.o JeuPendu
