#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "SDL_image.h"
#include "menu.h"
#include "const.h"



int menu(SDL_Surface *ecran)
{
#ifdef DEBUG
    printf("Menu debut\n");
#endif // DEBUG
    int retour = 0, continuer= 1;
    SDL_Rect menuPos, mousePos;
    int choixJeu = MENU;// variable pour la seletion du menu
    SDL_Event event;

	//on dessine le menu
    menuIMG = IMG_Load("res/menu.jpg");
    SDL_FillRect(ecran,NULL, SDL_MapRGB(ecran->format,255,255,255));
    menuPos.x=0;
    menuPos.y=0;
    SDL_BlitSurface(menuIMG, NULL, ecran, &menuPos);
    SDL_Flip(ecran); // on met à jour l'affichage
#ifdef DEBUG
        printf("Menu -- Boucle principale\n");
#endif
	// boucle infinie
	while(choixJeu != QUITTER) //tant que l'on a pas reussi a mettre les caisse sur tous les objectifs
	{

		//on gere les events
		SDL_WaitEvent(&event); // Récupération de l'evenement dans event
        switch(event.type)
        {
            case SDL_QUIT: //event de type quitter
                continuer = 0;
                return QUITTER;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE: // appui touche ECHAP
                        continuer = 0;
                        break;
                    case SDLK_a:
                    	//on réoriente le joueur
                        return QUITTER;

                        break;

                    case SDLK_z:
                        //on réoriente le joueur
                        return MENU;

                        break;

                    case SDLK_e:
                        //on réoriente le joueur
                        return JEU;

                        break;

                    case SDLK_r:
                        //on réoriente le joueur
                        return EDITEUR;

                        break;
                    

                    default:
                    	break;

                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                if (event.button.x>110 && event.button.x<285)
                {
#ifdef DEBUG
                    printf("X:%d\n",event.button.x);
#endif
                    if(event.button.y>230 && event.button.y<270)
                    {
#ifdef DEBUG
                        printf("JEU y:%d\n",event.button.y);
#endif
                        return JEU;
                    }
                    else if(event.button.y>286 && event.button.y<330)
                    {
#ifdef DEBUG
                        printf("EDITEUR y:%d\n",event.button.y);
#endif
                        return EDITEUR;
                    }
                    else if(event.button.y>340 && event.button.y<380)
                    {
#ifdef DEBUG
                        printf("QUITTER y:%d\n",event.button.y);
#endif
                        return QUITTER;
                    }
                    else
                    {
                        break;
                    }
                }
                break;
           	default:
           		break;
        }

	}


    return QUITTER;

}



