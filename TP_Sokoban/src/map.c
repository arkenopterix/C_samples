#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "utils.h"

int loadMapTabFromLevelTab(Case **mt, int *lt, GameState *gs)
{
	int ret = 0;
	int i;
#ifdef DEBUG
    			printf("loadMapTabFromLevelTab -- START\n");
#endif // DEBUG
	for(i = 0;i < TAILLE_CARTE*TAILLE_CARTE;i++)
	{
		mt[i]->x=pos2x(i);
		mt[i]->y=pos2y(i);
		mt[i]->type = lt[i];
		switch(lt[i])
		{
			case EMPTY:
				break;
			case OBJECTIF:
				gs->numObj++;
				mt[i]->caseIMG[0] = IMG_Load("res/objectif.png");
				break;
			case CRATE_MOV:
				mt[i]->caseIMG[0] = IMG_Load("res/caisse.jpg");
				mt[i]->caseIMG[1] = IMG_Load("res/caisse_ok.jpg");
				gs->numCrate++;
				break;
			case CRATE_FIX:
				break;
			case WALL:
				mt[i]->caseIMG[0] = IMG_Load("res/mur.jpg");
				gs->numWall++;
				break;
			default:
#ifdef DEBUG
    			printf("ERROR -- loadMapTabFromLevelTab -- unknown square type: %d\n",lt[i] );
#endif // DEBUG
				ret = -1;
				break;
		}
	}
#ifdef DEBUG
    			printf("loadMapTabFromLevelTab -- END ret:%d\n",ret);
#endif // DEBUG
	return ret;

}
