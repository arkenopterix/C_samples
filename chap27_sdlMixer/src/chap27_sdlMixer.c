#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "SDL_image.h"
#include <SDL_mixer.h>


int main(int argc, char *argv[])
{
    //declaration de la var ecran
    SDL_Surface *ecran = NULL, *bkgrnd = NULL, *icon=NULL;
    SDL_Rect iconPos, fondPos;
    SDL_Event event;
    int continuer = 1;// variable pour la boucle infinie
    int followMouse = 0;
    //Structure pour la musique
    Mix_Music *musique = NULL;

    //Structure pour le son
    Mix_Chunk *hatchSound = NULL;
    Mix_Chunk *panSound = NULL;

    // demarrage de la SDL
    if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 )
    {
        printf( "Erreur lors de l'init d'SDL: %s\n", SDL_GetError() );
        exit(EXIT_FAILURE);
    } 

    //demarrage de SDL_mixer Mix_OpenAudio( frequence son, sample format, nombre de hadware channels (2 pour stéréo), sample size - taille des chunks utilisées pour la lecture ici 2ko)
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        printf( "Erreur lors de l'init d'SDL_mixer : %s\n", Mix_GetError() );
        exit(EXIT_FAILURE);
    }

    SDL_WM_SetIcon(SDL_LoadBMP("res/icon.bmp"),NULL);
	ecran = SDL_SetVideoMode(718,638,32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE); // taille de la fenetre + enable double bufferring
    SDL_WM_SetCaption("Star Skipper", NULL);// changement du nom de la fenetre
    SDL_ShowCursor(SDL_DISABLE); // on cache le curseur de la souris
    // Enable key repeat
    SDL_EnableKeyRepeat(10,10);

    //Load music
    musique = Mix_LoadMUS( "res/hype_home.mp3" );
    if( musique == NULL )
    {
        printf( "Failed to load hype_home music! SDL_mixer Error: %s\n", Mix_GetError() );
        exit(EXIT_FAILURE);
    }

    //Load sound effects
    hatchSound = Mix_LoadWAV( "res/hatch.wav" );
    if( hatchSound == NULL )
    {
        printf( "Failed to load hatch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        exit(EXIT_FAILURE);
    }

   //Load sound effects
    panSound = Mix_LoadWAV( "res/pan.wav" );
    if( panSound == NULL )
    {
        printf( "Failed to load pan sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        exit(EXIT_FAILURE);
    }


    // chargement de l'image de fond avec la fonction native SDL qui ne charge que des BMP
    bkgrnd = SDL_LoadBMP("res/fond_Space.bmp");

    fondPos.x = 0; // Les coordonnées du fond  seront (0,0)
    fondPos.y = 0;



    //on charge l'image bmp avec la methode SDL classique
    icon = IMG_Load("res/viseur.png");

    iconPos.x = 100; // Les coordonnées du fond  seront (0,0)
    iconPos.y = 130;


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
                    case SDLK_a:
                        Mix_PlayChannel( -1, hatchSound, 0 );
                        break;
                    case SDLK_z:
                        if( Mix_PlayingMusic() == 0 )
                        {
                            //Lancer la musique
                            Mix_PlayMusic( musique, -1 );
                        }
                        //Sinon, c'est que la musique est en cours de lecture
                        else
                        {
                            //Si la musique est en pause
                            if( Mix_PausedMusic() == 1 )
                            {
                                //reprendre le morceau
                                Mix_ResumeMusic();
                            }
                            //Si la musique est en cours de lecture
                            else
                            {
                                //mettre la lecture en pause
                                Mix_PauseMusic();
                            }
                        }
                        break;
                    case SDLK_e:
                        Mix_HaltMusic(); // arret musique
                        break;
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                Mix_PlayChannel( -1, panSound, 0 );
                break;
            case SDL_MOUSEMOTION:
                iconPos.x = event.motion.x - icon->w/2;
                iconPos.y = event.motion.y - icon->h/2;
                break;

        }


        // on efface l'écran
        SDL_FillRect(ecran,NULL, SDL_MapRGB(ecran->format,255,255,255));

        SDL_BlitSurface(bkgrnd, NULL, ecran, &fondPos); // collage de la surface à l'écran
        SDL_BlitSurface(icon, NULL, ecran, &iconPos);
        SDL_Flip(ecran); // on met à jour l'affichage
    }

    Mix_FreeChunk(hatchSound);
    Mix_FreeChunk(panSound);
    Mix_FreeMusic(musique);
    SDL_FreeSurface(bkgrnd);// libération de la surface (pas besoin de le faire pour l'écran, qui est géré en dessous dans SDL_Quit)
    Mix_Quit(); // arret module SDLmixer
	SDL_Quit();// Arret de la SDL

	return EXIT_SUCCESS;
}