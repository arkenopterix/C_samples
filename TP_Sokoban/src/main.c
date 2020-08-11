#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "map.h"
#include "level.h"
#include "menu.h"
#include "game.h"




int main(int argc, char *argv[])
{
#ifdef DEBUG
    printf("Main debut\n");
#endif // DEBUG
    int retour = 0;
    SDL_Surface *fond = NULL;
    int choixJeu = MENU;// variable pour la boucle infinie, on 
    SDL_Event event;


    // On intiialise les données SDL
    SDL_Init(SDL_INIT_VIDEO); // demarrage de la SDL

    SDL_WM_SetIcon(SDL_LoadBMP("res/icon.bmp"),NULL);
	fond = SDL_SetVideoMode(TAILLE_CARTE_PX,TAILLE_CARTE_PX,32, SDL_HWSURFACE | SDL_DOUBLEBUF); // taille de la fenetre + enable double bufferring
    SDL_WM_SetCaption("Sobokan", NULL);// changement du nom de la fenetre

	// boucle infinie
	while(choixJeu != QUITTER) //tant que l'on a pas reussi a mettre les caisse sur tous les objectifs
	{
#ifdef DEBUG
	    printf("Main -- Boucle principale\n");
#endif
		//on affihe le menu, et on y attend l'instruction du joueur
		choixJeu = menu(fond);

		switch(choixJeu)
		{
			case QUITTER:
				break;
			case MENU:
				break;
			case JEU:
				retour = game(levelTab,fond);
				choixJeu = MENU;
				break;
			case EDITEUR:
				break;
			default:
				break;

		}

	}
	SDL_FreeSurface(menuIMG);
	retour = freeGameImages(mapTab,&gameState);
	
    //SDL_FreeSurface(bkgrnd);// libération de la surface (pas besoin de le faire pour l'écran, qui est géré en dessous dans SDL_Quit)
	SDL_Quit();// Arret de la SDL


    return 0;

}



