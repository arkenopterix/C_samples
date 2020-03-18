#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

void pause();

int main(int argc, char *argv[])
{
    //declaration de la var ecran
    SDL_Surface *ecran = NULL;

	SDL_Init(SDL_INIT_VIDEO); // demarrage de la SDL

	ecran = SDL_SetVideoMode(640,480,32, SDL_HWSURFACE); // taille de la fenetre


	SDL_WM_SetCaption("Star Skipper", NULL);// changement du nom de la fenetre

    pause();

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
