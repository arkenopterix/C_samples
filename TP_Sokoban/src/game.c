#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "map.h"
#include "game.h"



int game(int *levTab, SDL_Surface *fond)
{
#ifdef DEBUG
    printf("game debut\n");
#endif // DEBUG
    int retour = 0;
    int continuer = 1;// variable pour la boucle infinie
    SDL_Event event;

    //remplissage du tableau de la carte grâce aux données du tableau niveau
	retour = loadMapTabFromLevelTab(mapTab,levTab,&gameState);
	if (retour != 0)
	{
#ifdef DEBUG
	    printf("game -- Retour loadMapTabFromLevelTab KO!\n");
#endif
	    return -1;
	}

	//on dessine la carte une première fois
    SDL_FillRect(fond,NULL, SDL_MapRGB(fond->format,255,255,255));
    drawMap(mapTab,&gameState,fond);
    SDL_Flip(fond); // on met à jour l'affichage
	// boucle infinie
	while((gameState.numObj != gameState.objOK) && continuer ) //tant que l'on a pas reussi a mettre les caisse sur tous les objectifs
	{
#ifdef DEBUG
	    printf("game -- Boucle principale\n");
#endif
		//on gere les events
		SDL_WaitEvent(&event); // Récupération de l'evenement dans event
        switch(event.type)
        {
            case SDL_QUIT: //event de type quitter
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE: // appui touche ECHAP
                        continuer = 0;
                        break;
                    case SDLK_UP:
                    	//on réoriente le joueur
                    	gameState.playerDir = PLAYER_U;
                        
                        //on déplace le joueur si possible
                        movePlayer(mapTab,&gameState,gameState.playerDir);

                        break;

                    case SDLK_DOWN:
                        //on réoriente le joueur
                    	gameState.playerDir = PLAYER_D;

                    	//on déplace le joueur si possible
                        movePlayer(mapTab,&gameState,gameState.playerDir);

                        break;

                    case SDLK_RIGHT:
                        //on réoriente le joueur
                    	gameState.playerDir = PLAYER_R;

                    	//on déplace le joueur si possible
                        movePlayer(mapTab,&gameState,gameState.playerDir);

                        break;

                    case SDLK_LEFT:
                        //on réoriente le joueur
                    	gameState.playerDir = PLAYER_L;

                    	//on déplace le joueur si possible
                        movePlayer(mapTab,&gameState,gameState.playerDir);

                        break;

                    default:
                    	break;

                }
                break;
           	default:
           		break;
        }

		//on redessine la carte mise a jour
		SDL_FillRect(fond,NULL, SDL_MapRGB(fond->format,255,255,255));
    	drawMap(mapTab,&gameState,fond);
    	SDL_Flip(fond); // on met à jour l'affichage
	}
	


    return 0;

}
