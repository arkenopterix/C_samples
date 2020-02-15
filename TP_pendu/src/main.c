#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"


#define MOT "BLOUBLI"
#define TAILLE_MOT 8


int main(int argc, char *argv[])
{
    //Initialisation des variables
    char motADeviner[TAILLE_MOT] = MOT;
    int nbCoups = 10;
    int occurenceCarTrouve = 0;
    char *motCache = NULL;
    char caractereLu = 0;
    int compteurSucces = TAILLE_MOT - 1;

    //Initialisation du tableau motADeviner:
    motCache = malloc(TAILLE_MOT*sizeof(char));

    if (motADeviner!=NULL)
    {
        initMotCache(motCache,TAILLE_MOT);
    }
    else
    {
        printf("Malloc failed... you have a problem..\n");
        return -1;
    }

    //Menu du pauvre..
    printf("Bienvenue dans le Pendu !\n\n");

    //boucle principale du jeu
    while (nbCoups >0 && compteurSucces >0)
    {
        // on réinitialise la variable occurencetrouve
        occurenceCarTrouve = 0;

        //prompt du jeu
        printf("Il vous reste %d coups a jouer %d\n",nbCoups,compteurSucces);
        printf("Quel est le mot secret ? %s \n",motCache);
        printf("Proposez une lettre : ");
        caractereLu = lireCaractere();

        //on verifie s'il y a au moins une occurence du caractere trouve
        chercherCaratereLu(caractereLu,motADeviner,motCache,&occurenceCarTrouve);

        if(occurenceCarTrouve == 0) //la lettre donnee est dans le mot
        {
             nbCoups--;

        }
        else
        {
            compteurSucces= compteurSucces - occurenceCarTrouve;
        }



    }

    if(nbCoups <= 0) //toutes les tentatives epuisées = perdu
    {
        printf("Flute! vous avez perdu... Ah ben v'la au't chose!\n");
    }
    else // il restait des tentatives = gagne
    {
        printf("Bravo! vous avez gagne!\n");
    }

    return 0;

}
//gcc -Wall -c "chap13_strings.c"
//gcc -Wall -o "chap13_strings" "chap13_strings.c"
