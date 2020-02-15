#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

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
