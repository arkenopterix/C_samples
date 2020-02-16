#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dico.h"

//#define DEBUG
/*
*   Fonction qui prends en entree un fichier, compte le nombre de lignes et renvoie le resultat
*/
int compteMotsDansFichier(FILE *f)
{
    int retour =0;
    char c[TAILLE_MAX_MOT];

    while (fgets(c,TAILLE_MAX_MOT,f) != NULL) // on lit le fichier tant qu'on ne recoit pas d'erreurs (NULL)
        {
            retour++;
        }

    return retour;
}

/*
*   Charge le tableau de dictionnaires a partir du fichier mots.txt
*/
int chargementDictionnaire(FILE *f,Dictionnaire *d, int nbMots)
{
    int retour=0;
    char c[TAILLE_MAX_MOT];
    int indexMot =0;

    while (fgets(c,TAILLE_MAX_MOT,f) != NULL && (indexMot < nbMots)) // on lit le fichier tant qu'on ne recoit pas d'erreurs (NULL)
    {
        strncpy(d[indexMot].mot,c,TAILLE_MAX_MOT);

#ifdef DEBUG
        printf("mot recupere : %s \n",d[indexMot].mot);
#endif
        d[indexMot].tailleMot = strlen(c);
#ifdef DEBUG
            printf("Taille du mot: %d \n",d[indexMot].tailleMot);
#endif
        d[indexMot].mot[d[indexMot].tailleMot-1] = '\0'; // on force la fin de chaine
        indexMot++;
    }

    return retour;
}

