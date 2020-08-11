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
    int type; //type de case
    int x; // coord x de la case sur la carte
    int y; // coord y de la case sur la carte
    SDL_Rect casePos;
};

Case mapTab[TAILLE_CARTE*TAILLE_CARTE];

// structure permettant de stocker les donnes du jeu
typedef struct GameState GameState;
struct GameState
{
    int numObj;// nombre d'objectifs dans le niveau
    int numCrate; //nombre de caisses dans le niveau
    int numWall; //nombre de murs
    int objOK; //nombre d'objectifs accomplis
    int playerPos; // position du joueur sur le tableau
    int playerDir; // direction du joueur
    SDL_Surface *mapIMG[8]; // tableau contenant les images des differentes tiles du jeu
};

GameState gameState;



int loadMapTabFromLevelTab(Case *mt, int *lt, GameState *gs);

int drawMap(Case *mt, GameState *gs, SDL_Surface *bg);

int freeGameImages(Case *mt,  GameState *gs);

int movePlayer(Case *mt,  GameState *gs, int direction);

int moveCrate(Case *mt,GameState *gs, int newPlayerPos, int direction);


#endif
