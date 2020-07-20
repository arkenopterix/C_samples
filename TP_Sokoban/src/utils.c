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
		pos = x+y+(y*(TAILLE_CARTE-1));
	}
	
	return pos;

}




