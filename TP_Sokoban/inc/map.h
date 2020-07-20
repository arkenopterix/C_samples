#ifndef MAP
#define MAP
#include <SDL/SDL.h>
#include "SDL_image.h"
#include "const.h"

#define TAILLE_CASE_PX 34
#define TAILLE_CARTE 12
#define TAILLE_CARTE_PX TAILLE_CASE_PX*TAILLE_CARTE


typedef struct Case Case;
struct Case
{
    int type;
    int x;
    int y;
    SDL_Surface *caseIMG;
};

Case mapTab[TAILLE_CARTE*TAILLE_CARTE];

int loadMapTabFromLevelTab(Case *mt, int *lt, GameState *gs);

#endif
