#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "SDL_ttf.h"

Uint32 incrementerCompteur(Uint32 intervalle , void *parametre);



int main(int argc, char *argv[])
{
    //declaration de la var ecran
    SDL_Surface *ecran = NULL, *bkgrnd = NULL, *texteBlended = NULL, *texteSolid = NULL, *texteShaded = NULL ;
    SDL_Rect pos;
    SDL_Event event;
    TTF_Font *police;
    SDL_Color couleurNoire = {0,0,0},couleurBlanche = {255,255,255} ;
    int continuer = 1;
    SDL_TimerID compteurTimerID;
    int compteur = 0;
    char txtCompt[100];

    memset (txtCompt,'\0', 99 );


	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER); // demarrage de la SDL

    if (TTF_Init() == -1)// init du module TTF
    {
        fprintf(stderr, "erreur d'initilisation module TTF : %s \n",TTF_GetError());
        exit(EXIT_FAILURE);

    }

    SDL_WM_SetIcon(SDL_LoadBMP("res/icon.bmp"),NULL);
	ecran = SDL_SetVideoMode(640,480,32, SDL_HWSURFACE | SDL_DOUBLEBUF ); // taille de la fenetre + enable double bufferring
    SDL_WM_SetCaption("Star Skipper", NULL);// changement du nom de la fenetre

    //Initialisation du timer pour la modification de l'alpha de la base
    compteurTimerID = SDL_AddTimer(100, incrementerCompteur, &compteur);


    // chargement de l'image de fond avec la fonction native SDL qui ne charge que des BMP
    bkgrnd = SDL_LoadBMP("res/fond_Space.bmp");



    //chargement de la police
    police =TTF_OpenFont("res/Cardinal.ttf",64);

    //Mettre le texteBlended en italique
    TTF_SetFontStyle(police, TTF_STYLE_ITALIC);

    if (police == NULL)
    {
        printf("erreur chargement police");
        exit(EXIT_FAILURE);
    }
    //Ecriture du texteBlended dans la SDL_Surface texteBlended en mode Blended (optimal)
    texteBlended = TTF_RenderText_Blended(police,"StarTrader", couleurNoire);

    //Ecriture du texteBlended dans la SDL_Surface texteBlended en mode Solid (plus rapide,mais moche)
    texteSolid = TTF_RenderText_Solid(police,"StarTrader", couleurNoire);

    //Ecriture du texteBlended dans la SDL_Surface texteBlended en mode Blended (plus rapide que blended, mais nécessite un fond uni)
    texteShaded = TTF_RenderText_Shaded(police,"StarTrader", couleurNoire,couleurBlanche);

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

                }
                break;
        }
 
        // on efface l'écran
        SDL_FillRect(ecran,NULL, SDL_MapRGB(ecran->format,255,255,255));

        // Les coordonnées du fond  seront (0,0)
        pos.x = 0; 
        pos.y = 0;
        SDL_BlitSurface(bkgrnd, NULL, ecran, &pos); // collage de la surface à l'écran

        sprintf(txtCompt, "compteur: %d",compteur);
        
        //on libère la surface en vue de la recréer
        SDL_FreeSurface(texteShaded);
        //Ecriture du texteBlended dans la SDL_Surface texteBlended en mode Blended (plus rapide que blended, mais nécessite un fond uni)
        texteShaded = TTF_RenderText_Shaded(police,txtCompt, couleurNoire,couleurBlanche);
        // Les coordonnées du fond  seront (0,0)
        pos.x = 0; 
        pos.y = 0;
        SDL_BlitSurface(texteSolid, NULL, ecran, &pos); // collage de la surface à l'écran

        // Les coordonnées du fond  seront (0,0)
        pos.x = 100; 
        pos.y = 50;
        SDL_BlitSurface(texteShaded, NULL, ecran, &pos); // collage de la surface à l'écran

        // Les coordonnées du fond  seront (0,0)
        pos.x = 320; 
        pos.y = 240;
        SDL_BlitSurface(texteBlended, NULL, ecran, &pos); // collage de la surface à l'écran

        SDL_Flip(ecran); // on met à jour l'affichage
    }

    

    //on ferme la font chargée
    TTF_CloseFont(police);

    TTF_Quit();//Arret de TTF

    SDL_FreeSurface(texteBlended);
    SDL_FreeSurface(texteShaded);
    SDL_FreeSurface(texteSolid);
    SDL_RemoveTimer(compteurTimerID); // on retire le timer déclaré plus haut
    SDL_FreeSurface(bkgrnd);// libération de la surface (pas besoin de le faire pour l'écran, qui est géré en dessous dans SDL_Quit)
	SDL_Quit();// Arret de la SDL

	return EXIT_SUCCESS;
}


//Fonction callback qui sera appelée toutes les X ms)
Uint32 incrementerCompteur(Uint32 intervalle , void *parametre)
{
    int *compteur = parametre; // On recrée le paramètre souhaité à partir du pointeur sur void
    *compteur= *compteur +1;

    return intervalle; // on retourne un nouvel intervalle de temps si on veux, ici, on maintient l'intervalle donné en entrée
}
