#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

void pause();

int main(int argc, char *argv[])
{
    //declaration de la var ecran
    SDL_Surface *ecran = NULL;
    SDL_Rect position;
    SDL_Surface *degrade[481];
    int couleur = 0;
    int i;


	SDL_Init(SDL_INIT_VIDEO); // demarrage de la SDL

	ecran = SDL_SetVideoMode(640,480,32, SDL_HWSURFACE); // taille de la fenetre


	SDL_WM_SetCaption("Degrade", NULL);// changement du nom de la fenetre

    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 17, 206, 112));

    position.x = 0; // Les coordonnées de la surface seront (0,0)
    position.y = 0;

    for(i=0;i < 481;i++)
    {
        degrade[i] = SDL_CreateRGBSurface(SDL_HWSURFACE,640,1,32,0,0,0,0);
        position.y = i;

        couleur = i/1.88;
        //remplissage de la surface rectangle avec du blanc
        SDL_FillRect(degrade[i], NULL, SDL_MapRGB(ecran->format, 255, 255,couleur ));
        SDL_BlitSurface(degrade[i], NULL, ecran, &position); // collage de la surface à l'écran

    }
    SDL_Flip(ecran); // on met à jour l'affichage

    pause();

    for(i=0;i < 481;i++)
    {
        SDL_FreeSurface(degrade[i]);// libération de la surface (pas besoin de le faire pour l'écran, qui est géré en dessous dans SDL_Quit)

	}
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
