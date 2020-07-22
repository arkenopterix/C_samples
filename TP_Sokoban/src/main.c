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
    SDL_Surface *fond = NULL;

    // On intiialise les données µSDL
    SDL_Init(SDL_INIT_VIDEO); // demarrage de la SDL

    SDL_WM_SetIcon(SDL_LoadBMP("res/icon.bmp"),NULL);
	fond = SDL_SetVideoMode(TAILLE_CARTE_PX,TAILLE_CARTE_PX,32, SDL_HWSURFACE | SDL_DOUBLEBUF); // taille de la fenetre + enable double bufferring
    SDL_WM_SetCaption("Sobokan", NULL);// changement du nom de la fenetre

    //remplissage du tableau de la carte grâce aux données du tableau niveau
	retour = loadMapTabFromLevelTab(mapTab,levelTab,&gameState);
	if (retour != 0)
	{
#ifdef DEBUG
	    printf("Main -- Retour loadMapTabFromLevelTab KO!\n");
#endif
	    return -1;
	}

	//on dessine la carte une première fois
    SDL_FillRect(fond,NULL, SDL_MapRGB(fond->format,255,255,255));
    drawMap(mapTab,&gameState,fond);
    SDL_Flip(fond); // on met à jour l'affichage
	// boucle infinie
	while(gameState.numObj != gameState.objOK) //tant que l'on a pas reussi a mettre les caisse sur tous les objectifs
	{
		//on gere les events


		//on redessine la carte mise a jour
	}	
	
	

    //SDL_FreeSurface(bkgrnd);// libération de la surface (pas besoin de le faire pour l'écran, qui est géré en dessous dans SDL_Quit)
	SDL_Quit();// Arret de la SDL


    return 0;

}
//gcc -Wall -c "chap13_strings.c"
//gcc -Wall -o "chap13_strings" "chap13_strings.c"
