#include <stdio.h>
#include <stdlib.h>
#include "chap15_structs.h"

void initialiserJoueur(Joueur *j)
{
    printf("init joueur 2\n");
    sprintf(j->nom,"joueur2");
    j->vies = 2;
    j->f=NORMAL;

}


int main(int argc, char *argv[])
{

    Joueur jTab[3];
    Joueur *j3 = &(jTab[2]);

    jTab[0] = (Joueur) {"",0,BALAISE}; // initialisation de la structure

    sprintf(jTab[0].nom,"joueur1");
    jTab[0].vies=3;
    printf("J1 nom : %s \n",jTab[0].nom);
    printf("J1 nombre de vies : %d \n",jTab[0].vies);
    printf("J1 Force: %d \n",jTab[0].f);

    initialiserJoueur(&(jTab[1]));
    printf("J2 nom : %s \n",jTab[1].nom);
    printf("J2 nombre de vies : %d \n",jTab[1].vies);
    printf("J2 Force: %d \n",jTab[1].f);

    sprintf(j3->nom,"joueur3");
    j3->vies = 4;
    j3->f=QUICHE;
    printf("J3 nom : %s \n",j3->nom);
    printf("J3 nombre de vies : %d \n",j3->vies);
    printf("J3 Force: %d \n",j3->f);


	return 0;

}
//gcc -Wall -c "chap14_strings.c"
//gcc -Wall -o "chap14_strings" "chap14_strings.c"
