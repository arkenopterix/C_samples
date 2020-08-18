#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "SDL_image.h"

Uint32 bougerBase(Uint32 intervalle , void *parametre);



int main(int argc, char *argv[])
{
    //declaration de la var ecran
    SDL_Surface *ecran = NULL, *bkgrnd = NULL, *ship=NULL, *base=NULL;
    SDL_Rect fondPos, shipPos, basePos;
    SDL_Event event;
    int continuer = 1;// variable pour la boucle infinie
    int tempsPrecedent = 0, tempsActuel = 0;//variables utilisées pour la gestion du temps écoulé
    SDL_TimerID baseTimerID;




	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER); // demarrage de la SDL

    SDL_WM_SetIcon(SDL_LoadBMP("res/icon.bmp"),NULL);
	ecran = SDL_SetVideoMode(718,638,32, SDL_HWSURFACE | SDL_DOUBLEBUF ); // taille de la fenetre + enable double bufferring
    SDL_WM_SetCaption("Star Skipper", NULL);// changement du nom de la fenetre

    //Initialisation du timer pour la modification de l'alpha de la base
    baseTimerID = SDL_AddTimer(30, bougerBase, &basePos);


    // chargement de l'image de fond avec la fonction native SDL qui ne charge que des BMP
    bkgrnd = SDL_LoadBMP("res/fond_Space.bmp");

    fondPos.x = 0; // Les coordonnées du fond  seront (0,0)
    fondPos.y = 0;


    //chargement de l'image via la methode de SDL_Image
    ship = IMG_Load("res/skipper.png");

    shipPos.x = 200; // Les coordonnées du fond  seront (0,0)
    shipPos.y = 200;

    //on charge l'image bmp avec la methode SDL classique
    base = IMG_Load("res/base.png");

    basePos.x = 100; // Les coordonnées du fond  seront (0,0)
    basePos.y = 130;

    //boucle infinie
    while (continuer)
    {
        SDL_PollEvent(&event); // Récupération de l'evenement dans event
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
                        shipPos.y -= 2;
                        break;

                }
                break;
        }
        tempsActuel = SDL_GetTicks();// On récupère le nombre de milisecondes depuis le démarrage de l'application (se réinitialise au bout de 49 jours d'execution)
        if (tempsActuel - tempsPrecedent > 30)// si au moins 30ms se sont écoulés depuis la dernière boucle
        {
            shipPos.x ++;
            tempsPrecedent = tempsActuel; //on réinitialise notre compteur temps
        }
        else //sinon, on met le programe en veille pour environ le temps qu'il faut pour atteindre 30ms
        {
            SDL_Delay(30 - (tempsActuel - tempsPrecedent));
        }


        // on efface l'écran
        SDL_FillRect(ecran,NULL, SDL_MapRGB(ecran->format,255,255,255));
        SDL_BlitSurface(bkgrnd, NULL, ecran, &fondPos); // collage de la surface à l'écran
        SDL_BlitSurface(ship, NULL, ecran, &shipPos);
        SDL_BlitSurface(base, NULL, ecran, &basePos);
        SDL_Flip(ecran); // on met à jour l'affichage
    }

    SDL_RemoveTimer(baseTimerID); // on retire le timer déclaré plus haut
    SDL_FreeSurface(bkgrnd);// libération de la surface (pas besoin de le faire pour l'écran, qui est géré en dessous dans SDL_Quit)
    SDL_FreeSurface(ship);
	SDL_Quit();// Arret de la SDL

	return EXIT_SUCCESS;
}


//Fonction callback qui sera appelée toutes les X ms)
Uint32 bougerBase(Uint32 intervalle , void *parametre)
{
    SDL_Rect* basePos = parametre; // On recrée le paramètre souhaité à partir du pointeur sur void
    basePos->x++;
    return intervalle; // on retourne un nouvel intervalle de temps si on veux, ici, on maintient l'intervalle donné en entrée
}
