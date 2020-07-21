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

	x = pos % TAILLE_CARTE;

	return x;

}


/*
*   Fonction pour récupérer la coordonnées y dans la carte a partir de la position dans le tableau de la carte
*/
int pos2y(int pos)
{
	int y = -1;

	y = pos / TAILLE_CARTE;

	return y;
}

