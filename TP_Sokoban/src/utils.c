#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "map.h"





/*
*   Fonction pour récupérer la position dans le tableau de la carte à partir des coordonnées x/y
*/
int coord2pos(int x, int y)
{
    int pos = -1;
	
	if ((0<x<TAILLE_CARTE) && (0<y<TAILLE_CARTE))
	{
		pos = x+(y*TAILLE_CARTE);
	}
	
	return pos;

}


/*
*   Fonction pour récupérer la coordonnées x dans la carte a partir de la position dans le tableau de la carte
*/
int pos2x(int pos)
{
	int x = -1;
#ifdef DEBUG
    printf("|---- utils -- pos2x --DEBUT\n");
#endif // DEBUG
	x = pos % TAILLE_CARTE;
#ifdef DEBUG
    printf("|---- utils -- pos2x --FIN x: %d\n",x);
#endif // DEBUG
	return x;

}


/*
*   Fonction pour récupérer la coordonnées y dans la carte a partir de la position dans le tableau de la carte
*/
int pos2y(int pos)
{
	int y = -1;
#ifdef DEBUG
    printf("	|---- utils -- pos2y --DEBUT\n");
#endif // DEBUG
	y = pos / TAILLE_CARTE;
#ifdef DEBUG
    printf("	|---- utils -- pos2y --FIN y: %d\n",y);
#endif // DEBUG
	return y;
}

/*
*   Fonction pour récupérer la nouvelle position lors d'un déplacement 2D dans le tableau à partir d'un postition donnée
*/
int newPosFromMove(int pos, int direction)
{
	int newPos = -1;
	int x=0,y=0;
#ifdef DEBUG
    printf("	|---- utils -- newPosFromMove --DEBUT pos : %d direction : %d\n",pos,direction);
#endif // DEBUG
	switch(direction)
	{
    	case PLAYER_U:
    		x = pos2x(pos);
    		y = pos2y(pos);
    		y--;
    		if(y < 0)
    		{
#ifdef DEBUG
    			printf("	|---- utils -- newPosFromMove --FIN newPos: %d\n",y);
#endif // DEBUG
    			return pos;
    		}
    		newPos = coord2pos(x,y);
			break;
		case PLAYER_D:
			x = pos2x(pos);
    		y = pos2y(pos);
    		y++;
    		if(y >= TAILLE_CARTE)
    		{
#ifdef DEBUG
    			printf("	|---- utils -- newPosFromMove --FIN newPos: %d\n",y);
#endif // DEBUG
    			return pos;
    		}
    		newPos = coord2pos(x,y);
			break;
		case PLAYER_L:
			x = pos2x(pos);
    		y = pos2y(pos);
    		x--;
    		if(x < 0)
    		{
#ifdef DEBUG
    			printf("	|---- utils -- newPosFromMove --FIN newPos: %d\n",y);
#endif // DEBUG
    			return pos;
    		}
    		newPos = coord2pos(x,y);
			break;
		case PLAYER_R:
			x = pos2x(pos);
    		y = pos2y(pos);
    		x++;
    		if(x >= TAILLE_CARTE)
    		{
#ifdef DEBUG
    			printf(	"	|---- utils -- newPosFromMove --FIN newPos: %d\n",y);
#endif // DEBUG
    			return pos;
    		}
    		newPos = coord2pos(x,y);
			break;
		default:
#ifdef DEBUG
    		printf("ERROR -- newPosFromMove -- unknown dir! : %d\n",direction);
#endif // DEBUG		
			break;

		}
#ifdef DEBUG
    printf("	|---- utils -- newPosFromMove --FIN newPos: %d\n",y);
#endif // DEBUG
	return newPos;
}