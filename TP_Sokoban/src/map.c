#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "utils.h"

int loadMapTabFromLevelTab(Case *mt, int *lt, GameState *gs)
{
	int ret = 0;
	int i;
#ifdef DEBUG
    			printf("loadMapTabFromLevelTab -- START\n");
#endif // DEBUG
	for(i = 0;i < TAILLE_CARTE*TAILLE_CARTE;i++)
	{
#ifdef DEBUG
    			printf("loadMapTabFromLevelTab -- assigning value to square: %d\n",i);
#endif 
   			
		mt[i].x=pos2x(i);
		mt[i].y=pos2y(i);
		mt[i].casePos.x=mt[i].x * TAILLE_CASE_PX;
		mt[i].casePos.y=mt[i].y * TAILLE_CASE_PX;
		mt[i].type = lt[i];

#ifdef DEBUG
    			printf("loadMapTabFromLevelTab -- mt[i].x: %d mt[i].y: %d, mt[i].type:%d\n",mt[i].x,mt[i].y,mt[i].type);
#endif 
		switch(lt[i])
		{
			case EMPTY:
				break;
			case OBJECTIF:
				gs->numObj++;
				mt[i].caseIMG[0] = IMG_Load("res/objectif.png");
				break;
			case CRATE_MOV:
				mt[i].caseIMG[0] = IMG_Load("res/caisse.jpg");
				mt[i].caseIMG[1] = IMG_Load("res/caisse_ok.jpg");
				gs->numCrate++;
				break;
			case CRATE_FIX:
				break;
			case WALL:
				mt[i].caseIMG[0] = IMG_Load("res/mur.jpg");
				gs->numWall++;
				break;
			case PLAYER_U:
				gs->playerPos = i;
				gs->playerDir = PLAYER_U;
				mt[i].type = EMPTY;
				break;
			case PLAYER_D:
				gs->playerPos = i;
				gs->playerDir = PLAYER_D;
				mt[i].type = EMPTY;
				break;
			case PLAYER_L:
				gs->playerPos = i;
				gs->playerDir = PLAYER_L;
				mt[i].type = EMPTY;
				break;
			case PLAYER_R:
				gs->playerPos = i;
				gs->playerDir = PLAYER_R;
				mt[i].type = EMPTY;
				break;
			default:
#ifdef DEBUG
    			printf("ERROR -- loadMapTabFromLevelTab -- unknown square type: %d\n",lt[i] );
#endif // DEBUG
				ret = -1;
				break;
		}
		gs->playerIMG[0] = IMG_Load("res/mario_haut.gif");
		gs->playerIMG[1] = IMG_Load("res/mario_bas.gif");
		gs->playerIMG[2] = IMG_Load("res/mario_gauche.gif");
		gs->playerIMG[3] = IMG_Load("res/mario_droite.gif");


	}
#ifdef DEBUG
    			printf("loadMapTabFromLevelTab -- END ret:%d\n",ret);
#endif // DEBUG
	return ret;

}

int drawMap(Case *mt, GameState *gs, SDL_Surface *bg)
{
	//on itere sur le tableau de cases pour préparer une à une les images de la carte
	int ret = 0;
	int i;
	SDL_Rect curPlayerPos;
#ifdef DEBUG
    			printf("drawMap -- START\n");
#endif // DEBUG
	for(i = 0;i < TAILLE_CARTE*TAILLE_CARTE;i++)
	{
		switch(mt[i].type)
		{
			case EMPTY:
				break;
			case OBJECTIF:
				SDL_BlitSurface(mt[i].caseIMG[0], NULL, bg, &mt[i].casePos);
				mt[i].caseIMG[0] = IMG_Load("res/objectif.png");
				break;
			case CRATE_MOV:
				SDL_BlitSurface(mt[i].caseIMG[0], NULL, bg, &mt[i].casePos);
				break;
			case CRATE_FIX:
				break;
			case WALL:
				SDL_BlitSurface(mt[i].caseIMG[0], NULL, bg, &mt[i].casePos);
				
				break;
			default:
#ifdef DEBUG
    			printf("ERROR -- drawMap -- unknown square type: %d\n",mt[i].type );
#endif // DEBUG
				ret = -1;
				break;
		}
	}

	//on dessine maintenant le joueur au dessus de la carte
	curPlayerPos.x = pos2x(gs->playerPos)* TAILLE_CASE_PX;
	curPlayerPos.y = pos2y(gs->playerPos)* TAILLE_CASE_PX;
#ifdef DEBUG
    			printf("drawMap -- player pos: x %d ; y %d\n",curPlayerPos.x, curPlayerPos.y);
#endif	
	SDL_BlitSurface(gs->playerIMG[gs->playerDir], NULL, bg, &curPlayerPos);



}



int freeGameImages(Case *mt,  GameState *gs)
{
	int ret = 0;
	int i;
#ifdef DEBUG
    			printf("freeGameImages -- START\n");
#endif // DEBUG
	for(i = 0;i < TAILLE_CARTE*TAILLE_CARTE;i++)
	{

#ifdef DEBUG
    			printf("freeGameImages -- freeing loaded map images %d\n",i);
#endif 
		switch(mt[i].type)
		{
			case EMPTY:
				break;
			case OBJECTIF:
				gs->numObj--;
				if (mt[i].caseIMG[0] != NULL)
				{
					SDL_FreeSurface(mt[i].caseIMG[0]);
				}	
				break;
			case CRATE_MOV:
				if (mt[i].caseIMG[0] != NULL)
				{
					SDL_FreeSurface(mt[i].caseIMG[0]);
				}
				if (mt[i].caseIMG[1] != NULL)
				{
					SDL_FreeSurface(mt[i].caseIMG[1]);
				}		
				gs->numCrate--;
				break;
			case CRATE_FIX:
				break;
			case WALL:
				if (mt[i].caseIMG[0] != NULL)
				{
					SDL_FreeSurface(mt[i].caseIMG[0]);
				}	
				gs->numWall--;
				break;
			default:
#ifdef DEBUG
    			printf("ERROR -- freeGameImages -- unknown square type: %d\n",mt[i].type);
#endif // DEBUG
				ret = -1;
				break;
		}
		if (gs->playerIMG[0] != NULL)
		{
			SDL_FreeSurface(gs->playerIMG[0]);
		}	
		if (gs->playerIMG[1] != NULL)
		{
			SDL_FreeSurface(gs->playerIMG[1]);
		}	
		if (gs->playerIMG[2] != NULL)
		{
			SDL_FreeSurface(gs->playerIMG[2]);
		}	
		if (gs->playerIMG[3] != NULL)
		{
			SDL_FreeSurface(gs->playerIMG[3]);
		}		

	}
#ifdef DEBUG
    			printf("freeGameImages -- END ret:%d\n",ret);
#endif // DEBUG
	return ret;

}