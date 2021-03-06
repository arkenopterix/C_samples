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
				break;
			case CRATE_MOV:
				gs->numCrate++;
				break;
			case CRATE_FIX:
				break;
			case WALL:
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
		gs->mapIMG[PLAYER_U] = IMG_Load("res/aboni_haut.png");
		gs->mapIMG[PLAYER_D] = IMG_Load("res/aboni_bas.png");
		gs->mapIMG[PLAYER_L] = IMG_Load("res/aboni_gauche.png");
		gs->mapIMG[PLAYER_R] = IMG_Load("res/aboni_droite.png");
		gs->mapIMG[WALL] = IMG_Load("res/mur.jpg");
		gs->mapIMG[OBJECTIF] = IMG_Load("res/objectif.png");
		gs->mapIMG[CRATE_MOV] = IMG_Load("res/caisse.jpg");
		gs->mapIMG[CRATE_FIX] = IMG_Load("res/caisse_ok.jpg");


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
	SDL_Rect curPlayerPos, tilePose;
#ifdef DEBUG
    			printf("drawMap -- START\n");
#endif // DEBUG
	for(i = 0;i < TAILLE_CARTE*TAILLE_CARTE;i++)
	{
		switch(mt[i].type)
		{
			case EMPTY:
#ifdef DEBUG
    			printf("drawMap -- case[%d]=EMPTY\n",i);
#endif
				break;
			case OBJECTIF:
#ifdef DEBUG
    			printf("drawMap -- case[%d]=OBJECTIF\n",i);
#endif 

				SDL_BlitSurface(gs->mapIMG[OBJECTIF], NULL, bg, &mt[i].casePos);
				break;
			case CRATE_MOV:
#ifdef DEBUG
    			printf("drawMap -- case[%d]=CRATE_MOV\n",i);
#endif 
				SDL_BlitSurface(gs->mapIMG[CRATE_MOV], NULL, bg, &mt[i].casePos);
				break;
			case CRATE_FIX:
#ifdef DEBUG
    			printf("drawMap -- case[%d]=CRATE_FIX\n",i);
#endif 
				SDL_BlitSurface(gs->mapIMG[CRATE_FIX], NULL, bg, &mt[i].casePos);
				break;
			case WALL:
#ifdef DEBUG
    			printf("drawMap -- case[%d]=WALL\n",i);
#endif 
				SDL_BlitSurface(gs->mapIMG[WALL], NULL, bg, &mt[i].casePos);				
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
	SDL_BlitSurface(gs->mapIMG[gs->playerDir], NULL, bg, &curPlayerPos);



}



int freeGameImages(Case *mt,  GameState *gs)
{
	int ret = 0;
	int i;
#ifdef DEBUG
    			printf("freeGameImages -- START\n");
#endif // DEBUG
	for(i = 0;i < 8;i++)
	{

#ifdef DEBUG
    			printf("freeGameImages -- freeing loaded map images %d\n",i);
#endif 
		SDL_FreeSurface(gs->mapIMG[i]);
		

	}
#ifdef DEBUG
    			printf("freeGameImages -- END ret:%d\n",ret);
#endif // DEBUG
	return ret;

}



int movePlayer(Case *mt,  GameState *gs, int direction)
{
	int ret = 0;
	int newpos,tempVal ;
#ifdef DEBUG
    printf("movePlayer -- START\n");
#endif // DEBUG
    switch(direction)
	{
    	case PLAYER_U:
#ifdef DEBUG
    		printf("movePlayer -- moving player UP\n");
#endif // DEBUG
    		// on calcul la future position du joueur
			newpos = newPosFromMove(gs->playerPos,direction);
			break;
		case PLAYER_D:
#ifdef DEBUG
    		printf("movePlayer -- moving player DOWN\n");
#endif // DEBUG
    		// on calcul la future position du joueur
			newpos = newPosFromMove(gs->playerPos,direction);
			break;
		case PLAYER_L:
#ifdef DEBUG
    		printf("movePlayer -- moving player LEFT\n");
#endif // DEBUG
    		// on calcul la future position du joueur
			newpos = newPosFromMove(gs->playerPos,direction);
			break;
		case PLAYER_R:
#ifdef DEBUG
    		printf("movePlayer -- moving player RIGHT\n");
#endif // DEBUG
   		    // on calcul la future position du joueur
			newpos = newPosFromMove(gs->playerPos,direction);
			break;
		default:
#ifdef DEBUG
    		printf("ERROR -- movePlayer -- unknown dir! : %d\n",direction);
#endif // DEBUG		
			break;
		}
		// si le mouvement est dans les limitesde la carte
		if(newpos != -1)
		{
			// on teste la collision de la future position avec un mur
			if ((mt[newpos].type != WALL) && (mt[newpos].type != CRATE_FIX))
			{

				if(mt[newpos].type == CRATE_MOV)
				{
					tempVal = moveCrate(mt,gs,newpos,direction);
					if(tempVal == MOVE_OK)
					{
						//la fonction movecrate à autorisé le mouvement
						gs->playerPos = newpos;
#ifdef DEBUG
    		printf("movePlayer --deplacement de la caisse OK  mt[%d].type:%d  mtNext[%d].type:%d\n",newpos,mt[newpos].type,newPosFromMove(newpos,direction),mt[newPosFromMove(newpos,direction)].type);
#endif
					}
				}
				else
				{
					//déplacement ok, on met à jour la position du joueur
					gs->playerPos = newpos;
				}
				
			}
		}

#ifdef DEBUG
    printf("movePlayer -- END ret:%d\n",ret);
#endif // DEBUG
	return ret;
}


int moveCrate(Case *mt, GameState *gs, int newPlayerPos, int direction)
{
	// Par défaut on considère le mouvement impossible
	int ret = MOVE_IMPOSSIBLE; 
	int newpos;
	SDL_Surface *tmpPt;
#ifdef DEBUG
    printf("moveCrate -- START newpos:%d, direction: %d\n",newPlayerPos,direction);
#endif

     switch(direction)
	{
    	case PLAYER_U:
#ifdef DEBUG
    		printf("moveCrate -- moving crate UP\n");
#endif // DEBUG
    		// on calcul la future position de la caisse
			newpos = newPosFromMove(newPlayerPos,direction);
			break;
		case PLAYER_D:
#ifdef DEBUG
    		printf("moveCrate -- moving crate DOWN\n");
#endif // DEBUG
    		// on calcul la future position de la caisse
			newpos = newPosFromMove(newPlayerPos,direction);
			break;
		case PLAYER_L:
#ifdef DEBUG
    		printf("moveCrate -- moving crate LEFT\n");
#endif // DEBUG
    		// on calcul la future position de la caisse
			newpos = newPosFromMove(newPlayerPos,direction);
			break;
		case PLAYER_R:
#ifdef DEBUG
    		printf("moveCrate -- moving crate RIGHT\n");
#endif // DEBUG
   		    // on calcul la future position de la caisse
			newpos = newPosFromMove(newPlayerPos,direction);
			break;
		default:
#ifdef DEBUG
    		printf("ERROR -- moveCrate -- unknown dir! : %d\n",direction);
#endif // DEBUG		
			break;
		}   
		if(newpos != -1)
		{
			// on teste la collision de la future position avec un mur
			if ((mt[newpos].type == WALL) || (mt[newpos].type == CRATE_MOV ) || (mt[newpos].type == CRATE_FIX ))
			{
#ifdef DEBUG
    		printf("ERROR -- moveCrate --deplacementde la caisse impossible (mt[%d].type:%d\n",newpos,mt[newpos].type);
#endif 
				return MOVE_IMPOSSIBLE;

			}
			else if (mt[newpos].type == EMPTY)
			{
				//La caisse peut être déplacée, on la déplace
#ifdef DEBUG
    		printf("moveCrate --deplacement de la caisse OK mt[%d].type:%d  mt[%d].type:%d\n",newPlayerPos,mt[newPlayerPos].type,newpos,mt[newpos].type);
#endif
    			// on procède au changement de types pour les cases
				mt[newPlayerPos].type = EMPTY;
				mt[newpos].type = CRATE_MOV;

	


#ifdef DEBUG
    		printf("moveCrate --deplacement de la caisse OK mt[%d].type:%d  mt[%d].type:%d\n",newPlayerPos,mt[newPlayerPos].type,newpos,mt[newpos].type);
#endif
			}
			else if (mt[newpos].type == OBJECTIF)
			{
				// On déplace la caisse sur un objectif! on met à jour la carte
				mt[newPlayerPos].type = EMPTY;
				mt[newpos].type = CRATE_FIX;

				//on met à jour le statut du jeu
				gs->objOK++;
#ifdef DEBUG
    		printf("moveCrate --deplacement de la caisse OK objectif OK! mt[%d].type:%d  mt[%d].type:%d\n",newPlayerPos,mt[newPlayerPos].type,newpos,mt[newpos].type);
#endif
			}
		}

#ifdef DEBUG
    printf("moveCrate -- END ret:%d\n",MOVE_OK);
#endif // DEBUG
	return MOVE_OK;

}