pendu: obj/utils.o obj/main.o
	gcc -o JeuPendu obj/utils.o obj/main.o

obj/utils.o: src/utils.c
	gcc -o obj/utils.o -c src/utils.c -I inc/  -Wall

obj/main.o: src/main.c inc/utils.h
	gcc -o obj/main.o -c src/main.c -I inc/  -Wall

clean:
	rm -rf obj/utils.o obj/main.o JeuPendu
