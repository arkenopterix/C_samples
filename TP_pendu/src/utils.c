#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "utils.h"





/*
*   Fonction pour initialiser le mot cache avec des asterisques
*/
void initMotCache(char *c,int taille)
{
    // on rempli le tableau d'asterisques
    int i;
    for ( i=0 ; i <= taille-1 ; i++)
    {
        c[i]='*';
    }
    c[taille] = '\0';

}

/*
*   Fonction de gestion du menu
*/
int menu(int *choix)
{
    int retour = 0;

    return retour;
}


/*
* Fonction de lecture des caracteres
*/
char lireCaractere()
{
    char caractere = 0;

    // on lit le premier caractère
    caractere = getchar();

    // On la met en majuscule si elle ne l'est pas
    caractere = toupper(caractere);

    // on vide le buffer en lisant les caractères jusqu'au \n
    while (getchar() != '\n');

    return caractere;
}

/*
*   Fonction récursive qui indique si le caractere choisi par l'utilisateur est dans le mot
*   et retourne le nombre de fois qu'il apparait
*/
int chercherCaratereLu(char cLu, char* motADeviner, char* motCache, int *nbOccurence)
{
    char *suiteMotADeviner = NULL;
    int occurenceMotTrouve = 0;
#ifdef DEBUG
    printf("chercherCarlu: motADevinier: %s , motchache : %s , nbocc : %d \n",motADeviner,motCache,*nbOccurence);
#endif
    // on cherche l'occurence du caracère
    suiteMotADeviner = strchr(motADeviner,(int) cLu);
    if(suiteMotADeviner !=NULL)
    {
        //on calcule l'indexe du caractere trouve

#ifdef DEBUG
        printf("int moaDeviner: %d , int suitrMotAdeviner: %d, index : %d \n",(int)motADeviner,((int) suiteMotADeviner),((int)motADeviner - ((int) suiteMotADeviner)));
#endif
        occurenceMotTrouve = ((int) suiteMotADeviner) - ((int)motADeviner);

        //on incremente le compteur d'occurences
        *nbOccurence= *nbOccurence+1;

        //on remplace une asterisque par une lettre
        motCache[occurenceMotTrouve] = cLu;

        //et on repart pour un tour
        chercherCaratereLu(cLu,suiteMotADeviner+1,motCache+occurenceMotTrouve+1,nbOccurence);

        return 1;
    }
    else
    {
        return 0;
    }

}

int choisiChiffreAuPif(int nbMots)
{

    srand(time(NULL));


    return (rand() % nbMots);
}


