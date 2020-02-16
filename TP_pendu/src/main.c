#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "dico.h"

#define MOT "BLOUBLI"
#define TAILLE_MOT 8
//#define DEBUG


int main(int argc, char *argv[])
{
    /*
    *   Initialisation des variables
    */

    //variables du jeu
    //char motADeviner[TAILLE_MAX_MOT];
    int nbCoups = 10;
    int occurenceCarTrouve = 0;
    char *motCache = NULL;
    char caractereLu = 0;
    int compteurSucces;

    //variables liées au dico
    FILE *fichierMots = NULL;
    int nbMots;
    Dictionnaire *dicoTab = NULL;
    int indexMotPartie;

    /*
    *Recuperation de la liste des mots
    */

    //ouverture du fichier
    fichierMots = fopen("data/mots.txt", "r");

    if(fichierMots == NULL)// on teste si l'ouverture c'est bien passée
    {
        printf("ERREUR: Fichier data/mots.txt introuvable\n");
        exit(1);
    }

    //on compte le nombre de mots dans le fichier
    nbMots = compteMotsDansFichier(fichierMots);
#ifdef DEBUG
    printf("nombre de mots dans mots.txt: %d \n",nbMots);
#endif // DEBUG

    //On alloue la mémoire pour le tableau de Dictionnaire
    dicoTab = malloc(nbMots*sizeof(Dictionnaire));

    if(dicoTab == NULL)
    {
        printf("ERREUR: allocation memoire a echoue");
        exit(1);
    }

    //on remet le curseur du fichier à 0
    rewind(fichierMots);

    //On rempli le tableau de dictionnaire:
    chargementDictionnaire(fichierMots,dicoTab,nbMots);

    //cloture du fichier de mots
    fclose(fichierMots);

    /*
    *   Preparation des objets de la partie
    */

    //On selectionne le mot pour la partie:
    indexMotPartie = choisiChiffreAuPif(nbMots);

#ifdef DEBUG
    printf(" Mot selectionne: %s, taille : %d \n",dicoTab[indexMotPartie].mot,dicoTab[indexMotPartie].tailleMot);
#endif // DEBUG

    //Initialisation du tableau motCache:
    motCache = malloc(dicoTab[indexMotPartie].tailleMot*sizeof(char));

    if (motCache!=NULL)
    {
        initMotCache(motCache,dicoTab[indexMotPartie].tailleMot-1);
    }
    else
    {
        printf("ERREUR: Malloc failed... you have a problem..\n");
        return -1;
    }

    //Init compteursucces:
    compteurSucces = dicoTab[indexMotPartie].tailleMot-1;
    //Menu du pauvre..
    printf("Bienvenue dans le Pendu !\n\n");

    /*
    *   boucle principale du jeu
    */
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
        chercherCaratereLu(caractereLu,dicoTab[indexMotPartie].mot,motCache,&occurenceCarTrouve);

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
