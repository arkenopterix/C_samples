#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "level.h"



int main(int argc, char *argv[])
{
#ifdef DEBUG
    printf("Main debut\n");
#endif // DEBUG
    int retour = 0;


    //remplissage du tableau de la carte grâce aux données du tableau niveau
	retour = loadMapTabFromLevelTab(&mapTab,levelTab,&gameState);
	if (retour != 0)
	{
#ifdef DEBUG
	    printf("Main -- Retour loadMapTabFromLevelTab KO!\n");
#endif
	    return -1;
	}

	//on dessine la carte une première fois

	// boucle infinie
	while(gameState.numObj != gameState.objOK) //tant que l'on a pas reussi a mettre les caisse sur tous les objectifs
	{
		//on gere les events


		//on redessine la carte mise a jour
	}	
	
	



    return 0;

}
//gcc -Wall -c "chap13_strings.c"
//gcc -Wall -o "chap13_strings" "chap13_strings.c"
