#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "SDL_image.h"


int main(int argc, char *argv[])
{
    //declaration de la var ecran
    SDL_Surface *ecran = NULL, *bkgrnd = NULL, *icon=NULL, *ship=NULL;
    SDL_Rect iconPos, fondPos, shipPos;
    SDL_Event event;
    int continuer = 1;// variable pour la boucle infinie
    int followMouse = 0;



	SDL_Init(SDL_INIT_VIDEO); // demarrage de la SDL

    SDL_WM_SetIcon(SDL_LoadBMP("res/icon.bmp"),NULL);
	ecran = SDL_SetVideoMode(718,638,32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE); // taille de la fenetre + enable double bufferring
    SDL_WM_SetCaption("Star Skipper", NULL);// changement du nom de la fenetre

    // Enable key repeat
    SDL_EnableKeyRepeat(10,10);




    // chargement de l'image de fond avec la fonction native SDL qui ne charge que des BMP
    bkgrnd = SDL_LoadBMP("res/fond_Space.bmp");

    fondPos.x = 0; // Les coordonnées du fond  seront (0,0)
    fondPos.y = 0;



    //on charge l'image bmp avec la methode SDL classique
    icon = IMG_Load("res/base.png");

    iconPos.x = 100; // Les coordonnées du fond  seront (0,0)
    iconPos.y = 130;

    //on ajoute la transparence
    SDL_SetColorKey(icon, SDL_SRCCOLORKEY, SDL_MapRGB(icon->format,0,15,104));

    //on rend l'image semi-tranparente (255=visible, 0=transparente, 128=valeur50% qui est optimisée dans SDL)
    SDL_SetAlpha(icon, SDL_SRCALPHA, 128);


    //chargement de l'image via la methode de SDL_Image
    ship = IMG_Load("res/skipper.png");

    shipPos.x = 200; // Les coordonnées du fond  seront (0,0)
    shipPos.y = 200;



    //boucle infinie
    while (continuer)
    {
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
                        shipPos.y -= 2;
                        break;
                    case SDLK_DOWN:
                        shipPos.y += 2;
                        break;
                    case SDLK_RIGHT:
                        shipPos.x += 2;
                        break;
                    case SDLK_LEFT:
                        shipPos.x -= 2;
                        break;
                    case SDLK_a:
                        SDL_WarpMouse(ecran->w/2, ecran->h /2);
                        break;

                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                iconPos.x = event.button.x- icon->w/2;
                iconPos.y = event.button.y- icon->h/2;
                if(followMouse == 0)
                {
                    followMouse = 1;
                    SDL_ShowCursor(SDL_DISABLE); // on cache le curseur de la souris
                } else {
                    followMouse = 0;
                    SDL_ShowCursor(SDL_ENABLE); // on montre le curseur de la souris
                }
                break;
            case SDL_MOUSEMOTION:
                if(followMouse == 1)
                {
                    iconPos.x = event.motion.x - icon->w/2;
                    iconPos.y = event.motion.y - icon->h/2;
                }
                break;
            case SDL_VIDEORESIZE:
                iconPos.x = event.resize.w/2  - icon->w/2;
                iconPos.y = event.resize.h/2 - icon->h/2;
                break;

        }
        if ((event.active.state & SDL_APPMOUSEFOCUS) == SDL_APPMOUSEFOCUS) // un seul & car il s'agit d'un & logique pour dégager le flag
        {
            if(event.active.gain == 0) // la sourie est sortie dans la fenetre
            {
                fprintf(stdout,"mouse out");
            }
            else if (event.active.gain == 1) // la sourie est entrée dans la fenetre
            {
                fprintf(stdout,"mouse in");
            }

        }
        else if ((event.active.state & SDL_APPACTIVE) == SDL_APPACTIVE)
        {
            if(event.active.gain == 0) // lfenetre a été reduite
            {
                fprintf(stdout,"la fenetre a été reduite");
            }
            else if (event.active.gain == 1) // la fenetre a été restaurée
            {
                fprintf(stdout,"la fenetre a été restaurée");
            }
        }

        // on efface l'écran
        SDL_FillRect(ecran,NULL, SDL_MapRGB(ecran->format,255,255,255));

        SDL_BlitSurface(bkgrnd, NULL, ecran, &fondPos); // collage de la surface à l'écran
        SDL_BlitSurface(icon, NULL, ecran, &iconPos);
        SDL_BlitSurface(ship, NULL, ecran, &shipPos);
        SDL_Flip(ecran); // on met à jour l'affichage
    }


    SDL_FreeSurface(bkgrnd);// libération de la surface (pas besoin de le faire pour l'écran, qui est géré en dessous dans SDL_Quit)
	SDL_Quit();// Arret de la SDL

	return EXIT_SUCCESS;
}

void pause()
{
    int continuer = 1;
    SDL_Event event;

    while (continuer)
    {
        SDL_WaitEvent( &event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}
