#ifndef LEVEL
#define LEVEL
#include "const.h"

int levelTab[TAILLE_CARTE*TAILLE_CARTE] = {WALL      ,WALL      ,WALL      ,WALL      ,WALL      ,EMPTY     ,EMPTY     ,WALL      ,WALL      ,WALL      ,WALL      ,WALL, 
 WALL      ,WALL      ,WALL      ,WALL      ,WALL      ,EMPTY     ,EMPTY     ,EMPTY     ,EMPTY     ,EMPTY     ,EMPTY     ,WALL,
 WALL      ,WALL      ,WALL      ,WALL      ,EMPTY     ,EMPTY     ,EMPTY     ,WALL      ,WALL      ,EMPTY     ,EMPTY     ,WALL,
 EMPTY     ,OBJECTIF  ,OBJECTIF  ,WALL      ,EMPTY     ,WALL      ,EMPTY     ,WALL      ,WALL      ,EMPTY     ,WALL      ,WALL,
 EMPTY     ,EMPTY     ,EMPTY     ,EMPTY     ,EMPTY     ,CRATE_MOV ,EMPTY     ,EMPTY     ,WALL      ,CRATE_MOV ,WALL      ,WALL,
 WALL      ,EMPTY     ,EMPTY     ,WALL      ,EMPTY     ,WALL      ,EMPTY     ,EMPTY     ,EMPTY     ,EMPTY     ,WALL      ,WALL,
 WALL      ,WALL      ,WALL      ,WALL      ,EMPTY     ,EMPTY     ,EMPTY     ,WALL      ,WALL      ,CRATE_MOV ,WALL      ,WALL,
 WALL      ,WALL      ,WALL      ,WALL      ,WALL      ,WALL      ,WALL      ,WALL      ,WALL      ,EMPTY     ,EMPTY     ,WALL,
 WALL      ,WALL      ,WALL      ,WALL      ,OBJECTIF  ,EMPTY     ,EMPTY     ,EMPTY     ,EMPTY     ,EMPTY     ,EMPTY     ,WALL,
 WALL      ,WALL      ,WALL      ,WALL      ,WALL      ,WALL      ,WALL      ,WALL      ,WALL      ,WALL      ,WALL      ,WALL,
 WALL      ,WALL      ,WALL      ,WALL      ,WALL      ,WALL      ,WALL      ,WALL      ,WALL      ,WALL      ,WALL      ,WALL,
 WALL      ,WALL      ,WALL      ,WALL      ,WALL      ,WALL      ,WALL      ,WALL      ,WALL      ,WALL      ,WALL      ,WALL};

#endif